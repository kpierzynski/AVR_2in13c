#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct
{
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMP_FILE_HEADER;

typedef struct
{
    unsigned int size;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int imageSize;
    unsigned int XpixelsPerM;
    unsigned int YpixelsPerM;
    unsigned int colorsUsed;
    unsigned int colorsImportant;
} BMP_INFO_HEADER;
#pragma pack(pop)

unsigned int closest(unsigned int x, unsigned int m)
{
    return ((x - 1) | (m - 1)) + 1;
}

void remove_extension(char *file_name)
{
    char *dot = strrchr(file_name, '.');
    if (!dot || dot == file_name)
        return;
    *dot = '\0';
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <bmp_file>\n", argv[0]);
        return 1;
    }

    // Open the BMP file
    FILE *fp = fopen(argv[1], "rb");
    if (!fp)
    {
        printf("Failed to open file %s\n", argv[1]);
        return 2;
    }

    // Read the BMP file header
    BMP_FILE_HEADER fileHeader;
    if (fread(&fileHeader, sizeof(BMP_FILE_HEADER), 1, fp) != 1)
    {
        printf("Failed to read file header\n");
        fclose(fp);
        return 3;
    }

    // Read the image data
    int imageSize = fileHeader.bfSize - fileHeader.bfOffBits;
    unsigned char *imageData = (unsigned char *)malloc(imageSize);
    if (!imageData)
    {
        printf("Failed to allocate memory for image data\n");
        fclose(fp);
        return 4;
    }

    BMP_INFO_HEADER infoHeader;
    if (fread(&infoHeader, sizeof(BMP_INFO_HEADER), 1, fp) != 1)
    {
        printf("Failed to read info header\n");
        fclose(fp);
        return 3;
    }

    if (infoHeader.width % 8 != 0)
    {
        printf("Failed to convert. File width not multiple of 8\n");
        fclose(fp);
        return 7;
    }

    fseek(fp, fileHeader.bfOffBits, SEEK_SET);
    size_t bytesRead = fread(imageData, 1, imageSize, fp);
    if (bytesRead != imageSize)
    {
        printf("Failed to read image data, read %lu bytes instead of %d\n", bytesRead, imageSize);
        free(imageData);
        fclose(fp);
        return 5;
    }

    // Padding size in bits
    unsigned int padding = closest(infoHeader.width, 32) - infoHeader.width;
    padding /= 8;

    unsigned int pos = 0;
    unsigned char *cleanData = (unsigned char *)malloc(infoHeader.width * infoHeader.height);

    // Remove padding
    for (int i = 0; i < imageSize; i++)
    {
        if ((i % 16) > infoHeader.width / 8 - 1)
            continue;

        cleanData[pos++] = (~(imageData[i] & 0xFF)) & 0xFF;
    }

    char fileName[32];
    sprintf(fileName, "%s", argv[1]);
    remove_extension(fileName);

    char targetFileName[34];
    sprintf(targetFileName, "%s.c", fileName);

    FILE *target;
    target = fopen(targetFileName, "w");

    // Create array in c style array
    fprintf(target, "#define IMG_WIDTH %d\n#define IMG_HEIGHT %d\n", infoHeader.width, infoHeader.height);
    fprintf(target, "const uint8_t %s[] PROGMEM = {", fileName);
    for (int i = pos; i > 0; i--)
    {
        if (i % (infoHeader.width / 8) == 0)
            fprintf(target, "\n");

        fprintf(target, "0x%02X, ", (unsigned char)(cleanData[pos - i]));
    }
    fprintf(target, "\n};\n");

    // Clean up
    free(imageData);
    free(cleanData);
    fclose(fp);
    fclose(target);

    return 0;
}

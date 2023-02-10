#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void rle_decompress(uint8_t *compressed, uint16_t length)
{
    register uint8_t current;
    register uint8_t next;

    while (length)
    {
        current = *(compressed);
        next = *(compressed + 1);

        if (current == next)
        {
            uint8_t len = *(compressed + 2);
            while (len--)
                printf("%d ", current);

            compressed += 3;
            length -= 3;
        }
        else
        {
            printf("%d ", current);
            compressed++;
            length--;
        }
    }
}

uint16_t rle_compress(uint8_t *data, uint8_t *result, uint16_t length)
{
    uint8_t *compressed = result;
    uint8_t *writer = result;

    register uint8_t current;
    register uint8_t next;

    while (length > 0)
    {
        current = *data;
        next = *(data + 1);

        if (current == next)
        {
            uint8_t len = 0;
            uint8_t *ptr = data;
            while (*ptr++ == current && length > len && len != 255)
                len++;

            *writer++ = current;
            *writer++ = next;
            *writer++ = len;

            length -= len;
            data += len;
        }
        else
        {
            *writer++ = current;
            data++;
            length--;
        }
    }

    return (writer - compressed);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <bmp_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        printf("Failed to open file %s\n", argv[1]);
        return 2;
    }

    int width;
    int height;
    char array_name[32];
    if (fscanf(fp, "#define IMG_WIDTH %d\n#define IMG_HEIGHT %d\nconst uint8_t %s PROGMEM = {\n", &width, &height, array_name) != 3)
    {
        printf("Cannot parse input file\n");
        return 3;
    }
    width /= 8;
    unsigned char *input = (unsigned char *)malloc(height * width);

    for (int row = 0; row < height; row++)
    {
        for (int i = 0; i < width; i++)
        {
            fscanf(fp, "0x%hhx, ", &input[row * width + i]);
        }
        fscanf(fp, "\n");
    }

    int input_len = width * height;
    unsigned char *rle = (unsigned char *)malloc(input_len * 3 / 2 + 1);
    uint16_t len = rle_compress(input, rle, input_len);

    printf("//len: %d, compressed_len: %d, saved: %d, ratio: %f\r\n", input_len, len, input_len - len, (float)(input_len - len) / (input_len)*100);
    printf("#include <avr/io.h>\n");
    printf("#include <avr/pgmspace.h>\n\n");
    printf("const uint8_t %s PROGMEM = {\n", array_name);
    printf("0x%02X, //RLE LEN H byte\n", (len >> 8) & 0xFF);
    printf("0x%02X, //RLE LEN L byte\n", len & 0xFF);

    for (uint16_t i = 0; i < len; i++)
    {
        if ((i) % 16 == 0)
            printf("\n");
        printf("0x%02X, ", rle[i]);
    }
    printf("\n};\n");

    free(input);
    free(rle);

    return 0;
}

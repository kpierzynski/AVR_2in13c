//len: 2756, compressed_len: 1243, saved: 1513, ratio: 54.898407
#include <avr/io.h>
#include <avr/pgmspace.h>

const uint8_t example_prepared[] PROGMEM = {
0x04, //RLE LEN H byte
0xDB, //RLE LEN L byte

0x00, 0x00, 0xFF, 0x00, 0x00, 0x55, 0xE0, 0x00, 0x00, 0x0B, 0x01, 0xF0, 0x00, 0x00, 0x0B, 0x01, 
0xF1, 0xC0, 0x00, 0x1C, 0x0F, 0x00, 0x00, 0x07, 0x01, 0xFF, 0xE0, 0x00, 0x38, 0x07, 0x00, 0x00, 
0x07, 0x01, 0xFF, 0xE0, 0x00, 0x38, 0x03, 0x80, 0x00, 0x00, 0x06, 0x03, 0xFF, 0xE0, 0x00, 0x38, 
0x03, 0x80, 0x00, 0x00, 0x06, 0x1F, 0xFF, 0xC0, 0x00, 0x38, 0x03, 0x80, 0x00, 0x00, 0x06, 0x3F, 
0xFF, 0xC0, 0x00, 0x38, 0x03, 0x80, 0x00, 0x00, 0x06, 0x3F, 0xFF, 0x80, 0x00, 0x3E, 0x0F, 0x80, 
0x00, 0x00, 0x06, 0x3F, 0xFF, 0xC0, 0x00, 0x1F, 0xFF, 0x00, 0x00, 0x07, 0x1F, 0xFF, 0xC0, 0x00, 
0x0F, 0xFF, 0x00, 0x00, 0x07, 0x03, 0xFF, 0xE0, 0x00, 0x07, 0xFE, 0x00, 0x00, 0x07, 0x01, 0xFF, 
0xE0, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x07, 0x01, 0xFF, 0xE0, 0x00, 0x00, 0x0A, 0x01, 0xF0, 0x80, 
0x00, 0x00, 0x0A, 0x01, 0xF0, 0x00, 0x00, 0x03, 0x30, 0x00, 0x00, 0x08, 0xC0, 0x00, 0x00, 0x02, 
0xE0, 0xFC, 0x00, 0x00, 0x0A, 0x01, 0xF9, 0xFE, 0x00, 0x00, 0x0A, 0x03, 0xFD, 0xFF, 0x00, 0x00, 
0x0A, 0x07, 0xFF, 0xFF, 0x02, 0x00, 0x00, 0x0A, 0x07, 0xFF, 0x87, 0x80, 0x00, 0x00, 0x09, 0x07, 
0x0F, 0x83, 0x80, 0x00, 0x00, 0x02, 0x03, 0x00, 0x00, 0x06, 0x07, 0x07, 0x02, 0x03, 0x80, 0x00, 
0x00, 0x02, 0x07, 0xC0, 0x00, 0x00, 0x05, 0x07, 0x07, 0x02, 0x03, 0x80, 0x00, 0x00, 0x02, 0x07, 
0xE0, 0x00, 0x00, 0x05, 0x07, 0x07, 0x02, 0x03, 0x80, 0x00, 0x00, 0x02, 0x0F, 0xF0, 0x00, 0x00, 
0x05, 0x03, 0x87, 0x03, 0x80, 0x00, 0x00, 0x02, 0x0F, 0xF8, 0x00, 0x00, 0x05, 0x03, 0x87, 0x03, 
0x80, 0x00, 0x1F, 0xFF, 0xFC, 0x00, 0x00, 0x05, 0x01, 0xC0, 0x07, 0x00, 0x00, 0x02, 0x3F, 0xFF, 
0xFE, 0x00, 0x00, 0x07, 0x06, 0x00, 0x00, 0x02, 0x3F, 0xFF, 0xFF, 0x02, 0x00, 0x00, 0x0A, 0x3F, 
0xFF, 0xFF, 0x02, 0x80, 0x00, 0x00, 0x09, 0x3F, 0xFF, 0xBF, 0xC0, 0x00, 0x00, 0x06, 0x03, 0x00, 
0x00, 0x02, 0x3E, 0x00, 0x1F, 0xE0, 0x00, 0x00, 0x06, 0x03, 0x80, 0x00, 0x3E, 0x00, 0x0F, 0xE0, 
0x00, 0x00, 0x06, 0x03, 0x80, 0x00, 0x3E, 0x00, 0x07, 0xF0, 0x00, 0x00, 0x06, 0x03, 0x80, 0x00, 
0x3E, 0x00, 0x07, 0xF0, 0x00, 0x00, 0x04, 0x07, 0xFF, 0xFF, 0x02, 0x80, 0x00, 0x3E, 0x00, 0x0F, 
0xE0, 0x00, 0x00, 0x04, 0x07, 0xFF, 0xFF, 0x02, 0x80, 0x00, 0x3E, 0x00, 0x1F, 0xE0, 0x00, 0x00, 
0x04, 0x07, 0xFF, 0xFF, 0x02, 0x80, 0x00, 0x3F, 0xFF, 0xBF, 0xC0, 0x00, 0x00, 0x04, 0x07, 0xFF, 
0xFF, 0x02, 0x80, 0x00, 0x3F, 0xFF, 0xFF, 0x02, 0x80, 0x00, 0x00, 0x04, 0x03, 0x80, 0x03, 0x80, 
0x00, 0x3F, 0xFF, 0xFF, 0x02, 0x00, 0x00, 0x05, 0x03, 0xC0, 0x03, 0x80, 0x00, 0x3F, 0xFF, 0xFE, 
0x00, 0x00, 0x05, 0x01, 0xC0, 0x03, 0x80, 0x00, 0x1F, 0xFF, 0xFC, 0x00, 0x00, 0x06, 0xE0, 0x03, 
0x80, 0x00, 0x00, 0x02, 0x0F, 0xF8, 0x00, 0x00, 0x06, 0xE0, 0x03, 0x80, 0x00, 0x00, 0x02, 0x0F, 
0xF0, 0x00, 0x00, 0x0B, 0x0F, 0xE0, 0x00, 0x00, 0x0B, 0x07, 0xC0, 0x00, 0x00, 0x0B, 0x03, 0x00, 
0x00, 0x14, 0x07, 0xFF, 0x80, 0x00, 0x00, 0x0A, 0x1F, 0xFF, 0x80, 0x00, 0x00, 0x0A, 0x1F, 0xFF, 
0x80, 0x00, 0x00, 0x0A, 0x3F, 0xFF, 0x80, 0x00, 0x00, 0x0A, 0x3C, 0x00, 0x00, 0x0C, 0x38, 0x00, 
0x00, 0x0C, 0x38, 0x00, 0x00, 0x0C, 0x18, 0x00, 0x00, 0x0C, 0x1C, 0x00, 0x00, 0x0C, 0x0F, 0xFF, 
0x80, 0x00, 0x00, 0x0A, 0x3F, 0xFF, 0x80, 0x00, 0x00, 0x0A, 0x3F, 0xFF, 0x80, 0x00, 0x00, 0x0A, 
0x3F, 0xFF, 0x80, 0x00, 0x00, 0x3D, 0x0F, 0x3F, 0xFF, 0x80, 0x00, 0x00, 0x09, 0x0F, 0x3F, 0xFF, 
0x80, 0x00, 0x00, 0x09, 0x0F, 0x3F, 0xFF, 0x80, 0x00, 0x00, 0x09, 0x0F, 0x3F, 0xFF, 0x80, 0x00, 
0x00, 0x32, 0x03, 0x80, 0x00, 0x00, 0x0A, 0xF8, 0x03, 0x80, 0x00, 0x00, 0x09, 0x01, 0xFE, 0x03, 
0x80, 0x00, 0x00, 0x09, 0x03, 0xFF, 0x03, 0x80, 0x00, 0x00, 0x09, 0x07, 0xFF, 0x83, 0x80, 0x00, 
0x00, 0x09, 0x07, 0xFF, 0xE3, 0x80, 0x00, 0x00, 0x09, 0x07, 0x83, 0xF3, 0x80, 0x00, 0x00, 0x09, 
0x07, 0x01, 0xFB, 0x80, 0x00, 0x00, 0x09, 0x07, 0x00, 0x7F, 0x80, 0x00, 0x00, 0x09, 0x07, 0x00, 
0x3F, 0x80, 0x00, 0x00, 0x09, 0x03, 0x00, 0x1F, 0x80, 0x00, 0x00, 0x09, 0x03, 0x80, 0x0F, 0x80, 
0x00, 0x00, 0x09, 0x01, 0xC0, 0x07, 0x80, 0x00, 0x00, 0x0B, 0x03, 0x00, 0x00, 0x1A, 0x0E, 0x00, 
0x00, 0x0C, 0x0E, 0x00, 0x00, 0x0C, 0x0E, 0x00, 0x00, 0x0C, 0x0E, 0x00, 0x00, 0x0C, 0x0E, 0x00, 
0x00, 0x0C, 0x0E, 0x00, 0x00, 0x0C, 0x0E, 0x00, 0x00, 0x0C, 0x0E, 0x00, 0x00, 0x0C, 0x0E, 0x00, 
0x00, 0x0C, 0x0E, 0x00, 0x00, 0x0C, 0x0E, 0x00, 0x00, 0x0C, 0x0E, 0x00, 0x00, 0x0C, 0x0E, 0x00, 
0x00, 0x0C, 0x0E, 0x00, 0x00, 0x0C, 0x0E, 0x00, 0x00, 0x0C, 0x0E, 0x00, 0x00, 0x18, 0x01, 0x80, 
0x00, 0x00, 0x0A, 0xF8, 0x0F, 0x80, 0x00, 0x00, 0x09, 0x01, 0xFE, 0x3F, 0x80, 0x00, 0x00, 0x09, 
0x03, 0xFE, 0x7F, 0x80, 0x00, 0x00, 0x09, 0x03, 0xFF, 0xFE, 0x00, 0x00, 0x0A, 0x07, 0x87, 0xF8, 
0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x02, 0x07, 0x03, 0xE0, 0x00, 0x00, 0x07, 0x0F, 0x80, 0x00, 
0x07, 0x03, 0xC0, 0x00, 0x00, 0x07, 0x0F, 0x80, 0x00, 0x07, 0x03, 0x80, 0x00, 0x00, 0x07, 0x0F, 
0x80, 0x00, 0x07, 0x03, 0x80, 0x00, 0x00, 0x07, 0x0F, 0x80, 0x00, 0x07, 0x03, 0x80, 0x00, 0x00, 
0x07, 0x0F, 0x80, 0x00, 0x07, 0xFF, 0xFF, 0x02, 0x80, 0x00, 0x00, 0x06, 0x0F, 0x80, 0x00, 0x07, 
0xFF, 0xFF, 0x02, 0x80, 0x00, 0x00, 0x06, 0x0F, 0x80, 0x00, 0x07, 0xFF, 0xFF, 0x02, 0x80, 0x00, 
0x00, 0x06, 0x0F, 0x80, 0x00, 0x07, 0xFF, 0xFF, 0x02, 0x80, 0x00, 0x00, 0x06, 0x0F, 0x80, 0x00, 
0x00, 0x0B, 0x0F, 0x80, 0x00, 0x00, 0x0B, 0x0F, 0x80, 0x00, 0x00, 0x0B, 0x0F, 0x80, 0x00, 0x07, 
0x80, 0x00, 0x00, 0x08, 0x0F, 0x80, 0x00, 0x07, 0xF0, 0x00, 0x00, 0x08, 0x0F, 0x80, 0x00, 0x07, 
0xFE, 0x00, 0x00, 0x08, 0x0F, 0x80, 0x00, 0x03, 0xFF, 0xC0, 0x00, 0x00, 0x07, 0x0F, 0x80, 0x00, 
0x00, 0x02, 0x7F, 0xF0, 0x00, 0x00, 0x07, 0x0F, 0x80, 0x00, 0x00, 0x02, 0x0F, 0xFE, 0x00, 0x00, 
0x07, 0x0F, 0x80, 0x00, 0x00, 0x03, 0xFF, 0x80, 0x00, 0x00, 0x06, 0x0F, 0x80, 0x00, 0x00, 0x03, 
0x1F, 0x80, 0x00, 0x00, 0x06, 0x0F, 0x80, 0x00, 0x00, 0x03, 0x0F, 0x80, 0x00, 0x00, 0x06, 0x0F, 
0x80, 0x00, 0x00, 0x03, 0x3F, 0x80, 0x00, 0x00, 0x06, 0x0F, 0x80, 0x00, 0x00, 0x02, 0x01, 0xFF, 
0x80, 0x00, 0x00, 0x06, 0x0F, 0x80, 0x00, 0x00, 0x02, 0x0F, 0xFF, 0x00, 0x00, 0x07, 0x0F, 0x80, 
0x00, 0x00, 0x02, 0xFF, 0xF8, 0x00, 0x00, 0x07, 0x0F, 0x80, 0x00, 0x07, 0xFF, 0xC0, 0x00, 0x00, 
0x07, 0x0F, 0x80, 0x00, 0x07, 0xFE, 0x00, 0x00, 0x08, 0x0F, 0x80, 0x00, 0x07, 0xF0, 0x00, 0x00, 
0x08, 0x07, 0x00, 0x00, 0x02, 0x07, 0x80, 0x00, 0x00, 0x11, 0xFF, 0x00, 0x00, 0x08, 0x01, 0x80, 
0x00, 0x03, 0xFF, 0xC0, 0x00, 0x00, 0x07, 0x0F, 0x80, 0x00, 0x07, 0xFF, 0xE0, 0x00, 0x00, 0x07, 
0x7F, 0x80, 0x00, 0x1F, 0xFF, 0xF8, 0x00, 0x00, 0x06, 0x03, 0xFF, 0x80, 0x00, 0x3F, 0xFF, 0xFC, 
0x00, 0x00, 0x06, 0x0F, 0xFF, 0x00, 0x00, 0x02, 0x3F, 0x81, 0xFC, 0x00, 0x00, 0x06, 0x7F, 0xF8, 
0x00, 0x00, 0x02, 0x7F, 0x00, 0xFE, 0x00, 0x00, 0x05, 0x03, 0xFF, 0xF0, 0x00, 0x00, 0x02, 0xFC, 
0x00, 0x3F, 0x00, 0x00, 0x05, 0x07, 0xFC, 0x70, 0x00, 0x00, 0x02, 0xFC, 0x00, 0x3F, 0x00, 0x00, 
0x05, 0x07, 0xE0, 0x70, 0x00, 0x01, 0xF8, 0x00, 0x1F, 0x80, 0x00, 0x00, 0x04, 0x07, 0x80, 0x70, 
0x00, 0x01, 0xF0, 0x00, 0x0F, 0x80, 0x00, 0x00, 0x04, 0x07, 0xE0, 0x70, 0x00, 0x01, 0xF0, 0x00, 
0x0F, 0x80, 0x00, 0x00, 0x04, 0x07, 0xFC, 0x70, 0x00, 0x01, 0xF0, 0x00, 0x0F, 0x80, 0x00, 0x00, 
0x04, 0x01, 0xFF, 0xF0, 0x00, 0x01, 0xF0, 0x00, 0x0F, 0x80, 0x00, 0x00, 0x05, 0x3F, 0xF0, 0x00, 
0x01, 0xF0, 0x00, 0x0F, 0x80, 0x00, 0x00, 0x05, 0x07, 0xFF, 0x00, 0x01, 0xF8, 0x00, 0x0F, 0x80, 
0x00, 0x00, 0x05, 0x01, 0xFF, 0x80, 0x00, 0xF8, 0x00, 0x1F, 0x80, 0x00, 0x00, 0x06, 0x3F, 0x80, 
0x00, 0xFC, 0x00, 0x3F, 0x00, 0x00, 0x07, 0x07, 0x80, 0x00, 0xFC, 0x00, 0x3F, 0x00, 0x00, 0x0A, 
0x7F, 0x00, 0xFE, 0x00, 0x00, 0x0A, 0x3F, 0xC1, 0xFC, 0x00, 0x00, 0x0A, 0x3F, 0xFF, 0xFC, 0x00, 
0x00, 0x0A, 0x1F, 0xFF, 0xF8, 0x00, 0x00, 0x0A, 0x07, 0xFF, 0xE0, 0x00, 0x00, 0x0A, 0x03, 0xFF, 
0xC0, 0x00, 0x00, 0x0B, 0x7F, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x14, 
};
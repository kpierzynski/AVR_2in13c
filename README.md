# AVR_2in13c

## This library is created for WaveShare 2.13inch white,black,yellow (or red) version of the epaper display.

Library uses saved in progmem images to display on epaper

In rle_converter there are two programs: bmp2c and c2rle.
bmp2c converts monochrome bmp to C array. Note that image has to be rotated to left and then flipped vertically to work.
c2rle compress array from bmp2c and produce compressed result.

# Functions

    void paper_init();

Initialize WaveShare 2.13inchC display

---

    void paper_display(const uint8_t *black, const uint8_t *color);

Send two buffers, black and colored from PROGMEM to the display.

---

    void paper_rle_display(const uint8_t *compressed);

Send only black (but can be easily extended for color) buffer to the display, but buffer is compressed with RLE encoding.

---

    void paper_clear();

Clears whole display

---

    void paper_sleep();

Put display to sleep. It is important step, display can get damaged if not turned off.

---

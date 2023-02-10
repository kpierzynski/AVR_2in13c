#ifndef __PAPER_H_
#define __PAPER_H_

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stddef.h>

#include "paper_mem.h"
#include "spi.h"

// This library is created for WaveShare 2.13inch white,black,yellow (or red) version of the epaper display.
#define WIDTH 104
#define HEIGHT 212

#define DDR_DC DDRB
#define PORT_DC PORTB
#define DC PB1
#define DDR_RST DDRB
#define PORT_RST PORTB
#define RST PB0
#define DDR_BUSY DDRD
#define PORT_BUSY PORTD
#define BUSY PD7

#define DDR_CS DDR_SS
#define PORT_CS PORT_SS
#define CS SS

#define DC_OUT DDR_DC |= (1 << DC)
#define DC_HIGH PORT_DC |= (1 << DC)
#define DC_LOW PORT_DC &= ~(1 << DC)

#define RST_OUT DDR_RST |= (1 << RST)
#define RST_HIGH PORT_RST |= (1 << RST)
#define RST_LOW PORT_RST &= ~(1 << RST)

#define CS_OUT DDR_CS |= (1 << CS)
#define CS_HIGH PORT_CS |= (1 << CS)
#define CS_LOW PORT_CS &= ~(1 << CS)

#define PIN_BUSY PIND
#define BUSY_IN DDR_BUSY &= ~(1 << BUSY)
#define BUSY_STATE (PIN_BUSY & (1 << BUSY))
#define BUSY_PULLUP PORT_BUSY |= (1 << BUSY)

void paper_init();
void paper_rle_display(const uint8_t *compressed);
void paper_display(const uint8_t *black, const uint8_t *color);
void paper_clear();
void paper_sleep();

#endif
#ifndef __SPI_H_
#define __SPI_H_

#include <avr/io.h>

#define DDR_SCK DDRB
#define DDR_MOSI DDRB
#define DDR_MISO DDRB
#define DDR_SS DDRB

#define PORT_SCK PORTB
#define PORT_MOSI PORTB
#define PORT_MISO PORTB
#define PORT_SS PORTB

#define SCK PB5
#define MISO PB4
#define MOSI PB3
#define SS PB2

void spi_init();
void spi_write(uint8_t byte);

#endif
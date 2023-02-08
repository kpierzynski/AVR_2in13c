#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>

#include "spi.h"
#include "paper.h"

#include "./images/city.h"

int main()
{
	_delay_ms(5000);
	spi_init();
	paper_init();

	DDRD |= (1 << PD6); // LED

	paper_display(city_black, city_color);
	paper_sleep();

	while (1)
	{
		PORTD ^= (1 << PD6);
		_delay_ms(250);
	}

	return -1;
}
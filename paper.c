#include "paper.h"

static void paper_cmd(uint8_t cmd)
{
	DC_LOW;
	CS_LOW;
	spi_write(cmd);
	CS_HIGH;
}

static void paper_data(uint8_t byte)
{
	DC_HIGH;
	CS_LOW;
	spi_write(byte);
	CS_HIGH;
}

inline static void paper_busy()
{
	while (!BUSY_STATE)
		;
}

void paper_display(const uint8_t *black, const uint8_t *color)
{
	paper_cmd(DISPLAY_START_TRANSMISSION1_CMD);
	for (uint16_t i = 0; i < WIDTH * HEIGHT / 8; i++)
		paper_data(pgm_read_byte(black + i));

	paper_cmd(DISPLAY_START_TRANSMISSION2_CMD);
	for (uint16_t i = 0; i < WIDTH * HEIGHT / 8; i++)
		paper_data(pgm_read_byte(color + i));
	// paper_data(0xFF);

	paper_cmd(DISPLAY_REFRESH_CMD);
	paper_busy();
}

void paper_clear()
{
	paper_cmd(DISPLAY_START_TRANSMISSION1_CMD);
	for (uint16_t i = 0; i < WIDTH * HEIGHT / 8; i++)
		paper_data(0xFF);

	paper_cmd(DISPLAY_START_TRANSMISSION2_CMD);
	for (uint16_t i = 0; i < WIDTH * HEIGHT / 8; i++)
		paper_data(0xFF);

	paper_cmd(DISPLAY_REFRESH_CMD);
	paper_busy();
}

void paper_init()
{
	DC_OUT;
	RST_OUT;
	CS_HIGH;
	CS_OUT;
	BUSY_IN;

	RST_HIGH;
	_delay_ms(200);
	RST_LOW;
	_delay_ms(5);
	RST_HIGH;
	_delay_ms(200);

	paper_cmd(BOOSTER_SOFT_START_CMD);
	paper_data(0x17);
	paper_data(0x17);
	paper_data(0x17);

	paper_cmd(POWER_ON_CMD);
	paper_busy();

	paper_cmd(PANEL_SETTING_CMD);
	paper_data(0x8F);

	paper_cmd(VCOM_AND_DATA_INVERVAL_SETTING_CMD);
	paper_data(0x37);

	paper_cmd(RESOLUTION_SETTING_CMD);
	paper_data(WIDTH & 0xFF);
	paper_data(HEIGHT >> 8);
	paper_data(HEIGHT & 0xFF);

	paper_busy();
}

void paper_sleep()
{
	paper_cmd(POWER_OFF_CMD);
	paper_busy();

	paper_cmd(DEEP_SLEEP_CMD);
	paper_data(0xA5);
}
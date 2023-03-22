#include "senseur_solaire.h"

senseur_solaire::senseur_solaire(uint16_t VEML7700_ADDRESS, uint16_t VEML7700_CMD_CONF, uint16_t VEML7700_CONF_100, uint16_t VEML7700_CMD_ALS)
{
	this->VEML7700_ADDRESS = VEML7700_ADDRESS;
	this->VEML7700_CMD_CONF = VEML7700_CMD_CONF;
	this->VEML7700_CONF_100 = VEML7700_CONF_100;
	this->VEML7700_CMD_ALS = VEML7700_CMD_ALS;
	i = 0;
	luminositer[0] = 0;
	erreur = 0;
	while (i < 10)
	{
		calculer();
	}
}

void senseur_solaire::calculer()
{
	if (i > 10)
	{
		i = 0;
	}

	int fd = wiringPiI2CSetup(VEML7700_ADDRESS);
	if (fd == -1)
	{
		erreur++;
	}
	else
	{
		// Set integration time to 100ms
		wiringPiI2CWriteReg16(fd, VEML7700_CMD_CONF, VEML7700_CONF_100);

		// Read ambient light level
		int data = wiringPiI2CReadReg16(fd, VEML7700_CMD_ALS);

		// Convert raw data to lux
		luminositer[i] = 0.0576 * (data & 0x0FFF);
		i++;
		erreur = 0;
	}
	
}

float senseur_solaire::moyenne()
{
	if (erreur > 5)
	{
		for (size_t y = 0; y < 10; y++)
		{
			luminositer[y] == -300;
		}
	}
	float moyenne = 0;
	for (size_t y = 0; y < 10; y++)
	{
		moyenne = luminositer[y] + moyenne;
	}
	return moyenne/10;
}

void senseur_solaire::initialisation(uint16_t VEML7700_ADDRESS, uint16_t VEML7700_CMD_CONF, uint16_t VEML7700_CONF_100, uint16_t VEML7700_CMD_ALS)
{
	this->VEML7700_ADDRESS = VEML7700_ADDRESS;
	this->VEML7700_CMD_CONF = VEML7700_CMD_CONF;
	this->VEML7700_CONF_100 = VEML7700_CONF_100;
	this->VEML7700_CMD_ALS = VEML7700_CMD_ALS;
}

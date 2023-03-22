#pragma once
#include <iostream>
#include <wiringPiI2C.h>
class senseur_solaire
{
private:
	int i;
	int erreur;
	float luminositer[10];
	uint16_t VEML7700_ADDRESS;
	uint16_t VEML7700_CMD_CONF;
	uint16_t VEML7700_CONF_100;
	uint16_t VEML7700_CMD_ALS;
public:
	senseur_solaire(uint16_t VEML7700_ADDRESS = 0x10, uint16_t VEML7700_CMD_CONF = 0x00, uint16_t VEML7700_CONF_100 = 0x0000, uint16_t VEML7700_CMD_ALS = 0x04);
	void calculer();
	float moyenne();
	void initialisation(uint16_t VEML7700_ADDRESS = 0x10, uint16_t VEML7700_CMD_CONF = 0x00, uint16_t VEML7700_CONF_100 = 0x0000, uint16_t VEML7700_CMD_ALS = 0x04);
};


/*
 * ships.h
 *
 *  Created on: Jan 12, 2024
 *      Author: MinhNhan
 */

#ifndef COMPONENT_SHIPS_SHIPS_H_
#define COMPONENT_SHIPS_SHIPS_H_


#include "stdint.h"

typedef struct Ship_t Ship;

struct Ship_t{
	uint8_t x;
	uint8_t y;
	uint8_t width;
	uint8_t height;
};


Ship *ship_create(uint8_t x,uint8_t y, uint8_t width, uint8_t height);
void ship_detroy(Ship *ship);
void ship_move(Ship *ship,uint8_t x, uint8_t y);



#endif /* COMPONENT_SHIPS_SHIPS_H_ */

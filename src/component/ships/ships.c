/*
 * ships.c
 *
 *  Created on: Jan 12, 2024
 *      Author: MinhNhan
 */



#include "ships.h"
#include <stdlib.h>
#include <config.h>

Ship *ship_create(uint8_t x,uint8_t y, uint8_t width, uint8_t height){
	Ship *p_ship = malloc(sizeof(Ship));

	if(p_ship == NULL) return NULL;

	p_ship->x = x;
	p_ship->y = y;
	p_ship->width = width;
	p_ship->height = height;
	return p_ship;

}
void ship_detroy(Ship *ship){
	free(ship);
	ship = NULL;
}
void ship_move(Ship *ship,uint8_t x, uint8_t y){
	if((x >= 0 && x < MAX_WIDTH) && ( y >=0 && y< MAX_HEIGHT)){
		ship->x = x;
		ship->y = y;
	}
}

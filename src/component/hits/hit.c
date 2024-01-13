/*
 * hit.c
 *
 *  Created on: Jan 12, 2024
 *      Author: MinhNhan
 */



#include "hits.h"
#include <stdlib.h>
#include <config.h>

Hit *hit_create(uint8_t x,uint8_t y, uint8_t width, uint8_t height){
	Hit *p_hit = malloc(sizeof(Hit));
	if(p_hit == NULL)  return NULL;
	p_hit->x = x;
	p_hit->y = y;
	p_hit->width = width;
	p_hit->height = height;
	return p_hit;
}
void hit_detroy(Hit *hit){
	free(hit);
	hit = NULL;
}
void hit_move(Hit *hit, uint8_t x, uint8_t y){
	if((x >= 0 && x < MAX_WIDTH) && ( y >=0 && y< MAX_HEIGHT)){
		hit->x = x;
		hit->y = y;
	}
}

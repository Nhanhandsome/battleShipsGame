/*
 * hits.h
 *
 *  Created on: Jan 12, 2024
 *      Author: MinhNhan
 */

#ifndef COMPONENT_HITS_HITS_H_
#define COMPONENT_HITS_HITS_H_


#include "stdint.h"

typedef struct Hit_t Hit;

struct Hit_t{
	uint8_t x;
	uint8_t y;
	uint8_t width;
	uint8_t height;
};

Hit *hit_create(uint8_t x,uint8_t y, uint8_t width, uint8_t height);
void hit_detroy(Hit *hit);
void hit_move(Hit *hit, uint8_t x, uint8_t y);

#endif /* COMPONENT_HITS_HITS_H_ */

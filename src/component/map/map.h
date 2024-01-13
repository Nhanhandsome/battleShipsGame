/*
 * map.h
 *
 *  Created on: Jan 12, 2024
 *      Author: MinhNhan
 */

#ifndef COMPONENT_MAP_MAP_H_
#define COMPONENT_MAP_MAP_H_

#include "stdint.h"
#include "hits/hits.h"
#include "ships/ships.h"
#include "config.h"
#include <stdbool.h>

typedef enum{
	GAME_OVER = -1,
	GAME_PLAYING = 0,
	GAME_END
}Game_state_t;

typedef struct Map_t Map;

struct Map_t{
	uint8_t map[MAX_HEIGHT][MAX_WIDTH];
	Ship *ship[MAX_SHIPS];
	uint8_t num_ships;
	Hit *hits[MAX_HITS];
	uint8_t num_hits;
	Game_state_t resulte;
};
uint8_t random_number(uint8_t min,uint8_t max);
void map_init(Map *map,const char *file_name);
void map_clear(Map *map);
void map_refresh(Map *map);
bool map_add_ships(Map *map,Ship *ship);
bool map_attack(Map* map,Hit *hit);
Game_state_t map_get_game_state(Map *map);
#endif /* COMPONENT_MAP_MAP_H_ */

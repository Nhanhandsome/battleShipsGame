/*
 * map.c
 *
 *  Created on: Jan 12, 2024
 *      Author: MinhNhan
 */

#include "map.h"
#include <stdlib.h>
#include <config.h>
#include <stdio.h>

uint8_t random_number(uint8_t min, uint8_t max) {
	uint8_t number = min + rand() % (max - min + 1);
	return number;
}

void map_init(Map *map, const char *file_name) {
	for (uint8_t i = 0; i < MAX_HEIGHT; i++) {
		for (uint8_t j = 0; j < MAX_WIDTH; j++) {
			map->map[i][j] = '*';
		}
	}
	for (uint8_t i = 0; i < MAX_SHIPS; i++) {
		map->ship[i] = NULL;
	}
	map->num_ships = 0;
	for (uint8_t i = 0; i < MAX_HITS; i++) {
		map->hits[i] = NULL;
	}
	map->num_hits = 0;
	FILE *file = fopen(file_name, "r");
	Ship *p_ship = NULL;
	if (file == NULL) {
		for (uint8_t i = 0; i < MAX_SHIPS; i++) {
			CREATE_SHIPS: p_ship = ship_create(random_number(0, 7),
					random_number(0, 7), 2, 1);
			if (map_add_ships(map, p_ship) != true) {
				ship_detroy(map->ship[i]);
				goto CREATE_SHIPS;
			}
		}
		goto END_INIT;
	}
	map->resulte = GAME_PLAYING;
	END_INIT: map_refresh(map);
}
void map_clear(Map *map) {
	for (uint8_t i = 0; i < MAX_HEIGHT; i++) {
		for (uint8_t j = 0; j < MAX_WIDTH; j++) {
			map->map[i][j] = '*';
		}
	}
}

void map_refresh(Map *map) {
	for (uint8_t i = 0; i < MAX_HEIGHT; i++) {
		for (uint8_t j = 0; j < MAX_WIDTH; j++) {
			putchar(map->map[i][j]);
			putchar(' ');
		}
		printf("\n");
	}
	if (map->num_hits > 0) {
		for (uint8_t i = 0; i < MAX_HITS; i++) {
			Hit *p_hit = map->hits[i];
			if (p_hit != NULL) {
				map->map[p_hit->y][p_hit->x] = '*';
				if (p_hit->y > 0) {
					map->hits[i]->y--;
					if(map->map[p_hit->y][p_hit->x] == 'x'){
						map->map[p_hit->y][p_hit->x] = '*';
						hit_detroy(p_hit);
						map->hits[i] = NULL;
						continue;
					}
					else{
						map->map[p_hit->y][p_hit->x] = 'x';
					}
				} else {
					hit_detroy(p_hit);
					map->hits[i] = NULL;
				}
			}
		}
	}
	int res = 0;
	for (uint8_t i = 0; i < MAX_HEIGHT; i++) {
		for (uint8_t j = 0; j < MAX_WIDTH; j++) {
			if(map->map[i][j] != '*') res++;
		}
	}
	if(res == 0) map->resulte = GAME_END;
}

bool map_add_ships(Map *map, Ship *ship) {

	for (uint8_t j = 0; j < map->num_ships; j++) {
		for (uint8_t i = 0; i < ship->height; i++) {
			for (uint8_t j = 0; j < ship->width; j++) {
				if (map->map[ship->y][ship->x] == 'x') {
					return false;
				}
			}
		}
	}

	for (int i = 0; i < ship->width; i++) {
		map->map[ship->y][ship->x + i] = 'x';
	}
	for (int i = 0; i < ship->height; i++) {
		map->map[ship->y + i][ship->x] = 'x';
	}

	map->ship[map->num_ships] = ship;
	map->num_ships++;
	return true;
//	map_refresh(map);
}
bool map_attack(Map *map, Hit *hit) {
	if (map->num_hits >= MAX_HITS) {
		map->resulte = GAME_OVER;
		return false;
	}
	map->hits[map->num_hits] = hit;
	map->num_hits++;
	map->map[hit->y][hit->x] = 'x';
	return true;
}
Game_state_t map_get_game_state(Map *map){
	return map->resulte;
}

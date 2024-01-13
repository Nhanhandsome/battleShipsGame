/*
 * main.c
 *
 *  Created on: Jan 12, 2024
 *      Author: MinhNhan
 */
#include "map/map.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

Map map;

typedef enum{
	KEY_LEFT = 'a',
	KEY_RIGHT = 'd',
	KEY_FIRE = 'f'
}KEY_CONTROLL;

typedef struct Position_t Position;

struct Position_t{
	uint8_t x;
};

int main(int argc, char **argv) {

	printf("Welcome Guy\r\n");
	Sleep(10);
	char begin = getch();
	if(begin == 'r'){
		printf("Playing Game\r\n");
	}
	map_init(&map,"map.txt");
	Position pos = {pos.x = 4};
	while(1){
		system("@cls||clear");
		map_refresh(&map);
		printf("\r\nPosition : x-%d",pos.x);
		char key = 0;
		if(kbhit() > 0) key = getch();
		switch (key) {
			case KEY_LEFT:
				if(pos.x > 0) pos.x--;
				break;
			case KEY_RIGHT:
				if(pos.x < MAX_WIDTH-1) pos.x++;
				break;
			case KEY_FIRE:
				printf("Attack \r\n");
				Hit *hit = hit_create(pos.x,7, 1,1);
				map_attack(&map, hit);
				break;
			default:
				break;
		}
		if(map_get_game_state(&map) != GAME_PLAYING)
			break;
	}
	system("@cls||clear");
	switch (map.resulte) {
		case GAME_END:
			printf("******GAME PASS******\r\n");
			break;
		case GAME_OVER:
			printf("******GAME OVER******\r\n");
			break;
		default:
			break;
	}
	printf("Press key to exit\r\n");
	getch();
	return 0;
}

#include <stdlib.h>
#include <string.h>
#include "life.h"
#include "screen.h"
#include "game.h" 

struct Life *lives_head = NULL;

void InitializeLives() {
    for (int i = 0; i < 3; i++) {
        struct Life *new_life = (struct Life*)malloc(sizeof(struct Life));// aloca dinamicamente a struct de vidas
        strcpy(new_life->icon, "❤️ "); // Ícone do coração
        new_life->next = lives_head;
        lives_head = new_life;
    }
}

void DrawLives() {
    struct Life *current_life = lives_head;
    int x = MINX + 2; // posição coração em x
    int y = MINY + 2; // posição do coração em y

    while (current_life != NULL) {
        screenSetColor(COLOR_SCORE, DARKGRAY);
        screenGotoxy(x, y);
        printf("%s", current_life->icon);
        x += 4; // Espaçamento entre os corações
        current_life = current_life->next;
    }
}
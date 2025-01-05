#include <stdio.h>
#include <ncurses.h>

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 10

struct order
{
    int x;
    int y;
};

struct fields
{
    struct order * orders;
    struct order player;
    int order_count;
};

void display_field(const struct fields *game_fields) {
    for (int y = 0; y < FIELD_HEIGHT; y++) {
        for (int x = 0; x < FIELD_WIDTH; x++) {
            int is_order = 0;
            for (int i = 0; i < game_fields->order_count; i++) {
                if (game_fields->orders[i].x == x && game_fields->orders[i].y == y) {
                    printf("O "); 
                    is_order = 1;
                    break;
                }
            }
            if (!is_order) {
                if (game_fields->player.x == x && game_fields->player.y == y) {
                    printf("P "); 
                } else {
                    printf(". "); 
                }
            }
        }
        printf("\n"); 
    }
}

int main(){
    initscr();
    cbreak();
    noecho();

    printw("Нажмите ESC для выхода");

    struct fields field;

    int ch;
    while ((ch = getch) != 27)
    {
        if (ch >= 32 && ch <= 126)
        {
            if (ch == 'w')
            {
                bool ok = true;
                int len = sizeof(field.orders)/sizeof(field.orders[0]);
                for (int i = 0; i < len; i++){
                    int y = field.orders->y++;
                    if (field.orders[i].y == y){
                        ok = false;
                    }
                }

                if (ok) {
                    field.player.y++;
                    display_field(&field);
                } else {
                    display_field(&field);
                }
            }

            if (ch == 'a')
            {
                bool ok = true;
                int len = sizeof(field.orders)/sizeof(field.orders[0]);
                for (int i = 0; i < len; i++){
                    int x = field.orders->x--;
                    if (field.orders[i].x == x){
                        ok = false;
                    }
                }

                if (ok) {
                    field.player.x--;
                    display_field(&field);
                } else {
                    display_field(&field);
                }
            }
            if (ch == 'd')
            {
                bool ok = true;
                int len = sizeof(field.orders)/sizeof(field.orders[0]);
                for (int i = 0; i < len; i++){
                    int x = field.orders->x++;
                    if (field.orders[i].x == x){
                        ok = false;
                    }
                }

                if (ok) {
                    field.player.x++;
                    display_field(&field);
                } else {
                    display_field(&field);
                }
            }
            if (ch == 's')
            {
                bool ok = true;
                int len = sizeof(field.orders)/sizeof(field.orders[0]);
                for (int i = 0; i < len; i++){
                    int y = field.orders->y--;
                    if (field.orders[i].y == y){
                        ok = false;
                    }
                }

                if (ok) {
                    field.player.y--;
                    display_field(&field);
                } else {
                    display_field(&field);
                }
            }
            
            
        } 
        refresh();
    }
    
}
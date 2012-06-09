#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    EMPTY = 0,
    FIELD_X = 1,
    FIELD_O = 2
} field_t;

static field_t field[3][3] = { { EMPTY, EMPTY, EMPTY },
                               { EMPTY, EMPTY, EMPTY },
                               { EMPTY, EMPTY, EMPTY } };

void set_field(int x, int y, field_t val) {
    assert(0 <= x && x < 3 && 0 <= y && y < 3);
    field[x][y] = val;
}

char coord_to_char(int x, int y) {
    assert(0 <= x && x < 3 && 0 <= x && x < 3);
    field_t f = field[x][y];
    return f == EMPTY ? ' ' :
           f == FIELD_X ? 'X' : 'O';
}

void print_field(void) {
    printf("#############\n");
    printf("#   #   #   #\n");
    printf("# %c # %c # %c #\n", coord_to_char(0, 0), coord_to_char(1, 0), coord_to_char(2, 0));
    printf("#   #   #   #\n");
    printf("#############\n");
    printf("#   #   #   #\n");
    printf("# %c # %c # %c #\n", coord_to_char(0, 1), coord_to_char(1, 1), coord_to_char(2, 1));
    printf("#   #   #   #\n");
    printf("#############\n");
    printf("#   #   #   #\n");
    printf("# %c # %c # %c #\n", coord_to_char(0, 2), coord_to_char(1, 2), coord_to_char(2, 2));
    printf("#   #   #   #\n");
    printf("#############\n");
}

field_t test_winner(void) {
    field_t winner;
    for (int i = 0; i < 3; i++) {
        winner = field[i][0] & field[i][1] & field[i][2];
        if (winner != EMPTY)
            return winner;
        winner = field[0][i] & field[1][i] & field[2][i];
        if (winner != EMPTY)
            return winner;
    }
    winner = field[0][0] & field[1][1] & field[2][2];
    if (winner != EMPTY)
        return winner;
    winner = field[2][0] & field[1][1] & field[0][2];
    if (winner != EMPTY)
        return winner;
    return EMPTY;
}

bool test_full(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (field[i][j] == EMPTY)
                return false;
        }
    }
    return true;
}

void get_coords(int *x, int *y) {
    while (true) {
        *x = -1;
        *y = -1;
        printf("x = ");
        scanf("%d", x);
        printf("y = ");
        scanf("%d", y);
        if (*x > 2 || *x < 0 || *y > 2 || *y < 0) {
            printf("Ungültige Koordinaten!\n");
            continue;
        }
        if (field[*x][*y] != EMPTY) {
            printf("Feld ist voll!\n");
            continue;
        }
        break;
    }
}

void clear_field(void) {
    memset(field, 0, sizeof(field));
}

void announce_winner(field_t winner) {
    if (winner == EMPTY) {
        printf("\n==================\n");
        printf("= Unentschieden! =\n");
        printf("==================\n\n");
        clear_field();
        return;
    }
    printf("\n======================\n");
    printf("= Spieler %d gewinnt! =\n", winner == FIELD_X ? 1 : 2);
    printf("======================\n\n");
    clear_field();
}

int main(int argc, char **argv) {
    int player = 1;
    while (true) {
        print_field();
        int x, y; 
        get_coords(&x, &y);
        set_field(x, y, player ? FIELD_X : FIELD_O);
        field_t winner = test_winner();
        if (winner != EMPTY) {
            announce_winner(winner);
            continue;
        }
        if (test_full()) {
            announce_winner(EMPTY);
            continue;
        }
        player = 1 - player;
    }
}

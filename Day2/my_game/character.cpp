#include "character.h"

character::character(int firstCoordinate, int secondCoordinate, WINDOW *inpWnd) {
    x = secondCoordinate;
    y = firstCoordinate;
    wnd = inpWnd;
}

bool character::possibleDraw() {
    int maxY, maxX, minX = 0, minY = 0;
    getmaxyx(wnd, maxY, maxX);
    return (y - halfHeightUp > minY && y + halfHeightDown < maxY && x + halfWidth < maxX && x - halfWidth > minX);
}

void character::draw(bool stand) {
    if (!possibleDraw()) {
        return;
    }
    drawStatic();
    if (stand) {
        drawStand();
    } else {
        drawMove();
    }
}

void character::drawStand() {
    // legs
    for (int i = y; i != y + 3; ++i) {
        for (int j = x - 2; j != x + 3; ++j) {
            if (j != x) {
                move(i, j);
                addch('|');
            }
        }
    }
    refresh();

    // face
    move(y - 5, x);
    addch('-');
    move(y - 6, x - 1);
    addch('*');
    move(y - 6, x + 2);
    addch('*');
    refresh();


}

void character::drawMove() {
    // legs
    move(y, x - 1);
    addch('/');
    move(y, x - 2);
    addch('/');
    move(y + 1, x - 2);
    addch('/');
    move(y + 1, x - 3);
    addch('/');
    move(y + 2, x - 3);
    addch('/');
    move(y + 2, x - 4);
    addch('/');

    move(y, x + 1);
    addch(92);
    move(y, x + 2);
    addch(92);
    move(y + 1, x + 2);
    addch(92);
    move(y + 1, x + 3);
    addch(92);
    move(y + 2, x + 3);
    addch(92);
    move(y + 2, x + 4);
    addch(92);
    refresh();

    // face
    move(y - 5, x);
    addch('O');
    move(y - 6, x - 1);
    addch('>');
    move(y - 6, x + 2);
    addch('<');
    refresh();

}

void character::drawStatic() {

    // bottom
    move(y - 1, x);
    addch('_');
    refresh();

    // body
    move(y - 1, x - 2);
    addch('|');
    move(y - 2, x - 2);
    addch('|');
    move(y - 1, x + 2);
    addch('|');
    move(y - 2, x + 2);
    addch('|');
    refresh();

    // hands

    move(y - 1, x - 5);
    addch('/');
    move(y - 1, x - 4);
    addch('/');
    move(y - 2, x - 4);
    addch('/');
    move(y - 2, x - 3);
    addch('/');
    move(y - 3, x - 3);
    addch('/');

    move(y - 1, x + 5);
    addch(92);
    move(y - 1, x + 4);
    addch(92);
    move(y - 2, x + 4);
    addch(92);
    move(y - 2, x + 3);
    addch(92);
    move(y - 3, x + 3);
    addch(92);
    refresh();

    // shoulders

    move(y - 4, x - 2);
    addch('_');
    move(y - 4, x - 1);
    addch('|');
    move(y - 4, x + 2);
    addch('_');
    move(y - 4, x + 1);
    addch('|');
    refresh();

    // head

    move(y - 5, x - 1);
    addch('_');
    move(y - 5, x - 2);
    addch('_');
    move(y - 5, x - 3);
    addch('|');
    move(y - 6, x - 3);
    addch('|');
    move(y - 7, x - 3);
    addch('|');
    move(y - 8, x - 2);
    addch('_');
    move(y - 8, x - 1);
    addch('_');
    move(y - 8, x);
    addch('_');

    move(y - 5, x + 1);
    addch('_');
    move(y - 5, x + 2);
    addch('_');
    move(y - 5, x + 3);
    addch('|');
    move(y - 6, x + 3);
    addch('|');
    move(y - 7, x + 3);
    addch('|');
    move(y - 8, x  + 2);
    addch('_');
    move(y - 8, x + 1);
    addch('_');
    refresh();
}

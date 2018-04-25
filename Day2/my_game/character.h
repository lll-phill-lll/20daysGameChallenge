#ifndef CHARACTER_H
#define CHARACTER_H


#include <curses.h>

class character {
 private:
    int x, y;
    WINDOW *wnd;
    int halfWidth = 5;
    int halfHeightUp = 7;
    int halfHeightDown = 3;


    bool possibleDraw();
    void drawStatic();
    void drawMove();
    void drawStand();


 public:
    character(int firstCoordinate, int secondCoordinate, WINDOW *inpWnd);
    void draw(bool stand);
    void unDraw();
};

#endif // CHARACTER_H

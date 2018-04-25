#include <string>
#include <iostream>
#include <character.h>


int main() {
    WINDOW *wnd;
    wnd = initscr();

    cbreak();
    noecho();

    int nrows, ncols;
    getmaxyx(wnd, nrows, ncols);

    // standing character
    character man(nrows - 4, ncols / 2, wnd);
    man.draw(true);

    // running character

    character man2(nrows - 4, ncols / 2 - 15, wnd);
    man2.draw(false);

    char d;
    while (1) {
        d = getch(); // curses call to input from keyboard
        if (d == 'q') break;
    }
    endwin();
}

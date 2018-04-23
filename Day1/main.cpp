#include <string>
#include <curses.h>
#include <iostream>

// http://heather.cs.ucdavis.edu/~matloff/UnixAndC/CLanguage/Curses.pdf

void draw_body(int y_center, int x_center) {
    // int y_center = y_max - 4;
    // int x_center = x_max / 2;

    // legs
    for (int y = y_center; y != y_center + 4; ++y) {
        for (int x = x_center - 2; x != x_center + 3; ++x) {
            if (x != x_center) {
                move(y, x);
                insch('|');
            }
        }
    }
    refresh();

    // bottom
    // y_center = y_max - 5;
    // x_center = x_max / 2;
    move(y_center - 1, x_center);
    insch('_');
    refresh();
}


int main() {
    WINDOW *wnd;
    wnd = initscr();

    cbreak();
    noecho();

    int nrows, ncols;
    getmaxyx(wnd, nrows, ncols);

    draw_body(nrows - 4, ncols / 2);
    /* move(nrows - 1, ncols / 2);
    insch('*');
    refresh(); */

    // std::cout << nrows << " " << ncols << "\n";

    char d;
    while (1) {
        d = getch(); // curses call to input from keyboard
        if (d == 'q') break;
    }
    endwin();
    return 0;
}

#include <ncurses.h>

#include "utils.h"
#include "time.h"

#define BOARD_HEIGHT 20
#define BOARD_WIDTH 10

#define WIN_BOX_WIDTH 2
#define WIN_WIDTH_ADJUST 2

#define MS_PER_FRAME 16

void init_ncurses();

int main()
{
    init_ncurses();

    WINDOW *board_win = newwin(BOARD_HEIGHT + WIN_BOX_WIDTH, BOARD_WIDTH * WIN_WIDTH_ADJUST + WIN_BOX_WIDTH, 0, 0);
    box(board_win, 0, 0);

    int ch;
    while (true)
    {
      long start = get_current_time();
      //process_input
      //update
      //render
      wrefresh(board_win);
      delay(start + MS_PER_FRAME - get_current_time());
    }



    refresh(); // update screen
    wrefresh(board_win); // refresh board win
    getch(); // wait for user input
    endwin(); // end ncurses

    return 0;
}

void init_ncurses() 
{
    initscr();             // to initialize ncurses
    noecho();              // disable echo mode in terminal
    cbreak();              // disable line buffering
    keypad(stdscr, TRUE);  // enable additional keys (F1, arrows etc)
    curs_set(0);           // hide cursor
    nodelay(stdscr, TRUE); // non-blocking getch
    refresh();
}

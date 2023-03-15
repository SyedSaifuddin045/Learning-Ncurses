#include <curses.h>
#include <ncurses.h>

int main(int argc, char *argv[]) {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, true);

  int max_x, max_y;
  getmaxyx(stdscr, max_y, max_x);

  WINDOW *win = newwin(max_y - 2, max_x - 2, 1, 1);
  printw("Initial Height = %d and Width = %d", max_y, max_x);
  box(win, 0, 0);

  refresh();
  wrefresh(win);

  int ch;
  int height, width, start_y, start_x;

  while ((ch = getch()) != KEY_F(1)) {

    getbegyx(win, start_y, start_x);
    getmaxyx(win, height, width);

    if (ch == ' ' && height > 4 && width > 13) {

      wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
      wrefresh(win);
      wclear(win);

      wresize(win, height - 2, width - 2);
      mvwin(win, start_y + 1, start_x + 1);
      box(win, 0, 0);

      wmove(win, (height / 2) - 1, (width / 2 - 11));
      wprintw(win, "Height = %d , Width = %d.", height, width);

      refresh();
      wrefresh(win);
    }
    if (ch == '\n' && height < max_y-2 && width < max_x-2) {
      wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
      wrefresh(win);
      wclear(win);

      wresize(win, height + 2, width + 2);

      mvwin(win, start_y - 1, start_x - 1);
      box(win, 0, 0);
      wmove(win, (height / 2)+1 , (width / 2 - 10));

      wprintw(win, "Height = %d , Width = %d.", height, width);

      refresh();
      wrefresh(win);
    }
  }

  delwin(win);
  endwin();

  return 0;
}

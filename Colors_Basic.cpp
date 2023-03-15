#include <cstdlib>
#include <curses.h>
#include<cstring>
#include <ncurses.h>


void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);

int main(int argc, char *argv[]) {
  initscr();
  if (has_colors() == true) {
    start_color();
  }

  else {
    endwin();
    printf("Your Terminal Does not support Color");
    exit(1);
  }
  init_pair(1,COLOR_RED,COLOR_YELLOW);
  attron(COLOR_PAIR(1)|A_BLINK);
  print_in_middle(stdscr,LINES/2,0,0,(char*)"Hemlo");
  refresh();
  getch();
  endwin();
  return 0;
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = std::strlen(string);
	temp = (float)(width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}

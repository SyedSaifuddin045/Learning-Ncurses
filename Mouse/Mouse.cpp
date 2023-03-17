#include <ncursescpp/Window.hpp>

#include <ncursescpp/Ncurses.hpp>
#include <string>
#include <vector>

#include <curses.h>

std::vector<std::string> choices = {"Choice 1", "Choice 2", "Choice 3",
                                    "Chocie 4", "Choice 5", "EXIT"};

int m_height = choices.size() + 2, m_width = choices[1].size() * 2, m_y = 1,
    m_x = 1;
int t_y = 0, t_x = 0;
void print_menu(nccpp::Window *W, int highlight);

int main(int argc, char *argv[]) {
  nccpp::Window *menu_win;
  int choice = -1, highlight = 1;

  nccpp::ncurses();
  nccpp::ncurses().clear();
  nccpp::ncurses().raw(false);
  nccpp::ncurses().echo(false);
  nccpp::ncurses().cbreak(true);
  nccpp::ncurses().keypad(true);

  t_x = nccpp::ncurses().column_count();
  t_y = nccpp::ncurses().line_count();

  nccpp::ncurses().attron(A_REVERSE);

  nccpp::ncurses().addstr("Click on EXIT to Quit ! \n t_y:" +
                          std::to_string(t_y));
  nccpp::ncurses().refresh();
  nccpp::ncurses().attroff(A_REVERSE);

  menu_win = new nccpp::Window(m_height, m_width, (t_y - m_height) / 2,
                               (t_x - m_width) / 2);
  print_menu(menu_win, 1);

  nccpp::ncurses().mousemask(30, nullptr);
  while (1) {
    int ch = getch();
    switch (ch) {
    case KEY_MOUSE:
      MEVENT event;
      if (nccpp::ncurses().getmouse(event) == OK) {
        if (event.bstate & BUTTON1_PRESSED) {
          int row = event.y - (t_y / 2) + (choices.size() / 2);
          int col = (event.x - (m_width / 2)) + (choices[1].size() / 2);
          // int index = row;
          nccpp::ncurses().refresh();
          if (row >= 0 && row < choices.size() && col >= 0) {
            choice = row;
          }
        }
      }
      break;
    case KEY_UP:
      if (highlight == 1)
        highlight = choices.size();
      else
        highlight--;
      break;
    case KEY_DOWN:
      if (highlight == choices.size())
        highlight = 1;
      else
        highlight++;

      break;

    case KEY_ENTER:
      choice = highlight - 1;
      break;
    default:
      nccpp::ncurses().clear();
      nccpp::ncurses().mvprintw(t_y - 1, 0, "You pressed : %c ", ch);
      nccpp::ncurses().refresh();
      break;
    }

    print_menu(menu_win, highlight);

    if (choice != -1) {

      break;
    }
  }
  nccpp::ncurses().mvaddstr(t_y - 1, 0, "Your Choice : " + choices[choice]);

  print_menu(menu_win, choice+1);
  nccpp::ncurses().getch();
  menu_win->destroy();
  return 0;
}

void print_menu(nccpp::Window *W, int highlight) {
  int y = m_y, x = (m_width / 2) - (choices[1].size() / 2);
  W->box(0, 0);
  for (int i = 0; i < choices.size(); i++) {
    if (highlight == i + 1) {
      W->attron(A_REVERSE);
      W->mvaddstr(y, x, choices[i]);
      W->attroff(A_REVERSE);
    } else {
      W->mvaddstr(y, x, choices[i]);
    }
    y++;
  }
  W->refresh();
}

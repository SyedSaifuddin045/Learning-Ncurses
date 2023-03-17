#include <ncursescpp/Color.hpp>
#include <ncursescpp/Window.hpp>

#include <ncursescpp/Ncurses.hpp>
#include <string>

int main(int argc, char *argv[]) {
  // declaring a normal string to print
  std::string str = "A string";
  // variables to store max_x,max_y and wmax_x,wmax_y
  int mx, my, by, bx;
  // similar to init_scr
  nccpp::ncurses().start_color();
  // Trying to change color but I guess not supported in mhy terminal
  nccpp::ncurses().init_color(10, 0, 0, 1000);
  // declaring a new Color similar to init_pair from ncurses
  nccpp::Color C = nccpp::Color(10, 0);
  // getting The max row ,column of the terminal
  my = nccpp::ncurses().line_count();
  mx = nccpp::ncurses().column_count();
  // Creating a new Window of size row - 2 and col - 2
  nccpp::Window *W = new nccpp::Window(my - 2, mx - 2, 1, 1);
  // Adding these values to the string for clarification
  str += ",Size :" + std::to_string(mx) + " , " + std::to_string(my);
  // Creating a border around the window with default characters.
  W->box(0, 0);
  // getting the window's max_x and max_y.
  W->get_maxyx(by, bx);
  // getting reference to the attribute of our color
  auto A = nccpp::ncurses().color_to_attr(C);
  // Turing on attributes of the terminal.
  W->attron(A_BOLD | A_UNDERLINE | A);
  // moving the cursor to middle and printing the string in the middle.
  W->mvaddstr((by / 2) + 1, (bx - str.length()) / 2, str);
  // refreshing to make sure the string appears.
  W->refresh();
  // making the application wait for a input to see results.
  W->getch();

  return 0;
}

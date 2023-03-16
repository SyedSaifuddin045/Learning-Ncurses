#include <ncursescpp/Window.hpp>
#include<string>
#include<ncursescpp/Ncurses.hpp>

int main (int argc, char *argv[])
{
  std::string str = "A string";
  int mx,my,by,bx;
  nccpp::ncurses();
  my = nccpp::ncurses().line_count();
  mx = nccpp::ncurses().column_count();
  nccpp::Window* W = new nccpp::Window(my-2,mx-2,1,1);
  str +=", Window Size :" + std::to_string(mx) +" , " + std::to_string(my);
  W->box(0, 0);
  W->get_maxyx(by, bx);
  W->attron(A_BOLD|A_BLINK);
  W->mvaddstr((by/2)+1,(bx-str.length())/2,str);
  W->refresh();
  W->getch();

  return 0;
}

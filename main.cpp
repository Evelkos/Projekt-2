#include "interface.hpp"

using namespace std;

int main()
{
  Owner ow;
  std::cout<<"Wskaznik na pierwszy element listy ksiegarni: "<<ow.get_firstBs()<<std::endl;
  main_menu(ow);
/*
  Bookshop b;
  b.show_books();
  b.new_book();
  b.show_books();
  b.new_book();
  b.show_books();
*/

  return 0;
}

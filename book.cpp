#include"book.hpp"

Book::Book(std::string n, std::string a, std::string p, float pr, int y, int pag, int nu, int nO): name(n), author(a), publisher(p), price(pr), year(y), pages(pag), number(nu), nOrd(nO)
{
  // D(std::cout<<"Utworzono nowa ksiazke"<<std::endl;)
  std::cout<<"Utworzono ksiazke!"<<std::endl;
}

Book::~Book()
{
  //  D(std::cout<<"Usuwamy ksiazke!"<<std::endl;)
  std::cout<<"Usunieto ksiazke!"<<std::endl;
}

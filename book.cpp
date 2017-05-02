#include"book.hpp"

Book::Book(std::string n, std::string a, std::string p, float pr, int y, int pag, int nu, int nO): name(n), author(a), publisher(p), price(pr), year(y), pages(pag), number(nu), nOrd(nO)
{
  D(std::cout <<"Tworze ksiazke"<<std::endl;)
}

Book::~Book()
{
  D(std::cout<<"Usuwamy ksiazke!"<<std::endl;)
}

std::ostream& operator<< (std::ostream &os, Book *b)
{
  os <<b->name<<"  "<<b->author<<"  "<<b->publisher<<"  "<<b->price<<"  "<<b->year<<"  "<<b->pages<<"  "<<b->number<<std::endl;
  return os;
}

Book& Book::operator= (Book &b2)
{
  this->name = b2.get_name();
  this->author = b2.get_author();
  this->publisher = b2.get_publisher();
  this->price = b2.get_price();
  this->year = b2.get_year();
  this->pages = b2.get_pages();
  this->number = b2.get_number();
  this->nOrd = b2.get_nOrd();
  return *this;
}

bool Book::operator== (Book& o)
{
  int i = 0;
  if(this->get_name() == o.get_name() && this->get_author() == o.get_author() && this->get_publisher() == o.get_publisher())
    i = 1;
  return i;
}

//wylicza cene hurtowa ksiazki
float quantity_pr(int year, int pages)
{
    return year*pages/22000;
}

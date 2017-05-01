#ifndef book_h
#define book_h

//#include "debug_head.hpp"
#include<iostream>
//#include<time.h>
//#include<cstdlib>
//#include<string.h>

class Book
{
  std::string name, author, publisher;
  float price;
  int year, pages, number, nOrd; //nOrd - ilosc zamowionych egzemplarzy

  public:

  Book(std::string = "-", std::string = "-", std::string = "-", float = 0.0, int = 0, int = 0, int = 0, int = 0);
  ~Book();

  std::string get_name() {return name;}
  std::string get_author() {return author;}
  std::string get_publisher() {return publisher;}
  float get_price() {return price;}
  int get_year() {return year;}
  int get_pages() {return pages;}
  int get_number() {return number;}
  int get_nOrd() {return nOrd;}

  void set_name(std::string n) {name = n;}
  void set_author(std::string a) {author = a;}
  void set_publisher(std::string p) {publisher = p;}
  void set_price(float pr) {price = pr;}
  void set_year(int y) {year = y;}
  void set_pages(int pag) {pages = pag;}
  void set_number(int n) {number = n;}
  void set_nOrd(int nO) {nOrd = nO;}

  friend std::ostream& operator<< (std::ostream &os, Book *b) {os <<b->name<<"  "<<b->author<<"  "<<b->publisher;
  os <<"  "<<b->price<<"  "<<b->year<<"  "<<b->pages<<"  "<<b->number<<std::endl; return os;}
  Book& operator= (Book &b2);
  bool operator== (Book& o);
};

float quantity_pr(int, int);

#endif

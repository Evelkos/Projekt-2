#include "bookshop.hpp"

int Bookshop::numBookshops = 0;

Bookshop::Bookshop(std::string n, std::string c, double b): name(n), city(c), budget(b), firstB(NULL), order(NULL), oA(0)
{
  numBookshops++;
  D(std::cout <<"Tworze ksigarnie"<<std::endl;)
}

Bookshop::~Bookshop()
{
  while(firstB != NULL)
    firstB = delete_o(1, firstB);
  while(firstE != NULL)
    firstE = delete_o(1, firstE);
  while(firstC != NULL)
    firstC = delete_o(1, firstC);

  D(std::cout <<"Niszcze ksigarnie"<<std::endl;)
  numBookshops--;
}

Bookshop& Bookshop::operator= (Bookshop &b2)
{
  this->name = b2.get_name();
  this->city = b2.get_city();
  this->budget = b2.get_budget();
  this->oA = 0;
  return *this;
}

std::ostream& operator<< (std::ostream &os, Bookshop *b)
{
  os<<b->get_name()<<" "<<b->get_city()<<" "<<b->get_budget()<<std::endl;
  return os;
}

//UWAGA: DOPRACOWAC WYSWIETLANIE - KLIENTOM NI MOZE WYSWIETLAC SIE LISTA, JESLI NIE MA ZADNYCH EGZEMPLARZY!
//wyswietla liste ksiazek, zwraca liczbe ksiazek "dostepnych" w zaleznosci od tego kto widzi liste
void Bookshop::show_book(){ show_l(firstB);}

//zbiera informacje o ksiazce, ktora ma zostac stworzona, dodaje ja do listy
void Bookshop::new_book()
{
  string t, a, p;
  int no, y, pag;
  double pr;

  srand(time(NULL));
  y = rand()%50+1967;
  pag = rand()%400+154;
  std::cout<<"Tytul: ";                                                        std::cin>>t;
  std::cout<<"Autor: ";                                                        std::cin>>a;
  std::cout<<"Wydawca: ";                                                      std::cin>>p;
  std::cout<<"Ilosc zamawianych egzemplarzy: ";                                std::cin>>no;
  std::cout<<"Cena egzemplarza w hurtowni: "<<quantity_pr(y, pag)<<std::endl;
  std::cout<<"Ustal cene ksiazki w ksiegarni: ";                               std::cin>>pr;

  Book b(t, a, p, pr, y, pag, 0, no);
  firstB = new_o(firstB, b);
}

//usuwa ksiazke o zadanym numerze, zwraca do budzetu 30% ceny hurtowej egzemplarzy
void Bookshop::withdraw_book(int n)
{
  int i;
  List<Book> *current = firstB;

  for(i = 1 ; i < n ; i++)
    current = current->get_next();
  budget -= 0.3*quantity_pr(current->obj.get_year(), current->obj.get_pages());
  delete_o(n, firstB);
}

//wyszukuje z listy ksiazke o zadanym tytule, autorze, wydawnictwie, kategorii i zwraca na nia wskaznik
List<Book>* Bookshop::find_book(std::string t, std::string a, std::string p)
{
  Book b(t, a, p);
  return find_o(b, firstB);
}


//wyswietla liste klientow ksiegarni
void Bookshop::show_customer_list() {show_l(firstB);}

//tworzy nowego klienta na podstawie wprowadzonych danych, umieszcza go na koncu listy klientow, zwraca nan wskaznik
void Bookshop::add_to_list_customer()
{
  std::string n, s;
  double m;

  std::cout<<"Imie: ";         std::cin>>n;
  std::cout<<"Nazwisko: ";     std::cin>>s;
  std::cout<<"Pieniadze: ";    std::cin>>m;

  Customer c(n, s, m);
  firstC = new_o(firstC, c);
}

//usuwa klienta, ktorego numer zostal dany
void Bookshop::delete_customer(int n)
{
  int i;
  List<Customer> *current = firstC;

  for(i = 1 ; i < n ; i++)
    current = current->get_next();
  delete_o(n, firstC);
}

//wyswietla liste pracownikow, zwraca ich liczbe
void Bookshop::show_employee_list(){ show_l(firstE); }


//usuwa pracownika, ktorego numer zostal dany
void Bookshop::delete_employee(int n)
{
  int i;
  List<Employee> *current = firstE;

  for(i = 1 ; i < n ; i++)
    current = current->get_next();
  budget -= current->get_obj()->get_salary();
  delete_o(n, firstE);
}

//tworzy nowego pracownika na podstawie wybranych przez uzytkonika danych
void Bookshop::new_employee()
{
  std::string n, s;
  double sal;

  std::cout<<"Nowy pracownik: "<<std::endl;
  std::cout<<"Imie: ";       std::cin>>n;
  std::cout<<"Nazwisko: ";   std::cin>>s;
  std::cout<<"Pensja: ";     std::cin>>sal;

  Employee e(n, s, sal);
  firstE = new_o(firstE, e);
}

#include "functions.hpp"

void tests()
{
  Bookshop *b1 = NULL, *b2 = NULL, *bf = NULL, *bl = NULL;
  int i;

  std::cout<<std::endl<<"TEST KLASY BOOKSHOP"<<std::endl<<std::endl<<"Na poczatek tworzymy obiekt automatyczny"<<std::endl;
  Bookshop b("KSIEGARNIA", "MIASTO", 987.65, &b1, &b2);
  std::cout<<std::endl<<"Przeciazenie operatora << (wyswietlanie informacji o obiekcie):"<<std::endl;
  std::cout<<&b;
  std::cout<<"Przeciazenie operatora + (zwiekszenie budzetu - w tym wypadku o 200):"<<std::endl;
  b + 200;
  std::cout<<&b;
  std::cout<<"Przeciazenie operatora - (zmniejszenie budzetu - w tym wypadku o 100):"<<std::endl;
  b - 100;
  std::cout<<&b;


  std::cout<<std::endl<<"Tworzymy okiekty dynamicznie"<<std::endl<<"Ze wzgledu na specyfikacje funkcji uzytkownik proszony jest o podanie potrzebnych danych"<<std::endl;
  for(i = 0 ; i < 5 ; i++)
    add_to_list_bookshop(&bf, &bl);
  std::cout<<std::endl<<"Lista obiektow utworzonych dynamicznie:"<<std::endl;
  show_bookshop_list(bf);
  std::cout<<std::endl<<"Test statycznej metody zwracajacej liczbe obiektow"<<std::endl<<"Liczba ksiegarni: "<<Bookshop::get_numBookshops()<<std::endl;


  std::cout<<std::endl<<"Usuwamy obiekty kolejno: ostatni, trzeci, pierwszy"<<std::endl;
  delete_bookshop(&bf, &bl, 5);
  delete_bookshop(&bf, &bl, 3);
  delete_bookshop(&bf, &bl, 1);
  std::cout<<std::endl<<"Lista ksiegarni po usunieciu obiektow:"<<std::endl;
  show_bookshop_list(bf);
  std::cout<<std::endl<<"Usuwamy pozostale obiekty utworzone dynamicznie"<<std::endl;
  while(bf != NULL)
    delete_bookshop(&bf, &bl, 1);
  bf = NULL;
  bl = NULL;


  std::cout<<std::endl<<"Tworzymy obiekt statyczny"<<std::endl;
  static Bookshop bs("KSIEGARNIA", "STATYCZNA", 999.99, &bf, &bl);
  cout<<&bs;
  std::cout<<std::endl<<"Obiekt statyczny zostanie usuniety na zakonczeniu programu"<<std::endl;

  std::cout<<std::endl<<"Po zakonczonym tescie niszczony jest obiekt automatyczny"<<std::endl;
}


void testsb()
{
  int i;
  Book b1("Ksiazka", 0, "Autor", "Wydawca", 2017, 500 , 0 , 0);
  Bookshop *bs, *bs1 = NULL, *bs2 = NULL;

  std::cout<<"TEST KLASY BOOK"<<std::endl<<"Tworzymy obiekt automatyczny"<<std::endl;
  std::cout<<std::endl<<"Przeciazenie operatora << (wyswietlanie informacji o obiekcie):"<<std::endl;
  std::cout<<&b1;


  std::cout<<std::endl<<"Tworzymy obiekty dynamicznie."<<std::endl<<"W tym celu pomocniczo tworzymy ksiegarnie"<<std::endl;
  bs = new Bookshop("KSIEGARNIA", "POMOCNICZA", 987.65, &bs1, &bs2);
  std::cout<<std::endl<<"Nastepnie tworzymy ksiazki i dodajemy je do listy"<<std::endl;
  for(i = 0 ; i < 4 ; i++)
    bs->add_to_list_book("KSIAZKA", "AUTOR", "WYDAWCA", i+1, 1);
    bs->add_to_list_book("TAKA", "KTORA", "JEST", i+1, 1);  //ksiazka tworzona poza petla - do wyszukiwania ksiazek
  std::cout<<std::endl<<"Lista obiektow utworzonych dynamicznie:";
  bs->show_book_list(0);


  std::cout<<std::endl<<"Testujemy wyszukiwanie ksiazek"<<std::endl<<"Szukamy ksiazki o tytulu \"TAKA\", napisanej przez \"KTORA\", wydanej przez \"JEST\""<<std::endl;
  if(bs->find_book("TAKA", "KTORA", "JEST") != NULL)
  {
    cout<<"Ksiazka zostala znaleziona. Oto ona:"<<std::endl;
    cout<<bs->find_book("TAKA", "KTORA", "JEST");
  }
  else std::cout<<"Ksiazka nie zostala znaleziona"<<std::endl;


  std::cout<<std::endl<<"Teraz szukamy ksiazki o tytulu \"TAKA\", napisanej przez \"KTOREJ\", wydanej przez \"NIE_MA\""<<std::endl;
  if(bs->find_book("TAKA", "KTOREJ", "NIE_MA") != NULL)
  {
    cout<<"Ksiazka zostala znaleziona. Oto ona:"<<std::endl;
    cout<<bs->find_book("TAKA", "KTOREJ", "NIE_MA");
  }
  else std::cout<<"Ksiazka nie zostala znaleziona"<<std::endl;


  std::cout<<std::endl<<"Usuwamy obiekty kolejno: ostatni, trzeci, pierwszy"<<std::endl;
  bs->delete_book(5);
  bs->delete_book(3);
  bs->delete_book(1);

  std::cout<<std::endl<<"Lista ksiazek po usunieciu obiektow:";
  bs->show_book_list(0);
  std::cout<<std::endl<<"Usuwamy pozostale obiekty utworzone dynamicznie"<<std::endl;
  while(bs->get_firstB() != NULL)
    bs->delete_book(1);
  std::cout<<std::endl<<"Usuwamy pomocnicza ksiegarnie"<<std::endl;
  delete(bs);

  std::cout<<std::endl<<"Tworzymy obiekt statyczny"<<std::endl;
  static Book b2("TO", 9.99, "KSAIZKA", "STATYCZNA", 2017, 200, 1, 0);
  cout<<&b2;
  std::cout<<std::endl<<"Obiekt statyczny zostanie usuniety na zakonczeniu programu"<<std::endl;


  std::cout<<std::endl<<"Po zakonczonym tescie niszczony jest obiekt automatyczny"<<std::endl;
}


void testsc()
{
  Bookshop *bs, *bf = NULL, *bl = NULL;
  int i;

  std::cout<<std::endl<<"TEST KLASY CUSTOMER"<<std::endl<<std::endl<<"Na poczatek tworzymy obiekt automatyczny"<<std::endl;
  Customer c("Jan", "KOWALSKI", 99.99);
  std::cout<<&c;


  std::cout<<std::endl<<"Przeciazenie operatora += (zwiekszenie budzetu klienta o zadana liczbe - w tym wypadku 100):"<<std::endl;
  c += 100;
  std::cout<<&c;


  std::cout<<std::endl<<"Testujemy przegladanie kolekcji klienta"<<std::endl<<"Do kolekcji nie zostala dodana jeszcze zadna ksiazka:"<<std::endl;
  c.show_collection();
  std::cout<<std::endl<<"Dodajemy kolejno dwie ksiazki."<<std::endl;
  c.add_to_collection("Ksiazka1", "Autor1", "Wydawca1", 1);
  c.add_to_collection("Ksiazka2", "Autor2", "Wydawca2", 1);
  std::cout<<std::endl<<"Po dodaniu dwoch ksiazek:";
  c.show_collection();
  std::cout<<"Powstale ksiazki zostana usuniete podczas niszczenia obiektu automatycznego"<<std::endl;


  std::cout<<std::endl<<"Tworzymy okiekty dynamicznie"<<std::endl<<"W tym celu pomocniczo tworzymy ksiegarnie"<<std::endl;
  bs = new Bookshop("KSIEGARNIA", "POMOCNICZA", 987.65, &bf, &bl);
  std::cout<<"Ze wzgledu na specyfikacje funkcji uzytkownik proszony jest o podanie potrzebnych danych"<<std::endl;
  for(i = 0 ; i < 5 ; i++)
    bs->add_to_list_customer();

  std::cout<<std::endl<<"Lista obiektow utworzonych dynamicznie:"<<std::endl;
  bs->show_customer_list();


  std::cout<<"Usuwamy obiekty kolejno: ostatni, trzeci, pierwszy"<<std::endl;
  bs->delete_customer(5);
  bs->delete_customer(3);
  bs->delete_customer(1);
  std::cout<<std::endl<<"Lista klientow po usunieciu obiektow:"<<std::endl;
  bs->show_customer_list();
  std::cout<<std::endl<<"Usuwamy pozostale obiekty utworzone dynamicznie"<<std::endl;
  while(bs->get_firstC() != NULL)
    bs->delete_customer(1);
  std::cout<<std::endl<<"Usuwamy pomocnicza ksiegarnie"<<std::endl;
  delete(bs);


  std::cout<<std::endl<<"Tworzymy obiekt statyczny"<<std::endl;
  static Customer c2("Ewelina", "Chmielewska", 88.88);
  cout<<&c2;
  std::cout<<std::endl<<"Obiekt statyczny zostanie usuniety na zakonczeniu programu"<<std::endl;

  std::cout<<std::endl<<"Po zakonczonym tescie niszczony jest obiekt automatyczny"<<std::endl;
}

void testse()
{
  Bookshop *bs, *bf = NULL, *bl = NULL;
  int i;

  std::cout<<std::endl<<"TEST KLASY EMPLOYEE"<<std::endl<<std::endl<<"Na poczatek tworzymy obiekt automatyczny"<<std::endl;
  Employee e("Piotr", "Nowak", 25, 1200.00);
  cout<<&e;


  std::cout<<std::endl<<"Tworzymy okiekty dynamicznie"<<std::endl<<"W tym celu pomocniczo tworzymy ksiegarnie"<<std::endl;
  bs = new Bookshop("KSIEGARNIA", "POMOCNICZA", 987.65, &bf, &bl);
  std::cout<<"Ze wzgledu na specyfikacje funkcji uzytkownik proszony jest o podanie potrzebnych danych"<<std::endl;
  for(i = 0 ; i < 5 ; i++)
    bs->add_to_list_employee();
  std::cout<<std::endl<<"Lista obiektow utworzonych dynamicznie:"<<std::endl;
  bs->show_employee_list();


  std::cout<<"Usuwamy obiekty kolejno: ostatni, trzeci, pierwszy"<<std::endl;
  bs->delete_employee(5);
  bs->delete_employee(3);
  bs->delete_employee(1);
  std::cout<<std::endl<<"Lista pracownikowni po usunieciu obiektow:"<<std::endl;
  bs->show_employee_list();


  std::cout<<std::endl<<"Usuwamy pozostale obiekty utworzone dynamicznie"<<std::endl;
  while(bs->get_firstE() != NULL)
    bs->delete_employee(1);
  std::cout<<"Usuwamy pomocnicza ksiegarnie"<<std::endl;
  delete(bs);


  std::cout<<std::endl<<"Tworzymy obiekt statyczny"<<std::endl;
  static Employee e2("Ewelina", "Chmielewska", 19, 10.00);
  cout<<&e2;
  std::cout<<std::endl<<"Obiekt statyczny zostanie usuniety na zakonczeniu programu"<<std::endl;


  std::cout<<std::endl<<"Po zakonczonym tescie niszczony jest obiekt automatyczny"<<std::endl;
}

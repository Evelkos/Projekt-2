#include "owner.hpp"

void tests()
{
  int i;

  std::cout<<std::endl<<"TEST KLASY BOOKSHOP"<<std::endl<<std::endl<<"Na poczatek tworzymy obiekt automatyczny"<<std::endl;
  Bookshop b("KSIEGARNIA", "MIASTO", 987.65);
  std::cout<<std::endl<<"Przeciazenie operatora << (wyswietlanie informacji o obiekcie):"<<std::endl;
  std::cout<<&b;
  std::cout<<"Przeciazenie operatora + (zwiekszenie budzetu - w tym wypadku o 200):"<<std::endl;
  b + 200;
  std::cout<<&b;
  std::cout<<"Przeciazenie operatora - (zmniejszenie budzetu - w tym wypadku o 100):"<<std::endl;
  b - 100;
  std::cout<<&b;


  std::cout<<std::endl<<"Tworzymy okiekty dynamicznie"<<std::endl;
  std::cout<<"W tym celu tworzymy pomocniczego wlasciciela"<<std::endl<<"Ze wzgledu na specyfikacje funkcji uzytkownik proszony jest o podanie potrzebnych danych"<<std::endl;
  Owner ow;
  for(i = 0 ; i < 5 ; i++)
    ow.new_bs();
  std::cout<<std::endl<<"Lista obiektow utworzonych dynamicznie:"<<std::endl;
  ow.show_bs();
  std::cout<<std::endl<<"Test statycznej metody zwracajacej liczbe obiektow"<<std::endl<<"Liczba ksiegarni: "<<Bookshop::get_numBookshops()<<std::endl;


  std::cout<<std::endl<<"Usuwamy obiekty kolejno: ostatni, trzeci, pierwszy"<<std::endl;
  ow.delete_bs(5);
  ow.delete_bs(3);
  ow.delete_bs(1);
  std::cout<<std::endl<<"Lista ksiegarni po usunieciu obiektow:"<<std::endl;
  ow.show_bs();
  std::cout<<std::endl<<"Usuwamy pozostale obiekty utworzone dynamicznie"<<std::endl;
  while(ow.get_firstBs() != NULL)
    ow.delete_bs(1);


  std::cout<<std::endl<<"Tworzymy obiekt statyczny"<<std::endl;
  static Bookshop bs("KSIEGARNIA", "STATYCZNA", 999.99);
  cout<<&bs;
  std::cout<<std::endl<<"Obiekt statyczny zostanie usuniety na zakonczeniu programu"<<std::endl;


  std::cout<<std::endl<<"Po zakonczonym tescie niszczony jest obiekt automatyczny"<<std::endl;
}


void testsb()
{
  int i;
  std::cout<<"TEST KLASY BOOK"<<std::endl<<"Tworzymy obiekt automatyczny"<<std::endl;
  Book b("Ksiazka", "Autor", "Wydawca", 9.99, 2017, 123, 1, 0);
  std::cout<<std::endl<<"Przeciazenie operatora << (wyswietlanie informacji o obiekcie):"<<std::endl;
  std::cout<<&b;


  std::cout<<std::endl<<"Tworzymy obiekty dynamicznie."<<std::endl<<"W tym celu pomocniczo tworzymy ksiegarnie"<<std::endl;
  Bookshop bs("KSIEGARNIA", "POMOCNICZA", 99999.99);
  std::cout<<std::endl<<"Nastepnie tworzymy ksiazki i dodajemy je do listy"<<std::endl;
  std::cout<<"Ze wzgledu na specyfikacje funkcji uzytkownik proszony jest o podanie potrzebnych danych"<<std::endl;
  for(i = 0 ; i < 5 ; i++)
    bs.new_book();
  std::cout<<std::endl<<"Lista obiektow utworzonych dynamicznie:"<<std::endl;
  bs.show_books();
  std::cout<<"Przeciazenie operatora = (pierwszy obiekt listy = obiekt utworzony automatycznie):"<<std::endl;
    *(bs.get_firstB()->get_obj()) = b;
  std::cout<<std::endl<<"Lista obiektow utworzonych dynamicznie po zmianie:";
  bs.show_books();


  std::cout<<std::endl<<"Testujemy wyszukiwanie ksiazek"<<std::endl<<"Szukamy ksiazki o tytule \"Ksiazka\", napisanej przez \"Autor\", wydanej przez \"Wydawca\""<<std::endl;
  if(bs.find_book("Ksiazka", "Autor", "Wydawca") != NULL)
    cout<<"Ksiazka zostala znaleziona."<<std::endl;
  else std::cout<<"Ksiazka nie zostala znaleziona"<<std::endl;


  std::cout<<std::endl<<"Teraz szukamy ksiazki o tytulu \"uegrqIUNF\", napisanej przez \"JSEBFIAWbe\", wydanej przez \"OISNFdgs\""<<std::endl;
  if(bs.find_book("uegrqIUNF", "JSEBFIAWbe", "OISNFdgs") != NULL)
    cout<<"Ksiazka zostala znaleziona."<<std::endl;
  else std::cout<<"Ksiazka nie zostala znaleziona"<<std::endl;


  std::cout<<std::endl<<"Usuwamy obiekty kolejno: ostatni, trzeci, pierwszy"<<std::endl;
  bs.delete_book(5);
  bs.delete_book(3);
  bs.delete_book(1);


  std::cout<<std::endl<<"Lista ksiazek po usunieciu obiektow:";
  bs.show_books();
  std::cout<<std::endl<<"Usuwamy pozostale obiekty utworzone dynamicznie"<<std::endl;
  while(bs.get_firstB() != NULL)
    bs.delete_book(1);


  std::cout<<std::endl<<"Tworzymy obiekt statyczny"<<std::endl;
  static Book bo("TO", "KSAIZKA", "STATYCZNA", 9.99, 2017, 200, 1, 0);
  cout<<&bo;
  std::cout<<std::endl<<"Obiekt statyczny zostanie usuniety na zakonczeniu programu"<<std::endl;


  std::cout<<std::endl<<"Po zakonczonym tescie niszczone sa obiekty automatyczne"<<std::endl;
}


void testsc()
{
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
  std::cout<<"Tworzymy automatycznie dwie ksiazki, aby moc dodac je do kolekcji."<<std::endl;
  Book b1("Ksiazka1", "Autor1", "Wydawca1", 8.88, 2017, 123, 1, 0);
  Book b2("Ksiazka2", "Autor2", "Wydawca2", 9.99, 2016, 456, 1, 0);
  std::cout<<"Dodajemy nowo powstale ksiazki do kolekcji"<<std::endl;
  c.add_to_collection(b1);
  c.add_to_collection(b2);
  std::cout<<std::endl<<"Po dodaniu dwoch ksiazek:";
  c.show_collection();
  std::cout<<"Powstale ksiazki zostana usuniete podczas niszczenia obiektu automatycznego"<<std::endl;


  std::cout<<std::endl<<"Tworzymy okiekty dynamicznie"<<std::endl<<"W tym celu pomocniczo tworzymy ksiegarnie"<<std::endl;
  Bookshop bs("Ksiegarnia", "Pomocnicza", 99999.99);
  std::cout<<"Ze wzgledu na specyfikacje funkcji uzytkownik proszony jest o podanie potrzebnych danych"<<std::endl;
  for(i = 0 ; i < 5 ; i++)
    bs.new_customer();


  std::cout<<std::endl<<"Lista obiektow utworzonych dynamicznie:"<<std::endl;
  bs.show_customers();


  std::cout<<"Usuwamy obiekty kolejno: ostatni, trzeci, pierwszy"<<std::endl;
  bs.delete_customer(5);
  bs.delete_customer(3);
  bs.delete_customer(1);
  std::cout<<std::endl<<"Lista klientow po usunieciu obiektow:"<<std::endl;
  bs.show_customers();
  std::cout<<std::endl<<"Usuwamy pozostale obiekty utworzone dynamicznie"<<std::endl;
  while(bs.get_firstC() != NULL)
    bs.delete_customer(1);


  std::cout<<std::endl<<"Tworzymy obiekt statyczny"<<std::endl;
  static Customer c2("Ewelina", "Chmielewska", 88.88);
  cout<<&c2;
  std::cout<<std::endl<<"Obiekt statyczny zostanie usuniety na zakonczeniu programu"<<std::endl;


  std::cout<<std::endl<<"Po zakonczonym tescie niszczone sa obiekty automatyczne"<<std::endl;
}

void testse()
{
  int i;

  std::cout<<std::endl<<"TEST KLASY EMPLOYEE"<<std::endl<<std::endl<<"Na poczatek tworzymy obiekt automatyczny"<<std::endl;
  Employee e("Piotr", "Nowak", 1200.00);
  cout<<&e;


  std::cout<<std::endl<<"Tworzymy okiekty dynamicznie"<<std::endl<<"W tym celu pomocniczo tworzymy ksiegarnie"<<std::endl;
  Bookshop bs("KSIEGARNIA", "POMOCNICZA", 999999.99);
  std::cout<<"Ze wzgledu na specyfikacje funkcji uzytkownik proszony jest o podanie potrzebnych danych"<<std::endl;
  for(i = 0 ; i < 5 ; i++)
    bs.new_employee();
  std::cout<<std::endl<<"Lista obiektow utworzonych dynamicznie:"<<std::endl;
  bs.show_employees();


  std::cout<<"Usuwamy obiekty kolejno: ostatni, trzeci, pierwszy"<<std::endl;
  bs.delete_employee(5);
  bs.delete_employee(3);
  bs.delete_employee(1);
  std::cout<<std::endl<<"Lista pracownikowni po usunieciu obiektow:"<<std::endl;
  bs.show_employees();


  std::cout<<std::endl<<"Usuwamy pozostale obiekty utworzone dynamicznie"<<std::endl;
  while(bs.get_firstE() != NULL)
    bs.delete_employee(1);


  std::cout<<std::endl<<"Tworzymy obiekt statyczny"<<std::endl;
  static Employee e2("Ewelina", "Chmielewska", 10.00);
  cout<<&e2;
  std::cout<<std::endl<<"Obiekt statyczny zostanie usuniety na zakonczeniu programu"<<std::endl;


  std::cout<<std::endl<<"Po zakonczonym tescie niszczone sa obiekty automatyczne"<<std::endl;
}

void testsl()
{
  List<Book> *curr = NULL;
  std::cout<<std::endl<<"TEST SZABLONU KLASY LIST"<<std::endl;
  std::cout<<"Test klasy zostanie zrealizowany przy pomocy klasy Book"<<std::endl;


  std::cout<<std::endl<<"Tworzymy piec przykladowych ksiazek"<<std::endl;
  Book b1("A", "A", "A"), b2("B", "B", "B"), b3("C", "C", "C"), b4("D", "D", "D"), b5("E", "E", "E");
  std::cout<<"Nastepnie tworzymy wskaznik na pierwszy obiekt listy, ktory poczatkowo wskazuje na NULL."<<std::endl;
  std::cout<<"Dodajemy ksiazki w kolejnosci: B, A, C, E, D"<<std::endl;
  List<Book> *f = NULL;  //wskaznik na pierwszy element listy
  f = new_o(f, b2);
  f = new_o(f, b1);
  f = new_o(f, b3);
  f = new_o(f, b5);
  f = new_o(f, b4);
  std::cout<<"Lista ksiazek:"<<std::endl;
  show_l(f);
  std::cout<<"Jest to lista uporzadkowana"<<std::endl;


  std::cout<<std::endl<<"Usuwamy z listy obiekty kolejno: 5, 3, 1"<<std::endl;
  f = delete_o(5, f);
  f = delete_o(3, f);
  f = delete_o(1, f);
  std::cout<<"Lista ksiazek:"<<std::endl;
  show_l(f);

  std::cout<<std::endl<<"Sprawdzamy, czy na liscie znajduje sie obiekt: "<<&b2<<std::endl;
  curr = find_o(b2, f);
  if(curr == NULL)  std::cout<<"Obiektu nie znaleziono"<<std::endl;
  else std::cout<<"Obiekt znaleziono: "<<curr->get_obj()<<std::endl;
  std::cout<<"Sprawdzamy, czy na liscie znajduje sie obiekt: "<<&b3<<std::endl;
  curr = find_o(b3, f);
  if(curr == NULL)  std::cout<<"Obiektu nie znaleziono"<<std::endl;
  else std::cout<<"Obiekt znaleziono: "<<curr->get_obj()<<std::endl;


  std::cout<<std::endl<<"Usuwamy pozostale obiekty utworzone dynamicznie:"<<std::endl;
  while(f != NULL)
    f = delete_o(1, f);


  std::cout<<std::endl<<"Po zakonczonym tescie niszczone sa obiekty automatyczne"<<std::endl;
}

#include "functions.hpp"
extern void tests();
extern void testsb();
extern void testsc();
extern void testse();

//menu glowne
void main_menu(Bookshop **first, Bookshop **last)
{
  char choice, choice2;

  while(choice != '5'){
    std::cout<<std::endl<<"Wybierz osobe"<<std::endl;
    std::cout<<"1. Wlasciciel"<<std::endl;
    std::cout<<"2. Pracownik"<<std::endl;
    std::cout<<"3. Klient"<<std::endl;
    std::cout<<"4. Testy"<<std::endl;
    std::cout<<"5. Koniec"<<std::endl;
    std::cin>>choice;
    switch (choice)
    {
      case '1': //wlasciciel
        bookshop_menu1(first, last);
        break;

      case '2': //pracownik
        if(*first == NULL)
          std::cout<<std::endl<<"Nie powstala jeszcze zadna ksiegarnia. Nie moze byc zadnego pracownika."<<std::endl<<std::endl;
        else
          employee_menu1(*first);
        break;

      case '3': //klient
        if(*first == NULL)
            std::cout<<std::endl<<"Nie powstala jeszcze zadna ksiegarnia. Nie moze byc zadnego klienta."<<std::endl<<std::endl;
        else
          customer_menu1(*first);
        break;
      case '4':
        std::cout<<"TESTY"<<std::endl<<"1. Test klasy bookshop"<<std::endl<<"2. Test klasy book"<<std::endl<<"3. Test klasy customer"<<std::endl<<"4. Test klasy employee"<<std::endl;
        std::cin>>choice2;
        if(choice2 == '1')
          tests();
        else if(choice2 == '2')
          testsb();
        else if(choice2 == '3')
          testsc();
        else if(choice2 == '4')
            testse();
        break;
      case '5':
        break;
      default:
        std::cout<<"Nie ma takiej mozliwosci"<<std::endl<<std::endl;
        break;
    }
  }
}

//menu wlasciciela ksiegarni - ogolne
void bookshop_menu1(Bookshop **first, Bookshop **last)
{
  int number;
  char ii = '0',choice;
  while(ii == '0'){
    std::cout<<std::endl<<"Wlasciciel"<<std::endl;
    std::cout<<"1. wyswietl liste ksiegarni"<<std::endl;
    std::cout<<"2. stworz nowe ksiegarnie"<<std::endl;
    std::cout<<"3. usun ksiegarnie"<<std::endl;
    std::cout<<"4. zarzadzaj ksiegarnia"<<std::endl;
    std::cout<<"5. wyjscie"<<std::endl;

    std::cin>>choice;
    switch(choice)
    {
      case '1':
        show_bookshop_list(*first);
        break;

      case '2':
        std::cout<<std::endl<<"Ile nowych ksiegarni chcesz stworzyc?"<<std::endl;
        std::cin>>number;
        for(int i = 0 ; i < number ; i++)
          add_to_list_bookshop(first, last);
        break;

      case '3':
        if(*first == NULL)
          std::cout<<std::endl<<"Nie mam jeszcze zadnych ksiegarni, wiec nie moge zadnej usunac."<<std::endl;

        else
        {
          Bookshop *current;
          current = *first;

          std::cout<<std::endl<<"Wybierz numer ksiegarni, ktora chcesz usunac"<<std::endl;
          show_bookshop_list(*first);
          std::cin>>number;

          for(int i = 1 ; i < number ; i++)
            current = current->get_next();

            delete_bookshop(first, last, number);
        }
        break;

      case '4':
        if((*first) == NULL)
          std::cout<<std::endl<<"Nie istnieje jeszcze zadna ksiegarnia. Stworz ksiegarnie, aby zaczac nia zarzadzac."<<std::endl;
        else
          bookshop_menu2(*first);
        break;

      case '5':
        ii = '1';
        break;

      default:
        std::cout<<"Przykro mi, nie ma takiej mozliwosci"<<std::endl;
        break;
    }
  }
}

//menu wlasciciela ksiegarni - ksiegarnia
void bookshop_menu2(Bookshop *first)
{
  Bookshop *current;
  float sum = 0;
  int choice, number;
  int ii = 1;

  current = first;

  while(ii == 1){
    std::cout<<std::endl<<"Ksiegarnia "<<current->get_name()<<" w miescie "<<current->get_city()<<std::endl;
    std::cout<<"1. Wyswietl liste pracownikow"<<std::endl;
    std::cout<<"2. Zatrudnij nowego pracownika"<<std::endl;
    std::cout<<"3. Zwolnij pracownika"<<std::endl;
    std::cout<<"4. Wyplac pensje pracownikom"<<std::endl;
    std::cout<<"5. Zarzadzaj zamowieniami"<<std::endl; //akceptowanie/odrzucanie
    std::cout<<"6. Nastepna ksiegarnia"<<std::endl;
    std::cout<<"7. Wyjscie"<<std::endl;
    std::cin>>choice;

    switch(choice)
    {
      case 1:
        current->show_employee_list();
        break;

      case 2:
        current->add_to_list_employee();
        break;

      case 3:
        if(current->get_firstE() == NULL)
          std::cout<<std::endl<<"W tej ksiegarni nie ma jeszcze zadnych pracownikow. Aby zwolnic pracownika najpierw jakiegos zatrudnij"<<std::endl;
        else
        {
          std::cout<<std::endl<<"Wybierz numer pracownika, ktorego chcesz usunac."<<std::endl;
          current->show_employee_list();
          std::cin>>number;
          current->delete_employee(number);
        }
        break;

      case 4:
        if(current->get_firstE() == NULL)
          std::cout<<"W tej ksiegarni nikt jeszcze nie pracuje. Zatrudnij pracownika, aby wyplacic mu pensje."<<std::endl;
        else
        {
          Employee *currentE;
          currentE = current->get_firstE();

          while(currentE != NULL)
          {
            sum += currentE->get_salary();
            currentE = currentE->get_next();
          }

          if(current->get_budget()<sum) {std::cout << "Za maly budzet " << std::endl; break;}

          else (*current) - sum;
        }
        break;

      case 5:
        accept(current);
        break;

      case 6:
        if(current->get_next() == NULL)
          current = first;
        else
          current = current->get_next();
        break;

      case 7:
        ii = 0;
        break;

      default:
        std::cout<<"Nie rozumiem"<<std::endl;
        break;
    }
  }
}

//menu pracownika - ogolne
void employee_menu1(Bookshop *first)
{
  int choice, number;
  int ii = 1;
  Bookshop *current;
  current = first;

  while(ii == 1)
  {
    std::cout<<std::endl<<"PRACOWNIK - ksiegarnia "<<current->get_name()<<" w miescie "<<current->get_city()<<std::endl;
    std::cout<<"1. Wyswietl liste pracownikow"<<std::endl;
    std::cout<<"2. Wybierz pracownika"<<std::endl;
    std::cout<<"3. Przejdz do nastepnej ksiegarni"<<std::endl;
    std::cout<<"4. Wyjscie"<<std::endl;
    std::cin>>choice;

    switch(choice)
    {
      case 1:
      current->show_employee_list();
      break;

      case 2:
        if(current->get_firstE() == NULL)
          std::cout<<std::endl<<"W podanej ksiegarni nie ma jeszcze pracownika, w ktorego mozna sie wcielic"<<std::endl;

        else
        {
          Employee *currentE;
          currentE = current->get_firstE();
          current->show_employee_list();

          std::cout<<"Wybierz numer pracownika, w ktorego chcesz sie wcielic"<<std::endl;
          std::cin>>number;
          for(int i = 1 ; i < number ; i++)
            currentE = currentE->get_next();
          employee_menu2(currentE, current);
        }

      case 3:
        if(current->get_next() == NULL)
          current = first;
        else
          current = current->get_next();
        break;

      case 4:
        ii = 0;
        break;
    }
  }
}

//menu pracownika - konkretny pracownik
void employee_menu2(Employee *currentE, Bookshop *currentB)
{
  int ii = 1;
  int choice;
  while(ii == 1){
    std::cout<<std::endl<<"Pracownik "<<currentE->get_name()<<" "<<currentE->get_surname()<<std::endl;
    std::cout<<"\"Hmm... co by tu zrobic?\""<<std::endl;
    std::cout<<"1. Pokaz liste wszystkich ksiazek"<<std::endl;
    std::cout<<"2. Dopisz ksiazke do zamowienia"<<std::endl;
    std::cout<<"3. Zloz zamowienie"<<std::endl;
    std::cout<<"4. Wyswietl aktualne zamowienie"<<std::endl;
    std::cout<<"5. Stan za kasa i czekaj na klientow"<<std::endl;

    std::cin>>choice;
    switch(choice)
    {
      case 1:
        currentB->show_book_list(0);
        break;

      case 2:
        add_order2(currentB);
        break;

      case 3:
        order(currentB);
        break;

      case 4:
        show_order(currentB);
        break;

      case 5:
        ii = 0;
        break;

      default:
        std::cout<<"Nieee, cos innego..."<<std::endl<<std::endl;
    }
  }
}

//menu klienta - ogolne
void customer_menu1(Bookshop *first)
{
  int choice, number;
  int ii = 1;
  Bookshop *current;
  current = first;

  while(ii == 1)
  {
    std::cout<<std::endl<<"KLIENT - ksiegarnia "<<current->get_name()<<" w miescie "<<current->get_city()<<std::endl;
    std::cout<<"1. Wyswietl liste klientow"<<std::endl;
    std::cout<<"2. Stworz nowego klienta"<<std::endl;
    std::cout<<"3. Usun klienta"<<std::endl;
    std::cout<<"4. Wybierz klienta"<<std::endl;
    std::cout<<"5. Przejdz do nastepnej ksiegarni"<<std::endl;
    std::cout<<"6. Wyjscie"<<std::endl;
    std::cin>>choice;

    switch (choice)
    {
      case 1:
        current->show_customer_list();
        break;

      case 2:
        current->add_to_list_customer();
        break;

      case 3:
        if(current->get_firstC() == NULL)
          std::cout<<std::endl<<"W tej ksiegarni nie ma jeszcze zadnych klientow."<<std::endl;
        else
        {
          current->show_customer_list();
          std::cout<<std::endl<<"Wybierz numer klienta, ktorego chcesz usunac."<<std::endl;
          std::cin>>number;
          current->delete_customer(number);
        }
        break;

      case 4:
        if(current->get_firstC() == NULL)
          std::cout<<std::endl<<"W podanej ksiegarni nie ma jeszcze klienta, w ktorego mozna sie wcielic"<<std::endl;

        else if(current->get_firstE() == NULL)
          std::cout<<"Klient podchodzi do drzwi ksiegarni. \"ZAMKNIETE DO ODWOLANIA\" - glosi napis na drzwiach"<<std::endl;

        else
        {
          Customer *currentC;
          currentC = current->get_firstC();
          current->show_customer_list();
          std::cout<<"Wybierz numer klienta, w ktorego chcesz sie wcielic"<<std::endl;
          std::cin>>number;

          for(int i = 1 ; i < number ; i++)
            currentC = currentC->get_next();
          customer_menu2(currentC, current);
        }
        break;

      case 5:
        if(current->get_next() == NULL)
          current = first;
        else
          current = current->get_next();
        break;

      case 6:
        ii = 0;
        break;

      default:
        std::cout<<"Nie ma takiego wyboru."<<std::endl;
        break;
    }
  }
}

//menu klienta - konkretny klient
void customer_menu2(Customer *currentC, Bookshop *currentB)
{
  Book *currentBo;
  int choice, number;
  int ii = 1;

  while(ii == 1){
    std::cout<<std::endl<<"Klient "<<currentC->get_name()<<" "<<currentC->get_surname()
             <<" wchodzi do ksiegarni "<<currentB->get_name()<<" w miescie "<<currentB->get_city()
             <<". Podchodzi do lady"<<std::endl<<"-W czym moge pomoc? - pyta sprzedawca"<<std::endl
             <<"-Chwilowo sie tylko rozgladam - odpowiada klient"<<std::endl
             <<"1. Obejrzyj ksiazki"<<std::endl  //wyswietla liste ksiazek
             <<"2. Kup ksiazke"<<std::endl
             <<"3. Zamow ksiazke"<<std::endl
             <<"4. Idz do pracy (zarabiac na nowe ksiazki)"<<std::endl
             <<"5. Przejrzyj swoja kolekcje"<<std::endl
             <<"6. Sprawdz zawartosc portfela"<<std::endl
             <<"7. Wyjdz z ksiegarni"<<std::endl;
    std::cin>>choice;

    switch(choice)
    {
      case 1:
        currentB->show_book_list(1);
        break;

      case 2:
      {
        int nB = 0;
        currentBo = currentB->get_firstB();

        if(currentBo != NULL)
        {
          do
          {
            nB += currentBo->get_number();
            currentBo = currentBo->get_next();
          }while(currentBo != currentB->get_firstB());
        }

        if(currentB->get_firstB() != NULL && nB != 0)
        {
          std::cout<<"-Ktora ksiazke mam podac?"<<std::endl;
          currentB->show_book_list(1);
          std::cout<<"-Poprosze ta z numerem ";
          std::cin>>number;
          currentBo = currentB->get_firstB();
          int i = 0;
          while(true)  //ustawianie wskaznika na wybrana przez klienta ksiazke
          {
            if(currentBo->get_number() > 0)
              i++;
            if(i == number)
              break;
            currentBo = currentBo->get_next();
          }

          if(currentC->get_money() >= currentBo->get_price())
          {
            currentC->set_money(currentC->get_money() - currentBo->get_price());
            currentBo->set_number(currentBo->get_number() - 1);
            currentC->add_to_collection(currentBo->get_title(), currentBo->get_author(), currentBo->get_publisher(), 1);
            (*currentB)+(currentBo->get_price());
          }

          else
          {
            std::cout<<"\"Sprzedawca zdejmuje ksiazke z polki i zapakowuje ja do reklamowki.\"";
            std::cout<<"-Nalezy sie "<<currentBo->get_price()<<"zl"<<std::endl;
            std::cout<<"\"Klient przeszukuje portfel w poszukiwaniu pieniedzy, lecz znajduje tylko "<<currentC->get_money()<<"zl"<<endl;
            std::cout<<"-Ups, chyba nie stac mnie na ta ksiazke... - mowi - No nic. W takim razie chwilowo dziekuje."<<endl;
          }
        }
        else
          std::cout<<"Nie moge nic kupic."<<std::endl;
      }
      break;

      case 3:
        add_order(currentB);
        break;

      case 4:
        *currentC += 100.0;
        break;

      case 5:
        currentC->show_collection();
        break;

      case 6:
        std::cout<<"W portfelu znajduje sie "<<currentC->get_money()<<"zl"<<std::endl;
        break;

      case 7:
        std::cout<<"-Do widzenia."<<std::endl<<"-Do widzenia."<<std::endl;
        ii = 0;
        break;

      default:
        std::cout<<"Hmm... chyba nie moge tego zrobic."<<std::endl;
        break;
    }
  }
}

//wyswietla liste ksiegarni, zwraca ich liczbe
int show_bookshop_list(Bookshop *first)
{
  int i = 0;
  if(first == NULL)
    std::cout<<std::endl<<"Nie mam jeszcze zadnej ksiegarni... musze jak najszybciej jakas zalozyc!"<<endl;
  else
  {
    do
    {
      std::cout<<++i<<". ";
      std::cout << first;
      first = first->get_next();
    }while(first != NULL);
  }
  return i;
}

//dodaje ksiegarnie na koniec aktualnej listy ksiegarni
void add_to_list_bookshop(Bookshop **first, Bookshop **last)
{

  std::string n;
  std::cout<<"Podaj nazwe nowej ksiegarni: ";
  std::cin>>n;
  std::string c; //city
  float b; //budget

  std::cout<<"Podaj nazwe miasta, w ktorym chcesz zalozyc ksiegarnie: ";
  std::cin>>c;
  do
  {
      std::cout<<"Podaj poczatkowy budzet ksiegarni: ";
      std::cin>>b;
  }while(b<0);
  new Bookshop(n, c, b, first, last);

}

//usuwa ksiegarnie, kontroluje liste
void delete_bookshop(Bookshop **first, Bookshop **last, int n)
{
  Bookshop *current, *previous=NULL;
  current = *first;

  for(int i = 1 ; i < n ; i++)
    {
      previous = current;
      current = current->get_next();
    }


  if(previous!=NULL) previous->set_next(current->get_next());

  if(previous==NULL) *first=current->get_next();

  if(current->get_next()==NULL) *last=previous;

  delete(current);
}

//klient sklada zamowienie na konkretna ksiazke
void add_order(Bookshop *current)
{
  Book *currentB;
  std::string t, a, p;
  float pr;
  int nO; //nO- ilosc zamawianych egzemplarzy

  std::cout<<"-Chcialbym zamowic ksiazke."<<std::endl;
  std::cout<<"-Jaki jest tytul ksiazki?"<<std::endl<<"-";
  std::cin>>t;
  std::cout<<"-"<<t<<"... Zapisane. Kto jest autorem?"<<std::endl<<"-";
  std::cin>>a;
  std::cout<<"-Ok. Jakie wydawnictwo?"<<std::endl<<"-";
  std::cin>>p;
  std::cout<<"-Ile egzemplarzy chce pan/pani zamowic?"<<std::endl;
  std::cin>>nO;
  std::cout<<"Prosze jeszcze chwilke poczekac. Sprawdze, czy ksiazki juz u nas nie ma."<<std::endl<<"..."<<std::endl<<"..."<<std::endl<<"..."<<std::endl;

  currentB = current->find_book(t, a, p);
  std::cout<<"Szukanie"<<std::endl;
  if(currentB == NULL || currentB->get_number() < nO)
  {
    std::cout<<"\"<KLIK KLIK KLIK> (sprawdzanie w systemie)\""<<std::endl;
    std::cout<<"-Przykro mi, ale jednak nie mamy wystarczajacej liczby ksiazek. Juz skladam zamowienie. Prosze przyjsc za kilka dni. Niedlugo powinna byc dostawa."<<endl;
    if(currentB == NULL)
    {
      cout<<"Ustal cene ksiazki: ";
      cin>>pr;
      current->add_to_list_book(t, a, p, pr, nO);
    }
    else
      currentB->set_nOrd(currentB->get_nOrd() + nO - currentB->get_number());
  }
  else
  {
    std::cout<<"\"<KLIK KLIK KLIK> (sprawdzanie w systemie)\""<<std::endl;
    std::cout<<"-Ooo, jednak mamy potrzebna ksiazke! Zaraz pomoge ja znalezc..."<<std::endl;
    std::cout<<"-Nie, dziekuje, nie trzeba. Zaraz jeszcze raz przejrze polke. Na pewno sobie poradze."<<std::endl;
  }
}

//zamawianie ksiazki przez pracownika
void add_order2(Bookshop *current)
{
  Book *currentB;
  std::string t, a, p;
  int nO; //nO- ilosc zamawianych egzemplarzy
  float pr;

  std::cout<<"Tytul: ";
  std::cin>>t;
  std::cout<<"Autor: ";
  std::cin>>a;
  std::cout<<"Wydawnictwo: ";
  std::cin>>p;
  std::cout<<"Ilosc potrzebnych egzemplarzy (conajmniej 1): ";
  std::cin>>nO;
  std::cout<<"Cena: ";
  std::cin>>pr;

  if(nO < 1)
    nO = 1;

  currentB = current->find_book(t, a, p);

  if(currentB == NULL)
    current->add_to_list_book(t, a, p, pr, nO);
  else if(currentB != NULL)
    std::cout<<"Chwila.. ta ksiazka juz u nas jest! Nie musze jej dopisywac."<<std::endl;
}

//wyswietla zamowienie
void show_order(Bookshop *current)
{
  Book *currentO;

  if(current->get_ordActive() == 0)
    std::cout<<"Zadne zamowienie nie jest aktualnie zlozone."<<std::endl;

  else
  {
    currentO = current->get_order();
    std::cout<<"AKTUALNE ZAMOWIENIE:"<<std::endl;

    do
    {
      std::cout<<currentO->get_title()<<" "<<currentO->get_author()<<" "<<currentO->get_publisher()<<" "<<currentO->get_number()<<std::endl;
      currentO = currentO->get_next();
    }while(currentO != current->get_order());
  }
}

//skladanie zamowienia
void order(Bookshop *current)
{
  Book *currentB = NULL, *currentO = NULL;
  int n = 0;
  if(current->get_firstB() != NULL)
  {
    currentB = current->get_firstB();

    std::cout<<"ZAMOWIENIE:"<<std::endl;
    do
    {
      std::cout<<std::endl<<"\""<<currentB->get_title()<<"\"  "<<currentB->get_author()<<"  "<<currentB->get_publisher()<<std::endl;
      std::cout<<"Ilosc dostepnych egzemplarzy: "<<currentB->get_number()<<std::endl<<"Ilosc egzemplarzy do zamowienia: "<<currentB->get_nOrd()<<std::endl;
      std::cin>>n;
      while(n < currentB->get_nOrd())
      {
        std::cout<<"UWAGA: Ilosc zamawianych egzemplarzy nie moze byc mniejsza niz ilosc potrzebnych egzemplarzy."<<std::endl<<"Zamow: ";
        std::cin>>n;
      }
      if(n > 0)
      {
        if(current->get_order() == NULL)
        {
          current->set_order(new Book(currentB->get_title(), 0, currentB->get_author(), currentB->get_publisher(), 0, 0, n, 0));
          currentO = current->get_order();
          currentO->set_next(currentO);
          currentO->set_previous(currentO);
        }
        else
        {
          currentO->set_next(new Book(currentB->get_title(), 0, currentB->get_author(), currentB->get_publisher(), 0, 0, n, 0));
          currentO->get_next()->set_previous(currentO);
          currentO = currentO->get_next();
          current->get_order()->set_previous(currentO);
          currentO->set_next(current->get_order());
        }
      }

      currentB = currentB->get_next();
    }while(currentB != current->get_firstB());

    if(current->get_order() != NULL)
    {
      currentO = current->get_order();
      std::cout<<"Zlozono zamowienie: "<<std::endl;
      do
      {
        std::cout <<currentO;
        currentO = currentO->get_next();
      }while(currentO != current->get_order());

      current->set_ordActive(1);
    }
  }
}

void accept(Bookshop *current)
{
  Book *currentB, *previousB;
  char choice;

  if(current->get_ordActive() == 0 || current->get_order() == NULL)
    std::cout<<"Aktualnie nie ma zadnych zamowien"<<std::endl;

  else
  {
    std::cout<<std::endl<<"ZAMOWIENIE:"<<std::endl;
    currentB = current->get_order();
    do  //drukowanie listy zamowien
    {
      std::cout <<current;
      currentB = currentB->get_next();
    }while(currentB != current->get_order());  //currentB znowu wskazuje na pierwsza ksiazke z listy zamowien

    std::cout<<std::endl<<"Czy akceptujesz zamowienie?"<<std::endl<<"1. Tak"<<std::endl<<"2. Nie"<<std::endl;
    std::cin>>choice;
    if(choice == '1')
    {
      do
      {
        if(current->get_budget() > (currentB->get_price())*(currentB->get_number()))
        {
          previousB = current->find_book(currentB->get_title(), currentB->get_author(), currentB->get_publisher());
          if(previousB != NULL)
          {
            previousB->set_number(previousB->get_number() + currentB->get_number());
            current->set_budget(current->get_budget() - (currentB->get_price())*(currentB->get_number()));
          }
        }
        currentB = currentB->get_next();
        currentB->set_nOrd(0);
      }while(currentB != current->get_order());
    }

    while(current->get_order() != NULL)
    {
      currentB = current->get_order();
      current->set_order(current->get_order()->get_next());
      if(currentB == currentB->get_next())
        current->set_order(NULL);
      delete(currentB);
    }
  }
  current->set_ordActive(0);
}


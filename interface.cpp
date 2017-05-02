#include "interface.hpp"
extern void tests();
extern void testsb();
extern void testsc();
extern void testse();

//menu glowne
void main_menu(Owner &ow)
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
        bs_menu1(ow);
        break;
      case '2': //pracownik
        if(ow.get_firstBs() == NULL)
          std::cout<<std::endl<<"Nie powstala jeszcze zadna ksiegarnia. Nie moze byc zadnego pracownika."<<std::endl<<std::endl;
        else
          em_menu1(ow);
        break;
      case '3': //klient
        if(ow.get_firstBs() == NULL)
          std::cout<<std::endl<<"Nie powstala jeszcze zadna ksiegarnia. Nie moze byc zadnego klienta."<<std::endl<<std::endl;
        else
          cu_menu1(ow);
        break;
      case '4': //testy
        std::cout<<"TESTY"<<std::endl<<"1. Test klasy bookshop"<<std::endl<<"2. Test klasy book"<<std::endl<<"3. Test klasy customer"<<std::endl<<"4. Test klasy employee"<<std::endl;
        std::cin>>choice2;
//        if(choice2 == '1')
//          tests();
//        else if(choice2 == '2')
//          testsb();
//        else if(choice2 == '3')
//          testsc();
//        else if(choice2 == '4')
//            testse();
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
void bs_menu1(Owner &ow)
{
  int number;
  char ii = '0', choice;
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
        ow.show_bs();
        break;
      case '2':
        ow.new_bs();
        break;
      case '3':
        if(ow.get_firstBs() == NULL)
          std::cout<<std::endl<<"Nie ma jeszcze zadnych ksiegarni. Nie mozna zadnej usunac."<<std::endl;
        else
        {
          ow.show_bs();
          std::cout<<std::endl<<"Wybierz numer ksiegarni, ktora chcesz usunac"<<std::endl;
          std::cin>>number;
          ow.delete_bs(number);
        }
        break;
      case '4':
        if(ow.get_firstBs() == NULL)
          std::cout<<std::endl<<"Nie istnieje jeszcze zadna ksiegarnia. Nie mozna zarzadzac ksiegarniami."<<std::endl;
        else
          bs_menu2(ow);
        break;
      case '5':
        ii = '1';
        break;
      default:
        std::cout<<"Nie ma takiej mozliwosci"<<std::endl;
        break;
    }
  }
}

//menu wlasciciela ksiegarni - ksiegarnia
void bs_menu2(Owner &ow)
{
  List<Bookshop> *currBs = ow.get_firstBs();;
  Bookshop *bs;
  List<Employee> *em;
  double sum = 0;
  char choice = '0';
  int number;

  while(choice != '7'){
    bs = currBs->get_obj();
    std::cout<<std::endl<<"Ksiegarnia "<<bs->get_name()<<" w miescie "<<bs->get_city()<<std::endl;
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
      case '1':
        bs->show_employees();
        break;
      case '2':
        bs->new_employee();
        break;
      case '3':
        if(bs->get_firstE() == NULL)
          std::cout<<std::endl<<"W tej ksiegarni nie ma jeszcze zadnych pracownikow. Nie mozna nikogo zwolnic"<<std::endl;
        else
        {
          bs->show_employees();
          std::cout<<std::endl<<"Wybierz numer pracownika, ktorego chcesz usunac."<<std::endl;
          std::cin>>number;
          bs->delete_employee(number);
        }
        break;
      case '4':
        if((em = bs->get_firstE()) == NULL)
          std::cout<<"W tej ksiegarni nikt jeszcze nie pracuje. Zatrudnij pracownika, aby wyplacic mu pensje."<<std::endl;
        else
        {
          do
          {
            sum += em->get_obj()->get_salary();
            em = em->get_next();
          }while(em != bs->get_firstE());
          if(bs->get_budget()<sum) {std::cout << "Za maly budzet " << std::endl; break;}
          else (*bs) - sum;
        }
        break;
      case '5':
        ow.accept(bs);
        break;
      case '6':
        currBs = currBs->get_next();
        break;
      case '7':
        break;
      default:
        std::cout<<"Nie ma takiej mozliwosci"<<std::endl;
        break;
    }
  }
}

//menu pracownika - ogolne
void em_menu1(Owner &ow)
{
  char choice = '0';
  int number;
  List<Bookshop> *currBs = ow.get_firstBs();
  Bookshop *bs;
  List<Employee> *currEm;

  while(choice != '3')
  {
    bs = currBs->get_obj();
    std::cout<<std::endl<<"PRACOWNIK - ksiegarnia "<<bs->get_name()<<" w miescie "<<bs->get_city()<<std::endl;
    std::cout<<"1. Wybierz pracownika"<<std::endl;
    std::cout<<"2. Przejdz do nastepnej ksiegarni"<<std::endl;
    std::cout<<"3. Wyjscie"<<std::endl;
    std::cin>>choice;

    switch(choice)
    {
      case '1':
        if(bs->get_firstE() == NULL)
          std::cout<<std::endl<<"W danej ksiegarni nie ma jeszcze zadnego pracownika. Nie mozna sie w zadnego wcielic."<<std::endl;
        else
        {
          bs->show_employees();
          std::cout<<"Wybierz numer pracownika, w ktorego chcesz sie wcielic"<<std::endl;
          std::cin>>number;
          for(int i = 1 ; i < number ; i++)
            currEm = currEm->get_next();
          em_menu2(currEm->get_obj(), bs);
        }
      case '2':
        currBs = currBs->get_next();
        break;
      case '3':
        break;
      default:
        std::cout<<"Nie ma takiej mozliwosci."<<std::endl;
        break;
    }
  }
}

//menu pracownika - konkretny pracownik
void em_menu2(Employee *em, Bookshop *bs)
{
  int ii = 1;
  char choice = '0';
  if(em != NULL  && bs != NULL)
  {
    while(ii == 1){
      std::cout<<std::endl<<"Pracownik "<<em->get_name()<<" "<<em->get_surname()<<std::endl;
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
          bs->show_books();
          break;
        case 2:
          bs->order_b();
          break;
        case 3:
          bs->order_e();
          break;
        case 4:
          bs->show_order();
          break;
        case 5:
          break;
        default:
          std::cout<<"Nie ma takiej mozliwosci."<<std::endl<<std::endl;
      }
    }
  }
  else std::cout<<"Blad: w tej ksiegarni nie ma jeszcze zadnych pracownikow"<<std::endl;
}

//menu klienta - ogolne
void cu_menu1(Owner &ow)
{
  char choice = '0';
  int number;
  List<Bookshop> *currBs = ow.get_firstBs();
  List<Customer> *currCu = currBs->get_obj()->get_firstC();
  Bookshop *bs = currBs->get_obj();
  if(currCu != NULL)
  {
    while(choice != '6')
    {
      std::cout<<std::endl<<"KLIENT - ksiegarnia "<<bs->get_name()<<" w miescie "<<bs->get_city()<<std::endl;
      std::cout<<"1. Wyswietl liste klientow"<<std::endl;
      std::cout<<"2. Stworz nowego klienta"<<std::endl;
      std::cout<<"3. Usun klienta"<<std::endl;
      std::cout<<"4. Wybierz klienta"<<std::endl;
      std::cout<<"5. Przejdz do nastepnej ksiegarni"<<std::endl;
      std::cout<<"6. Wyjscie"<<std::endl;
      std::cin>>choice;

      switch (choice)
      {
        case '1':
          bs->show_customers();
          break;
        case '2':
          bs->new_customer();
          break;
        case '3':
          if(bs->get_firstC() == NULL)
            std::cout<<std::endl<<"W tej ksiegarni nie ma jeszcze zadnych klientow."<<std::endl;
          else
          {
            bs->show_customers();
            std::cout<<std::endl<<"Wybierz numer klienta, ktorego chcesz usunac."<<std::endl;
            std::cin>>number;
            bs->delete_customer(number);
          }
          break;
        case '4':
          if(bs->get_firstC() == NULL)
            std::cout<<std::endl<<"W danej ksiegarni nie ma jeszcze zadnych klientow. Nie mozna zadnego wybrac."<<std::endl;
          else if(bs->get_firstE() == NULL)
            std::cout<<"Ksiegarnia zamknieta do odwolania. (Brak pracownikow)"<<std::endl;
          else
          {
            bs->show_customers();
            std::cout<<"Wybierz numer klienta, w ktorego chcesz sie wcielic"<<std::endl;
            std::cin>>number;
            for(int i = 1 ; i < number ; i++)
              currCu = currCu->get_next();
            cu_menu2(currCu->get_obj(), bs);
          }
          break;
        case '5':
          currBs = currBs->get_next();
          break;
        case '6':
            break;
        default:
          std::cout<<"Nie ma takiego wyboru."<<std::endl;
          break;
      }
    }
  }
  else
    std::cout<<"Blad: w tej ksiegarni nie ma jeszcze klientow."<<std::endl;
}

//menu klienta - konkretny klient
void cu_menu2(Customer *cu, Bookshop *bs)
{
  List<Book> *currBo;
  char choice = '0';
  int number, i = 0;

  while(choice != '7'){
    std::cout<<"Klient "<<cu->get_name()<<" "<<cu->get_surname()<<std::endl;
    std::cout<<"Ksiegarnia"<<bs->get_name()<<" w miescie "<<bs->get_city()<<std::endl;
    std::cout<<"1. Obejrzyj ksiazki"<<std::endl;
    std::cout<<"2. Kup ksiazke"<<std::endl;
    std::cout<<"3. Zamow ksiazke"<<std::endl;
    std::cout<<"4. Idz do pracy (zarabiac na nowe ksiazki)"<<std::endl;
    std::cout<<"5. Przejrzyj swoja kolekcje"<<std::endl;
    std::cout<<"6. Sprawdz zawartosc portfela"<<std::endl;
    std::cout<<"7. Wyjdz z ksiegarni"<<std::endl;
    std::cin>>choice;

    switch(choice)
    {
      case '1':
        bs->show_books();
        break;
      case '2':
        if(currBo != NULL)
        {
          std::cout<<"Lista ksiazek do kupienia:"<<std::endl;
          bs->show_books();                               //wyswietlanie ksiazek ma nie obejmowac tych z zerowa iloscia egz.
          std::cout<<"-Poprosze ksiazke z numerem...";
          std::cin>>number;

          while(true)  //ustawianie wskaznika na wybrana przez klienta ksiazke
          {
            if(currBo->get_obj()->get_number() > 0)  i++;
            if(i == number)  break;
            currBo = currBo->get_next();
          }
          cu->buy(*(currBo->get_obj()));
        }
        else
          std::cout<<"Nie moge nic kupic."<<std::endl;
        break;

      case 3:
        bs->order_b();
        break;
      case 4:
        *cu += 100.0;
        break;
      case 5:
        cu->show_collection();
        break;
      case 6:
        std::cout<<"W portfelu znajduje sie "<<cu->get_money()<<"zl"<<std::endl;
        break;
      case 7:
        std::cout<<"-Do widzenia."<<std::endl<<"-Do widzenia."<<std::endl;
        break;
      default:
        std::cout<<"Nie ma takiej mozliwosci"<<std::endl;
        break;
    }
  }
}

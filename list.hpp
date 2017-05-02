#ifndef List_hpp
#define List_hpp
#include"book.hpp"

template<typename T>
class List
{
  public:
  T obj;
  List<T> *next, *previous;
  public:
  List(T &o): next(NULL), previous(NULL) {obj = o;}
  T* get_obj() {return &obj;}
  List<T>* get_next() {return next;}
  List<T>* get_previous() {return previous;}

  void set_next(List<T> *n) {next = n;}
  void set_previous(List<T> *p) {previous = p;}
};

//wyswietla liste obiektow, zwraca ich liczbe na liscie
template<typename T>
int show_l(List<T> *first)
{
  List<T> *current;
  int i = 0;

  if(first == NULL) //lista jest pusta
    i = -1;

  else
  {
    current = first;
    do
    {
      std::cout<<++i<<". "<<current->get_obj();
      current = current->get_next();
    }while(current != first);
  }
  return i;
}

//usuwa z listy element o zadanym numerze, zwraca wskaznik na pierwszy element listy
template<typename T>
List<T>* delete_o(int n, List<T> *first)
{
  List<T> *current = first;

  if(first != NULL){
    if(first == first->get_next())  first = NULL;
    else if(n == 1)
    {
      (first->get_previous())->set_next(first->get_next());
      (first->get_next())->set_previous(first->get_previous());
      first = first->get_next();
    }
    else
    {
      for(int i = 1 ; i < n ; i++)
        current = current->get_next();
      (current->get_previous())->set_next(current->get_next());
      (current->get_next())->set_previous(current->get_previous());
    }
    delete(current);
  }
  return first;
}

//tworzy nowy element listy, posrednio: ustawia go na wlasciwym miejscu, zwraca wskaznik na pierwszy element listy
template<typename T>
auto new_o(List<T> *first, T &o) -> List<T>*
{
  List<T> *n;
  n = new List<T>(o);
  return (add_o(first,n));
}

//umieszcza nowy obiekt na wlasciwym miejscu - zwraca wskaznik na pierwszy element listy
template<typename T>
auto add_o(List<T> *first, List<T> *nObj) -> List<T>*
{
  int i = 0; //flaga
  if(first == NULL)
  {
    first = nObj;
    nObj->set_next(nObj);
    nObj->set_previous(nObj);
  }
  else{
    List<T> *current;
    current = first;

    do
    {
      if(current->obj.get_name() > nObj->obj.get_name()){  //ustawianie obiektu na wlasciwym miejscu
        (current->get_previous())->set_next(nObj);
        nObj->set_previous(current->get_previous());
        current->set_previous(nObj);
        nObj->set_next(current);
        i++;
        break;
      }
      current = current->get_next();
    }while(current != first);

    if(nObj->obj.get_name() < first->obj.get_name())  //nowy obiekt staje sie pierwszy - ma najmlodsza nazwe
      first = nObj;

    else if(i == 0)  //nazwa nowego obiektu jest najstarsza - obiekt dodany na "koniec" listy
    {
      (first->get_previous())->set_next(nObj);
      nObj->set_previous(first->get_previous());
      first->set_previous(nObj);
      nObj->set_next(first);
    }
  }

  return first;
}

//wyszukuje obiekt z listy, zwraca na niego wskaznik, lub NULL (jesli takiego nie znajdzie)
template<typename T>
List<T>* find_o(T &o, List<T> *first)
{
  int i = 0;
  List<T> *current = first;
  if(current != NULL)
  {
    do
    {
      if(*(current->get_obj()) == o){ i++; break; }
      current = current->get_next();
    }while(current != first);

    if(i == 0)
      current = NULL;
  }

  return current;
}


#endif

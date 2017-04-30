#include "list.hpp"

//template<typename T>
//List<T>::List(): next(NULL), previous(NULL) {};


//wyswietla liste, zwraca liczbe wyswietlonych elementow
template<typename T>
int show_l(List<T> *first)
{
  int i = 0;
  if(first == NULL) //lista jest pusta
    i = -1;
  else
  {
    do
    {
      std::cout<<++i<<". "<<&((*first).obj); //sprawdzic, czy dziala
      first = first->get_next();
    }while(first != NULL);
  }
  return i;
}


//usuwa z listy element o zadanym numerze, zwraca wskaznik na pierwszy element listy
template<typename T>
List<T>* delete_o(int n, List<T> *first)
{
  T *current;
  current = first;

  if(first == first->get_next())
    first = NULL;

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
  return first;
}


//dodaje wskazanie na pierwszy element listy, tworzy nowy element, dodaje go do listy
template<typename T>
auto new_o(List<T> *first) -> List<T>*//decltype(first)
{
  List<T> *f;
  List<T> *n;
  f = first;
  n = new List<T>();
  return NULL;
 // return f;//(add_o(first,n));
}


template<typename T>
auto add_o(List<T> *first, List<T> *nObj) -> List<T>*//decltype(first)
{
  int i = 0; //flaga
  if(first == NULL)
  {
    first = nObj;
    nObj->set_next(nObj);
    nObj->set_previous(nObj);
  }
  else{
    T *current;
    current = first;

    do
    {
      if(current->get_name() > nObj->get_name()){  //ustawianie ksiazki na wlasciwym miejscu
        (current->get_previous())->set_next(nObj);
        nObj->set_previous(current->get_previous());
        current->set_previous(nObj);
        nObj->set_next(current);
        i++;
        break;
      }
      current = current->get_next();
    }while(current != first);

    if(nObj->get_name() < first->get_name())  //nowa ksiazka staje sie pierwsza - ma najmlodszy tytul
      first = nObj;

    else if(i == 0)  //tytul nowej ksiazki jest najstarszy - ksiazka dodana na "koniec" listy
    {
      (first->get_previous())->set_next(nObj);
      nObj->set_previous(first->get_previous());
      first->set_previous(nObj);
      nObj->set_next(first);
    }
  }
  return first;
}


//wyszukuje z listy obiekt o zadanej nazwie, zwraca na niego wskaznik
template<typename T>
List<T>* find_o(std::string n, List<T> *first)
{
  int i = 0;
  List<T> *current = NULL;

  current = first;
  do
  {
    if(n == current->get_name())
    {
      i++;
      break;
    }
    current = current->get_next();
  }while(current != first);

  if(i == 0)
    current = NULL;

  return current;
}

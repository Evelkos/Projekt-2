#include<iostream>
#include<cstring>
//wczytuje ciag wyrazow, dlugosc ciagu ograniczona
char* load(char *words, int length){
	char *result;
	char *wEnd;  //koniec ciagu wyrazow

	result = fgets(words, length, stdin);
	if(words != NULL){
		wEnd = strchr(words, '\n');
		if(wEnd != NULL)
			*wEnd = '\0';
		else{
			while(getchar() != '\n');
		}
	}
	return result;
}

//wczytuje liczbe
double load_n(){
  char number[10];
  unsigned int i, j = 0;
  double result = 0;

  load(number, 10);
  for(i = 0 ; i < strlen(number) ; i++)
  {
    if((number[i] - '0') >= 0 && (number[i] - '0') <=9)  //wczytywanie cyfr, pomijanie innych znakow (poza '.')
      result = result*10+(number[i] - '0');
    else if(number[i] == '.')                          //wystapil znak '.' => liczba bedzie miala czesc dziesietna
    {
      for(i++; i < strlen(number) ; i++)
      {
        if(number[i] - '0' >= 0 && number[i] - '0' <=9 && j == 0)  //wystapienie pierwszej cyfry po kropce
        {
          result += 0.1*(number[i] - '0');
          j++;
        }
        else if(number[i] - '0' >= 0 && number[i] - '0' <=9 && j == 1)  //wystapienie drugiej cyfry po kropce
          {
            result += 0.01*(number[i] - '0');
            break;
          }
      }
      break;
    }
  }
  return result;
}

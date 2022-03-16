#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

/*
2. Прочитать с клавиатуры имя. Написать функцию,
которая проверяет и исправляет имя так, чтобы оно
было с большой буквы, а остальные - маленькие.
*/

void Correct(string *arr, int Full) {
  for(int i = 0; i < Full; i++) {
    for(int j = 0; j < arr[i].length(); j++) {
      if(j == 0) {
        arr[i][j] = char(toupper(arr[i][j]));
      } else {
        arr[i][j] = char(tolower(arr[i][j]));
      }
    }
  }
}

void Create(string *arr, int Full) {
  cout << "Enter your Full name: ";
  for(int i = 0; i < Full; i++) {
    cin >> arr[i];
  }
}

void Print(string *arr, int Full) {
  for(int i = 0; i < Full; i++) {
    cout << arr[i] << " ";
  }
}

int main(){
  int Full = 3;
  string *arr = new string[Full];

  Create(arr, Full);

  Correct(arr, Full);

  Print(arr, Full);
}

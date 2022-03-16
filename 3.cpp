#include <iostream>
using namespace std;

/*
3. Передать в функцию переменную по указателю и по ссылке,
возвести в квадрат. Вернуть true, если переменная стала больше.
*/

bool cube(int &a) {
  int b = a;
  a = a*a;
  return(a > b);
}

int main() {
  int a;

  cout << "Enter number: ";
  cin >> a;

  cout << cube(a);
}

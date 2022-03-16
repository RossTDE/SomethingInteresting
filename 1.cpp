#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
1. Создать функцию, которая ищет в массиве
целых чисел заданное число и возвращает его индекс.
По умолчанию должна искать ноль.
*/

template<typename T>
class List {
public:
    List();
    List(const List<T> &lst);
    ~List();

    void pop_front();
    void push_back(T data);
    void clear();
    int GetSize() const { return Size; }
    T& operator[](const int index) const;

private:
    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;

        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    unsigned int Size;
    Node<T>* head;
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::List(const List<T>& lst) {
    for (int i = 0; i < lst.GetSize(); i++) {
        push_back(lst[i]);
    }
}
template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head;

    head = head->pNext;

    delete temp;

    Size--;
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr) {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
void List<T>::clear()
{
    while (Size) {
        pop_front();
    }
}


template<typename T>
T& List<T>::operator[](const int index) const
{
    int counter = 0;

    Node<T>* current = this->head;

    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }

    throw std::out_of_range("Elemrnt with index " + to_string(index) + "not found");
}

List<int> search(int* arr, int size, int a) {
    List<int> lst;
    for (int i = 0; i < size; i++) {
        if (arr[i] == a) {
            lst.push_back(i);
        }
    }
    return lst;
}

int main() {
    srand(time(0));
    int size = rand() % 50;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    } cout << endl << endl;

     List<int> lst = search(arr, size, 5);

    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << " ";
    }

}

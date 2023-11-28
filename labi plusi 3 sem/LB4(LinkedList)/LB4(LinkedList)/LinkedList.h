#ifndef LinkedList_h
#define LinkedList_h
#include <string>
#include "Exception.h"
#include "CheckOnInt.h"
#include "CheckString.h"
#include "CaseCheck.h"
#include "isEmpty.h"
#include "notThisIndex.h"

using namespace std;

template <class T>
class MyNode {

private:
    T data;
 
public:
    MyNode* next;
    MyNode* prev;
    MyNode();
    MyNode(T data);
    T getData();
    ~MyNode();
};

template <class T>
MyNode<T>:: MyNode() {
    data = 0;
    next = nullptr;
    prev = nullptr;
}

template <class T>
MyNode<T>::MyNode(T data) {
  this->data = data;
}


template <class T>
T MyNode<T>::getData() {
  return this->data;
}

template <class T>
MyNode<T>::~MyNode() { }

/* Linked List: */

template <class T>
class MyList {
  private:
    T* head;
    T* tail;
    int Size;
    
  public:
    MyList();
    T* getHead();
    T* getTail();
    int size(){return Size;}
   // void addEnd(T* new_node);
    void addBegin(T* new_node);
    void push(T* new_node);
    void pop();
    void CheckIndex(int n);
    void printList();
    void CheckOnType();
    ~MyList();

    friend ostream& operator << (std::ostream &os, MyList &p);
    friend istream& operator >> (std::istream& in, MyList& p);
    
};

template <class T>
MyList<T>::MyList() {
  this->head = nullptr;
  this->tail = nullptr;
  this->Size = 0;
}

template <class T>
T* MyList<T>::getHead() {
      return this->head;
}

template <class T>
T* MyList<T>::getTail() {
  return this->tail;
}

//
//template <typename T>
//void MyList<T>::addEnd(T* new_node) {
//
//    T a;
//  new_node->next = nullptr;
//  new_node->prev = nullptr;
//
//  if (this->Size == 0) {
//    this->head = new_node;
//    this->tail = this->head;
//    this->Size = this->Size + 1;
//  } else {
//    this->tail->next = new_node;
//    new_node->prev = this->tail;
//    this->tail = new_node;
//    this->Size = this->Size + 1;
//  }
//}

template <class T>
void MyList<T>::push(T* new_node) {
    
    
  new_node->next = nullptr;
  new_node->prev = nullptr;

  if (this->Size == 0) {
    this->head = new_node;
    this->tail = this->head;
    this->Size = this->Size + 1;
  } else {
    this->head->prev = new_node;
    new_node->next = this->head;
    this->head = new_node;
    this->Size = this->Size + 1;
  }
}



template <class T>
void MyList<T>::pop() {
    
    try{
        if(Size == 0)
            throw isEmpty(1,"Лист пуст!");
        if(Size == 1 ){
            T* temp = this->head;
            this->head->next = nullptr;
            this->head->prev = nullptr;
            cout << temp->getData() << endl;
            this->Size -= 1;
        }

        else{
            T* temp = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
            cout << temp->getData() << endl;
            this->Size -= 1;
        }
        
    }
    catch(MyException ex){
       ex.show();
    }

}


template <class T>
void MyList<T>::CheckIndex(int index) {
    T* temp = this->head;
    
    try{
        if(index < 0 || index > Size-1)
            throw notThisIndex(2,"Нет такого элемента!");
        
        if (index == 0) {
        cout << temp->getData() << endl;
       
      } else if (index == this->Size ) {
            cout << temp->getData() << endl;
       
      } else if (index < 0 || index >= this->Size) {
            cout << temp->getData() << endl;
        
      }else if (index < this->Size / 2) {
        T* temp = this->head;
        int i = 0;
        while (temp) {
          if (i == index) {
              cout << temp->getData() << endl;
          }
          i++;
          temp = temp->next;
        }
      } else {
        T* temp = this->tail;
        int i = this->Size - 1;
        while (temp) {
          if (i == index) {
                    cout << temp->getData() << endl;
                }
          i--;
          temp = temp->prev;
        }
      }
    }
    
    catch(MyException ex){
        ex.show();
    }

    
}

template <class T>
void MyList<T>::printList() {

    if(Size == 0){
        cout << endl << "It is empty" << endl;
    }
    else{
        T* temp = this->head;
        while(temp) {
          cout << temp->getData() << "\t";
          temp = temp->next;
        }
    }
  
}


template <class T>
MyList<T>::~MyList() {
  while (this->head) {
    T* next = this->head->next;
    delete this->head;
    this->Size -= 1;
    this->head = next;
  }
}





void CreateListOfStrings() {

    MyList<MyNode<string>> list;
    string a;
    int b;

    cout << "Введите количество элементов: ";

    try{
        if(!(cin >> b))
            throw CheckInt(4,"Введен тип не int");

    }
    catch(CheckInt ex){
        ex.show();
        exit(1);
    }



      while(b != 0){

          try{
              cin >> a;
              for (int i = 0; i < a.length(); i++)
                  if (a[i] >= 48 && a[i] <= 57)
                      throw CheckString(5, "Введена чифра!");

              list.push(new MyNode<string>(a));
              b--;

          }
          catch ( CheckString ex)
          {
              ex.show();
          }

      }


    int x = 100;

    while (x!= 0 ) {
        cout <<endl << "Выберите операцию: "<< endl
        << "Вывод списка - 1"<< endl
        << "Размер списка - 2"<< endl
        << "Pop - 3"<< endl
        << "Добавить элемент в начало - 4"<< endl
        << "Просмотр элемента из списка - 5"<< endl
        << "0 - конец" << endl;

        try{
            if(!(cin >> x))
                throw CheckCase(5,"Введено не число!");

        }

        catch(CheckCase ex){
            ex.show();
        }

        switch (x) {
            case 1:
                list.printList();
                break;
            case 2:
                cout << list.size() << endl;
                break;
            case 3:
                list.pop();
                break;

            case 4:{
                string q;
                cin >> q;

                list.push(new MyNode<string>(q));
                break;
            }

            case 5:{
                int q;
                cin >> q;
                list.CheckIndex(q);
                break;
            }

            default:
                break;
        }
    }

}

void CreateListOfInts() {

    MyList<MyNode<int>> list;

    int a,b;


    cout << "Введите количество элементов: ";

    try{

        if(!(cin >> b))
            throw CheckInt(7,"Введен тип не int");

    }

    catch(CheckInt ex){
        ex.show();
    }

      while(b != 0){

          try{
              if(!(cin >> a))
                 throw CheckInt(4,"Введен тип не int");

            list.push(new MyNode<int>(a));
            b--;
          }
          catch ( CheckInt ex)
          {
              ex.show();
              exit(1);
          }
      }


    int x = 100;

    while (x!= 0 ) {
        cout << endl << "Выберите операцию: "<< endl
        << "Вывод списка - 1"<< endl
        << "Размер списка - 2"<< endl
        << "Pop - 3"<< endl
        << "Добавить элемент в начало - 4"<< endl
        << "Просмотр элемента из списка - 5"<< endl

        << "0 - конец"<< endl ;

        try{
            if(!(cin >> x))
                throw CheckCase(3,"Введено не число!");

        }

        catch( CheckCase ex){
            ex.show();

        }

        switch (x) {
            case 1:
                list.printList();
                break;
            case 2:
                cout << list.size() << endl;
                break;
            case 3:{
                list.pop();
                break;
            }

            case 4:{
                int q;

                try{
                    if(!(cin >> q))
                        throw CheckInt(4,"Введено число не типа int!");
                    if(q < 0)
                        throw MyException();
                    list.push(new MyNode<int>(q));
                    break;
                }

                catch( CheckInt ex){
                    ex.show();
                    exit(1);
                }
                break;
            }

            case 5:{
                int q;

                try{
                    if(!(cin >> q))
                        throw CheckInt(4,"Введено число не типа int!");
                    list.CheckIndex(q);
                    break;
                }
                catch( CheckInt ex){
                   ex.show();
                    exit(1);
                }
                break;
            }

            default:
                break;
        }
    }
}


#endif /* LinkedList_h */

#pragma once
#include <iostream>
using namespace std;
struct Element
{
	//Данные
	char data;
	//Адрес следующего элемента списка
	Element* Next;
};
//Односвязный список
class List
{
	//Адрес головного элемента списка
	Element* Head;
	//Адрес концевого элемента списка
	Element* Tail;
	//Количество элементов списка
	int Count;
public:
	//Конструктор
	List();
	//Деструктор
	~List();
	//Добавление элемента в список
	//(Новый элемент становится последним)
	void Add(char data);
	//Удаление элемента списка
	//(Удаляется головной элемент)
	void Add_Plus(char data);
	void Del();
	//Удаление всего списка
	void DelAll();
	//Распечатка содержимого списка
	//(Распечатка начинается с головного элемента) 
	void Print();
	//Получение количества элементов,
	//находящихся в списке
	int GetCount();
	void Print_Head();
};
List::List()
{
	//Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	//Вызов функции удаления
	DelAll();
}
int List::GetCount()
{
	//Возвращаем количество элементов
	return Count;
}
void List::Add(char data)
{
	//создание нового элемента
	Element* temp = new Element;
	//заполнение данными
	temp->data = data;
	//следующий элемент отсутствует
	temp->Next = NULL;
	//новый элемент становится последним элементом списка
	//если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	//новый элемент становится единственным
	//если он первый добавленный
	else {
		Head = Tail = temp;
	}
	Count++;
}
void List::Add_Plus(char data)
{
	Element* temp = new Element;
	temp->data = data;
	temp->Next = NULL;
	if (Head != NULL) {
		Head = temp;
	}
	else                               
	{                                  
		Head = Tail = temp;
	}
	Count++;
}
void List::Print_Head()
{
	cout << "Head = " << Head->data << endl;
}
void List::Del()
{
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//перебрасываем голову на следующий элемент
	Head = Head->Next;
	//удаляем бывший головной элемент
	delete temp;
}
void List::DelAll()
{
	//Пока еще есть элементы 
	while (Head != 0)
		//Удаляем элементы по одному
		Del();
}
void List::Print()
{
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//Пока еще есть элементы
	while (temp != 0)
	{
		//Выводим данные
		cout << temp->data << " ";
		//Переходим на следующий элемент
		temp = temp->Next;
	}
	cout << "\n\n";
}
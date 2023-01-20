#pragma once
#include <iostream>
using namespace std;
struct Element
{
	//������
	char data;
	//����� ���������� �������� ������
	Element* Next;
};
//����������� ������
class List
{
	//����� ��������� �������� ������
	Element* Head;
	//����� ��������� �������� ������
	Element* Tail;
	//���������� ��������� ������
	int Count;
public:
	//�����������
	List();
	//����������
	~List();
	//���������� �������� � ������
	//(����� ������� ���������� ���������)
	void Add(char data);
	//�������� �������� ������
	//(��������� �������� �������)
	void Add_Plus(char data);
	void Del();
	//�������� ����� ������
	void DelAll();
	//���������� ����������� ������
	//(���������� ���������� � ��������� ��������) 
	void Print();
	//��������� ���������� ���������,
	//����������� � ������
	int GetCount();
	void Print_Head();
};
List::List()
{
	//���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	//����� ������� ��������
	DelAll();
}
int List::GetCount()
{
	//���������� ���������� ���������
	return Count;
}
void List::Add(char data)
{
	//�������� ������ ��������
	Element* temp = new Element;
	//���������� �������
	temp->data = data;
	//��������� ������� �����������
	temp->Next = NULL;
	//����� ������� ���������� ��������� ��������� ������
	//���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	//����� ������� ���������� ������������
	//���� �� ������ �����������
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
	//���������� ����� ��������� ��������
	Element* temp = Head;
	//������������� ������ �� ��������� �������
	Head = Head->Next;
	//������� ������ �������� �������
	delete temp;
}
void List::DelAll()
{
	//���� ��� ���� �������� 
	while (Head != 0)
		//������� �������� �� ������
		Del();
}
void List::Print()
{
	//���������� ����� ��������� ��������
	Element* temp = Head;
	//���� ��� ���� ��������
	while (temp != 0)
	{
		//������� ������
		cout << temp->data << " ";
		//��������� �� ��������� �������
		temp = temp->Next;
	}
	cout << "\n\n";
}
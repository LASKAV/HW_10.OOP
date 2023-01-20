#include <iostream>
#include "List.h"

using namespace std;

// В класс односвязного списка (см. код в Тимс) добавить метод,
// добавляющий элемент к началу (голове) списка.

int main()
{
	List MyList_one;

	char str[] = "Much data";
	cout << "\n" << "Data (str) = " << str << endl;
	cout << endl;

	int lenstr = strlen(str);

	for (size_t i = 0; i < lenstr; i++)
	{
		MyList_one.Add(str[i]);
	}
	cout << endl;

	MyList_one.Print();
	cout << "Element = " << MyList_one.GetCount();

	char str_t[] = "III";
	cout << "\n" << "Data (str) = " << str_t << endl;
	cout << endl;

	for (size_t i = 0; i < strlen(str_t); i++)
	{
		MyList_one.Add_Plus(str_t[i]);
	}
	cout << endl;

	MyList_one.Print();
	MyList_one.Print_Head();
	cout << "Element = " << MyList_one.GetCount();
	MyList_one.DelAll();

	return 0;
}

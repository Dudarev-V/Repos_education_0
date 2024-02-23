#include<iostream>
using namespace std;

int main()
{
	setlocale(0, "");

	int n, sum = 0, c_odd = 0, nnz = 0; //nnz - number of non-zero
	bool f = 1;

	cout << "Введите количество вершин:" << endl;
	cout << endl;
	cin >> n;
	cout<< endl;

	int* arr = new int[n];

	cout << "Введите степени соответствующих вершин:" << endl;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> *(arr + i);
		sum += *(arr + i);
		if (*(arr + i) != 0)
		{
			nnz++;
		}
		if (*(arr + i) % 2 != 0)
		{
			c_odd++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (*(arr + i) >= nnz) f = 0; //степень вершины в одной компоненте связности не может превышать
		//или быть равной количеству вершин в этой компоненте
	}

	if (sum % 2 != 0) f = 0; //сумма степеней графа четна
	if (c_odd % 2 != 0) f = 0; //проверка по лемме о рукопожатиях

	cout << endl;

	if (f)
		cout << "Существует";
	else
		cout << "Не существует";

	cout << endl;

	return 0;
}

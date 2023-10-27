#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int SortOtbor(int[], int);//прототип функции Сортировка выбором
int ShakerSort(int[], int);//прототип функции Шейкерной сортировки
using namespace std;

int main()
{

	setlocale(LC_ALL, "rus");

	const int size = 4000; //размер массива
	int array[size] = {};
	int array2[size] = {};//создаем еще один массив, чтобы обе функции сортировок, использовали идентичные масивы(копия массива array)

	int timeOfSortArray = 0;
	int timeOfSortArray2 = 0;

	//заполним массивы случайными числами от 1-го до 800-та
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		array[i] = 1 + rand() % 800;
		array2[i] = array[i];//копируем значения первого массива во второй, чтобы использовать его в функции шейкерной сортировки
	}

	//выводим исходный (неотсортированный) массив на экран
	cout << "Неотсортированный массив: " << endl;
	for (int i = 0; i < size; i++)
		cout << setw(4) << array[i];

	cout << endl << endl;

	timeOfSortArray = SortOtbor(array, size);

	//выводим отсортированный массив (выбором) на экран
	cout << "Отсортированный массив (выбором): " << endl;
	for (int i = 0; i < size; i++)
		cout << setw(4) << array[i];

	cout << endl << endl;

	timeOfSortArray2 = ShakerSort(array2, size);

	//выводим отсортированный массив ("Шекером") на экран
	cout << "Отсортированный массив (\"Шекером\"): " << endl;
	for (int i = 0; i < size; i++)
		cout << setw(4) << array2[i];

	cout << endl << endl;

	cout << "На сортировку массива методом выбора потрачено: " << timeOfSortArray << " временных тактов процессора!\n\n";
	cout << "На сортировку массива методом \"Шейкер\" потрачено: " << timeOfSortArray2 << " временных тактов процессора!\n\n";

	if (timeOfSortArray < timeOfSortArray2)
	{
		cout << "Более эффективным оказался метод сортировки выбором!" << endl << endl;
	}
	else if (timeOfSortArray2 < timeOfSortArray)
	{
		cout << "Более эффективным оказался метод сортировки \"Шейкер\"!" << endl << endl;
	}
	else cout << "Эффективность методов сортировки в данном случае равна!" << endl << endl;

	return 0;
}

int SortOtbor(int Array[], int Size)
{
	int startTime = 0; // начальное время работы функции сортировки
	int endTime = 0; // конечное время работы функции сортировки
	int searchTime = 0; //продолжительность работы функции сортировки

	int min; //минимальный элемент в массиве
	int index;
	int temp; // временная переменная для хранения минимального значения элемента

	startTime = clock(); //начинаем отсчет продолжительности сортировки
	for (int i = Size - 1; i >= 1; i--)
	{
		//задаем начальные значения
		min = Array[i];
		index = i;

		//цикл перебора элементов массива
		for (int j = i - 1; j >= 0; j--)
		{
			//находим минимальный элемент
			if (min > Array[j])
			{
				//запоминаем минимальный элемент и его индекс
				min = Array[j];
				index = j;
			}
		}

		//запоминаем минимум
		temp = Array[index];

		for (int x = index; x < i; x++)//сдвигаем элементы влево
		{
			Array[x] = Array[x + 1];
		}

		Array[i] = temp;
	}
	endTime = clock(); // конечное время работы функции сортировки

	return searchTime = (endTime - startTime); //искомое время работы функции ;
}

int ShakerSort(int Array2[], int Size)
{
	int startTime = 0; // начальное время работы функции сортировки
	int endTime = 0; // конечное время работы функции сортировки
	int searchTime = 0; //продолжительность работы функции сортировки

	int temp; //буфер

	int Left, Right; //границы сортировки

	Left = 1;
	Right = Size - 1;

	startTime = clock(); //начинаем отсчет продолжительности сортировки
	do
	{
		for (int i = Right, j = Left; i >= Left, j <= Right; i--, j++)
		{
			if (Array2[i - 1] > Array2[i])
			{
				temp = Array2[i];
				Array2[i] = Array2[i - 1];
				Array2[i - 1] = temp;
			}

			if (Array2[j - 1] > Array2[j])
			{
				temp = Array2[j];
				Array2[j] = Array2[j - 1];
				Array2[j - 1] = temp;
			}

		}

		Left = Left + 1;
		Right = Right - 1;
	} while (Left <= Right);

	endTime = clock(); // конечное время работы функции сортировки

	return searchTime = (endTime - startTime); //искомое время работы функции ;
}
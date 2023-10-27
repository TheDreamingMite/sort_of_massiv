#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int SortOtbor(int[], int);//�������� ������� ���������� �������
int ShakerSort(int[], int);//�������� ������� ��������� ����������
using namespace std;

int main()
{

	setlocale(LC_ALL, "rus");

	const int size = 4000; //������ �������
	int array[size] = {};
	int array2[size] = {};//������� ��� ���� ������, ����� ��� ������� ����������, ������������ ���������� ������(����� ������� array)

	int timeOfSortArray = 0;
	int timeOfSortArray2 = 0;

	//�������� ������� ���������� ������� �� 1-�� �� 800-��
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		array[i] = 1 + rand() % 800;
		array2[i] = array[i];//�������� �������� ������� ������� �� ������, ����� ������������ ��� � ������� ��������� ����������
	}

	//������� �������� (�����������������) ������ �� �����
	cout << "����������������� ������: " << endl;
	for (int i = 0; i < size; i++)
		cout << setw(4) << array[i];

	cout << endl << endl;

	timeOfSortArray = SortOtbor(array, size);

	//������� ��������������� ������ (�������) �� �����
	cout << "��������������� ������ (�������): " << endl;
	for (int i = 0; i < size; i++)
		cout << setw(4) << array[i];

	cout << endl << endl;

	timeOfSortArray2 = ShakerSort(array2, size);

	//������� ��������������� ������ ("�������") �� �����
	cout << "��������������� ������ (\"�������\"): " << endl;
	for (int i = 0; i < size; i++)
		cout << setw(4) << array2[i];

	cout << endl << endl;

	cout << "�� ���������� ������� ������� ������ ���������: " << timeOfSortArray << " ��������� ������ ����������!\n\n";
	cout << "�� ���������� ������� ������� \"������\" ���������: " << timeOfSortArray2 << " ��������� ������ ����������!\n\n";

	if (timeOfSortArray < timeOfSortArray2)
	{
		cout << "����� ����������� �������� ����� ���������� �������!" << endl << endl;
	}
	else if (timeOfSortArray2 < timeOfSortArray)
	{
		cout << "����� ����������� �������� ����� ���������� \"������\"!" << endl << endl;
	}
	else cout << "������������� ������� ���������� � ������ ������ �����!" << endl << endl;

	return 0;
}

int SortOtbor(int Array[], int Size)
{
	int startTime = 0; // ��������� ����� ������ ������� ����������
	int endTime = 0; // �������� ����� ������ ������� ����������
	int searchTime = 0; //����������������� ������ ������� ����������

	int min; //����������� ������� � �������
	int index;
	int temp; // ��������� ���������� ��� �������� ������������ �������� ��������

	startTime = clock(); //�������� ������ ����������������� ����������
	for (int i = Size - 1; i >= 1; i--)
	{
		//������ ��������� ��������
		min = Array[i];
		index = i;

		//���� �������� ��������� �������
		for (int j = i - 1; j >= 0; j--)
		{
			//������� ����������� �������
			if (min > Array[j])
			{
				//���������� ����������� ������� � ��� ������
				min = Array[j];
				index = j;
			}
		}

		//���������� �������
		temp = Array[index];

		for (int x = index; x < i; x++)//�������� �������� �����
		{
			Array[x] = Array[x + 1];
		}

		Array[i] = temp;
	}
	endTime = clock(); // �������� ����� ������ ������� ����������

	return searchTime = (endTime - startTime); //������� ����� ������ ������� ;
}

int ShakerSort(int Array2[], int Size)
{
	int startTime = 0; // ��������� ����� ������ ������� ����������
	int endTime = 0; // �������� ����� ������ ������� ����������
	int searchTime = 0; //����������������� ������ ������� ����������

	int temp; //�����

	int Left, Right; //������� ����������

	Left = 1;
	Right = Size - 1;

	startTime = clock(); //�������� ������ ����������������� ����������
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

	endTime = clock(); // �������� ����� ������ ������� ����������

	return searchTime = (endTime - startTime); //������� ����� ������ ������� ;
}
/*Написать функцию, которая получает указатель на
динамический массив и его размер.Функция должна удалить из
массива все простые числа и вернуть указатель на новый
динамический массив*/
#include <iostream>
using namespace std;

template <class T>
void showArr(T*& arr, int size)  //   функция показа динамического массива на экран консоли
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ",   ";
	cout << "\n";
}

template <class T>
void NewFinishElement(T*& arr, int& size)  //   функция добавления элемента в конец массива
{
	T* arr1 = new int[size + 1];

	for (int i = 0; i < size; i++)
		arr1[i] = arr[i];

	delete[] arr;
	size++;
	arr = arr1;
}

int* Array_simplenum(int*& arr, int& size, int& size1) // массив без простых чисел
{
	size1 = 0;
	int* arr1 = new int[size1];

	for (int i = 0; i < size; i++)
	{
		bool prime = true;
		for (int j = 2; j <= arr[i] / 2; j++)
			if (arr[i] % j == 0)
			{
				prime = false;
				break;
			}

		if (!prime)
		{
			NewFinishElement(arr1, size1);
			arr1[size1 - 1] = arr[i];
		}

	}

	return arr1;
}

int main()
{
	

	int size = 5;
	int* Arr = new int[size] { 6,8,30 , 4, 11 };  // исходный массив

	cout << "Original array: \n";
	showArr(Arr, size);

	int size1; // количество элементов в новом массиве
	int* Arr1 = Array_simplenum(Arr, size, size1); // выбираем из первого массива все не простые числа и записываем в новый массив

	cout << "Array without primes : \n";
	showArr(Arr1, size1);

	delete[] Arr;
	delete[] Arr1;
}

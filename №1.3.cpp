#include <iostream>
#include <locale.h>
#include <ctime>

using namespace std;

void FillArrRand(int arr[], const int size)
{

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10 + 1;
	}

}

void PrintArray(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

int InsertSort(int* a, int N)
{
	int buf = 0; // для обмена значениями 

	/*********** Начало сортировки **************/

	for (int i = 0; i < N-1; i++)
	{
		int minIndex = -1;
		for (int j=i; j < N; j++) {
			if (a[j] % 2 == 0) { // если значение чётное, то
				if (minIndex < 0) // ещё не было чётных, поэтому 
					minIndex = j;  // запоминаем индекс найденного числа, как минимальное
				else // уже в цикле были чётные 
					if (a[j] < a[minIndex]) // и если это число меньше, чем то, чей индекс запомнили, то
						minIndex = j;         // запомнили индекс этого числа, как нового минимального
			}
		}
		if (minIndex < 0) { continue; }
		else {
			buf = a[i];
			a[i] = a[minIndex];
			a[minIndex] = buf;
		}

	}



	buf = 0;

	int k = 0;
	while ((a[k] % 2 == 0)&&(k<N))
	{
		k++;
	}

	for (int i = k; i < N - 1; i++)
	{
		int maxIndex = -1;
		for (int j = i; j < N; j++) {
			if (a[j] % 2 != 0) { // если значение нечётное, то
				if (maxIndex < 0) // ещё не было нечётных, поэтому 
					maxIndex = j;  // запоминаем индекс найденного числа, как максимальное
				else // уже в цикле были нечётные 
					if (a[j] > a[maxIndex]) // и если это число больше, чем то, чей индекс запомнили, то
						maxIndex = j;         // запомнили индекс этого числа, как нового максимального
			}
		}
		if (maxIndex < 0) { continue; }
		else {
			buf = a[i];
			a[i] = a[maxIndex];
			a[maxIndex] = buf;
		}

	}






	return 0;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int sizeN = 15;
	srand(time(NULL));



	int* arrA = new int[sizeN];


	FillArrRand(arrA, sizeN);



	cout << "********\tМассив a[" << sizeN << "] равен:\t********" << endl;
	PrintArray(arrA, sizeN);


	

	InsertSort(arrA, sizeN);

	cout << "********\tОтсортированный массив a[" << sizeN << "] равен:\t********" << endl;
	PrintArray(arrA, sizeN);


	delete[] arrA;
	



	return 0;
}
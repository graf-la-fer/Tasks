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


int main()
{
	setlocale(LC_ALL, "Rus");
	int sizeN = 15, sizeM = 0, sizeP;
	srand(time(NULL));



	int* arrA = new int[sizeN];


	FillArrRand(arrA, sizeN);



	cout << "********\tМассив a[" << sizeN << "] равен:\t********" << endl;
	PrintArray(arrA, sizeN);


	int s = 0;
	for (int i = 0; i < sizeN; i++)
	{
		if (arrA[i] % 2 == 0) {
			s++;
		}
	}

	cout << "s=" << s << endl;

	int* arrB = new int[s];
	int j = s-1;

	for (int i = 0; i < sizeN; i++)
	{
		if (arrA[i] % 2 == 0) {
			arrB[j] = arrA[i];
			j--;
		}
	}




	cout << "********\tМассив b[" << s << "] равен:\t********" << endl;
	PrintArray(arrB, s);
		


	delete[] arrA;
	delete[] arrB;



	return 0;
}
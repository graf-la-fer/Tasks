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

int qsort(int* a, int left, int right)
{
	int l = left;
	int r = right;
	int foo = 0;
	int mid = a[(l + r) / 2];

	while (l <= r)
	{
		
		while ((a[l] < mid) && (l <= right))
		{
			l++;
			
		}
		
		while ((a[r] > mid) && (r >= left))
		{
			r--;
			
		}

		if (l <= r)
		{
			if (a[l] != a[r])
			{
				foo = a[l];
				a[l] = a[r];
				a[r] = foo;

				
			}
			l++;
			r--;
		}
	}

	if (r > left)
	{
		qsort(a, left, r);
	}
	if (l < right)
	{
		qsort(a, l, right);
	}

	return 0;
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
		if (arrA[i] % 2 != 0) {
			s++;
		}
	}

	//cout <<"s="<< s << endl;

	int* arrB = new int[s];
	int j = 0;

	for (int i = 0; i < sizeN; i++)
	{
		if (arrA[i] % 2 != 0) {
			arrB[j] = arrA[i];
			j++;
		}
	}




	cout << "********\tМассив b[" << s << "] равен:\t********" << endl;
	PrintArray(arrB, s);

	qsort(arrB, 0, s - 1);
	
	cout << "********\tОтсортированный массив b[" << s << "] равен:\t********" << endl;
	PrintArray(arrB, s);


	delete[] arrA;
	delete[] arrB;
	


	return 0;
}
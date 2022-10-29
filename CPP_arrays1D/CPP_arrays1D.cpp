#include "pch.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include "CPP_arrays1D.h"

using namespace std;

void example1()
{
	const int N = 31;	// array length
	srand(time(0));
	// int arr[N]{ -2,1,2,3,4,6,3,4,5,7,9,6,54,34,32,4 };			// static array of integer elements with initialization
	int temperatures[N]{ 0 };			// static array of integer elements with zeroes
	for (int day = 0; day < N; day++)
	{
		temperatures[day] = -2 + rand() % 23;
		cout << "arr[" << day << "] = " << temperatures[day] << endl;
	}

	// finding of average value of array
	float averageTemerature = 0;
	for (int day = 0; day < N; day++)
	{
		averageTemerature += temperatures[day];
	}
	averageTemerature /= N; // averageTemerature = averageTemerature  / N;
	cout << endl << "Average temerature of a month is: " << setprecision(2) << averageTemerature;

	// days with temerature above average
	int aboveAverage = 0, underAverage = 0;
	for (int day = 0; day < N; day++)
	{
		if (temperatures[day] > averageTemerature)
		{
			aboveAverage++;
		}
		else
		{
			if (temperatures[day] < averageTemerature)
			{
				underAverage++;
			}
		}
	}
	cout << endl << "Number of days with temperature above average is: " << aboveAverage;
	cout << endl << "Number of days with temperature under average is: " << underAverage;

	// coldest and hottest day of month, days with zero
	int indexOfColdestDay = 0, indexOfHottestDay = 0, zeroDays = 0;
	for (int day = 0; day < N; day++)
	{
		if (temperatures[day] < temperatures[indexOfColdestDay])
		{
			indexOfColdestDay = day;
		}
		else
		{
			if (temperatures[day] > temperatures[indexOfHottestDay])
			{
				indexOfHottestDay = day;
			}
		}
		if (temperatures[day] == 0)
			zeroDays++;
	}
	cout << endl << "Coldest day of month is: " << indexOfColdestDay << ", temperature was: " << temperatures[indexOfColdestDay];
	cout << endl << "Hottest day of month is: " << indexOfHottestDay << ", temperature was: " << temperatures[indexOfHottestDay];
	cout << endl << "Days with ZERO is: " << zeroDays;
}

void example2()
{
	const int N = 10;			// array length
	const int ENLARGEMENT = 3;	// enlargement elements number
	int k = 0, value = 0, usedElements = N;

	int array[N + ENLARGEMENT]{ 0 };

	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		array[i] = 10 - rand() % 21;  // -10..+10
		cout << array[i] << '\t';
	}


	// adding 1 element to array
	do
	{
		cout << endl << "Enter the position of added element: ";
		cin >> k;
	} while (k < 1 || k > usedElements);
	usedElements++;

	cout << endl << "Enter the value to add: ";
	cin >> value;

	for (int i = usedElements; i > k - 1; i--)
	{
		array[i] = array[i - 1];
	}

	array[k - 1] = value;

	cout << endl << "Array after adding of 1 element to position " << k << endl;
	for (int i = 0; i < usedElements; i++)
	{
		cout << array[i] << '\t';
	}

	// Removing of the element
	do
	{
		cout << endl << "Enter the position of the element to remove: ";
		cin >> k;
	} while (k < 1 || k > usedElements);

	for (int i = k - 1; i < usedElements; i++)
	{
		array[i] = array[i + 1];
	}

	array[usedElements] = 0;
	usedElements--;

	cout << endl << "Array after removing of 1 element at position " << k << endl;
	for (int i = 0; i < usedElements; i++)
	{
		cout << array[i] << '\t';
	}


	// Removing of all negative elements
	int negatives = 0;
	for (int j = 0; j < usedElements; j++)
	{
		if (array[j] < 0)
		{
			for (int i = j; i < usedElements; i++)
			{
				array[i] = array[i + 1];
			}
			j--;
			usedElements--;
		}
	}
	cout << endl << "Array after removing of negative elements:" << endl;
	for (int i = 0; i < usedElements; i++)
	{
		cout << array[i] << '\t';
	}
}

int main()
{
	example1();
	example2();


	cout << endl << endl;

	int arr[2000]{ 0 };
	cout << endl << "Size in bytes of all array: " << sizeof(arr);
	cout << endl << "Size in bytes of one element: " << sizeof(int);
	cout << endl << "Number of elements in array: " << sizeof(arr) / sizeof(int);

	cout << endl << endl;

	return 0;
}


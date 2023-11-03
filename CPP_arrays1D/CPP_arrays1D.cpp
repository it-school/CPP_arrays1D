#include "pch.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include "CPP_arrays1D.h"

using namespace std;

/// <summary>
/// Declaration, filling, printing and sorting of static array
/// </summary>
void example0()
{
	const int N = 10;
	int arr[N]{ 0 };

	cout << endl << "Size in bytes of all array: " << sizeof(arr);
	cout << endl << "Size in bytes of one element: " << sizeof(int);
	cout << endl << "Number of elements in array: " << sizeof(arr) / sizeof(int);
	cout << endl << arr;


	for (size_t i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << '\t';
	}

	int temp;
	cout << endl << endl << "Bubble sort:" << endl;
	for (size_t j = 0; j < N - 1; j++)
	{
		for (size_t i = 0; i < N - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		cout << arr[i] << '\t';
	}


	cout << endl << endl << "Reversed selection sort:" << endl;
	int indexMin = 0;
	for (size_t j = 0; j < N; j++)
	{
		for (size_t i = j; i < N; i++)
		{
			if (arr[i] > arr[indexMin])
			{
				indexMin = i;
			}
		}
		temp = arr[j];
		arr[j] = arr[indexMin];
		arr[indexMin] = temp;
	}

	for (size_t i = 0; i < N; i++)
	{
		cout << arr[i] << '\t';
	}
}

/// <summary>
/// Example of statistical processing of month teperatures using 1-dimensonal array
/// </summary>
void example1()
{
	const int N = 31;	// array length
	srand(time(0));
	// int arr[N]{ -2,1,2,3,4,6,3,4,5,7,9,6,54,34,32,4 };			// static array of integer elements with initialization
	int temperatures[N]{ 0 };			// static array of integer elements with zeroes
	for (int day = 0; day < N; day++)
	{
		temperatures[day] = -2 + rand() % 23;
		cout << "day[" << day << "] = " << temperatures[day] << (!(day % 2) ? '\t' : '\n');
	}
	cout << endl;

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
	for (int day = 1; day < N; day++)
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

/// <summary>
/// Removing of an element
/// </summary>
/// <param name="array"></param>
/// <param name="SIZE"></param>
void printArray(const int array[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(5) << array[i];
	}
}

/// <summary>
/// Removing of all negative elements
/// </summary>
/// <param name="array"></param>
/// <param name="usedElements"></param>
void removingNegatives(int array[], int& usedElements)
{
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
}

/// <summary>
/// Removing of element in array
/// </summary>
/// <param name="array">array</param>
/// <param name="usedElements">array size</param>
/// <param name="k">number of element to remove</param>
void removeElement(int array[], int& usedElements, const int k)
{
	for (int i = k - 1; i < usedElements; i++)
	{
		array[i] = array[i + 1];
	}

	array[usedElements] = 0;
	usedElements--;
}

/// <summary>
/// Example of array partial use for resizing of 1-dimensional array
/// </summary>
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
	}

	cout << endl;
	printArray(array, usedElements);

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
	printArray(array, usedElements);


	// Removing of an element
	do
	{
		cout << endl << "Enter the position of the element to remove: ";
		cin >> k;
	} while (k < 1 || k > usedElements);
	removeElement(array, usedElements, k);
	cout << endl << "Array after removing of 1 element at position " << k << endl;
	printArray(array, usedElements);


	removingNegatives(array, usedElements);
	cout << endl << "Array after removing of negative elements:" << endl;
	printArray(array, usedElements);
}

int main()
{
	example0();

	cout << endl << endl;
	example1();

	cout << endl << endl;
	example2();

	cout << endl << endl;
	return 0;
}
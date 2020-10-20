#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	const int N = 10; // array length
	const int ENLARGEMENT = 1; // enlargement elements number
	int k = 0, value = 0;

	int array[N + ENLARGEMENT];

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
	} while (k < 1 || k > N);

	for (int i = N; i > k - 1; i--)
	{
		array[i] = array[i - 1];
	}

	cout << endl << "Enter the value to add: ";
	cin >> value;

	array[k - 1] = value;

	cout << endl << "Array after adding of 1 element to position " << k << endl;
	for (int i = 0; i < N + ENLARGEMENT; i++)
	{
		cout << array[i] << '\t';
	}

	// Removing of the element
	do
	{
		cout << endl << "Enter the position of the element to remove: ";
		cin >> k;
	} while (k < 1 || k > N);

	for (int i = k - 1; i < N; i++)
	{
		array[i] = array[i + 1];
	}

	array[N] = 0;

	cout << endl << "Array after removing of 1 element at position " << k << endl;
	for (int i = 0; i < N; i++)
	{
		cout << array[i] << '\t';
	}


	// Removing of all negative elements
	int negatives = 0;
	for (int j = 0; j < N-negatives; j++)
	{
		if (array[j] < 0)
		{
			for (int i = j; i < N; i++)
			{
				array[i] = array[i + 1];
			}
			j--;
			negatives++;
			//array[N] = 0;
		}
	}
	cout << endl << "Array after removing of negative elements:"<< endl;
	for (int i = 0; i < N-negatives; i++)
	{
		cout << array[i] << '\t';
	}
	
	// Sum and average value of all elements
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += array[i];
	}
	double average = (double)sum / N;

	cout << endl << "Sum: " << sum << endl;
	cout << "Average: " << average;

	// Searching of MIN and MAX values of array elements
	int maxIndex = 0;
	int minIndex = 0;
	for (int i = 1; i < N; i++)
	{
		if (array[i] > array[maxIndex])
			maxIndex = i;
		if (array[i] < array[minIndex])
			minIndex = i;
	}
	cout << endl << "Max is: " << array[maxIndex] << " is situated at: " << maxIndex;
	cout << endl << "Min is: " << array[minIndex] << " is situated at: " << minIndex;

	cout << endl << endl;
}


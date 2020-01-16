#include <iostream>
using namespace std;

void Heapify_MyArray(int MyArray[], int noe, int i)
{
	int greatest = i;  // take the root largest
	int Left = 2 * i + 1;
	int Right = 2 * i + 2;

	if (Left < noe && MyArray[Left] > MyArray[greatest])// If left child is greater than the parent
		greatest = Left;
	
	if (Right < noe && MyArray[Right] > MyArray[greatest])// If right child is greater than the greatest
		greatest = Right;
	
	if (greatest != i) // If greatest is not at root
	{
		int swap = MyArray[i];
		MyArray[i] = MyArray[greatest];	//swap
		MyArray[greatest] = swap;
		Heapify_MyArray(MyArray, noe, greatest);// Recursively heapify the affected sub-tree
	}
}

void Heap_Sort(int MyArray[], int noe)
{
	for (int i = noe / 2 - 1; i >= 0; i--) // build heap to rearrange the array
		Heapify_MyArray(MyArray, noe, i);
	
	for (int i = noe - 1; i >= 0; i--)// extract element 1 by 1
	{
		int swap = MyArray[0];
		MyArray[0] = MyArray[i];	// swap
		MyArray[i] = swap;
		Heapify_MyArray(MyArray, i, 0);
	}
}

void Display(int MyArray[], int noe)
{
	for (int i = 0; i < noe; i++)
		cout << MyArray[i] << "  ";
	cout << endl;
}

int main()
{
	int noe; // Number of elements
	cout << "No. of elements:  "; cin >> noe;
	int *MyArray = new int[noe];
	
	for (int i = 0; i < noe; i++) // input array
		cin >> MyArray[i];
	
	cout << "\n\tUnsorted array:\t";
	Display(MyArray, noe); // print unsorted array
	
	Heap_Sort(MyArray, noe);
	
	cout << "\n\tSorted array:\t";
	Display(MyArray, noe); // print sorted array
	
	cout << endl;
	return 0;
}

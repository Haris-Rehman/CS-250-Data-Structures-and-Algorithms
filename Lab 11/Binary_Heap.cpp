# include <iostream>
using namespace std;

int MyArray[50] = { 0 }; // 0 means empty
int NOE = 0;

void Display()
{
	cout << "\tArray:\t";
	for (int i = 1; MyArray[i] != 0; i++)
		cout << MyArray[i] << "  ";
	cout << endl << endl;
}

void Heapify_MyArray(int Array[], int noe, int i)
{
	int greatest = i;  // take the root largest
	int Left = 2 * i + 1;
	int Right = 2 * i + 2;

	if (Left < noe && Array[Left] > Array[greatest])// If left child is greater than the parent
		greatest = Left;

	if (Right < noe && Array[Right] > Array[greatest])// If right child is greater than the greatest
		greatest = Right;

	if (greatest != i) // If greatest is not at root
	{
		int swap = Array[i];
		Array[i] = Array[greatest];	//swap
		Array[greatest] = swap;
		Heapify_MyArray(Array, noe, greatest);// Recursively heapify the affected sub-tree
	}
}

void Heap_Sort(int Array[], int noe)
{
	for (int i = noe / 2 - 1; i >= 0; i--) // build heap to rearrange the array
		Heapify_MyArray(Array, noe, i);

	for (int i = noe - 1; i >= 0; i--)// extract element 1 by 1
	{
		int swap = Array[0];
		Array[0] = Array[i];	// swap
		Array[i] = swap;
		Heapify_MyArray(Array, i, 0);
	}
}

void Insert(int number) // number to be inserted
{
	int i = NOE + 1;
	MyArray[i] = number;
	NOE++;
	for (int i = NOE; i != 0; i /= 2)
		if (MyArray[i] < MyArray[i / 2])
			swap(MyArray[i], MyArray[i / 2]);
}

void Remove_Delete(int place) // delete from the specific index.
{
	MyArray[place] = 0;
	for (int i = place; i != 0; i /= 2)
		swap(MyArray[i], MyArray[i / 2]);
	swap(MyArray[NOE], MyArray[1]);
	for (int i = 1; i < NOE / 2;)
	{
		int left = 2 * i;
		int right = (2 * i) + 1;
		if (MyArray[left] > MyArray[right])
		{
			swap(MyArray[right], MyArray[i]);
			i = right;
		}
		else if (MyArray[left] < MyArray[right])
		{
			swap(MyArray[left], MyArray[i]);
			i = left;
		}
		else if (MyArray[left] == MyArray[right])
		{
			swap(MyArray[left], MyArray[i]);
			i = left;
		}
	}
}

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)  // element already in the middle
			return mid; 
		if (arr[mid] > x) // number is smaller than the Middle (left to the middle)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x); // number is larger than the Middle (right to the middle)
	}
	return -1; // element not present in the array
}

int main()
{
	cout << "Elements inserted.\n\n";
	Insert(3);
	Insert(10);
	Insert(11);
	Insert(5);
	Insert(15);
	Insert(17);
	Insert(13);
	Insert(12);
	Insert(11);
	Insert(8);
	Insert(21);
	Display();

	cout << "element at place 4 deleted.\n\n";
	Remove_Delete(4); // element at place 4 deleted
	Display();

	cout << "Sorted.\n\n";
	Heap_Sort(MyArray, NOE); // sorting
	Display();

	cout << "Searched 8.\n\n"; // Searched
	cout << "\tIndex of 8 is " << binarySearch(MyArray, 0, NOE, 8) << ".\n\n";

	return 0;
}

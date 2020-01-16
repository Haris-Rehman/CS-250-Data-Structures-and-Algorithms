# include <iostream>
using namespace std;

void Selection_Sort(int MyArray[], int Num)
{
	int i, j, minindex;
	for (i = 0; i < Num - 1; i++)
	{
		minindex = i;
		for (j = i + 1; j < Num; j++)
		if (MyArray[j] < MyArray[minindex])
			minindex = j;
		swap(MyArray[minindex], MyArray[i]);
	}
}

int main()
{
	int MyArray[5] = { 2, 8, 4, 6, 5 };
	cout << "Initial Array:\t";
	for (int j = 0; j < 5; j++)
		cout << MyArray[j] << "  ";
	cout << endl;
	int Num = sizeof(MyArray) / sizeof(MyArray[0]);
	Selection_Sort(MyArray, Num);
	cout << "Sorted Array:\t";
	for (int j = 0; j < 5; j++)
		cout << MyArray[j] << "  ";
	cout << endl;
}

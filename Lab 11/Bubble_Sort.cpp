# include <iostream>
using namespace std;

void Bubble_Sort(int MyArray[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (MyArray[j] > MyArray[j + 1])
			{
				swap(MyArray[j], MyArray[j + 1]);
			}
		}
	}
}

int main()
{
	int MyArray[6] = { 9, 4, 5, 2, 7, 1 };
	cout << "Input arr:\t";
	for (int i = 0; i < 6; i++)
		cout << MyArray[i] << "  ";
	cout << endl;
	Bubble_Sort(MyArray, 6);
	cout << "Output arr:\t";
	for (int i = 0; i < 6; i++)
		cout << MyArray[i] << "  ";
	cout << endl;
	return 0;
}

# include <iostream>
# include <stdexcept>
using namespace std;

float Marks[30]; // array of marks
// two copies of marks array
float QiuckSortedMarks[30]; // to be quick sorted
float MergeSortedMarks[30];	// to be merge sorted

// Founctions prototypes
void Quick_Sort(int, int);
void Merge_sort(int, int);
void Merging(int, int, int);
void Print_Display();

int main()
{
	try
	{
		cout << "\nEnter the Marks between 0 and 100:" << endl << endl;
		for (int i = 0; i < 30; i++) // input marks array
		{
			cout << "\tMarks[" << i << "] =\t";
			cin >> Marks[i];
			if (Marks[i] > 100 || Marks[i] < 0)
				throw exception("Wrong Number entered.\n");
			QiuckSortedMarks[i] = MergeSortedMarks[i] = Marks[i]; // generate two copies of marks array
		}
		Quick_Sort(0, 30 - 1);
		Merge_sort(0, 30 - 1);
		system("cls");
		cout << "Rearranged Marks:" << endl << endl;
		Print_Display(); // display
	}
	catch (exception &wrong)
	{
		cout << endl << wrong.what() << endl;
	}
	return 0;
}

void Quick_Sort(int Left, int Right)
{
	int i = Left, j = Right;
	int swap;
	int Pivot = QiuckSortedMarks[(Left + Right) / 2]; // pivot in center
	while (i <= j) // partition
	{
		while (QiuckSortedMarks[i] < Pivot) // comparing ith element with pivot
			i++;
		while (QiuckSortedMarks[j] > Pivot) // comparing jth element with pivot
			j--;
		if (i <= j)
		{ //sorting using swap
			swap = QiuckSortedMarks[i];
			QiuckSortedMarks[i] = QiuckSortedMarks[j];
			QiuckSortedMarks[j] = swap;
			i++;
			j--;
		}
	};
	// recursion
	if (Left < j)
		Quick_Sort(Left, j);
	if (i < Right)
		Quick_Sort(i, Right);
}

void Merge_sort(int Low, int High)
{
	int Middle;
	if (Low < High)
	{
		Middle = (Low + High) / 2;
		// Splitting of data into two halves
		Merge_sort(Low, Middle); // first half
		Merge_sort(Middle + 1, High); // second half
		Merging(Low, High, Middle); // Merging of splitted data to get sorted output.
	}
}

void Merging(int Low, int High, int Middle)
{
	int i, j, k;
	int *temporary = new int[High - Low + 1];
	i = Low;
	k = 0;
	j = Middle + 1;
	// Merge splitted parts to temporary pointer array
	while (i <= Middle && j <= High)
	{
		if (MergeSortedMarks[i] < MergeSortedMarks[j])
		{
			temporary[k] = MergeSortedMarks[i];
			k++;
			i++;
		}
		else
		{
			temporary[k] = MergeSortedMarks[j];
			k++;
			j++;
		}
	}
	// Insert all the remaining values from i to mid into temp[].
	while (i <= Middle) // put remaining values into temporary (from i to mid)
	{
		temporary[k] = MergeSortedMarks[i];
		k++;
		i++;
	}
	while (j <= High) // put remaining values into temporary (from j to high)
	{
		temporary[k] = MergeSortedMarks[j];
		k++;
		j++;
	}
	// Assign sorted data stored in temp[] to a[].
	for (i = Low; i <= High; i++) // assign data stored in temporary back to MergeSortedMarks
		MergeSortedMarks[i] = temporary[i - Low];
}

void Print_Display()
{
	cout << "Initial array:" << endl;
	cout << endl;
	for (int i = 0; i < 30; i++) // print the initial array of marks which was entered by user
		cout << "\tMarks[" << i << "] =\t" << Marks[i] << endl;
	cout << endl;
	cout << "Quick sorted array:" << endl;
	cout << endl;
	for (int i = 0; i < 30; i++) // print Quick sorted array
		cout << "\tMarks[" << i << "] =\t" << QiuckSortedMarks[i] << endl;
	cout << endl;
	cout << "Merge sorted array:" << endl;
	cout << endl;
	for (int i = 0; i < 30; i++) // print Merge sorted attay
		cout << "\tMarks[" << i << "] =\t" << MergeSortedMarks[i] << endl;
	cout << endl;
}

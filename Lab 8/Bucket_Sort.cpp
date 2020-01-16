#include<iostream>
using namespace std;

void Display(int[], int); // prototypes
void Bucket_Sort(int[], int);
void Sort_EveryBucket(int[], int);

int main()
{
	int noe; // number of elements in array
	cout << "No. of elements:  ";
	cin >> noe;
	int *MyArray = new int[noe];
	cout << endl;
	for (int i = 0; i < noe; i++) // input array
	{
		cout << "\t";
		cin >> MyArray[i];
	}
	Bucket_Sort(MyArray, noe); // Bucket sort Function call
	Display(MyArray, noe);
	cout << endl;
	return 0;
}

void Bucket_Sort(int MyArray[], int noe)
{
	// four buckets to sort data
	int BucketArray1[5]; int ptr1 = 0;
	int BucketArray2[5]; int ptr2 = 0;
	int BucketArray3[5]; int ptr3 = 0;
	int BucketArray4[5]; int ptr4 = 0;
	// inserting data in every bucket
	for (int i = 0; i < noe; i++)
	{
		if (MyArray[i] <= 25) // bucket1 0 - 25
		{
			BucketArray1[ptr1] = MyArray[i];
			ptr1++;
		}
		if (MyArray[i] > 25 && MyArray[i] <= 50) // bucket2 25 - 50
		{
			BucketArray2[ptr2] = MyArray[i];
			ptr2++;
		}
		if (MyArray[i] > 50 && MyArray[i] <= 75) // bucket3 50 - 75
		{
			BucketArray3[ptr3] = MyArray[i];
			ptr3++;
		}
		if (MyArray[i] > 75 && MyArray[i] <= 100) // bucket4 75 - 100
		{
			BucketArray4[ptr4] = MyArray[i];
			ptr4++;
		}
	}
	//sorting data in every bucket
	Sort_EveryBucket(BucketArray1, ptr1);
	Sort_EveryBucket(BucketArray2, ptr2);
	Sort_EveryBucket(BucketArray3, ptr3);
	Sort_EveryBucket(BucketArray4, ptr4);
	// Now combining every bucket to form sorted Array
	for (int a = 0; a < noe; a++)
	{
		int b;
		if (ptr1 != 0)
		{
			for (b = 0; b < ptr1; b++)
			{
				MyArray[a] = BucketArray1[b];
				a++;
			}
		}
		if (ptr2 != 0)
		{
			for (b = 0; b < ptr2; b++)
			{
				MyArray[a] = BucketArray2[b];
				a++;
			}
		}
		if (ptr3 != 0)
		{
			for (b = 0; b < ptr3; b++)
			{
				MyArray[a] = BucketArray3[b];
				a++;
			}
		}
		if (ptr4 != 0)
		{
			for (b = 0; b < ptr4; b++)
			{
				MyArray[a] = BucketArray4[b];
				a++;
			}
		}
	}
}

void Sort_EveryBucket(int MyArray[], int noe) // sorting every bucket
{
	for (int i = 0; i < noe - 1; i++)
	{
		for (int j = 0; j < noe - i - 1; j++)
		{
			if (MyArray[j] > MyArray[j + 1])
			{
				int swap = MyArray[j];
				MyArray[j] = MyArray[j + 1];
				MyArray[j + 1] = swap;
			}
		}
	}
}

void Display(int MyArray[], int size)
{
	cout << "\n\nSorted elements:\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << "\t" << MyArray[i] << endl;
	}
}

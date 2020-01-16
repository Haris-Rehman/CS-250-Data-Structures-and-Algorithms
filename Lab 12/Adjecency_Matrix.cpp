# include <iostream>
using namespace std;

void insert(int My_Array[][5], int i, int j, int value)
{
	My_Array[i][j] = value;
}

void displayAdjecencyMatrix(int My_Array[][5], int I, int J)
{
	for (int i = 0; i < I; i++)
	{
		cout << "\t";
		for (int j = 0; j < J; j++)
		{
			cout << My_Array[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

int visitingNodes(int Visited[], int ctr, int My_Array[][5])
{
	Visited[ctr] = 0;
	cout << Visited[ctr] << "  ";
	ctr++;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (My_Array[i][j] == 1)
			{
				int asd = 0;
				for (int a = 0; a < 5; a++)
				{
					if (Visited[a] == j) asd = 1;
				}
				if (asd == 0)
				{
					Visited[ctr] = j;
					cout << Visited[ctr] << "  ";
					ctr++;
				}
			}
		}
	}
	cout << endl;
	return ctr;
}

void stackPop(int my_ctr, int Visited[])
{
	my_ctr--;
	for (; my_ctr >= 0; my_ctr--)
	{
		cout << Visited[my_ctr] << "  ";
		Visited[my_ctr] = '\0';
	}
}

int main()
{
	int My_Array[5][5] = { 0 }; // adjecency matrix
	int Visited[5] = { 0 }; //stack
	//linking
	insert(My_Array, 0, 1, 1);
	insert(My_Array, 0, 4, 1);
	insert(My_Array, 1, 2, 1);
	insert(My_Array, 1, 3, 1);
	insert(My_Array, 1, 4, 1);
	insert(My_Array, 2, 3, 1);
	insert(My_Array, 3, 4, 1);
	insert(My_Array, 1, 0, 1);
	insert(My_Array, 4, 0, 1);
	insert(My_Array, 2, 1, 1);
	insert(My_Array, 3, 1, 1);
	insert(My_Array, 4, 1, 1);
	insert(My_Array, 3, 2, 1);
	insert(My_Array, 4, 3, 1);
	//print
	cout << "Adjecency matrix:\n\n";
	displayAdjecencyMatrix(My_Array, 5, 5);
	//visiting all the nodes
	cout << "Visited:\n\n\t";
	int my_ctr= 0;
	my_ctr = visitingNodes(Visited, my_ctr, My_Array);
	//poping stack
	cout << "\n\npoping stack:\n\n\t";
	stackPop(my_ctr, Visited);
	cout << endl << endl;
	return 0;
}

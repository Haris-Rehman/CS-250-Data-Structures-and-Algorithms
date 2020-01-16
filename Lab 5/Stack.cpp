# include <iostream>
using namespace std;

struct node
{
	node*previus; // pointer pointing to the previus element of the stack implemented by list
	int data; // store the information in the stack implemented by list
	node*next;// pointer pointing to the next element of the stack implemented by list
};

class Stack
{
private:
	node *head; // pointer at the start of the stack implemented by list
	node *tail; // pointer at the end of the stack implemented by list
	int counter;// counting the total elements of the stack
public:
	Stack() // constructor
	{ // initially head and tail are NULL
		head = NULL;
		tail = NULL;
		counter = 0;
	}
	void createnode(int value)
	{ // create node when there is no element
		counter++;
		node *temporary = new node;   // temporary node to store the value temporarily
		temporary->data = value;
		temporary->next = NULL;       // there is only one element in the stack,
		temporary->previus = NULL;    // so next and previus pointers are NULL

		head = temporary;			  // head and tail are the same item
		tail = temporary;			  // because of only one item in the stack
		temporary = NULL;
	}
	void insert(int value)// inserting the element
	{
		node *temporary = new node;
		temporary->data = value;
		temporary->next = NULL;
		temporary->previus = tail;// inserting temporary node
		tail->next = temporary;
		tail = temporary;// moving the tail to the temporary pointer
		counter++;
	}
	void remove() // delete element
	{
		node *temporary = new node;
		temporary = tail; // storing the head in the tail
		if (tail->previus != NULL) // if there is more than one element in the stack
		{
			tail = tail->previus; // moving the tail to previus node
			tail->next = NULL; // and next of tail to NULL
		}
		delete temporary;
		temporary = NULL;
		counter--;
	}
	void display() // display last element intered in the stack
	{
		cout << "\nPeak element in stack:\t";
		cout << tail->data;
		cout << endl;
	}
	void remove_all(int total) // remove all the elements in the stack
	{						   // one by one
		for (int i = 1; i < total; i++)
		{
			remove();
		}
		counter = 0;
	}
	void checkempty()
	{
		if (counter == 0)
			cout << "\nstack is empty." << endl;
		else
			cout << "\nstack has " << counter << " elements" << endl;
	}
	void checkfull()
	{
		if (counter == 10)
			cout << "\nstack is full." << endl;
		else
			cout << "\nstack has " << counter << " elements" << endl;
	}
};

int main()
{
	Stack st; // object of the list
	int dat; // data
	cout << "\nStack: No items in stack" << endl;
	cout << endl << endl;
	int i = 0; // counter for counting the elements of the stack
	int input; // user choice of operations
	while (1)
	{
		try
		{
			cout << "OPERATIONS:\n";
			cout << "\t1 = insert in stack" << endl;
			cout << "\t2 = delete from stack" << endl;
			cout << "\t3 = clear stack" << endl;
			cout << "\t4 = check empty" << endl;
			cout << "\t5 = check full" << endl;
			cout << "\t0 = exit" << endl;
			cin >> input;
			switch (input)
			{
			case 1:
				if (i < 10)
				{
					int d; // data
					cout << "data you want to insert: ";
					cin >> d; // data
					if (i == 0)
						st.createnode(d);
					else
						st.insert(d);// insert data in the stack
					i++;// increment in no. of items in the stack
				}
				else
				{
					st.checkfull();
					getchar(); // stay
					cin.ignore();
				}
				break;
			case 2:
				if (i > 0)
				{
					st.remove();// delete data from stack
					i--;// Decrement in no. of items in the stack
				}
				else
				{
					st.checkempty(); // check whether the stack is empty
					getchar();
					cin.ignore();
				}
				break;
			case 3:
				st.remove_all(i); // remove all the elements of the stack
				i = 0; // number of elements in stack is zero
				system("cls");
				cout << "\nStack:\tNo Items in the stack\n";
				break;
			case 4:
				st.checkempty();
				getchar();
				cin.ignore();
				break;
			case 5:
				st.checkfull();
				getchar();
				cin.ignore();
				break;
			case 0:
				return 0;
				break;
			}
			system("cls");
			if (i < 1)
			{ // exception handdled
				throw exception("\nStack:\tNo Items in the stack\n");
			}
			st.display(); // display last element in the stack
		}
		catch (exception e) // exception handled
		{
			cout << e.what();
		}
		cout << endl << endl;
	}
}

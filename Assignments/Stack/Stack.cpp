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
	int min[10];// array to store minimum values
	// minimum value is which is at the top of min array
	int ctr = 0;// counter to count elements in min array
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
		///////////////////////////////////////////////
		//update ctr and min array
		min[ctr] = value;
		ctr++;
		////////////////////////////////////////////////
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
		///////////////////////////////////////////////////
		//update ctr and min array
		if (value < min[ctr - 1])
		{
			min[ctr] = value;
			ctr++;
		}
		////////////////////////////////////////////////////
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
		//////////////////////////////////////////////
		//update min array while removing elements from array
		if (min[ctr-1] == temporary->data)
		{
			min[ctr - 1] = NULL;
			ctr--;
		}
		//////////////////////////////////////////////
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
	////////////////////////////////////
	int return_min()
	{
		return min[ctr - 1];
	}
	////////////////////////////////////
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
			cout << "\t3 = check Minimum value" << endl;
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
			case 3:
				cout << endl << "Minimum value = " << st.return_min() << endl;
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


// THE ORDER OF ALL THE OPERATIONS ON FINDING THE MINIMUM VALUE IN THE STACK IS OF THE ORDER 1.
// There is an array based stack to store min values and is updated if any element is inserted or removed.
// Top value in the array based stack is the Minimum value in the stack.
// There is no any saperate function to find the min value in stack. it requires big-O(n).

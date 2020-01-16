# include <iostream>
using namespace std;

struct node
{
	node*previus; // pointer pointing to the previus element of the list
	int data; // store the information in the list
	node*next;// pointer pointing to the next element of the list
};

class list
{
private:
	node *head; // pointer at the start of the list
	node *tail; // pointer at the end of the list
public:
	list() // constructor
	{ // initially head and tail are NULL
		head = NULL;
		tail = NULL;
	}
	void createnode(int value)
	{ // create node when there is no element in the list
		node *temporary = new node; // temporary node to store the value temporarily
		temporary->data = value; 
		temporary->next = NULL;       // there is only one element in the list,
		temporary->previus = NULL;    // so next and previus pointers are NULL
		head = temporary;			  // head and tail are the same item
		tail = temporary;			  // because of only one item in the list
		temporary = NULL;
	}
	void insertinstart(int value)// inserting the element in the start of the list
	{
		node *temporary = new node;
		temporary->data = value; 
		temporary->next = head; // inserting temporary node in the start of the list
		temporary->previus = NULL;
		head->previus = temporary; // doubly linked list
		head = temporary; // moving the head to the temporary pointer
	}
	void insertinend(int value)// inserting the element in the end of the list
	{
		node *temporary = new node;
		temporary->data = value;
		temporary->next = NULL;
		temporary->previus = tail;// inserting temporary node in the end of the list
		tail->next = temporary;
		tail = temporary;// moving the tail to the temporary pointer
	}
	void insertinmiddle(int pos, int value)
	{			// inserting the element in the middle of the list
		node *temporary = new node; 
		temporary->data = value; 
		// two temporary nodes
		node *p = new node;	 // store the element of the next node
		node *q = new node; // store the element of the previus node
		p = head; // starting from the head
		for (int i = 1; i < pos; i++)
		{ // then traversing to the position where the element has to be inserted
			p = p->next;
		}
		q = p->previus;
		// split q and p and inserting element between them.
		q->next = temporary; // temporary is next to q
		temporary->previus = q; // q is previus to temporary
		temporary->next = p; // p is next to temporary
		p->previus = temporary; // temporary is previus to p
	}
	void deletefromstart() // delete element from the start of the list
	{
		node *temporary = new node;
		temporary = head; // storing the head in the temporary
		if (head->next != NULL) // if there is more than one element in the list
		{
			head = head->next; // moving the head to next element
			head->previus = NULL; // and its previus to NULL
		}
		delete temporary;
		temporary = NULL;
	}
	void deletefromend() // delete element from the end of the list
	{
		node *temporary = new node;
		temporary = tail; // storing the head in the tail
		if (tail->previus != NULL) // if there is more than one element in the list
		{
			tail = tail->previus; // moving the tail to previus node
			tail->next = NULL; // and next of tail to NULL
		}
		delete temporary;
		temporary = NULL;
	}
	void deletefrommiddle(int pos) // delete element from the middle of the list
	{
		node *temporary = new node;
		temporary = head; // assigning head to temporary
		for (int i = 1; i < pos; i++) // traversing to the required position
		{
			temporary = temporary->next;
		}
		node *p = new node;
		node *q = new node;
		p = temporary->previus; // p is previus to temporary
		q = temporary->next; // q is next to temporary
		// deleting temporary from between
		p->next = q; // q is next to p
		q->previus = p; // p is previus to q
		delete temporary;
		temporary = NULL;
	}
	void display() // display list
	{
		cout << "\nList:\t";
		node *temporary = new node;
		temporary = head; // assigning head to temporary
		while (temporary != NULL)
		{ // moving forward and printong the element
			cout << temporary->data << "\t";
			temporary = temporary->next;
		}
		cout << endl;
	}
	void displayreverse()// display list in the reverse order
	{
		cout << "\nReverse List:\t";
		node *temporary = new node;
		temporary = tail; // assigning tail to head
		while (temporary != NULL)
		{ // moving backward and displaying the element
			cout << temporary->data << "\t";
			temporary = temporary->previus;
		}
		cout << endl;
	}
	void searchfounction(int Num) // founction to search the required number
	{
		node *number = nullptr; // pointer to search the desired number
		node *temporary = new node;
		node *c = new node; // one more temporary pointer
		temporary = head;
		c = head; // starting from head
		int i = 1;
		while (c != NULL && c->data != Num)
		{ // traversing
			temporary = c;
			c = c->next;
			i++;
		}
		if (c != NULL)
		{
			number = c;
			c = c->next;
			cout << "\n\nPlace of " << Num << " is " << i << endl;
			// printing the place of the required element
		}
		else
		{
			cout << "\n\nNot Found.";
		}
		cout << "\n\nPress Enter to chose next operation.";
		cin.ignore();
		getchar();
	}
	void remove_all(int total) // remove all the elements in the list
	{						   // one by one
		for (int i = 1; i < total; i++)
		{
			deletefromend();
		}
	}
};

int main()
{
	list l; // object of the list
	int dat; // data
	cout << "\tWELCOME TO THE LIST";
haris:
	cout << endl << endl;
	cout << "Enter data to create node: ";
	cin >> dat; // data
	l.createnode(dat); // craete first element of the list
	system("cls");
	l.display(); // display list
	cout << endl << endl;
	int i = 1; // counter for counting the elements of the list
	int input; // user choice of operations
	while (1)
	{
		try
		{
			cout << "\n\nOPERATIONS:\n";
			cout << "\t1 = insert at start" << endl;
			cout << "\t2 = insert at end" << endl;
			cout << "\t3 = insert in the middle" << endl;
			cout << "\t4 = delete from start" << endl;
			cout << "\t5 = delete from end" << endl;
			cout << "\t6 = delete from middle" << endl;
			cout << "\t7 = search in the list" << endl;
			cout << "\t8 = Distroy list" << endl;
			cout << "\t9 = Display list in reverse order" << endl;
			cout << "\t0 = exit" << endl;
			cin >> input;
			switch (input)
			{
			case 1:
				int da; // data
				cout << "data you want to insert: ";
				cin >> da; // data
				l.insertinstart(da); // insert data in the start of the list
				i++; // increment in no. of items in the list
				break;
			case 2:
				int d; // data
				cout << "data you want to insert: ";
				cin >> d; // data
				l.insertinend(d);// insert data in the end of the list
				i++;// increment in no. of items in the list
				break;
			case 3:
				int date; // data
				int position;
				cout << "Enter position: ";
				cin >> position;
				if (position > i || position < 1)
				{
					cout << "\nWrong Position.\n";
					cout << "\n\nPress Enter to chose next operation.";
					cin.ignore();
					getchar();
				}
				else
				{
					cout << "data you want to insert: ";
					cin >> date; // data
					l.insertinmiddle(position, date);// insert data in the middle of the list
					i++; // increment in no. of items in the list
				}
				break;
			case 4:
				if (i > 0)
				{
					l.deletefromstart(); // delete data from the start of list
					i--;// Decrement in no. of items in the list
				}
				break;
			case 5:
				if (i > 0)
				{
					l.deletefromend();// delete data from the end of list
					i--;// Decrement in no. of items in the list
				}
				break;
			case 6:
				if (i > 0)
				{
					int pos; // position
					cout << "enter position: ";
					cin >> pos;
					if (pos > i || pos < 1)
					{
						cout << "\nWrong Position.\n";
						cout << "\n\nPress Enter to chose next operation.";
						cin.ignore();
						getchar();
					}
					else
					{
						l.deletefrommiddle(pos); // delete element from the middle of the list
						i--; // Decrement in no. of items in the list
					}
				}
				break;
			case 0:
				return 0; // end program
				break;
			case 7:
				if (i > 0)
				{
					int f; // number to be searched
					cout << "enter number to be searched: ";
					cin >> f;// number to be searched
					l.searchfounction(f); // search data in the list
				}
				break;
			case 8:
				l.remove_all(i); // remove all the elements of the list
				i = 0; // number of elements in list is zero
				system("cls");
				cout << "\nList:\tNo Items in the List\n";
				goto haris;
				break;
			case 9:
				l.displayreverse();
				cout << "\nPress Enter to chose next operation.";
				cin.ignore();
				getchar();
				break;
			}
			system("cls");
			if (i < 1)
			{ // exception handdled
				throw exception("\nList:\tNo Items in the List\n");
			}
			l.display(); // display list
		}
		catch (exception e)
		{
			cout << e.what();
			goto haris;
		}
		cout << endl << endl;
	}
}

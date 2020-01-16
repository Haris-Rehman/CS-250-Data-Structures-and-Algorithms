# include <iostream>
# include <stdexcept>
using namespace std;

struct node
{ // struct of node
	int data; // inforation
	node *next; // pointer pointing to to the next element
};

class list
{
private:
	node *head; // singly linked list
public:
	list()
	{ // initially no item in the head
		head = NULL;
	}
	void createnewnode(int value)
	{ // create first element of the list
		node *temporary = new node;
		temporary->data = value; // temporary contain the information of the value
		temporary->next = NULL;
		head = temporary; // assigning to head
		temporary = NULL;
	}
	void insertatstart(int value)
	{ // insert element at the start of the list
		node *temporary = new node;
		temporary->data = value; // assigning information to the data of temporary
		temporary->next = head;
		head = temporary; // moving head to first element
	}
	void insertatend(int value)
	{// insert element at the end of the list
		node *temporary = new node; // temp node to store the value temporarily
		node *p = new node; // p node for traversing to the end
		temporary->data = value;// assigning information to the data of temporary
		temporary->next = NULL;
		p = head;
		while (p->next != NULL)
		{ // traversing
			p = p->next; // moving pointer to the next element
		}
		p->next = temporary; // assigning address of temporary to the nextptr at the end of the list
	}
	void insertatmiddle(int pos, int value)
	{
		node *pre = new node; // store address of previous node
		node *cur = new node; // stor address of current node
		node *temporary = new node; // temporary node to store the value
		cur = head;
		for (int i = 1; i < pos; i++)
		{ // traversing
			pre = cur;
			cur = cur->next;
		}
		temporary->data = value; // assigning information to the data of temporary
		// insertion at the middle of the list
		pre->next = temporary;
		temporary->next = cur;
	}
	void deletefromstart()
	{ // delete element from the start of the list
		node *temporary = new node;
		temporary = head;
		head = head->next; // moving head to the next element in the list
		delete temporary;
	}
	void deletefromend()
	{// delete element from the end of the list
		node *current = new node; // store address of current node
		node *previous = new node; // store address of previous node
		current = head;
		while (current->next != NULL)
		{ // traversing
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
		delete current;
	}
	void deletefrommiddle(int pos)
	{
		node *current = new node;// store address of current node
		node *previous = new node;// store address of previous node
		current = head;
		for (int i = 1; i < pos; i++)
		{ // traversing
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}
	void display()
	{ // display the list
		cout << "\nList:\t";
		node *temporary = new node;
		temporary = head;
		while (temporary != NULL)
		{ // traversing
			cout << temporary->data << "\t";
			temporary = temporary->next;
		}
		cout << endl;
	}
	void searchfounction(int Num)
	{ // searching the data
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
	void remove_all(int total)
	{
		// delete all the elements from the list one by one
		for (int i = 1; i <= total; i++)
		{
			deletefromend();
		}
	}
};

int main()
{
	list l;
	int dat;
	cout << "\tWELCOME TO THE LIST";
haris:
	cout << endl << endl;
	cout << "Enter data to create node: ";
	cin >> dat;
	l.createnewnode(dat); // craete first element of the list
	system("cls");
	l.display(); // display list
	cout << endl << endl;
	int i = 1; // counter for counting the elements of the list
	int input;
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
			cout << "\t0 = exit" << endl;
			cin >> input;
			switch (input)
			{
			case 1:
				int da; // data
				cout << "data you want to insert: ";
				cin >> da;
				l.insertatstart(da); // insert data in the start of the list
				i++; // increment in no. of items in the list
				break;
			case 2:
				int d; // data
				cout << "data you want to insert: ";
				cin >> d;
				l.insertatend(d);// insert data in the end of the list
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
					l.insertatmiddle(position, date);// insert data in the middle of the list
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
					if (position > i || position < 1)
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
					int f; // number to be researched
					cout << "enter number to be searched: ";
					cin >> f;
					l.searchfounction(f); // search data in the list
				}
				break;
			case 8:
				l.remove_all(i); // remove all the elements of the list
				i = 0;
				system("cls");
				cout << "\nList:\tNo Items in the List\n";
				goto haris;
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
		}
		cout << endl << endl;
	}
}

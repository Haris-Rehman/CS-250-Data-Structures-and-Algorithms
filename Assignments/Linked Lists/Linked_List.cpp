# include <iostream>
using namespace std;

struct node
{
	node *head1;
	node *tail1;
	node *head0;
	node *tail0;

	node *previus;
	int data;
	node *next;

	void oddcreator() // creates the list of odd numbers
	{
		node *tem = new node;
		tem->data = 1;
		tem->next = tem;
		tem->previus = tem;
		head1 = tem;
		tail1 = tem;
		for (int i = 3; i < 10; i += 2)
		{
			node *temp = new node;
			temp->data = i;
			temp->next = head1;
			tail1->next = temp;
			temp->previus = tail1;
			tail1 = temp;
		}
	}

	void evencreater()// creates the list of even numbers
	{
		node *tem = new node;
		tem->data = 0;
		tem->next = tem;
		tem->previus = tem;
		head0 = tem;
		tail0 = tem;
		for (int i = 2; i < 10; i += 2)
		{
			node *temp = new node;
			temp->data = i;
			temp->next = head0;
			tail0->next = temp;
			temp->previus = tail0;
			tail0 = temp;
		}
	}

	void display0() // display even numberd list
	{
		node *temp = new node;
		temp = head0;
		cout << "LIST0:\t";
		while (temp != tail0 && temp != tail1)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << temp->data << "\t";
		cout << endl;
	}

	void display1()// display odd numberd list
	{
		node *temp = new node;
		temp = head1;
		cout << "LIST1:\t";
		while (temp != tail1 && temp != tail1)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << temp->data << "\t";
		cout << endl;
	}

	void concatenate()
	{ // concatenate the even list and odd list
		tail0->next = head1;
		head1->previus = tail0;
		head1 = tail0 = NULL;
		tail1->next = head0;
		head0->previus = tail1;
	}

	void neworder()
	{
		// arrange the elements in the new ascending order
		node *qw = new node;
		for (int i = 0; i < 9; i++)
		{
			qw = head0;
			for (int j = 0; j < 9 - i; j++)
			{
				if (qw->data > qw->next->data)
				{ // bubble sorting algorithm for swapping
					int t = qw->data;
					qw->data = qw->next->data;
					qw->next->data = t;
				}
				qw = qw->next;
			}
		}
	}

	void deleteelement(int position) // delete element from the position
	{
		position--;
		node *temp = new node;
		temp = head0;
		for (int i = 1; i <= position; i++)
			temp = temp->next;
		temp->previus->next = temp->next;
		temp->next->previus = temp->previus;
		delete temp;
		temp = NULL;
	}

	void sumofintegers() // display sum of all data in the list
	{
		{
			int sum = 0;
			node *temporary = new node;
			temporary = head0;
			do {
				sum = sum + temporary->data;
				temporary = temporary->next;
			} while (temporary != head0);
			cout << "\nSum of integers in the list: " << sum << endl;
		}
	}

	void numberofelements() // display number of elements in the list
	{
		node *temporary = new node;
		temporary = head0;
		int num = 0;
		while (temporary->next != head0)
		{
			num++;
			temporary = temporary->next;
		}
		num++;
		cout << "\nnumber of elements:  " << num << endl << endl;
	}

	void deletingeverysecondnode() // delete every second node
	{
		node *pa = new node;
		node *qb = new node;
		pa = head0;
		qb = pa->next;
		do
		{
			pa->next = qb->next;
			qb->next->previus = pa;
			delete[] qb;
			pa = pa->next;
			qb = pa->next;
		} while (qb != head0->previus);
		pa->next = head0;
		head0->previus = pa;
		tail1 = pa;
		delete qb;
	}

	void movenodeforward()
	{ // move nth node m position forward
		int n, m;
		cout << "\nnode you want to move: ";
		cin >> n;
		cout << "number of places you want to jump: ";
		cin >> m;
		node*temp = new node;
		temp = head0;
		for (int i = 0; i < n - 1; i++)
		{
			temp = temp->next;
		}
		node*p = temp;
		temp->previus->next = temp->next;
		temp->next->previus = temp->previus;

		node *q = p;
		for (int g = 0; g < m; g++)
		{
			q = q->next;
		}

		p->next = q->next;
		p->previus = q;
		q->next = p;
		q->next->previus = p;
	}

	void movebackward()
	{// move yth node z position forward
		int y, z;
		cout << "\n(counting from the end)" << endl;
		cout << "enter node you want to move:  ";
		cin >> y;
		cout << "enter positions you want to jump:  ";
		cin >> z;
		node*end = tail1;
		for (int i = 0; i < y - 1; i++)
		{
			end = end->previus;
		}
		node*r = new node;
		r = end;
		end->next->previus = end->previus;
		end->previus->next = end->next;
		node *q = new node;
		q = r;
		for (int t = 0; t < z; t++)
		{
			q = q->previus;
		}
		r->previus = q->previus;
		r->next = q;
		q->previus->next = r;
		q->previus = r;
	}

	void insertinmiddle(int d, int pos)
	{ // insert node in the middle
		node *temporary = new node;
		temporary->data = d;
		// two temporary nodes
		node *p = new node;	 // store the element of the next node
		node *q = new node; // store the element of the previus node
		p = head0; // starting from the head
		for (int i = 1; i <+pos; i++)
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

	void copylist()
	{
		node* head3 = new node;
		{
			node*cp = head3;
			node*old = head0;
			for (int i = 1; i < 12; i++)
			{
				head3->next = new node;
				head3->next->previus = head3;
				head3 = head3->next;
			}
			head3->next = cp;
			head3->data = 12;
			head3 = cp;

			do
			{
				head3->data = head0->data;
				head3 = head3->next;
				head0 = head0->next;
			} while (head3 != cp && head0 != old);

		}
		cout << "copied list is " << endl;
		// display new copied list
		node *temp = new node;
		temp = head3;
		cout << "LISTnew:\t";
		temp = temp->next->next;
		while (temp->next != head3)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << temp->data << "\t";
		cout << endl;
	}
};

int main()
{
	node n1;
	n1.evencreater(); // initiallizes the list of even numbers
	n1.display0();
	n1.oddcreator(); // initiallizes the list of odd numbers
	n1.display1();

	n1.concatenate();
	cout << "lists concatinated." << endl;
	n1.display0();

	n1.neworder();
	cout << "list arranged in ascending order." << endl;
	n1.display0();

	int input;
	while (1)
	{
		cout << endl << endl;
		n1.display0();
		cout << "\n\n 1 = sum of integers" << endl;
		cout << " 2 = number of elements" << endl;
		cout << " 3 = delete every second node" << endl;
		cout << " 4 = move node forward" << endl;
		cout << " 5 = move node backward" << endl;
		cout << " 6 = delete from middle" << endl;
		cout << " 7 = insert in middle" << endl;
		cout << " 8 = make another copy of list" << endl;
		cout << " 9 = rearange list" << endl;
		cout << " 0 = exit" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			n1.sumofintegers();
			break;
		case 2:
			n1.numberofelements();
			break;
		case 3:
			n1.deletingeverysecondnode();
			cout << "Every second node deleted." << endl;
			//display0();
			break;
		case 4:
			n1.movenodeforward();
			cout << "node moved forward." << endl;
			//display0();
			break;
		case 5:
			n1.movebackward();
			cout << "node moved backward." << endl;
			//display0();
			break;
		case 6:
			int e;
			cout << "Enter the element you want to delete: ";
			cin >> e;
			n1.deleteelement(e);
			cout << "3rd element deleted" << endl;
			//display0();
			break;
		case 7:
			int d, p;
			cout << "\nEnter the element to be added: ";
			cin >> d;
			cout << "Enter position where to be added:  ";
			cin >> p;
			n1.insertinmiddle(d, p);
			//display0();
			break;
		case 8:
			n1.copylist();
			cout << "list is copied" << endl;
			break;
		case 9:
			n1.neworder();
			break;
		case 0:
			return 0;
		}
	}
	return 0;
}

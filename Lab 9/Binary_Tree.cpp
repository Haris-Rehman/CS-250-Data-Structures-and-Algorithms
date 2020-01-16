# include <iostream>
using namespace std;

struct MyNode
{
	MyNode *Parent; // parent
	MyNode *LeftChild; // left
	MyNode *RightChild; // right
	int DATA; // info
};

int Found;

class Tree
{
private:
	MyNode *ROOT;
public:
	Tree() // default constructor
	{
		ROOT = new MyNode;
		ROOT->LeftChild = ROOT->Parent = ROOT->RightChild = NULL;
		ROOT->DATA = NULL; // initiallizing root from NULL
	}
	void Insert_Function(int n)
	{
		MyNode *Temporary = new MyNode;
		Temporary->DATA = n;
		Temporary->LeftChild = Temporary->RightChild = Temporary->Parent = NULL;
		MyNode *p; // another temporary node
		p = ROOT; // p at root
		if (ROOT->DATA == NULL) // for the First Element to be entered
			ROOT = Temporary;
		else // if some elements are already inserted
		{
			while (p->RightChild != NULL && p->LeftChild != NULL) // reach at the bottom
			{
				if (Temporary->DATA > p->DATA) // right child greater than parent
					p = p->RightChild;
				else // left child smaller than parent
					p = p->LeftChild;
			}
			if (Temporary->DATA > p->DATA) // right child greater than parent
			{
				p->RightChild = Temporary;
				Temporary->Parent = p;
			}
			else // left child smaller than parent
			{
				p->LeftChild = Temporary;
				Temporary->Parent = p;
			}
		}
	}
	void Delete_Function(int x)
	{
		MyNode *a = NULL;
		MyNode *b = NULL;
		a = b = ROOT;
		while (a != NULL && a->DATA != x)
		{
			b = a;
			if (x < a->DATA)
				a = a->LeftChild;
			else
				a = a->RightChild;
		}
		if (a == NULL)
			return;
		if (a->LeftChild == NULL && a->RightChild == NULL)
		{
			b->RightChild = NULL;
			delete a;
			a = NULL;
		}
	}
	void Inorder_Function(MyNode *Root)
	{
		if (Root != NULL)
		{
			Inorder_Function(Root->LeftChild);
			cout << Root->DATA << "  ";
			Inorder_Function(Root->RightChild);
		}
	}
	void Postorder_Function(MyNode *Root)
	{
		if (Root != NULL)
		{
			Postorder_Function(Root->LeftChild);
			Postorder_Function(Root->RightChild);
			cout << Root->DATA << "  ";
		}
	}
	void Preorder_Function(MyNode *Root)
	{
		if (Root != NULL)
		{
			cout << Root->DATA << "  ";
			Preorder_Function(Root->LeftChild);
			Preorder_Function(Root->RightChild);
		}
	}
	void Display_Function() // display preorder, inorder, postorder
	{
		cout << "Preorder:\t";
		Preorder_Function(ROOT);
		cout << endl;
		cout << "Inorder:\t";
		Inorder_Function(ROOT);
		cout << endl;
		cout << "Postorder:\t";
		Postorder_Function(ROOT);
		cout << endl << endl;
	}
	void search(int n, MyNode *Root)
	{
		if (Root->DATA == n) // if found
			Found = 1;
		if (Root->LeftChild != NULL) // goes to left child
			search(n, Root->LeftChild);
		if (Root->RightChild != NULL) // goes to right child
			search(n, Root->RightChild);
	}
	void Search_Function(int n)
	{
		search(n, ROOT);
	}
	int Max_Function(int x, int y) // returns larger value
	{
		if (x >= y)
			return x;
		else 
			return y;
	}
	int Hight_Function(MyNode* rt)
	{
		if (rt == NULL)
			return 0;
		return 1 + Max_Function(Hight_Function(rt->LeftChild), Hight_Function(rt->RightChild));
	}
	bool BalanceCheck_Function(MyNode* r) // check balanced hight of tree
	{ 
		int lft; // left subtree hight
		int rt; // right subtree hight
		if (r == NULL) // tree is empty
			return true;
		lft = Hight_Function(r->LeftChild);
		rt = Hight_Function(r->RightChild);
		int x = abs(lft - rt); // if difference is greater than 1 then it is unbalanced
		if (x <= 1 && BalanceCheck_Function(r->RightChild) && BalanceCheck_Function(r->LeftChild))
			return true;
		return false;
	}
	void CheckBalance()
	{
		if (BalanceCheck_Function(ROOT) == true)
			cout << "tree is Balanced." << endl << endl;
		else if (BalanceCheck_Function(ROOT) == false)
			cout << "tree is UnBalanced." << endl << endl;;
	}
};

int main()
{
	Tree T1;

	cout << "Inserting Elements" << endl << endl;
	T1.Insert_Function(4);
	T1.Insert_Function(2);
	T1.Insert_Function(6);
	T1.Insert_Function(1);
	T1.Insert_Function(3);
	T1.Insert_Function(5);
	T1.Insert_Function(7);

	T1.Display_Function();

	// Element to be searched is 's'
	int s = 5; Found = 0;
	cout << "searched " << s << endl;
	T1.Search_Function(s);
	if (Found == 0)
		cout << s << " Not Found." << endl << endl;
	else
		cout << s << " Found." << endl << endl;

	s = 9; Found = 0;
	cout << "searched " << s << endl;
	T1.Search_Function(s);
	if (Found == 0)
		cout << s << " Not Found." << endl << endl;
	else
		cout << s << " Found." << endl << endl;

	T1.Delete_Function(7);

	cout << "7 Deleted." << endl << endl;

	T1.Display_Function();

	T1.CheckBalance();

	return 0;
}

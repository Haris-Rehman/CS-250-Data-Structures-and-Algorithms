# include <iostream>
# include <string>
# include <stdexcept>
# include <sstream>
# include "header.h"
using namespace std;

int Calculator::Quit() // quit program if expression is Q.
{
	if (charcounter == 1 && MyExp[0] == 'q')
		return -1;
	else
		return 0;
}

Calculator::Calculator() {} // default constructor

void Calculator::SetMyExp(string mexp) // store expression
{
	MyExp = mexp;
	charcounter = 0;
}

int Calculator::GetSolved() // return result
{
	return Solved;
}

int Calculator::AllOperations() // perform operations
{
	CountCharacters();// count characters in expression
	int q = Quit(); // check Quit
	if (q == -1)
		return q;
	StringToArrayConverter();
	InfixToPostfixConverter();
	PostfixSolver();
	return q;
}

void Calculator::CountCharacters() // count characters in expression
{
	for (int i = 0; MyExp[i] != '\0'; i++)
		charcounter = charcounter + 1;
	if (charcounter > 30)
	{ // mathematical expression cannot be greater than 30 characters
		Solved = 0;
		throw exception();
	}
}

///////////////////////////////////////////////////////////////////
///				0 is NULL char in int array.					///
/// to avoid confusion, i have used -10 instead of NULL char.	///
///////////////////////////////////////////////////////////////////

void Calculator::StringToArrayConverter() // convert string to int array
{
	int x;
	int Array[30]; // string to int array // individually
	for (int i = 0; i < 30; i++)
		Array[i] = IntegerArray[i] = -10;
	for (x = 0; x < MyExp.length(); x++)
	{ // signs cannot be stored in int array, so code words integers are used instead of them
		if (MyExp[x] == '+')
			Array[x] = -1; // store -1 for + in int array
		else if (MyExp[x] == '-')
			Array[x] = -2; // store -2 for - in int array
		else if (MyExp[x] == '/')
			Array[x] = -4; // store -4 for / in int array
		else if (MyExp[x] == '*')
			Array[x] = -3; // store -3 for * in int array
		else if (MyExp[x] == '(')
			Array[x] = -5; // store -5 for ( in int array
		else if (MyExp[x] == ')')
			Array[x] = -6; // store -6 for ) in int array
		else
			Array[x] = (MyExp[x]) - 48; // digit
	}
	int DigitCounter = 0;

	for (int i = 0, a = 0; Array[i] != -10; i = DigitCounter, a++) // for every digit //
	{
		if (Array[i] != -1 && Array[i] != -2 && Array[i] != -3 && Array[i] != -4 && Array[i] != -5 && Array[i] != -6 && Array[i] != '\0')
		{
			int Multiple = 1;
			for (int j = i; ; j++)
			{
				DigitCounter++;
				if (Array[j] == -1 || Array[j] == -2 || Array[j] == -3 || Array[j] == -4 || Array[j] == -5 || Array[j] == -6 || Array[j] == -10)
					break;
				Multiple *= 10;
			}
			Multiple /= 10;
			int intsum = 0; // converting every sapearate digit into int number in the integer array
			for (int j = i; ; j++, Multiple /= 10)
			{
				if (Array[j] == -1 || Array[j] == -2 || Array[j] == -3 || Array[j] == -4 || Array[j] == -5 || Array[j] == -6 || Array[j] == -10)
					break;
				intsum = intsum + Array[j] * Multiple;
			}
			IntegerArray[a] = intsum; // inserting into integer array
			DigitCounter--;
		}
		else
		{
			IntegerArray[a] = Array[i];
			DigitCounter++;
		}
	}
}

// i have used List for Push and Pop Operation in stack.
struct node
{
	int Precidence;
	int Digit;
	node *Next_Ptr;
	node *Previus_Ptr;
};

void Stack_Push(node *Head0, node*Node, int value) // Push Function in stack
{
	Node->Digit = value;
	Head0->Next_Ptr = Node;
	Node->Previus_Ptr = Head0;
	Node->Next_Ptr = NULL;


}//always do head=head->next after using this function
 //do not bring it back to its orignal position

int Stack_Pop(node*Head0) // moves the head back
{						  // return poped operator
	node *Ptr;
	Ptr = Head0;
	Head0 = Head0->Previus_Ptr;
	int Num = Ptr->Digit;
	delete Ptr;
	Ptr = NULL;
	return Num;
}

int Check_Digit(int asd)
{
	if (asd != -1 && asd != -2 && asd != -3 && asd != -4 && asd != -5 && asd != -6)
		return 1; // asd is digit
	else
		return 0; // asd is operator
}

void PrecidenceSetter(node *Head0, int sign)
{ // sets the precidence of the differant operators
	if (sign == -1) // +
		Head0->Precidence = 1;
	if (sign == -2) // -
		Head0->Precidence = 1;
	if (sign == -3) // *
		Head0->Precidence = 2;
	if (sign == -4) // /
		Head0->Precidence = 2;
	if (sign == -5) // (
		Head0->Precidence = 5;
	if (sign == -6) // )
		Head0->Precidence = 5;
}

void Calculator::InfixToPostfixConverter()
{
	int PostFixArray[30]; // maximum length = 30
	for (int i = 0; i < 30; i++)
		PostFixArray[i] = -10; // in my program, in int array, im using -10 instead of NULL character
	int PostIndex = 0;
	node* Head1 = new node;
	Head1->Digit = 0;
	Head1->Precidence = -1;
	Head1->Previus_Ptr = NULL;
	int Operat;
	int check; // check if it is sign or a number
	for (int i = 0; IntegerArray[i] != -10; i++)
	{
		check = Check_Digit(IntegerArray[i]);
		if (check == 1) // if digit
		{
			PostFixArray[PostIndex] = IntegerArray[i];
			PostIndex++;
		}
		if (check == 0) // if operator/sign
		{
			if (IntegerArray[i] != -6)
			{
				node *nnew = new node;
				Stack_Push(Head1, nnew, IntegerArray[i]);
				Head1 = Head1->Next_Ptr;
				nnew = NULL;
				PrecidenceSetter(Head1, IntegerArray[i]);
				if (Head1->Digit == -5)
					continue;
				if (Head1->Precidence <= Head1->Previus_Ptr->Precidence && Head1->Previus_Ptr->Digit != -5)
				{
					node*Temporary;
					//swapping values
					int temp, tmp;
					temp = Head1->Digit;
					Head1->Digit = Head1->Previus_Ptr->Digit;
					Head1->Previus_Ptr->Digit = temp;
					tmp = Head1->Precidence;
					Head1->Precidence = Head1->Previus_Ptr->Precidence;
					Head1->Previus_Ptr->Precidence = tmp;
					Temporary = Head1->Previus_Ptr;
					//swapping completed
					Operat = Stack_Pop(Head1);          //pop from the top of stack
					PostFixArray[PostIndex] = Operat;   //insert poped operator in postfix array
					PostIndex++;						//move postindex forward
					Head1 = Temporary;
				}
			}
			if (IntegerArray[i] == -6)
			{
				while (Head1->Digit != -5)
				{
					node*Temporary;
					Temporary = Head1->Previus_Ptr;
					Operat = Stack_Pop(Head1);          //pop from the top of stack
					PostFixArray[PostIndex] = Operat;   //insert poped operator in postfix array
					PostIndex++;						//move postindex forward
					Head1 = Temporary;
				}
				node*tmpry;
				tmpry = Head1->Previus_Ptr;
				Operat = Stack_Pop(Head1);               //pop from the top of stack
				PostFixArray[PostIndex] = Operat;		 //insert poped operator in postfix array
				PostIndex++;							 //move postindex forward
				Head1 = tmpry;
			}
		}
	}
	while (Head1->Previus_Ptr != NULL) // if any operator still remained unpoped
	{
		node*real = Head1->Previus_Ptr;
		Operat = Stack_Pop(Head1);          //pop from the top of stack
		PostFixArray[PostIndex] = Operat;   //insert poped operator in postfix array
		PostIndex++;						//move postindex forward
		Head1 = real;
	}
	// there are no braces in post fix expression. so, removing them (not needed here)
	for (int i = 0; PostFixArray[i] != -10; i++)
		if (PostFixArray[i] == -5 || PostFixArray[i] == -6)
			for (int j = i; PostFixArray[j] != -10; j++)
				PostFixArray[j] = PostFixArray[j + 1];
	//inserting postfix array into IntegerArray
	int i = 0;
	for (i = 0; PostFixArray[i] != -10; i++)
		IntegerArray[i] = PostFixArray[i];
	for (; IntegerArray[i] != -10; i++)
		IntegerArray[i] = -10;
}

void Calculator::PostfixSolver()
{
	int TotalOperations = 0; // (+, -, *, /)
	int TotalItems = 0;
	for (int i = 0; IntegerArray[i] != -10; i++) // sign counter
	{
		if (IntegerArray[i] == -1) // -1 for +
			TotalOperations++;
		if (IntegerArray[i] == -2) // -2 for -
			TotalOperations++;
		if (IntegerArray[i] == -3) // -3 for *
			TotalOperations++;
		if (IntegerArray[i] == -4) // -4 for /
			TotalOperations++;
		TotalItems++;
	}
	for (int a = 0; a < TotalOperations; a++) // expression main jitny signs hain utni dafa chaly ga
	{
		int search = 0; // int index for search operation
		for (int i = 0;; i++) // iterate and search the sign/operator
		{
			if (IntegerArray[i] == -1 || IntegerArray[i] == -2 || IntegerArray[i] == -3 || IntegerArray[i] == -4)
				break;
			search++;
		}
		if (IntegerArray[search] == -1) // if sign is +, add two integers before it.
		{
			IntegerArray[search - 2] = IntegerArray[search - 2] + IntegerArray[search - 1];
			search--; search--;
			for (int i = search + 1; i < TotalItems - 2; i++)
				IntegerArray[i] = IntegerArray[i + 2]; // shift the remaining array two places before // after operation, two spaces are free
		}
		else if (IntegerArray[search] == -2)// if sign is -, substract two integers before it.
		{
			IntegerArray[search - 2] = IntegerArray[search - 2] - IntegerArray[search - 1];
			search--; search--;
			for (int i = search + 1; i < TotalItems - 2; i++)// shift the remaining array two places before // after operation, two spaces are free
				IntegerArray[i] = IntegerArray[i + 2];
		}
		else if (IntegerArray[search] == -3)// if sign is *, Multiply two integers before it.
		{
			IntegerArray[search - 2] = IntegerArray[search - 2] * IntegerArray[search - 1];
			search--; search--;
			for (int i = search + 1; i < TotalItems - 2; i++)// shift the remaining array two places before // after operation, two spaces are free
				IntegerArray[i] = IntegerArray[i + 2];
		}
		else if (IntegerArray[search] == -4) // if sign is /, divide two integers before it.
		{
			if (IntegerArray[search - 1] == 0) // cannot divide by zero. (exception)
			{
				Solved = 0;
				throw exception();
			}
			IntegerArray[search - 2] = IntegerArray[search - 2] / IntegerArray[search - 1];
			search--; search--;
			for (int i = search + 1; i < TotalItems - 2; i++)// shift the remaining array two places before // after operation, two spaces are free
				IntegerArray[i] = IntegerArray[i + 2];
		}
	}
	Solved = IntegerArray[0]; // after all operations, answer = first integer of integer array.
}

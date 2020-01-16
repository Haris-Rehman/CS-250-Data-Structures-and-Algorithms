# include <iostream>
# include <string>
# include <stdexcept>
# include <sstream>
# include "header.h"
using namespace std;

int main()
{
	string myexpression;
	string *str = new string[6]; // pointer array of string to store previus expressions
	int ans[6] = { '\0' }; // array to store last answers
	int i = 0; //counter
	Calculator c1;
	while (1)
	{
		system("cls"); 
		cout << "Expression\t\t\t\tResult";
		try
		{
			if (i == 0) cout << "\n\n\n\n\n\n\n\n\n\n\n\n"; // formating
			if (i > 0)
			{
				for (int a = 1; a <= 5 - i; a++) cout << endl << endl; // expression not present
				if (i > 5)
					for (int i = 1; i <= 4; i++) // remove the oldest expression, shift elements of Queue
					{
						str[i] = str[i + 1];
						ans[i] = ans[i + 1];
					}
				if (i > 5)
					i = 5; // maintain 5 expressions to be displayed
				str[i] = myexpression; ans[i] = c1.GetSolved(); // store the latest expression
				cout << endl << endl;
				for (int j = 1; j <= i; j++) // display last 5 stored expression
				{
					cout << "\t" << str[j] << "\t\t";
					cout << ans[j] << endl << endl;
				}
			}
			cout << "\nExpression:\t";
			getline(cin, myexpression); // input expression
			c1.SetMyExp(myexpression); // set expression
			int w = c1.AllOperations(); // perform operations
			if (w == -1)
			{ // if user inters q, w = -1, quit program
				cout << endl;
				return 0;
			}
			cout << "result = " << c1.GetSolved() << endl;
		}
		catch (exception)
		{
			cout << "error\n";
		}
		i++;
	}
}

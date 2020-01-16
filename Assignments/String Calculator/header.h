# include <iostream>
# include <string>
# include <stdexcept>
# include <sstream>
using namespace std;

class Calculator
{
private:
	string MyExp;
	int charcounter; // Total number of Elements in expression
	int IntegerArray[30];
	int Solved; // Result
public:
	Calculator(); // Default constructor
	void SetMyExp(string); // set Expression
	int GetSolved(); // get result
	int AllOperations(); // Operations
	void CountCharacters(); // count characters in the string
	int Quit(); // Quit the program if Q pressed
	void StringToArrayConverter(); // convert string to array
	void InfixToPostfixConverter(); // convert infix array to postfix
	void PostfixSolver(); // solve postfix array
};

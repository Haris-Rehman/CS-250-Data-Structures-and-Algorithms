# include <iostream>
# include <ctime>
# include <stdint.h>
# include <inttypes.h>
using namespace std;

uintmax_t Factorial(uintmax_t n)
{
	for (int i = 0; i<100000; i++) cout << ""; // for some time delay
	if (n > 1)
		return n * Factorial(n - 1);
	else
		return 1;
}

int main()
{
	uintmax_t n;
	uintmax_t factorial = 1;
	cout << "Enter a positive integer: ";
	cin >> n;
	clock_t start = clock();  // start timer
	for (int i = 1; i <= n; ++i)
	{
		factorial *= i; for (int i = 0; i<100000; i++) cout << ""; // for some time delay
	}
	clock_t stop = clock();  // stop timer
	float cpu_time_used = float(stop - start) / CLOCKS_PER_SEC; //time in seconds

	clock_t star = clock();  // start timer
	uintmax_t as = Factorial(n);
	clock_t sto = clock();  // stop timer
	float cpu_time_use = float(sto - star) / CLOCKS_PER_SEC; //time in seconds
	
	cout << "\nIteration factorial = " << factorial << endl;
	cout << "time used:  " << cpu_time_used << endl;

	cout << "\nRecursion factorial = " << as << endl; // recursion
	cout << "time used:  " << cpu_time_use << endl;
	
	return 0;
}

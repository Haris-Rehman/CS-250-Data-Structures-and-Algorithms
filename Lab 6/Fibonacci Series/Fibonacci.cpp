# include <iostream>
# include <ctime>
# include <stdint.h>
# include <inttypes.h>
using namespace std;

int fibonacci(int n)
{
	if ((n == 1) || (n == 0))
	{
		return(n);
	}
	else
	{
		return(fibonacci(n - 1) + fibonacci(n - 2));
	}
}

int main()
{
	uintmax_t n, t1 = 0, t2 = 1, nextTerm = 0;

	cout << "Enter the number of terms: ";
	cin >> n;

	// Iteration
	cout << "\n\nFibonacci Series: (iteration)\n";
	clock_t start = clock();  // start timer
	uintmax_t sum = 2;
	for (int i = 1; i <= n - 2; ++i)
	{
		nextTerm = t1 + t2;
		t1 = t2;
		t2 = nextTerm;
		sum += nextTerm;
		cout << nextTerm << endl;
	}
	clock_t stop = clock();  // stop timer
	float cpu_time_used = float(stop - start) / CLOCKS_PER_SEC; //time in seconds
	// recursion
	cout << "\n\nFibonacci Series: (recursion)\n";
	clock_t star = clock();  // start timer
	uintmax_t i = 0;
	uintmax_t Sum = 1;
	while (i<n)
	{
		int as = fibonacci(i);
		i++;
		Sum += as;
		cout << as << endl;
	}
	clock_t sto = clock();  // stop timer
	float cpu_time_use = float(sto - star) / CLOCKS_PER_SEC; //time in seconds


	cout << endl << "SUM" << endl;
	cout << "\nIteration sum = " <<sum << endl;
	cout << "time used:  " << cpu_time_used << endl;
	cout << "\nRecursion sum = " << Sum << endl;
	cout << "time used:  " << cpu_time_use << endl;
	return 0;
}

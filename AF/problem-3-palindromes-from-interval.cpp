#include <iostream>

void print_other_test_cases();

bool is_palindrome(int x)
{
	if (x < 0)
	{
		return false;
	}
	int div = 1;
	while (x / div >= 10)
	{
		div *= 10;
	}
	while (x > 0)
	{
		int first_digit = x / div;
		int last_digit = x % 10;
		if (first_digit != last_digit)
		{
			return false;
		}
		x = (x % div) / 10; // deletes first and last digit abcdef -> bcde
		div /= 100;
	}
	return true;
}

void print_palindrome(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		if (is_palindrome(i))
		{
			std::cout << i << std::endl;
		}
	}
	std::cout << std::endl;
}

int main()
{
	int a, b;
	std::cout << "Please input your lower bound.\na = ";
	std::cin >> a;
	std::cout << "Please input your upper bound.\nb = ";
	std::cin >> b;

	print_palindrome(a, b);

	print_other_test_cases();

	return 0;
}

void print_other_test_cases()
{
	print_palindrome(1, 1);
	print_palindrome(10, 100);
	print_palindrome(100, 200);
	print_palindrome(0, 1000);
}
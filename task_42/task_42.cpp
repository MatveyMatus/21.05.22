#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
	int n;
	std::ifstream Value("input.txt");
	Value >> n;
	Value.close();

	long long m = pow(3,n / 3);
	if (n % 3 == 2) {
		m = m * 2;
	}
	if (n % 3 == 1) {
		m = m * 4 / 3;
		std::cout << m;
	}
	std::ofstream result("output.txt");
	result << m;
	result.close();

	return 0;
}

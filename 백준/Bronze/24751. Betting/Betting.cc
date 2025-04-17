#include <iostream>
#include <iomanip>

double a;

int main() {

	std::cin >> a;


	double ratio_option_one = 100.0 / a;
	double ratio_option_two = 100.0 / (100.0 - a);
	std::cout << std::fixed << std::setprecision(10) << ratio_option_one << std::endl;
	std::cout << std::fixed << std::setprecision(10) << ratio_option_two << std::endl;

	return 0;
}
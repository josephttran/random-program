#include <iostream>
#include <sstream>
#include <string>

struct Fraction {
	int num;
	int den;
};

int validateInt(std::string);
Fraction getFraction(std::string);
Fraction multiply(Fraction, Fraction);
Fraction add(Fraction, Fraction);
Fraction subtract(Fraction, Fraction);
Fraction divide(Fraction, Fraction);
void printFraction(const Fraction);

int main() {
	Fraction f1, f2, f3, f4, f5, f6;

	f1 = getFraction("first");
	f2 = getFraction("second");
	f3 = multiply(f1, f2);
	f4 = add(f1, f2);
	f5 = subtract(f1, f2);
	f6 = divide(f1, f2);

	std::cout << "\n\nFraction1 = ";
	printFraction(f1);

	std::cout << "\n\nFraction2 = ";
	printFraction(f2);

	std::cout << "\n\nFraction1 * Fraction2 = ";
	printFraction(f3);

	std::cout << "\n\nFraction1 + Fraction2 = ";
	printFraction(f4);

	std::cout << "\n\nFraction1 - Fraction2 = ";
	printFraction(f5);

	std::cout << "\n\nFraction1 / Fraction2 = ";
	printFraction(f6);

	std::cout << std::endl << std::endl;

	return 0;
}

int validateInt(std::string name) {
	int num;

	while (true) {
		std::cout << "\nEnter the " << name << " : ";
		std::string numStr;
		std::cin >> numStr;

		bool valid = true;
		for (unsigned int i = 0; i < numStr.length(); i++) {
			if (!isdigit(numStr[i])) {
				valid = false;
				break;
			}
		}

		if (!valid) {
			std::cout << "Error: Enter positive numbers only";
			continue;
		}

		std::stringstream sstream;
		sstream << numStr;
		sstream >> num;
		if (num < 0 || num > 40000) {
			std::cout << "Error: number entered is out of range";
			continue;
		}

		break;
	}

	return num;
}

Fraction getFraction(std::string n) {
	Fraction f;

	f.num = validateInt(n + " Numerator");
	f.den = validateInt(n + " Denominator");
	while (f.den == 0) {
		std::cout << "Error Denominator cannot be zero" << std::endl;
		f.den = validateInt("Denominator");
	}

	return f;
}

Fraction multiply(struct Fraction f1, struct Fraction f2) {
	Fraction f3;
	f3.den = f1.den * f2.den;
	f3.num = f1.num * f2.num;
	return f3;
}

Fraction add(Fraction f1, Fraction f2) {
	Fraction f3;
	f3.den = f1.den * f2.den;
	f1.num = f1.num * f2.den;
	f2.num = f2.num * f1.den;
	f3.num = f1.num + f2.num;
	return f3;
}
Fraction subtract(Fraction f1, Fraction f2) {
	Fraction f3;
	f3.den = f1.den * f2.den;
	f1.num = f1.num * f2.den;
	f2.num = f2.num * f1.den;
	f3.num = f1.num - f2.num;
	return f3;
}
Fraction divide(Fraction f1, Fraction f2) {
	Fraction f3;
	f3.den = f1.den * f2.num;
	f3.num = f1.num * f2.den;
	return f3;
}

void printFraction(const Fraction f) {
	std::cout << f.num << "/" << f.den;
}
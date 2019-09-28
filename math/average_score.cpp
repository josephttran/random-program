#include <iostream>
#include <iomanip>

double calcAverage(int score1, int score2, int score3);
int getScore(int num);
void printInfo();
void printOutput(int score1, int score2, int score3, double average);

int main() {
	printInfo();

	int score1, score2, score3;
	double average;

	score1 = getScore(1);
	score2 = getScore(2);
	score3 = getScore(3);
	average = calcAverage(score1, score2, score3);

	printOutput(score1, score2, score3, average);

	return 0;
}

double calcAverage(int score1, int score2, int score3) {
	double average;

	average = (static_cast<double>(score1) + score2 + score3) / 3;

	return average;
}

int getScore(int num) {
	int score;

	std::cout << "\nEnter Score" << num << " : ";
	std::cin >> score;

	while (std::cin.fail() || score < 0 || score > 100) {
		std::cout << "Invalid. \n\nEnter valid score : ";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> score;
	}
	return score;
}

void printInfo() {
	std::cout << "This program prompt the user to enter three Integer score\n";
	std::cout << "from three different exam within a range of 0 to 100.\n";
	std::cout << "It will them calculate the average and display it.";
	std::cout << std::endl;
}

void printOutput(int score1, int score2, int score3, double average) {
	std::cout << "Score1  : " << score1 << std::endl;
	std::cout << "Score2  : " << score2 << std::endl;
	std::cout << "Score3  : " << score3 << std::endl;
	std::cout << "Average : " << std::setprecision(2) << std::fixed << average << std::endl;
}

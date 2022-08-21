#include <iostream>
#include <string>
#include "Matrix.h"

std::vector<Matrix> matricies;

int FillMatrix () {
	int input = 0;

	std::cout << "Enter the number of Rows: ";
	std::cin >> input;
	int numRows = input;

	std::cout << "Enter the number of Columns: ";
	std::cin >> input;
	int numColumns = input;

	Matrix matrix(numRows, numColumns);
	matricies.push_back(matrix);

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numColumns; j++) {
			std::cout << "[" << i << "," << j << "] = ";
			std::cin >> input;
			matricies[matricies.size() - 1].setElement(i, j, input);
		}
	}

	return matricies.size() - 1;
}

int main() {
	std::cout << "Welcome to the Linear Algebra Calculuator" << std::endl;

	enum Operations {
		Stop,
		Fill,
		Print,
		Add,
		Scale,
		Multiply,
		AreEqual
	};

	// Initalize variables before menu
	std::string i = "0";
	std::string j = "0";
	std::string input;
	int index = 0;
	bool running = true;
	std::vector<int> vec(3,3);

	// Menu
	while (running) {
		std::cout << "Enter Command or Type \"help\": ";
		std::cin >> input;

		// Help Menu
		if (input == "help") {
			std::cout << Stop << "): Ending Program" << std::endl
					  << Fill << "): Fill Matrix" << std::endl
					  << Print << "): Print Matrix" << std::endl
					  << Add << "): Adds Two Matricies" << std::endl
					  << Scale <<"): Multiplies Matricy by scaler" << std::endl
					  << Multiply << "): Multiplies Two Matricies" << std::endl
					  << AreEqual << "): Checks If Two Matricies Are Equal" << std::endl
			          << std::endl;
		} else {
			switch (std::stoi(input)) {

				// Ends Program
			case Stop:
				std::cout << "Ending Program" << std::endl;
				running = false;
				break;

				// Prints Matrix
			case Print:
				std::cout << "Which Matrix Do You Want To Print? ";
				std::cin >> i;
				matricies[std::stoi(i)].print();
				break;

				// Fills Matrix
			case Fill:
				index = FillMatrix();
				std::cout << "Matrix " << index << ":" << std::endl;
				matricies[index].print();
				break;

				// Adds Matricies
			case Add:
				std::cout << "Which Matricies Do You Want To Add? ";
				std::cin >> i >> j;
				matricies.push_back(matricies[std::stoi(i)] += matricies[std::stoi(j)]);
				matricies[matricies.size() - 1].print();
				break;

				// Multiplies Matrix with Scaler
			case Scale:
				std::cout << "Which Matrix Do You Want To Scale? ";
				std::cin >> i;
				while (std::stoi(i) >= matricies.size()) {
					std::cout << i << " is not a valid matrix. Enter a number less then " << matricies.size() << ": ";
					std::cin >> i;
				}
				std::cout << "What is the scaler? ";
				std::cin >> j;
				std::cout << std::endl;
				matricies.push_back(matricies[std::stoi(i)] * std::stoi(j));
				matricies[matricies.size() - 1].print();
				break;

			// Multiplies Matricies
			case Multiply:
				std::cout << "Which Matricies Do You Want To Multiply? ";
				std::cin >> i >> j;
				if (matricies[std::stoi(i)].isMultipliable(matricies[std::stoi(j)])) {
					matricies.push_back(matricies[std::stoi(i)] * matricies[std::stoi(j)]);
					matricies[matricies.size() - 1].print();
				} else {
					std::cout << "lhs.numCols must equal rhs.numRows";
				}
				break;
			case AreEqual:
				std::cout << "Which Matricies Do You Want To Check? ";
				std::cin >> i >> j;
				if (matricies[std::stoi(i)] == (matricies[std::stoi(j)])) {
					std::cout << "Matrix " << i << " equals " << j << std::endl;
				} else {
					std::cout << "Matrix " << i << " does not equal " << j << std::endl;
				}
				break;
			}
		}
	}
	return 0;
}
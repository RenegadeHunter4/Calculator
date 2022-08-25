#include <iostream>
#include <string>
#include "Matrix.h"
#include "ComplexNum.h"
#include "NumberTheory.h"

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
		AreEqual,
		FindDeterminant,
		FindTranspose,
		ComplexNumTest,
		NumberTheoryTest
	};

	// Initalize variables before menu
	std::string i = "0";
	std::string j = "0";
	std::string k = "0";
	std::string input;
	int index = 0;
	bool running = true;
	std::vector<int> vec(3,3);
	ComplexNum<double> a(3, 3);
	ComplexNum<double> b(4, 4);

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
					  << FindDeterminant << "): Finds Determinate of Matrix" << std::endl
					  << FindTranspose << "): Finds Transpose of Matrix" << std::endl
					  << ComplexNumTest << "): Run Test Code for Complex Numbers Class" << std::endl
					  << NumberTheoryTest << "): Runs Test Code for Number Theory Test" << std::endl
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
				matricies.push_back(matricies[std::stoi(i)] + matricies[std::stoi(j)]);
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

				// Checks if Matricies are equal
			case AreEqual:
				std::cout << "Which Matricies Do You Want To Check? ";
				std::cin >> i >> j;
				if (matricies[std::stoi(i)] == (matricies[std::stoi(j)])) {
					std::cout << "Matrix " << i << " equals " << j << std::endl;
				} else {
					std::cout << "Matrix " << i << " does not equal " << j << std::endl;
				}
				break;

				// Finds Determinate of matrix
			case FindDeterminant:
				std::cout << "Which Matrix Do You Want To Find The Determinant Of? ";
				std::cin >> i;
				if (matricies[std::stoi(i)].isSquare()) {
					std::cout << "The Determinant of Matrix " << i << " is " << matricies[std::stoi(i)].findDeterminant() << std::endl;
				} else {
					std::cout << "Determinants are only defined for square matricies";
				}
				break;

				// Finds Transpose of Matrix
			case FindTranspose:
				std::cout << "Which Matrix Do You Want To Find The Transpose Of? ";
				std::cin >> i;
				matricies[std::stoi(i)].findTranspose().print();
				break;

				// Runs Test Code For Complex Number Class
			case ComplexNumTest:
				std::cout << "a: ";
				a.print();
				std::cout << "b: ";
				b.print();
				std::cout << "a+=b: ";
				a += b;			  
				a.print();		  
				std::cout << "a-=b: ";
				a -= b;			  
				a.print();		  
				std::cout << "a*=b: ";
				a *= b;			  
				a.print();		  
				std::cout << "a/=b: ";
				a /= b;			  
				a.print();		  
				std::cout << "a+=2: ";
				a += 2;			  
				a.print();		  
				std::cout << "a-=2: ";
				a -= 2;			  
				a.print();		  
				std::cout << "a*=2: ";
				a *= 2;			  
				a.print();		  
				std::cout << "a/=2: ";
				a /= 2;			  
				a.print();

				std::cout << "Absolute Value of a: ";
				std::cout << a.getAbsoluteValue() << std::endl;
				std::cout << "Distance Between a and b: ";
				std::cout << a.getDistance(b) << std::endl;
				std::cout << "Additive Inverse of a: ";
				a.getAdditiveInverse().print();
				std::cout << "Multiplicative Inverse of a: ";
				a.getMultiplicativeInverse().print();
				std::cout << "Conjugate of a: ";
				a.getConjugate().print();
			
				// Runs Test Code For Number Theory Class
			case NumberTheoryTest:
				std::cout << findGCD(28, 20) << std::endl;
			}
		}
	}
	return 0;
}
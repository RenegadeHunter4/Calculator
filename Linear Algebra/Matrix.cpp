#include "Matrix.h"
#include <stdexcept>

void term_func() {
	std::cout << "term_func was called by terminate." << std::endl;
	exit(-1);
}

/***********************CONSTRUCTORS**************************/
/* [Function Type] Constructor
 * [Purpose] Builds matrix based on sizeand fills entire matrix with one value.
 */
Matrix::Matrix(int n, int m, int value)
	:
	nRows(n),
	nCols(m) {
	ColVecs.insert(ColVecs.begin(), nCols, std::vector<int>(nRows, value));
	RowVecs.insert(RowVecs.begin(), nRows, std::vector<int>(nCols, value));
}

/* [Function Type] Constructor
 * [Purpose] Builds matrix based on size and fills entire matrix with zero.
 */
Matrix::Matrix(int n, int m) :
	nRows(n),
	nCols(m) {
	ColVecs.insert(ColVecs.begin(), nCols, std::vector<int>(nRows, 0));
	RowVecs.insert(RowVecs.begin(), nRows, std::vector<int>(nCols, 0));
}

/* [Function Type] Constructor
 * [Purpose] Builds matrix based on a vector of vectors.
 * [Assumes] All the Vectors in ColVecs must be the same size.
 */
Matrix::Matrix(std::vector<std::vector<int>> ColVecs) : 
	ColVecs(ColVecs) {
	nCols = ColVecs.size();
	nRows = ColVecs[0].size();

	for (int i = 0; i < nRows; i++) {
		std::vector<int> temp;
		for (int j = 0; j < nCols; j++) {
			temp.push_back(ColVecs[j][i]); // If this throws an error because vector out of range it's because you have vectors that aren't the same size in ColVecs.
		}
		RowVecs.push_back(temp);
	}
}

/* [Function Type] Constructor
 * [Purpose] Simple Copy Constructor
 */
Matrix::Matrix(const Matrix& other) : 
	nCols(other.nCols),
	nRows(other.nRows),
	ColVecs(other.ColVecs),
	RowVecs(other.RowVecs) {
}

/***********************OPERATORS**************************/
/* [Function Type] Operator Overload
 * [Purpose] Uses [] to access the ith vector. Doing matrix[i][j] will return value at a_ij because of how <vector> element access works.
 */
std::vector<int> Matrix::operator[](int i)  const {
	return RowVecs[i];
}

/* [Function Type] Operator Overload
 * [Purpose] Adds two matricies together and returns the answer as a third matrix.
 */
Matrix Matrix::operator+(const Matrix other) const {
	if(other.nCols == this->nCols && other.nRows == this->nRows) {
		std::vector<std::vector<int>> res;
		for (int i = 0; i < nCols; i++) {
			std::vector<int> colVec;
			for (int j = 0; j < nRows; j++) {
				colVec.push_back(this->ColVecs[i][j] + other.ColVecs[i][j]);
			}
			res.push_back(colVec);
		}
		return Matrix(res);
	}
}

/* [Function Type] Operator Overload
 * [Purpose] Multiplies each element of a matrix by a scaler and then returns the matrix.
 */
Matrix Matrix::operator*(int scaler) const {
	std::vector<std::vector<int>> res;
	for (int i = 0; i < nCols; i++) {
		std::vector<int> colVec;
		for (int j = 0; j < nRows; j++) {
			colVec.push_back(this->ColVecs[i][j] * scaler);
		}
		res.push_back(colVec);
	}

	return Matrix(res);
}

/* [Function Type] Operator Overload
 * [Purpose] Multiplies two matricies together using normal matrix multiplication. Returns a 0 matrix if the matricies weren't multipliable
 */
Matrix Matrix::operator*(Matrix rhs) const {
	Matrix res(this->nRows, rhs.nCols);
	if (this->isMultipliable(rhs)) {
		for (int i = 0; i < this->nRows; i++) {
			for (int j = 0; j < rhs.nCols; j++) {
				int sum = 0;
				for (int k = 0; k < this->nCols; k++) {
					sum += this->RowVecs[i][k] * rhs.ColVecs[j][k];
				}
				res.setElement(i, j, sum);
			}
		}	
	} 
	return res;
}

/* [Function Type] Operator Overload
 * [Purpose] Subtracts two matricies and returns the answer as a third matrix.
 */
Matrix Matrix::operator-(Matrix other) const {
	if (other.nCols == this->nCols && other.nRows == this->nRows) {
		std::vector<std::vector<int>> res;
		for (int i = 0; i < nCols; i++) {
			std::vector<int> colVec;
			for (int j = 0; j < nRows; j++) {
				colVec.push_back(this->ColVecs[i][j] - other.ColVecs[i][j]);
			}
			res.push_back(colVec);
		}
		return Matrix(res);
	}
}

/***********************GETTERS & SETTERS**************************/
/* [Function Type] Setter
 * [Purpose] Sets the Element at row row and col col, to value.
 */
void Matrix::setElement(int row, int col, int value) {
	if (row < nRows && col < nCols) {
		std::vector<int> temp = RowVecs[row];		   // Copies Matrix Column i to temp
		temp.erase(temp.begin() + col);
		temp.insert(temp.begin() + col, value);	   // Sets the jth position of temp to value
		RowVecs.erase(RowVecs.begin() + row);		   // Sets the ith position of matrix to temp
		RowVecs.insert(RowVecs.begin() + row, temp);

		// Does the same thing for Colvecs
		temp = ColVecs[col];		   
		temp.erase(temp.begin() + row);
		temp.insert(temp.begin() + row, value);	   
		ColVecs.erase(ColVecs.begin() + col);		   
		ColVecs.insert(ColVecs.begin() + col, temp);
	}
	
}

/*[Function Type] Setter
* [Purpose] Adds row "row" to the end of the matrix.
*/
void Matrix::pushBackRow(std::vector<int> row) {
	RowVecs.push_back(row);

	for (int i = 0; i < nCols; i++) {
		ColVecs[i].push_back(row[i]);
	}
	nRows++;
}

/*[Function Type] Setter
* [Purpose] Adds column "column" to the end of the matrix.
*/
void Matrix::pushBackColumn(std::vector<int> column) {
	ColVecs.push_back(column);

	for (int i = 0; i < nRows; i++) {
		RowVecs[i].push_back(column[i]);
	}
	nCols++;
}

/*[Function Type] Setter
* [Purpose] Adds row "row" to the pos position in the matrix.
*/
void Matrix::insertRow(int pos, std::vector<int> row) {
	RowVecs.insert(RowVecs.begin() + pos, row);

	for (int i = 0; i < nCols; i++) {
		ColVecs[i].insert(ColVecs[i].begin() + pos, row[i]);
	}
	nRows++;
}

/*[Function Type] Setter
* [Purpose] Adds column "column" to the pos position in the matrix.
*/
void Matrix::insertColumn(int pos, std::vector<int> column) {
	ColVecs.insert(ColVecs.begin() + pos, column);

	for (int i = 0; i < nRows; i++) {
		RowVecs[i].insert(RowVecs[i].begin() + pos, column[i]);
	}
	nCols++;
}

/*[Function Type] Setter
* [Purpose] erases the row at "pos" index in the matrix.
*/
void Matrix::eraseRow(int pos) {
	RowVecs.erase(RowVecs.begin() + pos);

	for (int i = 0; i < nCols; i++) {
		ColVecs[i].erase(ColVecs[i].begin() + pos);
	}
	nRows--;
}

/*[Function Type] Setter
* [Purpose] erases the column at "pos" index in the matrix.
*/
void Matrix::eraseColumn(int pos) {
	ColVecs.erase(ColVecs.begin() + pos);

	for (int i = 0; i < nRows; i++) {
		RowVecs[i].erase(RowVecs[i].begin() + pos);
	}
	nCols--;
}

/*[Function Type] Getter
* [Purpose] Sets the Element at row rowand col col, to value.
*/
std::vector<int> Matrix::getRow(int pos) const {
	return RowVecs[pos];
}

/*[Function Type] Getter
* [Purpose] Sets the Element at row rowand col col, to value.
*/
std::vector<int> Matrix::getColumn(int pos) const {
	return ColVecs[pos];
}

/*[Function Type] Getter
* [Purpose] Sets the Element at row rowand col col, to value.
*/
int Matrix::getNumColumns() const {
	return nCols;
}

/*[Function Type] Getter
* [Purpose] Sets the Element at row rowand col col, to value.
*/
int Matrix::getNumRows() const {
	return nRows;
}

/************************HELPER MATH***************************/

/*[Function Type] Helpper Math
* [Purpose] Returns rather this matrix can be multiplied with the other on it's lhs. [this * other] not [other * this].
*/
bool Matrix::isMultipliable(const Matrix& other) const {
	return this->nCols == other.nRows;
}

/***********************MISC UTILITY**************************/
/* [Function Type] Misc. Utility
 * [Purpose] Prints Matrix to Console
 */
void Matrix::print() const {
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			std::cout << RowVecs[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
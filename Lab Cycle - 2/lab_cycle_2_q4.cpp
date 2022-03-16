/*Write a C++ program for developing a matrix class which can handle integer
matrices of different dimensions. Also overload the operator for addition and
multiplication of matrices. Use double pointers in your program to dynamically
allocate memory for the matrices.*/

#include <iostream>
using namespace std;

class Matrix{
	int rows,coloumns;
	int **matrix;
public:
	//function to get the no of rows and coloumns to dynamically allocate memory
	void getRowsandColoumns(){
		cout<<"Enter the no of rows and coloumns"<<endl;
		cin>>rows>>coloumns;
	}
	void allocateMatrix();
	void getMatrix();
	void displayMatrix();
	//destructor used to delete the dynamically allocated memory
	~Matrix(){
		for (int i = 0; i < rows; ++i) {
			delete matrix[i];
		}
		cout<<"Memory Deleted"<<endl;
		delete matrix;
	}
};

//function used to allocated dynamic memory to the matrix
void Matrix::allocateMatrix(){
	matrix = new int *[rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int [coloumns];
	}
}

//function to get values to the matrix.
void Matrix::getMatrix(){
	cout<<"Enter the Values"<<endl;
	for (int i = 0; i < rows; ++i) {
		cout<<"Row - "<<i+1<<endl;
		for (int j = 0; j < coloumns; ++j) {
			cin>>matrix[i][j];
		}
	}
}

//function to display the matrix entered.
void Matrix::displayMatrix(){
	cout<<"The Matrix you have entered is "<<rows<<"x"<<coloumns<<endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < coloumns; ++j) {
			cout<<matrix[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

int main() {
	Matrix matrix1;
	matrix1.getRowsandColoumns();
	matrix1.allocateMatrix();
	matrix1.getMatrix();
	matrix1.displayMatrix();
	return 0;
}

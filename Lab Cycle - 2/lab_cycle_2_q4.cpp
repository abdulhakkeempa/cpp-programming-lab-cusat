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
	Matrix(){}
	Matrix(int r,int c){
		rows=r;
		coloumns=c;
		matrix = new int *[rows];
		for (int i = 0; i < rows; ++i) {
			matrix[i] = new int [coloumns];
		}
	}
	//function to get the no of rows and coloumns to dynamically allocate memory
	void getRowsandColoumns(){
		cout<<"Enter the no of rows and coloumns"<<endl;
		cin>>rows>>coloumns;
	}
	void allocateMatrix();
	void getMatrix();
	void displayMatrix();
	void operator+(const Matrix&);
	void operator*(const Matrix&);
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
	cout<<"The Matrix is of dimension "<<rows<<"x"<<coloumns<<endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < coloumns; ++j) {
			cout<<matrix[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
//overloading + operator for matrix addition
void Matrix::operator+(const Matrix&a){
	if(rows==a.rows and coloumns==a.coloumns){
		Matrix sum(rows,coloumns);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < coloumns; ++j) {
				sum.matrix[i][j]=matrix[i][j]+a.matrix[i][j];
			}
		}
		sum.displayMatrix();
	}
	else{
		cout<<"Addition not possible"<<endl;
	}
}
//overloading * operator for matrix addition
void Matrix::operator *(const Matrix&a){
	if (coloumns==a.rows) {
		Matrix productMatrix(rows,a.coloumns);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < a.coloumns; ++j) {
				int sum=0;
				for (int k = 0; k < coloumns; ++k) {
					sum = matrix[i][k]*a.matrix[k][j]+sum;
					productMatrix.matrix[i][j] = sum;
				}
			}
		}
		productMatrix.displayMatrix();
	} else {
		cout<<"Multiplication not possible"<<endl;
	}
}
int main() {
	int quitOption,exitLoop;
	cout<<"Welcome\n1.Start\n2.Quit"<<endl;
	cin>>quitOption;
	if (quitOption==1) {
		Matrix matrix1;
		cout<<"Matrix - 1"<<endl;
		matrix1.getRowsandColoumns();
		matrix1.allocateMatrix();
		matrix1.getMatrix();

		Matrix matrix2;
		cout<<"Matrix - 2"<<endl;
		matrix2.getRowsandColoumns();
		matrix2.allocateMatrix();
		matrix2.getMatrix();

		cout<<endl;
		cout<<"Matrix - 1"<<endl;
		matrix1.displayMatrix();
		cout<<endl;
		cout<<"Matrix - 2"<<endl;
		matrix2.displayMatrix();

		do {
			int option;
			cout<<"\n1.Matrix 1 + Matrix 2\n2.Matrix 1 x Matrix2"<<endl;
			cin>>option;
			switch (option) {
				case 1:
					matrix1+matrix2;
					break;
				case 2:
					matrix1*matrix2;
					break;
				default:
					break;
			}
			cout<<"\n1.Continue\n2.Quit"<<endl;
			cin>>exitLoop;
		} while (exitLoop==1);

	} else {
		cout<<"Successfully Quitted"<<endl;
		return 0;
	}
	return 0;
}

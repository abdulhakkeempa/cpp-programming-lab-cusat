#include <iostream>
using namespace std;

class matrices{
	int rows,coloumns;
	int matrix[10][10];
public:
	matrices(){};
	void get_matrix();
	friend void matrix_add(matrices,matrices);
	friend void matrix_mult(matrices,matrices);
	void matrix_transpose();
	void matrix_trace();
};

void matrices::get_matrix(){
	cout<<"Enter the No of Rows and Coloumns"<<endl;
	cin>>rows>>coloumns;

	for (int i = 0; i < rows; ++i) {
		cout<<"Enter elements of "<<i+1<<" row"<<endl;
		for (int j = 0; j < coloumns; ++j) {
			cin>>matrix[i][j];
		}
	}
}
void matrix_add(matrices a,matrices b){
	if(a.rows==b.rows and a.coloumns==b.coloumns){
		int sum[a.rows][a.coloumns];
		for (int i = 0; i < a.rows; ++i) {
			for (int j = 0; j < a.coloumns; ++j) {
				sum[i][j]=a.matrix[i][j]+b.matrix[i][j];
			}
		}
		for (int i = 0; i < a.rows; ++i) {
			for (int j = 0; j < b.coloumns; ++j) {
				cout<<sum[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	else{
		cout<<"Addition not possible"<<endl;
	}

}

void matrices::matrix_transpose(){
	int transpose[coloumns][rows];
	//to take the transpose
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < coloumns; ++j) {
			transpose[j][i] = matrix[i][j];
		}
	}
	//to display the transpose
	cout<<"Transpose of the Matrix"<<endl;
	for (int i = 0; i < coloumns; ++i) {
		for (int j = 0; j < rows; ++j) {
			cout<<transpose[i][j]<<"\t";
		}
		cout<<"\n";
	}

}

void matrix_mult(matrices a,matrices b){
	if (a.coloumns==b.rows) {
		int mult[a.rows][b.coloumns];
		if(a.coloumns==b.rows){
			for (int i = 0; i < a.rows; ++i) {
				for (int j = 0; j < b.coloumns; ++j) {
					int sum = 0;
					for (int k = 0; k < a.coloumns; ++k) {
						sum = sum + a.matrix[i][k]*b.matrix[k][j];
						mult[i][j]=sum;
					}
				}
			}
			//printing result
			cout<<"The Result is"<<endl;
			for (int i = 0; i < a.rows; ++i) {
				for (int j = 0; j < b.coloumns; ++j) {
					cout<<mult[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
	} else {
		cout<<"For Matrix Multiplication , no of coloumns of first matrix should be equal to\n no of rows of second matrix";
	}

}

void matrices::matrix_trace(){
	if (rows !=coloumns){
		cout<<"Trace is possible for square matrix";
	}
	else{
	int trace = 0;
	for (int i = 0; i < rows; ++i) {
			trace = trace + matrix[i][i];
		}
	cout<<"The Trace of the Matrix is "<<trace;

	}
}
int main() {
	int choice;
	matrices matrix1,matrix2;
	cout<<"Main Menu"<<endl;
	cout<<"Welcome , select the operation you want to perform"<<endl;
	cout<<"1 for Addition of Matrix\n2 for Transpose of Matrix\n3 for Matrix Multiplication\n4 for Trace of Matrix"<<endl;
	cin>>choice;
	switch (choice) {
		case 1:
			matrix1.get_matrix();
			matrix2.get_matrix();
			matrix_add(matrix1, matrix2);
			break;
		case 2:
			matrix1.get_matrix();
			matrix1.matrix_transpose();
			break;
		case 3:
			matrix1.get_matrix();
			matrix2.get_matrix();
			matrix_mult(matrix1, matrix2);
			break;
		case 4:
			matrix1.get_matrix();
			matrix1.matrix_trace();
			break;
		default:
			cout<<"Invalid Choice";
			break;
	}
	return 0;
}

#include <iostream>
using namespace std;

class matrices{
	int rows,coloumns;
	int **matrix;
public:
	matrices(int r,int c){
		rows = r;
		coloumns = c;
		matrix = new int *[rows];
		for (int i = 0; i < rows; ++i) {
			matrix[i]= new int [coloumns];
		}
	}
	~matrices(){
		for (int i = 0; i < rows; ++i) {
			delete matrix[i];
		}
		delete matrix;
		cout<<"Memory Released"<<endl;
	}
	matrices(){};
	void get_matrix();
	friend void matrix_add(matrices&,matrices&);
	friend void matrix_mult(matrices&,matrices&);
	void matrix_transpose();
	void matrix_trace();
};

void matrices::get_matrix(){
	for (int i = 0; i < rows; ++i) {
		cout<<"Enter elements of "<<i+1<<" row"<<endl;
		for (int j = 0; j < coloumns; ++j) {
			cin>>matrix[i][j];
		}
	}
}
void matrix_add(matrices &a,matrices &b){
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

void matrix_mult(matrices &a,matrices &b){
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
		cout<<"For Matrix Multiplication , no of coloumns of first matrix should be equal to no of rows of second matrix"<<endl;
	}

}

void matrices::matrix_trace(){
	if (rows !=coloumns){
		cout<<"Trace is possible for square matrix"<<endl;
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
	int choice,m,n,opt,exit_option;
	cout<<"Enter the size of the First Matrix"<<endl;
	cin>>m>>n;
	matrices matrix1(m,n);
	matrix1.get_matrix();
	cout<<"Enter the size of the Second Matrix"<<endl;
	cin>>m>>n;
	matrices matrix2(m,n);
	matrix2.get_matrix();
	do {
		cout<<"Main Menu"<<endl;
		cout<<"Welcome , select the operation you want to perform"<<endl;
		cout<<"1.Addition of Matrix\n2.Transpose of Matrix\n3.Matrix Multiplication\n4.Trace of Matrix"<<endl;
		cin>>choice;
		switch (choice) {
			case 1:
				matrix_add(matrix1, matrix2);
				cout << "breaking...";
				break;
			case 2:
				cout<<"Choose the option\n1.Transpose of First Matrix\n2.Transpose of Second Matrix"<<endl;
				cin>>opt;
				if(opt == 1){
					matrix1.matrix_transpose();
				}
				else {
					matrix2.matrix_transpose();
				}
				break;
			case 3:
				matrix_mult(matrix1, matrix2);
				
				break;
			case 4:
				cout<<"Choose the option\n1.Trace of First Matrix\n2.Trace of Second Matrix"<<endl;
				cin>>opt;
				if(opt == 1){
					matrix1.matrix_trace();
				}
				else {
					matrix2.matrix_trace();
				}
				break;
			default:
				cout<<"Invalid Choice";
				break;
		}
		cout<<"Do you want to continue?\n1.Continue\n2.Exit"<<endl;
		cin>>exit_option;
	} while (exit_option==1);
	if (exit_option!=1){
		cout<<"Succesfully Exited"<<endl;
	}
	return 0;
}

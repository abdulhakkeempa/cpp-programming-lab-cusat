/*Write a C++ program to design a class representing complex numbers and
having the functionality of performing addition & multiplication of two complex
numbers using operator overloading (Use friend operator functions).*/

#include <iostream>
using namespace std;

class Complex{
	float real,image;
public:
	void getComplex();
	void displayComplex();
	friend Complex operator+(const Complex&,const Complex&);
	friend Complex operator*(const Complex&,const Complex&);
};
//member function to get the complex number.
void Complex::getComplex(){
	cout<<"Enter the real part"<<endl;
	cin>>real;
	cout<<"Enter the image part"<<endl;
	cin>>image;
}
//member function to display the complex number.
void Complex::displayComplex(){
	if (image<0) {
		cout<<real<<" "<<image<<"i"<<endl;
	} else {
		cout<<real<<" + "<<image<<"i"<<endl;
	}
}
//friend function to overload + for complex addition
Complex operator+(const Complex &A,const Complex &B){
	Complex Sum;
	Sum.real = A.real+B.real;
	Sum.image = A.image+B.image;
	return Sum;
}
//friend function to overload * for complex multiplication
Complex operator*(const Complex &A,const Complex &B){
	Complex Product;
	Product.real = (A.real*B.real)-(A.image*B.image);
	Product.image = (A.image*B.real) + (A.real*B.image);
	return Product;
}
int main() {
	int quit;
	cout<<"Welcome\n1.Start\n2.Quit"<<endl;
	cin>>quit;

	if (quit==2) {
		cout<<"You have successfully quitted"<<endl;
		return 0;
	}
	int choice,choice2;
	Complex complex1,complex2,Sum,Product;
	cout<<"Complex Number - 1"<<endl;
	complex1.getComplex();
	cout<<"Complex Number - 2"<<endl;
	complex2.getComplex();
	cout<<"Complex Number 1 = ";
	complex1.displayComplex();
	cout<<"Complex Number 2 = ";
	complex2.displayComplex();
	do {
		cout<<"Choose the operation you want to perform\n1.Complex Addition\n2.Complex Multiplication"<<endl;
		cin>>choice;
		switch (choice) {
			case 1:
				Sum = complex1+complex2;
				cout<<"Sum = ";
				Sum.displayComplex();
				break;
			case 2:
				Product = complex1*complex2;
				cout<<"Product = ";
				Product.displayComplex();
				break;
			default:
				break;
		}
		cout<<"Do you want to continue ? \n1.Continue\n2.Quit"<<endl;
		cin>>choice2;
	} while (choice2 == 1);
	if(choice2!=1){
		cout<<"Successfully Quitted!"<<endl;
	}
	return 0;
}

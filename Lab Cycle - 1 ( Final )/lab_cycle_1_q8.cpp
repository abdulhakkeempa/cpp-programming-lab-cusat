#include <iostream>
using namespace std;

class complex{
	float real,image;
public:
	complex(){}
	complex(float a){
		real=image=a;
	}
	complex(float x,float y){
	real=x;
	image=y;
	}
	friend complex sum(complex,complex);
	friend void display(complex);
};

complex sum(complex A,complex B){
	complex result;
	result.real=A.real+B.real;
	result.image=A.image+B.image;
	return result;
}

void display(complex number){
	if (number.image<0) {
		cout<<number.real<<" "<<number.image<<"i"<<endl;
	} else {
		cout<<number.real<<" + "<<number.image<<"i"<<endl;
	}
}
int main() {
	float num1,num2;
	cout<<"Enter the the different real and image part\n";
	cin>>num1>>num2;
	complex A(num1,num2);
	cout<<"A = ";
	display(A);
	float num3;
	cout<<"Enter the same real and image part"<<endl;
	cin>>num3;
	complex B(num3);
	cout<<"B = ";
	display(B);
	complex C;
	C=sum(A,B);
	cout<<"Sum = ";
	display(C);
	return 0;
}

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
	result.real=A.real+B.image;
	result.image=A.real+B.image;
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
	complex A(2.8,3.9);
	cout<<"A = ";
	display(A);
	complex B(-4.4);
	cout<<"B = ";
	display(B);
	complex C;
	C=sum(A,B);
	cout<<"Sum = ";
	display(C);
	return 0;
}


#include <iostream>
using namespace std;

class complex{
	int real,image;
public:
	void getvalue();
	complex friend sum(complex,complex);
	void display();

};
	void complex::getvalue(){
		cout<<"Enter the Real Part ";
		cin>>real;
		cout<<"Enter the Image Part ";
		cin>>image;
	}

	void complex::display(){
		if (image<0) {
			cout<<real<<image<<"i"<<endl;
		} else {
			cout<<real<<"+"<<image<<"i"<<endl;
		}
	}


	complex sum(complex a,complex b){
		complex result;
		result.real=a.real+b.real;
		result.image=a.image+b.image;
		return result;
	}

int main() {
	int exitOption;
	cout<<"1.Start\n2.Quit"<<endl;
	cin>>exitOption;
	if (exitOption==2) {
		return 0;
	}
	complex a,b,result;
	cout<<"Complex 1"<<endl;
	a.getvalue();
	cout<<"Complex 2"<<endl;
	b.getvalue();
	cout<<"\nComplex 1 : ";
	a.display();
	cout<<"Complex 2 : ";
	b.display();
	result=sum(a, b);
	cout<<"Result 	  : ";
	result.display();
	return 0;
}

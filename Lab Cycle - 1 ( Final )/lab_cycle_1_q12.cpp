
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
	complex a,b,result;
	a.getvalue();
	a.display();
	b.getvalue();
	b.display();
	result=sum(a, b);
	result.display();
	return 0;
}

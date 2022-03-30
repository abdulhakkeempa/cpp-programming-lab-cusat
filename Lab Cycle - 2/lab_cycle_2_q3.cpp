/*Write a C++ program to overload operators like *, <<, >> using friend
function. The following overloaded operators should work for a class vector.*/

#include <iostream>
using namespace std;

class Vector{
	float iComponent,jComponent,kComponent;
public:
	void operator*(const Vector&);
	friend ostream & operator<<(ostream&,Vector&);
	friend istream & operator>>(istream&,Vector&);

};

//overloading >> operator to input the vector.
istream & operator>>(istream&din,Vector&a){
	cout<<"Enter the component of i"<<endl;
	cin>>a.iComponent;
	cout<<"Enter the component of j"<<endl;
	cin>>a.jComponent;
	cout<<"Enter the component of k"<<endl;
	cin>>a.kComponent;
	return (din);
}

//overloading << operator to input the vector.
ostream & operator<<(ostream&dout,Vector&a){
	if (a.jComponent>0 and a.kComponent>0) {
		dout<<a.iComponent<<"i + "<<a.jComponent<<"j + "<<a.kComponent<<"k"<<endl;
	}
	else {
		if(a.jComponent<0 and a.kComponent<0){
			dout<<a.iComponent<<"i "<<a.jComponent<<"j "<<a.kComponent<<"k"<<endl;
		}
		else if(a.jComponent<0){
			dout<<a.iComponent<<"i "<<a.jComponent<<"j + "<<a.kComponent<<"k"<<endl;
		}
		else {
			dout<<a.iComponent<<"i + "<<a.jComponent<<"j "<<a.kComponent<<"k"<<endl;
		}
	}
	return dout;
}

//overloading * operator to find the dot product.
void Vector::operator*(const Vector&a){
	float dotProduct;
	dotProduct = (iComponent*a.iComponent)+(jComponent*a.jComponent)+(kComponent*a.kComponent);
	cout<<"Dot Product : "<<dotProduct<<endl;
}

int main() {
	int exitOption,loopOption;
	cout<<"Welcome \n1.Start\n2.Quit"<<endl;
	cin>>exitOption;
	if (exitOption==1) {
		do {
			cout<<"Vector - 1"<<endl;
			Vector vector1;
			cin>>vector1;
			cout<<"Vector - 2"<<endl;
			Vector vector2;
			cin>>vector2;
			cout<<"Vector 1 : "<<vector1;
			cout<<"Vector 2 : "<<vector2;
			int choice;
			cout<<"1.Dot Product of Vector 1 and Vector 2\n2.Quit"<<endl;
			cin>>choice;
			if(choice==1){
				vector1*vector2;
				cout<<"Do you want to continue ?\n1.Continue\n2.Quit"<<endl;
				cin>>loopOption;
			}
			else{
				return 0;
			}
		} while (loopOption==1);
	}
	else {
		return 0;
	}
	return 0;
}

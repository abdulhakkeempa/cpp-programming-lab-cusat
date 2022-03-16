/*Write a C++ program to overload operators like *, <<, >> using friend
function. The following overloaded operators should work for a class vector.*/

#include <iostream>
using namespace std;

class Vector{
	int iComponent,jComponent,kComponent;
public:
	void getVector();
	void displayVector();
	Vector operator*(const Vector &a);
	void operator<<(const Vector &a);
	void operator>>(const Vector &a);

};
//member function to get the components of the vector.
void Vector::getVector(){
	cout<<"Enter the component of i"<<endl;
	cin>>iComponent;
	cout<<"Enter the component of j"<<endl;
	cin>>jComponent;
	cout<<"Enter the component of k"<<endl;
	cin>>kComponent;
}
//member function to display the vector entered.
void Vector::displayVector(){
	if (jComponent>=0 and kComponent>=0) {
		cout<<iComponent<<"i + "<<jComponent<<"j + "<<kComponent<<"k"<<endl;
	}
	else {
		if(jComponent<0 and kComponent<0){
			cout<<iComponent<<"i "<<jComponent<<"j "<<kComponent<<"k"<<endl;
		}
		else if(jComponent<0){
			cout<<iComponent<<"i "<<jComponent<<"j + "<<kComponent<<"k"<<endl;
		}
		else {
			cout<<iComponent<<"i + "<<jComponent<<"j "<<kComponent<<"k"<<endl;
		}
	}
}


int main() {

	return 0;
}

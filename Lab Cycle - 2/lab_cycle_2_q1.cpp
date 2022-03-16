#include <iostream>
#include <cmath>
using namespace std;

class Vector{
	float i_Component,j_Component,k_Component,magnitude;
public:
	void getVector();
	void displayVector();
	void FindMagnitude();
	void operator==(const Vector&);
	void operator!=(const Vector&);
	void operator<(const Vector&);
	void operator<=(const Vector&);
	void operator>(const Vector&);
	void operator>=(const Vector&);
};

//member function to get the components of the vector.
void Vector::getVector(){
	cout<<"Enter the component of i"<<endl;
	cin>>i_Component;
	cout<<"Enter the component of j"<<endl;
	cin>>j_Component;
	cout<<"Enter the component of k"<<endl;
	cin>>k_Component;
}

//member function to display the vector entered.
void Vector::displayVector(){
	if (j_Component>=0 and k_Component>=0) {
		cout<<i_Component<<"i + "<<j_Component<<"j + "<<k_Component<<"k"<<endl;
	}
	else {
		if(j_Component<0 and k_Component<0){
			cout<<i_Component<<"i "<<j_Component<<"j "<<k_Component<<"k"<<endl;
		}
		else if(j_Component<0){
			cout<<i_Component<<"i "<<j_Component<<"j + "<<k_Component<<"k"<<endl;
		}
		else {
			cout<<i_Component<<"i + "<<j_Component<<"j "<<k_Component<<"k"<<endl;
		}
	}
}

//member function to compute the magnitude of the vector
void Vector::FindMagnitude(){
	magnitude = (i_Component*i_Component)+(j_Component*j_Component)+(k_Component*k_Component);
	magnitude = sqrtf(magnitude);
	//cout<<"Magnitude is"<<magnitude<<endl;
}

//member function to overload == operator for vector
void Vector::operator==(const Vector &A){
	if (magnitude == A.magnitude){
		cout<<"They are equal vectors"<<endl;
	}
	else {
		cout<<"They are unequal vectors"<<endl;
	}
}
//member function to overload != operator for vector
void Vector::operator!=(const Vector &A){
	if (magnitude != A.magnitude){
		cout<<"They are unequal vectors"<<endl;
	}
	else {
		cout<<"They are equal vectors"<<endl;
	}
}
//member function to overload < operator for vector
void Vector::operator<(const Vector &A){
	if (magnitude < A.magnitude) {
		cout<<"Vector 2 is greater than Vector 1"<<endl;
	}
	else {
		cout<<"Vector 1 is greater than Vector 2"<<endl;
	}
}
//member function to overload <= operator for vector
void Vector::operator<=(const Vector &A){
	if (magnitude < A.magnitude) {
		cout<<"Vector 2 is greater than Vector 1"<<endl;
	}
	else if(magnitude == A.magnitude){
		cout<<"They are equal vectors"<<endl;
	}
	else {
		cout<<"Vector 1 is greater than Vector 2"<<endl;
	}
}
//member function to overload > operator for vector
void Vector::operator>(const Vector &A){
	if (magnitude > A.magnitude) {
		cout<<"Vector 1 is greater than Vector 2"<<endl;
	}
	else {
		cout<<"Vector 2 is greater than Vector 1"<<endl;
	}
}
//member function to overload >= operator for vector
void Vector::operator>=(const Vector &A){
	if (magnitude > A.magnitude) {
		cout<<"Vector 1 is greater than Vector 2"<<endl;
	}
	else if(magnitude == A.magnitude){
		cout<<"They are equal vectors"<<endl;
	}
	else {
		cout<<"Vector 2 is greater than Vector 1"<<endl;
	}
}

int main() {
	int option;
	cout<<"Welcome\n1.Input Vectors\n2.Quit"<<endl;
	cin>>option;

	if (option==2) {
		cout<<"You have successfully quited"<<endl;
		return 0;
	}

	Vector V1,V2;
	int choice,choice2;
	cout<<"Vector 1"<<endl;
	V1.getVector();
	cout<<"\nVector 2"<<endl;
	V2.getVector();
	cout<<"Vector 1 = ";
	V1.displayVector();
	cout<<"Vector 2 = ";
	V2.displayVector();
	V1.FindMagnitude();
	V2.FindMagnitude();

	do {
		cout<<"\nChoose the operation you want to perform on the vector \n1.==\n2.!=\n3.<\n4.<=\n5.>\n6.>=\n7.Quit"<<endl;
		cin>>choice;
		switch (choice) {
			case 1:
				V1== V2;
				break;
			case 2:
				V1!= V2;
				break;
			case 3:
				V1< V2;
				break;
			case 4:
				V1<= V2;
				break;
			case 5:
				V1> V2;
				break;
			case 6:
				V1>= V2;
				break;
			default:
				break;
		}
		cout<<"Do you want to Continue ?\n1.Continue\n2.Quit"<<endl;
		cin>>choice2;
	} while (choice2 == 1);
	if(choice2!=1){
		cout<<"Successfully Quitted!"<<endl;
	}
	return 0;
}

/*Write a C++ program illustrating how the constructors are implemented and the
order in which they are called when the classes are inherited. Use three classes
named alpha, beta and gamma such that alpha and beta are base classes and
gamma is a derived class inheriting alpha & beta. */

#include <iostream>
using namespace std;

//base class - alpha.
class alpha{
protected:
	int numAlpha;
public:
	//default constructor of alpha.
	alpha(){
		cout<<"Default Constructor of Base Class - Alpha"<<endl;
	}
	//parameterized constructor of alpha.
	alpha(int a){
		numAlpha = a;
		cout<<"Alpha initialized"<<endl;
	}
	//function to display the value of alpha.
	void displayAlpha(){
		cout<<"Alpha : "<<numAlpha<<endl;
	}

};
//base class - beta.
class beta{
protected:
	int numBeta;
public:
	//default constructor of beta.
	beta(){
		cout<<"Default Constructor of Base Class - Beta"<<endl;
	}
	//parameterized constructor of beta.
	beta(int y){
		numBeta = y;
		cout<<"Beta initialized"<<endl;
	}
	//function to display the value of beta.
	void displayBeta(){
		cout<<"Beta : "<<numBeta<<endl;
	}
};

//derived class gamma from alpha and beta
class gamma:public alpha,public beta{
	int numGamma;
public:
	//default constructor of gamma.
	gamma(){
		cout<<"Default Constructor of Derived Class - Gamma"<<endl;
	}
	//parameterized constructor of gamma which passes arguments to base class.
	gamma(int x,int y,int z):alpha(x),beta(y){
		numGamma = z;
		cout<<"Gamma initialized"<<endl;
	}
	//function to display the value of gamma.
	void displayGamma(){
		cout<<"Gamma : "<<numGamma<<endl;
	}
};

int main() {
	int choice,Alpha,Beta,Gamma,loopOption;
	cout<<"In this program, two base classes 'Alpha' and 'Beta' is inherited by class Gamma"<<endl;
	do {
		cout<<"1.Create Object for Gamma which does not take any arguments\n2.Create Object for Gamma with arguments for all the classes\n3.Quit"<<endl;
		cin>>choice;
		if(choice == 1){
			//object for gamma which invokes the default constructor.
			gamma obj1;
			cout<<endl;
			cout<<"Even if there are no arguments passed, the default constructor of the base classes are called\nin the order they are inherited"<<endl;
		}
		else if (choice==2){
			cout<<"Give the input for alpha : ";
			cin>>Alpha;
			cout<<"Give the input for beta : ";
			cin>>Beta;
			cout<<"Give the input for gamma : ";
			cin>>Gamma;
			cout<<endl;
			//object for gamma which invokes the parameterized constructor.
			gamma obj2(Alpha,Beta,Gamma);
			cout<<endl;
			obj2.displayAlpha();
			obj2.displayBeta();
			obj2.displayGamma();
			cout<<endl;
			cout<<"Even though , if the object is created for a derived class as the base classes are inherited\ntheir constructor are called in the order in which they are inherited";
		}
		cout<<"Do you want to continue?\n1.Continue\n2.Quit"<<endl;
		cin>>loopOption;
	} while (loopOption==1);
		return 0;
}

/*Write a C++ program illustrating how the constructors are implemented and the
order in which they are called when the classes are inherited. Use three classes
named alpha, beta and gamma such that alpha and beta are base classes and
gamma is a derived class inheriting alpha & beta. */

#include <iostream>
using namespace std;

class alpha{
protected:
	int numAlpha;
public:
	alpha(){
		cout<<"Default Constructor of Base Class - Alpha"<<endl;
	}
	alpha(int a){
		numAlpha = a;
		cout<<"Parameterized Constructor for Base Class Alpha and Alpha initialized"<<endl;
	}
	void displayAlpha(){
		cout<<"Alpha : "<<numAlpha<<endl;
	}

};

class beta{
protected:
	int numBeta;
public:
	beta(){
		cout<<"Default Constructor Base Class - of Beta"<<endl;
	}
	beta(int y){
		numBeta = y;
		cout<<"Parameterized Constructor for Base Class Beta and Beta initialized"<<endl;
	}
	void displayBeta(){
		cout<<"Beta : "<<numBeta<<endl;
	}
};

class gamma:public alpha,public beta{
	int numGamma;
public:
	gamma(){
		cout<<"Default Constructor of Base Class - Gamma"<<endl;
	}
	gamma(int x,int y,int z):alpha(x),beta(y){
		numGamma = z;
		cout<<"Parameterized Constructor for Derived Glass Gamma and Gamma initialized"<<endl;
	}
	void displayGamma(){
		cout<<"Gamma : "<<numGamma<<endl;
	}
};

int main() {
	int choice,Alpha,Beta,Gamma;
	cout<<"In this program, two base classes Alpha and Beta is inherited by class Gamma"<<endl;
	cout<<"1.To Create Object for Gamma which does not take any arguments\n2.Create Object for Gamma with arguments for all the classes\n";
	cin>>choice;
	if(choice == 1){
		gamma k;
		cout<<endl;
		cout<<"Even if there is no arguments then also the default constructor of the base classes are called."<<endl;
	}
	else{
		cout<<"Give the input for alpha : ";
		cin>>Alpha;
		cout<<"Give the input for beta : ";
		cin>>Beta;
		cout<<"Give the input for gamma : ";
		cin>>Gamma;
		cout<<endl;
		gamma g(Alpha,Beta,Gamma);
		cout<<endl;
		g.displayAlpha();
		g.displayBeta();
		g.displayGamma();
		cout<<endl;
		cout<<"Even though , if the object is created for a derived class as the base classes are inherited\ntheir constructor are called in the order in which they are inherited";
	}
	return 0;
}

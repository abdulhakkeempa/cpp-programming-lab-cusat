//Write a C++ Program to demonstrate the use of class templates.
#include <iostream>
using namespace std;

template <class T>
class Calculator{
	T num1,num2;
public:
	Calculator(T a,T b){
		num1=a;
		num2=b;
	}
	T sum(){
		T sum;
		sum = num1+num2;
		return sum;
	}
	T subtract(){
		T difference;
		difference = num1-num2;
		return difference;
	}
	T multiply(){
		T product;
		product = num1*num2;
		return product;
	}
	T divide(){
		T ratio;
		ratio = num1/num2;
		return ratio;
	}
};
int main() {
	int choice;
	cout<<"1.Integer Operations\n2.Decimal Operations\n3.Quit"<<endl;
	cin>>choice;
	if (choice==1) {
		int num1,num2;
		cout<<"Enter the numbers"<<endl;
		cin>>num1>>num2;
		Calculator <int> obj1(num1,num2);
		int loopOption;
		do {
			cout<<"1.Addition\n2.Subtraction\n3.Multiplication\n4.Division"<<endl;
			int key;
			cin>>key;
			switch (key) {
				case 1:
					cout<<num1<<" + "<<num2<<" = "<<obj1.sum()<<endl;
					break;
				case 2:
					cout<<num1<<" - "<<num2<<" = "<<obj1.subtract()<<endl;
					break;
				case 3:
					cout<<num1<<" x "<<num2<<" = "<<obj1.multiply()<<endl;
					break;
				case 4:
					cout<<num1<<" / "<<num2<<" = "<<obj1.divide()<<endl;
					break;
				default:
					break;
			}
			cout<<"Do you want to continue\n1.Continue\n2.Exit"<<endl;
			cin>>loopOption;
		} while (loopOption==1);

	}
	else if (choice==2) {
		float num1,num2;
		cout<<"Enter the numbers"<<endl;
		cin>>num1>>num2;
		Calculator <float> obj2(num1,num2);
		int loopOption;
		do {
			cout<<"1.Addition\n2.Subtraction\n3.Multiplication\n4.Division"<<endl;
			int key;
			cin>>key;
			switch (key) {
				case 1:
					cout<<num1<<" + "<<num2<<" = "<<obj2.sum()<<endl;
					break;
				case 2:
					cout<<num1<<" - "<<num2<<" = "<<obj2.subtract()<<endl;
					break;
				case 3:
					cout<<num1<<" x "<<num2<<" = "<<obj2.multiply()<<endl;
					break;
				case 4:
					cout<<num1<<" / "<<num2<<" = "<<obj2.divide()<<endl;
					break;
				default:
					break;
			}
			cout<<"Do you want to continue\n1.Continue\n2.Exit"<<endl;
			cin>>loopOption;
		} while (loopOption==1);
	}
	return 0;
}

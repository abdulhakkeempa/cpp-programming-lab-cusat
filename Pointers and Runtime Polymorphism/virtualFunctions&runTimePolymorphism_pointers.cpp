/*Program to understand how to access member functions using pointers*/
#include <iostream>
using namespace std;

class item{
	int code;
	float price;
public:
	item(){
		cout<<"Constructor"<<endl;
	}
	~item(){
		cout<<"Destructor"<<endl;
	}
	void get_data(int c,float p){
		code = c;
		price = p;
	};
	void show_data(){
		cout<<"Code is "<<code<<endl;
		cout<<"Price is "<<price<<endl;
	}
};

//const int size = 10;
int main() {
	item x;
	x.get_data(50, 30);
	x.show_data();

	item *ptr; //pointer to class
	ptr = new item;
	ptr->get_data(30, 40); 	//pointer is pointing towards a function using -> operator
	ptr->show_data();
	(*ptr).get_data(100, 200); //pointer variable is accessing the member function with . operator
	(*ptr).show_data();
	ptr->show_data();

	(&x)->show_data();
	cout<<ptr<<endl; //prints the address of the object of item stored in ptr.
	cout<<&ptr<<endl;//prints the address of the pointer ptr.
	ptr->show_data();
	(*ptr).show_data();
	cout<<"Going to delete ptr"<<endl;
	delete ptr;
	cout<<"ptr deleted"<<endl;
	return 0;
}

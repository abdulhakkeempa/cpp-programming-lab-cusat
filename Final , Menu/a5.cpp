#include <iostream>
using namespace std;

class A{
public:
	A(){
		cout<<"This is Constructor"<<endl;
	}
	~A(){
		cout<<"This is Destructor"<<endl;
	}
};


int main() {
	A Object;
	return 0;
}

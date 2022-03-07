#include <iostream>
using namespace std;

class object{
	int static count;
public:
	object(){
		count++;
	}
	void static showcount(){
		cout<<"No of Objects created : "<<count;
	}
};

int object::count;

int main() {
	object a;
	a.showcount();
	return 0;
}

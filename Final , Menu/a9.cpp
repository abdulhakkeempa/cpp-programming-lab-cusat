#include <iostream>
using namespace std;

class object{
	int static count;
public:
	object(){
		count++;
	}
	void static showcount(){
		cout<<"No of Objects created : "<<count<<endl;
	}
};

int object::count;

int main() {
	int size=1;
	int choice;
	do
	{
		object *a = new object[size];
		a[size].showcount();
		cout<<"Do you want to create new objects \n1.New Object \n2.Quit"<<endl;
		cin>>choice;
	} while (choice==1);
	

	return 0;
}

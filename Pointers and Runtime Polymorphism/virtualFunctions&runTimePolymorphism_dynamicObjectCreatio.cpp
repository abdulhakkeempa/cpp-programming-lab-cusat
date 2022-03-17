//program to dynamically create objects and access them using pointer incrementation
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

const int size=4;
int main() {
	item *p = new item[size];
	item *d = p;
	int x;
	float y;
	for (int i = 0; i < size; ++i) {   //what happens when the size is limiting condition is greater than size
		cout<<"Enter Code and Price"<<i+1<<endl;
		cin>>x>>y;
		p->get_data(x, y);
		//(*p).show_data();
		cout<<p<<endl;
		p++;
	}
	for (int i = 0; i < size; ++i) {
		d->show_data();
		d++;
		cout<<d<<endl;
	}
	cout<<"delete - p"<<endl;
	delete p;
	cout<<"delete - d"<<endl;
	delete d;
	return 0;
}

#include <iostream>
using namespace std;

class A{
	int **p;
	int d1,d2;
public:
	A(int x,int y){
		cout<<"Array dynamically allocated by constructor"<<endl;
		d1 = x;
		d2 = y;
		p = new int *[d1];
		for (int i = 0; i < d1; ++i) {
			p[i] = new int [d2];
		}
	}
	void get_data();
	void put_data();
	~A(){
		cout<<"Memory released using destructor"<<endl;
	}
};

void A::get_data(){
	cout<<"Enter the Values Row by Row"<<endl;
	for (int i = 0; i < d1; ++i) {
		cout<<"Row - "<<i+1<<endl;
		for (int j = 0; j < d2; ++j) {
			cin>>p[i][j];
		}
	}
}

void A::put_data(){
	for (int i = 0; i < d1; ++i) {
		for (int j = 0; j < d2; ++j) {
			cout<<p[i][j]<<"\t";
		}
		cout<<endl;
	}
}



int main() {
	int row,col;
	cout<<"Enter the rows and coloumns of the matrix"<<endl;
	cin>>row>>col;
	A Object(row,col);
	Object.get_data();
	Object.put_data();
	return 0;
}

#include <iostream>
using namespace std;

const int size=6;
class list{
	int itemcode[size];
	float itemprice[size];
	float sum;
	static int count;
	bool removed;

public:
	void getdata();
	void displaysum();
	void remove();
	void displaylist();
};

void list::getdata(){
	for (int i = 0; i < size; ++i) {
		cout<<"Enter the Item Code : ";
		cin>>itemcode[i];
		cout<<"Enter the Item Price : ";
		cin>>itemprice[i];
		count++;
	}
}
void list::displaysum(){
	sum=0;
	for (int i = 0; i < size; ++i) {
		sum=sum+itemprice[i];
	}
	cout<<"The Total Sum of Products is "<<sum<<endl;
}
void list::remove(){
	int itemCode;
	cout<<"Enter the Item Code You Want to Remove\n";
	cin>>itemCode;
	removed=false;
	int position;
	for (int i = 0; i < size; ++i) {
		if (itemCode==itemcode[i]) {
			position=i;
			removed=true;
		}
	}
	if (removed) {
		cout<<"Succesfully Removed "<<endl;
		for (int i = position; i < size; ++i) {
			itemcode[i]=itemcode[i+1];
			itemprice[i]=itemprice[i+1];
		}
	}
	else {
		cout<<"The Particular Code is not Found"<<endl;
	}
}

void list::displaylist(){
	cout<<"Item Code\t\t";
	cout<<"Item Price"<<endl;
	if(removed){
		for (int i = 0; i < size-1; ++i) {
		cout<<itemcode[i]<<"\t\t\t";
		cout<<itemprice[i]<<endl;
		}
	}
	else{
		for (int i = 0; i < size; ++i) {
			cout<<itemcode[i]<<"\t\t\t";
			cout<<itemprice[i]<<endl;
		}
	}
}

int list::count;

int main() {
	list stock;
	stock.getdata();
	stock.displaysum();
	stock.remove();
	stock.displaylist();
	return 0;
}

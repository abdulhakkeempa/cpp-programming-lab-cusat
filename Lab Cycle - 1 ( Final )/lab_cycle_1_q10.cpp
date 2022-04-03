#include <iostream>
using namespace std;

const int size=6;
class list{
	int itemcode[size];
	float itemprice[size];
	float sum;
	static int count;
	bool removed;
	int n_removed;

public:
	list(){
		n_removed = 0;
	}
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
		n_removed++;
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
		for (int i = 0; i < size-n_removed; ++i) {
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
	list stock1;
	int choice,option;
	
	do
	{
		cout<<"Welcome\n1.Add Data\n2.Display the total sum\n3.Remove an item\n4.Display List\n5.Quit"<<endl;
		cin>>choice;
		switch (choice)
		{
			case 1:
				stock1.getdata();
				break;
			case 2:
				stock1.displaysum();
				break;
			case 3:
				stock1.remove();
				break;
			case 4:
				stock1.displaylist();
				break;
			case 5:
				return 0;
				break;
			default:
				cout<<"Invalid Choice"<<endl;
				break;
	}
		cout<<"Do you want to continue or quit\n1.Continue\n2.Quit"<<endl;
		cin>>option;
	} while (option==1);
	return 0;
}

#include <iostream>
using namespace std;

class list{
	string itemName;
	int itemCode;
	float itemPrice;
	int itemQuantity;
	float totalSum;
public:
	list(){
		itemCode=0;
		itemPrice=0;
		itemQuantity=0;
		totalSum = 0;
	}
	void addItem(){
		cout<<"Item Name : ";
		cin>>itemName;
		cout<<"Item Code : ";
		cin>>itemCode;
		cout<<"Item Quantity : ";
		cin>>itemQuantity;
		cout<<"Item Price : ";
		cin>>itemPrice;
	}
	void displayItem(){
		cout<<itemCode<<"\t\t"<<itemName<<"\t\t"<<itemPrice<<"\t\t"<<itemQuantity<<endl;
	}
	void alterQuantity(int decrement){
		itemQuantity = itemQuantity - decrement;
	}
	int checkCode(){
		return itemCode;
	}
	int checkQuantity(){
		return itemQuantity;
	}
	void updateQuantity(int newQuantity){
		itemQuantity = itemQuantity + newQuantity;
	}
	float generateSum(){
		return itemQuantity*itemPrice;
	}
};

int main() {
	list *stock = new list[10];
	list *shoppingList = new list[10];
	int stockCount = 0;
	int shoppingCount = 0;
	int option,choice;
	int keyPosition;
	bool found = false;
	do {
		cout<<"1.Add Item\n2.Delete Item\n3.Update Item\n4.Display Items\n5.Purchase Item"<<endl;
		cin>>option;
		switch (option) {
			case 1:
				stock[stockCount].addItem();
				cout<<"Item Added Successfully"<<endl;
				stockCount++;
				break;
			case 2:
			{
				int searchKey;
				cout<<"Item Code : ";
				cin>>searchKey;
				for (int i = 0; i < stockCount; ++i) {
					if (searchKey==stock[i].checkCode()) {
						found = true;
						keyPosition = i;
						break;
					}
				}
				if (!found) {
					cout<<"Invalid Code"<<endl;
				}
				else{
					for (int i = keyPosition; i < stockCount; ++i) {
						stock[i]=stock[i+1];
					}
					stockCount--;
				}
			}
				break;
			case 3:
			{
				bool found = false;
				cout<<"Item Code\tItem Name\tItem Price\tItem Quantity"<<endl;
				for (int i = 0; i < stockCount; ++i) {
					stock[i].displayItem();
				}
				int searchKey;
				cout<<"Enter the Item Code : ";
				cin>>searchKey;
				for (int i = 0; i < stockCount; ++i) {
					if (searchKey==stock[i].checkCode()) {
						int x;
						cout<<"Enter the Amount of Quantity : ";
						cin>>x;
						stock[i].updateQuantity(x);
						found = true;
						break;
					}
				}
				if(!found){
					cout<<"Invalid Code"<<endl;
				}
			}
				break;
			case 4:
				cout<<"Item Code\tItem Name\tItem Price\tItem Quantity"<<endl;
				for (int i = 0; i < stockCount; ++i) {
					stock[i].displayItem();
				}
				break;
			case 5:
			  int choice;
			  do{
				bool purchased = false;
				int tempItemCode,tempItemQuantity;
				cout<<"Enter the Item Code"<<endl;
				cin>>tempItemCode;
				cout<<"Quantity you want to purchase"<<endl;
				cin>>tempItemQuantity;
				for (int i = 0; i < stockCount; ++i) {
					if (tempItemCode==stock[i].checkCode()) {
						if(tempItemQuantity>stock[i].checkQuantity()){
							cout<<"Insufficient Stock"<<endl;
							break;
						}
						purchased = true;
						shoppingList[shoppingCount]=stock[i];
						shoppingList[shoppingCount].updateQuantity(tempItemQuantity);
						stock[i].alterQuantity(tempItemQuantity);
						shoppingList[shoppingCount].displayItem();
						shoppingCount++;
						break;
					}
				}
				cout<<"Do you want to continue purchase"<<endl;
				cout<<"1.Continue\n2.Generate Bill"<<endl;
				cin>>choice;
				float totalSum;
				if(choice==2 and purchased==true){
					cout<<"Your Purchase Bill"<<endl;
					cout<<"Item Code\tItem Name\tItem Price\tItem Quantity"<<endl;
					for (int i = 0; i < shoppingCount; ++i) {
						shoppingList[i].displayItem();
						totalSum = totalSum + shoppingList[i].generateSum();
					}
					cout<<"Total Sum = "<<totalSum<<endl;
				}
				}
			  while(choice==1);
			  break;
			default:
				break;
		}
		cout<<"1.Continue\n2.Quit"<<endl;
		cin>>choice;
	}while(choice==1);
	return 0;
}

#include <iostream>
#include <limits>
using namespace std;

class bank{
	string cust_name;
	int acc_no;
	char acc_type;
	float balance,customer_amount;
	int static count;
public:
	void new_acc(void);
	void withdraw(void);
	void deposit(void);
	void balance_enquiry(void);
	void acc_statement(void);
};

int bank::count;

void bank::new_acc(){
	count++;
	acc_no=count;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout<<"Enter your name"<<endl;
	getline(cin,cust_name);
	cout<<"Enter the type of Account your prefer\nS for Savings Account\nC for Current Account\n";
	cin>>acc_type;
	cout<<"Enter the Amount you want to deposit (Minimum Balance is Rs.500)\n";
	cin>>balance;
	cout<<"\nYour Account Number is "<<acc_no<<endl;
	cout<<"Congratulations , Account Created Successfully\n";
}

void bank::withdraw(){
	cout<<"Enter the amount you have to withdraw\n";
	cin>>customer_amount;
	if ((balance-customer_amount)>500) {
		balance=balance-customer_amount;
		cout<<"Rs."<<customer_amount<<" is withdrawn\n";
	} else {
		cout<<"Transaction Failed\nInfo : Minimum Balance Not Available\n";
	}
}

void bank::deposit(){
	cout<<"Enter the amount you have to deposit\n";
	cin>>customer_amount;
	balance=customer_amount+balance;
	cout<<"Rs."<<customer_amount<<" is deposited\n";
}

void bank::balance_enquiry(){
	cout<<"Current Balance is Rs."<<balance<<endl;
}

void bank::acc_statement(){
	cout<<"------------------------------------\n";
	cout<<"Your Account Statement is \n";
	cout<<"Account Holder  : "<<cust_name<<endl;
	cout<<"Account No      : "<<acc_no<<endl;
	cout<<"Account Type    : "<<acc_type<<endl;
	cout<<"Account Balance : Rs."<<balance<<endl;
	cout<<"------------------------------------\n";

}

int main() {
	const int customer_number=20;
	int choice;
	bool Close = false;
	bank* customer=new bank[customer_number];
	int leave;

	for (int i = 0; i < customer_number; ++i) {
		if(Close){
			leave = 3;
		}
		else{
			leave = 1;
		}
		while (leave == 1){
		cout<<"\nCustomer "<<i+1<<endl;
		cout<<"Main Menu\n1.Press 1 for New Account\n2.Press 2 to Withdraw\n3.Press 3 to Deposit\n4.Press 4 to check balance\n5.Press 5 for Account Statement\n";
		cin>>choice;
		switch (choice) {
			case 1:
			    customer[i].new_acc();
				break;
			case 2:
				customer[i].withdraw();
				break;
			case 3:
				customer[i].deposit();
				break;
			case 4:
				customer[i].balance_enquiry();
				break;
			case 5:
				customer[i].acc_statement();
				break;
			default:
				cout<<"Error! , Try Again"<<endl;
				break;
			}
			cout<<"\nDo you want to continue or quit.\nPress 1 to Continue\nPress 2 to Next Customer\nPress 3 to Quit the Application\n";
			cin>>leave;
			
			if (leave==3) {
				Close = true;
			}
			
		}
	}
	return 0;
}

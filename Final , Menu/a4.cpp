#include <iostream>
using namespace std;

class Strings{
	string name;
	int count;
public:
	void getString();
	void compare(Strings,Strings);
	void concatenate(Strings,Strings);
	void length(Strings);
	void displayLength();
};

void Strings::getString(){
	cout<<"Enter Your String : ";
	getline(cin,name);
}
void Strings::concatenate(Strings string1,Strings string2){
	name=string1.name+string2.name;
	cout<<name<<endl;
}

void Strings::compare(Strings string1,Strings string2){
	if (string1.name == string2.name) {
		cout<<"They are same strings"<<endl;
	}
	else {
		cout<<"They are not same strings"<<endl;
	}
}

void Strings::length(Strings string){
	count=0;
	while(string.name[count]){
		count++;
	}
}

void Strings::displayLength(){
	cout<<"The String Length is "<<count<<endl;
}

int main() {
	Strings string1,string2,result;
	int choice,option;
	string1.getString();
	string2.getString();
	do
	{	
	cout<<"1.String Length\n2.Concatenate\n3.Compare"<<endl;
	cin>>choice;
	switch (choice)
	{
		case 1:
			cout<<"First String"<<endl;
			string1.length(string1);
			string1.displayLength();
			cout<<"Second String"<<endl;
			string2.length(string2);
			string2.displayLength();
			break;
		case 2:
			result.concatenate(string1, string2);
			break;
		case 3:
			result.compare(string1,string2);
			break;
		default:
			cout<<"Invalid Choice"<<endl;
			break;
	}
	cout<<"Do you want to continue or quit\n1.Continue\n2.Quit"<<endl;
	cin>>option;
	} while (option == 1);
	if(option == 2){
		cout<<"Succesfully Quitted"<<endl;
	}
	return 0;
}

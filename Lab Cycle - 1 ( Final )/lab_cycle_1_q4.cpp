#include <iostream>
#include <cstring>
using namespace std;

class Strings{
	char *name;
	int length;
public:
	Strings(){
		length=0;
		name = new char[length+1];
	}
	~Strings(){
		delete name;
		cout<<"Memmory Released"<<endl;
	}
	void getString(const char *txt);
	void compare(const Strings&,const Strings&);
	void concatenate(const Strings&,const Strings&);
	void displayLength();
};

void Strings::getString(const char *txt){
	length = strlen(txt);
	delete name;
	name = new char[length+1];
	strcpy(name, txt);
}

void Strings::concatenate(const Strings &string1,const Strings &string2){
	length = string1.length + string2.length;
	delete name;
	name = new char[length+1];
	strcpy(name, string1.name);
	strcat(name, string2.name);
	cout<<"The Concatenated String is "<<name<<endl;
}

void Strings::compare(const Strings &string1,const Strings &string2){
	if (string1.length == string2.length) {
		cout<<"They are same strings"<<endl;
	}
	else if (string1.length > string2.length) {
		cout<<string1.name<<" is greater than "<<string2.name<<endl;
	}
	else {
		cout<<string2.name<<" is greater than "<<string1.name<<endl;
	}
}

void Strings::displayLength(){
	cout<<"The String Length is "<<length<<endl;
}

int main() {
	char name1[50],name2[50];
	Strings string1,string2,result;
	int choice,option;
	cout<<"Enter your First String"<<endl;
	cin>>name1;
	cout<<"Enter your Second String"<<endl;
	cin>>name2;
	string1.getString(name1);
	string2.getString(name2);
	do
	{
	cout<<"1.String Length\n2.Concatenate\n3.Compare"<<endl;
	cin>>choice;
	switch (choice)
	{
		case 1:
			cout<<"First String"<<endl;
			string1.displayLength();
			cout<<"Second String"<<endl;
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
	if(option != 1){
		cout<<"Succesfully Quitted"<<endl;
	}
	return 0;
}

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
	string1.getString();
	string1.length(string1);
	string1.displayLength();

	string2.getString();
	string2.length(string2);
	string2.displayLength();

	result.concatenate(string1, string2);
	result.compare(string1,string2);

	return 0;
}

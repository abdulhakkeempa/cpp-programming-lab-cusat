/*Write a C++ program to design a student class representing student roll no. and
a test class (derived class of student) representing the scores of the student in
various subjects and sports class representing the score in sports. The sports and
test class should be inherited by a result class having the functionality to add
the scores and display the final result for a student. Demonstrate the concept of
Virtual base class on Hybrid inheritance.*/
#include <iostream>
#include <iomanip>
using namespace std;

//base class - Student
class Student{
protected:
	char name[15];
	int rollNo;
public:
	void getRollNo(){
		cout<<"Enter your name"<<endl;
		cin>>name;
		cout<<"Enter you roll no : ";
		cin>>rollNo;
	}
	void displayRollNo(){
		cout<<"Name"<<setw(16)<<":"<<setw(2)<<name<<endl;
		cout<<"Roll No"<<setw(13)<<":"<<rollNo<<endl;
	}
};

//derived class - Test , inherited Student as virtual base to avoid ambiguity
class Test:public virtual Student{
protected:
	float mark1,mark2;
public:
	void getMarks(){
		cout<<"Enter the mark for subject 1 : ";
		cin>>mark1;
		cout<<"Enter the mark for subject 2 : ";
		cin>>mark2;
	}
	void displayMarks(){
		cout<<"Mark for Subject 1 :"<<mark1<<endl;
		cout<<"Mark for Subject 2 :"<<mark2<<endl;
	}
};

//derived class - Sports , inherited Student as virtual base to avoid ambiguity
class Sports:public virtual Student{
protected:
	int sportsScore;
public:
	void getScore(){
		cout<<"Enter the Score for Sports : ";
		cin>>sportsScore;
	}
	void displayScore(){
		cout<<"Score for Sports"<<setw(4)<<":"<<setw(2)<<sportsScore<<endl;
	}
};

//derived class - Result from Test and Sports.
class Result:public Test,public Sports{
	float total;
public:
	void totalResult(){
		total = mark1 + mark2 + sportsScore;
	}
	void displayResult(){
		cout<<endl;
		displayRollNo();
		displayMarks();
		displayScore();
		totalResult();
		cout<<"Total"<<setw(16)<<": "<<total<<endl;
	}
};

int main() {
	int option,loopOption;
	cout<<"Welcome\n1.Start\n2.Quit"<<endl;
	cin>>option;
	if (option==1) {
		do {
			Result A;
			A.getRollNo();
			A.getMarks();
			A.getScore();
			A.displayResult();
			cout<<"1.Continue\n2.Quit"<<endl;
			cin>>loopOption;
		} while (loopOption==1);
	}
	return 0;
}

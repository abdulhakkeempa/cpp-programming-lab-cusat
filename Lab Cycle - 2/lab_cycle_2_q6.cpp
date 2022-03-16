/*Write a C++ program to design a student class representing student roll no. and
a test class (derived class of student) representing the scores of the student in
various subjects and sports class representing the score in sports. The sports and
test class should be inherited by a result class having the functionality to add
the scores and display the final result for a student. Demonstrate the concept of
Virtual base class on Hybrid inheritance.*/

#include <iostream>
using namespace std;

class Student{
protected:
	int rollNo;
public:
	void getRollNo(){
		cout<<"Enter you roll no : ";
		cin>>rollNo;
	}
	void displayRollNo(){
		cout<<"Roll No : "<<rollNo<<endl;
	}
};

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
		cout<<"Mark for Subject 1 : "<<mark1<<endl;
		cout<<"Mark for Subject 2 : "<<mark2<<endl;
	}
};

class Sports:public virtual Student{
protected:
	int sportsScore;
public:
	void getScore(){
		cout<<"Enter the Score for Sports : ";
		cin>>sportsScore;
	}
	void displayScore(){
		cout<<"Score for Sports : "<<sportsScore<<endl;
	}
};

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
		cout<<"Total is : "<<total<<endl;
	}
};

int main() {
	Result A;
	A.getRollNo();
	A.getMarks();
	A.getScore();
	A.displayResult();
	return 0;
}

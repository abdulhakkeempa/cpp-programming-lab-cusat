#include <iostream>
#include <limits>
using namespace std;

class student{
	std::string name;
	int roll_no;
	float mark1,mark2,mark3,totalMarks;
	char grade;

	public:
		void input();
		char calcGrade(float,float,float);
		void display();
};

void student::input(){
	std::cout<<"Enter the Student Name : ";
	std::cin>>name;
	std::cout<<"Enter the Roll No : ";
	std::cin>>roll_no;
	std::cout<<"Enter the Marks for Subject 1 : ";
	std::cin>>mark1;
	std::cout<<"Enter the Marks for Subject 2 : ";
	std::cin>>mark2;
	std::cout<<"Enter the Marks for Subject 3 : ";
	std::cin>>mark3;
}

char student::calcGrade(float mark1,float mark2,float mark3){
	totalMarks = (mark1+mark2+mark3)/3;
	if(totalMarks>=90){
		grade='A';
	}
	else if(totalMarks>=80 and totalMarks<90){
		grade='B';
	}
	else if(totalMarks>=70 and totalMarks<80){
		grade='C';
	}
	else if(totalMarks>=60 and totalMarks<70){
		grade='D';
	}
	else if(totalMarks>=50 and totalMarks<60){
		grade='E';
	}
	else{
		grade='F';
	}
	return grade;
}

void student::display(){
	std::cout<<"Student : "<<name;
	std::cout<<"\nThe Grade is "<<calcGrade(mark1,mark2,mark3)<<std::endl;
}

int main() {
	int choice = 1;
	do{
		student Student1;
		Student1.input();
		Student1.display();
		std::cout<<"\nDo you want to continue \n1.Continue\n2.Quit"<<std::endl;
		std::cin>>choice; 
	} while(choice == 1);
	return 0;
}

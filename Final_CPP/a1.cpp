#include <iostream>

class student{
	std::string name;
	int roll_no;
	float mark1,mark2,mark3,marks;
	char grade;

	public:
		void input();
		char calcGrade(float marks);
		void display();
};

void student::input(){
	std::cout<<"Enter the Student Name : ";
	std::getline(std::cin,name);
	std::cout<<"Enter the Roll No : ";
	std::cin>>roll_no;
	std::cout<<"Enter the Marks for Subject 1 : ";
	std::cin>>mark1;
	std::cout<<"Enter the Marks for Subject 2 : ";
	std::cin>>mark2;
	std::cout<<"Enter the Marks for Subject 3 : ";
	std::cin>>mark3;
}

char student::calcGrade(float marks){

	if(marks>=90){
		grade='A';
	}
	else if(marks>=80 and marks<90){
		grade='B';
	}
	else if(marks>=70 and marks<80){
		grade='C';
	}
	else if(marks>=60 and marks<70){
		grade='D';
	}
	else if(marks>=50 and marks<60){
		grade='E';
	}
	else{
		grade='F';
	}
	return grade;
}

void student::display(){
	std::cout<<"Student : "<<name;
	std::cout<<"\nThe Grade for Subject 1 is "<<calcGrade(mark1)<<std::endl;
	std::cout<<"The Grade for Subject 2 is "<<calcGrade(mark2)<<std::endl;
	std::cout<<"The Grade for Subject 3 is "<<calcGrade(mark3);
}

int main() {
	student Student1;
	Student1.input();
	Student1.display();
	return 0;
}

//Write a C++ program to demonstrate the concept of Multiple and Multilevel
//inheritance including constructors with parameters.

#include <iostream>
#include <iomanip>
using namespace std;

//base class - details of student in CS Department.
class StudentsAtCs{
protected:
	int noOfStudents;
public:
	//constructor for base class.
	StudentsAtCs(int n){
		noOfStudents = n;
	}
	void display(){
		cout<<"No of Students in CS Department"<<setw(14)<<":"<<setw(6)<<noOfStudents<<endl;
	}
};
//base class- details of teachers in CS Department.
class TeachersAtCs{
protected:
	int noOfTeacher;
public:
	//constructor for base class.
	TeachersAtCs(int n){
		noOfTeacher = n;
	}
	void display(){
		cout<<"No of Teachers in CS Department"<<setw(14)<<":"<<setw(6)<<noOfTeacher<<endl;
	}
};

//multiple inheritance - derived class (whole details of CS Department).
class csDepartment:public StudentsAtCs,public TeachersAtCs{
protected:
	int noOfNonTeachingStaff;
public:
	//constructor for derived class which passes arguments to the base class.
	csDepartment(int n1,int n2,int n3):StudentsAtCs(n1),TeachersAtCs(n2){
		noOfNonTeachingStaff=n3;
	}
	void display(){
		cout<<"No of Non Teaching Staff in CS Department"<<setw(4)<<":"<<setw(6)<<noOfNonTeachingStaff<<endl;
	}
};

//multilevel inheritance - derived class (whole details in university).
class University:public csDepartment{
	int studentsRegistered;
public:
	University(int n1,int n2,int n3,int n4):csDepartment(n1, n2, n3){
		studentsRegistered=n4;
	}
	void display(){
		StudentsAtCs::display(); //invokes the display function of base class StudentsAtCs
		TeachersAtCs::display(); //invokes the display function of base class TeachersAtCs
		csDepartment::display(); //invokes the display function of derived class csDepartment
		cout<<"No of Students Registered in the University : "<<setw(5)<<studentsRegistered<<endl;
	}
};


int main() {
	cout<<"In this Program there are two base classes , StudentsAtCs and TeachersAtCs"<<endl;
	cout<<"which are then inherited by the class csDepartment (multiple inheritance)"<<endl;
	cout<<"csDepartment is then inherited by class University (multilevel)"<<endl;
	int option;
	cout<<"1.Start\n2.Quit"<<endl;
	cin>>option;
	if (option==1) {
		int deptStudents,deptTeachers,deptNonTeachers,UniversityStudents;
		cout<<"No of Students in CS Department"<<endl;
		cin>>deptStudents;
		cout<<"No of Teachers in CS Department"<<endl;
		cin>>deptTeachers;
		cout<<"No of Non Teachers in CS Department"<<endl;
		cin>>deptNonTeachers;

		cout<<"No of Students Registered under the University"<<endl;
		cin>>UniversityStudents;
		University CUSAT(deptStudents,deptTeachers, deptNonTeachers, UniversityStudents);
		int choice;
		cout<<"Do you want to display the details\n1.Print\n2.Quit"<<endl;
		cin>>choice;
		if (choice==1) {
			CUSAT.display(); //invokes the display function of the derived class University.
		} else {
			return 0;
		}
	} else {
		cout<<"Successfully Quited !"<<endl;
		return 0;
	}
	return 0;
}

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

//multilevel inheritance- derived class (whole details of the college).
class College:public csDepartment{
protected:
	int totalNoStudents,totalNoTeachers,totalNoNonTeachers;
public:
	//constructor for derived class which passes arguments to the base class.
	College(int n1,int n2,int n3,int n4,int n5,int n6):csDepartment(n1, n2, n3){
		totalNoStudents=n4;
		totalNoTeachers=n5;
		totalNoNonTeachers=n6;
	}
	void display(){
		cout<<"No of Students in the College"<<setw(16)<<":"<<setw(6)<<totalNoStudents<<endl;
		cout<<"No of Teachers in the College"<<setw(16)<<":"<<setw(6)<<totalNoTeachers<<endl;
		cout<<"No of Non Teaching Staff in the College"<<setw(6)<<":"<<setw(6)<<totalNoNonTeachers<<endl;
	}
};
//multilevel inheritance - derived class (whole details in university).
class University:public College{
	int studentsRegistered;
public:
	University(int n1,int n2,int n3,int n4,int n5,int n6,int n7):College(n1, n2, n3, n4, n5, n6){
		studentsRegistered=n7;
	}
	void display(){
		StudentsAtCs::display(); //invokes the display function of base class StudentsAtCs
		TeachersAtCs::display(); //invokes the display function of base class TeachersAtCs
		csDepartment::display(); //invokes the display function of derived class csDepartment
		College::display(); //invokes the display function of base class College
		cout<<"No of Students Registered in the University : "<<setw(5)<<studentsRegistered<<endl;
	}
};


int main() {
	cout<<"In this Program there are two base classes , StudentsAtCs and TeachersAtCs"<<endl;
	cout<<"which are then inherited by the class csDepartment (multiple inheritance)"<<endl;
	cout<<"csDepartment is then inherited by class College and College by class University (multilevel)"<<endl;
	int option;
	cout<<"1.Start\n2.Quit"<<endl;
	cin>>option;
	if (option==1) {
		int deptStudents,deptTeachers,deptNonTeachers,colStudents,colTeachers,colNonTeachers,UniversityStudents;
		cout<<"No of Students in CS Department"<<endl;
		cin>>deptStudents;
		cout<<"No of Teachers in CS Department"<<endl;
		cin>>deptTeachers;
		cout<<"No of Non Teachers in CS Department"<<endl;
		cin>>deptNonTeachers;

		cout<<"No of Students in the College"<<endl;
		cin>>colStudents;
		cout<<"No of Teachers in College"<<endl;
		cin>>colTeachers;
		cout<<"No of Non Teachers in College"<<endl;
		cin>>colNonTeachers;

		cout<<"No of Students Registered under the University"<<endl;
		cin>>UniversityStudents;
		University A(deptStudents,deptTeachers, deptNonTeachers, colStudents, colTeachers, colNonTeachers, UniversityStudents);
		int choice;
		cout<<"Do you want to display the details\n1.Print\n2.Quit"<<endl;
		cin>>choice;
		if (choice==1) {
			A.display(); //invokes the display function of the derived class University.
		} else {
			return 0;
		}
	} else {
		cout<<"Successfully Quited !"<<endl;
		return 0;
	}
	return 0;
}

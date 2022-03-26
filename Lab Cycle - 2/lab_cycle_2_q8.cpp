#include <iostream>
using namespace std;

class Shape{
protected:
	float area;
public:
	//virtual functions , which are redefined in derived classes
	virtual void get_data()=0;
	virtual void get_area()=0;
};

//class Circle inheriting class Shape.
class Circle:public Shape{
	float radius;
public:
	//modifying the function defined in the base class.
	void get_data(){
		cout<<"Enter the Radius of the Circle"<<endl;
		cin>>radius;
	}
	//modifying the function defined in the base class.
	void get_area(){
		area = (22.0/7.0)*radius*radius;
		cout<<"Area of the Circle is "<<area<<endl;
	}
};

//class Square inheriting class Shape.
class Square:public Shape{
	float side;
public:
	//modifying the function defined in the base class.
	void get_data(){
		cout<<"Enter the Side of the Square"<<endl;
		cin>>side;
	}
	//modifying the function defined in the base class.
	void get_area(){
		area = side*side;
		cout<<"Area of the Square is "<<area<<endl;
	}
};

//class Ellipse inheriting class Shape.
class Ellipse:public Shape{
	float minorAxis,majorAxis;
public:
	//modifying the function defined in the base class.
	void get_data(){
		cout<<"Enter the Minor Axis of the Ellipse"<<endl;
		cin>>minorAxis;
		cout<<"Enter the Major Axis of the Ellipse"<<endl;
		cin>>majorAxis;
	}
	//modifying the function defined in the base class.
	void get_area(){
		area = (22.0/7.0)*majorAxis*minorAxis;
		cout<<"The Area of the Ellipse is "<<area<<endl;
	}
};

//class Rectangle inheriting class Shape.
class Rectangle:public Shape{
	float length,breadth;
public:
	//modifying the function defined in the base class.
	void get_data(){
		cout<<"Enter the Length of the Rectangle"<<endl;
		cin>>length;
		cout<<"Enter the Breadth of the Rectangle"<<endl;
		cin>>breadth;
	}
	//modifying the function defined in the base class.
	void get_area(){
		area=length*breadth;
		cout<<"The Area of the Rectangle is "<<area<<endl;
	}
};
int main() {
	int exitOption,exitLoop;
	cout<<"Welcome\n1.Start\n2.Quit"<<endl;
	cin>>exitOption;
	if (exitOption==1) {
		do {
			//pointer of the type base class
			Shape *shapePointer;
			int choiceForArea;
			cout<<"1.Area of Square\n2.Area of Rectangle\n3.Area of Ellipse\n4.Area of Circle"<<endl;
			cin>>choiceForArea;
			switch (choiceForArea) {
				case 1:
					//shapePointer holding the address of the the object of class Square.
					shapePointer = new Square;
					//invokes the function of the class Square.
					shapePointer->get_data();
					shapePointer->get_area();
					break;
				case 2:
					//shapePointer holding the address of the the object of class Rectangle.
					shapePointer = new Rectangle;
					//invokes the function of the class Rectangle.
					shapePointer->get_data();
					shapePointer->get_area();
					break;
				case 3:
					//shapePointer holding the address of the the object of class Ellipse.
					shapePointer = new Ellipse;
					//invokes the function of the class Ellipse.
					shapePointer->get_data();
					shapePointer->get_area();
					break;
				case 4:
					//shapePointer holding the address of the the object of class Circle.
					shapePointer = new Circle;
					//invokes the function of the class Circle.
					shapePointer->get_data();
					shapePointer->get_area();
					break;
				default:
					break;
			}
			cout<<"Do you want to continue?\n1.Continue\n2.Quit"<<endl;
			cin>>exitLoop;
		} while (exitLoop==1);
	}
	if(exitLoop!=1 or exitOption!=1){
		cout<<"Successfully Exited!"<<endl;
	}
	return 0;
}

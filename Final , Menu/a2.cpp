#include <iostream>
#include <cmath>

void area(int length,int breadth){
	int area;
	area=length*breadth;
	std::cout<<"The Area of the Rectangle is "<<area<<std::endl;
}

void area(int side){
	int area;
	area=side*side;
	std::cout<<"The Area of the Square is "<<area<<std::endl;
}

void area(float radius){
	float area;
	area=3.14*radius*radius;
	std::cout<<"The Area of the Circle is "<<area<<std::endl;
}

void area(float height,float base1,float base2){
	float area;
	area=0.5*(height*(base1+base2));
	std::cout<<"The Area of the Trapezium is "<<area<<std::endl;
}

void area(int side1,int side2,int side3){
	float area;
	float s=(side1+side2+side3)/2;
	area=std::sqrt(s*(s-side1)*(s-side2)*(s-side3));
	std::cout<<"The Area of the Triangle is "<<area<<std::endl;
}

int main() {
	int choice,option;
	do{
		std::cout<<"1.Area of Rectangle\n2.Area of Circle\n3.Area of Trapezium\n4.Area of Triangle\n5.Area of Square\n";
		std::cin>>choice;
		switch(choice){
			case 1:
				int l,b;
				std::cout<<"Enter the Length & Breadth of Rectangle\n";
				std::cin>>l>>b;
				area(l, b);
				break;
			case 2:
				float radius;
				std::cout<<"\n\nEnter the Radius of the Circle\n";
				std::cin>>radius;
				area(radius);
				break;
			case 3:
				float height,base1,base2;
				std::cout<<"\n\nEnter the Height and Bases of Trapezium\n";
				std::cin>>height>>base1>>base2;
				area(height, base1, base2);
				break;
			case 4:
				int side1,side2,side3;
				std::cout<<"\n\nEnter the Sides of Triangle\n";
				std::cin>>side1>>side2>>side3;
				area(side1, side2, side3);
				break;
			case 5:
				int side;
				std::cout<<"\n\nEnter the Side of the Square\n";
				std::cin>>side;
				area(side);
				break;
	}
	std::cout<<"Do you want to continue?\n1.Continue\n2.Quit\n";
	std::cin>>option;
	}
	while(option == 1);
	
	return 0;
}

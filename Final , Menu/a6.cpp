#include <iostream>
using namespace std;

class Time{
	int hours;
	int minutes;
	int seconds;
public:
	void gettime(){
		cout<<"Enter the Hour\n";
		cin>>hours;
		cout<<"Enter the Minute\n";
		cin>>minutes;
		cout<<"Enter the Seconds\n";
		cin>>seconds;

	}
	void puttime(void){
		cout<<hours<<" hours "<<minutes<<" minutes and "<<seconds<<" seconds"<<endl;
	}
	void sum(Time,Time);
};

void Time::sum(Time t1,Time t2){
	seconds = t1.seconds+t2.seconds;
	minutes = seconds/60;
	seconds = seconds%60;
	minutes = minutes+t1.minutes+t2.minutes;
	hours=minutes/60;
	minutes=minutes%60;
	hours=hours+t1.hours+t2.hours;
}

int main() {
	Time T1,T2,T3;
	cout<<"Time 1"<<endl;
	T1.gettime();
	cout<<"Time 2"<<endl;
	T2.gettime();
	T3.sum(T1, T2);
	cout<<"Time 1 = ";
	T1.puttime();

	cout<<"Time 2 = ";
	T2.puttime();

	cout<<"Result  = ";
	T3.puttime();
	return 0;
}

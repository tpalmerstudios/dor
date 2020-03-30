#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct employeePay
{
	string name;
	int empNum;
	double payRate;
	double hours;
	double grossPay;
};

int main()
{
	employeePay employee1 = {"Betty Ross", 141, 18.75};
	employeePay employee2 = {"Jill Sandburg", 142, 17.50};
	
	cout << fixed << showpoint << setprecision(2);

	cout << "Name: " << employee1.name << endl;
	cout << "Employee Number: " << employee1.empNum << endl;
	cout << "Enter hours worked: ";
	cin >> employee1.hours;
	employee1.grossPay = employee1.hours * employee1.payRate;
	cout << "Gross Pay: " <<  employee1.grossPay << endl << endl;

	cout << "Name: " << employee2.name << endl;
	cout << "Employee Number: " << employee2.empNum << endl;
	cout << "Enter hours worked: ";
	cin >> employee2.hours;
	employee2.grossPay = employee2.hours * employee2.payRate;
	cout << "Gross Pay: " <<  employee2.grossPay << endl << endl;
	return 0;
}


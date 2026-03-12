#include <iostream>
using namespace std;

class Employee
{
public:
    virtual double calculateSalary() = 0; 
};

class FullTimeEmployee : public Employee
{
private:
    double fixedSalary;

public:
    FullTimeEmployee(double salary)
    {
        fixedSalary = salary;
    }

    double calculateSalary()
    {
        return fixedSalary;
    }
};

class PartTimeEmployee : public Employee
{
private:
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(int h, double r)
    {
        hoursWorked = h;
        hourlyRate = r;
    }

    double calculateSalary()
    {
        return hoursWorked * hourlyRate;
    }
};

int main()
{
    FullTimeEmployee emp1(50000);
    PartTimeEmployee emp2(20, 200);

    cout << "Full Time Employee Salary: " << emp1.calculateSalary() << endl;
    cout << "Part Time Employee Salary: " << emp2.calculateSalary() << endl;

    return 0;
}
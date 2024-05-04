#ifndef EMPLOYEE_H
#define EMPLOYEE_H
//employee class declaration
class employee
{
private:
	string name;
	string idNumber;
	string department;
	string position;
	int yearsWorked;
public:
	employee();
	employee(string, string, string, string, int);
	void setName(string);
	void setIdNumber(string);
	void setDepartment(string);
	void setPosition(string);
	//double setYearsWorked();
	bool setYearsWorked(int);
	string getName() const;
	string getIdNumber() const;
	string getDepartment() const;
	string getPosition() const;
	int getYearsWorked() const;
	
};
#endif
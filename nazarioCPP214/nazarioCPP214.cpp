// Nazario, Xavier
// November 1, 2025 ©
// Chapter 14 Programming Assignment
// References:
//	Gaddis, Tony. Starting Out with C++ from
//		Control Structures Through Objects. (10th Edition). Pearson Education (US), 2022.
//  C++ Tutorials:
//	 Classes (I) - https://cplusplus.com/doc/tutorial/classes/
//	 Classes (II) - https://cplusplus.com/doc/tutorial/templates/
//  Youtube Video:
//	 C++ Object Oriented Programming Crash Course - Introduction + Full Tutorial
//		From Channel Caleb Curry - https://www.youtube.com/watch?v=0NwsayeOsd4

//			*** NumDays, TimeOff, Personnel Report ***

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Define NumDays and TimeOff classes

//	NumDays takes hours worked and converts to days worked
//		Ex. 8 hrs = 1 day
class NumDays
{
	// Step 1: Define hours (private) variable
	//  hours (double) 
	private:

		double hours;	// Holds hours worked

	// Step 2: Constructor and Function Definition
	//	Make ALL public
	public:

		// Declare Default Constructor
		//	Uses hours
		//	Use h for variable / initialize to 0.0
		NumDays(double h = 0.0)
		{
			hours = h;
		}

		// Accessor Functions
		//	Use "get..." for naming / returns their attribute
		//	All are constants
		double getHours() const { return hours; }		// returns hours worked
		double getDays() const { return hours / 8.0; }	// returns days works, uses hours / 8.0 

		// Mutator Function
		//	Use "set..." for naming
		void setHours(double h) { hours = h; }	// Stores hours worked

	// Step 3: Overloaded Operator Functions
	//	Add, Subtract, increment, decrement
	//	Use obj as objects variable, NumDays is data type
	
	// Add Operator
	//	Remember const and *this (pointer)
		NumDays operator+(const NumDays& right) const
		{
			// Use temp as variable for return object
			NumDays temp;
			temp.hours = this->hours + right.hours;	// Adds hours
			return temp;							// returns sum of 2 NumDays Objects
		}

	// Subtract Operator
	//	Keep same temp variable
		NumDays operator-(const NumDays& right) const
		{
			NumDays temp;
			temp.hours = this->hours - right.hours;	// Subtracts hours
			return temp;							// returns difference of 2 NumDays Objects
		}

	// Increment Operator
	//	Uses hours, returns *this (pointer) as update
		NumDays operator++()
		{
			++hours;	// Prefix increase to hours
			return *this;	// returns updated hours
		}

		NumDays operator++(int)
		{
			// Use temp as variable
			NumDays temp = *this;	// Old values saved
			hours++;				// Postfix increase to hours
			return temp;			// returns updated hours
		}

	// Decrement Operator
	//	Uses hours, returns *this (pointer) as update
		NumDays operator--()
		{
			--hours;				// Prefix decrease to hours
			return *this;			// returns updated hours
		}

		NumDays operator--(int)
		{
			// Use temp as variable
			NumDays temp = *this;	// Old values saved
			hours--;				// Postfix decrease to hours
			return temp;			// returns updated hours
		}
};

// TimeOff takes sick leave, vacation, unpaid time off
//	Uses NumDays objects
class TimeOff
{
	// Step 1: Define Variables private
	//	Takes name and id
	//	Uses NumDays maxSickDays, sickTaken, maxVacation, vacTaken
	//		maxUnpaid, unpaidTaken
	private:

		string name;	// Holds employee Name
		int id;			// Holds employee ID Number
		
		NumDays maxSickDays;	// Holds Max Sick Days
		NumDays sickTaken;		// Holds Sick Dayes Taken

		NumDays maxVacation;		// Holds Max Vacation Days
		NumDays vacTaken;		// Holds Vacation Days Taken

		NumDays maxUnpaid;		// Holds Max Unpaid Time
		NumDays unpaidTaken;		// Holds UnPaid Time Taken

	// Step 2: Constructor and Function Definition
	//	Make ALL public
	public:

		// Declare Default Constructor
		//	Initialize name to "" / id to 0
		TimeOff()
		{
			name = "";
			id = 0;
		}

		// Overloaded Constructor
		//	Takes name and id as paramaters
		//	Use n and i as variable
		TimeOff(string n, int i)
		{
			name = n;
			id = i;
		}

		// Accessor Functions
		//	Use "get..." for naming / returns attribute
		//	Make ALL const
		string getName() const { return name; }		// returns employee Name
		int getId() const { return id; }			// returns employee ID Number

		NumDays getMaxSickDays() const { return maxSickDays; }		// returns Sick Days allotted
		NumDays getSickDaysTaken() const { return sickTaken; }		// returns Sick Days used

		NumDays getMaxVacation() const { return maxVacation; }		// returns Vacation Days allotted
		NumDays getVacTaken() const { return vacTaken; }			// returns Vacation Days used

		NumDays getMaxUnpaid() const { return maxUnpaid; }			// returns Unpaid Days allotted
		NumDays getUnpaidTaken() const { return unpaidTaken; }		// returns Unpaid Days used

		// Mutator Functions
		//	Use "set..." for naming
		//	Keep n and i for variables
		//	Use h for hours (double)
		void setName(string n) { name = n; }	// Sets employees Name
		void setId(int i) { id = i; }			// Sets emplyees ID Number

		void setMaxSickHours(double h) { maxSickDays.setHours(h); }		// Sets Max Sick Hours allotted
		void setSickHoursTaken(double h) { sickTaken.setHours(h); }		// Sets Sick Hours used

		void setMaxVacationHours(double h)
		{
			// Input Validation: Hours to NOT EXCEED 240 (Company Policy)
			//	Use if statement
			if (h > 240.0)
				h = 240.0;												// Sets Max Vacation Hours allotted
			maxVacation.setHours(h);
		}

		void setVacationHoursTaken(double h) { vacTaken.setHours(h); }	// Sets Vacation Hours used

		void setMaxUnpaidHours(double h) { maxUnpaid.setHours(h); }		// Sets Max Unpaid Hours allotted
		void setUnpaidTaken(double h) { unpaidTaken.setHours(h); }		// Sets Unpaid Hours used

		// calcMaxFromMonths Function
		//	Employees get 12 hrs vacation / 8 hrs sick leave PER Month
		//	Uses time employee worked in months (int)
		//		Use if statement / Vacation CAPPED AT 240.0 hrs
		void calcMaxFromMonths(int months)
		{
			if (months < 0)
				months = 0;

			double vacHours = months * 12.0;	// Gets Vacation Hours
			double sickHours = months * 8.0;	// Gets Sick Hours

			if (vacHours > 240.0)
				vacHours = 240.0;				// Validates Vacation Hours allotted (Company Policy)

			setMaxVacationHours(vacHours);		// Calculates Vacation Hours allotted
			setMaxSickHours(sickHours);			// Calculates Sick Hours allotted
		}
};

// Main Function starts here
int main()
{
	// Step 1: Declare Input Variables
	//	Use name, id, month
	string name;
	int id;
	int months;

	// Step 2: Get name/id/months worked
	//	Display Personnel Title followed by separator line
	cout << "Personnel Search\n";
	cout << string(25, '-') << endl;

	cout << "Please enter an employee's name. " << endl;
	getline(cin, name);

	cout << endl;	// Breaking up for display

	cout << "Please enter the corresponding ID Number. " << endl;
	cin >> id;

	cout << endl; // Breaking up for display

	cout << "Please enter the number of months the employee has worked. " << endl;
	cin >> months;

	// Step 3: Create employee TimeOff Object then Calculate MAX Vacation/Sick Days
	//	Use emp for object name, takes name and id as parameters
	//	calcMaxFromMonths takes months as parameter
	TimeOff emp(name, id);
	emp.calcMaxFromMonths(months);

	// Step 4: Display Employee Days
	//	Format with setprecision() and fixed
	cout << fixed << setprecision(2);

	//	Display Summary Title then separator line
	cout << "\nEmployee Leave Summary\n";
	cout << string(25, '-') << endl;

	// Display employee searched
	cout << "Name: " << emp.getName() << endl;
	cout << "ID Number: " << emp.getId() << endl;
	cout << "Months Worked: " << months << endl;

	cout << endl; // Breaking up 

	// Display Vacation Hours/Days
	cout << "Vacation Leave Available" << endl;
	cout << "Days: " << emp.getMaxVacation().getDays() << endl;
	cout << "Hours: " << emp.getMaxVacation().getHours() << endl;

	cout << endl; // Breaking up

	// Display Sick Hours/Days
	cout << "Sick Leave Available" << endl;
	cout << "Days: " << emp.getMaxSickDays().getDays() << endl;
	cout << "Hours: " << emp.getMaxSickDays().getHours() << endl;

	// return 0
	return 0;
}
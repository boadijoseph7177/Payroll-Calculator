
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int empNo;              // Employee number
	double gross;			// gross pay for a given employee
	double stateTax;		// state tax for a given employee
	double fedTax;			// federal tax for a given employee
	double fica;			// FICA for a given employee
	double totGross = 0;	// total gross pay for all employees
	double totState = 0;	// total state tax for all employees
	double totFed = 0;	// total federal tax for all employees
	double totFica = 0;	// total FICA for all employees
	double totNet = 0;	// total net pay for all employees

	cout << "Enter employee information:\n";
	cout << " Employee Number (0 to quit): ";
	cin >> empNo;      // input employee number; priming read
	while (empNo < 0) { 	// validate employee number
		cout << "Employee number cannot be less than zero\n";
		cout << " Re-enter employee number (0 to quit): ";
		cin >> empNo;
	} // endwhile

	while (empNo != 0) { // get and validate other employee payroll information
		cout << " Gross pay: $";
		cin >> gross;		// input gross pay
		while (gross < 0.0) {		// validate gross pay
			cout << "Gross pay may not be less than zero.\n";
			cout << " Re-enter Gross pay: $";
			cin >> gross;
		} // endwhile
		cout << " Federal Withholding: $";
		cin >> fedTax;		// get federal withholding
		while (fedTax < 0.0 || fedTax > gross) { 		// validate federal withholding 
			cout << "Federal withholding cannot be less than zero or exceed gross pay\n";
			cout << " Re-enter Federal Withholding: $";
			cin >> fedTax;
		} // endwhile
		cout << " State Withholding: $";
		cin >> stateTax;		// input state withholding
		while (stateTax < 0.0 || stateTax > gross) {  		// validate state withholding
			cout << "State withholding cannot be less than zero or exceed gross pay\n";
			cout << " Re-enter State Withholding: $";
			cin >> stateTax;
		} // endwhile
		cout << " FICA Withholding: $";
		cin >> fica;		// input FICA withholding
		while (fica < 0.0 || fica > gross) {  		// validate FICA withholding
			cout << "FICA withholding cannot be less than zero or exceed gross pay\n";
			cout << " Re-enter FICA Withholding: $";
			cin >> fica;
		} // endwhile
		// ensure total withholdings do not exceed the gross pay
		if ((fedTax + stateTax + fica) > gross) {
			cout << "\n*** ERROR: Total withholdings cannot exceed gross pay *** \n"
				<< "\n Re-enter the data for this employee\n";
		}
		else {      // add values to totals
			totGross += gross;
			totFed += fedTax;
			totState += stateTax;
			totFica += fica;
		} // endif
		cout << "\nProcessing the next employee:\n";
		cout << " Employee Number (0 to quit): ";
		cin >> empNo;      // input next employee number
		while (empNo < 0) { 	// validate employee number
			cout << "Employee number cannot be less than zero\n";
			cout << " Re-enter employee number (0 to quit): ";
			cin >> empNo;
		} // endwhile
	} // endwhile
	totNet = totGross - totFed - totState - totFica;	// total net pay

	cout << fixed << showpoint << setprecision(2) << endl;
	cout << " Total Gross Pay: \t$" << setw(8) << totGross << endl;
	cout << " Total Federal Tax: \t$" << setw(8) << totFed << endl;
	cout << " Total State Tax: \t$" << setw(8) << totState << endl;
	cout << " Total FICA: \t\t$" << setw(8) << totFica << endl;
	cout << " Total Net Pay: \t\t$" << setw(8) << totNet << endl;
	return 0;
}
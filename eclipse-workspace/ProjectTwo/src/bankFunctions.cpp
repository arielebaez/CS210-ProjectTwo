/*
 * Jeff Perkinson
 * CS-210-J3528
 * Feb 2020
 * Project Two Airgead Banking
 */

#include <iostream>             // Library needed for cin and cout objects
#include <stdexcept>            // Library needed for the runtime_error object to be
                                // thrown/caught in exception handling cases
#include <string>				// C++ string class library
#include "Investment.h"

/*
 * namespaces provide scope to certain identifiers to avoid ambiguity and collision
 * https://www.learncpp.com/cpp-tutorial/2-9-naming-collisions-and-an-introduction-to-namespaces/
 */
using namespace std;

/*
 * Function to prompt a user for numerical input and return the input
 * for storing in a variable to be passed into an investment object (e.g.
 * investment amount, monthly deposit, etc.)
 */
double getDouble(string t_prompt) {
	bool validEntry;			// flag to drive exception handling
	string userEntryAsString;	// store user input to convert to double
	double userEntry;			// store user input as double to return

	/*
	 * Exception handling to validate user entry.
	 * A do-while loop is used because the prompt
	 * should be displayed at least once and assume the user
	 * makes a valid selection. Don't initiate a loop until an exception is thrown.
	 */
	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			cout << t_prompt << endl;
			cin >> userEntryAsString;
			/*
			 * The stod method of the string class parses the string argument,
			 * interprets its content as a floating-point number, and returns the
			 * result of type double.
			 * http://www.cplusplus.com/reference/string/stod/
			 */
			userEntry = stod(userEntryAsString);
		}
		// Catch an invalid argument (e.g. user enters a string in lieu of double)
		catch (invalid_argument& excpt) {
            cout << "Invalid entry type, please enter a number." << endl << endl;
            validEntry = false;
        }
	} while (!validEntry);
	return userEntry;
}

/*
 * Function to prompt a user for investment amount and return it
 * for storing in a variable to be passed into an investment object.
 * Uses exception handling to ensure the investment amount is greater than zero.
 */
double inputInvestment(string t_prompt) {
	bool validEntry;			// flag to drive exception handling
	double investmentAmount;	// store and return the investment amount

	/*
	 * Standard exception handling do-while loop.  See getDouble()
	 * for additional details.
	 */
	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			investmentAmount = getDouble(t_prompt);
			if (investmentAmount <= 0) {
				throw runtime_error("Invalid entry. Please enter an amount greater than $0.");
			}
		}
		// Catch an investment amount 0 or less
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while(!validEntry);

	return investmentAmount;
}

/*
 * Function to prompt a user for deposit amount and return it
 * for storing in a variable to be passed into an investment object.
 * Uses exception handling to ensure the deposit is greater than zero.
 */
double inputDeposit(string t_prompt) {
	bool validEntry;			// flag to drive exception handling
	double depositAmount;		// store and return the deposit amount

	/*
	 * Standard exception handling do-while loop.  See getDouble()
	 * for additional details.
	 */
	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			depositAmount = getDouble(t_prompt);
			if (depositAmount <= 0) {
				throw runtime_error("Invalid entry. Please enter an amount greater than $0.");
			}
		}
		// Catch a deposit amount 0 or less
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while(!validEntry);

	return depositAmount;
}

/*
 * Function to prompt a user for an interest rate and return it
 * for storing in a variable to be passed into an investment object.
 * Uses exception handling to ensure the interest rate is not negative.
 */
double inputInterestRate(string t_prompt) {
	bool validEntry;			// flag to drive exception handling
	double interestRate;		// store and return the interest rate

	/*
	 * Standard exception handling do-while loop.  See getDouble()
	 * for additional details.
	 */
	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			interestRate = getDouble(t_prompt);
			if (interestRate < 0) {
				throw runtime_error("Invalid entry. Please enter a non-negative interest rate.");
			}
		}
		// Catch an interest rate less than 0
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while(!validEntry);

	return interestRate;
}

/*
 * Function to prompt a user for number of years and return it
 * for storing in a variable to be passed into an investment object.
 * Uses exception handling to ensure the number of years are 1 or more.
 */
double inputNumberYears(string t_prompt) {
	bool validEntry;			// flag to drive exception handling
	double numberYears;			// store and return the number of years

	/*
	 * Standard exception handling do-while loop.  See getDouble()
	 * for additional details.
	 */
	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			numberYears = getDouble(t_prompt);
			if (numberYears < 1) {
				throw runtime_error("Invalid entry. Please enter 1 year or more.");
			}
		}
		// Catch years less than 1
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while(!validEntry);

	return numberYears;
}

/*
 * Function to print horizontal borders
 */
void printHorizontalBorder(int length, char printChar) {
	for (int i = 0; i < length; ++i) {
			cout << printChar;
		}
}

/*
 * Function to display the investment attributes (e.g. amount, years interest).
 * Function uses overloading to determine output based on arguments provided
 * in the function call.  The version without parameters is intended for the
 * initial part of the program before any investment object is instantiated.
 * The Investment object is passed in by reference to avoid an additional
 * copy for performance savings and per the standards.
 * No object data members are manipulated or returned from this function.
 */
void printInvestmentSnapshot() {
	const int MENU_WIDTH = 35;			// Column width of the menu
	string menuTitle = "Data Input";	// menu title
	char menuChar = '*';
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2) - 1), menuChar);
	cout << " " << menuTitle << " ";
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2)), menuChar);
	cout << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years: " << endl;
}

void printInvestmentSnapshot(Investment& investment) {
	const int MENU_WIDTH = 35;			// Column width of the menu
	string menuTitle = "Data Input";	// menu title
	char menuChar = '*';
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2) - 1), menuChar);
	cout << " " << menuTitle << " ";
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2)), menuChar);
	cout << endl;
	cout << "Initial Investment Amount: $" << investment.getInvestmentAmount() << endl;
	cout << "Monthly Deposit: $" << investment.getMonthlyDeposit() << endl;
	cout << "Annual Interest: " << investment.getInterestRate() << "%" << endl;
	cout << "Number of Years: " << investment.getNumberYears() << endl;
}

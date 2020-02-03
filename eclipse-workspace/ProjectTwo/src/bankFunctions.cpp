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
#include <stdlib.h>
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

/*
 * Function to round float to 2 decimal places for menu outout.
 * Taken from https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
 */
float round(float var) {
    // 37.66666 * 100 = 3766.66
    // 3766.66 + .5 = 3767.16 for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

/*
 * Function to display growth output, both with and without a monthly deposit
 * amount accounted for.  The Investment object is passed in
 * by reference to avoid an additional copy for performance savings and per the standards.
 * No object data members are manipulated or returned from this function.
 */

void printGrowth(Investment& investment, bool withMonthly/* default is false */) {
	const int MENU_WIDTH = 64;
	const double MONTHS_IN_YEAR = 12.00;
	string menuTitleNoDeposit = "Balance and Interest - No Additional Deposits";
	string menuTitleWithDeposits = "Balance and Interest - With Additional Deposits";
	string menuTitle;
	if(withMonthly) {
		menuTitle = menuTitleWithDeposits;
	}
	else {
		menuTitle = menuTitleNoDeposit;
	}
	int menuTitleWhiteSpace = MENU_WIDTH - menuTitle.length();
	string subTitleOne = "Year";
	string subTitleTwo = "Interest Earned";
	string subTitleThree = "Year End Balance";
	int subTitlePadding = 2;
	const int ITEMIZED_ITEM_LENGTH = 10;
	const int subTitleWhiteSpace = 	MENU_WIDTH - ((ITEMIZED_ITEM_LENGTH * 3) + (subTitlePadding * 2));
	char menuChar = '=';
	char titleChar = ' ';
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	printHorizontalBorder((menuTitleWhiteSpace / 2), titleChar);
	cout << menuTitle;
	printHorizontalBorder((menuTitleWhiteSpace / 2), titleChar);
	cout << endl;
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	printHorizontalBorder(subTitlePadding, titleChar);
	cout << subTitleOne;
	printHorizontalBorder((subTitleWhiteSpace / 2), titleChar);
	cout << subTitleTwo;
	printHorizontalBorder((subTitleWhiteSpace / 2), titleChar);
	cout << subTitleThree;
	cout << endl;
	double begBalance = investment.getInvestmentAmount();
	for (int i = 0; i < investment.getNumberYears(); ++i) {
		int year = (i + 1);
		double interestRate = investment.getInterestRate() / 100.00;
		double interestEarned;
		double totalInterest;
		double endBalance;
		double monthEndBalance;
		if(withMonthly) {
			interestEarned = 0;
			totalInterest = 0;
			interestRate = interestRate / MONTHS_IN_YEAR;
			for (int i = 0; i < MONTHS_IN_YEAR; ++i) {
				// Assumes deposit is made at the beginning of the month
				begBalance += investment.getMonthlyDeposit();
				interestEarned = (begBalance * (1 + interestRate)) - begBalance;
				monthEndBalance = begBalance + interestEarned;
				begBalance = monthEndBalance;
				totalInterest += interestEarned;
			}
		}
		else {
			totalInterest = (begBalance * (1 + interestRate)) - begBalance;
		}
		if(withMonthly) {
			endBalance = begBalance;
		}
		else {
			endBalance = begBalance + totalInterest;
		}
		/*
		 *  using to_string() to convert numerical values to a string causes an error
		 *  that appears to be a compiler bug, with the best solution being to
		 *  downgrade the compiler.
		 *  https://stackoverflow.com/questions/43294488/mingw-g-multiple-definition-of-vsnprintf-when-using-to-string
		 *  So instead I convert to a string using itoa from stdlib
		 *  http://www.cplusplus.com/reference/cstdlib/itoa/
		 */
		char buffer [20];
		string yearString;
		yearString = itoa((year), buffer, 10);
		string endBalanceString;
		endBalanceString = itoa((endBalance), buffer, 10);
		string totalInterestString;
		totalInterestString = itoa((totalInterest), buffer, 10);
		int padding = 2;
		int growthOutputWhiteSpace = 	MENU_WIDTH - (yearString.length()
										+ endBalanceString.length() + totalInterestString.length()
										+ (padding * 2));
		printHorizontalBorder(padding, titleChar);
		cout << year;
		printHorizontalBorder((growthOutputWhiteSpace / 2), titleChar);
		cout << totalInterest;
		//FIXME: Why is this needed?
		if((i + 1) >= 10) {
			printHorizontalBorder(((growthOutputWhiteSpace / 2) - 1), titleChar);
		}
		else {
			printHorizontalBorder((growthOutputWhiteSpace / 2), titleChar);
		}
		cout << endBalance;
		cout << endl;
		begBalance = endBalance;
	}
}

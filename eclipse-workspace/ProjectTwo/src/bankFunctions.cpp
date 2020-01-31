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

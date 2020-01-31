/*
 * Jeff Perkinson
 * CS-210-J3528
 * Feb 2020
 * Project Two Airgead Banking
 */

/*
 * Per the standards, all header files should have #define guards to prevent
 * multiple inclusion.  The format of the symbol name should be
 * <PROJECT>_<PATH>_<FILE>_H_.  To guarantee uniqueness, they should be
 * based on the full path in a project's source tree.
 */

#ifndef PROJECTTWO_SRC_BANKFUNCTIONS_H_
#define PROJECTTWO_SRC_BANKFUNCTIONS_H_

/*
 * The namespaces below are scoped to the specific function declarations
 * Using 'namespace std' is considered bad practice, particularly
 * in a header file that can potentially be used in multiple other files
 * https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice
 */

double getDouble(std::string t_prompt);			// Capture user input to pass to investment setters
double inputInvestment(std::string t_prompt);	// Capture investment amount from the user
double inputDeposit(std::string t_prompt);		// Capture the monthly deposit amount from the user
double inputInterestRate(std::string t_prompt);	// Capture the interest rate from the user
double inputNumberYears(std::string t_prompt);	// Capture the number of years from the user

#endif /* PROJECTTWO_SRC_BANKFUNCTIONS_H_ */

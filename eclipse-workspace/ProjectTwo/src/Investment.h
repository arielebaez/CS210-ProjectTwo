/*
 * Jeff Perkinson
 * CS-210-J3528
 * Feb 2020
 * Project Two Airgead Banking
 */

/* The header file contains the class definition, including
 * data members (fields) and member function declarations (method signatures).
 * (Programming Languages, ZyBooks, 7.8: Separate files for classes)
 */

/*
 * Per the standards, all header files should have #define guards to prevent
 * multiple inclusion.  The format of the symbol name should be
 * <PROJECT>_<PATH>_<FILE>_H_.  To guarantee uniqueness, they should be
 * based on the full path in a project's source tree.
 */

#ifndef PROJECTTWO_SRC_INVESTMENT_H_
#define PROJECTTWO_SRC_INVESTMENT_H_

// Define the Investment class
class Investment {
	// Public members, customarily member functions, are accessible outside of the class.
	public:


	// Private members, customarily data members, are accessible only within the class itself.
	private:
		/* Type double has been chosen to store the numeric variables pertaining
		 * to the investment class and application.  Types double are, to this point,
		 * in my studies, the best known data type type for representing currency and
		 * interest rates (i.e. percentages or fractions).  The variable representing
		 * the number of years is also type double to avoid potential truncation issues.
		 * Storing the number of years as a double (e.g. 12.0 in lieu of 12) should have
		 * no impact on interest calculations.
		 * Making every variable the same type also eases capturing user input.  A
		 * single function can be built to prompt the user for input, capture, and
		 * return the input provided, all of the same type.
		 */
		double m_investmentAmount;
		double m_monthlyDeposit;
		double m_interestRate;
		double m_numberYears;
};



#endif /* PROJECTTWO_SRC_INVESTMENT_H_ */

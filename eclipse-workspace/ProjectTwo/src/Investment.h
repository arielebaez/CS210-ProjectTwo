/*
 * Jeff Perkinson
 * CS-210-J3528
 * Feb 2020
 * Project Two Airgead Banking
 */

/*
 * The header file contains the class definition, including
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
		/*
		 * Constructors.  Method overloading is employed to allow two constructors-
		 * the default and parameterized constructor.  When no constructor is defined,
		 * a default, no-parameter constructor is called that initializes member
		 * fields to the default value for their corresponding types.  If a parameterized
		 * overloaded constructor is defined, a default should be defined as well.
		 * The compiler will no longer implicitly define the default constructor,
		 * so it must be explicitly defined. Additionally, its good to define a
		 * default constructor for the investment object that initializes the
		 * member fields to logical default values
		 * (e.g. m_numberYears should be at least 1 and not 0 as 0 defeats
		 * the purpose of investing.)
		 */
		// Default Constructor
		Investment();

		// Parameterized Constructor
		/*
		 * The program allows users to examine investments utilizing both
		 * additional monthly deposits and no additional monthly deposits.
		 * As such, capturing a deposit amount for object creation will
		 * be optional, so that parameter should have a default value of 0.
		 * When default value parameters are mixed with non-default value
		 * parameters in the function definition, the default value parameters
		 * should be listed last, as arguments correspond to order of placement
		 * in the function call.  Sandwiching default value parameters in-between
		 * non-default value parameters can lead to errors.
		 */
		Investment(double t_investmentAmount, double t_interestRate, double t_numberYears, double t_monthlyDeposit=0);

		/*
		 * FIXME: Destructor discussion and definition
		 */

		/*
		 * Setters and Getters promote encapsulation by restricting direct access
		 * to the class' data members from outside users of the class (e.g. main.cpp).
		 * Getters return the value of the data member but do not modify member values,
		 * while setters allow for manipulation of the data member's value.
		 * Setters can use exception handling techniques
		 * to validate the input and ensure the class is not put in a corrupt state.
		 */

		// Getters
		/*
		 * Getters are usually defined as const to make clear that the data members
		 * won't be changed.  This also promotes secure coding, as the compiler
		 * will throw an error if the function modifies a data member (Programming Languages,
		 * ZyBooks, 7.5: Mutators, accessors, private helpers).
		 */
		double getInvestmentAmount() const;
		double getMonthlyDeposit() const;
		double getInterestRate() const;
		double getNumberYears() const;

		// Setters
		/*
		 * Per the standards, function parameters are named with a t_ prefix
		 * to distinguish function parameters from other variables
		 */
		void setInvestmentAmount(double t_investmentAmount);
		void setMonthlyDeposit(double t_monthlyDeposit);
		void setInterestRate(double t_interestRate);
		void setNumberYears(double t_numberYears);

	// Private members, customarily data members, are accessible only within the class itself.
	private:
		/*
		 * Type double has been chosen to store the numeric variables pertaining
		 * to the investment class and application.  Types double are, to this point,
		 * in my studies, the best known data type type for representing currency and
		 * interest rates (i.e. percentages or fractions).  The variable representing
		 * the number of years is also type double to avoid potential truncation issues.
		 * Storing the number of years as a double (e.g. 12.0 in lieu of 12) should have
		 * no impact on interest calculations.
		 * Making every variable the same type also eases capturing user input.  A
		 * single function can be built to prompt the user for input, capture, and
		 * return the input provided, all of the same type.
		 * Per the standards, private data members are named with an m_ prefix to distinguish
		 * them from public data. The m_ stands for "member" data.
		 */
		double m_investmentAmount;
		double m_monthlyDeposit;
		double m_interestRate;
		double m_numberYears;
};

#endif /* PROJECTTWO_SRC_INVESTMENT_H_ */

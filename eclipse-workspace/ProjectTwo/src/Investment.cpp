/*
 * Jeff Perkinson
 * CS-210-J3528
 * Feb 2020
 * Project Two Airgead Banking
 */


/*
 * A file that uses the class must include the .h file.  Its contents are
 * sufficient to allow compilation, as long as the corresponding .cpp file
 * is compiled into the program too.
 * (Programming Languages, ZyBooks, 7.8: Separate files for classes)
 */
#include "Investment.h"

// Constructors - see Investment.h for detailed discussion
Investment::Investment() {
	m_investmentAmount = 0;
	m_monthlyDeposit = 0;
	m_interestRate = 0;
	m_numberYears = 1;
}

Investment::Investment(double t_investmentAmount, double t_interestRate, double t_numberYears, double t_monthlyDeposit /* default = 0 */) {
	m_investmentAmount = t_investmentAmount;
	m_monthlyDeposit = t_monthlyDeposit;
	m_interestRate = t_interestRate;
	m_numberYears = t_numberYears;
}

// Destructor - see Investment.h for detailed discussion


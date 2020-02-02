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
/*
 * The default constructor initializes the data members to logical default
 * values.  Since the data members are pointer types, the '*' must prefix
 * the data member identifier to dereference the pointer and set the actual
 * value of the heap variable the pointer references.
 */
Investment::Investment() {
	m_investmentAmount = 0;
	m_monthlyDeposit = 0;
	m_interestRate = 0;
	m_numberYears = 1;
}

/*
 * The parameterized constructor initializes the data members to the argument
 * values passed in by the class user.
 */
Investment::Investment(double t_investmentAmount, double t_interestRate, double t_numberYears, double t_monthlyDeposit /* default = 0 */) {
	m_investmentAmount = t_investmentAmount;
	m_monthlyDeposit = t_monthlyDeposit;
	m_interestRate = t_interestRate;
	m_numberYears = t_numberYears;
}

// Getters
double Investment::getInvestmentAmount() const {
	return m_investmentAmount;
}

double Investment::getMonthlyDeposit() const {
	return m_monthlyDeposit;
}

double Investment::getInterestRate() const {
	return m_interestRate;
}

double Investment::getNumberYears() const {
	return m_numberYears;
}

// Setters
void Investment::setInvestmentAmount(double t_investmentAmount) {
	this->m_investmentAmount = t_investmentAmount;
}

void Investment::setMonthlyDeposit(double t_monthlyDeposit) {
	this->m_monthlyDeposit = t_monthlyDeposit;
}

void Investment::setInterestRate(double t_interestRate) {
	this->m_interestRate = t_interestRate;
}

void Investment::setNumberYears(double t_numberYears) {
	this->m_numberYears = t_numberYears;
}

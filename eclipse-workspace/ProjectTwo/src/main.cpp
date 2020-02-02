/*
 * Jeff Perkinson
 * CS-210-J3528
 * Feb 2020
 * Project Two Airgead Banking
 */

#include <iostream>

/*
 * A file that uses the class must include the .h file.  Its contents are
 * sufficient to allow compilation, as long as the corresponding .cpp file
 * is compiled into the program too.
 * (Programming Languages, ZyBooks, 7.8: Separate files for classes)
 */
//FIX BELOW COMMENTS:
//The data members are pointer types.  The class constructors allocate memory
//		 * for true values at object instantiation.  Using pointers promotes memory preservation
//		 * and program efficiency, as calls to methods utilizing these data members
//		 * operate on the heap value pointed to by the data member in lieu of a separate
//		 * stack copy that occupies additional memory.
//		 * Smart pointers are used in lieu of standard pointers to promote safety and prevention
//		 * of memory leaks.  Smart pointers are used to make sure that an object is deleted if it
//		 * is no longer used.  Smart pointers are wrappers that eliminate the need for
//		 * explicitly using 'new' and 'delete' keywords, which are handled automatically.
//		 * Unique pointers are used here as they are the preferred type of smart pointer.
//		 * They are a scope pointer- once the pointer is out of scope it is automatically deleted.
//		 * (SMART POINTERS in C++ https://www.youtube.com/watch?v=UOB7-B2MfwA)

#include "Investment.h"
#include "bankFunctions.h"

using namespace std;

int main() {

	Investment myInvestment(2500.23, 10.25, 25, 500.12);

	cout << "Initial Investment: " << myInvestment.getInvestmentAmount() << endl;
	cout << "Interest Rate: " << myInvestment.getInterestRate() << endl;
	cout << "Number of Years: " << myInvestment.getNumberYears() << endl;
	cout << "Monthly Deposit: " << myInvestment.getMonthlyDeposit() << endl;

	myInvestment.setMonthlyDeposit(1005.63);

	cout << "Initial Investment: " << myInvestment.getInvestmentAmount() << endl;
	cout << "Interest Rate: " << myInvestment.getInterestRate() << endl;
	cout << "Number of Years: " << myInvestment.getNumberYears() << endl;
	cout << "Monthly Deposit: " << myInvestment.getMonthlyDeposit() << endl;

	return 0;
}



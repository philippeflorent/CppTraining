#include "SalesData.h"
#include "Common.h"

/*!
* Function that calculates the averrage price of sold books
\retval int	average price
*/
double SalesData::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

/*!
* Function intended to act like the compound assignment operator, +=. The object on which this function is called represents the left-hand operand of the assignment. 
\param[in] rhs		The right-hand operand is passed as an explicit argument
\retval this		return instance
*/
SalesData& SalesData::combine(const SalesData& rhs)
{
	units_sold += rhs.units_sold; // add the members of rhs into
	revenue += rhs.revenue; // the members of ''this'' object
	return *this; // return the object on which the function was called
}

/*!
* Function that reads a book from istream
\param[in] is		input stream to read the book from
*/
/*SalesData::SalesData(std::istream& is)
{
	read(is, *this); // read will read a transaction from is into this object
}*/

// non member functions 

/*!
* Function that reads a SaleData book from cin

\param[in] is		input stream
\param[in] item		book to be populated
\retval ret			return same input stream
*/
istream& read(istream& is, SalesData& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

/*!
* Function that reads a SaleData book from cin

\param[in] os		output stream
\param[in] item		book to be printed out
\retval ret			return same output stream
*/
ostream& print(ostream& os, const SalesData& item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

/*!
* Function that takes two SalesData objects and returns a new SalesData representing their sum
*/
SalesData add(const SalesData& lhs, const SalesData& rhs)
{
	SalesData sum = lhs; // copy data members from lhs into sum
	sum.combine(rhs); // add data members from rhs into sum
	return sum;
}
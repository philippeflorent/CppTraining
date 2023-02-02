#pragma once

#include "Common.h"

class SalesData {
public:
	// friend declarations for nonmember SalesData operations added
	friend SalesData add(const SalesData&, const SalesData&);
	friend istream& read(istream&, SalesData&);
	friend ostream& print(ostream&, const SalesData&);
	// constructors added
	//SalesData() = default;
	//SalesData(const string& s) : bookNo(s) { }
	SalesData(const string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p* n) { }
	//SalesData(istream&);
	// remaining constructors all delegate to another constructor
	SalesData() : SalesData("", 0, 0) {}
	SalesData(std::string s) : SalesData(s, 0, 0) {}
	SalesData(std::istream& is) : SalesData()
	{
		read(is, *this);
	}
	// new members: operations on SalesData objects
	string isbn() const { return bookNo; }
	SalesData& combine(const SalesData&);
private:
	double avg_price() const;
	// data members are unchanged from § 2.6.1 (p. 72)
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// nonmember SalesData interface functions
SalesData add(const SalesData&, const SalesData&);
ostream& print(ostream&, const SalesData&);
istream& read(istream&, SalesData&);


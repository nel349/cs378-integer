// --------------------------
// projects/integer/Integer.h
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector
#include <string.h>    // vector
using namespace std;

// -----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
template <typename II, typename FI>
FI shift_left_digits (II b, II e, int n, FI x) {
	x = copy(b, e, x);
	//    FI y = x;
	//    advance(y, n);


	fill(x, x+n, 0);
	advance(x,n);


	return x;}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename FI>
FI shift_right_digits (II b, II e, int n, FI x) {
	x = copy(b, e-n, x);

	return x;}

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the sum of the two input sequences into the output sequence
 * ([b1, e1) + [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {

	int size = distance(b1, e1);
	int size2 = distance(b2, e2);

	int biggestSize= max(size, size2);
	FI y(x);
	bool flag = false;


	int extra = 1;
	int last = biggestSize;

	advance(x, biggestSize);
	while(e1 != b1 && e2 != b2){
		--e1;
		--e2;
		if(last == 1){
			int temp;
			if(flag)
				temp = (*e1  + *e2 + extra);
			else
				temp = (*e1  + *e2 );
			--x;
			*x=temp;
		}
		else if(flag){
			int temp = (*e1  + *e2 + extra) % 10;
			flag = false;
			--x;
			*x=temp;

		}
		else{
			int temp = (*e1  + *e2) % 10;
			--x;
			*x=temp;

		}
		if((*e1 + *e2)/10 == 1 ||  (*e1 + *e2) ==10 || (*e1 + *e2 + extra) ==10){
			flag = true;
		}
		--last;
	}
	while(e1 != b1){
		--e1;
		if(last == 1){
			int temp;
			if(flag)
				temp = (*e1  +  extra);
			else
				temp = (*e1  );
			--x;
			*x=temp;
		}
		else if(flag){
			int temp = (*e1  +  extra) % 10;
			flag = false;
			--x;
			*x=temp;

		}
		else{
			int temp = (*e1) % 10;
			--x;
			*x=temp;

		}
		if((*e1 )/10 == 1 ||  (*e1) ==10 || (*e1 + extra) ==10){
			flag = true;
		}
		--last;
	}

	while(e2 != b2){
		--e2;
		if(last == 1){
			int temp;
			if(flag)
				temp = (*e2  +  extra);
			else
				temp = (*e2  );
			--x;
			*x=temp;
		}
		else if(flag){
			int temp = (*e2  +  extra) % 10;
			flag = false;
			--x;
			*x=temp;

		}
		else{
			int temp = (*e2) % 10;
			--x;
			*x=temp;

		}
		if((*e2 )/10 == 1 ||  (*e2) ==10 || (*e2 + extra) ==10){
			flag = true;
		}
		--last;
	}


	if( to_string(x[0]).length() == 2){
		string first = to_string(x[0]);
		int f = (char)first[0] - '0';
		int s = (char)first[1]- '0';
		int n = 0;
		n = biggestSize;
		while(n > 0){
			y[n+1] = x[n];
			n--;
		}
		y[1] = s;
		y[0] = f;
		biggestSize = biggestSize +1;

	}

	advance(y, biggestSize);

	return y;}

// ------------
// minus_digits
// ------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the difference of the two input sequences into the output sequence
 * ([b1, e1) - [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {

	// <your code>
	return x;}

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the product of the two input sequences into the output sequence
 * ([b1, e1) * [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
	// <your code>
	return x;}

// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the division of the two input sequences into the output sequence
 * ([b1, e1) / [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
	// <your code>
	return x;}

// -------
// Integer
// -------

template < typename T, typename C = std::vector<T> >
class Integer {
	// -----------
	// operator ==
	// -----------

	/**
	 * <your documentation>
	 */
	friend bool operator == (const Integer& lhs, const Integer& rhs) {
		// <your code>
		return false;}

	// -----------
	// operator !=
	// -----------

	/**
	 * <your documentation>
	 */
	friend bool operator != (const Integer& lhs, const Integer& rhs) {
		return !(lhs == rhs);}

	// ----------
	// operator <
	// ----------

	/**
	 * <your documentation>
	 */
	friend bool operator < (const Integer& lhs, const Integer& rhs) {
		// <your code>
		return false;}

	// -----------
	// operator <=
	// -----------

	/**
	 * <your documentation>
	 */
	friend bool operator <= (const Integer& lhs, const Integer& rhs) {
		return !(rhs < lhs);}

	// ----------
	// operator >
	// ----------

	/**
	 * <your documentation>
	 */
	friend bool operator > (const Integer& lhs, const Integer& rhs) {
		return (rhs < lhs);}

	// -----------
	// operator >=
	// -----------

	/**
	 * <your documentation>
	 */
	friend bool operator >= (const Integer& lhs, const Integer& rhs) {
		return !(lhs < rhs);}

	// ----------
	// operator +
	// ----------

	/**
	 * <your documentation>
	 */
	friend Integer operator + (Integer lhs, const Integer& rhs) {
		return lhs += rhs;}

	// ----------
	// operator -
	// ----------

	/**
	 * <your documentation>
	 */
	friend Integer operator - (Integer lhs, const Integer& rhs) {
		return lhs -= rhs;}

	// ----------
	// operator *
	// ----------

	/**
	 * <your documentation>
	 */
	friend Integer operator * (Integer lhs, const Integer& rhs) {
		return lhs *= rhs;}

	// ----------
	// operator /
	// ----------

	/**
	 * <your documentation>
	 * @throws invalid_argument if (rhs == 0)
	 */
	friend Integer operator / (Integer lhs, const Integer& rhs) {
		return lhs /= rhs;}

	// ----------
	// operator %
	// ----------

	/**
	 * <your documentation>
	 * @throws invalid_argument if (rhs <= 0)
	 */
	friend Integer operator % (Integer lhs, const Integer& rhs) {
		return lhs %= rhs;}

	// -----------
	// operator <<
	// -----------

	/**
	 * <your documentation>
	 * @throws invalid_argument if (rhs < 0)
	 */
	friend Integer operator << (Integer lhs, int rhs) {
		return lhs <<= rhs;}

	// -----------
	// operator >>
	// -----------

	/**
	 * <your documentation>
	 * @throws invalid_argument if (rhs < 0)
	 */
	friend Integer operator >> (Integer lhs, int rhs) {
		return lhs >>= rhs;}

	// -----------
	// operator <<
	// -----------

	/**
	 * <your documentation>
	 */
	friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
		// <your code>
		return lhs << "0";}

	// ---
	// abs
	// ---

	/**
	 * absolute value
	 * <your documentation>
	 */
	friend Integer abs (Integer x) {
		return x.abs();}

	// ---
	// pow
	// ---

	/**
	 * power
	 * <your documentation>
	 * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
	 */
	friend Integer pow (Integer x, int e) {
		return x.pow(e);}

private:
	// ----
	// data
	// ----

	C _x; // the backing container
	// <your data>

private:
	// -----
	// valid
	// -----

	bool valid () const { // class invariant
		// <your code>
		return true;}

public:
	// ------------
	// constructors
	// ------------

	/**
	 * <your documentation>
	 */
	Integer (int value) {
		// <your code>
		assert(valid());}

	/**
	 * <your documentation>
	 * @throws invalid_argument if value is not a valid representation of an Integer
	 */
	explicit Integer (const std::string& value) {
		// <your code>
		if (!valid())
			throw std::invalid_argument("Integer::Integer()");}

	// Default copy, destructor, and copy assignment.
	// Integer (const Integer&);
	// ~Integer ();
	// Integer& operator = (const Integer&);

	// ----------
	// operator -
	// ----------

	/**
	 * <your documentation>
	 */
	Integer operator - () const {
		// <your code>
		return Integer(0);}

	// -----------
	// operator ++
	// -----------

	/**
	 * <your documentation>
	 */
	Integer& operator ++ () {
		*this += 1;
		return *this;}

	/**
	 * <your documentation>
	 */
	Integer operator ++ (int) {
		Integer x = *this;
		++(*this);
		return x;}

	// -----------
	// operator --
	// -----------

	/**
	 * <your documentation>
	 */
	Integer& operator -- () {
		*this -= 1;
		return *this;}

	/**
	 * <your documentation>
	 */
	Integer operator -- (int) {
		Integer x = *this;
		--(*this);
		return x;}

	// -----------
	// operator +=
	// -----------

	/**
	 * <your documentation>
	 */
	Integer& operator += (const Integer& rhs) {
		// <your code>
		return *this;}

	// -----------
	// operator -=
	// -----------

	/**
	 * <your documentation>
	 */
	Integer& operator -= (const Integer& rhs) {
		// <your code>
		return *this;}

	// -----------
	// operator *=
	// -----------

	/**
	 * <your documentation>
	 */
	Integer& operator *= (const Integer& rhs) {
		// <your code>
		return *this;}

	// -----------
	// operator /=
	// -----------

	/**
	 * <your documentation>
	 * @throws invalid_argument if (rhs == 0)
	 */
	Integer& operator /= (const Integer& rhs) {
		// <your code>
		return *this;}

	// -----------
	// operator %=
	// -----------

	/**
	 * <your documentation>
	 * @throws invalid_argument if (rhs <= 0)
	 */
	Integer& operator %= (const Integer& rhs) {
		// <your code>
		return *this;}

	// ------------
	// operator <<=
	// ------------

	/**
	 * <your documentation>
	 */
	Integer& operator <<= (int n) {
		// <your code>
		return *this;}

	// ------------
	// operator >>=
	// ------------

	/**
	 * <your documentation>
	 */
	Integer& operator >>= (int n) {
		// <your code>
		return *this;}

	// ---
	// abs
	// ---

	/**
	 * absolute value
	 * <your documentation>
	 */
	Integer& abs () {
		// <your code>
		return *this;}

	// ---
	// pow
	// ---

	/**
	 * power
	 * <your documentation>
	 * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
	 */
	Integer& pow (int e) {
		// <your code>
		return *this;}};

#endif // Integer_h

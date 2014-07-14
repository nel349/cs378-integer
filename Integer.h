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


bool zeroless_minus_mode = false;
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
	int distances = distance(b,e);
	cout << "distance: "<< distances << endl;
	if(n >= distances ){
		*x = 0;
		++x;
		return x;
	}
	else{
		x = copy(b, e-n, x);
	}


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
template <typename II1, typename II2, typename BI>
BI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, BI x) {

	int size = distance(b1, e1);
	int size2 = distance(b2, e2);

	int biggestSize= max(size, size2);
	BI y(x);
	bool flag = false;


	int extra = 1;
	int last = biggestSize;

	advance(x, biggestSize);
	while(e1 != b1 && e2 != b2){
		--e1;
		--e2;


		if(last == 1){
			int temp;
			if(flag){
				temp = (*e1  + *e2 + extra);
			}

			else{
				temp = (*e1  + *e2 );
			}	

			--x;
			*x=temp;
		}
		else if(flag){
			int temp = (*e1  + *e2 + extra) % 10;
			if(!(*e1  + *e2 + extra >= 10) ){
				flag = false;
			}

			--x;
			*x=temp;

		}
		else{
			int temp = (*e1  + *e2) % 10;
			--x;
			*x=temp;

		}

		if((*e1 + *e2)/10 == 1 ||  (*e1 + *e2) ==10 ){
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
template <typename II1, typename II2, typename BI>
BI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, BI x) {

	int size = distance(b1, e1);
	int size2 = distance(b2, e2);
	int biggestSize= max(size, size2);
	bool flag = false;
	bool flag_prev = false;
	int need_extra = 10;
	advance(x, biggestSize);
	int curr_e1 = *e1;
	int prev_e1 = 0;
	if( size < size2){

		swap(e1, e2);
		swap(b1, b2);
	}
	while(e1 != b1 && e2 != b2){
		--e1;
		--e2;

		curr_e1 = *e1;

		if( flag_prev){
			curr_e1 = prev_e1;
			flag_prev = false;
		}

		if(*e2 > *e1 && e1 != b1  &&  *e2 > curr_e1  ){
			--e1;
			prev_e1 = *e1 -1 ;
			++e1;
			flag = true;
			flag_prev =true;
		}

		int temp = 0;

		if(flag){
			flag = false;
			temp = ( need_extra + curr_e1 ) - *e2;

			--x;
			*x= temp;
		}
		else{
			temp =  curr_e1  - *e2;

			--x;
			*x= temp;
		}

	}

	while(e1 != b1){
		--e1;
		--x;
		if(flag_prev){
			*x = *e1 - 1;
		}
		else{
			*x = *e1;
		}

	}

	while(e2 != b2){
		--e2;
		--x;
		*x = -(*e2);
	}


	advance(x, biggestSize );

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
template <typename II1, typename II2, typename BI>
BI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, BI x) {
	vector< vector<int> > c(10);

	for(int i=0; i<10; ++i){

		II1 ew1 = e1;
		int extra = 0;
		int temp_t;
		vector<int> result;
		if(i == 0){
			result.push_back(0);
		}
		II1 bw1 = b1;
		while(bw1 != ew1){
			--ew1;
			temp_t =extra + (*ew1 * i);
			extra = 0;
			if(temp_t < 10){
				result.push_back(temp_t);
			}
			else{
				result.push_back(temp_t%10);
				extra = temp_t / 10;
			}
		}
		if(extra != 0){
			result.push_back(extra);
		}
		c[i] = result;
	}
	--e2;
	vector<int>::reverse_iterator p = c[*e2].rbegin();
	vector<int>::reverse_iterator e = c[*e2].rend();
	++e2;
	int size = distance(b2,e2);
	int size1 = distance(b1, e1);
	int t_size = size1 + size + 1;
	vector<int> t(t_size);
	int i=1;
	--e2;
	while( i<size){
		--e2;
		vector<int> temp(size1+1+i);
		vector<int>::iterator shifted_left = shift_left_digits (c[*e2].rbegin(), c[*e2].rend(), i, temp.begin());
		e = plus_digits(p, e, temp.begin(), shifted_left, t.rbegin());
		p = t.rbegin();
		++i;
	}

	x = copy(p, e, x);
	return x;
}





// -------
// Integer
// -------

template < typename T, typename C = std::vector<T> >
class Integer {



	// -----------
	// operator ==
	// -----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @return true if all elements / sign are equal. False otherwise
	 */
	friend bool operator == (const Integer& lhs, const Integer& rhs) {
		if(lhs.container.size() != rhs.container.size()){
			return false;
		}
		if(lhs.negative != rhs.negative){
			return false;
		}

		for(int i= 0 ; i < (int)rhs.container.size(); ++i){
			if(lhs.container[i] != rhs.container[i]){
				return false;
			}
		}

		return true;}

	// -----------
	// operator !=
	// -----------

	/**
	 @param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @return true if all elements / sign are equal. False otherwise
	 */
	friend bool operator != (const Integer& lhs, const Integer& rhs) {
		return !(lhs == rhs);}

	// ----------
	// operator <
	// ----------

	/**
	 *@param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @return true if all elements < sign are greater. False otherwise
	 */
	friend bool operator < (const Integer& lhs, const Integer& rhs) {
		if(lhs.negative == false && rhs.negative == true)
			return false;
		if(lhs.negative == true && rhs.negative == false)
			return true;

		typename C::const_iterator aP;
		typename C::const_iterator bP;

		if(lhs.negative == false && rhs.negative == false){

			if(lhs.container.size() < rhs.container.size()){
				return true;
			}

			if(lhs.container.size() > rhs.container.size()){
				return false;
			}

		}

		if(lhs.negative == true && rhs.negative == true){
			if(lhs.container.size() < rhs.container.size())
				return false;
			if(lhs.container.size() > rhs.container.size())
				return true;


		}
		aP = rhs.container.begin();
		bP = lhs.container.begin();

		while(aP != rhs.container.end()){
			if(*bP < *aP){
				return true;
			}
			else if (*bP > *aP ) {
				return false;	
			}
			++aP;
			++bP;
		}
		return false;


	}

	// -----------
	// operator <=
	// -----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @return true if all elements <= sign are less then equal. False otherwise
	 */
	friend bool operator <= (const Integer& lhs, const Integer& rhs) {
		return !(rhs < lhs);}

	// ----------
	// operator >
	// ----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @return true if all elements > sign are greater. False otherwise
	 */
	friend bool operator > (const Integer& lhs, const Integer& rhs) {
		return (rhs < lhs);}

	// -----------
	// operator >=
	// -----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @return true if all elements >= sign are greater than or equal. False otherwise
	 */
	friend bool operator >= (const Integer& lhs, const Integer& rhs) {
		return !(lhs < rhs);}

	// ----------
	// operator +
	// ----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @return the sum of lhs and rhs
	 */
	friend Integer operator + (Integer lhs, const Integer& rhs) {
		return lhs += rhs;}

	// ----------
	// operator -
	// ----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @return the difference of lhs minus rhs
	 */
	friend Integer operator - (Integer lhs, const Integer& rhs) {
		return lhs -= rhs;}

	// ----------
	// operator *
	// ----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @return the sum product lhs and rhs
	 */
	friend Integer operator * (Integer lhs, const Integer& rhs) {
		return lhs *= rhs;}

	// ----------
	// operator /
	// ----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @return the sum of lhs and rhs
	 * @throws invalid_argument if (rhs == 0)
	 */
	friend Integer operator / (Integer lhs, const Integer& rhs) {
		if(rhs ==0){
			throw std::invalid_argument("Invalid number 0");
		}
		return lhs /= rhs;}

	// ----------
	// operator %
	// ----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @throws invalid_argument if (rhs <= 0)
	 */
	friend Integer operator % (Integer lhs, const Integer& rhs) {
		if(rhs <=0){
			throw std::invalid_argument("Invalid number 0");
		}
		return lhs %= rhs;}

	// -----------
	// operator <<
	// -----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 * @throws invalid_argument if (rhs < 0)
	 */
	friend Integer operator << (Integer lhs, int rhs) {
		if(rhs < 0){
			throw std::invalid_argument("Invalid number 0");
		}
		return lhs <<= rhs;}

	// -----------
	// operator >>
	// -----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side	 * @throws invalid_argument if (rhs < 0)
	 */
	friend Integer operator >> (Integer lhs, int rhs) {
		if(rhs < 0){
			throw std::invalid_argument("Invalid number 0");
		}

		return lhs >>= rhs;}

	// -----------
	// operator <<
	// -----------

	/**
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 */
	friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
		if(rhs.negative){
			lhs << "-";
		}
		for(int i =0; i< (int)rhs.container.size() ; ++i){
			lhs << rhs.container[i];
		}

		return lhs;}

	// ---
	// abs
	// ---

	/**
	 * absolute value
	 * @param lhs left hand side of the operation
	 * @param rhs right hand side
	 */
	friend Integer abs (Integer x) {
		return x.abs();}

	// ---
	// pow
	// ---

	/**
	 * power
	 * @param x base
	 * @param e exponent integer
	 * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
	 */
	friend Integer pow (Integer x, int e) {
		return x.pow(e);}

public:
	// ----
	// data
	// ----

	// C _x; // the backing container

	C container;
	bool negative= false; //If negative -->true
	int size;



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
		int t_value = value;
		int sized = 0;



		if(value > 0){
			negative = false;
		}else if(value == 0){
			container.push_back(0);
			++size;

		}	
		else{
			negative = true;
			t_value = value * (-1);
			sized = to_string(t_value).size();
		}
		sized = to_string(t_value).size();
		int index = sized - 1;
		C c(sized, 0);
		while(t_value != 0){

			c[index] = t_value %10;

			t_value = t_value/10;
			++size;
			--index;
		}

		container = c;
		assert(valid());
	}

	Integer (){

	}

	/**
	 * @param value String value of Integer
	 * @throws invalid_argument if value is not a valid representation of an Integer
	 */
	explicit Integer (const std::string& value) {

		// bool isNegative = false;


		if( value[0] == '-'){

			container.resize((int)value.size() - 1);

			// cout << "THIS IS NEGATIVE " << endl;
			this->negative = true;
			int m =0;
			for(int i =1 ; i < (int)value.size(); ++i){
				if( isdigit(value[i]) ){
					// cout << value[i] << " ";
					container[m] = value[i] - '0';
					m++;
				}else{
					throw std::invalid_argument("Integer()");
				}
			}
		}
		else{

			container.resize((int)value.size());

			for(int i =0 ; i < (int)value.size(); ++i){
				if( isdigit(value[i]) ){
					// cout << value[i] << " ";
					container[i] = value[i] - '0';
				}else{
					throw std::invalid_argument("Integer()");
				}
			}
		}




		if (!valid())
			throw std::invalid_argument("Integer::Integer()");
	}

	// Default copy, destructor, and copy assignment.
	// Integer (const Integer&);
	// ~Integer ();
	// Integer& operator = (const Integer&);

	// ----------
	// operator -
	// ----------

	/**
	 * @param - subtract sign
	 *
	 */
	Integer operator - () const {
		Integer y = *this;
		if(negative){
			y.negative = false;
		}
		else{
			y.negative = true;
		}

		return y;}

	// -----------
	// operator ++
	// -----------

	/**
	 * @param pre-increment
	 */
	Integer& operator ++ () {
		*this += 1;
		return *this;}

	/**
	 * @param post-increment
	 */
	Integer operator ++ (int) {
		Integer x = *this;
		++(*this);
		return x;}

	// -----------
	// operator --
	// -----------

	/**
	 * @param pre-decrement
	 */
	Integer& operator -- () {
		*this -= 1;
		return *this;}

	/**
	 * @param post-decrement
	 */
	Integer operator -- (int) {
		Integer x = *this;
		--(*this);
		return x;}

	// -----------
	// operator +=
	// -----------

	/**
	 * @param plus-equal operator
	 */
	Integer& operator += (const Integer& rhs) {

		C result(this->container.size() + rhs.container.size());
		typename C::iterator ite;

		if(this->negative == true && rhs.negative == false){

		}
		else if(this->negative == false && rhs.negative == false){
			ite = plus_digits(this->container.rbegin(), this->container.rend(), rhs.container.rbegin(), rhs.container.rend(), result.begin());;
			negative = false;
		}
		else if(this->negative == false && rhs.negative == true){
		}
		else{
			ite = plus_digits(this->container.rbegin(), this->container.rend(), rhs.container.rbegin(), rhs.container.rend(), result.begin());
		}

		container = result;

		result.erase(ite, result.end());
		container.resize(result.size());


		return *this;
	}

	// -----------
	// operator -=
	// -----------

	/**
	 * @param minus-equal operator
	 */
	Integer& operator -= (const Integer& rhs) {
		zeroless_minus_mode = true;
		if(*this == rhs){
			container.clear();
			container.push_back(0);
			return *this;
		}
		Integer lhs = *this;
		C copy_my_Container(rhs.container.begin(), rhs.container.end());
		C result(lhs.container.size() + rhs.container.size());
		typename C::iterator ite_e;

		if(lhs.negative == false && rhs.negative == true)
			ite_e = plus_digits(lhs.container.begin(), lhs.container.end(), rhs.container.begin(), rhs.container.end(), result.begin());
		else if(lhs.negative == true && rhs.negative == false){
			ite_e = plus_digits(lhs.container.begin(), lhs.container.end(), rhs.container.begin(), rhs.container.end(), result.begin());
		}
		else if(lhs.negative == true && rhs.negative == true){
			if(rhs > lhs){
				ite_e = minus_digits(copy_my_Container.begin(), copy_my_Container.end(), lhs.container.begin(), lhs.container.end(), result.begin() );
				negative = false;
			}
			else{
				ite_e = minus_digits(lhs.container.begin(), lhs.container.end(), copy_my_Container.begin(), copy_my_Container.end(), result.begin());;

			}
		}
		else{

			// cout << "D" <<endl;
			if(rhs > lhs){
				ite_e = minus_digits(copy_my_Container.begin(), copy_my_Container.end(), lhs.container.begin(), lhs.container.end(), result.begin());
				negative = true;
			}else{
				// cout << "F" <<endl;
				ite_e = minus_digits(lhs.container.begin(), lhs.container.end(), copy_my_Container.begin(), copy_my_Container.end(), result.begin());
			}

		}

		result.erase(ite_e, result.end());

		typename C::iterator ite = result.begin();
		int cntz = 0;
		while(ite != result.end() ){
			if(*ite != 0){
				break;
			}
			cntz++;
			++ite;
		}
		ite = result.begin() + cntz;
		typename C::iterator itend = result.end();
		typename C::iterator itre = container.begin();
		C v(ite, itend);
		container.clear();
		container = v;


		zeroless_minus_mode = false;
		return *this;}

	// -----------
	// operator *=
	// -----------

	/**
	 * @param times-equal operator
	 */
	Integer& operator *= (const Integer& rhs) {
		C my_container(container.begin(), container.end());
		C copy_my_Container(rhs.container.begin(), rhs.container.end());
		C result(container.size() + rhs.container.size(), 0);
		typename C::iterator ite;
		ite= multiplies_digits(my_container.begin(), my_container.end(), copy_my_Container.begin(), copy_my_Container.end(), result.begin());


		result.erase(ite, result.end());
		container.resize(result.size());
		typename C::iterator ite_r = result.begin();
		typename C::iterator ite_c = container.begin();
		while( ite_r != result.end()){
			*ite_c = *ite_r;
			++ite_r;
			++ite_c;
		}

		return *this;}

	// -----------
	// operator /=
	// -----------

	/**
	 * @param divides-equal operator
	 * @throws invalid_argument if (rhs == 0)
	 */
	Integer& operator /= (const Integer& rhs);

	// -----------
	// operator %=
	// -----------

	/**
	 * @param modulus-equal operator
	 * @throws invalid_argument if (rhs <= 0)
	 */
	Integer& operator %= (const Integer& rhs) {
		Integer x = *this / rhs;

		Integer y = *this - (x * rhs);

		container = y.container;

		return *this;}

	// ------------
	// operator <<=
	// ------------

	/**
	 * @param lefshift-equal operator
	 */
	Integer& operator <<= (int n) {
		container.resize(*this.container.size() + n);
		typename C::reverse_iterator ite = shift_left_digits(*this.container.rbegin(), *this.container.rend(), n, container.rbegin());

		return *this;}

	// ------------
	// operator >>=
	// ------------

	/**
	 * @param rightshift-equal operator
	 */
	Integer& operator >>= (int n) {
		container.resize(*this.container.size() - n);
		typename C::reverse_iterator ite = shift_right_digits(*this.container.rbegin(), *this.container.rend(), n, container.rbegin());
		return *this;}

	// ---
	// abs
	// ---

	/**
	 * absolute value
	 * @param absolute value operator
	 */
	Integer& abs () {
		Integer x = *this;
		if( this->negative){
			this->negative = false ;
		}
		return *this;}

	// ---
	// pow
	// ---

	/**
	 * power
	 * @param power
	 * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
	 */
	Integer& pow (int e) {
		assert(e >= 0);	
		Integer n = *this;

		if (e == 0){
			Integer one = 1;
			*this = one;
			return *this;
		}
		int d = e/2;
		Integer p = this->pow(d);


		Integer q = p * p;

		if (e & 1){
			Integer w = q * n;

			*this = w;
			return *this;
		}

		*this = q;
		return *this;
	}


	void resize(int r){
		this->container.resize(r);
	}

	void add_digit(int r);

};





template < typename T, typename C >
void Integer<T, C>::add_digit(int r){
	if(  (int)container.size() == 1 && container[0] == 0 && r == 0){
		cout << "ENTRO AQUI NO SE AGREGO EL 0";
	}else{
		this->container.push_back(r);

	}
}


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
	bool flaggy = false;
	int divisor_size = distance(b2, e2);
	int dividend_size = distance(b1, e1);

	if(divisor_size > dividend_size){
		*x = 0;
		++x;
		return x;
	}

	typename vector<int>::iterator itedv;
	Integer<int> divisor = 0;
	divisor.resize(divisor_size);
	itedv = divisor.container.begin();


	while(b2 != e2){
		*itedv = *b2;
		++b2;
		++itedv;
	}

	typename vector<int>::iterator it_dnd;
	Integer<int> dividend;
	Integer<int> result;

	while(b1 != e1){
		dividend.add_digit(*b1);
		++b1;
		Integer<int> temp  = 0 ;
		Integer<int> n  = 0 ;
		Integer<int> difference  = 1 ;
		Integer<int> prev_temp = 1;
		if(divisor <= dividend  || dividend == 0 ){
			int cnt = 0;
			while( temp  <= dividend ) {
				n++;
				prev_temp = temp;
				temp = (n * divisor);
				cnt++;
			}
			flaggy =true;
			cnt--;
			difference = dividend - prev_temp;
			dividend =  difference;
			result.add_digit(cnt);
		}
		else if(flaggy){
			result.add_digit(0);
		}


	}

	x = copy(result.container.begin(), result.container.end(), x);


	return x;
}



// -----------
// operator /=
// -----------

/**
 * <your documentation>
 * @throws invalid_argument if (rhs == 0)
 */
template < typename T, typename C >
Integer<T,C>&  Integer<T, C>::operator /= (const Integer& rhs) {
	C my_container(container.begin(), container.end());
	C copy_my_Container(rhs.container.begin(), rhs.container.end());
	C result(container.size() + rhs.container.size(), 0);
	typename C::iterator ite;
	ite= divides_digits(my_container.begin(), my_container.end(), copy_my_Container.begin(), copy_my_Container.end(), result.begin());


	result.erase(ite, result.end());
	container.resize(result.size());



	typename C::iterator ite_r = result.begin();
	typename C::iterator ite_c = container.begin();


	while( ite_r != result.end()){
		*ite_c = *ite_r;
		++ite_r;
		++ite_c;
	}


	return *this;}


#endif // Integer_h

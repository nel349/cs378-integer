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
			if(flag){
				// cout << "A" << " ";
				temp = (*e1  + *e2 + extra);
			}

			else{
				// cout << "B" << " ";
				temp = (*e1  + *e2 );
			}	

			--x;
			*x=temp;
		}
		else if(flag){
			// cout << "C" << " ";
			int temp = (*e1  + *e2 + extra) % 10;
			if(!(*e1  + *e2 + extra >= 10) ){
				// cout << "ENTERS AFTER 0"<< " ";
				flag = false;
			}

			--x;
			*x=temp;

		}
		else{
			int temp = (*e1  + *e2) % 10;
			// cout << "D" << " ";
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
template <typename II1, typename II2, typename FI>
FI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {

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

	// std::vector<int> temp;


	advance(x, biggestSize );

	return x;}


void printVector(vector< vector<int> > v){
	for(int i =0; i < (int)v.size() ; ++i){

		for(int j =0; j < (int)v[i].size(); ++j){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

}




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
			temp_t = (*(ew1) * i) + extra;
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
	while( i<size){
		--e2;
		vector<int> temp((e1-b1)+1+i);
		vector<int>::iterator shifted_left = shift_left_digits (c[*(e2-1)].rbegin(), c[*(e2-1)].rend(), i, temp.begin());
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




	void status(std::vector<int> v){
		for(int i = 0; i <(int) v.size(); i++){
			cout << v[i] ;
		}
		cout << endl;
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
	friend FI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
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

		// cout << "THIS IS MY DIVISOR" << endl;
		// for(int i = 0; i <(int) divisor.container.size(); i++){
		// 	cout << divisor.container[i] ;
		// }
		// cout << endl;

		typename vector<int>::iterator it_dnd;
		Integer<int> dividend;
		// dividend.resize(dividend_size);
		// it_dnd = dividend.container.begin();

		Integer<int> result;

		while(b1 != e1){
			dividend.add_digit(*b1);
			++b1;
			// ++it_dnd;
			Integer<int> temp  = 0 ;
			Integer<int> n  = 0 ;
			Integer<int> difference  = 1 ;
			Integer<int> prev_temp = 1;

			// cout << "THIS IS MY n " << endl;
			// 		status(n);

			// cout << "THIS IS MY DIVIDEND on A" << endl;
			// for(int i = 0; i <(int) dividend.container.size(); i++){
			// 	cout << dividend.container[i] ;
			// }
			// cout << endl;

			if(divisor <= dividend  || dividend == 0 ){
				int cnt = 0;

				while( temp  <= dividend ) {
					// cout << "THIS IS MY n " << endl;
					// status(n);
					n++;
					prev_temp = temp;
					temp = (n * divisor);

					// cout << "THIS IS what I subtract: " ;
					// status(prev_temp);




					cnt++;
				}
				flaggy =true;
				cnt--;
				// cout << "THIS IS MY DIVIDEND: " ;
				// status(dividend);
				// cout << endl;

				difference = dividend - prev_temp;
				// cout << "THIS IS MY DIFFERENCE: " ;
				// status(difference);

				dividend =  difference;
				// dividend.add_digit(*b1);

				// cout << "THIS IS what my DIVIDEND becomes after adding : " << *b1 << endl ;
				// status(dividend);



				// cout << "THIS IS MY result" << endl;
				result.add_digit(cnt);
				// status(result);
				// return x;
			}
			else if(flaggy){
				result.add_digit(0);
			}


		}


		x = copy(result.container.begin(), result.container.end(), x);



		// cout << "THIS IS MY DIVIDEND" << endl;
		// for(int i = 0; i <(int) dividend.container.size(); i++){
		// 	cout << dividend.container[i] ;
		// }
		// cout << endl;



		// cout << "THIS IS MY result" << endl;
		// for(int i = 0; i <(int) result.container.size(); i++){
		// 	cout << result.container[i] ;
		// }
		// cout << endl;

		return x;
	}




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
		if(lhs.negative == false && rhs.negative == true)
			return false;
		if(lhs.negative == true && rhs.negative == false)
			return true;

		typename C::const_iterator beg;
		typename C::const_iterator end;

		if(lhs.negative == false && rhs.negative == false){

			if(lhs.container.size() < rhs.container.size()){
				return true;
			}

			if(lhs.container.size() > rhs.container.size()){
				return false;
			}

			beg = rhs.container.begin();
			end = lhs.container.begin();

		}

		if(lhs.negative == true && rhs.negative == true){
			if(lhs.container.size() < rhs.container.size())
				return false;
			if(lhs.container.size() > rhs.container.size())
				return true;

			beg = rhs.container.begin();
			end = lhs.container.begin();
		}


		while(beg != rhs.container.end()){
			if(*end < *beg){
				// cout << *end << "  " << *beg << endl;
				return true;
			}
			else if (*end > *beg ) {
				return false;	
			}
			// cout << *end << "  " << *beg << endl;	
			++beg;
			++end;
		}
		return false;


	}

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
			//			++size;
		}
		sized = to_string(t_value).size();
		int index = sized - 1;
		vector<int> c(sized, 0);
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

		bool vd = true;

		if( !isdigit(value[0] ) && value[0] != '-' ) {
			cout << "NOT VALID: " << value[0]<<endl;
			throw std::invalid_argument("Integer()");
			vd = false;
		}
		for(int i = 1; i < (int)value.size(); ++i){

			if( !isdigit(value[i] ) ) {
				cout << "NOT VALID: " << value[i]<<endl;
				throw std::invalid_argument("Integer()");
				vd = false;
			}
		}

		// istringstream(value) >> v;
		if(vd){
			cout << "VAlID: "<< atoi(value.c_str()) << endl;

			Integer<int> x(atoi(value.c_str()));
			x.negative = true;
		}


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

		C result(this->container.size() + rhs.container.size());
		typename C::iterator ite;

		if(this->negative == true && rhs.negative == false){
			// ite = minus_digits(this->container.rbegin(), this->container.rend(), rhs.container.rbegin(), rhs.container.rend(), result.begin());

		}
		else if(this->negative == false && rhs.negative == false){
			ite = plus_digits(this->container.rbegin(), this->container.rend(), rhs.container.rbegin(), rhs.container.rend(), result.begin());;
			negative = false;
		}
		else if(this->negative == false && rhs.negative == true){
			// ite = minus_digits(this->container.rbegin(), this->container.rend(), rhs.container.rbegin(), rhs.container.rend(), result.begin());
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
	 * <your documentation>
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

		// cout << "MY copy container" << endl;
		//       for(int i  =0 ; i< (int)copy_my_Container.size(); i++){
		//       	cout << copy_my_Container[i];
		//       }
		// cout <<  endl;

		C result(lhs.container.size() + rhs.container.size());
		typename C::iterator ite_e;

		if(lhs.negative == false && rhs.negative == true)
			ite_e = plus_digits(lhs.container.begin(), lhs.container.end(), rhs.container.begin(), rhs.container.end(), result.begin());
		else if(lhs.negative == true && rhs.negative == false){


			ite_e = plus_digits(lhs.container.begin(), lhs.container.end(), rhs.container.begin(), rhs.container.end(), result.begin());

		}
		else if(lhs.negative == true && rhs.negative == true){

			// cout << "C" <<endl;

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
				// cout << "RHS"<< rhs<< endl;

				// cout << "LHS"<< lhs<< endl;
				// cout << "E" <<endl;
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
			// cout << *ite << endl;
			cntz++;
			++ite;
		}

		ite = result.begin() + cntz;

		typename C::iterator itend = result.end();

		typename C::iterator itre = container.begin();





		std::vector<int> v(ite, itend);
		// container = copy(ite, itend, itre);
		//      cout <<"Number of zeroes to remove: "<< cntz << endl;
		// cout << "MY result container" << endl;
		//      for(int i  =0 ; i< (int)v.size(); i++){
		//      	cout << v[i];
		//      }
		// cout <<  endl;
		container.clear();
		container = v;


		zeroless_minus_mode = false;
		return *this;}

	// -----------
	// operator *=
	// -----------

	/**
	 * <your documentation>
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
	 * <your documentation>
	 * @throws invalid_argument if (rhs == 0)
	 */
	Integer& operator /= (const Integer& rhs) {
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

	// -----------
	// operator %=
	// -----------

	/**
	 * <your documentation>
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
	 * <your documentation>
	 */
	Integer& operator <<= (int n) {
		container.resize(*this.container.size() + n);
		typename C::reverse_iterator ite = shift_left_digits(*this.container.rbegin(), *this.container.rend(), n, container.rbegin());

		return *this;}

	// ------------
	// operator >>=
	// ------------

	/**
	 * <your documentation>
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
	 * <your documentation>
	 */
	Integer& abs () {
		Integer x = *this;
		//		for(int i=0; i < x.size; i++){
		//			cout << x.container[i]<< "-";
		//		}
		//		cout << endl;

		//		cout << "Negative? = " << x.negative<< endl;
		if( this->negative){
			//			cout << "Negative? = yes " << x.negative<< endl;
			this->negative = false ;
		}


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

		// Integer n = *this;
			// if(this == 0 && (e == 0) )
			// 	throw std::invalid_argument("Integer::pow(int)");

			// if(e < 0)
			// 	throw std::invalid_argument("Integer::pow(int)");

			// Integer result = 1;

			// if(e > 1)
			// 	result = n.pow(e/2); 

			// if(!(e & 1) )		// even
			// 	result *= result;
			// else{		// odd
			// 	result *= result;
			// 	result *= *this;
			// }

			// *this = result;
		Integer n = *this;

		if (e == 0){
			Integer one = 1;
			*this = one;
			return *this;
		}
		// Integer d = ee / 2;
		Integer p = n.pow(e / 2);
		

		Integer q = p * p;
		if (e & 1){
			Integer w = q * n;
			*this = w;
			return *this;
		}

		*this = q;
		return *this;}


	void resize(int r){
		this->container.resize(r);
	}

	void add_digit(int r){
		if(  (int)container.size() == 1 && container[0] == 0 && r == 0){
			cout << "ENTRO AQUI NO SE AGREGO EL 0";
		}else{
			this->container.push_back(r);

		}
	}
};








#endif // Integer_h

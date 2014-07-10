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

    advance(x, biggestSize );

	return x;}


void printVector(vector< vector<int> > v){
    for(int i =0; i < (int)v.size() ; ++i){

        for(int j =0; j < (int)v[0].size(); ++j){
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
	--e1;
	int first_value = *e1;
	++e1;
	--e2;
	int second_value = *e2;
	++e2;
	cout << "First Value = " <<  first_value << endl;

    int size = distance(b1, e1);
    int size2 = distance(b2, e2);

    if( size2 > size){
        swap(e1, e2);
        swap(b1, b2);
    }
  

    int biggestSize= max(size, size2);
    int smallestSize = min(size, size2);

    vector< vector<int> > sums ={};

    

    int last =0;
    II1 o_e1 = e1;
    // II1 o_b1 = b1;
    // II2 o_e2 = e2;
    // II2 o_b2 = b2;
    int temp_extra = 0;
    // int  i = 0;
    // int  j = 0;
    while(e1 != b1 && e2 != b2){
        vector<int> row = {};
        temp_extra = 0;// --e1;
        --e2;
        int temp = 0;
        last =biggestSize;
        // j=0;
        while(e1 != b1){
            --e1;
            temp = *e1 *  *e2;

            // if( last != 1)                        
            int re = (temp % 10) + temp_extra;
            
            if(re / 10  == 1){
                temp_extra = (*e1 *  *e2)/ 10 + 1;
                
                    re = (re % 10);
                
            }
            else{
                if(last != 1)
                    temp_extra = (*e1 *  *e2)/ 10;
            }
            if(last == 1){
                re = temp + temp_extra; 
                string s_re = to_string(re);
                cout << "THIS IS LAST : " << s_re << endl;
                if(s_re.size() == 2){
                	row.push_back( (int)((char)s_re[1] - '0') );  
                	row.push_back( (int)((char)s_re[0] - '0') );
                }
                else{
                	row.push_back(re);
                }
                         
            }
            else{
                row.push_back(re);
            }


            cout << "*e1:" << *e1 << " e2:" << *e2 << " = " << re << " and my number is : "<< temp_extra<<endl;

            --last;  
        }
        vector<int> r_row = row;
        reverse_copy(row.begin(), row.end(), r_row.begin() );
        sums.push_back(r_row);
        e1 = o_e1; 

        cout << endl;
    }

    int size_result;
    int t = first_value * second_value;

    if(( (size == 1 && size2 == 1)  && t < 10 ) ){
    	size_result = 1;
    }
    else if(( (size == 1 && size2 == 1)  && t > 10 )){
    	size_result = 2;

    }
    else if(smallestSize == 1){
    	size_result = biggestSize;
    }
    else{
    	size_result = (int)sums[0].size() + sums.size() - 1;
    }
 	int mm;
    if(smallestSize == 1){
    	mm = 0;
    }
    else if(smallestSize ==2){
    	mm =1;
    }
    else{
    	mm =2;
    }
    	

    cout << "THIS IS THE SIZE OF OF OUR RESULT " << size_result  << endl;



    printVector(sums);


    vector< vector<int>> result = {};
    // int m = size_result - sums.size() -1 - i;

   
    int m =mm;
    for(int i =0; i < (int)sums.size() ; i++){
    	vector<int> pad(size_result, 0);
    	
    	if(mm >=0){
    		m = mm--;
    	}	
    	cout << "m is : " << m << endl;
    	cout << "size_result: " << size_result << endl;
    	for(int j = 0; j < size_result && m < size_result - i; j++){
    		pad[m] = sums[i][j];
    		++m;
    	}

    	result.push_back(pad);
    	
    }	
	// int xx[size_result];
    printVector(result);
    // vector<int> final_result(size_result, 0);
    // int sum =0;







    // int x_sum[size_result];
    vector<int> temp(result[0]);
    vector<int> temp_r(size_result, 0);
    // x_sum= copy(result[0].begin(), result[0].end(), x_sum);
  
    for(int i = 0; i +1 < (int)result.size() ; ++i){
    	// x_sum = copy(xx.begin(), xx.end(), x_sum);

    	// plus_digits(temp.begin(), temp.end(), result[i+1].begin(), result[i+1].end(), temp_r.begin());
    	// x_sum= copy(xx.begin(), xx.end(), x_sum);
		plus_digits(temp.begin(), temp.end(), result[i+1].begin(), result[i+1].end(), temp_r.begin());
	
    	for (int i = 0; i < (int)temp_r.size(); i++ ){
    		cout << temp_r[i] << " "; 
    	}

    	temp = temp_r;
    	cout << endl;
    }

    copy(temp.begin(), temp.end(), x);


    for (int i = 0; i < 9; i++ ){
    		cout << x[i] << " "; 
    	}
	advance(x, size_result);
   
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
		vector<int> c(sized, 0);
		while(t_value != 0){
		
			c[index] = t_value %10;
				
			t_value = t_value/10;
			
			--index;
		}

		container = c;
		assert(valid());
	}

	/**
	 * <your documentation>
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

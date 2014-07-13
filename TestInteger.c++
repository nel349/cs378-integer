    // --------------------------------
// projects/integer/TestInteger.c++
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

/*
Google Test Libraries:
    % ls -al /usr/include/gtest/
    ...
    gtest.h
    ...

    % locate libgtest.a
    /usr/lib/libgtest.a

    % locate libpthread.a
    /usr/lib/x86_64-linux-gnu/libpthread.a
    /usr/lib32/libpthread.a

    % locate libgtest_main.a
    /usr/lib/libgtest_main.a

To compile the test:
    % g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Integer.c++ TestInteger.c++ -o TestInteger -lgtest -lgtest_main -lpthread

To run the test:
    % valgrind TestInteger

To obtain coverage of the test:
    % gcov-4.7 -b Integer.c++ TestInteger.c++
*/

// --------
// includes
// --------

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

#include "gtest/gtest.h"

#include "Integer.h"

// -----------
// TestInteger
// -----------

// -----------------
// shift_left_digits
// -----------------

TEST(Integer, shift_left_digits) {
    const int a[] = {2, 3, 4};
    const int b[] = {2, 3, 4, 0, 0};
          int x[10];
    const int* p = shift_left_digits(a, a + 3, 2, x);
    ASSERT_EQ(5, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}

// ------------------
// shift_right_digits
// ------------------

TEST(Integer, shift_right_digits) {
    const int a[] = {2, 3, 4};
    const int b[] = {2};
          int x[10];
    const int* p = shift_right_digits(a, a + 3, 2, x);
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}

TEST(Integer, shift_right_digits_1) {
    const int a[] = {2, 3, 4};
    const int b[] = {0};
          int x[10];
    const int* p = shift_right_digits(a, a + 3, 3, x);
    cout << x[0] << endl;
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, b));}

// -----------
// plus_digits
// -----------

TEST(Integer, plus_digits) {
    const int a[] = {2, 3, 4};
    const int b[] = {5, 6, 7};
    const int c[] = {8, 0, 1};
          int x[10];
    const int* p = plus_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(3, p - x);

   cout << x[0] << x[1] << x[2] << endl;
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


TEST(Integer, plus_digits_2) {
    const int a[] = {0, 0, 0};
    const int b[] = {0, 0, 0};
    const int c[] = {0, 0, 0};
          int x[10];
    const int* p = plus_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(3, p - x);

    // cout << x[0] << x[1] << x[2] << x[3] << endl;
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


TEST(Integer, plus_digits_3) {
    const int a[] = {9, 9, 9};
    const int b[] = {9, 9, 9};
    const int c[] = {1, 9, 9, 8};
          int x[10];
    const int* p = plus_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(4, p - x);

//    cout << x[0] << x[1] << x[2] << x[3] << endl;
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}



    TEST(Integer, plus_digits_4) {
    const int a[] = {9, 9, 9, 9};
    const int b[] = {9, 9, 9, 9};
    const int c[] = {1 ,9 ,9, 9, 8};
          int x[10];
    const int* p = plus_digits(a, a + 4, b, b + 4, x);
    ASSERT_EQ(5, p - x);

//    cout << x[0] << x[1] << x[2] << x[3] << endl;
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    TEST(Integer, plus_digits_5) {
    const int a[] = {9, 8, 7, 6};
    const int b[] = {2, 3, 4, 5};
    const int c[] = {1 ,2 ,2, 2, 1};
          int x[10];
    const int* p = plus_digits(a, a + 4, b, b + 4, x);
    ASSERT_EQ(5, p - x);

//    cout << x[0] << x[1] << x[2] << x[3] << endl;
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    TEST(Integer, plus_digits_6) {
    const int a[] = {9, 9, 9, 9};
    const int b[] = {1};
    const int c[] = {1 ,0 ,0, 0, 0};
          int x[10];
    const int* p = plus_digits(a, a + 4, b, b + 1, x);
    ASSERT_EQ(5, p - x);

   // cout << x[0] << x[1] << x[2] << x[3] <<x[4]  << endl;
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    TEST(Integer, plus_digits_7) {
    const int a[] = {1, 9, 9, 9};
    const int b[] = {1};
    const int c[] = {2 ,0 ,0, 0};
          int x[10];
    const int* p = plus_digits(a, a + 4, b, b + 1, x);
    ASSERT_EQ(4, p - x);

   // cout << x[0] << x[1] << x[2] << x[3] << endl;
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

    

    TEST(Integer, plus_digits_8) {
    const int b[] = {1, 9, 9, 9};
    const int a[] = {1};
    const int c[] = {2 ,0 ,0, 0};
          int x[10];
    const int* p = plus_digits(a, a + 1, b, b + 4, x);
    ASSERT_EQ(4, p - x);

    // cout << x[0] << x[1] << x[2] << x[3] << endl;
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    TEST(Integer, plus_digits_9) {
    const int b[] = {0, 0, 2, 2, 7, 1, 5, 6};
    const int a[] = {0, 1, 7, 0, 3, 6, 7, 0};
    const int c[] = {0, 1, 9, 3, 0, 8, 2, 6};
          int x[10];
    const int* p = plus_digits(a, a + 8, b, b + 8, x);
    ASSERT_EQ(8, p - x);

    cout << x[0] << x[1] << x[2] << x[3] << x[4] << x[5] << x[6]<< x[7] <<  endl;
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

TEST(Integer, plus_digits_10) {
    Integer<int> x = 1;
    Integer< int> y = 3;
        x++;
        x++;

        for(int i=0; i < (int)x.container.size(); i++){
          cout << x.container[i]<< "-";
        }
        cout << endl;
    ASSERT_TRUE(x==y);
  }




// ------------
// minus_digits
// ------------

TEST(Integer, minus_digits) {
    const int a[] = {8, 0, 1};
    const int b[] = {5, 6, 7};
    const int c[] = {2, 3, 4};
          int x[10];
    const int* p = minus_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(3, p - x);

    cout << x[0] << x[1] << x[2]  << endl;

    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}



TEST(Integer, minus_digits_1) {
    const int a[] = {8, 0, 0};
    const int b[] = {5, 2, 7};
    const int c[] = {2, 7, 3};
          int x[10];
    const int* p = minus_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(3, p - x);

    cout << x[0] << x[1] << x[2]  << endl;

    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}



TEST(Integer, minus_digits_2) {
    const int a[] = {7, 8, 9};
    const int b[] = {5, 6, 7};
    const int c[] = {2, 2, 2};
          int x[10];
    const int* p = minus_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(3, p - x);

    cout << x[0] << x[1] << x[2]  << endl;

    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


TEST(Integer, minus_digits_3) {
    const int a[] = {7, 8, 9};
    const int b[] = {5};
    const int c[] = {7, 8, 4};
          int x[10];
    const int* p = minus_digits(a, a + 3, b, b + 1, x);
    ASSERT_EQ(3, p - x);

    cout << x[0] << x[1] << x[2]  << endl;

    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


TEST(Integer, minus_digits_4) {
    const int a[] = {7, 8, 3};
    const int b[] = {9, 9};
    const int c[] = {6, 8, 4};
          int x[10];
    const int* p = minus_digits(a, a + 3, b, b + 2, x);
    ASSERT_EQ(3, p - x);

    cout << x[0] << x[1] << x[2]  << endl;

    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


TEST(Integer, minus_digits_5) {
const int a[] = {7, 8, 3, 2};
const int b[] =    {9, 9, 9};
const int c[] = {6, 8, 3, 3};
      int x[10];
const int* p = minus_digits(a, a + 4, b, b + 3, x);
ASSERT_EQ(4, p - x);

cout << x[0] << x[1] << x[2] << x[3]  << endl;

ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


TEST(Integer, minus_digits_6) {
const int a[] =    {3, 2};
const int b[] = {1, 0, 0};
const int c[] =    {0, 6, 8};
      int x[10];
const int* p = minus_digits(a, a + 2, b, b + 3, x);
ASSERT_EQ(3, p - x);

cout << x[0] << x[1] << x[2]  << endl;

ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


TEST(Integer, minus_digits_7) {
const int a[] = {1, 3, 2, 6};
const int b[] = {1, 1, 3, 4};
const int c[] = {0, 1, 9, 2};
      int x[10];
const int* p = minus_digits(a, a + 4, b, b + 4, x);
ASSERT_EQ(4, p - x);

cout << x[0] << x[1] << x[2]  <<  x[3]<<endl;

ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}



// -----------------
// multiplies_digits
// -----------------

TEST(Integer, multiplies_digits_1) {
    const int a[] = {2, 3, 4};
    const int b[] = {5, 6, 7};
    const int c[] = {1, 3, 2, 6, 7, 8};
          int x[10];
    const int* p = multiplies_digits(a, a + 3, b, b + 3, x);
    ASSERT_EQ(6, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

    TEST(Integer, multiplies_digits_2) {
    const int a[] = {2, 2};
    const int b[] = {2};
    const int c[] = {4,4};
          int x[10];
    const int* p = multiplies_digits(a, a + 2, b, b +1 , x);
    ASSERT_EQ(2, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    TEST(Integer, multiplies_digits_3) {
    const int a[] = {0};
    const int b[] = {0};
    const int c[] = {0};
          int x[10];
    const int* p = multiplies_digits(a, a + 1, b, b + 1, x);
//    cout << x[0] << x[1] << x[2]  << endl;
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    TEST(Integer, multiplies_digits_4) {
    const int a[] = {2};
    const int b[] = {8};
    const int c[] = {1,6};
          int x[10];
    const int* p = multiplies_digits(a, a + 1, b, b + 1, x);
//    cout << x[0] <<"   " <<x[1] << "  "<< x[2]<< endl;
    ASSERT_EQ(2, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    TEST(Integer, multiplies_digits_5) {
    const int a[] = {5, 6, 7, 8, 9};    
    const int b[] = {2, 3, 4};
    
    const int c[] = {1, 3, 2, 8, 8, 6, 2, 6};
          int x[10];
    const int* p = multiplies_digits(a, a + 5, b, b + 3, x);
    ASSERT_EQ(8, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    TEST(Integer, multiplies_digits_6) {
    const int a[] = {2, 3};
    const int b[] = {1};
    const int c[] = {2, 3};
          int x[10];
    const int* p = multiplies_digits(a, a + 2, b, b + 1, x);
//    cout << x[0] <<"   " <<x[1] << "  "<< endl;
    ASSERT_EQ(2, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    TEST(Integer, multiplies_digits_7) {
    const int a[] = {5, 6, 7};
    const int b[] = {2};
    const int c[] = {1, 1, 3, 4};
          int x[10];
    const int* p = multiplies_digits(a, a + 3, b, b + 1, x);

    for(int i =0 ; i < 4; i++){
      cout << x[i];
    }
    cout<< endl;

    ASSERT_EQ(4, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}



// -----------
// constructor
// -----------

TEST(Integer, constructor_1) {
    try {
        const Integer<int> x("abc");
        ASSERT_TRUE(false);}
    catch (std::invalid_argument& e) {
        ASSERT_STREQ("Integer()", e.what());}}

TEST(Integer, constructor_2) {
    try {
        const Integer<int> x("2");}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, constructor_3) {
    try {
        const Integer<int> x(2);}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}

TEST(Integer, constructor_4) {
    try {
        const Integer<int> x("-22");}
    catch (std::invalid_argument& e) {
        ASSERT_TRUE(false);}}


TEST(Integer, constructor_5) {
    try {
        const Integer<int> x("-3--");
       ASSERT_TRUE(false);}
    catch (std::invalid_argument& e) {
        ASSERT_STREQ("Integer()", e.what());}}



TEST(Integer, constructor_6) {
    
        const Integer<int> x(223);
  

    vector<int>  c {2,2,3};
    cout << x.container[0] << " " << x.container[1]  << " " << x.container[2] << endl;          

    // ASSERT_EQ(2, c - x);
    ASSERT_TRUE(std::equal(x.container.begin(), x.container.end(), c.begin()) );
}


TEST(Integer, constructor_7) {
    
        const Integer<int> x(-23443433);
  

    vector<int>  c {2,3,4,4,3,4,3,3};
    cout << x.container[0] << " " << x.container[1]  << " " << x.container[2] << endl;          

    // ASSERT_EQ(2, c - x);
    ASSERT_TRUE(std::equal(x.container.begin(), x.container.end(), c.begin()) );
}


// TEST(Integer, constructor_5) {
//     try {
//         const Integer<int> x("-3--");
//        ASSERT_TRUE(false);}
//     catch (std::invalid_argument& e) {
//         ASSERT_STREQ("Integer()", e.what());}}



// --------
// negation
// --------

 TEST(Integer, negation) {
     try {
         const Integer<int> x = 98765;
         const Integer<int> y = -x;

//         for(int i=0; i < y.size; i++){
//        	 cout << y.container[i]<< "-";
//         }
//         cout << endl;

         ASSERT_EQ(-98765, y);}
     catch (std::invalid_argument& e) {
         ASSERT_TRUE(false);}}

 TEST(Integer, negation_1) {
     try {
         const Integer<int> x = -1;
         const Integer<int> y = -x;

//         for(int i=0; i < y.size; i++){
//        	 cout << y.container[i]<< "-";
//         }
//         cout << endl;

         ASSERT_EQ(1, y);}
     catch (std::invalid_argument& e) {
         ASSERT_TRUE(false);}}


 TEST(Integer, negation_2) {
     try {
         const Integer<int> x = -765;
         const Integer<int> y = -x;

//         for(int i=0; i < y.size; i++){
//        	 cout << y.container[i]<< "-";
//         }
//         cout << endl;

         ASSERT_EQ(765, y);}
     catch (std::invalid_argument& e) {
         ASSERT_TRUE(false);}}




// ---
// abs
// ---

 TEST(Integer, abs_1) {
     try {
         Integer<int>  x = -98765;
         Integer<int>& y = x.abs();
         ASSERT_EQ(98765, x);
         ASSERT_EQ(&x,    &y);}
     catch (std::invalid_argument& e) {
         ASSERT_TRUE(false);}}
//
 TEST(Integer, abs_2) {
     try {
         Integer<int> x = -98765;
         Integer<int> y = abs(x);

//         cout << y.container[0] << " " << y.container[1] << endl;
         Integer<int> z = 98765;
         ASSERT_EQ(x, x);
         ASSERT_EQ( z, y);}
     catch (std::invalid_argument& e) {
         ASSERT_TRUE(false);}}

// --------
// equal_to
// --------

 TEST(Integer, equal_to) {
     try {
         const Integer<int> x = 98765;
         const Integer<int> y = 98765;
         ASSERT_EQ(      x, y);
     }
     catch (std::invalid_argument& e) {
         ASSERT_TRUE(false);}}



 TEST(Integer, equal_to_1) {
      try {
          const Integer<int> x = -765;
          const Integer<int> y = -765;
          ASSERT_EQ(      x, y);
      }
      catch (std::invalid_argument& e) {
          ASSERT_TRUE(false);}}



// ------
// output
// ------

 TEST(Integer, output) {
     try {
         const Integer<int> x = 98765;
         std::ostringstream out;
         out << x;
         ASSERT_EQ("98765", out.str());}
     catch (std::invalid_argument& e) {
         ASSERT_TRUE(false);}}



  TEST(Integer, plus_equal_1) {

    Integer<int> x = 0;

    Integer<int> y = 6;

    const Integer<int> z = 6;

    x += y;

    ASSERT_EQ(x, z);
  }


  TEST(Integer, plus_equal_2) {

    Integer<int> x = 3;

    Integer<int> y = 6;

    const Integer<int> z = 9;

    x += y;

    ASSERT_EQ(x, z);
  }
//
// Greater than
// 


  TEST(Integer, greater_than_1) {

    Integer<int> x = 43;

    Integer<int> y = 34;

    ASSERT_TRUE(x > y);
  }

  TEST(Integer, greater_than_2) {

    Integer<int> x = 3;

    Integer<int> y = 86;



    ASSERT_TRUE( x <  y);
  }


  TEST(Integer, greater_than_3) {

    Integer<int> x = 39999;

    Integer<int> y = 39998;



    ASSERT_TRUE( x >  y);
  }

    TEST(Integer, greater_than_5) {
      Integer<int> x  = 1326;

      Integer<int> y = 1134;

    ASSERT_FALSE( y > x);
  }


TEST(Integer, plus_plus) {
      
      Integer<int> max  = 7;

      Integer<int> c = 1;

      while( c != max){
        c++;
      }
      // for(int i = 0; i < (int)c.container.size(); ++i){
      //   cout << c.container[i];
      // }
      // cout << endl;
      ASSERT_TRUE(c == max);
  }

  // 
  //Less than
  //

 TEST(Integer, less_than_1) {

    Integer<int> x = 7;

    Integer<int> y = 7;

    ASSERT_FALSE( y < x);
  }




  TEST(Integer, less_than_2){
     Integer<int> max  = 7;

      Integer<int> c = 1;

      ASSERT_TRUE(c < max);
  }

  TEST(Integer, greater_than_4) {
      Integer<int> x  = 1326;

      Integer<int> y = 1134;

    ASSERT_FALSE( x  <  y);
  }


  // 
  // Multiplies equal
  // 
TEST(Integer, multiplies_equal) {
      
      Integer<int> x  = 7;

      Integer<int> y = 1;

      Integer<int> w = 7 ;

      Integer<int>  z= 7;
      Integer<int>  a= 49;

      w *= x;


      // for(int i = 0; i < (int)w.container.size(); ++i){
      //   cout << w.container[i];
      // }
      // cout << endl;
      // ASSERT_TRUE(x == (z * 1));

      ASSERT_TRUE(a == w);


  }

  TEST(Integer, multiplies_equal_2) {
      
      Integer<int> x  = 12;

      Integer<int> y = 4;

      Integer<int> z = 48;



      x *= y;


      // for(int i = 0; i < (int)x.container.size(); ++i){
      //   cout << x.container[i];
      // }
      // cout << endl;
      // ASSERT_TRUE(x == (z * 1));

      ASSERT_TRUE(x == z);


  }


    TEST(Integer, multiplies_integer_1) {
      
      Integer<int> x  = 567;

      Integer<int> y = 2;

      Integer<int> w =0;

      Integer<int> z =  1134;

      w = x * y;


      // for(int i = 0; i < (int)w.container.size(); ++i){
      //   cout << w.container[i];
      // }

      ASSERT_TRUE(w == z);


  }


// 
  // Minus 
  // 
TEST(Integer, minus_integer_1) {
      
      Integer<int> x  = 7;

      Integer<int> y = 3;

      Integer<int> actual = 0;

      Integer<int> expected = 4;

      actual = x - y;
      // for(int i = 0; i < (int)actual.container.size(); ++i){
      //   cout << actual.container[i];
      // }
      // cout << endl;
      ASSERT_TRUE(actual == expected);
  }


  TEST(Integer, minus_integer_2) {
      
      Integer<int> x  = 1326;

      Integer<int> y = 1134;

      Integer<int> actual = 0;

      Integer<int> expected = 192;

      actual = x - y;
      // for(int i = 0; i < (int)actual.container.size(); ++i){
      //   cout << actual.container[i];
      // }
      // cout << endl;
      ASSERT_TRUE(actual == expected);
  }


  // --------------
  // divides_digits
  // --------------


  TEST(Integer, divides_digits_1) {
      const int a[] = {1, 3};
      const int b[] = {5, 6, 7};
      const int c[] = {0};
            int x[10];
      const int* p = divides_digits(a, a + 2, b, b + 3, x);
      ASSERT_EQ(1, p - x);
      ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


  TEST(Integer, divides_digits_2) {
      const int a[] = {1, 3, 3};
      const int b[] = {5, 6, 7, 5};
      const int c[] = {0};
            int x[10];
      const int* p = divides_digits(a, a + 2, b, b + 4, x);
      ASSERT_EQ(1, p - x);
      ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}



      TEST(Integer, divides_digits_3) {
      const int a[] = {1, 3, 2, 6, 7, 8};
      const int b[] = {5, 6, 7};
      const int c[] = {2, 3, 4};
            int x[10];
      const int* p = divides_digits(a, a + 6, b, b + 3, x);
      ASSERT_EQ(3, p - x);
      ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}



      TEST(Integer, divides_digits_4) {
      const int a[] = {5,0,0,0};
      const int b[] = {2};
      const int c[] = {2,5,0,0};
            int x[4];
      const int* p = divides_digits(a, a + 4, b, b + 1, x);

      // cout << "MY final Result: ";
      // for(int i = 0 ; i < 4; i++){
      //   cout << x[i] << " ";
      // }
      // cout<< endl;

      ASSERT_EQ(4, p - x);
      ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    TEST(Integer, divides_digits_5) {
      const int a[] = {7, 8, 8, 8, 8};
      const int b[] = {3, 2, 3, 2};
      const int c[] = {2, 4};
            int x[10];
      const int* p = divides_digits(a, a + 5, b, b + 4, x);

      // cout << "MY final Result: ";
      // for(int i = 0 ; i < 4; i++){
      //   cout << x[i] << " ";
      // }
      // cout<< endl;

      ASSERT_EQ(2, p - x);
      ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}



      TEST(Integer, divides_digits_6) {
      const int a[] = {1, 3, 7, 9, 4, 8};
      const int b[] = {5, 7, 4};
      const int c[] = {2, 4, 0};
            int x[10];
      const int* p = divides_digits(a, a + 6, b, b + 3, x);

      cout << "MY final Result: ";
      for(int i = 0 ; i < 3; i++){
        cout << x[i] << " ";
      }
      cout<< endl;

      ASSERT_EQ(3, p - x);
      ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}




      TEST(Integer, divides_digits_7) {
      const int a[] = {5, 7, 4, 9, 7};
      const int b[] = {4, 8, 6, 3};
      const int c[] = {1, 1};
            int x[10];
      const int* p = divides_digits(a, a + 5, b, b + 4, x);

      cout << "MY final Result: ";
      for(int i = 0 ; i < 2; i++){
        cout << x[i] << " ";
      }
      cout<< endl;

      ASSERT_EQ(2, p - x);
      ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}



      TEST(Integer, divides_digits_8) {
      const int a[] = {2};
      const int b[] = {1};
      const int c[] = {2};
            int x[10];
      const int* p = divides_digits(a, a + 1, b, b + 1, x);

      cout << "MY final Result: ";
      for(int i = 0 ; i < 1; i++){
        cout << x[i] << " ";
      }
      cout<< endl;

      ASSERT_EQ(1, p - x);
      ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}




      TEST(Integer, divides_digits_9) {
      const int a[] = {1};
      const int b[] = {1};
      const int c[] = {1};
            int x[10];
      const int* p = divides_digits(a, a + 1, b, b + 1, x);

      cout << "MY final Result: ";
      for(int i = 0 ; i < 1; i++){
        cout << x[i] << " ";
      }
      cout<< endl;

      ASSERT_EQ(1, p - x);
      ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


      TEST(Integer, divides_digits_10) {
      const int a[] = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
      const int b[] = {2};
      const int c[] = {1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6};
            int x[20];
      const int* p = divides_digits(a, a + 18, b, b + 1, x);

      cout << "MY final Result: ";
      for(int i = 0 ; i < 18; i++){
        cout << x[i] << " ";
      }
      cout<< endl;

      ASSERT_EQ(18, p - x);
      ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

  




 





//   TEST(Integer, divides_digits_4) {
//       const int a[] = {1, 3, 2, 6, 7, 8};
//       const int b[] = {5, 6, 7};
//       const int c[] = {2, 3, 4};
//             int x[10];
//       const int* p = divides_digits(a, a + 6, b, b + 3, x);
//       ASSERT_EQ(3, p - x);
//       ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    // ASSERT_EQ(z, x);
// ---
// pow
// ---

// TEST(Integer, pow_1) {
//     try {
//         Integer<int>       x = 98765;
//         const int          e =  9867;
//         Integer<int>&      y = x.pow(e);
//         ASSERT_EQ(9867,  e);
//         ASSERT_EQ(   0,  x);
//         ASSERT_EQ(  &x, &y);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// TEST(Integer, pow_2) {
//     try {
//         const Integer<int> x = 98765;
//         const int          e =  9867;
//         const Integer<int> y = pow(x, e);
//         ASSERT_EQ(98765, x);
//         ASSERT_EQ( 9867, e);
//         ASSERT_EQ(    0, y);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

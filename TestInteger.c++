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
    cout << x[0] << x[1] << x[2]  << endl;
    ASSERT_EQ(1, p - x);
    ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}


    TEST(Integer, multiplies_digits_4) {
    const int a[] = {2};
    const int b[] = {8};
    const int c[] = {1,6};
          int x[10];
    const int* p = multiplies_digits(a, a + 1, b, b + 1, x);
    cout << x[0] <<"   " <<x[1] << "  "<< x[2]<< endl;
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

// --------------
// divides_digits
// --------------

// TEST(Integer, divides_digits) {
//     const int a[] = {1, 3, 2, 6, 7, 8};
//     const int b[] = {5, 6, 7};
//     const int c[] = {2, 3, 4};
//           int x[10];
//     const int* p = divides_digits(a, a + 6, b, b + 3, x);
//     ASSERT_EQ(3, p - x);
//     ASSERT_TRUE(std::equal(const_cast<const int*>(x), p, c));}

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





// ---
// abs
// ---

// TEST(Integer, abs_1) {
//     try {
//         Integer<int>  x = -98765;
//         Integer<int>& y = x.abs();
//         ASSERT_EQ(98765, x);
//         ASSERT_EQ(&x,    &y);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// TEST(Integer, abs_2) {
//     try {
//         const Integer<int> x = -98765;
//         const Integer<int> y = abs(x);
//         ASSERT_EQ(-98765, x);
//         ASSERT_EQ( 98765, y);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// --------
// equal_to
// --------

// TEST(Integer, equal_to) {
//     try {
//         const Integer<int> x = 98765;
//         const Integer<int> y = 98765;
//         ASSERT_EQ(      x, y);
//         ASSERT_EQ(      x, 98765);
//         ASSERT_EQ(  98765, x);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// --------
// negation
// --------

// TEST(Integer, negation) {
//     try {
//         const Integer<int> x = 98765;
//         const Integer<int> y = -x;
//         ASSERT_EQ(-98765, y);}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

// ------
// output
// ------

// TEST(Integer, output) {
//     try {
//         const Integer<int> x = 98765;
//         std::ostringstream out;
//         out << x;
//         ASSERT_EQ("98765", out.str());}
//     catch (std::invalid_argument& e) {
//         ASSERT_TRUE(false);}}

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

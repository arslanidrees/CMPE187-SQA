//==============================================================================
// Name        : cmpe187-proj1.cpp

// Author      : Arslan Idrees, Ritika Sengal, Jia Chen, Philip Nguyen
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : A solution to determine whether three integer inputs make a 
//				 triangle. If they do create a triangle, we further determine
//				 what type of triangle it is: scalene, isosceles or equialateral
// Definitions:
//	   Scalene -  All three lengths of the trianlge do not equal each other
//     Isosceles - Exactly two sides of the triangle are equal in length
//     Equilateral - All three lengths of the triangle are equal
//==============================================================================

#include <iostream>;
using namespace std;

// Function Prototypes 
bool isTriangle(int[]);
bool isScalene(int[]);
bool isIsosceles(int[]);
bool isEquilateral(int[]);
bool valid_input(int[]);
void testCase1();
void testCase2();

int main()
{
	// Run Tests
	testCase1();
	testCase2();

	int side[3];

	cout << "Hello, please enter in the three integer values for your triangle" << endl;
	
	// Input of three integers
	cout << "1st Number: ";
	cin >> side[0]; // x variable

	cout << "2nd Number: ";
	cin >> side[1]; // y variable

	cout << "3rd Number: ";
	cin >> side[2]; // z variable

	if (valid_input(side))
	{
		// Function call to check whether integer inputs
		// form a triangle.
		isTriangle(side);
	}
	else
	{
		cout << "The integer values entered are invalid for the sides of the triangle." << endl;
	}
	
	return 0;
}

// This function validates the user input by determining 
// if all the length inputs are greater than zero
bool valid_input(int side[])
{
	if (side[0] > 0 && side[1] > 0 && side[2] > 0)
		return true;
	else
		return false;
}

bool isTriangle(int side[])
{
	int sum1, sum2, sum3;

	sum1 = side[0] + side[1];
	sum2 = side[0] + side[2];
	sum3 = side[1] + side[2];

	if (sum1 < side[2] || sum2 < side[1] || sum3 < side[0])
	{
		// IF the sides do NOT form a triangle, output:
		cout << "The values entered can't form a triangle" << endl;
		return false;
	}
	else
	{
		// IF the sides DO form a triangle, 
		// conitinue to check what KIND of triangle
		isScalene(side);
		isIsosceles(side);
		isEquilateral(side);
		return true;
	}
}

bool isScalene(int side[])
{
	// All sides should NOT equal to each other
	if (side[0] != side[1] && side[1] != side[2] && side[0] != side[2])
	{
		cout << "Your values form a scalene triangle" << endl;
		return true;
	}
	else
		return false;
}

bool isIsosceles(int side[])
{
	// Exactly TWO SIDES of the triangle should be EQUAL
	if ((side[0] == side[1] && side[1] != side[2]) || (side[0] == side[2] && side[2] != side[1]) || (side[2] == side[1] && side[1] != side[0]))
	{
		cout << "Your values form an isosceles triangle" << endl;
		return true;
	}
	else
		return false;
	
}

bool isEquilateral(int side[])
{
	// ALL sides should be EQUAL to each other
	if (side[0] == side[1] && side[1] == side[2])
	{
		cout << "Your values form an equilateral triangle" << endl;
		return true;
	}
	else
		return false;
}

// Test case #1:
// Purpose: To test the valid_input function to make sure it recognizes
//			the presence of negative numbers and determines that they
//			cannot be used this program.
// Input: 3 negative integers
// Expected Outcome: false
void testCase1()
{
	int side[3] = { -3, -4, -5 };
	cout << valid_input(side) << endl;
}

// Test case #2:
// Purpose: To test the valid_input function to make sure it recognizes
//			and allows for postive numbers
// Input: 3 positive integers
// Expected Outcome: true
void testCase2()
{
	int side[3] = { 3, 4, 5 };
	cout << valid_input(side) << endl;
}
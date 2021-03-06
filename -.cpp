 //==============================================================================
// Name        : cmpe187-proj1.cpp

// Authors     : Arslan Idrees, Ritika Singhal, Jia Chen, Philip Nguyen
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
void isTriangle(int[]);
bool isScalene(int[]);
bool isIsosceles(int[]);
bool isEquilateral(int[]);
bool valid_input(int[]);

int main()
{
	{
		//The sides of a triangle
		int side[3] = {3.7, 4.9, 5.8};					//These values are changed for testing purposes.

		//Checking if the input is valid. If valid, then only proceed.
		if (valid_input(side))
		{
			// Function call to check whether integer inputs
			// form a triangle.
			isTriangle(side);
		}
		else
		{
			cout << "Invalid Input!" << endl;
		}
	}
	system("Pause");
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

//This function checks if the sides form a triangle.
//If the sides form a triangle, then it proceeds and calls other functions to
//check the type of the triangle.
void isTriangle(int side[])
{
	int sum1, sum2, sum3;

	sum1 = side[0] + side[1];
	sum2 = side[0] + side[2];
	sum3 = side[1] + side[2];

	if (sum1 <= side[2] || sum2 <= side[1] || sum3 <= side[0])
	{
		// IF the sides do NOT form a triangle, output:
		cout << "Not a triangle" << endl;
	}
	else
	{
		// IF the sides DO form a triangle, 
		// conitinue to check what KIND of triangle
		if (isScalene(side))
			return;
		if (isIsosceles(side))
			return;
		isEquilateral(side);
	}
}

//It checks if it is a scalene triangle
bool isScalene(int side[])
{
	// All sides should NOT be equal to each other
	if (side[0] != side[1] && side[1] != side[2] && side[0] != side[2])
	{
		cout << "Scalene triangle" << endl;
		return true;
	}
	else
		return false;
}

//It checks if it is an issoceles triangle
bool isIsosceles(int side[])
{
	// Exactly TWO SIDES of the triangle should be EQUAL
	if ((side[0] == side[1] && side[1] != side[2]) || (side[0] == side[2] && side[2] != side[1]) || (side[2] == side[1] && side[1] != side[0]))
	{
		cout << "Isosceles triangle" << endl;
		return true;
	}
	else
		return false;
	
}

//It checks if it is an equilateral triangle
bool isEquilateral(int side[])
{
	// ALL sides should be EQUAL to each other
	if (side[0] == side[1] && side[1] == side[2])
	{
		cout << "Equilateral triangle" << endl;
		return true;
	}
	else
		return false;
}

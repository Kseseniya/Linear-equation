#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ALL_SOLUTIONS -1 
#define NO_ROOTS 0
#define ONE_ROOT 1

int Linear_equation(double a, double b, double* x);
int ChekingZero(double value);

//! Print roots of linear equation
//! 
//! @param [in]	Num_roots	Number of roots of a linear equation					
//! @param[out]	x			The root of linear equation
//! 
//! @note In case the equation has no roots, the output is "No roots".
//! @note In case of infinite number of roots, the output is "Solutions are all numbers".
//! 
//! @attention If the coefficients are entered incorrectly, the output is "Error"

int main()
{
	printf("Enter a, b: ");

	double a = 0, b = 0;

	if (scanf_s("%lg  %lg", &a, &b) != 2)
	{
		printf("Error\n");
		return 0;
	}

	double x = 0;

	int Num_roots = Linear_equation(a, b, &x);

	assert(isfinite(x));

	switch (Num_roots)
	{
	case NO_ROOTS:
		printf("No roots\n");
		break;
	case ONE_ROOT:
		printf("x = %lg\n", x);
		break;
	case ALL_SOLUTIONS:
		printf("Solutions are all numbers\n");
		break;
	default:
		printf("main() : ERROR: Num_roots = %d\n ", Num_roots);
		break;
	}
	return 0;
}

//! Solves a linear equation
//! 
//! @param [in]		a	a-coefficient
//! @param [in]		b	b-coefficient
//! @param [out]	x	x-Pointer to the root
//! 
//! @return Number of roots
//! 
//! @note	In case of infinite number of roots
//!			returns ALL_SOLUTIONS 

int Linear_equation(double a, double b, double* x)
{
	assert(isfinite(a));
	assert(isfinite(b));

	if (ChekingZero(a))
	{
		if (ChekingZero(b))
		{
			return ALL_SOLUTIONS;
		}
		else
		{
			return NO_ROOTS;
		}
	}
	else
	{
		*x = (-b) / a;
		return ONE_ROOT;
	}
}

//! This function allows to compare values against zero
//!
//! @param[in] value   The value of the variable to be compared
//! 
//! @return 1 - if the condition is met, 0 - if the condition is not met

int ChekingZero(double value)
{
	return(fabs(value) <= 1e-5);
}
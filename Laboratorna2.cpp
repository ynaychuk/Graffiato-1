#include "stdafx.h"
#include <math.h>
#include <conio.h>

void tabForFunction1(double begin, double end, double step) {
	printf_s(" x  |\tresult\n----------------------------\n");
	double result;
	for (double x = begin; x <= end+step/2; x += step) {
		if (x < 2.3) {
			result = cos(x) + tan(x);
		}
		else
			if ((x >= 2.3) && (x < 2.7)) {
				result = 1 / tan(x) + sin(x);
			}
			else
				if (x > 2.7) {
					result = pow(x*log(x), 3);
				}
		printf_s("%.2lf|\t%lf\n", x, result);
	}
}

void tabForFunction2(double begin, double end, double step, double error) {
	int k;
	double sum;
	double result;
	
	printf_s(" x  |  k  | result   |  sum\n----------------------------\n");

	for (double x = begin; x <= end+step/2; x += step) {
		k = 0; result = 1; sum = 0;
		while (result> error) {
			result = x / ((2   * k - 1)*(2 * k + 3))*cos(2 * k + 1);
			sum += result;
			k++;
			result = fabs(result);
			 
		} ;
		printf_s("%.1lf |  %d  | %lf  %lf\n", x, k, result, sum);
		
	}
}
int main()
{
	double result, begin, end, step, error;

	printf_s("TASK 1:\n");
	printf_s("Enter begin=>");
	scanf_s("%lf", &begin);
	printf_s("Enter end=>");
	scanf_s("%lf", &end);
	printf_s("Enter step=>");
	scanf_s("%lf", &step);

	tabForFunction1(begin, end, step);
		
	printf_s("----------------------------\nTASK 2:\n");
	printf_s("Enter begin=>");
	scanf_s("%lf", &begin);
	printf_s("Enter end=>");
	scanf_s("%lf", &end);
	printf_s("Enter step=>");
	scanf_s("%lf", &step);
	printf_s("Enter error=>");
	scanf_s("%lf", &error);
	
	tabForFunction2(begin, end, step, error);
	
	_getche();
    return 0;
}


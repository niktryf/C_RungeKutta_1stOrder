/*******************************************************************
 *** RK4 Header file: 
 *** Functions for Runge-Kutta 4th order method for the solution of 
 *** 1st order ODEs.
 *** 
 *******************************************************************/

double RK4(double x, double y, double h, double (*F)(double, double));
double F(double x, double y);

/*******************************************************************
 *** Runge-Kutta 4th order method for the solution of 
 *** 1st order ODEs: 
 *** Runge-Kutta method function and "source" function.
 ***
 ***  Author: Nikos Tryfonidis, November 2015
 *** The MIT License (MIT)
 *** Copyright (c) 2015 Nikos Tryfonidis
 *** See LICENSE.txt
 *******************************************************************/
#include <stdio.h>
#include <math.h>

/* Right-hand side of differential equation 
   (enter desired function here) 
*/
double F(double x, double y) 
{
  return sqrt(x);
}

/*
  Runge - Kutta 4th order
  x : independent variable
  y : dependent variable
*/

double RK4(double x, double y, double h, double (*F)(double, double))
{
  int i;
  double ynew, k[4];
  
  k[0] = h*F(x, y);
  k[1] = h*F(x + 0.5*h, y + 0.5*k[0]);
  k[2] = h*F(x + 0.5*h, y + 0.5*k[1]);
  k[3] = h*F(x + h, y + k[2]);
  
  ynew = y + (1.0/6.0)*(k[0] + 2*k[1] + 2*k[2] + k[3]);
  
  return ynew;
}

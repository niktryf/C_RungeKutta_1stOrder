/*******************************************************************
 *** Runge-Kutta 4th order method for the solution of 
 *** 1st order ODEs: main source file.
 *** 
 *** Author: Nikos Tryfonidis, November 2015
 *** The MIT License (MIT)
 *** Copyright (c) 2015 Nikos Tryfonidis
 *** See LICENSE.txt
 *******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Headers ("headers" directory): */
#include "../headers/RK4.h"
#include "../headers/io.h"
#include "../headers/memory.h"

int main(int argc, char * argv[])
{
  int i, j, totalSteps, nOutput, interval;
  double h, length;
  double *x, *y;
  
  /* Get command line arguments */
  getArgs(argc, argv, &h, &length, &interval);
  
  /* Calculate total timesteps */
  totalSteps = length/h;
  printf("Total steps: %d\n", totalSteps);
  nOutput = totalSteps/interval+1;
  printf("Output size: %d points\n", nOutput);
  
  /* Allocate dependent and independent variable arrays */
  x = allocateDoubleArray1D(nOutput);
  y = allocateDoubleArray1D(nOutput);
  
  /*********************************/
  /*** ODE Solution              ***/
  /*********************************/
  
  /* Set Initial conditions here!  */
  x[0] = 0; y[0] = 1.0;  
  
  double x_old, y_old;
  x_old = x[0];
  y_old = y[0];
  
  /* Write solution every [interval] steps */
  for (i=1; i<nOutput; i++) {
    for(j=0;j<interval;j++) {
      x_old = x_old + h;
      y_old = RK4(x_old, y_old, h, F);
    }
    x[i] = x_old;
    y[i] = y_old; 
  }

  /* Write File Output */
  writeFileOutput (x, y, nOutput, "output/out.txt");
  
  /* Free Memory */
  free(x); free(y);
  
  return 0;
}


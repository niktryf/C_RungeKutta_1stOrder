/*******************************************************************
 *** Runge-Kutta 4th order method for the solution of 
 *** 1st order ODEs: Input and Output functions.
 *** 
 *** Author: Nikos Tryfonidis, November 2015
 *** The MIT License (MIT)
 *** Copyright (c) 2015 Nikos Tryfonidis
 *** See LICENSE.txt
 *******************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*
  Reads arguments and sets timestep, length and output interval from command line
*/
int getArgs(int argc, char **argv, double *step, double *totalTime, int *interval)
{
  if (argc == 4) {
    sscanf(argv[1],"%lf",&(*step) );
    sscanf(argv[2],"%lf",&(*totalTime) );
    sscanf(argv[3],"%d",&(*interval) );
  }
  else {
    printf("\n*** User Error: Command line arguments needed! ***\n\n");
    printf("Please run with the following arguments:\n\n");
    printf("./RK4_1 <timestep> <length> <output interval>\n\n");
    printf("Exiting...\n\n");
    exit(-1);
  }
  return 0;
}


/* Writes output to file 
   1st Column: x (independent variable)
   2nd Column: y (dependent variable)
*/
void writeFileOutput (double *x, double *y, int size, char *filename_output) 
{
    int i, j;
    FILE *outputFile;

    /* Open Output File */
    outputFile = fopen(filename_output, "w");

    /* Write Output */
    for(i=0; i<size; i++) {
        /* Apply desired number of digits for output here: */
        fprintf(outputFile, "%f\t%.10f\t\n", x[i], y[i]);
    }

    /* Close Output File */
    fclose(outputFile);
}

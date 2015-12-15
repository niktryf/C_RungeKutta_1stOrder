/*******************************************************************
 *** RK4 Header file: 
 *** Functions for input & output.
 *** 
 *******************************************************************/

int getArgs(int argc, char **argv, double *step, double *totalTime, int *interval);
void writeFileOutput (double *x, double *y, int size, char *filename_output);

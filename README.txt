			RK4_1

			i. Description
			ii. Dependencies
			iii. Instructions
			iv. Output

--------------------------------------------------------------------
i. DESCRIPTION:

The code in the current repository constitutes 
a simple 1st order ODE solver written in C.

The program essentially solves equations of the following form:

  		(dy/dx) = f(x,y)

The numerical method used is Runge - Kutta 4th order, one of 
the most well-known methods for the numerical solution of such 
differential equations.

--------------------------------------------------------------------
ii. DEPENDENCIES:

   The program is written in C. It should compile without any problems 
   in any system able of compiling C programs.

   The program also uses numpy and matplotlib for plotting the results
   ("analysis" directory), two fundamental packages for numerical Python. 

   Installing these is straightforward for linux systems, 
   for example in Ubuntu:

   sudo apt-get install python-numpy python-matplotlib

--------------------------------------------------------------------
iii. INSTRUCTIONS:

1. Enter the desired right-hand side function f(x,y) into the 
   F function inside the src/RK4.c source file .

2. Enter the desired initial conditions for x and y in main.c 
   (right after the memory allocation).

3. Compile, using the provided makefile. Simply type "make" in the 
   main directory, where the makefile is also located.

4. Run the program from the command line in the following format:
   
	$ ./RK4_1 <timestep> <length> <output interval>

   For example, running the following:

	$ ./RK4_1 0.1 100 10

   will use a time step of 0.1, for 100 length units and produce 
   output every 10 timesteps (i.e. every 10*0.1 = 1 length units).

---------------------------------------------------------------------
iv. OUTPUT:

   The program outputs the independent variable x and the numerical 
   solution y as columns in the output file "output/out.txt".

   To make a y(x) - x plot, enter the "analysis" directory and run:
   
   $ python plot1D.py

   This produces a simple plot of the numerical solution. You can 
   customize the plot from within the plot1D.py source file, using 
   basic matplotlib knowledge.




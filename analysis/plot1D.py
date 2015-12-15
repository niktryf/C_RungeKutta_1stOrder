#############################################################
### Python script for plotting data (x,y) 
###   Data is read from given file
###   Plot is created using matplotlib
###   
###   Author: Nikos Tryfonidis
###   The MIT License (MIT)
###   Copyright (c) 2015 Nikos Tryfonidis
###   See LICENSE.txt
#############################################################################

import numpy as np
import matplotlib.pyplot as plt

def plot1D (filename):
    
    # Load data
    x,y = np.loadtxt(filename, unpack=True)
    # Plot (matplotlib)
    plt.plot(x, y, color='red', linestyle='solid')
    
    # Set Axis
    plt.axis([x[0], x[-1], 0, max(y)+max(y)/4])
    
    # Figure and axes titles
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Numerical Solution (Runge-Kutta 4th)')
    plt.grid()
    # Draw Plot
    plt.show()
	
plot1D("../output/out.txt")


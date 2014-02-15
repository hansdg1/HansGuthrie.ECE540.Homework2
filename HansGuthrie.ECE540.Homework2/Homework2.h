#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdio>


#define PI_4 0.785398163	// Define Pi/4

//Function Prototypes
double *BuildArray( int Elements, double Start, double End );
double *SineOfArray( double *x, int Elements );
double *AbsRelativErrorOfArrays( double *In1, double *In2, int Elements );
double FindLowerBound( int Elements, double * Arr );
double FindUpperBound( int Elements, double * Arr );

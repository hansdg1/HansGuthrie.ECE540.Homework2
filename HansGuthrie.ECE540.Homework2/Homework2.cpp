#include <stdio.h>
#include <stdlib.h>

//This function allocates an array of doubles of length "Elements" on the heap. 
//It then fills them 
double *BuildArray( int Elements, double Start, double End );

double *SineOfArray( double *x, int Elements );

double *AbsRelativErrorOfArrays( double *In1, double *In2, int Elements );

int main()
{

}


double *BuildArray( int Elements, double Start, double End )
{
	//Old way to define array
	//Array = (double *)malloc( sizeof(double)*Elements );

	//Build the array
	int k;
	double Step;

	//Allocate space for the output array
	double *out = new double[ Elements ];
	Step = ( End - Start ) / (double)( Elements - 1 );
	
	//Now check if the allocation was valid
	if ( out )
	{
		out[ 0 ] = Start; //First element
		//Loop through the array
		for ( k = 1; k < Elements; k++ )
		{
			out[ k ] = out[ k - 1 ] + Step; //Next element equals last plus step value
		} //End for loop through array
	} //End valid allocation test

	return out;//returns the Built Array
} //End of BuildArray function

double *SineOfArray( double *x, int Elements )
{
	return NULL;
}

double *AbsRelativErrorOfArrays( double *In1, double *In2, int Elements )
{
	return NULL;
}


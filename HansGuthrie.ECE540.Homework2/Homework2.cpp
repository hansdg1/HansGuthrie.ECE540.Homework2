#include "Homework2.h"

using namespace std;

//The main method. Calculates the error between the two arrays,
//and outputs it to "Output.csv" along with the upper and lower
//bounds of 
int main()
{
	int LENGTH_OF_TEST = 499;
	double LowerBound;		// Value of the LowerBound
	double UpperBound;		// Value of the UpperBound

	double * Array = BuildArray( LENGTH_OF_TEST, -PI_4, PI_4 );							//Creates array via BuildArray function
	double * SineArray = SineOfArray( Array, LENGTH_OF_TEST );							//Creates the sine array via 'Arr' and the SineArray function
	double * ErrorArray = AbsRelativErrorOfArrays( Array, SineArray, LENGTH_OF_TEST );  //Creates the error array via 'Arr' and 'Sine' arrays

	// Checks to see if the arrays were created
	if ( !Array || !SineArray || !ErrorArray )
	{
		cout << "Error. Not Enough Memory\n";
		system( "PAUSE" );
		return 0;
	}

	ofstream OutputFile;						//Creates FileStream
	OutputFile.open( "Output.csv" );			//Attemps to write to file Output.csv

	// Checks to see if the file was created
	if ( !OutputFile.is_open() )
	{
		cout << "Cannot write to file output.csv\n";
		system( "PAUSE" );
		return 0;
	}

	//Print the 'Array' array to the .csv file
	OutputFile << "Base Array: " << endl;
	for ( int i = 0; i < LENGTH_OF_TEST; i++ )
	{
		OutputFile << Array[ i ] << ",";
	}

	//Print the 'SineArray(Array)' array to the .csv file
	OutputFile << "\nSineArray: " << endl;
	for ( int i = 0; i < LENGTH_OF_TEST; i++ )
	{
		OutputFile << SineArray[ i ] << ",";
	}

	//Print the 'ErrorArray' array to the .csv file
	OutputFile << "\nErrorArray: " << endl;
	for ( int i = 0; i < LENGTH_OF_TEST; i++ )
	{
		OutputFile << ErrorArray[ i ] << ",";
	}

	//Calculate the Upper and Lower Bounds

	// Calls function to find the lower bound of .001 in the 'Error' array
	LowerBound = FindLowerBound( LENGTH_OF_TEST, ErrorArray );
	// Calls function to find the upper bound of .001 in the 'Error' array
	UpperBound = FindUpperBound( LENGTH_OF_TEST, ErrorArray );	

	//Output the Upper and Lower bounds to the OutputFile
	OutputFile << "\nLowerBound " << LowerBound;			// Prints the lower bound to the file
	OutputFile << "\nUpperBound " << UpperBound;			// Prints the upper bound to the file


	//Cleanup all the memory we used
	OutputFile.close( );			// Closes the file we wrote
	delete []Array ;				// Free's the Arr array
	delete []SineArray;				// Free's the Sine array
	delete []ErrorArray;			// Free's the Error array
}

//This function allocates an array of doubles of length "Elements" on the heap. 
//It then fills them 
double *BuildArray( int Elements, double Start, double End )
{
	double * Array = new double[ Elements ]();		//Allocate the array we will return
	double Diff = fabs( End - Start );				//Finds the difference between the start and end
	
	int k;	//The for loop counter

	// Fill the array with numbers
	for ( k = 0; k < Elements; k++ )
	{
		Array[ k ] = Start + ( Diff / Elements )*( k + 1 );  // Calculate what value goes at each spot in teh array
	}
	return Array;
} //End of BuildArray function


//Allocates an array of doubles of length "Elements" and fills it with sin(x).
//Where x is the elements of the array (x) passed in. Returns a pointer to the allocated array
double *SineOfArray( double *x, int Elements )
{
	double * SineArray = new double[ Elements ]();		//Allocate space for the output array

	int k;		//The for loop counter
	//Fill the array with numbers
	for ( k = 0; k < Elements; k++ )
	{
		SineArray[ k ] = sin( x[ k ] ); //Calculate sin(x) and put it in the array
	}
	
	return SineArray;
}	//End SineOfArray

//Calculates the relative error between the given two arrays,
//and computers the error between them
double *AbsRelativErrorOfArrays( double *In1, double *In2, int Elements )
{
	double * ErrorArray = new double[ Elements ]();		//Allocate space for the output array
	
	int k;		//The for loop counter
	//Fill the array with numbers
	for ( k = 0; k < Elements; k++ )
	{
		//Calculates percent error for each spot in arrays, and saves to ErrorArray
		ErrorArray[ k ] = (fabs( In1[ k ] - In2[ k ] ) / fabs( In2[ k ] ));
		
	}
	return ErrorArray;
}	//End AbsRelativErrorOfArrays

// This function finds where in the array the value
// crosses .001 from above.
double FindLowerBound( int Elements, double * Array )
{
	double LowerBound;
	int Count = 0;

	//Loops until below .001
	while ( Array[ Count ] > .001
		&& Count < Elements )
	{
		Count++;
	}

	if ( Count != Elements )
	{
		LowerBound = Array[ Count ];	// If not 0 then set lower bound
	}
	else
	{
		LowerBound = Array[ 0 ];		// If 0, then set to lower bound = length
	}
	return LowerBound;
}

// This function finds where in the array the value
// crosses .001 from below.
double FindUpperBound( int Elements, double * Array )
{
	double UpperBound;
	int Count = Elements - 1;						// Count is Elements-1

	//Loop until below .001
	while ( Array[ Count ] > .001
		&& Count > 0 )
	{
		Count--;
	}

	if ( Count != 0 )
	{
		UpperBound = Array[ Count ];				// If not 0 then set upper bound
	}
	else
	{
		UpperBound = Array[ Elements - 1 ];			// If 0, then set to upper bound = length
	}
	return UpperBound;
}
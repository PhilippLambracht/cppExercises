#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>
#include <random>
#include <locale>
#include <string.h>
#include <pthread.h>
#include "timing/timing.h"
#include "productsum/productsum.h"

// =================================
// Global configuration parameters.
// =================================

// Specifies how many threads are used (Default: 1).
int nthreads;

// Specifies the size of the vector (Default: 100).
int nelements;

// =================================
// Function declaration.
// =================================

/**
 * @brief parseArguments
 *  Parses the specified command line arguments as followed:
 *      -n <INTEGER>    Specifies the number of threads to be used (Default: 1).
 *      -s <INTEGER>    Specifies the size of the test vector (Default: 100).
 *  Stores the number of threads in the global variable nthreads and the size
 *  of the test vector in the global variable nelements.
 * @param argc
 *  Number of command line arguments.
 * @param argv
 *  Vector with command line arguments in the same order they were given.
 */
void parseArguments ( int argc, char* argv[] );

/**
 * @brief sequentialProductSum
 *  Calculates the sum of products in a sequential manner.
 * @param _vector
 *  The vector.
 *  It holds that
 *      _vector.size() > 0
 * @return
 *  Returns
 *      _vector[0] * _vector[1] * ... * _vector[_vector.size() - 1]
 */
double sequentialProductSum ( std::vector<int> &_vector );

/**
 * @brief The VectorRange struct
 *  Struct to represent the range of a given vector.
 */
struct VectorRange
{
    /**
     * @brief vector
     *  The vector.
     */
    std::vector<int> *vector;
    /**
     * @brief startIdx
     *  The start index of the vector.
     */
    unsigned int startIdx;
    /**
     * @brief endIdx
     *  The end index of the vector.
     */
    unsigned int endIdx;
};

/**
 * @brief parallelProductSumWorker
 *  Threaded worker function to calculate the sum of product of a part of the test vector.
 * @param _arg
 *  An instance of the struct VectorRange, which specifies the vector, the start index and
 *  the end index.
 * @return
 *  Returns the sum of products of the specified range as void-pointer.
 */
void *parallelProductSumWorker ( void *_arg );

/**
 * @brief parallelProductSum
 *  Calculates the sum of products in a parallel manner by dividing the given vector in
 *  _nthreads parts.
 *  It holds that the length of the first (n-1) parts is
 *      _vector.size() DIV _nthreads
 *  The length of the last part is
 *      (_vector.size() DIV _nthreads) + (_vector.size() MOD _nthreads)
 *
 * @param _vector
 *  The vector.
 *  It holds that
 *      _vector.size() > 0
 * @param _nthreads
 *  The number of threads which are used to calculate the sum of product for the given vector.
 *  It holds that
 *      _nthreads > 0
 * @return
 *  Returns
 *      _vector[0] * _vector[1] * ... * _vector[_vector.size() - 1]
 */
double parallelProductSum ( std::vector<int> &_vector, int _nthreads );


void parseArguments ( int argc, char* argv[] )
{
    // TODO(1): Parse arguments.
    if(strncmp(argv[1],"-n" == 0){
      nthreads=atoi(argv[2]);
    }else{
      nthreads=1;
    }
    if(strncmp(argv[3],"-s" == 0){
      nelements=atoi(argv[4]);
    }else{
      nelements=100;
    }

    /*
    for(int i=1; i<argc;i++){
      if(strncmp(argv[i],"-n" == 0){
        nthreads=atoi(argv[i+1]);
      }
    }
    */
    //std::logic_error("Not implemented yet.");
}

double sequentialProductSum ( std::vector<int> &_vector )
{
    // TODO(2): Sequentiel calculation of the sum of products.
    // Add your implementation here!
      return ProductSum::calcProductSum(_vector, 0 ,_vector.size()-1);
    std::logic_error("Not implemented yet.");
    return -1;
}

void *parallelProductSumWorker ( void *_arg )
{
    // Related to TODO(3): Worker function for threaded calculation of the sum of products.
    int startIndex;
    int endIndex;
    std::vector<int> *wholeVector;
    std::vector<int> actualVector;
    struct VectorRange *vrData;
    vrData = (struct VectorRange *) _arg;
    startIndex=vrData->startIdx;
    endIndex=vrData->endIdx;
    wholeVector = vrData -> vector;
    for(int i = startIndex; i<endIndex; i++){
      actualVector.push_back(wholeVector[i]);
    }
    return (void *) parallelProductSum(&actualVector, nelements / nthreads):


    //std::logic_error("Not implemented yet.");
    return 0;
}

double parallelProductSum ( std::vector<int> &_vector, int _nthreads )
{
    // TODO(3): Parallel calculation of the sum of products.

    return ProductSum::calcProductSum(_vector, 0 ,_vector.size()-1);

    std::logic_error("Not implemented yet.");
    return -1;
}

int main ( int argc, char* argv[] )
{
    // Set locale, so that a point is used as thousand separator.
    setlocale ( LC_ALL, "" );
    void* ret
    // Parse command line parameters.
    parseArguments ( argc, argv );

    // Create a random vector of length nelements between 1 and 5.

    // initialize random seed.
    srand ( time ( NULL ) );

    // create and initialize the vector.
    std::vector<int> vector ( nelements );
    for ( int i = 0; i < nelements; ++i )
    {
        vector[i] = rand() % 5 + 1;
    }
    pthread_t threads[nthreads];
    fprintf ( stderr, "Starts calculations with an vector of size %d and %d threads.\n", nelements, nthreads );

    // Start calculations.
    long sequentialCalculationTime = 0, parallelCalculationTime = 0;
    double sequentialProductSumResult = -1, parallelProductSumResult = -2 ;
    long startTimestamp, endTimestamp;

    {
        // TODO(4): Time measurement of the sequential calculation of the product sum. Use your implemented function
        // sequentialProductSum() and store the measured calculation time in sequentialCalculationTime and the
        // product sum in sequentiatProduct startTimestamp = Timing::getTime();
        startTimestamp = Timing::getTime();
        sequentialProductSumResult = sequentialProductSum(&vector);
        endTimestamp = Timing::getTime();
        sequentialCalculationTime = Timing::getTimeDifference(startTimestamp, endTimestamp);
        //std::logic_error("Not implemented yet.");
    }

    {
        // TODO(5): Time measurement of the parallel calculation of the product sum. Use your implemented function
        // parallelProductSum() and store the measured calculation time in parallelCalculationTime and the
        // product sum in parallelProductSumResult.
        int strIndex = 0;
        int endIndex = nelements / nthreads;
        startTimestamp = Timing::getTime();
        for(unsigned long i = 0; i < nthreads; i++){
          struct VectorRange vr;
          vr.startIdx = strIndex;
          vr.endIdx = endIndex;
          vr.vector =&vector;
          pthread_create(&threads[i],0, parallelProductSumWorker, (void *) &vr);
          vr.startIdx = vr.endIdx;
          vr.endIdx = vr.endIdx + (nelements / nthreads);
        }
        parallelProductSumResult =1;
        for(unsigned long i = 0; i < nthreads; i++){
          pthread_join (threads[i],&ret);
          parallelProductSumResult *= (double)ret;
        }


        endTimestamp = Timing::getTime();
        parallelCalculationTime = Timing::getTimeDifference(startTimestamp, endTimestamp);



        //std::logic_error("Not implemented yet.");
    }

    // Output.
    fprintf ( stderr, "Parallel calculation time   : %'12ld nsec\n", parallelCalculationTime );
    fprintf ( stderr, "Sequential calculation time : %'12ld nsec\n", sequentialCalculationTime );
    fprintf ( stderr, "Correctness test            : %s\n",
              ( sequentialProductSumResult == parallelProductSumResult ) ? "True" : "Failed" );
    fprintf ( stderr, "Print csv output to stdout.\n" );
    fprintf ( stdout, "%d;%d;%ld;%ld\n", nthreads, nelements, parallelCalculationTime, sequentialCalculationTime );

    return EXIT_SUCCESS;
}

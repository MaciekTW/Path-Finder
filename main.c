
//
#include <stdio.h>
#include "Module.h"

//#define PRINT

#define N 8
#define M 8
#define SHIP_DEPTH  5

using namespace std;

int main( int argc, char** argv )
{

    if ( argc != 2 ) {
        printf( "Usage: %s <plik_we>", argv[0] );
        return -2;
    }

    int** tab = NULL;
    int** sol = NULL;

    if ( !( tab = createTab(N, M) ) || !( sol = createTab(N, M) ) )
    {
        perror( "ERROR: ALLOCATION ERROR \n" );
        return -1;
    }
    if ( readDepthTab(argv[1], tab, N, M) )
    {

#ifdef PRINT
    printf( "Deepth Array: \n\n" );
    printTab( tab, N, M );
    printf( "\n" );
#endif

    if ( !root( tab, N, M, SHIP_DEPTH, 0, 0, sol, N - 1, M - 1 ) )
        printf( "* *The Harbour cannot by achieved!!\n\n" );
    else
    {
        printf( "Path to the Harbour: \n\n" );
        printTab( sol, N, M );
    }
    }

    freeTab( &sol );
    freeTab( &tab );
    return 0;
}



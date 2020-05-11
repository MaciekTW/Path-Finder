#include "Module.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    UP = 1,
    RIGHT,
    DOWN,
    LEFT 
} Directions;

int** createTab( int nRow, int nCol )
{
    int** pTab = (int**)malloc( nRow * sizeof( int* ) );
    if ( !pTab )
        return NULL;
    memset( pTab, 0, nRow * sizeof( int* ) );

    *pTab = (int*)malloc( nRow * nCol * sizeof( int ) );
    if ( !*pTab )
        return 0;
    memset( *pTab, 0,nCol * nRow * sizeof( int ) );
   
    int* wsk = *pTab;
    int** ptr = pTab;
    for ( int i = 1; i <= nRow; i++, ptr++ )
    {
        *ptr = wsk;
        wsk += nCol;
    }
    return pTab;
}
void printTab( int** pRoot, int nRow, int nCol )
{
    for ( int i = 0; i < nRow; i++ )
    {
        int* ptr = *pRoot++;
        for ( int j = 0; j < nCol; j++ )
            printf( "%2d ", *ptr++ );
        printf( "\n" );
    }
}
int readDepthTab( char* sFile, int** pTab, int nRow, int nCol )
{
    FILE* file = NULL;

    if ( ( file = fopen(sFile, "r") ) == NULL )
    {
        printf( "Couldn't find a %s file\n", sFile );
        return 0;
    }
    for ( int i = 0; i < nRow; i++ )
    {
        int* p = *pTab++;
        for ( int j = 0; j < nRow; j++ )
            fscanf( file, "%d", p++ );
    }
    return 1;
}
int root( int** pDepthTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest )
{
    static int temp = 1;
    pRoot[x][y] = temp++;
    if ( x == x_dest && y_dest == y )
    {
        return 1;
    }
    int px = 0;
    int py = 0;
    for ( int i = UP; i <= LEFT; i++ )
    {
        if ( move( pDepthTab, nRow, nCol, nDepth, i, x, y, &px, &py, pRoot ) )
            if ( root( pDepthTab, nRow, nCol, nDepth, px, py, pRoot, x_dest, y_dest ) )
                return 1;
    }
    temp--;
    pRoot[x][y]=0;

    return 0;
}
int move( int** pDepthTab, int nRow, int nCol, int nDepth, int nextMove, int x, int y, int* px, int* py, int** pRoot )
{
    switch ( nextMove )
    {
    case UP:    *px = x - 1;  *py = y;  break;
    case RIGHT: *py = y + 1;  *px = x;  break;
    case DOWN:  *px = x + 1;  *py = y;  break;
    case LEFT:  *py = y - 1;  *px = x;  break;
    default:   perror("WRONG VALUE"); return 0;
    }

    if ( ( *px >= 0 && *px < nRow ) && ( *py >= 0 && *py < nCol ) )
        if ( pDepthTab[*px][*py] > nDepth )
            if ( pRoot[*px][*py] == 0 )
                return 1;
    return 0;

}
void freeTab( int*** pTab )
{
    free( **pTab );
    free( *pTab );
    *pTab = NULL;
}
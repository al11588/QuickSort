
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void quicksort( int *, int, int );
int partition( int *, int, int );
void swap( int *, int * );

int main()
{ 
   int loop, arrayToBeSorted[ MAX ] = { 0};

   srand( time( NULL ) );

   for ( loop = 0; loop < MAX; loop++ )
      arrayToBeSorted[ loop ] = rand() % 1000;

   printf( "Initial array values are: \n" );

   for ( loop = 0; loop < MAX; loop++ ) 
       printf( "%4d", arrayToBeSorted[ loop ] );    

   printf( "\n\n" );

   if ( MAX == 1 )
      printf( "Array is sorted: %d\n", arrayToBeSorted[ 0 ] );
   else { 
      quicksort( arrayToBeSorted, 0, MAX - 1 );
      printf( "The sorted array values are:\n" );

      for ( loop = 0; loop < MAX; loop++ ) 
         printf( "%4d", arrayToBeSorted[ loop ] );

      printf( "\n" );
   }

   return 0;
}

void quicksort( int array[], int first, int last )
{ 
   int currentLocation;

   if ( first >= last )
      return;

   currentLocation = partition( array, first, last );  /* place an element */
   quicksort( array, first, currentLocation - 1 );     /* sort left side   */
   quicksort( array, currentLocation + 1, last );      /* sort right side  */
}


int partition( int array[], int left, int right )
{ 
   int position = left;

   while ( 1 ) { 
      while ( array[ position ] <= array[ right ] && position != right )
         --right;

      if ( position == right )
         return position ;

      if ( array[ position ] > array[ right ] ) { 
         swap( &array[ position  ], &array[ right ] );
         position = right;
      }

      while ( array[ left ] <= array[ position ] && left != position  )
         ++left;

      if ( position == left )
         return position;

      if ( array[ left ] > array[ position ] ) { 
         swap( &array[ position ], &array[ left ] );
         position = left;
      }
   }
}


void swap( int *ptr1, int *ptr2 )
{ 
   int temp;

   temp = *ptr1;
   *ptr1 = *ptr2;
   *ptr2 = temp;
}
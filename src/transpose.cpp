#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

void parsec_roi_begin() 
{

}

void parsec_roi_end() 
{

}

void transpose_matrix()
{
  int rows = 4;
  int cols = 4;
  int matrix[rows][cols] = {{1,2,3,4},{4,5,6,7},{7,8,9,10}};
  int transpose[cols][rows];
  int i,j;
  
  for (i=0;i<rows;i++){
    for (j=0;j<cols;j++){
      transpose[i][j] = matrix[j][i];
    }
  }
}

int main(){

  parsec_roi_begin();
    transpose_matrix();
  parsec_roi_end();

  return 0;
}
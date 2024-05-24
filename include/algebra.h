#ifndef ALGEBRA_H
#define ALGEBRA_H
#include "../include/algebra.h"
#include "../include/loader.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct TwoDMatrix
{
  float **data;
  int m; // rows
  int n; // cols
} TwoDMatrix;

void matrix_from_df(Dataframe *df, TwoDMatrix *mat);

void matrix_multiplication(TwoDMatrix a, TwoDMatrix b, TwoDMatrix *c);

void allocate_matrix(TwoDMatrix *mat);

void plot_matrix(TwoDMatrix mat);

#endif
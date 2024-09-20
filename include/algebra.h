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

// void matrix_from_df(Dataframe *df, TwoDMatrix *mat);

// void matrix_multiplication(TwoDMatrix a, TwoDMatrix b, TwoDMatrix *c);

// void allocate_matrix(TwoDMatrix *mat);

// void plot_matrix(TwoDMatrix mat);

void matmul(float *a, float *b, float *c, int am, int an, int bm, int bn);

void matplot(float *a, int m, int n, const char *name);

void mattransp(float *a, float *b, int m, int n);

void ludecomp(float *a, int m, float *l, float *u);

void linsolve(float *a, float *b, float *x, int m);

void matinit(float *a, int m, int n, const float val);

#endif
#include "../include/algebra.h"
#include "../include/loader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void matrix_multiplication(TwoDMatrix a, TwoDMatrix b, TwoDMatrix *c)
{
  // assuming a * b = c
  if (!(a.n == b.m && a.m == b.n))
  {
    printf("Can't multiply matrices, dimensions don't match\n");
    exit(0);
  }
  c->m = a.m;
  c->n = a.n;
  allocate_matrix(c);
  for (int i = 0; i < a.m; i++)
  {
    for (int j = 0; j < a.n; j++)
    {
      float temp = 0.0;
      for (int k = 0; k < a.n; k++)
      {
        temp += a.data[k][i] * b.data[j][k];
      }
      c->data[j][i] = temp;
    }
  }
}

void matrix_transpose() {}

void matrix_inverse() {}

void free_matrix_memory() {}

void plot_matrix(TwoDMatrix mat)
{
  printf("--------- Matrix Information ---------\n");
  printf("Number of cols: %i\n", mat.n);
  printf("Number of rows: %i\n", mat.m);
  for (int j = 0; j < mat.m; j++)
  {
    for (int i = 0; i < mat.n; i++)
    {
      printf("%f ", mat.data[i][j]);
    }
    printf("\n");
  }
  printf("--------------------------------------\n");
}

void copy_values(Dataframe *df, TwoDMatrix *mat)
{
  long int len = df->n * sizeof(float);
  for (int i = 0; i < mat->n; i++)
  {
    memcpy(mat->data[i], df->vars[i].data, len);
  }
}

void allocate_matrix(TwoDMatrix *mat)
{
  mat->data = (float **)malloc(mat->n * sizeof(float *));
  if (mat->data == NULL)
  {
    printf("Error allocating memory for matrix\n");
    exit(0);
  }
  for (int i = 0; i < mat->m; i++)
  {
    mat->data[i] = (float *)malloc(mat->m * sizeof(float));
    if (mat->data[i] == NULL)
    {
      printf("Error allocating memory for matrix\n");
      exit(0);
    }
  }
}

void matrix_from_df(Dataframe *df, TwoDMatrix *mat)
{
  mat->m = df->n;
  mat->n = df->p;
  allocate_matrix(mat);
  copy_values(df, mat);
}
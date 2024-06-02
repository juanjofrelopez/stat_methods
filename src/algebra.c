#include "../include/algebra.h"
#include "../include/loader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// void matrix_multiplication(TwoDMatrix a, TwoDMatrix b, TwoDMatrix *c)
// {
//   // assuming a * b = c
//   if (!(a.n == b.m && a.m == b.n))
//   {
//     printf("Can't multiply matrices, dimensions don't match\n");
//     exit(0);
//   }
//   c->m = a.m;
//   c->n = a.n;
//   allocate_matrix(c);
//   for (int i = 0; i < a.m; i++)
//   {
//     for (int j = 0; j < a.n; j++)
//     {
//       float temp = 0.0;
//       for (int k = 0; k < a.n; k++)
//       {
//         temp += a.data[k][i] * b.data[j][k];
//       }
//       c->data[j][i] = temp;
//     }
//   }
// }

// void matrix_transpose() {}

// void matrix_inverse() {}

// void free_matrix_memory() {}

// void plot_matrix(TwoDMatrix mat)
// {
//   printf("--------- Matrix Information ---------\n");
//   printf("Number of cols: %i\n", mat.n);
//   printf("Number of rows: %i\n", mat.m);
//   for (int j = 0; j < mat.m; j++)
//   {
//     for (int i = 0; i < mat.n; i++)
//     {
//       printf("%f ", mat.data[i][j]);
//     }
//     printf("\n");
//   }
//   printf("--------------------------------------\n");
// }

// void copy_values(Dataframe *df, TwoDMatrix *mat)
// {
//   long int len = df->n * sizeof(float);
//   for (int i = 0; i < mat->n; i++)
//   {
//     memcpy(mat->data[i], df->vars[i].data, len);
//   }
// }

// void allocate_matrix(TwoDMatrix *mat)
// {
//   mat->data = (float **)malloc(mat->n * sizeof(float *));
//   if (mat->data == NULL)
//   {
//     printf("Error allocating memory for matrix\n");
//     exit(0);
//   }
//   for (int i = 0; i < mat->m; i++)
//   {
//     mat->data[i] = (float *)malloc(mat->m * sizeof(float));
//     if (mat->data[i] == NULL)
//     {
//       printf("Error allocating memory for matrix\n");
//       exit(0);
//     }
//   }
// }

// void matrix_from_df(Dataframe *df, TwoDMatrix *mat)
// {
//   mat->m = df->n;
//   mat->n = df->p;
//   allocate_matrix(mat);
//   copy_values(df, mat);
// }

int idx(int i, int j, int m, int n)
{
  return (i * n) + j;
}

/**
 * MATRIX MULTIPLICATION
 * a is m by n
 * b is m by n
 * c will be m by m
 */
void matmul(float *a, float *b, float *c, int am, int an, int bm, int bn)
{
  if (!(an == bm && am == bn))
  {
    printf("Can't multiply matrices, dimensions don't match\n");
    exit(0);
  }
  for (int i = 0; i < am; i++)
  {
    for (int j = 0; j < bn; j++)
    {
      float temp = 0.0;
      for (int k = 0; k < an; k++)
      {
        temp += a[i + k] * b[j + k];
      }
      c[i + j] = temp;
    }
  }
}

void matplot(float *a, int m, int n, const char *name)
{
  printf("\n");
  printf("-------------%s----------------\n", name);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%f ", a[idx(i, j, m, n)]);
    }
    printf("\n");
  }
  printf("-----------------------------\n");
  printf("\n");
}

void mattransp(float *a, float *b, int m, int n)
{
  int j = 0;
  int len = m * n;
  for (int i = 0; i < n; i++)
  {
    int k = 0;
    while (k < len)
    {
      b[j] = a[i + k];
      k += n;
      j++;
    }
  }
}

void matinit(float *a, int m, int n, const float val)
{
  for (int i = 0; i < m * n; i++)
  {
    a[i] = val;
  }
}

void eyeinit(float *a, int m)
{
  if (m <= 0)
    return;
  matinit(a, m, m, 0.0);
  for (int i = 0; i < m; i++)
  {
    a[idx(i, i, m, m)] = 1.0f;
  }
}

/**
 * LU DECOMPOSITION
 * a is a square matrix m by m
 * a = lu
 */
void ludecomp(float *a, int m, float *l, float *u)
{
  matinit(l, m, m, 0.0);
  matinit(u, m, m, 0.0);

  for (int j = 0; j < m; j++)
  {
    l[idx(j, j, m, m)] = 1.0;
    for (int i = 0; i < j + 1; i++)
    {
      float sum = 0;
      for (int k = 0; k < i; k++)
      {
        sum += (u[idx(k, j, m, m)] * l[idx(i, k, m, m)]);
      }
      u[idx(i, j, m, m)] = a[idx(i, j, m, m)] - sum;
    }

    for (int i = j; i < m; i++)
    {
      float sum = 0.0;
      for (int k = 0; k < j; k++)
      {
        sum += u[idx(k, j, m, m)] * l[idx(i, k, m, m)];
      }
      l[idx(i, j, m, m)] = (a[idx(i, j, m, m)] - sum) / u[idx(j, j, m, m)];
    }
  }
}

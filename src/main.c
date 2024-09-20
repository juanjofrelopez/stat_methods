#include "../include/loader.h"
#include "../include/algebra.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  printf("Hello World!!\n");
  // Dataframe *df = load_csv("../assets/data.csv");
  // df_info(df);
  // print_values(df);
  // TwoDMatrix a;
  // matrix_from_df(df, &a);
  // TwoDMatrix b;
  // matrix_from_df(df, &b);
  // plot_matrix(a);
  // plot_matrix(b);
  // TwoDMatrix c;
  // matrix_multiplication(a, b, &c);
  // plot_matrix(c);

  // float a[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  // float b[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  // float c[9];
  // matmul(a, b, c, 3, 3, 3, 3);
  // matplot(c, 3, 3);
  // mattransp(a, c, 3, 3);
  // matplot(c, 3, 3);

  // int m = 3;
  // float a[9] = {2, -1, -2, -4, 6, 3, -4, -2, 8};
  // float l[m * m];
  // float u[m * m];
  // matplot(a, m, m, "A");
  // ludecomp(a, m, l, u);
  // matplot(l, m, m, "L");
  // matplot(u, m, m, "U");

  int m = 2;
  // float a[9] = {2, 4, 6, 4, 5, 6, 3, 1, -2};
  float a[4] = {1, 1, 2, -3};

  // float b[3] = {18, 24, 4};
  float b[2] = {7, -6};

  float x[m];
  matinit(x, m, 1, 0.0);
  matplot(a, m, m, "A");
  matplot(b, m, 1, "B");

  linsolve(a, b, x, m);
  matplot(x, m, 1, "X");
  // ans should be: (4,-2,3)

  return 0;
}
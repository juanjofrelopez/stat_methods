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

  int m = 3;
  float a[9] = {2, -1, -2, -4, 6, 3, -4, -2, 8};
  float l[m * m];
  float u[m * m];
  matplot(a, m, m, "A");
  ludecomp(a, m, l, u);

  matplot(l, m, m, "L");
  matplot(u, m, m, "U");

  return 0;
}
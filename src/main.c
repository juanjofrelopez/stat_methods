#include "../include/loader.h"
#include "../include/algebra.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  printf("Hello World!!\n");
  Dataframe *df = load_csv("../assets/data.csv");
  df_info(df);
  print_values(df);
  TwoDMatrix a;
  matrix_from_df(df, &a);
  TwoDMatrix b;
  matrix_from_df(df, &b);
  plot_matrix(a);
  plot_matrix(b);
  TwoDMatrix c;
  matrix_multiplication(a, b, &c);
  plot_matrix(c);
  return 0;
}
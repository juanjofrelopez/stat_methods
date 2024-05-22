#include "../include/loader.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  printf("Hello World!!\n");
  Dataframe *df = load_csv("../assets/data.csv");
  df_info(df);
  print_values(df);
  return 0;
}
#include "../include/loader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 1024

void print_values(Dataframe *df)
{
  for (int i = 0; i < df->p; i++)
  {
    printf("%s ", df->vars[i].name);
  }
  printf("\n");
  for (int i = 0; i < df->n; i++)
  {
    for (int j = 0; j < df->p; j++)
    {
      printf("%f ", df->vars[j].data[i]);
    }
    printf("\n");
  }
}

void df_info(Dataframe *df)
{
  printf("-----------Dataframe Information-----------\n");
  printf("Name:                  %s\n", df->name);
  printf("Number of predictors:  %i\n", df->p);
  printf("Number of variables:   %i\n", df->n);
  printf("Size of Var:           %li\n", sizeof(Var));
  printf("Size of df.data:       %li\n", sizeof(df->vars));
  printf("Size of data:          %li\n", sizeof(df->vars[0].data));
  printf("pointer to var arr:    %p\n", df->vars);
  printf("ptr to 1st var data:   %p\n", df->vars[0].data);
  printf("-------------------------------------------\n");
}

void count_np(FILE *fp, Dataframe *df)
{
  int p = 0;
  int n = 0;
  char s[MAX_CHARS];
  char *tok;
  if (fgets(s, MAX_CHARS, fp) != NULL)
  {
    tok = strtok(s, ",");
    while (tok != NULL)
    {
      p++;
      tok = strtok(NULL, ",");
    }
  }
  while (fgets(s, MAX_CHARS, fp) != NULL)
  {
    n++;
  }
  df->p = p;
  df->n = n;
  rewind(fp);
}

void alloc_predictors(Dataframe *df)
{
  df->vars = malloc(df->p * sizeof(Var));
  if (df->vars == NULL)
  {
    printf("Error allocating memory for predictors\n");
    exit(1);
  }
}

void alloc_data(Dataframe *df)
{
  for (int i = 0; i < df->p; i++)
  {
    df->vars[i].data = (float *)malloc(df->n * sizeof(float));
    if (df->vars[i].data == NULL)
    {
      printf("Error allocating memory for data in predictor %d\n", i);
      exit(1);
    }
  }
}

void fill_data(FILE *fp, Dataframe *df)
{
  char *tok;
  char s[MAX_CHARS];

  // Read first line for variable names
  fgets(s, MAX_CHARS, fp);
  tok = strtok(s, ",");
  int p = 0;
  int n = 0;
  while (tok != NULL)
  {
    // @TODO: remove \n from tok
    strcpy(df->vars[p].name, tok);
    tok = strtok(NULL, ",");
    p++;
  }

  while (fgets(s, MAX_CHARS, fp) != NULL)
  {
    p = 0;
    tok = strtok(s, ",");
    while (tok != NULL)
    {
      df->vars[p].data[n] = atof(tok);
      tok = strtok(NULL, ",");
      p++;
    }
    n++;
  }
  rewind(fp);
}

Dataframe *load_csv(char *filename)
{
  Dataframe *df = NULL;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    perror("Error opening file");
    exit(0);
  }
  df = (Dataframe *)malloc(sizeof(Dataframe));
  if (df == NULL)
  {
    printf("Couldn't allocate memory for the dataframe.\n");
    exit(0);
  }
  count_np(fp, df);
  df->name = "alo hawaii";
  alloc_predictors(df);
  alloc_data(df);
  fill_data(fp, df);
  fclose(fp);
  return df;
}

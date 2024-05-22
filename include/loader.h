#ifndef LOADER_H

#define LOADER_H

typedef struct Var
{
  char name[1024];
  float *data;
} Var;

typedef struct Dataframe
{
  char *name;
  Var *data;
  int p;
  int n;
} Dataframe;

Dataframe *load_csv(char *filename);

void df_info(Dataframe *df);

void print_values(Dataframe *df);

#endif
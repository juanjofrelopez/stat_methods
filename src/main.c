#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *base_filename = "column";
  int num_files = 4;
  int num_elements = 0;

  // Array to store pointers to float arrays for each column
  float **data_arrays = malloc(num_files * sizeof(float *));
  if (data_arrays == NULL)
  {
    fprintf(stderr, "Error allocating memory for data arrays\n");
    return 1;
  }

  // Loop through each binary file
  for (int i = 0; i < num_files; ++i)
  {
    char filename[100]; // Adjust buffer size if needed
    snprintf(filename, sizeof(filename), "../assets/%s%d.bin", base_filename, i + 1);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
      fprintf(stderr, "Error opening file: %s\n", filename);
      continue; // Skip to next file on error
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Check if file size is a multiple of sizeof(float)
    if (file_size % sizeof(float) != 0)
    {
      fprintf(stderr, "Error: File size not a multiple of float size\n");
      fclose(fp);
      continue; // Skip to next file on error
    }

    num_elements = file_size / sizeof(float);

    // Allocate memory for the float array for this column
    data_arrays[i] = malloc(num_elements * sizeof(float));
    if (data_arrays[i] == NULL)
    {
      fprintf(stderr, "Error allocating memory for data array %d\n", i);
      fclose(fp);
      continue; // Skip to next file on error (consider freeing previously allocated memory)
    }

    // Read data into the float array
    size_t num_read = fread(data_arrays[i], sizeof(float), num_elements, fp);
    if (num_read != num_elements)
    {
      fprintf(stderr, "Error reading data from file: %s\n", filename);
      fclose(fp);
      continue; // Skip to next file on error (consider freeing previously allocated memory)
    }

    fclose(fp);
  }

  // Now you have the data loaded into the data_arrays (**data_arrays[i] points to the float array for column i**)
  // Process or use the data as needed in your C program

  for (int i = 0; i < num_files; i++)
  {
    printf("variable: %i num of elements: %i\n", i, num_elements);
    for (int j = 0; j < num_elements; j++)
    {
      printf("%f\n", data_arrays[i][j]);
    }
  }

  // Free allocated memory (important!)
  for (int i = 0; i < num_files; ++i)
  {
    if (data_arrays[i] != NULL)
    {
      free(data_arrays[i]);
    }
  }
  free(data_arrays);

  return 0;
}

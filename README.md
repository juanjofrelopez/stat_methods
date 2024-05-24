# TODO

- [x] init a codebase with makefile
- [x] compile a hello world
- [x] open a csv file
- [x] iterate over it
- [x] define structs
- [x] parse data into structs
- [x] failed approach. read csv with py script
- [x] never give up. try again C-based csv loader
- [x] success
- [x] Define matrix structs
- [x] implement matrix loaders
- [ ] implement algebra library algebra.c
  - [ ] matrix multiplication
    - [x] first draft
    - [ ] modify this method to output a pointer to newly created matrix called C
  - [ ] matrix transpose
  - [ ] matrix inverse
- [ ] data toolset tools.c
  - [ ] mean
  - [ ] median
  - [ ] std deviation
  - [ ] variance
  - [ ] correlation -> to construct a correlation matrix
- [ ] investigate gnuplot for data viz
- [ ] implement simple linear regression
- [ ] implement multiple linear regression

## How to run

To generate the bin files from data.csv :

```bash
cd scripts
python3 prepare_data.py
```

To compile and run main rutine:

```bash
chmod u+x run.sh
./run.sh
```

## Cool articles

https://www.lucavall.in/blog/how-to-structure-c-projects-my-experience-best-practices
https://www.lucavall.in/blog/crafting-clean-maintainable-understandable-makefile-for-c-project

# Algebra

## Matrix struct

```c
typedef struct TwoDMatrix
{
  float **mat;
  int m; // rows
  int n; // cols
} TwoDMatrix;
```

## 2D Matrix creation from dataframe

To create a matrix from a df you pass the pointer to the df
The m-by-n matrix will be:

- m : rows -> "df.n" the number of observations
- n : cols -> "df.p" the number of variables

so first you allocate memory for n pointers
then for each space you create a pointer that has allocated m floats
then copy the contents from the data pointer in the df to the allocated pointer in the matrix.

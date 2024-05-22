# TODO

- [x] init a codebase with makefile
- [x] compile a hello world
- [x] open a csv file
- [x] iterate over it
- [x] define structs
- [x] parse data into structs
- [x] failed approach. read csv with py script
- [x] abstract loader
- [ ] implement algebra library algebra.c
  - [ ] matrix transpose
  - [ ] matrix multiplication
  - [ ] matrix inverse
- [ ] data toolset tools.c
  - [ ] mean
  - [ ] median
  - [ ] std deviation
  - [ ] variance
  - [ ] correlation -> to construct a correlation matrix
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

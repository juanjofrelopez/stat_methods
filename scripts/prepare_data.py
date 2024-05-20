import csv
from array import array

def write_csv_to_binary(csv_filename, binary_filename_base):
  with open(csv_filename, 'r', newline='') as csvfile:
      reader = csv.reader(csvfile)
      headers = next(reader)  # Read the header row

      # Create empty lists for each column
      column_lists = [[] for _ in headers]

      for row in reader:
          for i, value in enumerate(row):
              try:
                  # Convert to float, handle potential conversion errors
                  column_lists[i].append(float(value))
              except ValueError:
                  # Handle non-numeric values (e.g., print a warning)
                  print(f"Warning: Non-numeric value encountered in column {headers[i]}")

  # Write each column list to a separate binary file with numbered suffix
  for i, column in enumerate(column_lists):
      filename = f"../assets/{binary_filename_base}{i+1}.bin"  # Add suffix (1-based)
      output_file = open(filename,'wb')
      float_arr = array('f',column)
      float_arr.tofile(output_file)
      output_file.close()

# Example usage
csv_filename = '../assets/data.csv'
binary_filename_base = 'column'  # Adjust as needed

write_csv_to_binary(csv_filename, binary_filename_base)

print("CSV data successfully written to binary files.")

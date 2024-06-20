import numpy as np

# Create a 1D array with 6 elements
array = np.array([1, 2, 3, 4, 5, 6])

# Reshape the array to 2 rows and 3 columns
reshaped_array = np.reshape(array, (3, 2))

print(reshaped_array)

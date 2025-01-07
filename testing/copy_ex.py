import copy

original_list = [[1, 2, 3], [4, 5, 6]]
shallow_copied_list = copy.copy(original_list)

# Modify an inner list in the copied list
shallow_copied_list[0][0] = 99

print(original_list)  # Output: [[99, 2, 3], [4, 5, 6]]
print(shallow_copied_list)  # Output: [[99, 2, 3], [4, 5, 6]]


# Even if you create a new variable and did just normal shallow copy it points to the same object


deep_copied_list=copy.deepcopy(original_list)

deep_copied_list[0][0]=20


print(original_list)  # Output: [[1, 2, 3], [4, 5, 6]]
print(deep_copied_list)  # Output: [[99, 2, 3], [4, 5, 6]]

# A deep copy creates a new object and recursively copies all nested objects.H

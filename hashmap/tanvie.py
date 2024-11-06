def solution(queries):
    houses = set()  # Set to track built house locations
    longest_segment = 0  # To track the longest contiguous segment
    result = []
    
    left_boundaries = {}  # To track the left boundaries of contiguous segments
    right_boundaries = {}  # To track the right boundaries of contiguous segments
    
    for query in queries:
        if query in houses:
            result.append(longest_segment)
            continue
        
        # Initially, assume the house forms a segment of length 1
        left = query
        right = query
        
        # Check if there's a contiguous segment to the left
        if query - 1 in houses:
            left = left_boundaries[query - 1]
        
        # Check if there's a contiguous segment to the right
        if query + 1 in houses:
            right = right_boundaries[query + 1]
        
        # Now we know the new left and right boundaries of the segment
        left_boundaries[right] = left
        right_boundaries[left] = right
        left_boundaries[query] = left
        right_boundaries[query] = right
        
        # Update the longest contiguous segment
        current_segment_length = right - left + 1
        longest_segment = max(longest_segment, current_segment_length)
        
        # Add the current longest segment to the result
        result.append(longest_segment)
    
    return result

# Example usage
queries = [-32, -33, -23, -22, -24, -25, -31, -21, -30, -27, -29, -20]
print(solution(queries))  # Output: [1, 1, 3, 3]

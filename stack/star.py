import heapq

# Define the heuristic function (Manhattan distance)
def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def a_star(grid, start, goal):
    #Directions to move right,left,down,up
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    
    # Priority queue for the open list
    open_list = []
    heapq.heappush(open_list, (0, start))
    
    # Cost from start to a node
    g_cost = {start: 0}
    
    # Parent dictionary for reconstructing the path
    came_from = {}
    
    while open_list:
        _, current = heapq.heappop(open_list)
        
        # If goal is reached, reconstruct and return the path
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]
        
        # Explore neighbors
        for dx, dy in directions:
            neighbor = (current[0] + dx, current[1] + dy)
            
            # Check if the neighbor is within bounds and not an obstacle
            if 0 <= neighbor[0] < len(grid) and 0 <= neighbor[1] < len(grid[0]) and grid[neighbor[0]][neighbor[1]] == 0:
                # Tentative g_cost  (cost to move to this neighbor)
                tentative_g_cost = g_cost[current] + 1
                
                if neighbor not in g_cost or tentative_g_cost < g_cost[neighbor]:
                    # Update cost and parent
                    g_cost[neighbor] = tentative_g_cost
                    f_cost = tentative_g_cost + heuristic(neighbor, goal)
                    heapq.heappush(open_list, (f_cost, neighbor))
                    came_from[neighbor] = current
    
    return None  # No path found

# Example usage
if __name__ == "__main__":
    # 0 represents free space, 1 represents obstacles
    grid = [
        [0, 1, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0]
    ]
    start = (0, 0)  # Top-left corner
    goal = (4, 4)   # Bottom-right corner
    
    path = a_star(grid, start, goal)
    
    if path:
        print("Path found:", path)
    else:
        print("No path found.")

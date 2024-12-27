class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

def cloneGraph(node):
    """
    Clone an undirected graph.
    :param node: Node - The reference to the starting node of the graph.
    :return: Node - The reference to the starting node of the cloned graph.
    """
    if not node:
        return None

    # Dictionary to store the mapping from original node to cloned node
    cloned_nodes = {}

    def dfs(original_node):
        # If the node has already been cloned, return the clone
        if original_node in cloned_nodes:
            return cloned_nodes[original_node]

        # Clone the node
        clone = Node(original_node.val)
        cloned_nodes[original_node] = clone

        # Recursively clone the neighbors
        for neighbor in original_node.neighbors:
            clone.neighbors.append(dfs(neighbor))

        return clone

    # Start the DFS from the given node
    return dfs(node)

# Example Usage
if __name__ == "__main__":
    # Create a sample graph: 1 -- 2
    #                          |    |
    #                          4 -- 3
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    node4 = Node(4)

    node1.neighbors = [node2, node4]
    node2.neighbors = [node1, node3]
    node3.neighbors = [node2, node4]
    node4.neighbors = [node1, node3]

    # Clone the graph
    cloned_graph = cloneGraph(node1)

    # Verify the structure of the cloned graph
    print(f"Cloned Node Value: {cloned_graph.val}")
    print(f"Neighbors of Cloned Node: {[neighbor.val for neighbor in cloned_graph.neighbors]}")

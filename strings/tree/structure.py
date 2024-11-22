# THis is basic implementation of tree data structure


# Define the TreeNode class
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []  # List to store child nodes

# Define the GeneralTree class
class GeneralTree:
    def __init__(self, root_value):
        self.root = TreeNode(root_value)  # Create the root node
    
    def add_child(self, parent_value, child_value):
        # Find the parent node in the tree
        parent_node = self.find_node(self.root, parent_value)
        if parent_node:
            # Create a new child node and add it to the parent's children
            new_child = TreeNode(child_value)
            parent_node.children.append(new_child)
        else:
            print(f"Parent node with value {parent_value} not found.")
    
    def find_node(self, current_node, value):
        # Base case: if current node matches the value, return it
        if current_node.value == value:
            return current_node
        # Recursive case: search in the children
        for child in current_node.children:
            result = self.find_node(child, value)
            if result:
                return result
        return None  # Return None if the node is not found
    
    def print_tree(self, node=None, level=0):
        # Start from the root if no node is specified
        if node is None:
            node = self.root
        # Print the current node value with indentation based on the level
        print(" " * (level * 4) + str(node.value))
        # Recursively print the children
        for child in node.children:
            self.print_tree(child, level + 1)

# Create a general tree with 10 as the root
tree = GeneralTree(10)

# Add children to the root
tree.add_child(10, 5)
tree.add_child(10, 20)

# Print the tree structure
tree.print_tree()

 




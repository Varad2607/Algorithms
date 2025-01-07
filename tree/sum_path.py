class TreeNode:
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree(arr):
    if not arr:
        return None
    
    # Create nodes for the entire array
    nodes = [TreeNode(val) for val in arr]
    
    for i in range(len(nodes)):
        # Calculate left child index
        left_index = 2 * i + 1
        # Calculate right child index
        right_index = 2 * i + 2
        
        # Assign left child if within array bounds
        if left_index < len(nodes):
            nodes[i].left = nodes[left_index]
        
        # Assign right child if within array bounds
        if right_index < len(nodes):
            nodes[i].right = nodes[right_index]
    
    return nodes[0]

def inorder_traversal(root):
    def traverse(node):
        if not node:
            return []
        return (
            traverse(node.left) + 
            [node.val] + 
            traverse(node.right)
        )
    
    return traverse(root)

def main():
    # Test case 1
    arr1 = [1, 2, 3, 4, 5, 6, 7]
    root1 = build_tree(arr1)
    print("Inorder Traversal of Tree 1:")
    print(inorder_traversal(root1))
    
    # Test case 2
    arr2 = [4, 9, 0, 5, 1]
    root2 = build_tree(arr2)
    print("\nInorder Traversal of Tree 2:")
    print(inorder_traversal(root2))

if __name__ == "__main__":
    main()
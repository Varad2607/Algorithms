class TreeNode:
    def __init__(self,value):
        self.value=value
        self.children=[]

class Tree:
    def __init__(self,root_value):
        self.root=TreeNode(root_value)
    
    def add_child(self,parent_node,child_node):
        parent_node=self.find_node(TreeNode(parent_node))


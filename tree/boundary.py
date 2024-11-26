class TreeNode:
    def __init__(self,value):
        self.value=value
        self.left=None
        self.right=None


    @classmethod
    def build_tree(cls):
        # Ask for the node data
        data=int(input("Enter the data for the Node"))
        if data==-1:
            return None
        root=cls(data)
        print(f"Enter data for left of {data}:")
        root.left=cls.build_tree()
        print(f"Enter data to the right of {data}:")
        root.right=cls.build_tree()
        return root

    def print_left_node(self):
        if self:
            if self.left:
                self.result.append(self.value)
                self.print_left_boundary(self.left)
            elif self.right:
                self.result.append(self.value)
                self.print_left_boundary(self.right)
                

    def print_leaves(self):
        if self:
            pass
    

    def print_right_node(self):
        if self:
            pass

    def boundary_traversal(self):
        if not self:
            return []
        if self.left or self.right:
            self.result.append(self.value)
        
        self.print_left_node()



    
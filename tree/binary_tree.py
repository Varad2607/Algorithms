import queue
from collections import deque



class Node:
    def __init__(self,value):
        self.value=value
        self.left=None
        self.right=None

    @classmethod
    def build_tree(cls):
        data=int(input("Enter the data which you want to add"))
        if data==-1:
            return None
        root=cls(data)
        print("Enter data to the left of Node")
        root.left=cls.build_tree()
        print("Enter data to the right of Node")
        root.right=cls.build_tree()
        return root
    
    def preorder(self):
        if self.value==None:
            return None
        print(self.value)
        if self.left:
            self.left.preorder()
        if self.right:
            self.right.preorder()

    def postorder(self):
        if self.value==None:
            return None
        if self.left:
            self.left.postorder()
        if self.right:
            self.right.postorder()
        print(self.value)

    def inorder(self):
        if self.value==None:
            return None
        if self.left:
            self.left.inorder()
        if self.right:
            self.right.inorder()
        print(self.value)
        

    def level_order_traversal(self):
        # Use via iteration
        # Queue has FIFO property
        q=queue.Queue()
        q.add(self.value)
        q.add(None)

        while not q.empty():
            current_node=q.remove()
            if current_node==None:
                print("\n")
                if q.empty():
                    break
                else:
                    q.add(None)
            else:
                print(current_node)
                if current_node.left!=None:
                    q.add(current_node.left)
                if current_node.right!=None:
                    q.add(current_node.right)

    def count_nodes(self):
        if self.value==None:
            return None

        countleft=self.count_nodes(self.left)
        countright=self.count_nodes(self.right)
        return countleft +countright +1

    def sum_of_nodes(self):
        if self.value==None:
            return None

        sumleft=self.sum_of_nodes(self.left)
        sumright=self.sum_of_nodes(self.right)

        return sumleft + sumright + self.value

    def height_of_tree(self):
        if self.value==None:
            return None

        height_left=self.height_of_tree(self.left)
        height_right=self.height_of_tree(self.right)
        max_height=max(height_left,height_right)

        return 1 + max_height


    def diameter_tree(self):
        if not self:
            return 0

        dia_left=self.left.diameter()
        dia_right=self.right.diameter()

        dia_root=self.left.height_of_tree_self.right.height_of_tree()+1

        return max(dia_root,max(dia_left,dia_right))
    
    def diameter_fast(self):
        if self is None:
            return (0,0)
        
        left=self.left.diameter_fast()
        right=self.right.diameter_fast()

        option1=left[0]
        option2=right[0]
        option3=left[1]+right[1]+1

        
        current_diameter=max(option1,max(option2,option3))
        current_height=max(left[1],right[1])+1

        return (current_diameter,current_height)

    class TreeInfo:
        def __init__(self,dia,height):
            self.dia=dia
            self.height=height

    def diameter_fast(self):
        if self is None:
            return (0,0)

        left=self.left.diameter_fast()
        right=self.right.diameter_fast()

        option1=left[0]
        option2=right[0]
        option3=left[1]+right[1]

        current_diameter=max(option1,max(option2,option3))
        current_height=max(left[1],right[1])+1

        return Node.TreeInfo(current_diameter,current_height)

    def zigzag_traversal(self):
        if self is None:
            return None

        q=queue.Queue()
        q.put(self)
        q.put(None)
        left_to_right=True

        while q is not q.empty():
            current_node=q.pop()
            
            if current_node==None:
                left_to_right=False
                if q.empty():
                    break
                else:
                    q.put(None)
            else:
                print(current_node)
                if left_to_right:
                    if current_node.left:
                        q.put(current_node.left)
                    if current_node.right:
                        q.put(current_node.right)
                    left_to_right=False
                else:
                    if current_node.right:
                        q.put(current_node.right)
                    if current_node.left:
                        q.put(current_node.left)


    def zigzag_traversal(root):
        if not root:
            return []

        result = []
        q = deque()
        q.append(root)
        left_to_right = True

        while q:
            size = len(q)
            level = [0] * size  # Temporary storage for the current level

            for i in range(size):
                node = q.popleft()

                # Determine where to place the value in the level list
                index = i if left_to_right else size - 1 - i
                level[index] = node.val

                # Add cifhild nodes to the queue
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            # Add the level to the result
            result.extend(level)
            # Flip the direction
            left_to_right = not left_to_right

        return result


    def print_left_boundary(self):
        if self:
            if self.left:
                self.result.append(self.value)
                self.print_left_boundary(self.left)
            elif self.right:
                self.result.append(self.value)
                self.print_left_boundary(self.right)

    def print_leaves(self):
        if self:
            self.print_leaves(self.left)
        if not self.left and not self.right:
            self.result.append(self.value)
        self.print_leaves(self.right)
  

    def print_right_boundary(self):
        if self:
            if self.right:
                self.print_right_boundary(self.right)
                self.result.append(self.value)
            elif self.left:
                self.print_right_boundary(self.left)
                self.result(self.value)


    def boundary_traversal(self):
        if not self:
            return []
        self.result=[]

        # Add root node to the list
        if self.left or self.right:
            self.result.append(self.value)
        
        self.print_left_boundary(self)
        self.print_leaves(self)
        self.print_right_boundary(self)
























                    
            


    





        






    
        







    

    




       



                

                








        
        

def main():
    root=Node()
    root.build_tree()
    root.preorder()
    root.postorder()
    root.inorder()
    root.level_order_traversal()


if __name__=='__main__':
    main()

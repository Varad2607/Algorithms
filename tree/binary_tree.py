import queue



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


    def diamter_of_tree(self):
        if self is None:
            return 0

        diameter_left=self.left.diameter_left()
        diameter_right=self.right.diamter_right()
        diamter_left_right=self.left.height_of_tree()+self.right.height_of_tree()

        return max(diameter_left,max(diameter_left,diameter_right))





        pass



                

                








        
        

def main():
    root=Node()
    root.build_tree()
    root.preorder()
    root.postorder()
    root.inorder()
    root.level_order_traversal()


if __name__=='__main__':
    main()

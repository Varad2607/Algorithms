# In python we use classes to create objects
# Objects are made up of attributes and methods


class Fruit:
    def _init__(self):
        # Here name and color are attributes
        self.name="apple"
        self.color="red"
        
# my fruit is object
# access the attributes by using.


my_fruit=Fruit()
# The above implementation is bad as we cannot use the attributes in our use


# This is correct approach to use the class
class Fruit:
    def __init__(self,name,clr):
        # This is where we declare all the attributes, this automatically executed with every new class declared 
        self.name=name
        self.color=clr
    

    # This is known as methods, we have to pass self always
    def details(self):
        # self.name this can be used here
        pass 


class Guitar:
    def __init__(self):
        self.n_strings=6

    def play(self):
        pass

class Electric_guiter(Guitar):
    def __init__(self):
        super().__init__()
        self.n_strings=8
    def play(self):
        print("play")



my_gu=Guitar()




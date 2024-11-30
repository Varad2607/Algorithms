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





# self is a reference to the current instance of class
# when we create using init we pass self to access attributes and methods in class
# can you give example
# what is difference between @classmethod and @instancemethod

# classmethod
# are used when you want to work with class itself rather then instances of the class
# they take cls as a parameter instead self


# Inheritance
# It helps to create child class based on existing class from parent class
# This is very good to aviod repeatation of the code


class Dog:
    def __init__(self,name,age,friendliness):
        self.name=name
        self.age=age
        self.friendliness=friendliness


# Samoyed is child class of dog
class Samoyed(Dog):
    def __init__(self,name,age,friendliness):
        super().__init__(name,age,friendliness)

        self.name=name
    

    def likes_walks(self):
        return True


class Poodle:
    def __init__(self,name):
        self.name=name

    def likes_walks(self):
        return True


class Goldenretriver:
    def __init__(self,name):
        self.name=name

    def likes_walks(self):
        return 


sammy=Samoyed('Sammy',2,10)   
print(sammy.name,sammy.age,sammy.friendliness)




# Multiple Inheritance


class Goldendoodle(Poodle,Goldenretriver):
    pass



class Student:
    def __init__(self,name,age,number):
        self.name=name
        self.age=age
        self.number=number
        price=10
        self.price=price

class Varad(Student):
    def __init__(self,name,age,number):
        print(self.price)
        


stu=Varad('stff',10,10)

class dvd:
    def method(self):
        pass

class om(dvd):
    def cando(self):
        self.method()
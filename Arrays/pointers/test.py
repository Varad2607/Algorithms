#This is implemtation of try and except block in python
def main():
    try:
        a=int(input("Enter a number: "))
        print(a)
    except ValueError:
        print("Enter a valid number")

#This is information about strings
#remember strings have eol character at the end
    name="Hello"
    for i in range(len(name)):
        print(name[i])
        print(len(name))
        print(name[5])
    
#String slicing
    print(name[0:3]) #3 is not included
    print(name[1:4]) #4 is not included (last index is not included)
    print(name[1:]) #print from 1 to end
    print(name[:4]) #print from 0 to 3
    print(name[:]) #print whole string
    print(name[-1]) #print last character
    print(name[0:-2]) # this prints from 0 to 3

    











    
if __name__=="__main__":
    main()
    

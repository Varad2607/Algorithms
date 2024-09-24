class My_dict:
    def __init__(self):
        self._arr=[]
        self._my_dict={}
        self._majority_element=len(self._arr)//2
        self._input_array()


    def insert_element_dict(self):
        for i in range(len(self._arr)):
            if self._arr[i] not in self._my_dict:
                self._my_dict[self._arr[i]]=1
            else:
                self._my_dict[self._arr[i]]+=1
        if self._my_dict[self._arr[i]]>self._majority_element:
            print(f"The majority element is {self._arr[i]}")
        return -1
            
        

    def _input_array(self):
        n=int(input("Enter the number of elements in the array: "))
        for i in range(n):
            num=int(input())
            self._arr.append(num)
        self.insert_element_dict()
        

def main():
    obj=My_dict()

if __name__=="__main__":
    main()


    
    

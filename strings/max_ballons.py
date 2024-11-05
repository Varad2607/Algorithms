class Solution:
    """Class to solve the maximum number of balloons problem."""
    def __init__(self) -> None:
        pass

    def max_ballons(self,text:str)->int:
        # pylint: disable=missing-function-docstring
        count_char={}
        for char in text:
            if char not in count_char:
                count_char[char]=1
            else:
                count_char[char]+=1
        
        required_items={'b':1,'a':1,'l':2,'o':2,'n':1}
        max_balloons=float('inf')

        for char, required in required_items.items():
            if char in count_char:
                max_balloons=min(max_balloons,count_char[char]/required)
            else:
                return 0
        return int(max_balloons)



if __name__ == "__main__":
    s=Solution()
    print(s.max_ballons('nlaebolko'))



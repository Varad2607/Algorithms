
from typing import List

class Solution:
    def max_size_array(self,nums:List,k:int):
        n=len(nums)
        if n<k:    #Edge case 
            return 0
        current_sum=sum(nums[:k])
        result=current_sum
        for i in range(k,n):
            current_sum+=nums[i]-nums[i-k]
            result=max(current_sum,result)
        return result






if __name__=="__main__":
    s=Solution()
    print(s.max_size_array([1,2,6,4,2,1],3))


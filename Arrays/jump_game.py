from typing import List




class Solution:
    def jump(self, nums:List[int]) -> int:
        farthest_reach=0
        n=len(nums)
        min_jump=0
        for i in range (len(nums)):
            farthest_reach+=nums[i]
            if farthest_reach>=n-1:
                min_jump=i
                min_jump=min(min_jump,farthest_reach)
        return min_jump



if __name__=="__main__":
    s=Solution()
    print(s.jump([2,3,1,1,4]))
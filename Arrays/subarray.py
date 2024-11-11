# Problem: Minimum Size Subarray Sum
# Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
# Example 1:
from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        array_sum = sum(nums[:])
        length=len(nums)
        end=len(nums)
        current_sum=0
        for i in range(len(nums)):
            current_sum=sum(nums[i:end])
            if current_sum==target or current_sum>=target:
                current_length=len(nums)-i
                length=min(length,current_length)
        if current_sum<target and i<end-1:
            return 0
        else:
            return length
       


if __name__=='__main__':
    target=7
    nums=[2,3,1,2,4,3]
    s=Solution()
    print(s.minSubArrayLen(target,nums))

        
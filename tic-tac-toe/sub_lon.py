class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left=0
        ans=0
        dict={}
        counter=0
        for right in range (len(s)):
            if s[right] not in dict:
                dict[s[right]]=0
            else:
                if s[right] in dict:
                    ans=max(ans,right-left)
                    del dict[s[left]]
                    left+=1

        return ans

            

        

if __name__ == "__main__":
    s = "abcabcbb"
    print(Solution().lengthOfLongestSubstring(s))

            

        
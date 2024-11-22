class Solution:
    def validPalindrome(self, s: str) -> bool:
        valid=len(s)-1
        valid_2=len(s)/2
        valid_3=round(valid_2)+1
        dict={}
        for i in range (len(s)):
            if s[i] not in dict:
                dict[s[i]]=1
            else:
                dict[s[i]]+=1
        if len(dict)==valid:
            return True
        elif len(dict)==valid_3:
            return True
        else:
            return False

if __name__=="__main__":
    s=Solution()
    print(s.validPalindrome("acbca"))

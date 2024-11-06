
<<<<<<< HEAD
=======



>>>>>>> 4b3077416194bef5b90108f676fabe9181b1d5fe
#Things I learned in this code:
#1. len(s) is the number of characters in s, while len(s)-1 is the index of the last character in s.
#2. j==len(s) means that we have found all the characters of s in t.
#3 Empty string is a substring of any string.
#4 The for loop runs len(t) times, and the if statement runs len(s) times.
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        j=0
        if len(s)==0:
            return True
        for i in range(len(t)):
            if s[j]==t[i]:
                j+=1
            if j==len(s):
                return True

        return False
            

if __name__ == "__main__":
    sol=Solution()
    print(sol.isSubsequence("abc", "ahbgdc"))

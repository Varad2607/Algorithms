class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dict_1={}
        dict_2={}
        for char in s:
            if char not in dict_1:
                dict_1[char]=1
            else:
                dict_1[char]+=1
        print(dict_1)
        for char_1 in t:
            if char_1 not in dict_2:
                dict_2[char_1]=1
            else:
                dict_2[char_1]+=1
        print(dict_2)
        for chars in s:
            if dict_1[char]!=dict_2[char_1]:
                return False
        return True



if __name__=="__main__":
    s=Solution()
    print(s.isIsomorphic("egg","add"))

        
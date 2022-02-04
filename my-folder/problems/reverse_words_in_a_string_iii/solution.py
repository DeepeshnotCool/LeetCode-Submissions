class Solution:
    def reverseWords(self, s: str) -> str:
        s1 = s.split()
        s2 = ""
        for i in s1:
            s2 += i[::-1] + " "
        return s2[:len(s)]
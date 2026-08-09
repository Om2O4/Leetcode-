class Solution:
    def maxProfit(s, p: List[int]) -> int:
            h1=h2=-p[0]
            s1=s2=0
            for x in p:
                h1=max(h1,-x)
                s1=max(s1,h1+x)
                h2=max(h2,s1-x)
                s2=max(s2,h2+x)
            return s2

class Solution:
    def maxProfit(s, p: List[int]) -> int:
        l=0
        r=1
        m_p=0
        while r < len(p):
            currp = p[r]-p[l]
            if p[l]<p[r]:
                m_p=max(currp,m_p)
            else:
                l=r
            r+=1
        return m_p
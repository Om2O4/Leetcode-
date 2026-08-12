class Solution:
    def maxSubarrayLength(s, n: List[int], k: int) -> int:
        freq = {}
        left = 0
        ans = 0
        for right in range(len(n)):
            freq[n[right]] = freq.get(n[right], 0) + 1

            while freq[n[right]] > k:
                freq[n[left]] -= 1
                left += 1
            ans = max(ans, right - left + 1)
        return ans
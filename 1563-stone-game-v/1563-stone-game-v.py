class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stoneValue[i]

        def rangeSum(l, r):
            return prefix[r + 1] - prefix[l]

        NEG = float('-inf')
        dp = [[0] * n for _ in range(n)]
        ML = [[0] * n for _ in range(n)]   # ML[i][k] = max_{k'<=k} sum(i,k')+dp[i][k']
        MR = [[NEG] * n for _ in range(n)] # MR[k][j] = max_{k'>=k} sum(k'+1,j)+dp[k'+1][j]

        for i in range(n):
            ML[i][i] = rangeSum(i, i) + dp[i][i]
            MR[i][i] = NEG

        for length in range(2, n + 1):
            for i in range(0, n - length + 1):
                j = i + length - 1

                MR[i][j] = max(MR[i + 1][j], rangeSum(i + 1, j) + dp[i + 1][j])

                # binary search for the largest k with leftSum <= rightSum
                lo, hi = i, j - 1
                bestK = i - 1
                while lo <= hi:
                    mid = (lo + hi) // 2
                    if rangeSum(i, mid) <= rangeSum(mid + 1, j):
                        bestK = mid
                        lo = mid + 1
                    else:
                        hi = mid - 1

                best = 0
                if bestK >= i:
                    best = max(best, ML[i][bestK])
                if bestK + 1 <= j - 1:
                    best = max(best, MR[bestK + 1][j])
                # tie-break: exact equality at bestK allows either side
                if i <= bestK <= j - 1:
                    ls = rangeSum(i, bestK)
                    rs = rangeSum(bestK + 1, j)
                    if ls == rs:
                        best = max(best, rs + dp[bestK + 1][j])

                dp[i][j] = best
                ML[i][j] = max(ML[i][j - 1], rangeSum(i, j) + dp[i][j])

        return dp[0][n - 1]
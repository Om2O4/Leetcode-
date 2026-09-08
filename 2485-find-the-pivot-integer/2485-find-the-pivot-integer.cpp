class Solution {
public:
    int pivotInteger(int n) {
        int total_sum = n * (n + 1) / 2;
        int pivot_sq = total_sum;
        
        int x = std::sqrt(pivot_sq);
        if (x * x == pivot_sq) {
            return x;
        }        
        return -1;
    }
};
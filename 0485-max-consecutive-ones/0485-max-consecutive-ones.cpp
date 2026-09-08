class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_streak = 0;
        int current_streak = 0;
        
        for (int num : nums) {
            if (num == 1) {
                current_streak++;
                max_streak = std::max(max_streak, current_streak);
            } else {
                current_streak = 0;
            }
        }
        
        return max_streak;
    }
};
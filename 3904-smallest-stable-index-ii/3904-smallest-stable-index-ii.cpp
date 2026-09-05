class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxf = -1;
        int cd = 0, cMax = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxf = max(maxf, nums[i]);

            if (i == cd) cMax = maxf;

            if (nums[i] < cMax - k)
                cd = i + 1;
        }

        return cd < nums.size() ? cd : -1;
    }
};
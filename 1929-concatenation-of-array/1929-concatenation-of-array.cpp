class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};
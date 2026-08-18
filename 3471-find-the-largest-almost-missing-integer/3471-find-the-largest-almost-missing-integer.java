class Solution {
    public int largestInteger(int[] nums, int k) {
        int[] count = new int[100];
        for (int num : nums) {
            count[num]++;
        }
        if (k == 1) {
            return findLargestUniqueNumber(count);
        }
        if (k == nums.length) {
            return findLargestNumber(nums);
        }
        return findLargestUniqueEdgeNumber(nums, count);
    }

    private int findLargestUniqueNumber(int[] count) {
        int max = -1;
        for (int num = 0; num < count.length; num++) {
            if (count[num] == 1) {
                max = num;
            }
        }
        return max;
    }

    private int findLargestNumber(int[] nums) {
        int max = -1;

        for (int num : nums) {
            max = Math.max(max, num);
        }
        return max;
    }

    private int findLargestUniqueEdgeNumber(int[] nums, int[] count) {
        int max = -1;
        if (count[nums[0]] == 1) {
            max = nums[0];
        }
        if (count[nums[nums.length - 1]] == 1) {
            max = Math.max(max, nums[nums.length - 1]);
        }
        return max;
    }
}
class Solution {
    public void rotate(int[] nums, int k) {
        int[] numsc = nums.clone();
        int idx = 0;
        int target = (nums.length - k) % nums.length;
        if (target < 0) target += nums.length;
        for (int i = 0; i < nums.length; ++i)
        {
            if (target < nums.length) nums[i] = numsc[target++];
            else nums[i] = numsc[idx++];
        }
    }
}
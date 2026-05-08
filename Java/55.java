class Solution {
    public boolean canJump(int[] nums) {
        int jump_len = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; ++i)
        {
            if (nums[i] > jump_len) jump_len = nums[i];
            if (jump_len >= nums.length - 1 - i) return true;
            if (jump_len == 0) return false;
            --jump_len;
        }

        return false;
    }
}
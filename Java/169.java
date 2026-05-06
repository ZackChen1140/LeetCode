class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> d = new HashMap<>();
        Integer majorE = 0;
        Integer majorEn = 0;
        for (Integer i = 0; i < nums.length; ++i)
        {
            if (d.containsKey(nums[i]))
            {
                d.put(nums[i], d.get(nums[i]) + 1);
            }
            else d.put(nums[i], 1);

            if (d.get(nums[i]) > majorEn)
            {
                majorE = nums[i];
                majorEn = d.get(nums[i]);
            }
        }

        return majorE;
    }
}
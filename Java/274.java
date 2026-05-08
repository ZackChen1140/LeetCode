class Solution {
    public int hIndex(int[] citations) {
        int h = citations.length;
        int m;
        for (; h > 0; --h)
        {
            m = citations.length - h + 1;
            for (int i = 0; i < citations.length; ++i)
            {
                if (citations[i] < h) --m;
                if (m == 0) break;
            }
            if (m > 0) break;
        }

        return h;
    }
}
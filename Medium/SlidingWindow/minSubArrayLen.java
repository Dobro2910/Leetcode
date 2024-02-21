package Medium.SlidingWindow;

public class minSubArrayLen {
    public int minSubArrayLen(int target, int[] nums) {
        int smallestCount = 2147483647;
        int largestTotal = 0;
        int total = nums[0];
        int count = 1;
        int i = 0;
        int j = 0;

        while (i != nums.length) {
            if (total < target) {
                j++;

                if (j == nums.length) {
                    break;
                }

                total = total + nums[j];
                count++;
            } else if (total >= target) {
                if (count < smallestCount) {
                    smallestCount = count;
                }
                if (largestTotal < total) {
                    largestTotal = total;
                }
                total = total - nums[i];
                count--;
                i++;
            }
        }

        if (largestTotal < target) {
            return 0;
        }

        return smallestCount;
    }
}

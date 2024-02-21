package Medium.Arrays;

// not completed
public class jumpGame {
    public boolean canJump(int[] nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.length; i++) {
            // If the current index is beyond the furthest position you can reach, return false
            if (i > maxReach) {
                return false;
            }

            // Update the furthest position you can reach from the current index
            maxReach = Math.max(maxReach, i + nums[i]);

            // If you can reach the last index, return true
            if (maxReach >= nums.length - 1) {
                return true;
            }
        }

        return false;
    }
}

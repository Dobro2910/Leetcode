package Medium.Arrays;

// not completed
public class jumpGame2 {
    public int jump(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return 0; // Already at the end
        }

        int jumps = 0;
        int maxDistance = 0; // Represents the current farthest point that can be reached with the current number of jumps
        int farthestJump = 0; // Represents the farthest point that can be reached with the current number of jumps

        for (int i = 0; i < n - 1; i++) {
            farthestJump = Math.max(farthestJump, i + nums[i]);

            if (i == maxDistance) {
                // We've reached the current maximum reachable point
                maxDistance = farthestJump; // Update the current farthest point
                jumps++;
            }
        }

        return jumps;
    }
}

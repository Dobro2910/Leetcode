package Easy.Arrays;
import java.util.ArrayList;

public class removeElement {
    public int removeElement(int[] nums, int val) {
        // ArrayList<Integer> numsOutput = new ArrayList<>();
        int k = 0;
        int j = 0;

        for (int i = 0;i < nums.length; i++) {
            if (nums[i] != val) {
                // numsOutput.add(nums[i]);
                nums[j] = nums[i];
                j++;
                k++;
            }
        }
        
        return k;
    }
}

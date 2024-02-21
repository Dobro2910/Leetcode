package Medium.Arrays;

import java.util.ArrayList;

public class rotateArray {
    public void rotate(int[] nums, int k) {
        ArrayList<Integer> numsList = new ArrayList<>();
        
        if (k > nums.length) {
            k = k % nums.length;
        }

        for (int i = nums.length - k; i < nums.length; i++) {
            numsList.add(nums[i]);
        }

        for (int i = 0; i < nums.length - k; i++) {
            numsList.add(nums[i]);
        }

        for (int i = 0; i < nums.length; i++) {
            nums[i] = numsList.get(i);
        }
    }
}

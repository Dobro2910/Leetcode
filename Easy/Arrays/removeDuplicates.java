package Easy.Arrays;

public class removeDuplicates {
    public int removeDuplicates(int[] nums) {
        int j = 1; 
        int k = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                nums[j] = nums[i];
                j++;
                k++;
            }
        }

        return k;
    }
}

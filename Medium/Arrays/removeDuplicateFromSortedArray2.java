package Medium.Arrays;

public class removeDuplicateFromSortedArray2 {
    public int removeDuplicates(int[] nums) {
        int j = 1; 
        int k = 1;

        boolean addEnd = false;
        if (nums.length < 3) {
            return nums.length;
        }
        if (nums[nums.length - 1] > nums[nums.length - 3] || nums[nums.length - 1] == nums[nums.length - 3]) {
            addEnd = true;
        }

        for (int i = 1; i < nums.length - 1; i++) {
            if (nums[i] == nums[i - 1] && nums[i] != nums[i + 1]) {
                nums[j] = nums[i];
                j++;
                k++;
            } else if (nums[i] > nums[i - 1]) {
                nums[j] = nums[i];
                j++;
                k++;
            }
        }

        if (addEnd == true) {
            nums[j] = nums[nums.length - 1];
            k++;
        }

        return k;
    }
}

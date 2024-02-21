package Easy.Arrays;

import java.util.HashMap;
import java.util.Map;

public class majorityElement {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> hashMap = new HashMap<>();
        int product = 0;

        for (int i = 0; i < nums.length; i++) {
            hashMap.put(nums[i], 0);
        }
        
        for (int i = 0; i < nums.length; i++) {
            hashMap.put(nums[i], hashMap.get(nums[i]) + 1);
            if (hashMap.get(nums[i]) > nums.length/2) {
                product = nums[i];
            }
        }

        return product;
    }
}

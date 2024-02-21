package Medium.TwoPointer;

public class containerWithMostWater {
    class Solution {
        public int maxArea(int[] height) {
            int largest = 0;
            int current = 0;
            int i = 0;
            int j = height.length - 1;
    
            while (i != j) {
                if (height[i] < height[j]) {
                    current = height[i]  * (j-i);
                    i++;
                } else if (height[i] >= height[j]) {
                    current = height[j]  * (j-i);
                    j--;
                }
    
                if (largest < current) {
                    largest = current;
                }
            }
    
            return largest;
        }
    }
}

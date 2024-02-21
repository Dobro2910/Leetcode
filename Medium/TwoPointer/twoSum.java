package Medium.TwoPointer;

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                if (numbers[i] + numbers[j] == target) {
                    // Return an array with the indices i and j
                    return new int[]{i + 1, j + 1};
                }
            }
        }
        // If no solution is found, return an empty array or throw an exception
        return new int[]{};
    }
}

package Medium.Hashmap;
import java.util.HashMap;
import java.util.Arrays;

public class longestSequence {
    public int longestConsecutive(int[] nums) {
        int longestSequence = 0;
        HashMap<Integer, Integer> numsHashMap = new HashMap<>();

        for (int num : nums) {
            // Skip if num is already in the map (to avoid unnecessary processing)
            if (numsHashMap.containsKey(num))
                continue;

            // Find the lengths of left and right consecutive sequences
            int leftLength = numsHashMap.getOrDefault(num - 1, 0);
            int rightLength = numsHashMap.getOrDefault(num + 1, 0);

            // Calculate the current sequence length and update the longestSequence
            int currentSequenceLength = leftLength + rightLength + 1;
            longestSequence = Math.max(longestSequence, currentSequenceLength);

            // Update the lengths of adjacent sequences
            numsHashMap.put(num, currentSequenceLength);
            numsHashMap.put(num - leftLength, currentSequenceLength);
            numsHashMap.put(num + rightLength, currentSequenceLength);
        }

        return longestSequence;
    }
}

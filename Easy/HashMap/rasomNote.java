package Easy.HashMap;

import java.util.HashMap;

public class rasomNote {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> hashMap = new HashMap<>();

        for (int i = 0; i < magazine.length(); i++) {
            if (hashMap.containsKey(magazine.charAt(i))) {
                int currentCount = hashMap.get(magazine.charAt(i));
                hashMap.put(magazine.charAt(i), currentCount + 1);
            } else {
                hashMap.put(magazine.charAt(i), 1);
            }
        }

        for (int i = 0; i < ransomNote.length(); i++) {
            if (hashMap.containsKey(ransomNote.charAt(i))) {
                if (hashMap.get(ransomNote.charAt(i)) > 0) {
                    int currentCount = hashMap.get(ransomNote.charAt(i));
                    hashMap.put(ransomNote.charAt(i), currentCount - 1);
                    System.out.println(hashMap);
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
}

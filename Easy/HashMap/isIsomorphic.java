package Easy.HashMap;

import java.util.HashMap;

public class isIsomorphic {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> hashMap = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            if (hashMap.containsKey(s.charAt(i))) {
                if (hashMap.get(s.charAt(i)) != t.charAt(i)) {
                    return false;
                } 
            } else {
                for (Character value : hashMap.values()) {
                    if (value.equals(t.charAt(i))) {
                        return false;
                    }
                }
                hashMap.put(s.charAt(i), t.charAt(i));
                
            }
        }

        return true;
    }
}

package Easy.Arrays;

public class maxProfit {
    public int maxProfit(int[] prices) {
        int max = 0;
        int min = 2147483647;

        if (prices.length < 2) {
            return max;
        }

        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < min) {
                min = prices[i];
            } 
            
            if (prices[i] - min > max) {
                max = prices[i] - min ;
            }
        }

        return max;
    }
}

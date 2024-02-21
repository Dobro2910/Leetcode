package Medium.Arrays;

public class maxProfit2 {
    public int maxProfit(int[] prices) {
        int total = 0;

        if (prices.length < 2) {
            return total;
        }

        int i = 0;
        int j = 1;

        while (i < prices.length && j < prices.length) {
            if (prices[j] > prices[i]) {
                total = total + (prices[j] - prices[i]);
            }
            i++;
            j++;
        }

        return total;
    }
}

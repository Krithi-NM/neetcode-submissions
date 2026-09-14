class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];
        int buy = 0;
        int cooldown = 0;

        for (int i = 1; i < prices.size(); i++) {
            int prevHold = hold;
            int prevBuy = buy;
            int prevCooldown = cooldown;

            hold = max(prevHold, prevBuy - prices[i]);
            buy = max(prevBuy, prevCooldown);
            cooldown = prevHold + prices[i];
        }

        return max(buy, cooldown);
    }
};
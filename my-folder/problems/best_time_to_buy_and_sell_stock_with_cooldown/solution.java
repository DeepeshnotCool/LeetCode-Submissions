class Solution {
        public int maxProfit(int[] prices){
        int len=prices.length;
        if(len==0)return 0;
        int sell=0, buy=-prices[0], cool=0, min_buy=buy, tmp=sell;
        for(int i=1;i<len;i++){
            sell=min_buy+prices[i];// sell
            buy=cool-prices[i];// buy
            cool=Math.max(cool,tmp);
            tmp=sell;
            min_buy=Math.max(min_buy, buy);
        }
        return Math.max(sell,cool);
    
    }
}
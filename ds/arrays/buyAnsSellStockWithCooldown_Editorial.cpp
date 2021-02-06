// leetcode : 309
// Best Time to Buy and Sell Stock with Cooldown
// solution : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75927/Share-my-thinking-process/see the comment section
#include <bits/std++.h>
using namespace std;

/*  Logic Explained :
    conditions:
        1) buy before sell
        2) and hr 2 consecutive buy's ke beech me cooldown period hona chahiye

    ** yaha 3 possiblilities h:
        1) ya ho hmare buy aor sell ka silsila buy pr aake khtm ho jaeyge, ex: buy sell cooldown buy
        2) ya yeh silsila sell pr aake khtm hoga, ex : buy sell cooldown cooldown buy sell
        3) ya yeh cooldown pr aake khtm hoga, ex : buy sell cooldown cooldown


        toh isse solve kese krna h ?
        hm issme 2 arrays bana lete h
            buy[i] : jo max-proft (i-1)'th index tk hmne kmaiyi h, and agar hm i'th index ki value ko buy lele
                    toh insm ja maximum jo hoga..yani max-profit wo hm buy[i] me save krenge
                    ab jes ki conditions me bata rkha h ki 2 consecutive buy-sells ke beech me km se km ek cooldown period hona chahiye
                    ..toh agar hme ye dekhna h ki i'th index se pehle tk kitna max-profit kmaya h hmne toh hm,
                    (sell[i-2] - price[i]) :- kyuki sell[i-2] hme wo max-profit ki value lake dega jo cooldown period se pehle tha,
                    and kyuki hm i'th index pr buy krne wale h, mtlb price[i] subtract kr denge uss mese, mtlb (i-2)'th index tk jitna bhi profit hua h
                    ussme se price[i] ko minus krke jo bhi value aayegi, usko hm compare krenge uss max-profit ke sath jo (i-1)'th index ko buy krne pr mili thi
                    ..and max((sell[i-2]-prices[i]), buy[i-1]), hogo wo hme i'th index pr buy krne pr kitna max-profit mil skta h , wo batayega

            sell[i] : kyuki hm sell toh kbhi bhi kr skte h, cooldown wali conditions toh bs buy pr lgi h
                    toh i'th index tk max-profit kitni h,
                    toh agar hm prices[i] ko consideration me le, and ek bari na le, toh max-profit kis condition me zyada milegi,
                    jisbhi condition me max-profit zyada lile usse , hm iss index pr store kr denge
                    // buy[i-1] + prices[i] : current value ko consideration me leke jo max-profit milega,
                    ab kyuki sell krne se pehle buy krna pdegal, toh buy[i-1] hme buy ki latest value lake dega ,(jisme obviuosly max-profit mile)
                    toh sell[i] = max((buy[i-1] + prices[i]), sell[i-1])
*/
int maxProfit(vector<int> &prices){
    if(prices.size() < 2)   return 0;

    int n = prices.size();

    vector<int> buy(n+1);
    vector<int> sell(n+1);

    // kyuki array 1 --> n tk chlega (not 0 --> n tk)
    buy[1] = -prices[0];

    for(int i = 2; i <= n; i++){
        int price = prices[i-1];
        buy[i] = max(buy[i-1], sell[i-2]-price);
        sell[i] = max(sell[i-1], buy[i-1]+price);
    }

    // max-profit
    return sell[n];
}


// Driver function
int main(){
    vector<int> prices({1, 2, 3, 0, 2});
    // vector<int> prices({2,1,2,1,0,0,1});

    // cout << sellStockWithCooldown(prices) << endl;
    cout << maxProfit(prices) << endl;

    // sellStockWithCooldown(prices);


    return 0;
}

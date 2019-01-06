/*
 * =====================================================================================
 *
 *       Filename:  coin_change.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/24/2018 12:03:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
class Solution {
    #if 0
    int coinChange(vector<int> &coins, int index, int amount) {
        
        if (amount < coins[index]) {
            if (index > 0) return coinChange(coins, index-1, amount);
            else return(-1);
        }
        //std::cout << amount << "  " << coins[index] << endl;
        int max_count =amount/coins[index]; 
        int rest_amount = amount%coins[index];
        if (rest_amount == 0) return max_count;
        else if ((rest_amount != 0 ) && (index == 0)) return -1; 
        int min = INT_MAX;
        for (int i =max_count; i >=0; i--) {
            int count = coinChange(coins, index-1, rest_amount);
            cout << count << " " ;
            if (count != -1) {
                if ((count + i) < min) min = count + i;
            }
            rest_amount = rest_amount + coins[index];
        }
        if (min == INT_MAX ) return -1;
        return min;
    }
     struct {
        bool operator()(int a, int b) const
        {   
            return a < b;
        }   
    } customMore;
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0 ) return 0;
        if (coins.size() == 0) return -1;
        /* sort the coins in decreasing value order */
        sort(coins.begin(), coins.end(), customMore);
        return coinChange(coins, coins.size()-1, amount);
    }
    #endif
    struct {
        bool operator()(int a, int b) const
        {   
            return a < b;
        }   
    } customMore;
    public:
    int coinChange(vector<int>& coins, int amount) {
        vector <int> min_count((amount+1), -1);
        min_count[0] = 0;
        /* sort the coins in decreasing value order */
        sort(coins.begin(), coins.end(), customMore);
        /* calculate the min_count for all amount from 1 to amount */

        for (int i=1; i<=amount;i++) {
            int coin_count = INT_MAX;
            for (int coin_idx =0; coin_idx<coins.size(); coin_idx++) {
                if (i < coins[coin_idx]) break;
                if (min_count[i-coins[coin_idx]] == -1) continue;
                if (min_count[i - coins[coin_idx]] +1 < coin_count ) {
                    coin_count = min_count[i - coins[coin_idx]] +1;
                }
            }
            if (coin_count != INT_MAX) min_count[i] = coin_count;
            if (amount == 6247) 
                cout << "min count " << i << " " << min_count[i] << endl;
        }
        return min_count[amount];
    }
};

int main (void) {

    Solution obj;
    vector <int > coins = {186,419,83,408};
    int amount = 6249 ;
    cout << obj.coinChange(coins, amount);
    return 0;
}

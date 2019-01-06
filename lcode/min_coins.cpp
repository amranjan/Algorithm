/*
 * =====================================================================================
 *
 *       Filename:  min_coins.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/24/2018 10:36:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <vector>


using namespace std;

/*  Assuming coins are in the desending order  */
/*  [ 5, 2, 1] */
int sum (vector<int> & nums) {
    int s =0;
    for ( int i =0; i < nums.size(); i++) {
        s += nums[i];
    }
    return s;
}
int find_min_coin(vector <int > & coins, int amount) {

    vector<int>nums (coins.size());
    vector<int>rest_amt (coins.size());
    int start_idx  = 0, back =1, end_idx = coins.size() -1;
    int rest_amount = amount;
    while (1) {

        for (int i = start_idx; i <= end_idx ; i++) {
            nums[i] =0;
        }
        for (int i = start_idx; i <= end_idx ; i++) {
            nums[i] = rest_amount/coins[i];
            cout << "nums of coin " << coins[i] << " is " << nums[i] << "\n";
            rest_amount = rest_amount%coins[i];
            if (rest_amount == 0) {
                return sum(nums); /*   */
            }
            rest_amt[i] = rest_amount;
        }
        /*  If rest_amount is non_zero then go back reduce  number os coin by 1 */
        start_idx = end_idx+1;
        /*  check if prevous is non-zero then decreament by 1 */
        if (nums[end_idx - back] != 0) {
            --nums[end_idx - back];
            rest_amount = rest_amt[end_idx-back] + coins[end_idx-back];
            start_idx = end_idx - back +1; /*  start after this point */
        } else {
            /*  no coin of this denomination then just go back one more further  */
            back++;
            if (back > end_idx ) 
                return -1;
        }

    }
}

int main () {
    vector <int> coins  = { 10, 5, 2};

    cout << 5/coins[0] << "\n";
    cout << 5%coins[0] << "\n";
    cout << "\n" << find_min_coin(coins, 5) << "\n";
    cout  << "\n" << find_min_coin(coins, 16) << "\n";

}

/*
 * =====================================================================================
 *
 *       Filename:  permutation.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/03/2019 01:25:59 PM
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
#include <set>

#include <vector>

using namespace std;


class Solution {
    public:
        void permute_int(vector<int> &nums, vector<bool> &used, vector<int> &partial_nums, set<vector<int>> &sol) {
            if (partial_nums.size() == nums.size()) {
                sol.insert(partial_nums);
                return;
            }
            for (int i =0; i < nums.size(); i++) {
                if (!used[i]) {
                    partial_nums.push_back(nums[i]);
                    used[i] = true;
                    permute_int(nums, used, partial_nums, sol);
                    used[i] = false;
                    partial_nums.pop_back();
                }
            }
            return;
        }
        set<vector<int>> permutation (vector<int> &nums) {
            set<vector<int>> sol;
            vector<bool> used(nums.size(), false);
            vector<int> partial_nums;
            sort(nums.begin(), nums.end());
            permute_int(nums, used, partial_nums, sol);

            return sol;
        }

};

int main(void) {
    //vector<int> nums = { 2,1,3}; 
    vector<int> nums = { 5,1,1}; 
    set<vector<int>> sol;
    Solution obj; 
    sol = obj.permutation(nums);

    for (auto _list : sol) {
        for (auto num : _list) {
            cout << num << " " ;
        }
        cout << endl;
    }

    return 1;
}

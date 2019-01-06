/*
 * =====================================================================================
 *
 *       Filename:  binary_search.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  08/19/2018 07:17:02 PM
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
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min_idx = 0, max_idx = nums.size()-1; 
        while (1) {
            int middle_idx = (min_idx + max_idx)/2;
            if (target == nums[middle_idx]) {
                return middle_idx;
            } else if ( target < nums[middle_idx]) {
                max_idx = middle_idx-1;
            } else if (target > nums[middle_idx]) {
                min_idx = middle_idx+1;
            }
            /* if min_idx and middle_idx is same then just check against max_idx */
            if(min_idx >= max_idx) {
                if (target == nums[max_idx]) {
                    return max_idx;
                } else {
                    /* element not found */
                    return -1;
                }
            }
        }
        
        
    }
};



int main (void) {

    std::vector <int> a = {-1,0,3,5,9,12};
    Solution s;

    cout << "\n";
    cout << s.search(a, 9);
    cout << s.search(a, 2);
}




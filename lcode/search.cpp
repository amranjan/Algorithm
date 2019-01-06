/*
 * =====================================================================================
 *
 *       Filename:  search.cpp
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
/*  [ 5, 6, 7, 0, 1, 2, 3, 4]  */

/*  [ 6, 0, 1, 2, 3, 4, 5]  */

/*  [ 0, 1, 2, 3, 4, 5, 6]  */

/*    std::vector <int> f =  {4,5,6,7,8,1,2,3} ; */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int find_start_idx(vector<int>& nums) {
        int target = nums[0];
        if (nums[0] < nums[nums.size()-1]) {
            return 0;
        }
        int start = 0, end = nums.size() -1, middle; 
        while (1) {
            middle = start + (end-start + 1)/2 ;
            if (target > nums[middle]) {
                end = middle-1;
            } else if (target < nums[middle]) {
                target = nums[middle];
                start = middle;
            } else if (target == nums[middle]) {
                /*   */
                return ((middle == (nums.size() -1)) ? 0 : middle+1);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        int min_idx = 0, max_idx = nums.size() - 1; 
        min_idx = find_start_idx(nums);
        cout << "min is " << min_idx << "\n";
        if (min_idx != 0) {
            max_idx = min_idx -1;
            if (target <= nums[nums.size()-1]) {
                /*  if target is less than last number then the number falls between
                 *  start idx and last number  else 
                 *  it falls between first number and max_idx */
                max_idx = nums.size() -1;
            } else {
                min_idx = 0;
            }
        }

            cout <<"  min and max " << min_idx << "  " << max_idx << "\n";
        while (1) {
            int middle_idx = (min_idx + max_idx)/2;
            cout <<" middle point  "<< middle_idx <<"\n";
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

    std::vector <int> b = { 5, 6, 0, 1, 2, 3, 4};
    std::vector <int> d = { 0, 1, 2, 3, 4, 5, 6 };
    std::vector <int> e = { 1, 2, 3, 4, 5, 6, 0 };

    std::vector <int> c = { 6, 0, 1, 2, 3, 4, 5};
    std::vector <int> f =  {4,5,6,7,8,1,2,3} ;
    cout << " Starting point \n";
    int xx = 1/2;
    cout <<  xx << "\n\n";

    //cout << s.find_start_idx(b) << "\n";
#if 0
    cout << s.search(a, 9);
    cout << s.search(a, 2) << "\n";
    cout << s.find_start_idx(b) << "\n";
    cout << s.find_start_idx(d) << "\n";
    cout << s.find_start_idx(e) << "\n";
    cout << s.search(c, 2) << "\n";
    cout << s.search(e, 0) << "\n";
    cout << s.search(c, 5) << "\n";
#endif
    cout << "\n\n index for 6 is c "<< s.search(c, 6) << "\n";
    cout << " index for 6 in b is " <<s.search(b, 6) << "\n";
    cout << s.search(b, 5) << "\n\n\n\n";
    cout <<  "\n\n Index for 8 in f is " << s.search(f, 8) << "\n";
}




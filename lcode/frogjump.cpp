/*
 * =====================================================================================
 *
 *       Filename:  frogjump.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/23/2018 03:15:25 PM
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
#include <set>
using namespace std;

    bool canCross(vector<int>& stones) {
        std::vector <std::unordered_set <int>> steps(stones.size()); /* steps */
        steps[1].insert(1);
        if (stones[1] != 1) return false;
        for ( int i=2; i < stones.size(); i++) {
            for (int j =i-1; j >= 1; j--) { /* check till steps 0 */
                for (auto it = steps[j].begin(); it != steps[j].end(); it++) {
                    if (*it+1 == stones[i]-stones[j]) {
                        cout << "for " << stones[i] << " steps size is " << stones[i]-stones[j]<< " from " << stones[j]<< endl;
                        steps[i].insert(*it+1);
                    } else if (*it  == stones[i]-stones[j] ) {
                        steps[i].insert(*it );
                        cout << "for " << stones[i] << " steps size is " << stones[i]-stones[j]<< " from " << stones[j]<<endl;
                    } else if (*it -1  == stones[i]-stones[j]) {
                        steps[i].insert(*it -1);
                        cout << "for " << stones[i] << " steps size is " << stones[i]-stones[j]<< " from " << stones[j]<< endl;
                    } else {
                        cout <<stones[i] << " not reachable from " << stones[j] << "\n" ;
                       // steps[i].push_back(-1);
                       //break;
                    }

                }
            }
        }
        //cout << "steps needed " << steps[stones.size()-1][0] << endl;
        return (!steps[stones.size()-1].empty());
    }
int main(void) {
    vector <int> Stones {0,1,2,3,4,8,9,11 }; // false
    vector <int> Stones1 { 0,1,3,5,6,8,12,17}; // true

    if (canCross(Stones1)) cout << " true\n";
    else cout << "false\n";

    return 1;
}

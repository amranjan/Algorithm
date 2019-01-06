/*
 * =====================================================================================
 *
 *       Filename:  lcode_63_unique_path_recur.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  09/11/2018 09:57:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
public:
    int maxPath(vector<vector<int>>& obstacleGrid, int x, int y){
        int max_path = 0;
        if (obstacleGrid[x][y] != 0) return 0;
        else if ((x == (obstacleGrid.size()-1)) && (y == (obstacleGrid[0].size()-1))){
            return 1;
        }
        if ((x+1) < obstacleGrid.size()) {
            if (obstacleGrid[x+1][y] == 0) {
                max_path += maxPath(obstacleGrid, x+1, y);
            }
        }
        if ((y+1) < obstacleGrid[0].size()) {
            if (obstacleGrid[x][y+1] == 0) {
                max_path += maxPath(obstacleGrid, x, y+1);    
            }
        
        }
        return max_path;
    }
                
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return maxPath(obstacleGrid, 0, 0);
    }
};

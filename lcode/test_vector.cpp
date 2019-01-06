/*
 * =====================================================================================
 *
 *       Filename:  test_vector.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  08/29/2018 08:03:59 PM
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


int test_array[4][4] = {0};

void func_array (int a[4][4], int size) {
    cout << a[2][2] << endl; 

}
int main(void) {
    func_array(test_array, 4);
    int *myset = new  int [500];
    myset[10] = 100;
    cout << myset[10];
    vector <vector <int>> dp(10, vector<int>(10,0));
    dp[3][3] = 100;
    for (int i=0; i< 10; i++) {
        for (int j=0;j<10;j++) {
            cout <<dp[i][j]<< " ";
        }
        cout << endl;
    }



}

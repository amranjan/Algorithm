/*
 * =====================================================================================
 *
 *       Filename:  rotate_matrix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/28/2018 07:59:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;
int matrix[3][3] = { 
                    {1,2,3},
                    {4,5,6},
                    {7,8,9}};


int m2[4][4] = { 
    { 1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16},
};
#define M_SIZE 4 
void print_matrix(int m[][M_SIZE], int size) {
    for (int y=0 ; y < size; y++) { // Y cordinate 
        for ( int x = 0; x< size; x++) {  // X Cordinate 
            cout << m[y][x] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
void rotate_anti_clock(int m[][M_SIZE], int size) {

    for ( int loop = 0; loop < size/2; loop++) {
        int start = loop;
        int max = (size-loop) -1;
        for (int idx = 0; idx < (max-start); idx++) {
            int temp =  m[start][start+idx]; // Save 1st 
            // Copy 4th into 1st 
            m[start][start+idx] = m[start+idx][max];
            /*  Copy 3rd into 4th  */
            m[start+idx][max]= m[max][max-idx];
            /*  Copy 2nd into 3rd  */
            m[max][max-idx] = m[max-idx][start];
            /*  Copy saved 1st into 2nd  */
            m[max-idx][start] = temp;
            // print_matrix(m, M_SIZE);
        }

    }
}


int main () {

    //print_matrix(m2, M_SIZE);
    cout << endl;
    cout << endl;
    rotate_anti_clock(m2, M_SIZE);
    print_matrix(m2, M_SIZE);
    cout << endl;
}






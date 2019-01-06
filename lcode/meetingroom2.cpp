/*
 * =====================================================================================
 *
 *       Filename:  meetingroom1.cpp
 *
 *    Description:  Assign minimum number of meeting rooms 
 *
 *        Version:  1.0
 *        Created:  11/01/2018 09:02:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval (int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
        int minMeetingRooms(vector <Interval> &meetings);
};

int Solution::minMeetingRooms(vector <Interval> &meetings) {
    vector <int> start_times;
    vector <int> end_times;
    for (int i =0; i < meetings.size(); i++) {
        start_times.push_back(meetings[i].start);
        end_times.push_back(meetings[i].end);
    }
    sort(start_times.begin(), start_times.end());
    sort(end_times.begin(), end_times.end());
    auto cur_stime = start_times.begin(); 
    auto cur_etime = end_times.begin();
    int cur_meeting_rooms=0, max_meeting_rooms=0;
    for (int i =0; i < meetings.size(); i++) {
        if (*cur_etime <= *cur_stime) {
            /*  IF start time of cur meeting has passed the endtime then move 
             *  the endtime ptr forward and free up meeting rooms */
            while (*cur_etime <= *cur_stime) {
                cur_meeting_rooms--;
                cur_etime++;
            }
        } 
        /*  Now allocate meetin room for the cur meeting's start time
         *  and move to next start time  */
        cur_meeting_rooms++; 
        if (max_meeting_rooms < cur_meeting_rooms)  {
            max_meeting_rooms=cur_meeting_rooms;
        }
        cur_stime++;
    }

    /* Now run through start list and keep checking for freed meetings.  */

    cout << "Start times are \n";
    for ( auto it = start_times.begin(); it != start_times.end(); it++) {
        cout << *it << endl;
    }
    cout << "End times are \n";
    for ( auto it = end_times.begin(); it != end_times.end(); it++) {
        cout << *it << endl;
    }
    return max_meeting_rooms;
}

int main(void) {
    vector <Interval> m; 
    m.emplace_back(0, 10);
    m.emplace_back(5, 15);
    m.emplace_back(0, 20);
    m.emplace_back(10, 15);
    m.emplace_back(5, 30);
    m.emplace_back(20, 25);

    Solution obj;
    cout << " min rooms needed "<< obj.minMeetingRooms(m) <<endl;

}

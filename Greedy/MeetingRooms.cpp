/*
This problem is from interview bit : https://www.interviewbit.com/problems/meeting-rooms/
Problem Description: Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.
Where:
A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.
Note :- If a meeting ends at time t, another meeting starting at time t can use the same conference room
*/

bool compare(vector<int>A,vector<int>B){
    if(A[0]==B[0])return A[1]<=B[1];
    return A[0]<B[0];
}
int Solution::solve(vector<vector<int> > &A) {
    int ans=0;
    sort(A.begin(),A.end(),compare);
    // unordered_map<int,int>m;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0;i<A.size();i++){
        int cs = A[i][0], ce = A[i][1];
        // int ii=1,flag=0;
        // while(m[ii]){
        //     if(m[ii]<=cs){
        //         m[ii]=ce;
        //         flag=1;
        //         break;
        //     }
        //     ii++;
        // }
        // if(!flag){
        //     ans++;
        //     m[ii]=ce;
        // }
        while (!minHeap.empty() && minHeap.top() <= cs) {
            minHeap.pop();
        }
        minHeap.push(ce);
        ans=max(ans,static_cast<int>(minHeap.size()));
    }
    return ans;
}
/*
The commented part uses map which increases time complexity.  Iterating over map would take O(n) in worst case and since there are n elements, worst case time complexity is O(n^2).
So, we used heap to not repeatedly check for the elements. Insertion and removal in heap = O(log N). N elements => O(N log N). 
*/

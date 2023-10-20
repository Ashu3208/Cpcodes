/*
Problem Statement: Find the minimum steps it takes to reach a knight from source position to destination.
A x B = size of the board  (C,D) = initial position of the knight (E,F): Final position of the knight

Problem Link:
https://www.interviewbit.com/problems/knight-on-chess-board/

*/


int check(int A, int B, int x, int y) {
    return (x >= 1 and x <= A and y >= 1 and y <= B);
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int dx[8] = {-1, +1, -2, +2, -2, +2, -1, +1};
    int dy[8] = {+2, +2, +1, +1, -1, -1, -2, -2};
    int steps=0;
    queue<pair<int,int>>q;
    vector<vector<bool>>visited(A+1,vector<bool>(B+1,false));
    if(C==E and D==F)return 0;
    q.push({C,D});
    visited[C][D]=true;
    while(!q.empty()){
        int size=q.size();
        steps++;
        for(int j=0;j<size;j++){    
        int x = q.front().first,y=q.front().second;
        for (int i = 0; i < 8; i++) {
            int next_pos_x = x + dx[i];
            int next_pos_y = y + dy[i];
            if(check(A,B,next_pos_x,next_pos_y) and !visited[next_pos_x][next_pos_y]){
                visited[next_pos_x][next_pos_y]=true;
                if(next_pos_x==E and next_pos_y==F)return steps;
                q.push({next_pos_x,next_pos_y});
            }
        }
        q.pop();
        }
    }
    return -1;
}

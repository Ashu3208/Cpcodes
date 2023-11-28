/*
Prim's Algorithm is used to find MST of a graph.
Problem Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/

 int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>visited(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //min heap
        int ans=0;
        pq.push({0,0}); // weight, node
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node=it.second, weight=it.first;
            if(!visited[node]){
                visited[node]=1;
                ans+=weight;
                for (auto it:adj[node]){
                    int adjNode = it[0], edgeWt=it[1];
                    if(!visited[adjNode])pq.push({edgeWt,adjNode});
                }
            }
            
        }
        return ans;
        
    }

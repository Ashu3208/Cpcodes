//Question Link: https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1
class Solution{   
public:
    int solve(int i, int diff, int A[]){
        if(i<0)return 0;
        int ans=0;
        for(int j=i-1;j>=0;j--){
            if(A[i]-A[j]==diff)
                ans=max(ans,1+solve(j,diff,A));
        }
        return ans;
    }
    int lengthOfLongestAP(int A[], int n) {
        if(n<=2){
            return n;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,2+solve(i,A[j]-A[i],A)); 
        // Why 2+solve()?? We are considering A[j] and A[i] as the last element and solve function is returning the remaining element
            }
        }
        return ans;
    }
};

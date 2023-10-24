/**
Problem Link: https://www.interviewbit.com/problems/window-string
Given a string A and a string B, find the window with minimum length in A, which will contain all the characters in B in linear time complexity.
 Note that when the count of a character c in B is x, then the count of c in the minimum window in A should be at least x.

Note:

If there is no such window in A that covers all characters in B, return the empty string.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index and length )
**/


string Solution::minWindow(string A, string B) {
 unordered_map<int,int>countB, window;
 for(auto i:B){
     countB[i]++;
 }
 // have = char in window, need = unique char we require
 int have=0, need=countB.size(), ansLen=INT_MAX,l=0;
 string ans="";
 for(int i=0;i<A.size();i++){
     window[A[i]]++;
     if( countB[A[i]] and window[A[i]]==countB[A[i]]){
         have++;
     }
     while (have==need){
         if(i-l+1 < ansLen){
             ansLen=i-l+1;
             ans=A.substr(l,ansLen);
         }
         window[A[l]]--;
         if( countB[A[l]] and window[A[l]]<countB[A[l]]){
                have--;
        }
        l++;
     }
 }
 return ans;
}

/*
Concept Used: Sliding window, Hashmap, Two pointers
Intuition: We maintain two hashmap - one for storing occurence of given string and one for maintaining occurence in the current window.
We maintain two variables called have and need.  "need" is the distinct char in given string and have is the distinct char in current window and value of have indicates the no of char whose 
required frequencies have been met.
*/

/*
Problem Link: https://www.interviewbit.com/problems/substring-concatenation/
You are given a string, S, and a list of words, L, that are all of the same length.
Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
Order of concatenation does not matter. 
*/

int check(string A,const vector<string> &B,unordered_multiset<string>&s){
    int n =B[0].size();
    unordered_multiset<string>temp;
    for(int i=0;i<A.size();i++){
        string a="";
        for(int j=i;j<i+B[0].size();j++){
            a+=A[j];
        }
        if(s.count(a)){
            if(temp.count(a)<s.count(a)){
                i+=(n-1);
                temp.insert(a);
                if(temp.size()==s.size()){
                    return 1;
                }
            }else{
                return 0;
            }
            
        }else{
            return 0;
        }
    }
}
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int substring_len= B.size()*B[0].size();
    unordered_multiset<string>s;
    for(auto i:B){
        s.insert(i);
    }
    // cout<<"substring_len is "<<substring_len<<endl;
    vector<int>ans;
    for(int i=0;i<A.size()-substring_len+1;i++){
        if(i+substring_len>A.size())break;
        string substring= A.substr(i,substring_len);
        if(substring.size()==substring_len and check(substring,B,s)){
            ans.push_back(i);
        }    
    }
    return ans;
}

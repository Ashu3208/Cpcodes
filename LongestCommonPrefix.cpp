class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs[0].length();i++){
            char check=strs[0][i];
            int flag=1;
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=check){
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans+=check;
            }
            else break;

        }
        return ans;
    }
};

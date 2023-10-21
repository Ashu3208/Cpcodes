/*
    A number is said to be palindromic if it reads the same backwards. For eg 101 is palindrome because if you read it backwards, it still is 101. 
*/

int ispalindrome(int n){
    vector<int>digits;
    while(n>0){
        digits.push_back(n%10);
        n/=10;
    }
    for(int i=0;i<digits.size();i++){
        if(digits[i]!=digits[digits.size()-i-1]) return false;
    }
    return true;
}

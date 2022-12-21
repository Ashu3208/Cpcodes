#include <bits/stdc++.h>
// #include<stack>
using namespace std;
void insertAtBottom(int x,stack<int> &s){
    if(s.empty()){
        s.push(x);
        return;
    }
    int temp=s.top();
    s.pop();
    insertAtBottom(x,s);
    s.push(temp);
    
    
}
void reverse_stack(stack<int> &s){
    if(s.empty())
        return;
    int x=s.top();
    s.pop();
    reverse_stack(s);    
    insertAtBottom(x,s);
}
int reverse(int n){
	stack<int>s ;
	while(n){
	    s.push(n%10);
	    n/=10;
	}
	reverse_stack(s);
	n=0;
	while(!s.empty()){
	    n=n*10+s.top();
	    s.pop();
	}
	return n;
}
int main(){
    int n;
    cin>>n;
    cout<<reverse(n);
}

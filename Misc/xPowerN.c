// C program to calculate x^n
#include <stdio.h>
xpowern(int x,int n){
   if(n==1) return x;
   int temp=xpowern(x,n/2) *xpowern(x,n/2);
   if(n%2==0) return temp;
   else return temp*x;
}
int main(void) {
    int x,n;
    scanf("%d %d",&x,&n);
    printf("%d",xpowern(x,n));
    return 0;
}

#include <stdio.h>

int main(void) {
	int nt,n,a[200],temp;
	int i,m,x,t,y,j;
	scanf("%d",&nt);
	while(nt--){
	    temp=0;
	    scanf("%d",&n);
	    a[0]=1;m=1;i=1;
	    for(i=1;i<=n;i++){
	            for(j=0;j<m;j++){
	            x=i*a[j]+temp;
	            a[j]=x%10;
	            temp=x/10;
	        }
	        while(temp>0){
	            for(t=m;temp!=0;t++){
	                a[t]=temp%10;
	                m++;
	                temp=temp/10;
	             }
	        }
	    }
	    for(i=m-1;i>=0;i--){
	        printf("%d",a[i]);
	    }
	    printf("\n");
	    	}
	return 0;
}


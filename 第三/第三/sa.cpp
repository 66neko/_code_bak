#include<iostream> 
 #include<stdio.h> 
 #include<string.h> 
 #include<math.h> 
 #include<algorithm> 
 #include<stack> 
 #include<queue> 
 #include<set> 
 #define ll long long 
 using namespace std; 
 int n,a[10],ans,sum; 
 int main() 
 {  
        int i,j,k,m; 
        while (scanf("%d",&n)!=EOF) 
        { 
                ans=sum=0; 
                for (i=1;i<=n;i++) 
                { 
                       scanf("%d",&a[i]); 
                       sum+=a[i]; 
                } 
                if (n<4) ans=1024; 
                else 
                if (n==4) 
                { 
                       for (i=1;i<=4;i++) 
                          for (j=i+1;j<=4;j++) 
                          { 
                                 m=a[i]+a[j]; 
                                 while (m>1024) m-=1024; 
                                 if (m>ans) ans=m; 
                          } 
                       for (i=1;i<=4;i++) 
                          for (j=i+1;j<=4;j++) 
                             for (k=j+1;k<=4;k++) 
                               if ((a[i]+a[j]+a[k])%1024==0) ans=1024; 
                }else 
                { 
                       for (i=1;i<=5;i++) 
                          for (j=i+1;j<=5;j++) 
                             for (k=j+1;k<=5;k++) 
                             if ((a[i]+a[j]+a[k])%1024==0) 
                             { 
                                     m=sum-a[i]-a[j]-a[k]; 
                                     while (m>1024) m-=1024; 
                                     if (m>ans) ans=m; 
                             } 
                } 
                printf("%d\n",ans); 
        } 
        return 0; 
 } 
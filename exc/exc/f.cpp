#include <stdio.h>
void main()
{
 int d=0,y,n = 0,b=0;
 printf("请输入年份：");
 scanf("%d",&y);
if (y%4==0&&y%100!=0||y%400==0)
n=(y-1)/4-(y-1)/100+(y-1)/400;
     d=d+365*(y-1)+n;
 b=d%7;
 
 
 switch(b)
 {
 case 1: printf("星期一\n");break;
 case 2: printf("星期二\n");break;
 case 3: printf("星期三\n");break;
 case 4: printf("星期四\n");break;
 case 5: printf("星期五\n");break;
 case 6: printf("星期六\n");break;
 case 7: printf("星期日\n");break;
 }
 printf("从公元1年到公元%d年一共度过了%d天",y,d);
}
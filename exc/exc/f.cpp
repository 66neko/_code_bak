#include <stdio.h>
void main()
{
 int d=0,y,n = 0,b=0;
 printf("��������ݣ�");
 scanf("%d",&y);
if (y%4==0&&y%100!=0||y%400==0)
n=(y-1)/4-(y-1)/100+(y-1)/400;
     d=d+365*(y-1)+n;
 b=d%7;
 
 
 switch(b)
 {
 case 1: printf("����һ\n");break;
 case 2: printf("���ڶ�\n");break;
 case 3: printf("������\n");break;
 case 4: printf("������\n");break;
 case 5: printf("������\n");break;
 case 6: printf("������\n");break;
 case 7: printf("������\n");break;
 }
 printf("�ӹ�Ԫ1�굽��Ԫ%d��һ���ȹ���%d��",y,d);
}
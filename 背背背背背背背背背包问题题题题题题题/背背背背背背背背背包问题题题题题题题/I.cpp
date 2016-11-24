#include <stdio.h>
#include <string.h>
#include <algorithm>
#define M 405
#define N 40005
#define max(a, b) (a > b ? a : b)
int n, dp[N];

typedef struct number
{
       int a;
       int h;
       int c;
}Number;
Number data[M];

int cmp(const void *a, const void *b)
{
       return (*(number *)a).a > (*(number *)b).a ? 1 : -1;
}

int main()
{
       int i, j, k, C, max;
       scanf("%d", &n);
       for (i = 0, max = 0; i < n; i++)
       {
              scanf("%d%d%d", &data[i].h, &data[i].a, &data[i].c);
              if (max < data[i].a)
              {
                     max = data[i].a;
              }
       }
       int ans = 0;
       qsort(data, n, sizeof(data[0]), cmp);
       for (i = 0; i <= max; i++)
       {
              dp[i] = 0;
       }
       for (i = 0; i < n; i++)
       {
              C = data[i].a;
              for (j = 0; j < data[i].c; j++)
              {
                     for (k = C; k >= data[i].h; k--)
                     {
                            dp[k] = max(dp[k], dp[k - data[i].h] + data[i].h);
                            if (dp[k] > ans)
                            {
                                   ans = dp[k];
                            }
                     }
              }
       }
       printf("%d\n", ans);
       return 0;
}

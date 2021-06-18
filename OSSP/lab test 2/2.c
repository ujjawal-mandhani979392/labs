
#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    n = 4;
    m = 1;
    int alloc[4][1] = {{1},
                       {1},
                       {4},
                       {2}};
    char name[4][10] = {"A", "B", "C", "D"};
    int max[4][1] = {{6},
                     {5},
                     {7},
                     {4}};

    int avail[1] = {2};

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    printf("Need matrix :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d\t", need[i][j]);
        }
    }

    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    printf("\nFollowing is the SAFE Sequence\n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d\n", ans[n - 1]);
    for (i = 0; i < n - 1; i++)
    {
        int j = ans[i];
        printf(" %s -> ", *(name + j));
    }
    j = ans[n - 1];
    printf("%s", *(name + j));
    printf("\n");
    return (0);
}
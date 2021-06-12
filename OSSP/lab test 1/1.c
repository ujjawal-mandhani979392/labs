#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        printf("More than required arguments\n");
        exit(0);
    }
    int n = atoi(argv[1]);
    int fd[2];
    int *arr = (int *)malloc(sizeof(int) * n);
    pipe(fd);
    if (fork() > 0)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (i == 0)
            {
                arr[i] = 3;
            }
            else if (i % 2 == 0)
            {
                arr[i] = arr[i - 2] * arr[i - 2] + 1;
            }
            else
            {
                if (i == 1)
                {
                    arr[i] = 19 + arr[i - 1];
                }
                else
                    arr[i] = (19 * (i + 1) / 2) + arr[i - 1];
            }
        }
        write(fd[1], arr, sizeof(int) * n);
        close(fd[1]);
        wait(NULL);
        int sum;
        read(fd[0], &sum, sizeof(int));
        close(fd[0]);
        printf("Sum of the array = %d", sum);
    }
    else
    {
        sleep(n / 10);
        int i, j, temp, sum = 0;
        read(fd[0], arr, sizeof(int) * n);
        close(fd[0]);
        printf("Original array: \n");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        printf("Sorted array: \n");
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
        printf("\n");
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    }
    return 0;
}
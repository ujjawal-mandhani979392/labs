#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <malloc.h>
int **arr;
double *gd;

void *gettingMarks(int n)
{
    int i;
    printf("Enter the marks in 5 subjs of %d students\n", n);
    for (i = 0; i < 5; i++)
    {
        scanf("%d \n", &arr[n][i]);
    }
    return NULL;
}

void *calcGrade(int n)
{
    double grade = 0.0;
    int i;
    for (i = 0; i < 5; i++)
    {
        grade = grade + arr[n][i];
    }

    gd[n] = grade / 5 * 100;
    return NULL;
}

int main()
{
    pthread_t t1;
    pthread_t t2;
    int n = 0, i;
    printf("Enter the number\n");
    scanf("%d \n", &n);
    *arr = (int *)malloc(n * sizeof(int));
    for (int i = 1; i < 5; i++)
    {
        arr[i] = (int *)malloc(5 * sizeof(int));
    }
    gd = (double *)malloc(n * sizeof(double));
    for (i = 0; i < n; i++)
    {
        pthread_create(&t1, NULL, gettingMarks(i), NULL);
        pthread_create(&t2, NULL, calcGrade(i), NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
    }
    printf("After Thread\n");
    exit(0);
}

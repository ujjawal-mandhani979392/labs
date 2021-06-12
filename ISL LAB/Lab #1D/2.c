#include <stdio.h>
#include <string.h>
void main()
{
    char k[100], ct[100], pt[100];
    int lenm, lenk, i, j;
    char *msg, *key;
    size_t bufsize = 100;
    printf("Enter Message : ");
    getline(&msg, &bufsize, stdin);
    printf("Enter Key : ");
    getline(&key, &bufsize, stdin);
    lenm = strlen(msg);
    lenk = strlen(key);
    for (i = 0; i < lenm; i++, j++)
    {
        if (j == lenk)
        {
            j = 0;
        }
        k[i] = key[j];
    }
    for (i = 0; i < lenm; i++)
    {
        ct[i] = ((msg[i] + k[i]) % 26) + 'A';
    }
    ct[i] = '\0';
    for (i = 0; i < lenm; i++)
    {
        pt[i] = (((ct[i] - k[i]) + 26) % 26) + 'A';
    }
    pt[i] = '\0';
    printf("\nEncrypted Message : %s\n", ct);
    printf("\nDecrypted Message : %s\n", pt);
    return;
}
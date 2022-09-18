#include <stdio.h>

int main() {
    char str[80], substr[80];
    int n = 0, m = 0, i, j, flag; 

    printf("Enter a string: ");
    gets(str);
    printf("Enter search substring: ");
    gets(substr);

    while (str[n] != '\0') 
        n++;
    while (substr[m] != '\0') 
        m++;

    for (i = 0; i <= n-m; i++) {
        for (j = i; j < i + m; j++) {
            flag = 1;
            if (str[j] != substr[j-i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) 
            break;
    }

    if (flag == 1)
        printf("\nSEARCH SUCCESSFUL! Start: %d, End: %d", i, j-1);
    else
        printf("\nSEARCH UNSUCCESSFUL!");
 
    return 0;

}
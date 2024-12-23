#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char str[1000001];
int main() {

    char count[26] = { 0 };
    int max;
    scanf("%s", str);
    int num = strlen(str);
    for (int i = 0; i < num; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            count[str[i] - 97]++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            count[str[i] - 65]++;
        }
    }
    max = count[0];
    int index = 0;
    for (int z = 0; z < 26; z++)
    {
        if (count[z] >= max) {
            max = count[z];
            index = z;
        }
    }
    int sel = 0;
    for (int i = 0; i < 26; i++) {
        if (max == count[i]) {
            sel++;
        }
    }
    if (sel == 1) {
        printf("%c", index + 65);
    }
    else printf("?\n");
    return 0;
}
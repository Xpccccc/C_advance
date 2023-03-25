#include <stdio.h>
#include <string.h>

//洛谷：P1200 [USACO1.1]你的飞碟在这儿Your Ride Is Here
int main() {
    char ufo[6] = {0};
    char group[6] = {0};
    int sum_u = 0;
    int sum_g = 0;
    gets(ufo);
    gets(group);
    for (int i = 0; i < strlen(ufo); i++) {
        sum_u *= (int) ufo[i] - 64;
    }
    for (int i = 0; i < strlen(group); i++) {
        sum_g *= (int) group[i] - 64;
    }
    if ((sum_u % 47) == (sum_g % 47))
        printf("GO\n");
    else
        printf("STAY\n");
    return 0;
}
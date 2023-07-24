#include <stdio.h>
#include <string.h>
#include <assert.h>

char *my_strncat(char *destination, const char *source, size_t num) {
    assert(destination && source);
    int len = strlen(destination);
    int i = 0;
    while(num--){
        destination[len++] = source[i++];
    }
    return destination;
}

//模拟实现strncat
//char * strncat ( char * destination, const char * source, size_t num );
int main() {
    char str1[100] = "I am a handsome boy!";
    char str2[100] = "hhh hh";
    char str3[100] = {0};
//    strncat(str2, str1, 10);
//    printf("%s\n", str2);

    my_strncat(str2, str1, 10);
    printf("%s\n", str2);
    return 0;
}

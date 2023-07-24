#include <stdio.h>
#include <string.h>
#include <assert.h>

char *my_strncpy(char *destination, const char *source, size_t num) {
    assert(destination && source);
    int i = 0;
    int j = 0;
    while(num--){
        destination[i++] = source[j++];
    }
    return destination;
}

//模拟实现strncpy
//char * strncpy ( char * destination, const char * source, size_t num )
int main() {
    char str1[100] = "I am a handsome boy!";
    char str2[100] = "hhh hh";
    char str3[100] = {0};
//    strncpy(str2,str1,10);
//    printf("%s",str2);
    my_strncpy(str2, str1, 10);
    printf("%s",str2);
    return 0;
}

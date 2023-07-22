#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
struct _Record_Struct {
    unsigned char Env_Alarm_ID: 4;
    unsigned char Para1: 2;
    unsigned char state;
    unsigned char avail: 1;
} *Env_Alarm_Record;

//位段

int main() {
    struct _Record_Struct *pointer;
    struct _Record_Struct s={0} ;
    pointer = (struct _Record_Struct *) malloc(sizeof(struct _Record_Struct) * MAX_SIZE);
    s.Env_Alarm_ID = 10;
    s.Para1 = 11;
    s.avail = 12;
    s.state = 13;
    printf("%d", sizeof(struct _Record_Struct));
    return 0;
}

#include <stdio.h>

//65、鸡翁一值钱五，鸡母一值钱三，鸡雏三值钱一。百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？
int main() {
    int x, y, z, num = 1;
    for (x = 0; x <= 20; x++)
        for (y = 0; y <= 33; y++)
            for (z = 3; z < 99; z++)
                if (x * 5 + y * 3 + z / 3 == 100 && z % 3 == 0 && x + y + z == 100)
                    printf("combination %d:\n x=%d\ty=%d\tz=%d\n", num++, x, y, z);
                else
                    continue;
    return 0;
}

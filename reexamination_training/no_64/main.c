#include <stdio.h>

//64、有4个圆塔，圆心分别为(2，2)、(-2，2)、(2，-2)、(-2，-2)，圆半径为1。
// 这4个塔的高度分别为10m。塔以外无建筑物。今输入任一点的坐标，求该点的建筑高度(塔外的高度为零)。
int main() {
    int h = 10;
    float x1 = 2, y1 = 2;
    float x2 = -2, y2 = -2;
    float x3 = 2, y3 = -2;
    float x4 = -2, y4 = 2;
    float x, y = 0.0f;
    scanf("%f %f", &x, &y);
    float d1 = (x - x1) * (x - x1) + (y - y1) * (y - y1);
    float d2 = (x - x2) * (x - x2) + (y - y2) * (y - y2);
    float d3 = (x - x3) * (x - x3) + (y - y3) * (y - y3);
    float d4 = (x - x4) * (x - x4) + (y - y4) * (y - y4);
    if (d1 > 1 && d2 > 1 && d3 > 1 && d4 > 1)
        h = 0;
    printf("%d", h);
    return 0;
}

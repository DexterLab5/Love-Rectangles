#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int leftX;
    int bottomY;
    int width;
    int height;
} Rectangle;

int rightX(Rectangle rectangle) {
    return rectangle.leftX + rectangle.width;
}

int upY(Rectangle rectangle) {
    return rectangle.bottomY + rectangle.height;
}

bool overlapping(Rectangle rectangle1, Rectangle rectangle2) {
    if ((rectangle1.leftX <= rectangle2.leftX && rightX(rectangle1) >= rectangle2.leftX)
        || (rectangle1.leftX >= rectangle2.leftX && rectangle1.leftX <= rightX(rectangle2))
        && (rectangle1.bottomY <= rectangle2.bottomY && upY(rectangle1) >= rectangle2.bottomY)
        || (rectangle1.bottomY >= rectangle2.bottomY && rectangle1.bottomY <= upY(rectangle2))) {
        return true;
    }
    return false;
}

Rectangle getRectangle3(Rectangle rectangle1, Rectangle rectangle2) {
    Rectangle rec3;
    rec3.leftX = rectangle1.leftX;
    if (rec3.leftX < rectangle2.leftX) {
        rec3.leftX = rectangle2.leftX;
    }
    if (rec3.leftX == rectangle2.leftX) {
        rec3.width = rightX(rectangle1) - rectangle2.leftX;
    }
    else if (rec3.leftX == rectangle1.leftX) {
        rec3.width = rightX(rectangle2) - rectangle1.leftX;
    }
    rec3.bottomY = rectangle1.bottomY;
    if (rec3.bottomY < rectangle2.bottomY) {
        rec3.bottomY = rectangle2.bottomY;
    }
    if (rec3.bottomY == rectangle2.bottomY) {
        rec3.height = upY(rectangle1) - rectangle2.bottomY;
    }
    else if (rec3.bottomY == rectangle1.bottomY) {
        rec3.height = upY(rectangle2) - rectangle1.bottomY;
    }

    return rec3;
}

void printRectangle(Rectangle rectangle) {
    printf("leftX: %i\n",rectangle.leftX);
    printf("bottomY: %i\n",rectangle.bottomY);
    printf("width: %i\n",rectangle.width);
    printf("height: %i\n",rectangle.height);
}

int main(void) {
    Rectangle rec1;
    rec1.leftX = 1;
    rec1.bottomY = 1;
    rec1.width = 4;
    rec1.height = 3;
    Rectangle rec2;
    rec2.leftX = 3;
    rec2.bottomY = 2;
    rec2.width = 5;
    rec2.height = 4;
    if (overlapping(rec1, rec2) == 0) {
        printf("Rectangles don't overlap!\n");
        return 1;
    }
    Rectangle rec3 = getRectangle3(rec1,rec1);
    printRectangle(rec3);
    return 0;
}

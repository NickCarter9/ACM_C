#include <math.h>
#include <stdio.h>

typedef struct Point {
    float x;
    float y;
} Point;

typedef struct Rectangle {
    int index;
    Point leftUpperPoint;
    Point rightBottomPoint;
} Rectangle;

typedef struct Circle {
    int index;
    Point centerPoint;
    float radius;
} Circle;

void readRectangle(int, int, Rectangle*);
void readCircle(int, int, Circle*);
void checkInFigure(Rectangle*, int, Circle*, int, int, float, float);

int main(void) {
    char type;
    int countFigures = 0;
    int countRectangles = 0;
    int countCircles = 0;
    Rectangle rectangles[10];
    Circle circles[10];
    
    float pointX;
    float pointY;
    
    while(scanf("%c", &type) == 1) {
        if (type == '*') {
            break;
        } else if (type == 'r') {
            readRectangle(countFigures, countRectangles, rectangles);
            countRectangles++;                        
            countFigures++;
        } else if (type == 'c') {
            readCircle(countFigures, countCircles, circles);
            countCircles++;
            countFigures++;
        } else {
            continue;
        }
    }
    
    int pointIndex = 1;
    while(scanf("%f %f\n", &pointX, &pointY) == 2) {
        if (pointX >= 9999 && pointY >= 9999) {
            break;
        } else {
            checkInFigure(rectangles, countRectangles,
                            circles, countCircles,
                            pointIndex, pointX, pointY);
            pointIndex++;
        }
    } 
    
    
    return 0;
}

void readRectangle(int countFigures, int index, Rectangle* rectangles) {
    float leftUpperX;
    float leftUpperY;
    float rightBottomX;
    float rightBottomY;
    scanf("%f %f %f %f\n", &leftUpperX,
                            &leftUpperY,
                            &rightBottomX,
                            &rightBottomY);
    Point leftUpperPoint;
    leftUpperPoint.x = leftUpperX;
    leftUpperPoint.y = leftUpperY;
        
    Point rightBottomPoint;
    rightBottomPoint.x = rightBottomX;
    rightBottomPoint.y = rightBottomY;
        
    Rectangle rectangle;
    rectangle.index = countFigures;
    rectangle.leftUpperPoint = leftUpperPoint;
    rectangle.rightBottomPoint = rightBottomPoint;
                          
    rectangles[index] = rectangle;   
}

void readCircle(int countFigures, int index, Circle* circles) {
    float centerX;
    float centerY;
    float radius;
    scanf("%f %f %f\n", &centerX,
                        &centerY,
                        &radius);
    Point centerPoint;
    centerPoint.x = centerX;
    centerPoint.y = centerY;
            
        
    Circle circle;
    circle.index = countFigures;
    circle.centerPoint = centerPoint;
    circle.radius = radius;
            
    circles[index] = circle; 
}

void checkInFigure(Rectangle* rectangles, int countRectangles,
                    Circle* circles, int countCircles, 
                    int index, float pointX, float pointY) {
    int belongSize = 0;
    int i;
    for (i = 0; i < countRectangles; i++) {
        if (pointX > rectangles[i].leftUpperPoint.x 
                && pointX < rectangles[i].rightBottomPoint.x
                && pointY > rectangles[i].rightBottomPoint.y
                && pointY < rectangles[i].leftUpperPoint.y) {
            printf("Point %d is contained in figure %d\n",
                    index, rectangles[i].index + 1);
            belongSize++;
        } else {
            continue;
        }
    }
    
    for (i = 0; i < countCircles; i++) {
        double powX = pow((pointX - circles[i].centerPoint.x), 2);
        double powY = pow((pointY - circles[i].centerPoint.y), 2);
        double distance = sqrt(powX + powY);
        
        if (distance < circles[i].radius) {
            printf("Point %d is contained in figure %d\n",
                    index, circles[i].index + 1);
            belongSize++;
        } else {
            continue;
        }
    }
    
    if (belongSize == 0) {
        printf("Point %d is not contained in any figure\n", index);
    }  
    
}
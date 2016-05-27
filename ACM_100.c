#include <stdio.h>

typedef unsigned int boolean;

#define false 0
#define true 1

int calculateMaxCycleLength(int start, int end);
int calculateCycleLength(int num);
boolean isOddNumber(int num);

int main(void) {
    int num1;
    int num2;
    int acm100Result = 0;
    
    while(scanf("%d%d", &num1, &num2) == 2) {
        if (num1 > 1000000 || num2 > 1000000) {
            return 0;
        } else {
            if (num1 > num2) {
                acm100Result = calculateMaxCycleLength(num2, num1);
            } else {
                acm100Result = calculateMaxCycleLength(num1, num2);
            }
            printf("%d %d %d\n", num1, num2, acm100Result);
        }
    }
    return 0;
}

int calculateMaxCycleLength(int start, int end) {
    int maximumCycleLength = 0;
    int cycleLength = 0;
    int i;
    for (i = start; i <= end; i++) {
        cycleLength = calculateCycleLength(i);
        if (cycleLength > maximumCycleLength) {
            maximumCycleLength = cycleLength;
        } else {
            //nothing else.
        }
    }
    return maximumCycleLength;
}

int calculateCycleLength(int num) {
    int calculateNum = num;
    int cycleLength = 1;
    
    while (calculateNum != 1) {
        if(calculateNum == 1) {
            break;
        } else {
            
            if(isOddNumber(calculateNum)) {
                calculateNum = 3 * calculateNum + 1;
            } else {
                calculateNum = calculateNum / 2;
            }
            cycleLength++;
        }
    }
    return cycleLength;
}


boolean isOddNumber(int num) {
    if (num % 2 == 0) {
        return false;
    } else {
        return true;
    }
}
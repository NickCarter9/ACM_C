#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024
void decorder(char *buff);
void cleanBuffer(char *buff);

int main(void) {
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        decorder(&buffer[0]);
        cleanBuffer(&buffer[0]);
    }
    return 0;
}

void decorder(char *buffer) {
    int i;
    for(i = 0; i < 1024 ; i++) {
        if(buffer[i] == '\n' || buffer[i] == '\0') {
            break;
        } else {
            printf("%c", buffer[i]-7);
        }
    }
    printf("\n");
}

void cleanBuffer(char *buffer) {
    buffer[0] = '\0';
}
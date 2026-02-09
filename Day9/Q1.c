#include <stdio.h>
#include <string.h>

int main() {
    char codeName[100];

    if (scanf("%s", codeName) != 1) {
        return 1;
    }

    int length = strlen(codeName);
    
    for (int i = 0; i < length / 2; i++) {
        char temp = codeName[i];
        codeName[i] = codeName[length - 1 - i];
        codeName[length - 1 - i] = temp;
    }

    printf("%s\n", codeName);

    return 0;
}

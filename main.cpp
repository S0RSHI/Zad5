#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int arc, char * argv[]) {
    
    FILE* f = fopen(argv[1], "rb");

    if (f == nullptr) {
        printf("\nError when openning file");
        return 0;
    }

    fclose(f);

    return 0;
}
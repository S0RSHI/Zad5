#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct FileHeader {
    short b_type;
    int b_size;
    short b_rev1;
    short b_rev2;
    int b_off_B;
} File;

int main(int arc, char * argv[]) {
    
    FILE* f = fopen(argv[1], "rb");

    if (f == nullptr) {
        printf("Error when openning file");
        return 0;
    }
    

    printf("-----------INFO-----------\n");

    fread(&File.b_type, sizeof(File.b_type), 1, f);
    printf("Type: %x", File.b_type);

    fread(&File.b_size, sizeof(File.b_size), 1, f);
    printf("\nSize file: %dB", File.b_size);

    fread(&File.b_rev1, sizeof(File.b_rev1), 1, f);
    printf("\nReserved 1: %d", File.b_rev1);

    fread(&File.b_rev2, sizeof(File.b_rev2), 1, f);
    printf("\nReserved 2: %d", File.b_rev2);

    fread(&File.b_off_B, sizeof(File.b_off_B), 1, f);
    printf("\nPosition: %d", File.b_off_B);

    fclose(f);

    return 0;
}
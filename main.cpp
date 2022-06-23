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

struct PictureHeader {
    int b_Size;
    int b_Width;
    int b_Height;
    short b_Planes;
    short b_BitCount;
    int b_Compression;
    int b_SizeImage;
    int b_XPelsPerMeter;
    int b_YPelsPerMeter;
    int b_ClrUsed;
    int b_ClrImportant;
} Picture;

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

    fseek(f, 14, SEEK_SET);
    fread(&Picture.b_Size, sizeof(Picture.b_Size), 1, f);
    printf("\nInformation header size: %d", Picture.b_Size);

    fread(&Picture.b_Width, sizeof(Picture.b_Width), 1, f);
    printf("\nWidth: %dpx", Picture.b_Width);

    fread(&Picture.b_Height, sizeof(Picture.b_Height), 1, f);
    printf("\nHeight : %dpx", Picture.b_Height);

    fread(&Picture.b_Planes, sizeof(Picture.b_Planes), 1, f);
    printf("\nNumber of lobes: %d", Picture.b_Planes);

    fread(&Picture.b_BitCount, sizeof(Picture.b_BitCount), 1, f);
    printf("\nThe number of bits per pixel: %d (1, 4, 8, or 24)", Picture.b_BitCount);

    fread(&Picture.b_Compression, sizeof(Picture.b_Compression), 1, f);
    printf("\nCompression: %d (0=none, 1=RLE-8, 2=RLE-4)", Picture.b_Compression);

    fread(&Picture.b_SizeImage, sizeof(Picture.b_SizeImage), 1, f);
    printf("\nPicture size: %d", Picture.b_SizeImage);

    fread(&Picture.b_XPelsPerMeter, sizeof(Picture.b_XPelsPerMeter), 1, f);
    printf("\nHorizontal resolution: %d", Picture.b_XPelsPerMeter);

    fread(&Picture.b_YPelsPerMeter, sizeof(Picture.b_YPelsPerMeter), 1, f);
    printf("\nVertical resolution: %d", Picture.b_YPelsPerMeter);

    fread(&Picture.b_ClrUsed, sizeof(Picture.b_ClrUsed), 1, f);
    printf("\nThe number of colors: %d", Picture.b_ClrUsed);

    fread(&Picture.b_ClrImportant, sizeof(Picture.b_ClrImportant), 1, f);
    printf("\nImportant colors: %d", Picture.b_ClrImportant);

    fclose(f);

    return 0;
}
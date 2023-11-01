#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    const int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];

    if (argc != 2)
    {
        printf("Usage: ./recover infile\n");
        return 1;
    }

    FILE*inptr=fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("%s is not a valid file.\n", argv[1]);
        return 2;
    }

    FILE* outptr = NULL;

    int jpeg_counter = 0;


    while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", jpeg_counter);
            outptr = fopen(filename, "w");
            jpeg_counter++;

        }

        if (outptr != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, outptr);
        }

    }

    if (outptr != NULL)
    {
        fclose(outptr);
    }

    fclose(inptr);

    return 0;
}

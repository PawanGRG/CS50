#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < width; row++)
    {
        for (int col = 0; col < height; col++)
        {
            if (image[row][col].rgbtRed == 0x00 && image[row][col].rgbtBlue == 0x00 && image[row][col].rgbtGreen == 0x00)
            {
                image[row][col].rgbtBlue = 0xff;
            }
        }
    }
}

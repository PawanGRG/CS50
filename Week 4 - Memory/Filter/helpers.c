#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;

            float average = (red + blue + green) / 3.0;

            image[i][j].rgbtRed = round(average);
            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red_total = 0;
            float blue_total = 0;
            float green_total = 0;
            int count = 0;

            if (i == 0 && j == 0)
            {
                // Top-left corner
                for (int k = i; k <= i + 1; k++)
                {
                    for (int l = j; l <= j + 1; l++)
                    {
                        red_total += image[k][l].rgbtRed;
                        blue_total += image[k][l].rgbtBlue;
                        green_total += image[k][l].rgbtGreen;
                        count++;
                    }
                }
                temp[i][j].rgbtRed = round(red_total / count);
                temp[i][j].rgbtBlue = round(blue_total / count);
                temp[i][j].rgbtGreen = round(green_total / count);
            }
            else if (i == 0 && j == width - 1)
            {
                // Top-right corner
                for (int k = i; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j; l++)
                    {
                        red_total += image[k][l].rgbtRed;
                        blue_total += image[k][l].rgbtBlue;
                        green_total += image[k][l].rgbtGreen;
                        count++;
                    }
                }
                temp[i][j].rgbtRed = round(red_total / count);
                temp[i][j].rgbtBlue = round(blue_total / count);
                temp[i][j].rgbtGreen = round(green_total / count);
            }
            else if (i == height - 1 && j == 0)
            {
                // Bottom-left corner
                for (int k = i - 1; k <= i; k++)
                {
                    for (int l = j; l <= j + 1; l++)
                    {
                        red_total += image[k][l].rgbtRed;
                        blue_total += image[k][l].rgbtBlue;
                        green_total += image[k][l].rgbtGreen;
                        count++;
                    }
                }
                temp[i][j].rgbtRed = round(red_total / count);
                temp[i][j].rgbtBlue = round(blue_total / count);
                temp[i][j].rgbtGreen = round(green_total / count);
            }
            else if (i == height - 1 && j == width - 1)
            {
                // Bottom-right corner
                for (int k = i - 1; k <= i; k++)
                {
                    for (int l = j - 1; l <= j; l++)
                    {
                        red_total += image[k][l].rgbtRed;
                        blue_total += image[k][l].rgbtBlue;
                        green_total += image[k][l].rgbtGreen;
                        count++;
                    }
                }
                temp[i][j].rgbtRed = round(red_total / count);
                temp[i][j].rgbtBlue = round(blue_total / count);
                temp[i][j].rgbtGreen = round(green_total / count);
            }
            else if (i == 0)
            {
                // Top edge
                for (int k = i; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if (l < 0 || l >= width)
                            continue;

                        red_total += image[k][l].rgbtRed;
                        blue_total += image[k][l].rgbtBlue;
                        green_total += image[k][l].rgbtGreen;
                        count++;
                    }
                }
                temp[i][j].rgbtRed = round(red_total / count);
                temp[i][j].rgbtBlue = round(blue_total / count);
                temp[i][j].rgbtGreen = round(green_total / count);
            }
            else if (i == height - 1)
            {
                // Bottom edge
                for (int k = i - 1; k <= i; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if (l >= 0 && l < width)
                        {
                            red_total += image[k][l].rgbtRed;
                            blue_total += image[k][l].rgbtBlue;
                            green_total += image[k][l].rgbtGreen;
                            count++;
                        }
                    }
                }
                temp[i][j].rgbtRed = round(red_total / count);
                temp[i][j].rgbtBlue = round(blue_total / count);
                temp[i][j].rgbtGreen = round(green_total / count);
            }
            else if (j == 0)
            {
                // Left edge
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j; l <= j + 1; l++)
                    {
                        if (k >= 0 && k < height)
                        {
                            red_total += image[k][l].rgbtRed;
                            blue_total += image[k][l].rgbtBlue;
                            green_total += image[k][l].rgbtGreen;
                            count++;
                        }
                    }
                }
                temp[i][j].rgbtRed = round(red_total / count);
                temp[i][j].rgbtBlue = round(blue_total / count);
                temp[i][j].rgbtGreen = round(green_total / count);
            }
            else if (j == width - 1)
            {
                // Right edge
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j; l++)
                    {
                        if (k >= 0 && k < height)
                        {
                            red_total += image[k][l].rgbtRed;
                            blue_total += image[k][l].rgbtBlue;
                            green_total += image[k][l].rgbtGreen;
                            count++;
                        }
                    }
                }
                temp[i][j].rgbtRed = round(red_total / count);
                temp[i][j].rgbtBlue = round(blue_total / count);
                temp[i][j].rgbtGreen = round(green_total / count);
            }
            else
            {
                // Inner pixels
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if (k >= 0 && k < height && l >= 0 && l < width)
                        {
                            red_total += image[k][l].rgbtRed;
                            blue_total += image[k][l].rgbtBlue;
                            green_total += image[k][l].rgbtGreen;
                            count++;
                        }
                    }
                }
                temp[i][j].rgbtRed = round(red_total / count);
                temp[i][j].rgbtBlue = round(blue_total / count);
                temp[i][j].rgbtGreen = round(green_total / count);
            }
        }
    }

    for (int m = 0; m < height; m++)
    {
        for (int n = 0; n < width; n++)
        {
            image[m][n].rgbtRed = temp[m][n].rgbtRed;
            image[m][n].rgbtBlue = temp[m][n].rgbtBlue;
            image[m][n].rgbtGreen = temp[m][n].rgbtGreen;
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxRed = 0;
            int gxGreen = 0;
            int gxBlue = 0;

            int gyRed = 0;
            int gyGreen = 0;
            int gyBlue = 0;

            for (int p = -1; p <= 1; p++)
            {
                for (int q = -1; q <= 1; q++)
                {
                    int newRow = i + p;
                    int newCol = j + q;

                    if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width)
                    {
                        gxBlue += image[newRow][newCol].rgbtBlue * gx[p + 1][q + 1];
                        gyBlue += image[newRow][newCol].rgbtBlue * gy[p + 1][q + 1];
                        gxGreen += image[newRow][newCol].rgbtGreen * gx[p + 1][q + 1];
                        gyGreen += image[newRow][newCol].rgbtGreen * gy[p + 1][q + 1];
                        gxRed += image[newRow][newCol].rgbtRed * gx[p + 1][q + 1];
                        gyRed += image[newRow][newCol].rgbtRed * gy[p + 1][q + 1];
                    }
                }
            }

            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));

            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}

#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    // looping through the columns one at a time
    for (int i = 0; i < height; i++)
    {
        // accessing the pixels row by row in that column (looping through pixels)
        for (int j = 0; j < width; j++)
        {
            // color black is 00 red, 0x00 green and 0x00blue
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00)
            {
                // changing the pixel color to green
                image[i][j].rgbtBlue = 0x22;
                image[i][j].rgbtGreen = 0x8b;
                image[i][j].rgbtRed = 0x22;
            }
        }
    }
}

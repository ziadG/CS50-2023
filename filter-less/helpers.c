#include "helpers.h"
#include <math.h>
#include <stdio.h>

RGBTRIPLE pixel_blur(int y, int x, int height, int width, RGBTRIPLE image[height][width]);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Take the average value of RGB of a specific pixel
    // A variable to store the average value of RGB
    float avrg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Storing the average RGB values into avrg for each pixel
            avrg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            avrg = round(avrg);
            // Applying the avrg value to each pixel
            image[i][j].rgbtRed = avrg;
            image[i][j].rgbtGreen = avrg;
            image[i][j].rgbtBlue = avrg;
        }
    }
    // apply the average value of RGB to that pixel
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaBlue, sepiaGreen;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Storing the average RGB values into avrg for each pixel
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            // Applying the avrg value to each pixel
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // The height is column, the width is row.
    // Loop through every pixel making it's new width = the width of the pixel
    float tempr, tempb, tempg;
    long temp = width - 1;
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Temporarly storing the colors of the pixels
            tempr = image[i][j].rgbtRed;
            tempg = image[i][j].rgbtGreen;
            tempb = image[i][j].rgbtBlue;
            // Swapping
            image[i][j].rgbtRed = image[i][temp - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][temp - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][temp - j].rgbtBlue;
            // Assigning the value of the original pixel
            image[i][temp - j].rgbtRed = tempr;
            image[i][temp - j].rgbtGreen = tempg;
            image[i][temp - j].rgbtBlue = tempb;
        }
    }
    return;
}

RGBTRIPLE pixel_blur(int y, int x, int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurred;
    float counter = 0.0;
    float avrgRed = 0.0;
    float avrgBlue = 0.0;
    float avrgGreen = 0.0;
    // loop through the pixels
    for (int i = y - 1; i <= y + 1; i++)
    {
        for (int j = x - 1; j <= x + 1; j++)
        {
            // check pixel validity
            if (j <= width - 1 && j >= 0)
            {
                if (i <= height - 1 && i >= 0)
                {
                    avrgRed = avrgRed + image[i][j].rgbtRed;
                    avrgGreen = avrgGreen + image[i][j].rgbtGreen;
                    avrgBlue = avrgBlue + image[i][j].rgbtBlue;
                    counter++;
                }
            }
            blurred.rgbtRed = round(avrgRed / counter);
            blurred.rgbtGreen = round(avrgGreen / counter);
            blurred.rgbtBlue = round(avrgBlue / counter);
        }
    }
    return blurred;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // store a copy of the image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i <= height - 1; i++)
    {
        for (int j = 0; j <= width - 1; j++)
        {
            // storing the original pixel data in copy array
            copy[i][j] = image[i][j];
        }
    }
    // blur the copied pixels
    for (int i = 0; i <= height - 1; i++)
    {
        for (int j = 0; j <= width - 1; j++)
        {
            // we have to pass in the copied pixels not the original ones
            RGBTRIPLE blur = pixel_blur(i, j, height, width, copy);

            // assign all three channels to the return value of the function
            image[i][j] = blur;
        }
    }
    return;
}
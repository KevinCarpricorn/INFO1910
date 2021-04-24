#include "c_functions.h"

void make_coloured_image(int* red, int* green, int* blue, int len, struct ColouredPixels* cp, union PixelData* pd, struct Image* im) {
    cp->red = red;
    cp->green = green;
    cp->blue = blue;
    pd->colour_pixels = *cp;
    im->pd = *pd;
    im->length = len;
    im->is_coloured = 1;
}

void make_monochrome_image(int* grey, int len, union PixelData* pd, struct Image* im) {
    pd->grey_pixels = grey;
    im->pd = *pd;
    im->length = len;
    im->is_coloured = 0;
}

float c_r_psnr_wrapper(int* red1, int* green1, int* blue1, int* red2, int* green2, int* blue2, int len) {
    struct ColouredPixels cp1;
    struct ColouredPixels cp2;

    union PixelData pd1;
    union PixelData pd2;

    struct Image image1;
    struct Image image2;

    make_coloured_image(red1, green1, blue1, len, &cp1, &pd1, &image1);
    make_coloured_image(red2, green2, blue2, len, &cp2, &pd2, &image2);
    
    return c_r_psnr(&image1, &image2);
}

float c_g_psnr_wrapper(int* red1, int* green1, int* blue1, int* red2, int* green2, int* blue2, int len) {
    struct ColouredPixels cp1;
    struct ColouredPixels cp2;

    union PixelData pd1;
    union PixelData pd2;

    struct Image image1;
    struct Image image2;

    make_coloured_image(red1, green1, blue1, len, &cp1, &pd1, &image1);
    make_coloured_image(red2, green2, blue2, len, &cp2, &pd2, &image2);
    
    return c_g_psnr(&image1, &image2);
}

float c_b_psnr_wrapper(int* red1, int* green1, int* blue1, int* red2, int* green2, int* blue2, int len) {
    struct ColouredPixels cp1;
    struct ColouredPixels cp2;

    union PixelData pd1;
    union PixelData pd2;

    struct Image image1;
    struct Image image2;

    make_coloured_image(red1, green1, blue1, len, &cp1, &pd1, &image1);
    make_coloured_image(red2, green2, blue2, len, &cp2, &pd2, &image2);
    
    return c_b_psnr(&image1, &image2);
}

float c_total_psnr_wrapper(int* red1, int* green1, int* blue1, int* red2, int* green2, int* blue2, int len, int is_coloured) {
    struct ColouredPixels cp1;
    struct ColouredPixels cp2;

    union PixelData pd1;
    union PixelData pd2;

    struct Image image1;
    struct Image image2;

    if (is_coloured) {
        make_coloured_image(red1, green1, blue1, len, &cp1, &pd1, &image1);
        make_coloured_image(red2, green2, blue2, len, &cp2, &pd2, &image2);
    } else {
        make_monochrome_image(red1, len, &pd1, &image1);
        make_monochrome_image(red2, len, &pd2, &image2);
    }

    float f = c_total_psnr(&image1, &image2);
    return f;
}

float c_r_psnr(struct Image* image1, struct Image* image2) {
    int *red1;
    int *red2;
    int length;
    int i;
    int sum = 0;
    double mse;
    double psnr;
    red1 = image1->pd.colour_pixels.red;        // all the values in red channel of image1
    red2 = image2->pd.colour_pixels.red;        // all the values in red channel of image2
    length = image1->length;
    for (i = 0; i < length; i++)
    {
        sum += (red1[i] - red2[i]) * (red1[i] - red2[i]);
    }
    mse = 1.0 * sum / length;       // mean squared error(MSE)
    if (sum == 0)
    {
        return 0;
    }
    else
    {
        psnr = 10 * log10((255 * 255 / mse));       // peak Signal-to Noise Ratio(PSNR)
        psnr = (float) psnr;
        return psnr;
    }
}

float c_g_psnr(struct Image* image1, struct Image* image2) {
    int *green1;
    int *green2;
    int length;
    int i;
    int sum = 0;
    double mse;
    double psnr;
    green1 = image1->pd.colour_pixels.green;        // all the values in green channel of image1
    green2 = image2->pd.colour_pixels.green;        // all the values in green channel of image2
    length = image1->length;
    for (i = 0; i < length; i++)
    {
        sum += (green1[i] - green2[i]) * (green1[i] - green2[i]);
    }
    mse = 1.0 * sum / length;       // mean squared error(MSE)
    if (sum == 0)
    {
        return 0;
    }
    else
    {
        psnr = 10 * log10((255 * 255 / mse));       // peak Signal-to Noise Ratio(PSNR)
        psnr = (float) psnr;
        return psnr;
    }
}

float c_b_psnr(struct Image* image1, struct Image* image2) {
    int *blue1;
    int *blue2;
    int length;
    int i;
    int sum = 0;
    double mse;
    double psnr;
    blue1 = image1->pd.colour_pixels.blue;      // all the values in blue channel of image1
    blue2 = image2->pd.colour_pixels.blue;      // all the values in blue channel of image2
    length = image1->length;
    for (i = 0; i < length; i++)
    {
        sum += (blue1[i] - blue2[i]) * (blue1[i] - blue2[i]);
    }
    mse = 1.0 * sum / length;       // mean squared error(MSE)
    if (sum == 0)
    {
        return 0;
    }
    else
    {
        psnr = 10 * log10((255 * 255 / mse));       // peak Signal-to Noise Ratio(PSNR)
        psnr = (float) psnr;
        return psnr;
    }
}

float c_total_psnr(struct Image* image1, struct Image* image2) {
    int is_colour, length, i;
    int* pixel1, *pixel2, *red1, *red2, *green1, *green2, *blue1, *blue2;
    int sum = 0;
    double mse;
    double psnr;
    is_colour = image1->is_coloured;
    // Determining whether they are coloured images or monochrome images
    if (is_colour == 0)     // for monochrome images
    {
        pixel1 = image1->pd.grey_pixels;
        pixel2 = image2->pd.grey_pixels;
        length = image1->length;
        for (i = 0; i < length; i++)
        {
            sum += (pixel1[i] - pixel2[i]) * (pixel1[i] - pixel2[i]);
        }
        mse = 1.0 * sum / length;
        if (sum == 0)
        {
            return 0;
        }
        else
        {
            psnr = 10 * log10((255 * 255 / mse));
            psnr = (float) psnr;
            return psnr;
        }
    }
    else
    {
        // Values for all colour channels in image1 and image2
        red1 = image1->pd.colour_pixels.red;
        red2 = image2->pd.colour_pixels.red;
        green1 = image1->pd.colour_pixels.green;
        green2 = image2->pd.colour_pixels.green;
        blue1 = image1->pd.colour_pixels.blue;
        blue2 = image2->pd.colour_pixels.blue;
        length = image1->length;
        for (i = 0; i < length; i++)
        {
            sum += ((red1[i] - red2[i]) * (red1[i] - red2[i])) + \
            ((green1[i] - green2[i]) * (green1[i] - green2[i])) +\
             ((blue1[i] - blue2[i]) * (blue1[i] - blue2[i]));
        }
        mse = 1.0 * sum / (3 * length);     // mean squared error(MSE) for coloured images
        if (sum == 0)
        {
            return 0;
        }
        else
        {
            psnr = 10 * log10((255 * 255/ mse));       // peak Signal-to Noise Ratio(PSNR)
            psnr = (float) psnr;
            return psnr;
        }
    }
    return 0;
}
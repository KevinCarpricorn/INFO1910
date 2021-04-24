#include <math.h>

struct ColouredPixels {
    int* red;
    int* green;
    int* blue;
};

union PixelData {
    struct ColouredPixels colour_pixels;
    int* grey_pixels;
};

struct Image {
    union PixelData pd;
    int length;
    int is_coloured;  
};

void make_coloured_image(int* red, int* green, int* blue, int len, struct ColouredPixels* cp, union PixelData* pd, struct Image* im);

void make_monochrome_image(int* grey, int len, union PixelData* pd, struct Image* im);

float c_r_psnr_wrapper(int* red1, int* green1, int* blue1, int* red2, int* green2, int* blue2, int len);

float c_g_psnr_wrapper(int* red1, int* green1, int* blue1, int* red2, int* green2, int* blue2, int len);

float c_b_psnr_wrapper(int* red1, int* green1, int* blue1, int* red2, int* green2, int* blue2, int len);

float c_total_psnr_wrapper(int* red1, int* green1, int* blue1, int* red2, int* green2, int* blue2, int len, int is_coloured);
    
float c_r_psnr(struct Image* image1, struct Image* image2);

float c_g_psnr(struct Image* image1, struct Image* image2);

float c_b_psnr(struct Image* image1, struct Image* image2);

float c_total_psnr(struct Image* image1, struct Image* image2);

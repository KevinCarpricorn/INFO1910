from ctypes import *

c_lib = CDLL("./c_functions.so")
c_lib.c_r_psnr_wrapper.restype = c_float
c_lib.c_g_psnr_wrapper.restype = c_float
c_lib.c_b_psnr_wrapper.restype = c_float
c_lib.c_total_psnr_wrapper.restype = c_float

def make_c_array(ls):
    IntArray = c_int * len(ls)
    array = IntArray(*ls)
    return array

def is_coloured(image):
    assert len(image) > 0, "Image should be non-empty"
    return len(image[0]) == 3

def is_monochrome(image):
    assert len(image) > 0, "Image should be non-empty"
    return len(image[0]) == 1

def unpack_coloured_image(image):
    assert is_coloured(image), "This function should only receive coloured images"

    red_list = []
    green_list = []
    blue_list = []
    length = len(image)

    i = 0
    while i < length:
        red_list.append(image[i][0])
        green_list.append(image[i][1])
        blue_list.append(image[i][2])
        i += 1

    red_array = make_c_array(red_list)
    green_array = make_c_array(green_list)
    blue_array = make_c_array(blue_list)

    return red_array, green_array, blue_array, length

def unpack_monochrome_image(image):
    assert is_monochrome(image), "This function should only receive monochrome images"

    grey_list = []
    length = len(image)

    i = 0
    while i < length:
        grey_list.append(image[i][0])
        i += 1

    grey_array = make_c_array(grey_list)

    return grey_array, length

def call_c_r_psnr(image1, image2):
    red1, green1, blue1, length1 = unpack_coloured_image(image1)
    red2, green2, blue2, length2 = unpack_coloured_image(image2)

    assert length1 == length2, "Images are different sizes; cannot compare"

    return c_lib.c_r_psnr_wrapper(red1, green1, blue1, red2, green2, blue2, length1)

def call_c_g_psnr(image1, image2):
    red1, green1, blue1, length1 = unpack_coloured_image(image1)
    red2, green2, blue2, length2 = unpack_coloured_image(image2)

    assert length1 == length2, "Images are different sizes; cannot compare"

    return c_lib.c_g_psnr_wrapper(red1, green1, blue1, red2, green2, blue2, length1)
   
def call_c_b_psnr(image1, image2):
    red1, green1, blue1, length1 = unpack_coloured_image(image1)
    red2, green2, blue2, length2 = unpack_coloured_image(image2)

    assert length1 == length2, "Images are different sizes; cannot compare"

    return c_lib.c_b_psnr_wrapper(red1, green1, blue1, red2, green2, blue2, length1)

def call_c_total_psnr(image1, image2):

    if is_coloured(image1) and is_coloured(image2):
        red1, green1, blue1, length1 = unpack_coloured_image(image1)
        red2, green2, blue2, length2 = unpack_coloured_image(image2)

        assert length1 == length2, "Images are different sizes; cannot compare"

        f = c_lib.c_total_psnr_wrapper(red1, green1, blue1, red2, green2, blue2, length1, 1)
        return f

    elif is_monochrome(image1) and is_monochrome(image2):
        grey1, length1 = unpack_monochrome_image(image1)
        grey2, length2 = unpack_monochrome_image(image2)

        assert length1 == length2, "Images are different sizes; cannot compare"

        f = c_lib.c_total_psnr_wrapper(grey1, grey1, grey1, grey2, grey2, grey2, length1, 0)
        return f
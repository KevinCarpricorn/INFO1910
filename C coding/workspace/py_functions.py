import math


# PSNR for red values
def py_r_psnr(image1, image2):
    red1, red2 = [], []
    for line in image1:
        red1.append(line[0])        # all the values in red channel of image1
    for line in image2:
        red2.append(line[0])        # all the values in red channel of image2
    len_img = len(red1)
    mse = ((sum(list(map(lambda x, y: (x-y) * (x-y), red1, red2)))) / len_img) * 1000000000000000        # mean squared error(MSE)
    if mse == 0:
        return 0.0
    else:
        psnr = 10 * math.log10(255 * 255 * 1000000000000000 / mse)        # peak Signal-to Noise Ratio(PSNR)
        return psnr


# PSNR for green values
def py_g_psnr(image1, image2):
    green1, green2 = [], []
    for line in image1:
        green1.append(line[1])        # all the values in green channel of image1
    for line in image2:
        green2.append(line[1])        # all the values in green channel of image2
    len_img = len(green1)
    mse = ((sum(list(map(lambda x, y: (x-y) * (x-y), green1, green2)))) / len_img) * 1000000000000000        # mean squared error(MSE)
    if mse == 0:
        return 0.0
    else:
        psnr = 10 * math.log10(255 * 255 * 1000000000000000 / mse)        # peak Signal-to Noise Ratio(PSNR)
        return psnr


# PSNR for blue values
def py_b_psnr(image1, image2):
    blue1, blue2 = [], []
    for line in image1:
        blue1.append(line[2])        # all the values in blue channel of image1
    for line in image2:
        blue2.append(line[2])        # all the values in blue channel of image2
    len_img = len(blue1)
    mse = ((sum(list(map(lambda x, y: (x-y) * (x-y), blue1, blue2)))) / len_img) * 1000000000000000         # mean squared error(MSE)
    if mse == 0:
        return 0.0
    else:
        psnr = 10 * math.log10(255 * 255 * 1000000000000000 / mse)        # peak Signal-to Noise Ratio(PSNR)
        return psnr


# PSNR for
def py_total_psnr(image1, image2):
    len_line = len(image1[0])
    # Determining whether they are coloured images or monochrome images
    if len_line != 1:
        red1, red2, green1, green2, blue1, blue2 = [], [], [], [], [], []
        for line in image1:        # Values for all colour channels in image1
            red1.append(line[0])
            green1.append(line[1])
            blue1.append(line[2])
        for line in image2:        # Values for all colour channels in image2
            red2.append(line[0])
            green2.append(line[1])
            blue2.append(line[2])
        len_img = len(red1)
        # mean squared error(MSE) for coloured images
        mse = ((sum(list(map(lambda x, y: (x-y) * (x-y), red1, red2))) + sum(list(map(lambda x, y: (x-y) * (x-y), green1, green2))) + sum(list(map(lambda x, y: (x-y) * (x-y), blue1, blue2)))) / (3 * len_img)) * 1000000000000000 
        if mse == 0:
            return 0.0
        else:
            psnr = 10 * math.log10(255 * 255 * 1000000000000000 / mse)        # peak Signal-to Noise Ratio(PSNR)
            return psnr
    else:       # for monochrome images
        pixel1, pixel2 = [], []
        for line in image1:
            pixel1.append(line[0])
        for line in image2:
            pixel2.append(line[0])
        len_img = len(pixel1)
        mse = ((sum(list(map(lambda x, y: (x-y) * (x-y), pixel1, pixel2)))) / len_img) * 1000000000000000 
        if mse == 0:
            return 0.0
        else:
            psnr = 10 * math.log10((255 * 255 * 1000000000000000 / mse))
            return psnr



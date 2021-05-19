import py_functions
import translation
import os


# Determine if a string is an integer
def isinteger(x):
    try:
        x = int(x)
        return isinstance(x, int)
    except ValueError:
        return False


def ask_indexofimage1():
    while True:
        image1 = input('What is the index of the image you would like to select? ')
        if isinteger(image1) == False:
            print('That is not a valid integer.')
            continue
        elif int(image1) > len(loaded_image) or int(image1) < 1:
            print('The index should be between 1 and {}.'.format(len(loaded_image)))
        else:
            break
    return image1
    


def ask_indexofimage2():
    while True:
        image2 = input('What is the index of the image you would like to select? ')
        if isinteger(image2) == False:
            print('That is not a valid integer.')
            continue
        elif int(image2) > len(loaded_image) or int(image2) < 1:
            print('The index should be between 1 and {}.'.format(len(loaded_image)))
        else:
            break
    return image2


loaded_image = []
mode_num = 1
print('Welcome to the PSNR image menu!')
while True:
    if mode_num % 2 == 0:       # check the mode
        mode = 'C'
    else:
        mode = 'Python'
    print('')
    print("--- PSNR Image Menu ---")
    print('')
    print("Mode: {}\nType 'help' to see all commands".format(mode))
    print('')
    while True:
        command = input().lower().strip(' ')
        # load
        if command == 'load':
            filename = input('Enter the filename you want to load: ')
            if os.path.exists(filename) == False:       # file exist?
                print('Error: File does not exist.')
                break
            elif os.path.getsize(filename) == 0:        # file empty?
                print('Error: File is empty.')
                break
            try:
                with open(filename, 'r') as img:
                    image = img.readlines()
            except UnicodeDecodeError:
                print('Error: Image does not appear in RGB or monochrome format.')
                break
            flag = False
            image_list = []
            count = 0
            for index, line in enumerate(open(filename, 'r')):      # how many lines in the file
                count += 1
            for line in image:
                image_list.extend(line.split(','))
            for i in range(0, len(image_list)):
                image_list[i] = image_list[i].strip('\n')
            for line in image:
                if len(line.split(',')) != 3 and len(line.split(',')) != 1:        # There must be 1 or 3 pixels in each row
                    print('Error: Image does not appear in RGB or monochrome format.')
                    flag = True
                    break
            if flag == True:
                break
            # The total number of pixels must be equal to the number of rows or three times the number of rows
            if len(image_list) != count and len(image_list) != 3*count:
                print('Error: Image does not appear in RGB or monochrome format.')
                break
            else:
                for i in image_list:
                    if len(i) == 0:
                        print('Error: Image does not appear in RGB or monochrome format.')
                        flag = True
                        break
            if flag == True:
                break
            else:
                for i in image_list:
                    if i.strip() != i:
                        print('Error: Image does not appear in RGB or monochrome format.')
                        flag = True
                        break
                    elif isinteger(i) == False:
                        print('Error: Non-integer value found in image file.')
                        flag = True
                        break
                    elif int(i) < 0 or int(i) > 255:
                        print('Error: Number outside the range of 0 to 255 found in image file.')
                        flag = True
                        break
            if flag == True:
                break
            image_c = []
            for line in image:
                result = line.strip('\n')
                result = result.split(',')
                for i in range(0, len(result)):
                    result[i] = int(result[i])
                image_c.append(result)
            loaded_image.append(image_c)
            break
        # show
        elif command == 'show':
            if len(loaded_image) == 0:
                print('No loaded images to show.')
                break
            else:
                print('Loaded images:')
                for i in range(0, len(loaded_image)):
                    if len(loaded_image[i][0]) == 1:
                        image_type = 'monochrome'
                    else:
                        image_type = 'colour'
                    print('Image {}, Length {}, {}.'.format(i+1, len(loaded_image[i]), image_type))
                break
        # psnr-r
        elif command == 'psnr-r':
            if len(loaded_image) == 0:
                print('No images have been loaded. No image can be selected.')
                break
            else:
                image1 = ask_indexofimage1()
                image2 = ask_indexofimage2()
                img1 = loaded_image[int(image1)-1]
                img2 = loaded_image[int(image2)-1]
                # Determining whether the image is monochrome
                if len(img1[0]) == 1 or len(img2[0]) == 1:
                    print('One of those images is not in colour; cannot compute red PSNR.')
                    break
                # Determine if the images are the same size
                elif len(img1) != len(img2):
                    print('Images are not the same length; cannot compute PSNR between them.')
                    break
                else:
                    if mode == 'Python':
                        print('Red PSNR: {}'.format(py_functions.py_r_psnr(img1, img2)))
                        break
                    else:
                        print('Red PSNR: {}'.format(translation.call_c_r_psnr(img1, img2)))
                        break
        # psnr-g
        elif command == 'psnr-g':
            if len(loaded_image) == 0:
                print('No images have been loaded. No image can be selected.')
                break
            else:
                image1 = ask_indexofimage1()
                image2 = ask_indexofimage2()
                img1 = loaded_image[int(image1)-1]
                img2 = loaded_image[int(image2)-1]
                # Determining whether the image is monochrome
                if len(img1[0]) == 1 or len(img2[0]) == 1:
                    print('One of those images is not in colour; cannot compute green PSNR.')
                    break
                # Determine if the images are the same size
                elif len(img1) != len(img2):
                    print('Images are not the same length; cannot compute PSNR between them.')
                    break
                else:
                    if mode == 'Python':
                        print('Green PSNR: {}'.format(py_functions.py_g_psnr(img1, img2)))
                        break
                    else:
                        print('Green PSNR: {}'.format(translation.call_c_g_psnr(img1, img2)))
                        break
        # psnr-b
        elif command == 'psnr-b':
            if len(loaded_image) == 0:
                print('No images have been loaded. No image can be selected.')
                break
            else:
                image1 = ask_indexofimage1()
                image2 = ask_indexofimage2()
                img1 = loaded_image[int(image1)-1]
                img2 = loaded_image[int(image2)-1]
                # Determining whether the image is monochrome
                if len(img1[0]) == 1 or len(img2[0]) == 1:
                    print('One of those images is not in colour; cannot compute blue PSNR.')
                    break
                # Determine if the images are the same size
                elif len(img1) != len(img2):
                    print('Images are not the same length; cannot compute PSNR between them.')
                    break
                else:
                    if mode == 'Python':
                        print('Blue PSNR: {}'.format(py_functions.py_b_psnr(img1, img2)))
                        break
                    else:
                        print('Blue PSNR: {}'.format(translation.call_c_b_psnr(img1, img2)))
                        break
        # psnr
        elif command == 'psnr':
            if len(loaded_image) == 0:
                print('No images have been loaded. No image can be selected.')
                break
            else:
                image1 = ask_indexofimage1()
                image2 = ask_indexofimage2()
                img1 = loaded_image[int(image1)-1]
                img2 = loaded_image[int(image2)-1]
                # Determine if the image type is the same
                if len(img1[0]) != len(img2[0]):
                    print('Images are not the same type; cannot compute PSNR between them.')
                    break
                # Determine if the images are the same size
                elif len(img1) != len(img2):
                    print('Images are not the same length; cannot compute PSNR between them.')
                    break
                else:
                    if mode == 'Python':
                        print('PSNR of images: {}'.format(py_functions.py_total_psnr(img1, img2)))
                        break
                    else:
                        print('PSNR of images: {}'.format(translation.call_c_total_psnr(img1, img2)))
                        break
        # mode
        elif command == 'mode':
            mode_num += 1
            break
        # help
        elif command == 'help':
            print(' ')
            print('Commands:\n'
                  'load: Load a single image into the program for use\n'
                  'show: Display all images currently loaded\n'
                  'psnr-r: Calculate the PSNR between the red values for two colour images\n'
                  'psnr-g: Calculate the PSNR between the green values for two colour images\n'
                  'psnr-b: Calculate the PSNR between the blue values for two colour images\n'
                  'psnr: Calculate the PSNR between all values for two images\n'
                  'mode: Toggle mode between C and Python\n'
                  'help: Print out this command list\n'
                  'quit: Exit the PSNR Image Menu')
            break
        # quit
        elif command == 'quit':
            exit()
        else:
            print('Invalid command.')

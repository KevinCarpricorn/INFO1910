# with open('test.txt', 'r') as img:
#     image = img.readlines()
# image_list = []
# count = 0
# for index, line in enumerate(open('test.txt', 'r')):
#     count += 1
# for line in image:
#     image_list.extend(line.split(','))
# for i in range(0, len(image_list)):
#     image_list[i] = image_list[i].replace('\n', '')
# testlist = []
# for line in image:
#     x = line.replace('\n', '')
#     x = x.split(',')
#     for i in range(0, len(x)):
#         x[i] = int(x[i])
#     testlist.append(x)
# print(testlist)

import numpy as np
x = np.array([[1, 0], [0, 1], [3, 6]])
print(np.linalg.det(x))


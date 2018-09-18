#!usr/bin/env python
#-*-coding:utf-8-*-

import cv2
import numpy as np
import matplotlib.pyplot as plt

img = np.zeros((100,100),dtype=np.int8)

points = np.array([[1,1],[1,98],[98,98]])#,[98,1]])


cv2.fillConvexPoly(img, points, 1)
#cv2.fillPoly(img, [points], 1)
print(img)
plt.imshow(img, cmap='gray')
plt.show()

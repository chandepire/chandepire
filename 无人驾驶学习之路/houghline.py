#!usr/bin/env python
#-*-coding:utf-8-*-

import cv2

import numpy as np

def hough_detectline(img):
    thetas = np.deg2rad(np.arange(0,180))
    row,col = img.shape
    diag_len = np.ceil(np.sqrt(row**2+col**2))
    rhos = np.linspace(-diag_len,diag_len,int(2*diag_len))
    cos_t = np.cos(thetas)
    sin_t = np.sin(thetas)
    num_theta = len(thetas)

    #vote
    vote = np.zeros((int(2*diag_len),num_theta),dtype=np.uint64)
    y_inx,x_inx = np.nonzero(img)

    for i in range(len(x_inx)):
        x = x_inx[i]
        y = y_inx[i]
        for j in range(num_theta):
            rho = round(x*cos_t[j]+y*sin_t[j])+diag_len
            vote[int(rho),j] += 1

    return vote,rhos,thetas

image = np.zeros((500,500))

image[10:100,10:100] = np.eye(90)

accumulator, rhos, thetas = hough_detectline(image)

idx = np.argmax(accumulator)

rho = rhos[int(idx/accumulator.shape[1])]

theta = thetas[idx % accumulator.shape[1]]

k=-np.cos(theta)/np.sin(theta)

b=rho/np.sin(theta)

x=np.float32(np.arange(1,150,2))

#要在image 上画必须用float32，要不然会报错(float不行)

y=np.float32(k*x+b)

cv2.imshow("original image",image),cv2.waitKey(0)

for i in range(len(x)-1):

   cv2.circle(image,(x[i],y[i]),5,(255,0,0),1)

cv2.imshow("hough",image),cv2.waitKey(0)

print ("rho={0:.2f}, theta={1:.0f}".format(rho, np.rad2deg(theta)))

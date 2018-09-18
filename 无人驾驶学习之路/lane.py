#!usr/bin/env python
#-*-coding:utf-8-*-

import matplotlib.image as mplimg
import cv2
import numpy as np

#matplotlib 读取图片格式为RGB，cv2读取格式为BGR
#img = mplimg.imread("./images/lane_original.png")
img = cv2.imread("./images/lane_original.png")
#灰度图变换
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
#滤波降噪
blur_ksize = 5
blur_gray  = cv2.GaussianBlur(gray,(blur_ksize,blur_ksize),0,0)
#Canny 边界检测
canny_lthreshold = 70
canny_hthreshold = 150
edges = cv2.Canny(gray,canny_lthreshold,canny_hthreshold)

print(img.shape)

def roi_mask(img, vertices):
    mask = np.zeros_like(img)
    mask_color = 255
    cv2.fillPoly(mask, vertices, mask_color)
    masked_img = cv2.bitwise_and(img, mask)
    return masked_img

roi_vtx = np.array([[(0,img.shape[0]), (307,172),
                     (504, 290), (img.shape[1], img.shape[0])]])
roi_edges = roi_mask(edges, roi_vtx)

#霍夫变换
rho = 1
theta = np.pi / 180
threshold = 15
min_line_length = 60
max_line_gap    = 30


def draw_lanes(img, lines, color=[255, 0, 0], thickness=8):
  left_lines, right_lines = [], []
  for line in lines:
    for x1, y1, x2, y2 in line:
      k = (y2 - y1) / (x2 - x1)
      if k < 0:
        left_lines.append(line)
      else:
        right_lines.append(line)

  if (len(left_lines) <= 0 or len(right_lines) <= 0):
    return img

  clean_lines(left_lines, 0.1)
  clean_lines(right_lines, 0.1)
  print(left_lines)
  print(right_lines)
  left_points = [(x1, y1) for line in left_lines for x1,y1,x2,y2 in line]
  left_points = left_points + [(x2, y2) for line in left_lines for x1,y1,x2,y2 in line]
  right_points = [(x1, y1) for line in right_lines for x1,y1,x2,y2 in line]
  right_points = right_points + [(x2, y2) for line in right_lines for x1,y1,x2,y2 in line]

  left_vtx = calc_lane_vertices(left_points, 325, img.shape[0])
  right_vtx = calc_lane_vertices(right_points, 325, img.shape[0])

  cv2.line(img, left_vtx[0], left_vtx[1], color, thickness)
  cv2.line(img, right_vtx[0], right_vtx[1], color, thickness)

def calc_lane_vertices(point_list, ymin, ymax):
  x = [p[0] for p in point_list]
  y = [p[1] for p in point_list]
  fit = np.polyfit(y, x, 1)
  fit_fn = np.poly1d(fit)

  xmin = int(fit_fn(ymin))
  xmax = int(fit_fn(ymax))

  return [(xmin, ymin), (xmax, ymax)]

def clean_lines(lines, threshold):
  slope = [(y2 - y1) / (x2 - x1) for line in lines for x1, y1, x2, y2 in line]
  while len(lines) > 0:
    mean = np.mean(slope)
    diff = [abs(s - mean) for s in slope]
    idx = np.argmax(diff)
    if diff[idx] > threshold:
      slope.pop(idx)
      lines.pop(idx)
    else:
        break

def hough_lines(img, rho, theta, threshold,
                min_line_len, max_line_gap):
  lines = cv2.HoughLinesP(img, rho, theta, threshold, np.array([]),
                          minLineLength=min_line_len,
                          maxLineGap=max_line_gap)
  line_img = np.zeros((img.shape[0], img.shape[1], 3), dtype=np.uint8)
  draw_lanes(line_img, lines)
  return line_img


line_img = hough_lines(roi_edges, rho, theta, threshold, min_line_length, max_line_gap)

res_img = cv2.addWeighted(img, 0.8, line_img, 1, 0)

cv2.namedWindow("2")
cv2.imshow("2",line_img)
cv2.namedWindow("1")
cv2.imshow("1",res_img)
cv2.waitKey(0)

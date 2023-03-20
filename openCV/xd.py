import cv2
import numpy as np

imagen = 255*np.ones((84,84,3), dtype=np.uint8)
#cv2.line(imagen,(600,400),(0,0),(0,0,0),4)
cv2.rectangle(imagen,(0,28),(84,56),(255,120,0),-1)
cv2.imshow('Linea',imagen)
cv2.waitKey(0)
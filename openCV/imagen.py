import cv2
import numpy as np

#imagen2 = 255*np.ones((84,84,3),dtype=np.uint8)
#dibujando la linea
#cv2.line(imagen2, (0,56), (84,28), (0,0,0), 20)


imagen = cv2.imread('checkboard.jpg')
#cv2.imshow('Tablero',imagen,)
cv2.rectangle(imagen, (0,56), (84,28), (0,0,0), -1)
cv2.imshow('Checkboard',imagen)
cv2.waitKey(0)
cv2.destroyAllWindows()
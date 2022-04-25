# pip install opencv-python
import cv2
img = cv2.imread("lena.jpg")
cv2.imshow("output image -> ",img)
cv2.waitKey(0)
cv2.destroyAllWindows()
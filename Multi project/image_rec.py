from PIL import Image
import sys
original = Image.open(sys.argv[1])
corrected = Image.open(sys.argv[2])
error = 0.00
height = original.height
print original.getpixel((0,0))
for i in range (0,height):
	if original.getpixel((0,i)) != corrected.getpixel((0,i)):
		error +=1
print "The error rate is " 
print error/height
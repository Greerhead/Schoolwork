#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>

using namespace cv;

int main(int argc, char** argv){
Mat src, src_gray;
Mat grad;
int scale = 1;
int delta = 0;
int ddepth = CV_16S;

src = imread( argv[1] );

GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);

cvtColor(src,src_gray,CV_BGR2GRAY);

Mat gradx, grady;
Mat absgradx,absgrady;

Sobel(src_gray,gradx,ddepth,1,0,3,scale,delta,BORDER_DEFAULT);
convertScaleAbs(gradx,absgradx);

Sobel(src_gray,grady,ddepth,0,1,3,scale,delta,BORDER_DEFAULT);
convertScaleAbs(grady,absgrady);

addWeighted(absgradx,.5,absgrady,.5,0,grad);

imwrite("/home/josgreer/public_html/gradx.jpg", gradx);
imwrite("/home/josgreer/public_html/grady.jpg", grady);

Sobel(src_gray,gradx,ddepth,1,0,5,scale,delta,BORDER_DEFAULT);
convertScaleAbs(gradx,absgradx);

Sobel(src_gray,grady,ddepth,0,1,5,scale,delta,BORDER_DEFAULT);
convertScaleAbs(grady,absgrady);

addWeighted(absgradx,.5,absgrady,.5,0,grad);

imwrite("/home/josgreer/public_html/gradx5.jpg", gradx);
imwrite("/home/josgreer/public_html/grady5.jpg", grady);

return 0;
}



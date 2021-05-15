// creating canvas, drawing and texting

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // White img canvas
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));// 8UC3= 8bit_Unsign_Channel_3 // Scalar(B,G,R)=creatingColorImg

    // circle
    circle(img, Point(256, 256), 155, Scalar(0, 0, 255), FILLED); //2=thickness // fill?, then FILLED
    // rectangle (inside circle)
    rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
    // line
    line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255));
    // Put a text
    putText(img, "Hello", Point(137, 262), FONT_HERSHEY_DUPLEX, 2, Scalar(0, 0, 255));

    //print
    imshow("Original img", img);

    waitKey(0);

    return 0;
}

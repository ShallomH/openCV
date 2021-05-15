// warp perspective

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// defining card w and h
float w = 250, h = 350;
// defining matrix
Mat matrix, imgWarp;

int main() {
    // warp
    string path = "../card.PNG";
    Mat img = imread(path);

    // extract a point
    Point2f src[4] = {{460, 125}, {669, 166}, {352, 340}, {585, 396}};
    // define the size as we like
    Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    // use transformation matrix to find the card // i.e we will have img as top view
    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    // creating circle at the corners
    for (int i = 0; i < 4; i++){
        circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
    }

    //print
    imshow("Original img", img);
    imshow("Warp img", imgWarp);

    waitKey(0);

    return 0;
}

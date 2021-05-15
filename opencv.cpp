#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// loading image
int main() {
    string path = "../tiger.png";
    Mat img = imread(path);
    imshow("Tiger image", img);
    waitKey(0); // adding wait to show img, 0 for infinity
    return 0;

}

///////////////////////////////////////////

// loading video

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// video: is a series of images i.e needs to iterate through all the images, capture them 1 by 1 and display them
int main() {
    VideoCapture cap(0);
    Mat img;

    while (true) {
        cap.read(img);
        imshow("Webcam image", img);
        waitKey(1); // adding wait to show img, 0 for infinity
    }

    return 0;
}

////////////////////////////////////////////


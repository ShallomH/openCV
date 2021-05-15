// Resize and Crop img

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


// Resizing the org img
int main() {
    string path = "../tiger.png";
    Mat img = imread(path);

    //cout << img.size() << endl; // This gonna show the size of tiger.png img which is 1200x1200
    // Resizing the org img
    Mat imgResize;
    //resize(img, imgResize, Size(640, 480));
    resize(img, imgResize, Size(), 0.5, 0.5 ); // more convenient of scaling the org img by 50%

    //print
    imshow("Original img", img);
    imshow("Resizing", imgResize);

    waitKey(0);

    return 0;
}

//////////////////////////////////////

// cropping img

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    string path = "../tiger.png";
    Mat img = imread(path);

    Mat imgCrop;
    Rect myCrop(100, 100, 300, 250); // x,y is start pixel point on org img
    imgCrop = img(myCrop);

    //print
    imshow("Original img", img);
    imshow("Cropping", imgCrop);

    waitKey(0);

    return 0;
}


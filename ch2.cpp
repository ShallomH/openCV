// color to gray

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    string path = "../tiger.png";
    Mat img = imread(path);

    //convert img into gray scale
    Mat imgGray;
    cvtColor(img, imgGray, COLOR_BGR2GRAY);

    //print
    imshow("Original img", img);
    imshow("Gray img", imgGray);
    waitKey(0);

    return 0;
}

/////////////////////////////////////////////////

// blur img(Gaussian blur)

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    string path = "../tiger.png";
    Mat img = imread(path);

    //blur img
    Mat imgBlur;
    GaussianBlur(img, imgBlur, Size(7, 7), 10, 10);


    //print
    imshow("Original img", img);
    imshow("Blur img", imgBlur);
    waitKey(0);

    return 0;
}

//////////////////////////////////////////////////////

// Edge detection

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    string path = "../tiger.png";
    Mat img = imread(path);

    //blur img
    Mat imgBlur;
    GaussianBlur(img, imgBlur, Size(7, 7), 10, 10);

    //canny i.e edge detection. Note: blur img needs to proceed canny
    Mat imgCanny;
    Canny(imgBlur, imgCanny, 50, 150); // threshold1 and threshold2 you can play around with

    //print
    imshow("Original img", img);
    imshow("Canny", imgCanny);
    waitKey(0);

    return 0;
}

/////////////////////////////////////////////////////

// Dilation and Erosion
// A lot of time when we detect the edges, they are not completely fill i.e they are not joint (or) they are very thin to detect propely.
// What we can do is we can dilate it i.e increase thickness 
// or Erose it i.e decrease the thickness

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    string path = "../tiger.png";
    Mat img = imread(path);

    // blur img
    Mat imgBlur;
    GaussianBlur(img, imgBlur, Size(7, 7), 10, 10);

    // canny i.e edge detection. Note: blur img needs to proceed canny
    Mat imgCanny;
    Canny(imgBlur, imgCanny, 50, 150); // threshold1 and threshold2 you can play around with

    // dilate i.e adding thickness. Note: dilation needs canny img
    Mat imgDilate, imgErode;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5)); // Size = thickness
    dilate(imgCanny, imgDilate, kernel);
    erode(imgDilate, imgErode, kernel);

    //print
    imshow("Original img", img);
    imshow("Dilation", imgDilate);
    imshow("Erosion", imgErode);
    waitKey(0);

    return 0;
}



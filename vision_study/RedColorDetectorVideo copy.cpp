#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

 int main( int argc, char** argv )
 {
    VideoCapture cap("KOR_DAY_SCENES\\%05d.jpg"); 
    //filename(parameter) – name of the opened video file (eg. video.avi)
    //filename(parameter) – image sequence (eg. img_%02d.jpg, which will read samples like img_00.jpg, img_01.jpg, img_02.jpg, ...)
    //%05d.jpg = 00000.jpg ~ 99999.jpg까지의 이미지 파일을 전부 읽어오기
    // + device – id of the opened video capturing device (i.e. a camera index). If there is a single camera connected, just pass 0.
    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the web cam" << endl;
         return -1;
    }

    namedWindow("Control", WINDOW_NORMAL); //create a window called "Control" + not "CV_WINDOW_AUTOSIZE" -> "WINDOW_AUTOSIZE"
    moveWindow("Control", 0,0);
    resizeWindow("Control", 300,250);

 int iLowH = 0;
 int iHighH = 179;

 int iLowS = 0; 
 int iHighS = 255;

 int iLowV = 0;
 int iHighV = 255;

 //Create trackbars in "Control" window
 createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179) + not "cvCreateTrackbar" -> "createTrackbar"
 createTrackbar("HighH", "Control", &iHighH, 179);

 createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
 createTrackbar("HighS", "Control", &iHighS, 255);

 createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
 createTrackbar("HighV", "Control", &iHighV, 255);

    while (true)
    {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }

   Mat imgHSV; // 이미지 자체를 건들고 싶다면 Mat의 속성을 바꿔라
               // 이미지를 띄우는 window만 건들고 싶다면 (~) Window라는 명령어들을 활용하여 속성을 바꿔라

  cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

  Mat imgThresholded;

  inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
      
  //morphological opening (remove small objects from the foreground)
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

  //morphological closing (fill small holes in the foreground)
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

//  imshow("Thresholded Image", imgThresholded); //show the thresholded image
//  imshow("Original", imgOriginal); //show the original image

  Mat imgOriginalResize;
  resize(imgOriginal, imgOriginalResize, Size(256, 256), 0, 0, INTER_LINEAR); //CV_INTER_LINEAR -> INTER_LINEAR

  Mat imgThresholdedResize;
  resize(imgThresholded, imgThresholdedResize, Size(256, 256), 0, 0, INTER_LINEAR);

  imshow("Thresholded Image", imgThresholdedResize); //show the thresholded Resize image
  imshow("Original", imgOriginalResize); //show the original Resize image

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break; 
       }
    }

   return 0;

}
#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char** argv)
{
    VideoCapture cap("KOR_DAY_SCENES\\%05d.jpg");
    //filename(parameter) – name of the opened video file (eg. video.avi)
    //filename(parameter) – image sequence (eg. img_%02d.jpg, which will read samples like img_00.jpg, img_01.jpg, img_02.jpg, ...)
    //%05d.jpg = 00000.jpg ~ 99999.jpg까지의 이미지 파일을 전부 읽어오기
    // + device – id of the opened video capturing device (i.e. a camera index). If there is a single camera connected, just pass 0.
    if (!cap.isOpened())
        cout << "Error opening video stream or file" << endl;
        return -1;

    Mat frame;
    
    while(1)
    {
        cap.read(frame);
        if (frame.empty())
            break;

        imshow("image", frame);
        if(waitKey(33)>=0)
            break;
        //0.033s per 1 frame -> 0.990s per 30 frame
    }
    return 0;
}
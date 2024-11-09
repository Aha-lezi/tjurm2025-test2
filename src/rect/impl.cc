#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat gray,bin;
    std::vector<cv::Vec4i> hierarchy;
    cv::cvtColor(input,gray,cv::COLOR_BGR2GRAY);
    cv::threshold(gray,bin,0,255,cv::THRESH_BINARY_INV+cv::THRESH_OTSU);
    std::vector<std::vector<cv::Point>>contours;
    cv::findContours(bin,contours,hierarchy,cv::RETR_LIST,cv::CHAIN_APPROX_SIMPLE);
    cv::Rect b;
    cv::RotatedRect c;
    if(!contours.empty()){
        b=cv::boundingRect(contours[0]);
        c=cv::minAreaRect(contours[0]);
        for(size_t i=1;i<contours.size();i++){
            cv::Rect crect=cv::boundingRect(contours[i]);
            if(crect.area()>b.area()){
                b=crect;
                c=cv::minAreaRect(contours[i]);
            }
        }
    }
    res=std::make_pair(b,c);
    return res;
}
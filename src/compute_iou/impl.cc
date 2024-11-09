#include "impls.h"
#include <algorithm>

float compute_iou(const cv::Rect& a, const cv::Rect& b) {
    /**
     * 要求：
     *      有一个重要的指标叫做“交并比”，简称“IOU”，可以用于衡量
     * 两个矩形的重合程度，本练习要求自行学习交并比的计算方式，计算输入
     * 的两个矩形的交并比。
     * 
     * 提示：
     * (1) 注意OpenCV中规定的xy坐标系方向跟平常的xy坐标系不一样。
     * (2) 注意矩形的x, y, width, height四个属性在坐标系内的含义。
     * (3) 注意分母不要除以0（不过我们不会测试这一点）
     * 
     * 通过条件：
     * 运行测试点，显示通过就行，不通过会告诉你哪一组矩形错了。
    */
    // IMPLEMENT YOUR CODE HERE
    int x1=std::max(a.x,b.x);
    int y1=std::max(a.y,b.y);
    int ax2=a.x+a.width;
    int ay2=a.y+a.height;
    int bx2=b.x+b.width;
    int by2=b.y+b.height;
    int x2=std::min(ax2,bx2);
    int y2=std::min(ay2,by2);
    int js_width=std::max(0,x2-x1);
    int js_hight=std::max(0,y2-y1);
    float js=js_hight*js_width;
    float as=a.width*a.height;
    float bs=b.height*b.width;
    float sums=as+bs-js;
    if(sums>0){
        return js/sums;
    }
    else{
        return 0.f;
    }
}
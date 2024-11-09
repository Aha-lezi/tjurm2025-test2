#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat output(new_rows, new_cols, input.type());
    for(int i=0;i<new_cols;i++){
        for(int j=0;j<new_rows;j++){
            float x=j/scale;
            float y=i/scale;
            int x1=static_cast<int>(x);
            int y1=static_cast<int>(y);
            if(x1<input.rows && y1<input.cols && x1>=0 && y1>=0){
                cv::Vec3b& a =output.at<cv::Vec3b>(j,i);
                const cv::Vec3b& b =input.at<cv::Vec3b>(x1,y1);
                a[0]=b[0];
                a[1]=b[1];
                a[2]=b[2];
            }
        }
    }
    return output;
}
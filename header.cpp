//
//  header.cpp
//  Chapter02_DisplayingImage
//
//  Created by Faiz Akram on 25/08/17.
//  Copyright © 2017 Alexander Shishkov & Kirill Kornyakov. All rights reserved.
//

#include "header.hpp"

void printString(string str)
{
    cout<<"Input string was "<<str<<endl;
}
int addThem(int i1,int i2)
{
    return (i1 + i2);
}
double multiplyThem(double d1,double d2)
{
    return (d1*d2);
}
void edgeDetection(cv::Mat srcRGB,cv::Mat& draw)
{
    cv::Mat gray, edge;
    cvtColor(srcRGB, gray, CV_BGR2GRAY);
    Canny( gray, edge, 50, 150, 3);
    edge.convertTo(draw, CV_8U);
}
double correlationCalculation(cv::Mat sourceImage,cv::Mat templateImage,cv::Mat& correlationImage)
{
    cvtColor(sourceImage,sourceImage,CV_BGR2GRAY);
    cvtColor(templateImage,templateImage,CV_BGR2GRAY);
    
    cv::Mat result;
    int result_cols =  sourceImage.cols - templateImage.cols + 1;
    int result_rows = sourceImage.rows - templateImage.rows + 1;
    
    result.create( result_rows, result_cols, CV_32FC1 );
    if(templateImage.channels() == 1 && sourceImage.channels() == 1){
        
        matchTemplate(sourceImage,templateImage,result,CV_TM_CCOEFF_NORMED);
        
        
        normalize( result, result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );
        double minVal; double maxVal; cv::Point minLoc; cv::Point maxLoc;
        cv::Point matchLoc;
        
        minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat() );
        matchLoc = maxLoc;
        
        rectangle( correlationImage, matchLoc, cv::Point( matchLoc.x + templateImage.cols , matchLoc.y + templateImage.rows ), cv::Scalar::all(255), 2, 8, 0 );
        
        cvtColor(correlationImage,correlationImage,CV_BGR2RGB);
        
        return 1.0;
    }
    return 0.0;
}

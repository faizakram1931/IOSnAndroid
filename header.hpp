//
//  header.hpp
//  Chapter02_DisplayingImage
//
//  Created by Faiz Akram on 25/08/17.
//  Copyright © 2017 Alexander Shishkov & Kirill Kornyakov. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

void printString(string);
double multiplyThem(double,double);
int addThem(int,int);
void edgeDetection(cv::Mat,cv::Mat& );
double correlationCalculation(cv::Mat,cv::Mat,cv::Mat& );

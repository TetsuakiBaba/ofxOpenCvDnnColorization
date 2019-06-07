#pragma once

#include "ofMain.h"
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace cv;
using namespace cv::dnn;
using namespace std;



class ofxOpenCvDnnColorization{
public:
    ofxOpenCvDnnColorization();
    ~ofxOpenCvDnnColorization();
    void setup(string _path_to_cfg, string _path_to_weights);
    void update(ofPixels &op);
    void setNetworkImageSize(int _w, int _h);
    void draw(int _x, int _y, int _w, int _h);
    void draw(int _x, int _y);
    
    cv::Mat toCV(ofPixels &pix);
    dnn::Net net;
    int network_width = 226;
    int network_height = 226;
    int input_width;
    int input_height;
    
    
    ofImage image_colored;
    Mat color;
};

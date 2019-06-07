#pragma once

#include "ofMain.h"
#include "ofxOpenCvDnnColorization.h"
class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    ofVideoPlayer video;
    ofxOpenCvDnnColorization colorization;
		
};

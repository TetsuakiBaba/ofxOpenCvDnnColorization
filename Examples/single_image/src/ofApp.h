#pragma once

#include "ofMain.h"
#include "ofxOpenCvDnnColorization.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void dragEvent(ofDragInfo dragInfo);
    
    ofImage img;
    ofxOpenCvDnnColorization colorization;
};

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video.load(ofToDataPath("aquarium.mp4"));
    ofSetWindowShape(video.getWidth(), video.getHeight()*2);
    colorization.setNetworkImageSize(226, 226);
    colorization.setup(ofToDataPath("colorization_deploy_v2.prototxt"),
                       ofToDataPath("colorization_release_v2.caffemodel")
                       );
    video.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    if( video.isFrameNew() ){
        colorization.update(video.getPixels());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    video.draw(0,0);
    colorization.draw(0,video.getHeight());
    ofDrawBitmapStringHighlight("Original",20,20);
    ofDrawBitmapStringHighlight("Colored",20,20+video.getHeight());
}


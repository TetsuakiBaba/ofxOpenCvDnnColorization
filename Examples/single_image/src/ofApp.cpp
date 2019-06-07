#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load(ofToDataPath("monochrome.jpg"));
    ofSetWindowShape(img.getWidth()*2, img.getHeight());
    colorization.setNetworkImageSize(224, 224);
    colorization.setup(ofToDataPath("colorization_deploy_v2.prototxt"),
                   ofToDataPath("colorization_release_v2.caffemodel"));
    colorization.update(img.getPixels());
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
    img.draw(0,0);
    ofDrawBitmapStringHighlight("Original", ofGetWidth()/2-100, ofGetHeight()-20);
    colorization.draw(ofGetWidth()/2,0);
    ofDrawBitmapStringHighlight("Colorization", ofGetWidth()-100, ofGetHeight()-20);
    
    ofDrawBitmapStringHighlight("Drag and Drop a image file",
                                 ofGetWidth()/2-100,
                                 ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 's' ){
        ofSaveImage(colorization.image_colored.getPixels(), "output.jpg", OF_IMAGE_QUALITY_BEST);
    }
}


//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    if( dragInfo.files.size() > 0 ){
        img.load(dragInfo.files[0]);
    }
    ofSetWindowShape(img.getWidth()*2, img.getHeight());
    colorization.update(img.getPixels());
}

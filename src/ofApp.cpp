#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();

    radius = 0;
    mySound.load("lifelike-126735.mp3");
    mySound.setLoop(true);//on loop
}

//--------------------------------------------------------------
void ofApp::update(){
    float* val = ofSoundGetSpectrum(1);
    radius = val[0] * 9000.0;//apply for circle's
}

//--------------------------------------------------------------
void ofApp::draw(){
    //draw a circle for mouse position
    ofSetColor(0, 204, 0, 180);
    ofDrawCircle(mouseX, mouseY, radius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //setting for pan
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    //change to play speed
    mySound.setSpeed(0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 1.0f);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //setting for pan
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    mySound.setSpeed(0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight()) * 1.0f);
    mySound.play();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mySound.stop();
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

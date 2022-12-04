#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    mySound.load("lifelike-126735.mp3");
    mySound.setLoop(true);//on loop
    mySound.play();//sound play
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
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

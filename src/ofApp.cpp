#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    bufSize = 256;//buffer size
    ofBackground(33, 33, 33);
    ofSetColor(0, 0, 255);

    //setting for play music
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = 512;
    soundStream.setup(settings);

    left = new float[bufSize];
    right = new float [bufSize] ;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float audioHeight = ofGetHeight()/2.0f;
    float phaseDiff = ofGetWidth()/float(bufSize);

    ofSetColor(0, 204, 0);
    ofNoFill();
    ofSetLineWidth(3);

    //draw left channel waveform
    ofBeginShape();
    for (int i = 0; i < bufSize; i++){
        ofVertex(i * phaseDiff, audioHeight/2 + left[i] * audioHeight);
    }
    ofEndShape();

    //draw right channel waveform
    ofBeginShape();
    for (int i = 0; i < bufSize; i++){
        ofVertex(i * phaseDiff, audioHeight / 2 * 3 + right[i] * audioHeight);
    }
    ofEndShape();
}

void ofApp::audioReceived (float * input, int bufferSize, int nChannels){
    //Input a voice
    for (int i = 0; i < bufferSize; i++){
        left[i] = input[i*2];
        right[i] = input[i*2+1];
    }
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

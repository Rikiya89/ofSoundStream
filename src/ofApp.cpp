#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sampleRate = 44100;//sampling frequency
    amp = 0.5;//position
    pan = 0.5;//volume
    phase = 0;
    frequency = 440;
    ofSetFrameRate(30);
    ofBackground(32, 32, 32);

    //setting for play music
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = 512;
    soundStream.setup(settings);
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
        ofVertex(i + phaseDiff, audioHeight/2 + lAudio[i] * audioHeight);
    }
    ofEndShape();

    //draw right channel waveform
    ofBeginShape();
    for (int i = 0; i < bufSize; i++){
        ofVertex(i * phaseDiff, audioHeight / 2 * 3 + rAudio[i] * audioHeight);
    }
    ofEndShape();

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
void ofApp::audioRequested(float* output, int bufferSize, int nChannels) {
    float sample;//output sound's sample
    float phaseDiff;//change to position

    //calculate for 1 sample's position to change
    phaseDiff = TWO_PI * frequency / sampleRate;

    //make a phase of the size of buffer
    for(int i = 0; i < bufferSize; i++) {
        //update a position
        phase += phaseDiff;
        while (phase > TWO_PI){
            phase -= TWO_PI;
        }

        //make a sine waveform
        sample = sin(phase);

        //audio out, left right 2ch
        lAudio [i] =  output[i * nChannels] = sample * pan * amp;

        rAudio [i] = output[i * nChannels + 1] = sample * pan * amp;
    }
}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

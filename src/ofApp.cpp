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
    right = new float [bufSize];
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
        ofVertex(i * phaseDiff, audioHeight/2 + lAudio[i] * audioHeight);
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
    //change to wave from and volume by key type
    switch (key) {
        case '-'://volume down
            amp -= 0.05;
            amp = MAX(amp, 0);
            break;
        case '+'://volume up
            amp += 0.05;
            amp = MIN(amp, 1);
            break;
        case '1': //sin wave
            waveShape = 1;
            break;
        case '2'://sawtooth wave
            waveShape = 2;
            break;
        case '3'://short wave
            waveShape = 3;
            break;
        case '4'://triangle shape
            waveShape = 4;
            break;
        case '5'://white noise
            waveShape = 5;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    pan = (float)x / (float)ofGetWidth();
    float heightPct = (float(ofGetHeight()-y) / float(ofGetHeight()));
    frequency = 4000.0f * heightPct;
    if(frequency < 20) {
        frequency = 20;
    }
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

        //select a waveform
        switch (waveShape) {
            case 1://sin wave
                sample = sin(phase);
                break;
            case 2://sawtooth wave
                sample = - phase / PI + 1;
                break;
            case 3://short wave
                sample = (phase < PI) ? -1 : 1;
                break;
            case 4://triangle wave
                sample = (phase < PI) ? -2 / PI * phase + 1 : 2 / PI * phase -3;
                break;
            case 5://white noise
                sample = ofRandom(-1,1);
        }

        
        //audio out, left right 2ch
        lAudio [i] =  output[i * nChannels] = sample * pan * amp;

        rAudio [i] = output[i * nChannels + 1] = sample * (1.0 - pan) * amp;
    }
}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(100);
    c = 0;
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    c = (c + 1) % 255;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(ofColor::mediumVioletRed);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 300);
        
    ofSetColor(0, 0, 255, 125);
    ofDrawCircle(mouseX, mouseY, 300);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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


void  ofApp::drawCircle(int x, int y, int r, int angleInit, int angleEnd){

    ofBeginShape();
    for(float angle = angleInit; angle <= angleEnd; angle ++){
        float px = x + r * cos(ofDegToRad(angle));
        float py = y + r * sin(ofDegToRad(angle));
        ofVertex(px, py);
    }
    ofEndShape();
}

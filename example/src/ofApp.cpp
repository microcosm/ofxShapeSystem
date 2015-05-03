#include "ofApp.h"

void ofApp::setup(){
    shapeSystem.setup();

    filledSquare.setupFilledSquare(100);
    filledSquare.setPosition(ofVec3f(120, 100, 0));
    shapeSystem.add(filledSquare);

    hollowSquare.setupHollowSquare(25, 75);
    hollowSquare.setPosition(ofVec3f(120, 280, 0));
    shapeSystem.add(hollowSquare);

    gradientSquare.setupGradientSquare(25, 75);
    gradientSquare.setPosition(ofVec3f(120, 460, 0));
    gradientSquare.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(gradientSquare);

    invertedGradientSquare.setupGradientSquare(-25, 75);
    invertedGradientSquare.setPosition(ofVec3f(120, 640, 0));
    invertedGradientSquare.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(invertedGradientSquare);
}

void ofApp::update(){
    shapeSystem.update();
}

void ofApp::draw(){
    ofEnableAlphaBlending();
    shapeSystem.draw();
    ofDisableAlphaBlending();
}

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

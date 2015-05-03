#include "ofApp.h"

void ofApp::setup(){
    shapeSystem.setup();

    filledSquare.setupFilledSquare(20);
    filledSquare.setPosition(ofVec3f(30, 30, 0));
    shapeSystem.add(filledSquare);

    hollowSquare.setupHollowSquare(5, 15);
    hollowSquare.setPosition(ofVec3f(30, 60, 0));
    shapeSystem.add(hollowSquare);

    gradientSquare.setupGradientSquare(5, 15);
    gradientSquare.setBlur(10);
    gradientSquare.setPosition(ofVec3f(30, 90, 0));
    shapeSystem.add(gradientSquare);
}

void ofApp::update(){
    shapeSystem.update();
}

void ofApp::draw(){
    shapeSystem.draw();
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

#include "ofApp.h"

void ofApp::setup(){
    shapeSystem.setup();
    shape.setupFilledSquare(20);
    shape.setPosition(ofVec3f(20, 20, 0));
    shapeSystem.add(shape);
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

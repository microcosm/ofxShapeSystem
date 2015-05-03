#include "ofApp.h"

void ofApp::setup(){
    shapeSystem.setup();

    // Squares
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
    
    // Rings
    filledRing.setupFilledRing(60, 72);
    filledRing.setPosition(ofVec3f(320, 100, 0));
    shapeSystem.add(filledRing);
    
    hollowRing.setupHollowRing(60, 15, 57);
    hollowRing.setPosition(ofVec3f(320, 280, 0));
    shapeSystem.add(hollowRing);
    
    gradientRing.setupGradientRing(60, 15, 57);
    gradientRing.setPosition(ofVec3f(320, 460, 0));
    gradientRing.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(gradientRing);
    
    invertedGradientRing.setupGradientRing(60, -15, 57);
    invertedGradientRing.setPosition(ofVec3f(320, 640, 0));
    invertedGradientRing.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(invertedGradientRing);
    
    // Arcs
    filledArc.setupFilledArc(60, 72, 180);
    filledArc.setPosition(ofVec3f(520, 100, 0));
    shapeSystem.add(filledArc);
    
    hollowArc.setupHollowArc(60, 15, 57, 180);
    hollowArc.setPosition(ofVec3f(520, 280, 0));
    shapeSystem.add(hollowArc);
    
    gradientArc.setupGradientArc(60, 15, 57, 180);
    gradientArc.setPosition(ofVec3f(520, 460, 0));
    gradientArc.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(gradientArc);
    
    invertedGradientArc.setupGradientArc(60, -15, 57, 180);
    invertedGradientArc.setPosition(ofVec3f(520, 640, 0));
    invertedGradientArc.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(invertedGradientArc);
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

#include "ofApp.h"

void ofApp::setup(){
    shapeSystem.setup();

    // Squares
    filledSquare.setupFilledSquare(140);
    filledSquare.setPosition(ofVec3f(120, 100, 0));
    shapeSystem.add(filledSquare);

    hollowSquare.setupHollowSquare(40, 100);
    hollowSquare.setPosition(ofVec3f(120, 280, 0));
    shapeSystem.add(hollowSquare);

    gradientSquare.setupGradientSquare(40, 100);
    gradientSquare.setPosition(ofVec3f(120, 460, 0));
    gradientSquare.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(gradientSquare);

    invertedGradientSquare.setupGradientSquare(-40, 100);
    invertedGradientSquare.setPosition(ofVec3f(120, 640, 0));
    invertedGradientSquare.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(invertedGradientSquare);
    
    // Rings
    filledRing.setupFilledRing(60, 140);
    filledRing.setPosition(ofVec3f(320, 100, 0));
    shapeSystem.add(filledRing);
    
    hollowRing.setupHollowRing(60, 40, 100);
    hollowRing.setPosition(ofVec3f(320, 280, 0));
    shapeSystem.add(hollowRing);
    
    gradientRing.setupGradientRing(60, 40, 100);
    gradientRing.setPosition(ofVec3f(320, 460, 0));
    gradientRing.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(gradientRing);
    
    invertedGradientRing.setupGradientRing(60, -40, 100);
    invertedGradientRing.setPosition(ofVec3f(320, 640, 0));
    invertedGradientRing.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(invertedGradientRing);
    
    // Arcs
    filledArc.setupFilledArc(60, 140, 180);
    filledArc.setPosition(ofVec3f(520, 100, 0));
    shapeSystem.add(filledArc);
    
    hollowArc.setupHollowArc(60, 40, 100, 180);
    hollowArc.setPosition(ofVec3f(520, 280, 0));
    shapeSystem.add(hollowArc);
    
    gradientArc.setupGradientArc(60, 40, 100, 180);
    gradientArc.setPosition(ofVec3f(520, 460, 0));
    gradientArc.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(gradientArc);
    
    invertedGradientArc.setupGradientArc(60, -40, 100, 180);
    invertedGradientArc.setPosition(ofVec3f(520, 640, 0));
    invertedGradientArc.setColor(ofColor(255, 255, 255, 60));
    shapeSystem.add(invertedGradientArc);

    shapes = shapeSystem.getShapes();
}

void ofApp::update(){

}

void ofApp::draw(){
    ofBackground(ofColor::black);
    ofEnableAlphaBlending();
    shapeSystem.draw();
    ofDisableAlphaBlending();
}

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){
    float degreesY = ofMap(x, 0, ofGetWidth(), 0, 360);
    float degreesZ = ofMap(y, 0, ofGetHeight(), 0, 360);
    float blur = ofMap(y, 0, ofGetHeight(), 0, 20, true);

    for(int i = 0; i < shapes.size(); i++) {
        shapes.at(i)->setBlur(blur);
        shapes.at(i)->rotateY(degreesY);
        shapes.at(i)->rotateZ(degreesZ);
    }
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

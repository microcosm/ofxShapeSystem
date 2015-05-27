#include "ofxShapeSystem.h"

//Adapted from:
//http://forum.openframeworks.cc/t/circles-with-holes-or-with-stroke/8173/6
//https://github.com/jasonmcdermott/ofxForums/tree/master/vertexArrayGradientShapes

void ofxShapeSystem::setup() {
    setPosition(ofVec3f(0, 0, 0));
    setRotation(ofVec3f(0, 0, 0));
    setScale(ofVec3f(1, 1, 1));
}

void ofxShapeSystem::add(ofxShape &shape) {
    shapes.push_back(&shape);
}

void ofxShapeSystem::update() {
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->update();
    }
}

void ofxShapeSystem::draw() {
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    ofPushMatrix();
    ofTranslate(position.x, position.y, position.z);
    ofRotateX(rotation.x);
    ofRotateY(rotation.y);
    ofRotateZ(rotation.z);
    ofScale(scale.x, scale.y, scale.z);

    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }

    ofPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void ofxShapeSystem::setPosition(ofVec3f position_) {
    position.set(position_);
}

void ofxShapeSystem::setRotation(ofVec3f rotation_) {
    rotation.set(rotation_);
}

void ofxShapeSystem::setScale(ofVec3f scale_) {
    scale.set(scale_);
}

void ofxShapeSystem::rotateX(float degrees) {
    rotation.x = degrees;
}

void ofxShapeSystem::rotateY(float degrees) {
    rotation.y = degrees;
}

void ofxShapeSystem::rotateZ(float degrees) {
    rotation.z = degrees;
}

void ofxShapeSystem::incrementRotateX(float amount) {
    rotation.x += amount;
}

void ofxShapeSystem::incrementRotateY(float amount) {
    rotation.y += amount;
}

void ofxShapeSystem::incrementRotateZ(float amount) {
    rotation.z += amount;
}

void ofxShapeSystem::positionX(float positionX) {
    position.x = positionX;
}

void ofxShapeSystem::positionY(float positionY) {
    position.y = positionY;
}

void ofxShapeSystem::positionZ(float positionZ) {
    position.z = positionZ;
}

void ofxShapeSystem::incrementPositionX(float amount) {
    position.x += amount;
}

void ofxShapeSystem::incrementPositionY(float amount) {
    position.y += amount;
}

void ofxShapeSystem::incrementPositionZ(float amount) {
    position.z += amount;
}

void ofxShapeSystem::scaleX(float scaleX) {
    scale.x = scaleX;
}

void ofxShapeSystem::scaleY(float scaleY) {
    scale.y = scaleY;
}

void ofxShapeSystem::scaleZ(float scaleZ) {
    scale.z = scaleZ;
}

void ofxShapeSystem::incrementScaleX(float amount) {
    scale.x += amount;
}

void ofxShapeSystem::incrementScaleY(float amount) {
    scale.y += amount;
}

void ofxShapeSystem::incrementScaleZ(float amount) {
    scale.z += amount;
}

vector <ofxShape*> ofxShapeSystem::getShapes() {
    return shapes;
}
#include "ofxTransformable.h"

void ofxTransformable::setup() {
    setPosition(ofVec3f(0, 0, 0));
    setRotation(ofVec3f(0, 0, 0));
    setScale(ofVec3f(1, 1, 1));
}

void ofxTransformable::applyTransformations() {
    ofTranslate(position.x, position.y, position.z);
    ofRotateX(rotation.x);
    ofRotateY(rotation.y);
    ofRotateZ(rotation.z);
    ofScale(scale.x, scale.y, scale.z);
}

void ofxTransformable::setPosition(ofVec3f position_) {
    position.set(position_);
}

void ofxTransformable::setPosition(float x, float y) {
    position.set(ofVec3f(x, y, position.z));
}

void ofxTransformable::setPosition(float x, float y, float z) {
    position.set(ofVec3f(x, y, z));
}

void ofxTransformable::positionX(float positionX) {
    position.x = positionX;
}

void ofxTransformable::positionY(float positionY) {
    position.y = positionY;
}

void ofxTransformable::positionZ(float positionZ) {
    position.z = positionZ;
}

void ofxTransformable::incrementPositionX(float amount) {
    position.x += amount;
}

void ofxTransformable::incrementPositionY(float amount) {
    position.y += amount;
}

void ofxTransformable::incrementPositionZ(float amount) {
    position.z += amount;
}

void ofxTransformable::setRotation(ofVec3f rotation_) {
    rotation.set(rotation_);
}

void ofxTransformable::setRotation(float x, float y) {
    rotation.set(ofVec3f(x, y, rotation.z));
}

void ofxTransformable::setRotation(float x, float y, float z) {
    rotation.set(ofVec3f(x, y, z));
}

void ofxTransformable::rotateX(float degrees) {
    rotation.x = degrees;
}

void ofxTransformable::rotateY(float degrees) {
    rotation.y = degrees;
}

void ofxTransformable::rotateZ(float degrees) {
    rotation.z = degrees;
}

void ofxTransformable::incrementRotateX(float amount) {
    rotation.x += amount;
}

void ofxTransformable::incrementRotateY(float amount) {
    rotation.y += amount;
}

void ofxTransformable::incrementRotateZ(float amount) {
    rotation.z += amount;
}

void ofxTransformable::setScale(ofVec3f scale_) {
    scale.set(scale_);
}

void ofxTransformable::setScale(float x, float y) {
    scale.set(ofVec3f(x, y, scale.z));
}

void ofxTransformable::setScale(float x, float y, float z) {
    scale.set(ofVec3f(x, y, z));
}

void ofxTransformable::scaleX(float scaleX) {
    scale.x = scaleX;
}

void ofxTransformable::scaleY(float scaleY) {
    scale.y = scaleY;
}

void ofxTransformable::scaleZ(float scaleZ) {
    scale.z = scaleZ;
}

void ofxTransformable::incrementScaleX(float amount) {
    scale.x += amount;
}

void ofxTransformable::incrementScaleY(float amount) {
    scale.y += amount;
}

void ofxTransformable::incrementScaleZ(float amount) {
    scale.z += amount;
}

ofVec3f ofxTransformable::getPosition() {
    return position;
}

ofVec2f ofxTransformable::getPositionXY() {
    return ofVec2f(position.x, position.y);
}

ofVec3f ofxTransformable::getRotation() {
    return rotation;
}

ofVec2f ofxTransformable::getRotationXY() {
    return ofVec2f(rotation.x, rotation.y);
}

ofVec3f ofxTransformable::getScale() {
    return scale;
}

ofVec2f ofxTransformable::getScaleXY() {
    return ofVec2f(scale.x, scale.y);
}
#pragma once

#include "ofMain.h"

class ofxTransformable {
    
public:
    void setup();
    void applyTransformations();
    
    void setPosition(ofVec3f position_);
    void setPosition(float x, float y);
    void setPosition(float x, float y, float z);
    void positionX(float positionX);
    void positionY(float positionY);
    void positionZ(float positionZ);
    void incrementPositionX(float amount);
    void incrementPositionY(float amount);
    void incrementPositionZ(float amount);

    void setRotation(ofVec3f rotation_);
    void setRotation(float x, float y);
    void setRotation(float x, float y, float z);
    void rotateX(float degrees);
    void rotateY(float degrees);
    void rotateZ(float degrees);
    void incrementRotateX(float amount);
    void incrementRotateY(float amount);
    void incrementRotateZ(float amount);

    void setScale(ofVec3f rotation_);
    void setScale(float x, float y);
    void setScale(float x, float y, float z);
    void scaleX(float scaleX);
    void scaleY(float scaleY);
    void scaleZ(float scaleZ);
    void incrementScaleX(float amount);
    void incrementScaleY(float amount);
    void incrementScaleZ(float amount);
    
    ofVec3f getPosition();
    ofVec2f getPositionXY();
    ofVec3f getRotation();
    ofVec2f getRotationXY();
    ofVec3f getScale();
    ofVec2f getScaleXY();
    
private:
    ofVec3f position, rotation, scale;
};
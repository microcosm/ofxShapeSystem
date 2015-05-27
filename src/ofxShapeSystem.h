#pragma once

#include "ofxShape.h"

//Adapted from:
//http://forum.openframeworks.cc/t/circles-with-holes-or-with-stroke/8173/6
//https://github.com/jasonmcdermott/ofxForums/tree/master/vertexArrayGradientShapes

#include "ofMain.h"

class ofxShapeSystem {
    
public:
    void setup();
    void add(ofxShape &shape);
    void update();
    void draw();

    void setPosition(ofVec3f position_);
    void setRotation(ofVec3f rotation_);
    void setScale(ofVec3f rotation_);
    void rotateX(float degrees);
    void rotateY(float degrees);
    void rotateZ(float degrees);
    void incrementRotateX(float amount);
    void incrementRotateY(float amount);
    void incrementRotateZ(float amount);
    void positionX(float positionX);
    void positionY(float positionY);
    void positionZ(float positionZ);
    void incrementPositionX(float amount);
    void incrementPositionY(float amount);
    void incrementPositionZ(float amount);
    void scaleX(float scaleX);
    void scaleY(float scaleY);
    void scaleZ(float scaleZ);
    void incrementScaleX(float amount);
    void incrementScaleY(float amount);
    void incrementScaleZ(float amount);

    vector <ofxShape*> getShapes();

private:
    vector <ofxShape*> shapes;
    ofVec3f position, rotation, scale;
};
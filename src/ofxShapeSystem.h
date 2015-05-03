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
    
private:
    vector < ofxShape* > shapes;
};
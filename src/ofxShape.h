#pragma once

//Adapted from:
//http://forum.openframeworks.cc/t/circles-with-holes-or-with-stroke/8173/6
//https://github.com/jasonmcdermott/ofxForums/tree/master/vertexArrayGradientShapes

#include "ofMain.h"
#include "ofxTransformable.h"

class ofxShape : public ofxTransformable {
    
public:
    enum FillType {
        FILL_TYPE_FILLED,
        FILL_TYPE_HOLLOW,
        FILL_TYPE_GRADIENT
    };

    float theta45Degrees = PI * 0.25;

    void setupFilledSquare(float sideLength);
    void setupHollowSquare(float borderWeight, float sideLength);
    void setupGradientSquare(float borderWeight, float sideLength);

    void setupFilledRing(int resolution, float diameter_);
    void setupHollowRing(int resolution, float thickness_, float diameter_);
    void setupGradientRing(int resolution, float thickness_, float diameter_);

    void setupFilledArc(int resolution, float diameter_, float degrees);
    void setupHollowArc(int resolution, float thickness_, float diameter_, float degrees);
    void setupGradientArc(int resolution, float thickness_, float diameter_, float degrees);

    void setup(int numSides_, float thickness_);
    void setup(int numSides_, float thickness_, float diameter_);
    void setup(FillType fillType_, int numSides_, float thickness_, float diameter_);
    void setup(FillType fillType_, int numSides_, float thickness_, float diameter_, ofColor color_);
    void setup(FillType fillType_, int numSides_, float blur_, float thickness_, float diameter_, ofColor color_);
    void setup(ofVec3f rotation_, FillType fillType_, int numSides_, float blur_, float thickness_, float diameter_, ofColor color_);

    void setFillType(FillType fillType_);
    void setNumSides(int numSides_);
    void setBlur(float blur_);
    void setThickness(float thickness_);
    void setDiameter(float diameter_);
    void setRadius(float radius_);
    void setArcEndpoints(float startDegrees, float endDegrees);
    void setColor(ofColor color_);
    void setOpacity(float opacity_);
    
    void correctRotation();
    FillType getFillType();
    int getNumSides();
    float getBlur();
    float getThickness();
    float getDiameter();
    float getRadius();
    ofColor getColor();

    void update();
    void draw();

private:
    void drawGradient(float opaqueVertexDistance, float opacityControlledVertexDistance, float opacityControl);
    float toRadians(float degrees);
    float toRadius(float squareSidelength);
    float toThickness(float squareBorderSize);

    ofVec3f position, rotation, scale;
    float arcEndpointA, arcEndpointB, middleRadius;
    ofFloatColor color;
    FillType fillType;
    bool correctRotation45;

    int numSides;
    float blur, thickness, halfThickness, diameter, radius;
};
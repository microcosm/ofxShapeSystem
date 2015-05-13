#include "ofxShape.h"

//Adapted from:
//http://forum.openframeworks.cc/t/circles-with-holes-or-with-stroke/8173/6
//https://github.com/jasonmcdermott/ofxForums/tree/master/vertexArrayGradientShapes

void ofxShape::setupFilledSquare(float sideLength) {
    setup(4, 0);
    setFillType(FILL_TYPE_FILLED);
    setRadius(toRadius(sideLength));
    correctRotation();
}

void ofxShape::setupHollowSquare(float borderWeight, float sideLength) {
    setup(4, toThickness(borderWeight));
    setFillType(FILL_TYPE_HOLLOW);
    setRadius(toRadius(sideLength));
    correctRotation();
}

void ofxShape::setupGradientSquare(float borderWeight, float sideLength) {
    setup(4, toThickness(borderWeight));
    setFillType(FILL_TYPE_GRADIENT);
    setRadius(toRadius(sideLength));
    correctRotation();
}

void ofxShape::setupFilledRing(int resolution, float diameter_) {
    setup(FILL_TYPE_FILLED, resolution, 0, diameter_);
}

void ofxShape::setupHollowRing(int resolution, float thickness_, float diameter_) {
    setup(FILL_TYPE_HOLLOW, resolution, thickness_, diameter_);
}

void ofxShape::setupGradientRing(int resolution, float thickness_, float diameter_) {
    setup(FILL_TYPE_GRADIENT, resolution, thickness_, diameter_);
}

void ofxShape::setupFilledArc(int resolution, float diameter_, float degrees) {
    setup(FILL_TYPE_FILLED, resolution, 0, diameter_);
    setArcEndpoints(0, degrees);
}

void ofxShape::setupHollowArc(int resolution, float thickness_, float diameter_, float degrees) {
    setup(FILL_TYPE_HOLLOW, resolution, thickness_, diameter_);
    setArcEndpoints(0, degrees);
}

void ofxShape::setupGradientArc(int resolution, float thickness_, float diameter_, float degrees) {
    setup(FILL_TYPE_GRADIENT, resolution, thickness_, diameter_);
    setArcEndpoints(0, degrees);
}

void ofxShape::setup(int numSides_, float thickness_) {
    float defaultDiameter = 10;
    setup(numSides_, thickness_, defaultDiameter);
}

void ofxShape::setup(int numSides_, float thickness_, float diameter_) {
    FillType defaultFillType = FILL_TYPE_FILLED;
    setup(defaultFillType, numSides_, thickness_, diameter_);
}

void ofxShape::setup(FillType fillType_, int numSides_, float thickness_, float diameter_) {
    ofColor defaultColor = ofColor::white;
    setup(fillType_, numSides_, thickness_, diameter_, defaultColor);
}

void ofxShape::setup(FillType fillType_, int numSides_, float thickness_, float diameter_, ofColor color_) {
    ofVec3f defaultCenter = ofVec3f(0, 0, 0);
    setup(defaultCenter, fillType_, numSides_, thickness_, diameter_, color_);
}

void ofxShape::setup(ofVec3f centre_, FillType fillType_, int numSides_, float thickness_, float diameter_, ofColor color_) {
    float defaultBlur = 0;
    setup(centre_, fillType_, numSides_, defaultBlur, thickness_, diameter_, color_);
}

void ofxShape::setup(ofVec3f centre_, FillType fillType_, int numSides_, float blur_, float thickness_, float diameter_, ofColor color_) {
    ofVec3f defaultRotation = ofVec3f(0, 0, 0);
    setup(centre_, defaultRotation, fillType_, numSides_, blur_, thickness_, diameter_, color_);
}

void ofxShape::setup(ofVec3f centre_, ofVec3f rotation_, FillType fillType_, int numSides_, float blur_, float thickness_, float diameter_, ofColor color_) {
    ofVec3f defaultScale = ofVec3f(1, 1, 1);

    origin.set(centre_);
    setPosition(centre_);
    setRotation(rotation_);
    setScale(defaultScale);
    setFillType(fillType_);
    setNumSides(numSides_);
    setBlur(blur_);
    setThickness(thickness_);
    setDiameter(diameter_);
    setColor(color_);
    arcEndpointA = 0;
    arcEndpointB = 2 * PI;
    correctRotation45 = false;
}

void ofxShape::setPosition(ofVec3f position_) {
    position.set(position_);
}

void ofxShape::setRotation(ofVec3f rotation_) {
    rotation.set(rotation_);
}

void ofxShape::setScale(ofVec3f scale_) {
    scale.set(scale_);
}

void ofxShape::setFillType(FillType fillType_) {
    fillType = fillType_;
}

void ofxShape::setNumSides(int numSides_) {
    numSides = numSides_;
}

void ofxShape::setBlur(float blur_) {
    blur = blur_;
}

void ofxShape::setThickness(float thickness_) {
    thickness = thickness_;
    halfThickness = thickness_ * 0.5;
}

void ofxShape::setDiameter(float diameter_) {
    diameter = diameter_;
    radius = diameter_ * 0.5;
}

void ofxShape::setRadius(float radius_) {
    radius = radius_;
    diameter = radius_ * 2;
}

void ofxShape::setArcEndpoints(float startDegrees, float endDegrees) {
    arcEndpointA = toRadians(startDegrees);
    arcEndpointB = toRadians(endDegrees);
}

void ofxShape::setColor(ofColor color_) {
    color.set(color_);
}

void ofxShape::setOpacity(float opacity_) {
    color.a = ofMap(opacity_, 0, 255, 0, 1);
}

void ofxShape::rotateX(float degrees) {
    rotation.x = degrees;
}

void ofxShape::rotateY(float degrees) {
    rotation.y = degrees;
}

void ofxShape::rotateZ(float degrees) {
    rotation.z = degrees;
}

void ofxShape::positionX(float positionX) {
    position.x = positionX;
}

void ofxShape::positionY(float positionY) {
    position.y = positionY;
}

void ofxShape::positionZ(float positionZ) {
    position.z = positionZ;
}

void ofxShape::scaleX(float scaleX) {
    scale.x = scaleX;
}

void ofxShape::scaleY(float scaleY) {
    scale.y = scaleY;
}

void ofxShape::scaleZ(float scaleZ) {
    scale.z = scaleZ;
}

void ofxShape::correctRotation() {
    correctRotation45 = true;
}

ofVec3f ofxShape::getPosition() {
    return position;
}

ofVec2f ofxShape::getPositionXY() {
    return ofVec2f(position.x, position.y);
}

float ofxShape::getDiameter() {
    return diameter;
}

void ofxShape::update() {
    
}

void ofxShape::draw() {
    if (fillType == FILL_TYPE_FILLED) {
        drawGradient(radius - blur, 0,             color.a);  //Draw fully opaque
        drawGradient(radius,        radius - blur, 0);        //Draw blur
    } else if (fillType == FILL_TYPE_HOLLOW) {
        drawGradient(radius + halfThickness - blur, radius - halfThickness + blur, color.a); //Draw fully opaque
        drawGradient(radius + halfThickness,        radius + halfThickness - blur, 0);       //Draw outer blur
        drawGradient(radius - halfThickness,        radius - halfThickness + blur, 0);       //Draw inner blur
    } else if (fillType == FILL_TYPE_GRADIENT) {
        drawGradient(radius - halfThickness,                        radius + halfThickness, 0);  //Draw the gradient
        drawGradient(radius + halfThickness + halfThickness * 0.05, radius + halfThickness, 0);  //Hack definition via outer line
    }
}

void ofxShape::drawGradient(float opaqueVertexDistance, float opacityControlledVertexDistance, float opacityControl) {

    ofPushMatrix();
    ofTranslate(position.x, position.y, position.z);
    ofRotateX(rotation.x);
    ofRotateY(rotation.y);
    ofRotateZ(rotation.z);
    ofScale(scale.x, scale.y, scale.z);
    if(correctRotation45) ofRotateZ(45);

    int numCoordPairs = numSides + 1;
    GLfloat* ver_coords = new GLfloat[numCoordPairs * 4];
    GLfloat* ver_cols = new GLfloat[numCoordPairs * 8];

    float angle;
    float angleSize = (arcEndpointB - arcEndpointA) / numSides;

    for (int i = 0; i < numCoordPairs; i++) {
        angle = i * angleSize;
        angle += arcEndpointA;

        ver_coords[i*4+0] = (opaqueVertexDistance * cos(angle));
        ver_coords[i*4+1] = (opaqueVertexDistance * sin(angle));
        ver_cols[i*8+0] = color.r;
        ver_cols[i*8+1] = color.g;
        ver_cols[i*8+2] = color.b;
        ver_cols[i*8+3] = opacityControl;

        ver_coords[i*4+2] = (opacityControlledVertexDistance * cos(angle));
        ver_coords[i*4+3] = (opacityControlledVertexDistance * sin(angle));
        ver_cols[i*8+4] = color.r;
        ver_cols[i*8+5] = color.g;
        ver_cols[i*8+6] = color.b;
        ver_cols[i*8+7] = color.a;
    }

    glVertexPointer(2, GL_FLOAT, 0, ver_coords);
    glColorPointer(4, GL_FLOAT, 0, ver_cols);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, numCoordPairs * 2);

    delete[] ver_coords;
    delete[] ver_cols;
    ofPopMatrix();
}

float ofxShape::toRadians(float degrees) {
    return ofMap(degrees, 0, 360, 0, PI * 2);
}

//These methods convert desired humanly-understandable values in relation to a square
//and return the values needed by the 2D regular polygon drawing system
float ofxShape::toRadius(float squareSidelength) {
    return squareSidelength * cos(theta45Degrees);
}

float ofxShape::toThickness(float squareBorderSize) {
    float currentSquareThickness = squareBorderSize * cos(theta45Degrees);
    return ofMap(squareBorderSize, 0, currentSquareThickness, 0, squareBorderSize);
}
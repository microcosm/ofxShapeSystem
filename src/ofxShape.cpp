#include "ofxShape.h"

//Adapted from:
//http://forum.openframeworks.cc/t/circles-with-holes-or-with-stroke/8173/6
//https://github.com/jasonmcdermott/ofxForums/tree/master/vertexArrayGradientShapes

void ofxShape::setupFilledSquare(float diameter_) {
    setup(FILL_TYPE_FILLED, 4, 0, diameter_);
    correctRotation();
}

void ofxShape::setupHollowSquare(float thickness_, float diameter_) {
    setup(FILL_TYPE_HOLLOW, 4, thickness_, diameter_);
    correctRotation();
}

void ofxShape::setupGradientSquare(float thickness_, float diameter_) {
    setup(FILL_TYPE_GRADIENT, 4, thickness_, diameter_);
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
}

void ofxShape::setDiameter(float diameter_) {
    diameter = diameter_;
}

void ofxShape::setArcEndpoints(float startDegrees, float endDegrees) {
    arcEndpointA = toRadians(startDegrees);
    arcEndpointB = toRadians(endDegrees);
}

void ofxShape::setColor(ofColor color_) {
    color.set(color_);
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
        drawGradient(diameter - blur, 0,               color.a);
        drawGradient(diameter,        diameter - blur, 0);
    } else if (fillType == FILL_TYPE_HOLLOW) {
        drawGradient(diameter + thickness - blur, diameter - thickness + blur, color.a);
        drawGradient(diameter + thickness,        diameter + thickness - blur, 0);
        drawGradient(diameter - thickness,        diameter - thickness + blur, 0);
    } else if (fillType == FILL_TYPE_GRADIENT) {
        drawGradient(diameter - thickness,                    diameter + thickness, 0);
        drawGradient(diameter + thickness + thickness * 0.05, diameter + thickness, 0);
    }
}

void ofxShape::drawGradient(float opaque_, float transp_, float opac_) {

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
    //float angleSize = PI*2/numSides;
    float angleSize = (arcEndpointB - arcEndpointA) / numSides;

    for (int i = 0; i < numCoordPairs; i++) {
        angle = i * angleSize;
        angle += arcEndpointA; //Added this

        ver_coords[i*4+0] = (opaque_ * cos(angle));
        ver_coords[i*4+1] = (opaque_ * sin(angle));
        ver_cols[i*8+0] = color.r;
        ver_cols[i*8+1] = color.g;
        ver_cols[i*8+2] = color.b;
        ver_cols[i*8+3] = opac_;

        ver_coords[i*4+2] = (transp_ * cos(angle));
        ver_coords[i*4+3] = (transp_ * sin(angle));
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
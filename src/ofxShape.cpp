#include "ofxShape.h"

//Adapted from:
//http://forum.openframeworks.cc/t/circles-with-holes-or-with-stroke/8173/6
//https://github.com/jasonmcdermott/ofxForums/tree/master/vertexArrayGradientShapes

void ofxShape::setupFilledSquare(float diameter_) {
    setup(FILL_TYPE_FILLED, 4, 0, diameter_);
    rotateZ(45);
}

void ofxShape::setupHollowSquare(float thickness_, float diameter_) {
    setup(FILL_TYPE_HOLLOW, 4, thickness_, diameter_);
    rotateZ(45);
}

void ofxShape::setupGradientSquare(float thickness_, float diameter_) {
    setup(FILL_TYPE_GRADIENT, 4, thickness_, diameter_);
    rotateZ(45);
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
    origin.set(centre_);
    setPosition(centre_);
    setFillType(fillType_);
    setNumSides(numSides_);
    setBlur(blur_);
    setThickness(thickness_);
    setDiameter(diameter_);
    setColor(color_);
    setRotation(rotation_);
    arcEndpointA = 0;
    arcEndpointB = 2 * PI;
}

void ofxShape::setPosition(ofVec3f position_) {
    position.set(position_);
}

void ofxShape::setRotation(ofVec3f rotation_) {
    rotation.set(rotation_);
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
        drawGradient(diameter - blur, 0,               color.a, 0, numSides);
        drawGradient(diameter,        diameter - blur, 0,       0, numSides);
    } else if (fillType == FILL_TYPE_HOLLOW) {
        drawGradient(diameter + thickness - blur, diameter - thickness + blur, color.a, 0, numSides);
        drawGradient(diameter + thickness,        diameter + thickness - blur, 0,       0, numSides);
        drawGradient(diameter - thickness,        diameter - thickness + blur, 0,       0, numSides);
    } else if (fillType == FILL_TYPE_GRADIENT) {
        drawGradient(diameter - thickness,                    diameter + thickness, 0, 0, numSides);
        drawGradient(diameter + thickness + thickness * 0.05, diameter + thickness, 0, 0, numSides);
    }
}

void ofxShape::drawGradient(float opaque_, float transp_, float opac_, float blur_, int numSides_) {
    
    ofPushMatrix();
    ofTranslate(position.x, position.y, position.z);
    ofRotateX(rotation.x);
    ofRotateY(rotation.y);
    ofRotateZ(rotation.z);
    
    GLfloat* ver_coords = new GLfloat[ (numSides_+1) * 4];
    GLfloat* ver_cols = new GLfloat[ (numSides_+1) * 8];
    
    float angle;
    //float angleSize = PI*2/numSides_;
    float angleSize = (arcEndpointB-arcEndpointA)/numSides_;
    
    if (opaque_ < transp_) {
        middleRadius = opaque_ - ((transp_-opaque_)+blur_);
    } else {
        middleRadius = opaque_ - ((transp_-opaque_)+blur_);
    }
    
    middleRadius = (opaque_ + transp_)/2;
    
    for (int i=0; i< (1+numSides_); i++) {
        angle = i * angleSize;
        angle += arcEndpointA; //Added this
        ver_coords[i*4+0] = (opaque_*cos(angle));
        ver_coords[i*4+1] = (opaque_*sin(angle));
        ver_cols[i*8+0] = color.r;
        ver_cols[i*8+1] = color.g;
        ver_cols[i*8+2] = color.b;
        ver_cols[i*8+3] = opac_;
        ver_coords[i*4+2] = (transp_*cos(angle));
        ver_coords[i*4+3] = (transp_*sin(angle));
        ver_cols[i*8+4] = color.r;
        ver_cols[i*8+5] = color.g;
        ver_cols[i*8+6] = color.b;
        ver_cols[i*8+7] = color.a;
    }
    
    
    glVertexPointer( 2, GL_FLOAT, 0, ver_coords);
    glColorPointer(4, GL_FLOAT, 0, ver_cols);
    glDrawArrays( GL_TRIANGLE_STRIP, 0, ( numSides_ + 1 ) * 2 );
    
    delete[] ver_coords;
    delete[] ver_cols;
    ofPopMatrix();
}

float ofxShape::toRadians(float degrees) {
    return ofMap(degrees, 0, 360, 0, PI * 2);
}
#include "ofxShapeSystem.h"

//Adapted from:
//http://forum.openframeworks.cc/t/circles-with-holes-or-with-stroke/8173/6
//https://github.com/jasonmcdermott/ofxForums/tree/master/vertexArrayGradientShapes

void ofxShapeSystem::setup() {
    ofxTransformable::setup();
}

void ofxShapeSystem::setupCube(float sideLength) {
    setup();

    float halfSideLength = sideLength * 0.5;
    builder.clear();
    shape.setupFilledSquare(sideLength);

    shape.rotateX(90);
    shape.positionY(-halfSideLength);
    builder.push_back(shape);
    shape.positionY(halfSideLength);
    builder.push_back(shape);

    shape.rotateX(0);
    shape.positionY(0);

    shape.rotateY(90);
    shape.positionX(halfSideLength);
    builder.push_back(shape);
    shape.positionX(-halfSideLength);
    builder.push_back(shape);

    shape.rotateY(0);
    shape.positionX(0);

    shape.positionZ(halfSideLength);
    builder.push_back(shape);
    shape.positionZ(-halfSideLength);
    builder.push_back(shape);

    add(builder);
}

void ofxShapeSystem::add(ofxShape &shape) {
    shapes.push_back(&shape);
}

void ofxShapeSystem::add(vector<ofxShape> &_shapes) {
    for(int i = 0; i < _shapes.size(); i++) {
        add(_shapes.at(i));
    }
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
    applyTransformations();
    for(int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
    ofPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

vector <ofxShape*> ofxShapeSystem::getShapes() {
    return shapes;
}
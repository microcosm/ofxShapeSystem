#include "ofxShapeSystem.h"

//Adapted from:
//http://forum.openframeworks.cc/t/circles-with-holes-or-with-stroke/8173/6
//https://github.com/jasonmcdermott/ofxForums/tree/master/vertexArrayGradientShapes

void ofxShapeSystem::setup() {
    ofxTransformable::setup();
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
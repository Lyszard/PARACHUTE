#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	
	lines.push_back(new Spring(600, 400, 100, 200));
	attractor = new Attractor(ofVec3f(800, 900, 0),300000);
}

//--------------------------------------------------------------
void ofApp::update(){	
	
	for (int i = 0; i < lines.size(); i++)
	{
		for(int j = 0; j<lines[i]->getPoints().size(); j++)
			lines[i]->update(attractor);

	}
	double timer = ofGetElapsedTimef();
	if (timer > 0.5)
	{
		double temp = ofRandom(200000, 400000);
		attractor->setMass(temp);
		ofResetElapsedTimeCounter();
	}
	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	for (int i = 0; i < lines.size(); i++)
		lines[i]->draw();
	attractor->draw();
	ofLine(lines[0]->getPoints()[0]->getPosition()[0],lines[0]->getPoints()[0]->getPosition()[1], attractor->getPos()[0],attractor->getPos()[1]);
	ofLine(lines[0]->getPoints()[lines[0]->getPoints().size()-1]->getPosition()[0], lines[0]->getPoints()[lines[0]->getPoints().size() - 1]->getPosition()[1], attractor->getPos()[0], attractor->getPos()[1]);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
	//attractor->setG();
	

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

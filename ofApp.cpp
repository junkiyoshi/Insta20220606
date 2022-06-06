#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
	ofSetColor(0);
	ofFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	int radius = 720;
	for (int deg = 0; deg < 360; deg += 2) {

		auto start = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		auto noise_value = ofNoise(glm::vec3(start * 0.02, ofGetFrameNum() * 0.005));
		auto end_radius = ofMap(noise_value, 0, 1, 0, radius);
		auto end = glm::vec2(end_radius * cos(deg * DEG_TO_RAD), end_radius * sin(deg * DEG_TO_RAD));

		ofDrawLine(start, end);
		ofDrawCircle(end, 3);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
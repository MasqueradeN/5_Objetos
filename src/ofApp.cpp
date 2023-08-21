#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	posX = 50;
	posY = 0;
	radioCirculo = 20;

	Entity e = Entity();
	e.posx = 100;
	e.posy = 20;
	gameObjects.push_back(e);

	Entity e2 = Entity();
	e2.posx = 130;
	e2.posy = 20;
	gameObjects.push_back(e2);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (gameObjects.size() > 0)
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i].posx += 1 * ofGetLastFrameTime();
			gameObjects[i].posy += 9.81 * ofGetLastFrameTime();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::cornflowerBlue);
	ofSetColor(152,52,152);
	ofCircle(posX, posY, radioCirculo);

	if (gameObjects.size() > 0)
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i].draw();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	//posX = x;
	//posY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

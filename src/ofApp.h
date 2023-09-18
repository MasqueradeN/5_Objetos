#pragma once

#include "ofMain.h"
#include <vector>
#include <list>
#include "Entity.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void setupBalls();
		void setupLemmin();
		void update();
		void updateBalls();
		void updateLemmin();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		float posX;
		float posY;

		float radioCirculo;
		float poisonPosX, poisonPosY;

		std::vector<Entity> gameObjects;
		std::vector<Entity> items;

		void onBtn1Pressed();
		void onBtn2Pressed();

		enum EAppState
		{
			menu, balls, lemin
		} appstate;

		ofxPanel mainMenu;
		ofxButton btnEjercicio1, btnEjercicio2;
		ofImage playerSprite;
		ofImage poissonGrab, swordGrab, shieldGrab;
		ofImage backGround;
		ofVec2f playerSize;
		ofVec2f playerSpriteOffset;
		ofTrueTypeFont titleFont;
		ofTrueTypeFont uiFont;

		std::vector<ofColor> colors;
		ofColor trasnparent;

		bool w, a, s, d, poisonHand;

		std::list<Entity> inventory;
		Entity* currItem;

		void NextItem();
		void PrevItem();
		std::list<Entity>::iterator invIterator;
};

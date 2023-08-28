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

		std::vector<Entity> gameObjects;

		void onBtn1Pressed();
		void onBtn2Pressed();

		enum EAppState
		{
			menu, balls, lemin, max
		} appstate;

		ofxPanel mainMenu;
		ofxButton btnEjercicio1, btnEjercicio2;
		ofImage playerSprite;
		ofVec2f playerSize;
		ofVec2f playerSpriteOffset;

		bool w, a, s, d;

		std::list<Entity> inventory;
		Entity* currItem;
};

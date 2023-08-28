#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	appstate = EAppState::menu;

	mainMenu.setup();
	mainMenu.add(btnEjercicio1.setup("Balls Gaming"));
	mainMenu.add(btnEjercicio2.setup("Lemmings, oh no"));
	mainMenu.setPosition(ofGetWidth() / 2 - mainMenu.getWidth() / 2, ofGetHeight() / 2 - mainMenu.getHeight() / 2);

	btnEjercicio1.addListener(this, &ofApp::onBtn1Pressed);
	btnEjercicio2.addListener(this, &ofApp::onBtn2Pressed);
}

void ofApp::setupBalls()
{
	Entity e = Entity();
	e.posx = 100;
	e.posy = 0;
	gameObjects.push_back(e);

	Entity e2 = Entity();
	e2.posx = 130;
	e2.posy = 20;
	gameObjects.push_back(e2);
}

void ofApp::setupLemmin()
{
	posX = 50;
	posY = 0;
	radioCirculo = 20;
	playerSprite.load("ese mi sprite.png");
	playerSize = ofVec2f(26, 48);
	playerSpriteOffset = ofVec2f(12, 0);
	Entity hands = Entity();
	hands.name = "Ojito mano, mano";
	inventory.push_back(hands);
	currItem = &hands;
	Entity spada = Entity();
	spada.name = "La Swor";
	inventory.push_back(spada);
	Entity escudo = Entity();
	escudo.name = "Le Shild";
	inventory.push_back(escudo);
	currItem = &hands;
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (appstate == EAppState::balls)
	{
		updateBalls();
	}
	else if (appstate == EAppState::menu)
	{
		
	}
	else if (appstate == EAppState::lemin)
	{
		updateLemmin();
	}
}

void ofApp::updateBalls()
{
	if (gameObjects.size() > 0)
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i].velocity->y += 180 * ofGetLastFrameTime();

			if (gameObjects[i].posy >= ofGetHeight())
			{
				gameObjects[i].posy = ofGetHeight();
				gameObjects[i].velocity->y *= -0.9;
			}

			gameObjects[i].posx += 1 * ofGetLastFrameTime();
			gameObjects[i].posy += gameObjects[i].velocity->y * ofGetLastFrameTime();
		}
	}
}

void ofApp::updateLemmin()
{
	if (w)
	{
		posY -= 100 * ofGetLastFrameTime();
		playerSpriteOffset = ofVec2f(12, 0);
	}
	if (a)
	{
		posX -= 100 * ofGetLastFrameTime();
		playerSpriteOffset = ofVec2f(61, 0);
	}
	if (s)
	{
		posY += 100 * ofGetLastFrameTime();
	}
	if (d)
	{
		posX += 100 * ofGetLastFrameTime();
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (appstate == EAppState::balls)
	{
		ofBackground(ofColor::cornflowerBlue);
		mainMenu.draw();

		if (gameObjects.size() > 0)
		{
			for (int i = 0; i < gameObjects.size(); i++)
			{
				gameObjects[i].draw();
			}
		}
	}
	else if (appstate == EAppState::menu)
	{
		ofBackground(ofColor::darkGray);
		mainMenu.draw();
	}
	else if (appstate == EAppState::lemin)
	{
		ofBackground(ofColor::lawnGreen);
		//ofDrawCircle(posX, posY, radioCirculo);
		//ofSetColor(152, 52, 152);
		mainMenu.draw();
		playerSprite.drawSubsection(posX, posY, playerSize.x, playerSize.y, playerSpriteOffset.x, playerSpriteOffset.y);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'w')
	{
		w = true;
	}
	if (key == 'a')
	{
		a = true;
	}
	if (key == 's')
	{
		s = true;
	}
	if (key == 'd')
	{
		d = true;
	}

	if (appstate == EAppState::lemin)
	{
		if (key == 57357)
		{

		}
		if (key == 57359)
		{

		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (key == 'w')
	{
		w = false;
	}
	if (key == 'a')
	{
		a = false;
	}
	if (key == 's')
	{
		s = false;
	}
	if (key == 'd')
	{
		d = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
	//posX = x;
	//posY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	Entity e = Entity();
	e.posx = x;
	e.posy = y;
	gameObjects.push_back(e);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

void ofApp::onBtn1Pressed()
{
	std::cout << "Balls Gaming Beibiiiii\n";
	appstate = EAppState::balls;
	setupBalls();
}

void ofApp::onBtn2Pressed()
{
	std::cout << "Mequierodaruntiroaaaa Lemmings\n";
	appstate = EAppState::lemin;
	setupLemmin();
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{ 

}

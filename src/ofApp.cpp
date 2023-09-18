#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	appstate = EAppState::menu;

	titleFont.load("Pinus.otf", 24);
	uiFont.load("Pinus.otf", 12);

	mainMenu.setup();
	mainMenu.add(btnEjercicio1.setup("Balls Gaming"));
	mainMenu.add(btnEjercicio2.setup("Lemmings, oh no"));
	mainMenu.setPosition(ofGetWidth() / 2 - mainMenu.getWidth() / 2, ofGetHeight() / 2 - mainMenu.getHeight() / 2);

	btnEjercicio1.addListener(this, &ofApp::onBtn1Pressed);
	btnEjercicio2.addListener(this, &ofApp::onBtn2Pressed);
	ofDrawCircle(posX, posY, radioCirculo);
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

	backGround.load("hi-mods-and-staff-ily.gif");
}

void ofApp::setupLemmin()
{
	posX = 50;
	posY = 0;
	radioCirculo = 20;
	trasnparent = ofColor(0, 0, 0);
	playerSprite.load("ese mi sprite.png");
	poissonGrab.load("Le poisson.jpg");
	playerSize = ofVec2f(26, 48);
	playerSpriteOffset = ofVec2f(12, 0);
	Entity hands = Entity();
	hands.name = "Ojito mano, mano";
	inventory.push_back(hands);
	//currItem = &hands;
	Entity spada = Entity();
	spada.name = "La Swor";
	inventory.push_back(spada);
	Entity escudo = Entity();
	escudo.name = "Le Shild";
	inventory.push_back(escudo);

	//currItem = &inventory.front();
	invIterator = inventory.begin();
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

	poisonPosX = posX;
	poisonPosY = posY;
	poisonPosX -= 100 * ofGetLastFrameTime();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (appstate == EAppState::balls)
	{
		ofBackground(ofColor::cornflowerBlue);
		mainMenu.draw();
		backGround.draw(200, ofGetHeight() - backGround.getHeight());

		if (gameObjects.size() > 0)
		{
			for (int i = 0; i < gameObjects.size(); i++)
			{
				gameObjects[i].draw();
				colors.push_back(ofColor(ofRandom(0, 255),
					ofRandom(0, 255),
					ofRandom(0, 255)
				));
				gameObjects[i].setColor(colors[i]);
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
		ofBackground(ofColor::blueViolet);
		mainMenu.draw();
		playerSprite.drawSubsection(posX, posY, playerSize.x, playerSize.y, playerSpriteOffset.x, playerSpriteOffset.y);
		titleFont.drawString("Oh my days xd", 300, 50);
		//uiFont.drawString(currItem == nullptr ? "NULL" : currItem->name.c_str(), posX, posY);
		uiFont.drawString((*invIterator).name.c_str(), posX, posY);

		if (poisonHand && invIterator == --inventory.end())
		{
			poissonGrab.draw(posX - 10, posY + 10);
		}

		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i].draw();
		}

		Entity ufs = Entity();
		ufs.posx = rand() % (ofGetWidth() - 100) + 50;
		ufs.posy = rand() % (ofGetHeight() - 100) + 50;
		items.push_back(ufs);
		

		if (items.size() > 0)
		{
			Entity bruh = Entity();
			srand(time(NULL));
			bruh.posx = rand() % (ofGetWidth() - 100) + 50;
			bruh.posy = rand() % (ofGetHeight() - 100) + 50;
			bruh.name = "le poison";
			items.push_back(bruh);
			for (int i = 0; i < items.size(); i++)
			{
				items[i].setSprite("Le poisson.jpg");
				items[i].entitySprite.draw(items[i].posx, items[i].posy);
				items[i].setColor(ofColor::white);
				float treshHold = 30;
				if (poisonHand == false)
				{
					if (posX + treshHold > items[i].posx && posX + treshHold < items[i].posx + treshHold && posY + treshHold > items[i].posy && posY - treshHold < items[i].posy + treshHold)//|| posX <= items[i].posx && posY <= items[i].posy)
					{
						items.erase(items.begin() + i);
						inventory.push_back(bruh);
						poisonHand = true;
					}
					if (posX - treshHold < items[i].posx + treshHold && posX - treshHold > items[i].posx - treshHold && posY + treshHold > items[i].posy && posY - treshHold < items[i].posy + treshHold)
					{
						items.erase(items.begin() + i);
						inventory.push_back(bruh);
						poisonHand = true;
					}
					if (posY + treshHold > items[i].posy && posY + treshHold < items[i].posy + treshHold && posX + treshHold > items[i].posx && posX - treshHold < items[i].posy + treshHold)
					{
						items.erase(items.begin() + i);
						inventory.push_back(bruh);
						poisonHand = true;
					}
					if (posY - treshHold < items[i].posy && posY - treshHold > items[i].posy && posX + treshHold > items[i].posx && posX - treshHold < items[i].posy + treshHold)
					{
						items.erase(items.begin() + i);
						inventory.push_back(bruh);
						poisonHand = true;
					}
				}
			}
		}
	}
}

void ofApp::NextItem()
{
	++invIterator;
	if (invIterator == inventory.end())
	{
		invIterator = inventory.begin();
	}
	//*currItem = *invIterator;
}

void ofApp::PrevItem()
{
	if (invIterator == inventory.begin())
	{
		invIterator = inventory.end();
		--invIterator;
	}
	else
	{
		--invIterator;
	}
	//*currItem = *invIterator;
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
			PrevItem();
		}
		if (key == 57359)
		{
			NextItem();
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
	if (appstate == EAppState::balls)
	{
		posX = x;
		posY = y;
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (appstate == EAppState::balls)
	{
		Entity e = Entity();
		e.posx = x;
		e.posy = y;
		gameObjects.push_back(e);
	}
	else if (appstate == EAppState::lemin)
	{
		if (poisonHand == true && invIterator == --inventory.end())
		{
			Entity e = Entity();
			e.posx = poisonPosX;
			e.posy = poisonPosY;
			e.setColor(ofColor::green);
			gameObjects.push_back(e);
			poisonPosX = posX;
			--invIterator;
			inventory.pop_back();
			poisonHand = false;
		}
	}
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

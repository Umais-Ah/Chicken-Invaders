#include<iostream>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Chickens.h"
#include "BalloonChicken.h"
#include "BossChicken.h"
#include "RedChicken.h"
#include "FrozenChicken.h"
#include "SpaceshipChicken.h"
#include "GunChicken.h"
bool isPaused = false;
bool hadFocus = true;


int main(){
	bool l1=false,l2=false,l3=false;
	
	sf::RenderWindow window(sf::VideoMode(1067,600), "Chicken Invaders",sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(350);


	sf::SoundBuffer mainThemeBuffer, gameOverBuffer, stageClearBuffer,BossThemeBuffer,level1ThemeBuffer,level2ThemeBuffer;
    if (!mainThemeBuffer.loadFromFile("Sounds/Maintheme.ogg") || 
        !gameOverBuffer.loadFromFile("Sounds/GameOver.ogg") || 
        !stageClearBuffer.loadFromFile("Sounds/StageClear.ogg") ||
		!BossThemeBuffer.loadFromFile("Sounds/BossTheme.ogg") ||
	    !level1ThemeBuffer.loadFromFile("Sounds/lvl1Theme.ogg") ||
	    !level2ThemeBuffer.loadFromFile("Sounds/lvl2Theme.ogg")) {
        return -1; // Error loading sound files
    }

    sf::Sound mainTheme, gameOverSound, stageClearSound,bossThemeSound,level1ThemeSound,level2ThemeSound;
    mainTheme.setBuffer(mainThemeBuffer);
    gameOverSound.setBuffer(gameOverBuffer);
    stageClearSound.setBuffer(stageClearBuffer);
	bossThemeSound.setBuffer(BossThemeBuffer);
	level1ThemeSound.setBuffer(level1ThemeBuffer);
	level2ThemeSound.setBuffer(level2ThemeBuffer);
    level1ThemeSound.setLoop(true);
	level1ThemeSound.setVolume(60);
	level2ThemeSound.setLoop(true);
	level2ThemeSound.setVolume(60);  
	bossThemeSound.setLoop(true);
	bossThemeSound.setVolume(75);

    // Set main theme to loop and play it
    mainTheme.setLoop(true);
    mainTheme.play();


	 sf::Texture background1;
     background1.loadFromFile("images/levelCleared.png");
     sf::Sprite levelCleared;
     levelCleared.setTexture(background1);

	 sf::Texture background2;
     background2.loadFromFile("images/gameOver.png");
     sf::Sprite gameOver;
     gameOver.setTexture(background2);

	 bool ballonMove=true;
	 
	 sf::Texture level;
     level.loadFromFile("images/levelselect.png");
     sf::Sprite levelsprite;
	 levelsprite.setTexture(level);

	 sf::Texture skinsSelect;
	 skinsSelect.loadFromFile("images/skinSelect.png");

	 sf::Sprite skinsSelectsprite;
	 skinsSelectsprite.setTexture(skinsSelect);

	  sf::Texture mainbackground;
     mainbackground.loadFromFile("images/mainBackground.png");
     sf::Sprite homescreen;
	 while(window.isOpen()){
		 sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type)
			{
			case sf::Event::Closed:
			 mainTheme.stop();
				window.close();
				break;
			}
		}
     homescreen.setTexture(mainbackground);
	
	 while(true){
		window.clear();
	   window.draw(homescreen);
	window.display();
	 sf::Event evnt;
	 while (window.pollEvent(evnt)) {
	   switch (evnt.type) {
		   case sf::Event::Closed:
			   mainTheme.stop();
			   window.close();
			   break;
		   case sf::Event::LostFocus:
			   isPaused = true;
			   mainTheme.pause();
			   break;
		   case sf::Event::GainedFocus:
			   isPaused = false;
			   mainTheme.play();
			   break;
		   case sf::Event::KeyPressed:
			   if (evnt.key.code == sf::Keyboard::Escape) {
				   mainTheme.stop();
				   window.close();
			   }
			   break;
	   }
   }

	// This is your existing level selection code
while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){};
window.clear();
window.draw(levelsprite);
window.display();
while(true){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)){ l1=true;break; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)){ l2=true;break; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)){ l3=true;break; }
}

sf::sleep(sf::milliseconds(300)); 

int skinSelected = 1; // Default skin
window.clear();
window.draw(skinsSelectsprite);
window.display();
while(true) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) { skinSelected=1; break; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) { skinSelected=2; break; }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) { skinSelected=3; break; }
    
    // Small delay to prevent CPU overuse
    sf::sleep(sf::milliseconds(10));
}

//	LEVEL : 1
	 if(l1){
		level1ThemeSound.play();
		mainTheme.stop();
	 sf::Texture background;
     background.loadFromFile("images/background1.jpg");
     sf::Sprite sprite;
     sprite.setTexture(background);
	
	RedChicken redchicken1( 237.0,200.0,sf ::Vector2i(3, 1), 0.05f);
	RedChicken redchicken2( 337.0,200.0,sf ::Vector2i(3, 1), 0.05f);
	RedChicken redchicken3( 437.0,100.0,sf ::Vector2i(3, 1), 0.05f);
	RedChicken redchicken4( 537.0,100.0,sf ::Vector2i(3, 1), 0.05f);
	RedChicken redchicken5( 637.0,200.0,sf ::Vector2i(3, 1), 0.05f);
	RedChicken redchicken6( 737.0,200.0,sf ::Vector2i(3, 1), 0.05f);

	Egg	egg01(redchicken1.chickenX,redchicken1.chickenY,0.9,0.7);
	Egg	egg02(redchicken2.chickenX,redchicken2.chickenY,0.9,0.7);
	Egg	egg03(redchicken3.chickenX,redchicken3.chickenY,0.9,0.7);
	Egg	egg04(redchicken4.chickenX,redchicken4.chickenY,0.9,0.7);
	Egg	egg05(redchicken5.chickenX,redchicken5.chickenY,0.9,0.7);
	Egg	egg06(redchicken6.chickenX,redchicken6.chickenY,0.9,0.7);

	ballonMove=true;
	BalloonChicken balloonchicken1;
	Egg balloonchickenegg(balloonchicken1.chickenX,balloonchicken1.chickenY,0.9,0.4);

	Player player(skinSelected); 

	bool oppose = false;
	float deltaTime = 0.0f;
	sf::Clock clock;

	while(window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			level1ThemeSound.stop();
			Chickens::numOfChick = 0;  
			mainTheme.play();		
			  break; }
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
				case sf::Event::Closed:
				    level1ThemeSound.stop();
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (evnt.key.code == sf::Keyboard::Escape) {
						level1ThemeSound.stop();
						window.close(); // Exit game on Escape
					}
					break;
			}
		}
		window.clear();
		window.draw(sprite);

		player.movement();
		player.beamShoot();

		if(redchicken1.health>0.0){
			redchicken1.Update(0, deltaTime, oppose);
			redchicken1.chicken.setTextureRect(redchicken1.uvRect);

			egg01.eggDrop(redchicken1.chickenX,redchicken1.chickenY);
			egg01.egg_respwan=player.eggStrike(egg01.eggX,egg01.eggY,redchicken1.damage);		
			redchicken1.movement();
			window.draw(egg01.egg);
			window.draw(redchicken1.chicken);

			if(redchicken1.health==1) redchicken1.health--,
				redchicken1.chickenX=-1,redchicken1.chickenY=-1,Chickens :: numOfChick--;
		}

		if(redchicken2.health>0.0){
			redchicken2.Update(0, deltaTime, oppose);
			redchicken2.chicken.setTextureRect(redchicken2.uvRect);
			
			egg02.eggDrop(redchicken2.chickenX,redchicken2.chickenY);
			egg02.egg_respwan=player.eggStrike(egg02.eggX,egg02.eggY,redchicken2.damage);
			redchicken2.movement();
			window.draw(egg02.egg);
			window.draw(redchicken2.chicken);

			if(redchicken2.health==1) redchicken2.health--,
				redchicken2.chickenX=-1,redchicken2.chickenY=-1,Chickens :: numOfChick--;
		}

		if(redchicken3.health>0.0){
			redchicken3.Update(0, deltaTime, oppose);
			redchicken3.chicken.setTextureRect(redchicken3.uvRect);
			
			egg03.eggDrop(redchicken3.chickenX,redchicken3.chickenY);
			egg03.egg_respwan=player.eggStrike(egg03.eggX,egg03.eggY,redchicken3.damage);
			redchicken3.movement();
			window.draw(egg03.egg);
			window.draw(redchicken3.chicken);

			if(redchicken3.health==1) redchicken3.health--,
				redchicken3.chickenX=-1,redchicken3.chickenY=-1,Chickens :: numOfChick--;
		}

		if(redchicken4.health>0.0){
			redchicken4.Update(0, deltaTime, oppose);
			redchicken4.chicken.setTextureRect(redchicken4.uvRect);
			
			egg04.eggDrop(redchicken4.chickenX,redchicken4.chickenY);
			egg04.egg_respwan=player.eggStrike(egg04.eggX,egg04.eggY,redchicken4.damage);
			redchicken4.movement();
			window.draw(egg04.egg);
			window.draw(redchicken4.chicken);

			if(redchicken4.health==1) redchicken4.health--,
				redchicken4.chickenX=-1,redchicken4.chickenY=-1,Chickens :: numOfChick--;
		}

		if(redchicken5.health>0.0){
			redchicken5.Update(0, deltaTime, oppose);
			redchicken5.chicken.setTextureRect(redchicken5.uvRect);
		
			egg05.eggDrop(redchicken5.chickenX,redchicken5.chickenY);
			egg05.egg_respwan=player.eggStrike(egg05.eggX,egg05.eggY,redchicken5.damage);
			redchicken5.movement();
			window.draw(egg05.egg);
			window.draw(redchicken5.chicken);

			if(redchicken5.health==1) redchicken5.health--,
				redchicken5.chickenX=-1,redchicken5.chickenY=-1,Chickens :: numOfChick--;
		}

		
		oppose = redchicken6.Update(0, deltaTime, oppose);

		if(redchicken6.health>0.0){
			
			redchicken6.chicken.setTextureRect(redchicken6.uvRect);
		
			egg06.eggDrop(redchicken6.chickenX,redchicken6.chickenY);
			egg06.egg_respwan=player.eggStrike(egg06.eggX,egg06.eggY,redchicken6.damage);

			redchicken6.movement();
			window.draw(egg06.egg);
			window.draw(redchicken6.chicken);

			if(redchicken6.health==1) redchicken6.health--,
				redchicken6.chickenX=-1,redchicken6.chickenY=-1,Chickens :: numOfChick--;

		}

		if(player.health<2.0 && ballonMove && balloonchicken1.health>0.0 ){
			balloonchicken1.movement();
			balloonchickenegg.eggDrop(balloonchicken1.chickenX,balloonchicken1.chickenY);
			balloonchickenegg.egg_respwan=player.eggStrike(balloonchickenegg.eggX,balloonchickenegg.eggY,balloonchicken1.damage);
			
			window.draw(balloonchickenegg.egg);
			window.draw(balloonchicken1.chicken);

			if(balloonchicken1.chickenY<-50.0) ballonMove=false,Chickens :: numOfChick--;
			else if(balloonchicken1.health==1.0){
				balloonchicken1.health--,balloonchicken1.chickenX=-1,balloonchicken1.chickenY=-1,Chickens :: numOfChick--;
				player.beamtexture.loadFromFile("images/beam2.png");
				player.beam.setTexture(&player.beamtexture);
			}
		}
		else if( ( Chickens :: numOfChick)==1 && balloonchicken1.health==5 && ballonMove==true) (Chickens :: numOfChick)--;


		if(	redchicken1.beamStrike(player.beamX,player.beamY) || redchicken2.beamStrike(player.beamX,player.beamY) ||
			redchicken3.beamStrike(player.beamX,player.beamY) || redchicken4.beamStrike(player.beamX,player.beamY) || 
			redchicken5.beamStrike(player.beamX,player.beamY) || redchicken6.beamStrike(player.beamX,player.beamY) ||
			balloonchicken1.beamStrike(player.beamX,player.beamY))
			player.beam_respawn=true;
		else player.beam_respawn=false;


		if(player.beamMove)
			window.draw(player.beam);
		window.draw(player.spacecraft);
		if(player.DisplayHealth3()) window.draw(player.health3);
		if(player.DisplayHealth2()) window.draw(player.health2);
		if(player.DisplayHealth1()) window.draw(player.health1);

		window.display();

		if(!(Chickens :: numOfChick)){
			level1ThemeSound.stop();
			stageClearSound.play();
			window.clear();
			window.draw(levelCleared);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){};
			stageClearSound.stop();
			sf::sleep(sf::milliseconds(500));
			mainTheme.play();
			break;
		}
		if(player.health<=0.0){
			level1ThemeSound.stop();
			gameOverSound.play();
			window.clear();
			window.draw(gameOver);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){};
			Chickens :: numOfChick=0;
			gameOverSound.stop();
			sf::sleep(sf::milliseconds(500));
			mainTheme.play();
			break;
		}
	}
	l1=false;
	}

	 /*LEVEL : 2*/
	
	 
	if(l2){
	level2ThemeSound.play();
	mainTheme.stop();
	l2:
	 sf::Texture background5;
     background5.loadFromFile("images/background2.jpg");
     sf::Sprite sprite3;
     sprite3.setTexture(background5);

	Player player3(skinSelected); 
	GunChicken GunChicken1;
	SpaceshipChicken SpaceChicken4(70.0,200.0);
	SpaceshipChicken SpaceChicken5(997.0,200.0);
	Egg egg7(GunChicken1.chickenX-26,GunChicken1.chickenY,1,0.7);
	Egg egg8(GunChicken1.chickenX,GunChicken1.chickenY,1,0.8);
	Egg egg9(GunChicken1.chickenX+26,GunChicken1.chickenY,1,0.75);
	Egg egg10(SpaceChicken4.chickenX,SpaceChicken4.chickenY,1.2,0.6);
	Egg egg11(SpaceChicken5.chickenX,SpaceChicken5.chickenY,1.2,0.6);

	while (window.isOpen())
    {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			level2ThemeSound.stop();
			Chickens::numOfChick = 0;   
			mainTheme.play();		
			
			 break;
			 }
        sf::Event event;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
				case sf::Event::Closed:
					level2ThemeSound.stop(); // or level2/boss theme
					window.close();
					break;
				case sf::Event::LostFocus:
					isPaused = true;
					level2ThemeSound.pause(); // or level2/boss theme
					break;
				case sf::Event::GainedFocus:
					window.setActive(true); // Critical fix
					isPaused = false;
					level2ThemeSound.play(); // or level2/boss theme
					break;
				case sf::Event::KeyPressed:
					if (evnt.key.code == sf::Keyboard::Escape) {
						level2ThemeSound.stop(); // or level2/boss theme
						window.close();
					}
					break;
			}
		}
		window.clear();
		window.draw(sprite3);

		player3.movement();
		player3.beamShoot();


		

		if(GunChicken1.health>0.0){
			GunChicken1.movement();
			egg7.eggDrop(GunChicken1.chickenX-26,GunChicken1.chickenY);
			egg7.egg_respwan=player3.eggStrike(egg7.eggX,egg7.eggY,GunChicken1.damage);
			egg8.eggDrop(GunChicken1.chickenX,GunChicken1.chickenY);
			egg8.egg_respwan=player3.eggStrike(egg8.eggX,egg8.eggY,GunChicken1.damage);
			egg9.eggDrop(GunChicken1.chickenX+26,GunChicken1.chickenY);
			egg9.egg_respwan=player3.eggStrike(egg9.eggX,egg9.eggY,GunChicken1.damage);
			window.draw(GunChicken1.chicken);
			window.draw(egg7.egg);
			window.draw(egg8.egg);
			window.draw(egg9.egg);

			if(GunChicken1.health==1) GunChicken1.health--,
				GunChicken1.chickenX=-1,GunChicken1.chickenY=-1,Chickens :: numOfChick--;
		}

		if(SpaceChicken4.health>0.0){
			SpaceChicken4.movement();
			egg10.eggDrop(SpaceChicken4.chickenX,SpaceChicken4.chickenY);
			egg10.egg_respwan=player3.eggStrike(egg10.eggX,egg10.eggY,SpaceChicken4.damage);
			
			window.draw(egg10.egg);
			window.draw(SpaceChicken4.chicken);

			if(SpaceChicken4.health==1) SpaceChicken4.health--,
				SpaceChicken4.chickenX=-1,SpaceChicken4.chickenY=-1,Chickens :: numOfChick--;
		}

		if(SpaceChicken5.health>0.0){
			SpaceChicken5.movement();
			egg11.eggDrop(SpaceChicken5.chickenX,SpaceChicken5.chickenY);
			egg11.egg_respwan=player3.eggStrike(egg11.eggX,egg11.eggY,SpaceChicken5.damage);

			window.draw(egg11.egg);
			window.draw(SpaceChicken5.chicken);

			if(SpaceChicken5.health==1) SpaceChicken5.health--,
				SpaceChicken5.chickenX=-1,SpaceChicken5.chickenY=-1,Chickens :: numOfChick--;
		}
		
		if(GunChicken1.beamStrike(player3.beamX,player3.beamY) || SpaceChicken4.beamStrike(player3.beamX,player3.beamY) || SpaceChicken5.beamStrike(player3.beamX,player3.beamY))
			player3.beam_respawn=true;
		else player3.beam_respawn=false;

		if(player3.beamMove)
			window.draw(player3.beam);
		window.draw(player3.spacecraft);
		if(player3.DisplayHealth3()) window.draw(player3.health3);
		if(player3.DisplayHealth2()) window.draw(player3.health2);
		if(player3.DisplayHealth1()) window.draw(player3.health1);

		if(!(Chickens :: numOfChick)){
			level2ThemeSound.stop();
			stageClearSound.play();
			window.clear();
			window.draw(levelCleared);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){};
			stageClearSound.stop();
			sf::sleep(sf::milliseconds(500));
			mainTheme.play();
			break;
		}
		if(player3.health<=0.0){
			level2ThemeSound.stop();
			gameOverSound.play();
			window.clear();
			window.draw(gameOver);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){};
			Chickens :: numOfChick=0;
			gameOverSound.stop();
			sf::sleep(sf::milliseconds(500));
			mainTheme.play();
			break;
		}
		
		window.display();
	}
	l2=false;
	}

	 //LEVEL : 5
	if(l3){
		mainTheme.stop();
		bossThemeSound.play();

	sf::Texture background6;
     background6.loadFromFile("images/background3.jpg");
     sf::Sprite sprite4;
     sprite4.setTexture(background6);

	Player player4(skinSelected);
	FrozenChicken FrozenChicken1;
	BossChicken BossChicken1;
	Egg egg12(BossChicken1.chickenX,BossChicken1.chickenY,1.7,0.8);

	while (window.isOpen())
    {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			bossThemeSound.stop();
			Chickens::numOfChick = 0;   
			mainTheme.play();		
			
			 break;
			 }
        sf::Event event;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
				case sf::Event::Closed:
					bossThemeSound.stop(); // or level2/boss theme
					window.close();
					break;
				case sf::Event::LostFocus:
					isPaused = true;
					bossThemeSound.pause(); // or level2/boss theme
					break;
				case sf::Event::GainedFocus:
					window.setActive(true); // Critical fix
					isPaused = false;
					bossThemeSound.play(); // or level2/boss theme
					break;
				case sf::Event::KeyPressed:
					if (evnt.key.code == sf::Keyboard::Escape) {
						bossThemeSound.stop(); // or level2/boss theme
						window.close();
					}
					break;
			}
		}

		window.clear();
		window.draw(sprite4);

		player4.movement();
		player4.beamShoot();

		if(BossChicken1.health>0.0)
		{
			BossChicken1.movement();
			egg12.eggDrop(BossChicken1.chickenX,BossChicken1.chickenY);
			egg12.egg_respwan=player4.eggStrike(egg12.eggX,egg12.eggY,BossChicken1.damage);
			player4.beam_respawn=BossChicken1.beamStrike(player4.beamX,player4.beamY);

			window.draw(egg12.egg);
			window.draw(BossChicken1.chicken);
			if(BossChicken1.health==1) Chickens ::numOfChick--;
			
		}

		FrozenChicken1.movement();
		if(FrozenChicken1.Collision(player4.spaceraftX,player4.spaceraftY)) player4.health-=1;
			
		if(player4.beamMove)
			window.draw(player4.beam);
		window.draw(player4.spacecraft);
		window.draw(FrozenChicken1.chicken);

		if(BossChicken1.DisplayHealth4()) window.draw(BossChicken1.Bosshealth4);
		if(BossChicken1.DisplayHealth3()) window.draw(BossChicken1.Bosshealth3);
		if(BossChicken1.DisplayHealth2()) window.draw(BossChicken1.Bosshealth2);
		if(BossChicken1.DisplayHealth1()) window.draw(BossChicken1.Bosshealth1);

		if(player4.DisplayHealth3()) window.draw(player4.health3);
		if(player4.DisplayHealth2()) window.draw(player4.health2);
		if(player4.DisplayHealth1()) window.draw(player4.health1);

	if(!(Chickens :: numOfChick)){
		    bossThemeSound.stop();
		    stageClearSound.play();
			window.clear();
			window.draw(levelCleared);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){};
			stageClearSound.stop();
			sf::sleep(sf::milliseconds(500));
			mainTheme.play();
			break;
		}
		if(player4.health<=0.0){
			bossThemeSound.stop();
			gameOverSound.play();
			window.clear();
			window.draw(gameOver);  
			window.display();
			while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){};
			gameOverSound.stop();
			sf::sleep(sf::milliseconds(500));
			mainTheme.play();
			Chickens ::numOfChick=0;
			break;
		}

		window.display();
	}
	l3=false;
	}
	}
	}
	return 0;
}



#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class Player
{
public:
	Player(int skin);
	~Player(void);
	void movement();
	void beamShoot();
	bool eggStrike(float,float,float);
	bool DisplayHealth3();
	bool DisplayHealth2();
	bool DisplayHealth1();

public:

	float health;
	float spaceraftX,spaceraftY;
	bool beamMove;
	float beamX,beamY;
	bool beam_respawn;


	sf:: RectangleShape health1;
	sf:: RectangleShape health2;
	sf:: RectangleShape health3;
	sf:: RectangleShape beam;
	sf:: RectangleShape spacecraft;
	sf :: Texture beamtexture;

private:
    sf::Texture spacecrafttexture;
    sf::Texture health1texture;
    sf::Texture health2texture; 
    sf::Texture health3texture;
    
    // Add these sound members
    sf::SoundBuffer bulletBuffer;
    sf::Sound bulletSound;
	sf::SoundBuffer explosionBuffer;
    sf::Sound explosionSound;
};

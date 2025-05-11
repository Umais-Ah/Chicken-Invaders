#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class Chickens
{
public:
	Chickens(float,float);
	Chickens(float);
	~Chickens(void);
	virtual void movement() = 0;
	virtual bool beamStrike(float,float) = 0;
	void playHitSound();
public:
	static int numOfChick;
	int health;
	const float Origin,damage;
	float chickenX,chickenY;
	bool eggMove,chickenDir;
	sf :: RectangleShape chicken;
protected:
	sf :: Texture chickentexture;
	sf::SoundBuffer hitSoundBuffer;  // Sound buffer for hit sound
    sf::Sound hitSound;
};

class Egg 
{
public:
	Egg(float,float,float,float);
	~Egg();
	void eggDrop(float,float);

public:
	float eggX,eggY;
	bool egg_respwan;
	

	sf :: RectangleShape egg;
private:
	const float speed;
	sf :: Texture eggtexture;
	

};


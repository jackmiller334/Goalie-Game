#ifndef Audio_H
#define Audio_H
#include <SFML/Audio.hpp>

typedef sf::SoundBuffer soundBuff;

class Audio 
{
public:
	Audio();
	~Audio();


	void playKick1();
	void playKick2();
	void playKick3();
private:
	std::vector<sf::SoundBuffer> kicks;
	sf::Sound ballKick;
	void loadSounds();
};

#endif
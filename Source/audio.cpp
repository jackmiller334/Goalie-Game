#include "audio.h"

Audio::Audio()
{
	loadSounds();
}

Audio::~Audio()
{
}

void Audio::loadSounds()
{
	soundBuff temp;
	if(temp.loadFromFile("Assets/Sound/kick-01.wav"))
	{
		kicks.push_back(temp);
	}
	else
		printf("Audio failed to load: kick-01.wav");


	if(temp.loadFromFile("Assets/Sound/kick-02.wav"))
	{
		kicks.push_back(temp);
	}
	else
		printf("Audio failed to load: kick-02.wav");


	if(temp.loadFromFile("Assets/Sound/knee-01.wav"))
	{
		kicks.push_back(temp);
	}
	else
		printf("Audio failed to load: knee-01.wav");
}

void Audio::playKick1()
{
	ballKick.setBuffer(kicks[2]);
	ballKick.play();
}

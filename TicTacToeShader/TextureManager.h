#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include <string>

//TODO this could probably have a base class with Templates as it shares simularities 
//-----with an audio manager in the future, but I'll be lazy for now.

class TextureManager
{
public:
	static TextureManager *instance;
	static TextureManager *getInstance();
	bool LoadFile(std::string _fileName, std::string _key);
	sf::Texture& GetTexture(std::string _key);
	bool IsFileLoaded(std::string _key);
	bool LoadError();
	

private:
	bool errorLoading = false;
	std::map<std::string, sf::Texture> textures;
};
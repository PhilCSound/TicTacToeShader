#include "TextureManager.h"


//Singleton set nullpointer.
TextureManager *TextureManager::instance = 0;


TextureManager * TextureManager::getInstance()
{
	if (!instance)
		instance = new TextureManager;
	return instance;
}

bool TextureManager::LoadFile(std::string _fileName, std::string _key)
{
	if (!IsFileLoaded(_key))
	{
		sf::Texture _texture;
		if (!_texture.loadFromFile(_fileName))
			return false;
		_texture.setRepeated(true);
		textures.insert(std::pair<std::string, sf::Texture>(_key, _texture));
	}
	return true;
}

sf::Texture& TextureManager::GetTexture(std::string _key)
{
	if (!IsFileLoaded(_key)) {
		sf::Texture _texture;
		textures.insert(std::pair<std::string, sf::Texture>(_key, _texture));
		errorLoading = true;
	}

	//File's loaded so it returns the file in the map.
	return textures.at(_key);
}

bool TextureManager::IsFileLoaded(std::string _key)
{
	std::map<std::string, sf::Texture>::iterator _it = textures.find(_key);

	//Doesn't exist
	if (_it == textures.end()) {
		return false;
	}

	return true;
}

bool TextureManager::LoadError()
{
	//TODO: Could definately make this alot better in the future, but shall suffice
	bool _err = errorLoading;
	errorLoading = !errorLoading;
	return _err;
}

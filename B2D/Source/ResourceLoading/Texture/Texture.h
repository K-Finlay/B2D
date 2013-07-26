#ifndef TEXTURE_H
#define TEXTURE_H

namespace b2d{

	// Texture Manager Class
	class Texture{
	public:

		// Constructors
		Texture(){};

		// Functions
		static unsigned int LoadTexture (char *TextureFileName, unsigned int &TextureID);
	    static void ConfigureTexture (unsigned char *textureData, int texWidth, int texHeight);
	};
}

#endif
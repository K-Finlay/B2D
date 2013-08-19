#include "Texture.h"
#include <iostream>
#include <GL/glew.h>
#include <FreeImage/FreeImage.h>

///////////////////////////////////////////
//     This File Handles The Loading     //
//              Of A Texture             //
///////////////////////////////////////////

namespace b2d{

	// Load Texture From File
	GLuint Texture::LoadTexture (char *TextureFileName, GLuint &TextureID){

		// Check For Blank Texture Path
		if (TextureFileName == "NULL"){
			return -1;
		}

		// Get Image File Type And Set Variables
		FREE_IMAGE_FORMAT freeImageFormat = FreeImage_GetFileType (TextureFileName, 0);
		FIBITMAP *freeImageBitMap;

		// If Failed, Get File Extension
		if (freeImageFormat == FIF_UNKNOWN){
			FreeImage_GetFIFFromFilename (TextureFileName);
		}

		// If Still Failed, Return Failure
		else if (freeImageFormat == FIF_UNKNOWN){

			std::cout << stderr << " The Texture \"" << TextureFileName << "\" could not be loaded" << '\n' << "Unknown file type" << '\n';
			return -1;
		}

		// Check To See If Plugin Supprorts Texture Import
		if (FreeImage_FIFSupportsReading (freeImageFormat)){
			freeImageBitMap = FreeImage_Load (freeImageFormat, TextureFileName, 0);
		}

		// If Not, Return Failure
		else{

			std::cout << stderr << " The Texture \"" << TextureFileName << "\" could not be loaded" << '\n' << "File not found" << '\n';
			return -1;
		}

		// Convert Texture To 32 Bits
		FIBITMAP *temp = freeImageBitMap;
        freeImageBitMap = FreeImage_ConvertTo32Bits (temp);
        FreeImage_Unload (temp);

		// If Image Has Been Loaded, Create OpenGL Texture
		if (freeImageBitMap != NULL){

			// Delete Old Texture If It Exists
			glDeleteTextures (1, &TextureID);

			// Generate Texture
	        glGenTextures (1, &TextureID);
            glBindTexture (GL_TEXTURE_2D, TextureID);

			// Get Image Data
            BYTE *pixels = (BYTE*) FreeImage_GetBits (freeImageBitMap);
            Texture::ConfigureTexture (pixels,  FreeImage_GetWidth (freeImageBitMap),  FreeImage_GetHeight (freeImageBitMap));           

			// Unload Textures
            FreeImage_Unload(freeImageBitMap);
			glBindTexture (GL_TEXTURE_2D, 0);

			return TextureID;
		}

		// If Above Fails, Return Unknown Error
		else{

			std::cout << stderr << " The texture \"" << TextureFileName << "\" could not be loaded" << '\n' << "Unknown error" << '\n';
			return -1;
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Configure The Texture
	void Texture::ConfigureTexture (GLubyte *textureData, GLint texWidth, GLint texHeight){

		// If Data Is Empty, Return Failure
		if (textureData == NULL || texWidth == 0 || texHeight == 0){

			std::cout << stderr << " Texture could not be loaded. Could not load data" << '\n';
			return;
		}

		// Configure OpenGL Texture
		glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri (GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
        glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
	}
}
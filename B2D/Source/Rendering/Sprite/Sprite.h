#ifndef SPRITE_H
#define SPRITE_H

#include "../Primitive/Primitive.h"
#include "../../ResourceLoading/Texture/Texture.h"

namespace b2d{

	// Sprite Class
	class Sprite : private Square{
	public:

		// Constructors
		Sprite();
		Sprite (Vector2::Point Position, int Width, int Height, char* TexturePath, RGBA Colour = RGBA (1.0f, 1.0f, 1.0f, 1.0f));

		// Functions
		void Draw();
		void Update();
		void SwapTexture (char* TexturePath);
		void PlayAnimation (int NumOfFrames, int StartNum, int EndNum, float AnimationSpeed);
		void SetFrame (int NumOfFrames, int Frame);
		void StopAnimation();
		void ResumeAnimation();
		void Reload (Vector2::Point Position, int Width, int Height, char* TexturePath, RGBA Colour = RGBA (1.0f, 1.0f, 1.0f, 1.0f));
		void Destroy();
		using Square::Move;
		using Square::Translate;
		using Square::Scale;

		// Variables
		using Square::position;
		using Square::rotation;
		using Square::canRender;
		using Square::width;
		using Square::height;
		using Square::isStatic;
		using Square::colour;
		bool isAnimated;
		int frameNum;
		int startNum;
		int endNum;
		int currentFrame;
		double frameSize;
		float animationSpeed;
		unsigned int glTex;

	private:

		// Variables
		unsigned int vboID;
		double animationWaitTime;
		Vector2::Point oldVerts[4];
	};
}

#endif
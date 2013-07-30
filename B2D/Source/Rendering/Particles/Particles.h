#ifndef PARTICLES_H
#define PARTICLES_H

#include "../Sprite/Sprite.h"
#include <vector>

namespace b2d{

    // Particle Class
    class ParticleEmitter{
    
    public:
    
    	// Constructors
    	ParticleEmitter();
    	ParticleEmitter (Vector2::Point Position, char* TexturePath, float FadeRate = 1.0f, RGBA Colour = RGBA (1.0f, 1.0f, 1.0f, 1.0f));
		
		// Functions
		void SetEmissionRate (float EmissionRate, int EmissionNumber = 1);
		void SetMaxParticles (int MaxParticles);
		void SetParticleHealth (float MinLife, float MaxLife);
		void SetParticleSize (float MinSize, float MaxSize);
		void SetParticleVelocity (Vector2::Point MinVelocity, Vector2::Point MaxVelocity);
		void ChangeParticleVelocity (Vector2::Point MinVelocity, Vector2::Point MaxVelocity);
		void Draw();
		void Destroy();
    
    	// Variables
    	std::vector <Sprite> particleList;
		std::vector <float> lifeList;
		std::vector <float> sizeList;
		std::vector <Vector2::Point> velocityList;
		int maxParticles;
		int emissionNumber;
		float emissionRate;
		float minLife, maxLife;
		float minSize, maxSize;
		float fadeRate;
		bool canEmit;
		Vector2::Point minVelocity;
		Vector2::Point maxVelocity;
		Vector2::Point position;
		Vector4::Point colour;
		unsigned int glTexture;

	private:

		// Variables
		double timer;
    };
}

#endif
#include "Particles.h"
#include "../../ResourceLoading/Texture/Texture.h"
#include <GL/glew.h>
#include <time.h>
#include <random>

namespace b2d{

	// Particle Constructor
	ParticleEmitterLine::ParticleEmitterLine (Vector2::Point StartPos, Vector2::Point EndPos, char* TexturePath, float FadeRate, RGBA Colour){

		// Load Texture
		GLuint texID = 0;
		ParticleEmitterLine::glTexture = Texture::LoadTexture (TexturePath, texID);

		// Set Variables
		ParticleEmitterLine::startPos = StartPos;
		ParticleEmitterLine::endPos = EndPos;
		ParticleEmitterLine::colour = Colour.colour;
		ParticleEmitterLine::timer = 0.0;
		ParticleEmitterLine::fadeRate = FadeRate;
		ParticleEmitterLine::canEmit = true;

		// Seed Random
		srand ((unsigned int) time (NULL));
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Particle Emission Rate
	void ParticleEmitterLine::SetEmissionRate (float EmissionRate, int EmissionNumber){

		ParticleEmitterLine::emissionRate = EmissionRate / 100;
		ParticleEmitterLine::emissionNumber = EmissionNumber;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Max Num Of Particles
	void ParticleEmitterLine::SetMaxParticles (int MaxParticles){
		ParticleEmitterLine::maxParticles = MaxParticles;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Particle Health
	void ParticleEmitterLine::SetParticleHealth (float MinLife, float MaxLife){

		ParticleEmitterLine::minLife = MinLife;
		ParticleEmitterLine::maxLife = MaxLife;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Particle Size
	void ParticleEmitterLine::SetParticleSize (float MinSize, float MaxSize){

		ParticleEmitterLine::minSize = MinSize;
		ParticleEmitterLine::maxSize = MaxSize;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Initial Particle Velocity
	void ParticleEmitterLine::SetParticleVelocity (Vector2::Point MinVelocity, Vector2::Point MaxVelocity){

		ParticleEmitterLine::minVelocity = MinVelocity;
		ParticleEmitterLine::maxVelocity = MaxVelocity;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Change The Particle Velocity
	void ParticleEmitterLine::ChangeParticleVelocity (Vector2::Point MinVelocity, Vector2::Point MaxVelocity){

		// Change Min Velocity
		ParticleEmitterLine::minVelocity.x -= MinVelocity.x;
		ParticleEmitterLine::minVelocity.y -= MinVelocity.y;

		// Change Max Velocity
		ParticleEmitterLine::maxVelocity.x -= MaxVelocity.x;
		ParticleEmitterLine::maxVelocity.y -= MaxVelocity.y;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Draw The Particles
	void ParticleEmitterLine::Draw(){

		ParticleEmitterLine::timer += Time::deltaTime;

		// Check If New Particle Can Be Created
		if (ParticleEmitterLine::timer >= ParticleEmitterLine::emissionRate && (int) ParticleEmitterLine::particleList.size() <= ParticleEmitterLine::maxParticles && ParticleEmitterLine::canEmit){

			// Create Required Num Of Particles
			for (int i = 0; i < ParticleEmitterLine::emissionNumber; ++i){

			    // Set Particle Variables
			    float particleSize = float (rand()) / float (RAND_MAX) * (ParticleEmitterLine::maxSize - ParticleEmitterLine::minSize) + ParticleEmitterLine::minSize;
			    float particleHealth = float (rand()) / float (RAND_MAX) * (ParticleEmitterLine::maxLife - ParticleEmitterLine::minLife) + ParticleEmitterLine::minLife;
			    
			    Vector2::Point particleVelocity;
			    particleVelocity.x = float (rand()) / float (RAND_MAX) * (ParticleEmitterLine::maxVelocity.x - ParticleEmitterLine::minVelocity.x) + ParticleEmitterLine::minVelocity.x;
			    particleVelocity.y = float (rand()) / float (RAND_MAX) * (ParticleEmitterLine::maxVelocity.y - ParticleEmitterLine::minVelocity.y) + ParticleEmitterLine::minVelocity.y;
			    
			    // Add Variables To Lists
			    ParticleEmitterLine::lifeList.push_back (particleHealth);
			    ParticleEmitterLine::sizeList.push_back (particleSize);
			    ParticleEmitterLine::velocityList.push_back (particleVelocity);
			    
			    // Create New Particle
				float particlePos = float (rand()) / float (RAND_MAX) * (1.0f - 0.0f) + 0.0f;
				Sprite* newParticle = new Sprite (Vector2::Lerp (ParticleEmitterLine::startPos, ParticleEmitterLine::endPos, particlePos), (int) particleSize, (int) particleSize, "NULL");
			    
			    // Set Particle Texture
			    newParticle[0].glTex = ParticleEmitterLine::glTexture;
			    
			    // Add Particle To List
			    ParticleEmitterLine::particleList.push_back (newParticle[0]);
			    delete (newParticle);
			}

			// Reset Timer
			ParticleEmitterLine::timer = 0.0;
		}

		// Render All Particles
		for (int i = 0; i < (int) ParticleEmitterLine::particleList.size(); ++i){

			ParticleEmitterLine::particleList[i].Draw();

			// Move Particles
			ParticleEmitterLine::particleList[i].Translate (ParticleEmitterLine::velocityList[i].x, ParticleEmitterLine::velocityList[i].y, 0);

			// Subtract Health
			ParticleEmitterLine::lifeList[i] -= (float) Time::deltaTime;

			// Check If Particle Is Dying
			if (ParticleEmitterLine::lifeList[i] <= 0){
				ParticleEmitterLine::particleList[i].colour.w -= ParticleEmitterLine::fadeRate * (float) Time::deltaTime;
			}

			// Check If Particle Is Dead
			if (ParticleEmitterLine::lifeList[i] <= 0 && ParticleEmitterLine::particleList[i].colour.w <= 0){

				// Destroy Particle
				ParticleEmitterLine::particleList.erase (ParticleEmitterLine::particleList.begin() + i);
				ParticleEmitterLine::lifeList.erase (ParticleEmitterLine::lifeList.begin() + i);
				ParticleEmitterLine::sizeList.erase (ParticleEmitterLine::sizeList.begin() + i);
				ParticleEmitterLine::velocityList.erase (ParticleEmitterLine::velocityList.begin() + i);
			}
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Deconstructor
	void ParticleEmitterLine::Destroy(){

		glDeleteTexturesEXT (1, &glTexture);

		ParticleEmitterLine::particleList.clear();
		ParticleEmitterLine::lifeList.clear();
		ParticleEmitterLine::sizeList.clear();
		ParticleEmitterLine::velocityList.clear();
	}
}
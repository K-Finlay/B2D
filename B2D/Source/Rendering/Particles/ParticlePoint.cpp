#include "Particles.h"
#include "../../ResourceLoading/Texture/Texture.h"
#include <GL/glew.h>
#include <time.h>
#include <random>

namespace b2d{

	// Particle Constructor
	ParticleEmitterPoint::ParticleEmitterPoint (Vector2::Point Position, char* TexturePath, float FadeRate, RGBA Colour){

		// Load Texture
		GLuint texID = 0;
		ParticleEmitterPoint::glTexture = Texture::LoadTexture (TexturePath, texID);

		// Set Variables
		ParticleEmitterPoint::position = Position;
		ParticleEmitterPoint::colour = Colour.colour;
		ParticleEmitterPoint::timer = 0.0;
		ParticleEmitterPoint::fadeRate = FadeRate;
		ParticleEmitterPoint::canEmit = true;

		// Seed Random
		srand ((unsigned int) time (NULL));
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Particle Emission Rate
	void ParticleEmitterPoint::SetEmissionRate (float EmissionRate, int EmissionNumber){

		ParticleEmitterPoint::emissionRate = EmissionRate / 100;
		ParticleEmitterPoint::emissionNumber = EmissionNumber;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Max Num Of Particles
	void ParticleEmitterPoint::SetMaxParticles (int MaxParticles){
		ParticleEmitterPoint::maxParticles = MaxParticles;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Particle Health
	void ParticleEmitterPoint::SetParticleHealth (float MinLife, float MaxLife){

		ParticleEmitterPoint::minLife = MinLife;
		ParticleEmitterPoint::maxLife = MaxLife;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Particle Size
	void ParticleEmitterPoint::SetParticleSize (float MinSize, float MaxSize){

		ParticleEmitterPoint::minSize = MinSize;
		ParticleEmitterPoint::maxSize = MaxSize;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Initial Particle Velocity
	void ParticleEmitterPoint::SetParticleVelocity (Vector2::Point MinVelocity, Vector2::Point MaxVelocity){

		ParticleEmitterPoint::minVelocity = MinVelocity;
		ParticleEmitterPoint::maxVelocity = MaxVelocity;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Change The Particle Velocity
	void ParticleEmitterPoint::ChangeParticleVelocity (Vector2::Point MinVelocity, Vector2::Point MaxVelocity){

		// Change Min Velocity
		ParticleEmitterPoint::minVelocity.x -= MinVelocity.x;
		ParticleEmitterPoint::minVelocity.y -= MinVelocity.y;

		// Change Max Velocity
		ParticleEmitterPoint::maxVelocity.x -= MaxVelocity.x;
		ParticleEmitterPoint::maxVelocity.y -= MaxVelocity.y;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Draw The Particles
	void ParticleEmitterPoint::Draw(){

		ParticleEmitterPoint::timer += Time::deltaTime;

		// Check If New Particle Can Be Created
		if (ParticleEmitterPoint::timer >= ParticleEmitterPoint::emissionRate && (int) ParticleEmitterPoint::particleList.size() <= ParticleEmitterPoint::maxParticles && ParticleEmitterPoint::canEmit){

			// Create Required Num Of Particles
			for (int i = 0; i < ParticleEmitterPoint::emissionNumber; ++i){

			    // Set Particle Variables
			    float particleSize = float (rand()) / float (RAND_MAX) * (ParticleEmitterPoint::maxSize - ParticleEmitterPoint::minSize) + ParticleEmitterPoint::minSize;
			    float particleHealth = float (rand()) / float (RAND_MAX) * (ParticleEmitterPoint::maxLife - ParticleEmitterPoint::minLife) + ParticleEmitterPoint::minLife;
			    
			    Vector2::Point particleVelocity;
			    particleVelocity.x = float (rand()) / float (RAND_MAX) * (ParticleEmitterPoint::maxVelocity.x - ParticleEmitterPoint::minVelocity.x) + ParticleEmitterPoint::minVelocity.x;
			    particleVelocity.y = float (rand()) / float (RAND_MAX) * (ParticleEmitterPoint::maxVelocity.y - ParticleEmitterPoint::minVelocity.y) + ParticleEmitterPoint::minVelocity.y;
			    
			    // Add Variables To Lists
			    ParticleEmitterPoint::lifeList.push_back (particleHealth);
			    ParticleEmitterPoint::sizeList.push_back (particleSize);
			    ParticleEmitterPoint::velocityList.push_back (particleVelocity);
			    
			    // Create New Particle
			    Sprite* newParticle = new Sprite (ParticleEmitterPoint::position, (int) particleSize, (int) particleSize, "NULL");
			    
			    // Set Particle Texture
			    newParticle[0].glTex = ParticleEmitterPoint::glTexture;
			    
			    // Add Particle To List
			    ParticleEmitterPoint::particleList.push_back (newParticle[0]);
			    delete (newParticle);
			}

			// Reset Timer
			ParticleEmitterPoint::timer = 0.0;
		}

		// Render All Particles
		for (int i = 0; i < (int) ParticleEmitterPoint::particleList.size(); ++i){

			ParticleEmitterPoint::particleList[i].Draw();

			// Move Particles
			ParticleEmitterPoint::particleList[i].Translate (ParticleEmitterPoint::velocityList[i].x, ParticleEmitterPoint::velocityList[i].y, 0);

			// Subtract Health
			ParticleEmitterPoint::lifeList[i] -= (float) Time::deltaTime;

			// Check If Particle Is Dying
			if (ParticleEmitterPoint::lifeList[i] <= 0){
				ParticleEmitterPoint::particleList[i].colour.w -= ParticleEmitterPoint::fadeRate * (float) Time::deltaTime;
			}

			// Check If Particle Is Dead
			if (ParticleEmitterPoint::lifeList[i] <= 0 && ParticleEmitterPoint::particleList[i].colour.w <= 0){

				// Destroy Particle
				ParticleEmitterPoint::particleList.erase (ParticleEmitterPoint::particleList.begin() + i);
				ParticleEmitterPoint::lifeList.erase (ParticleEmitterPoint::lifeList.begin() + i);
				ParticleEmitterPoint::sizeList.erase (ParticleEmitterPoint::sizeList.begin() + i);
				ParticleEmitterPoint::velocityList.erase (ParticleEmitterPoint::velocityList.begin() + i);
			}
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Deconstructor
	void ParticleEmitterPoint::Destroy(){

		glDeleteTexturesEXT (1, &glTexture);

		ParticleEmitterPoint::particleList.clear();
		ParticleEmitterPoint::lifeList.clear();
		ParticleEmitterPoint::sizeList.clear();
		ParticleEmitterPoint::velocityList.clear();
	}
}
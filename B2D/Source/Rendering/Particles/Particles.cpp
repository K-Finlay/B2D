#include "Particles.h"
#include "../../ResourceLoading/Texture/Texture.h"
#include <GL/glew.h>
#include <time.h>
#include <random>

namespace b2d{

	// Particle Constructor
	ParticleEmitter::ParticleEmitter (Vector2::Point Position, char* TexturePath, float FadeRate, RGBA Colour){

		// Load Texture
		GLuint texID = 0;
		ParticleEmitter::glTexture = Texture::LoadTexture (TexturePath, texID);

		// Set Variables
		ParticleEmitter::position = Position;
		ParticleEmitter::colour = Colour.colour;
		ParticleEmitter::timer = 0.0;
		ParticleEmitter::fadeRate = FadeRate;
		ParticleEmitter::canEmit = true;

		// Seed Random
		srand ((unsigned int) time (NULL));
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Particle Emission Rate
	void ParticleEmitter::SetEmissionRate (float EmissionRate){
		ParticleEmitter::emissionRate = EmissionRate / 100;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Max Num Of Particles
	void ParticleEmitter::SetMaxParticles (int MaxParticles){
		ParticleEmitter::maxParticles = MaxParticles;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Particle Health
	void ParticleEmitter::SetParticleHealth (float MinLife, float MaxLife){

		ParticleEmitter::minLife = MinLife;
		ParticleEmitter::maxLife = MaxLife;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Particle Size
	void ParticleEmitter::SetParticleSize (float MinSize, float MaxSize){

		ParticleEmitter::minSize = MinSize;
		ParticleEmitter::maxSize = MaxSize;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Initial Particle Velocity
	void ParticleEmitter::SetParticleVelocity (Vector2::Point MinVelocity, Vector2::Point MaxVelocity){

		ParticleEmitter::minVelocity = MinVelocity;
		ParticleEmitter::maxVelocity = MaxVelocity;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Change The Particle Velocity
	void ParticleEmitter::ChangeParticleVelocity (Vector2::Point MinVelocity, Vector2::Point MaxVelocity){

		// Change Min Velocity
		ParticleEmitter::minVelocity.x -= MinVelocity.x;
		ParticleEmitter::minVelocity.y -= MinVelocity.y;

		// Change Max Velocity
		ParticleEmitter::maxVelocity.x -= MaxVelocity.x;
		ParticleEmitter::maxVelocity.y -= MaxVelocity.y;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Draw The Particles
	void ParticleEmitter::Draw(){

		ParticleEmitter::timer += Time::deltaTime;

		// Check If New Particle Can Be Created
		if (ParticleEmitter::timer >= ParticleEmitter::emissionRate && (int) ParticleEmitter::particleList.size() <= ParticleEmitter::maxParticles && ParticleEmitter::canEmit){

			// Set Particle Variables
			float particleSize = float (rand()) / float (RAND_MAX) * (ParticleEmitter::maxSize - ParticleEmitter::minSize) + ParticleEmitter::minSize;
			float particleHealth = float (rand()) / float (RAND_MAX) * (ParticleEmitter::maxLife - ParticleEmitter::minLife) + ParticleEmitter::minLife;

			Vector2::Point particleVelocity;
			particleVelocity.x = float (rand()) / float (RAND_MAX) * (ParticleEmitter::maxVelocity.x - ParticleEmitter::minVelocity.x) + ParticleEmitter::minVelocity.x;
			particleVelocity.y = float (rand()) / float (RAND_MAX) * (ParticleEmitter::maxVelocity.y - ParticleEmitter::minVelocity.y) + ParticleEmitter::minVelocity.y;

			// Add Variables To Lists
			ParticleEmitter::lifeList.push_back (particleHealth);
			ParticleEmitter::sizeList.push_back (particleSize);
			ParticleEmitter::velocityList.push_back (particleVelocity);

			// Create New Particle
			Sprite* newParticle = new Sprite (ParticleEmitter::position, (int) particleSize, (int) particleSize, "NULL");

			// Set Particle Texture
			newParticle[0].glTex = ParticleEmitter::glTexture;

			// Add Particle To List
			ParticleEmitter::particleList.push_back (newParticle[0]);
			delete (newParticle);

			// Reset Timer
			ParticleEmitter::timer = 0.0;
		}

		// Render All Particles
		for (int i = 0; i < (int) ParticleEmitter::particleList.size(); ++i){

			ParticleEmitter::particleList[i].Draw();

			// Move Particles
			ParticleEmitter::particleList[i].Translate (ParticleEmitter::velocityList[i].x, ParticleEmitter::velocityList[i].y, 0);

			// Subtract Health
			ParticleEmitter::lifeList[i] -= (float) Time::deltaTime;

			// Check If Particle Is Dying
			if (ParticleEmitter::lifeList[i] <= 0){
				ParticleEmitter::particleList[i].colour.w -= ParticleEmitter::fadeRate * (float) Time::deltaTime;
			}

			// Check If Particle Is Dead
			if (ParticleEmitter::lifeList[i] <= 0 && ParticleEmitter::particleList[i].colour.w <= 0){

				// Destroy Particle
				ParticleEmitter::particleList.erase (ParticleEmitter::particleList.begin() + i);
				ParticleEmitter::lifeList.erase (ParticleEmitter::lifeList.begin() + i);
				ParticleEmitter::sizeList.erase (ParticleEmitter::sizeList.begin() + i);
				ParticleEmitter::velocityList.erase (ParticleEmitter::velocityList.begin() + i);
			}
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Deconstructor
	void ParticleEmitter::Destroy(){

		glDeleteTexturesEXT (1, &glTexture);

		ParticleEmitter::particleList.clear();
		ParticleEmitter::lifeList.clear();
		ParticleEmitter::sizeList.clear();
		ParticleEmitter::velocityList.clear();
	}
}
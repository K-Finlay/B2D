#include "Sound.h"
#include <iostream>

using namespace audiere;

///////////////////////////////////////////
//     This File Handles The Loading     //
//       And Playing Of Sound Files      //
///////////////////////////////////////////

namespace b2d{

	// Sound Constructor
	Sound::Sound (const char* FileName, bool Looping, bool LoadIntoMemory){

		// Create Sound System
		Sound::system = (OpenDevice());

		if (!Sound::system){

			std::cout << stderr << " The sound engine could not be initialized" << '\n';
			return;
		}

		// Create Sound
		Sound::sound = (OpenSound (system, FileName, LoadIntoMemory));

		if (!Sound::sound){

			std::cout << stderr << " The sound \"" << FileName << "\" could not be loaded" << '\n';
			return;
		}

		// Set Looping If requested
		Sound::sound -> setRepeat (Looping);

		// Set Variables
		Sound::soundIsPlaying = false;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Play The Sound
	void Sound::Play(){

		// Play Sound
		Sound::sound -> reset();
		Sound::sound -> play();
		Sound::soundIsPlaying = true;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Pause The Sound
	void Sound::Pause(){

		Sound::sound -> stop();
		Sound::soundIsPlaying = true;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Stop The Sound
	void Sound::Stop(){

		// Stop Sound
		Sound::sound -> reset();
		Sound::sound -> stop();
		Sound::soundIsPlaying = false;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Volume
	void Sound::SetVolume (float Volume){
		Sound::sound -> setVolume (Volume);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Pan
	void Sound::SetPan (float Pan){
		Sound::sound -> setPan (Pan);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Pitch
	void Sound::SetPitch (float Pitch){
		Sound::sound -> setPitchShift (Pitch);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Sound Deconstructor
	Sound::~Sound(){
	}
}

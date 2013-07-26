#include "Sound.h"
#include <Windows.h>

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

			MessageBox (NULL, TEXT ("Sound engine could not be initialized."), TEXT ("AUDIERE ERROR"), MB_ICONERROR);
			return;
		}

		// Create Sound
		Sound::sound = (OpenSound (system, FileName, LoadIntoMemory));

		if (!Sound::sound){

			MessageBox (NULL, TEXT ("Sound could not be loaded"), TEXT ("AUDIERE ERROR"), MB_ICONERROR);
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

	// Stop The Sound
	void Sound::Stop(){

		// Stop Sound
		Sound::sound -> reset();
		Sound::sound -> stop();
		Sound::soundIsPlaying = false;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Sound Deconstructor
	Sound::~Sound(){
	}
}
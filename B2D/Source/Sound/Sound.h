#ifndef SOUND_H
#define SOUND_H

#include <Audiere/audiere.h>

namespace b2d{

	// The Sound Class
	class Sound{
	public:

		// Constructors
		Sound();
		Sound (const char* FileName, bool Looping, bool LoadIntoMemory = true);
		~Sound();

		// Functions
		void Play();
		void Pause();
		void Stop();
		void SetVolume (float Volume);
		void SetPan (float Pan);
		void SetPitch (float Pitch);

		// Variables
		bool soundIsPlaying;

	private:

		// Variables
		audiere::AudioDevicePtr system;
		audiere::OutputStreamPtr sound;
	};
}

#endif

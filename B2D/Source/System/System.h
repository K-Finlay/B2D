#ifndef TIME_H
#define TIME_H

namespace b2d{

	// Time Class
	class Time{
	public:

		// Constructor
		Time(){};

		// Functions
		static double GetSystemTime (int SecMinHour);
		static void GetDeltaTime();
		static void ResetDeltaTime();
        static double GetFPS();

		// Variables
		static double deltaTime;

	private:

		// Variables
		static double previousTime;
		static double currentTime;

        static double frameCount;
		static double timePerFrame;
		static double fps;
	};

	// Display Class
	class System{
	public:

		//Functions
		static int GetDisplayWidth();
		static int GetDisplayHeight();
		static int GetDisplayPixels();
	};
}

#endif
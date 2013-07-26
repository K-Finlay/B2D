#include "System.h"
#include <time.h>
#include <Windows.h>

///////////////////////////////////////////
//     This File Handles Everything      //
//             Time Related              // 
///////////////////////////////////////////

namespace b2d{

	// Init Variables
	double Time::currentTime = 0;
	double Time::previousTime = 0;
	double Time::deltaTime = 0;
    double Time::frameCount = 0;
	double Time::timePerFrame = 0;
	double Time::fps = 0;

	// Gets The Current System Time In Seconds, Minutes, Or Hours
	double Time::GetSystemTime (int SecMinHour){

		// Create Time Variables
		time_t cTime = time (0);
		tm *currentTime = localtime (&cTime);

		// Get Seconds
		if (SecMinHour == 0){
			return currentTime -> tm_sec;
		}

		// Get Minutes
		else if (SecMinHour == 1){
			return currentTime -> tm_min;
		}

		// Get Hours
		else if (SecMinHour == 2){
			return currentTime -> tm_hour;
		}

		// Get Error
		else{

			MessageBox (NULL, TEXT ("Invalid time type selected"), TEXT ("TIME ERROR"), MB_ICONERROR);
			return 0;
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get Delta Time
	void Time::GetDeltaTime(){

		Time::currentTime = clock();
		Time::deltaTime = (Time::currentTime - Time::previousTime) / CLOCKS_PER_SEC;
		Time::previousTime = Time::currentTime;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Reset Delta Time
	void Time::ResetDeltaTime(){

		Time::currentTime = 0.0;
		Time::deltaTime = 0.0;
		Time::previousTime = 0.0;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get FPS
	double Time::GetFPS(){

		// If One Second Has Not Passed, Add 1 Frame To Count
		if (Time::timePerFrame < 1){

			++Time::frameCount;
			Time::timePerFrame += Time::deltaTime;
		}

		// Otherwise, Return Frame Count
		else{

			Time::fps = Time::frameCount;
			Time::frameCount = 0;
			Time::timePerFrame = 0;

			return Time::fps;
		}

		return Time::fps;
	}
}
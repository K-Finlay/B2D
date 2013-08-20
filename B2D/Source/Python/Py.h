#ifndef PY_H
#define PY_H

#include <Python.h>
#include <vector>

#if defined (_WIN32)
    #define __func__ __FUNCTION__
#endif

// Functions Required To Load The Python Modules
void ParsePyTupleError (const char* Function, int Line);
PyObject* ImportPythonModule (const char* ModuleName);
PyObject* GetHandleToPythonFunction (PyObject* Module, const char* FunctionName);
PyObject* CallPythonFunction (PyObject* Function, PyObject* FunctionArguments);

namespace b2d{

	// This Is The Python Class
	class Python{
	public:

		// Functions
		static void Init (const char* ScriptDirectory);
		static void RunScript (const char* PythonModule, const char* Function);

		// Window Functions
		static PyObject* B2D_CreateGameWindow (PyObject* Self, PyObject* Args);
        static PyObject* B2D_ClearScreen (PyObject* Self, PyObject* Args);
        static PyObject* B2D_CloseWindow (PyObject* Self, PyObject* Args);
        static PyObject* B2D_ToggleFullScreen (PyObject* Self, PyObject* Args);
        static PyObject* B2D_SetWindowSize (PyObject* Self, PyObject* Args);
        static PyObject* B2D_SetWindowTitle (PyObject* Self, PyObject* Args);
        static PyObject* B2D_GameLoop (PyObject* Self, PyObject* Args);

		// Time Functions
		static PyObject* B2D_GetSystemTime (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetDeltaTime (PyObject* Self, PyObject* Args);
		static PyObject* B2D_ResetDeltaTime (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetFPS (PyObject* Self, PyObject* Args);
		static PyObject* B2D_deltaTime (PyObject* Self, PyObject* Args);

		// System Functions
		static PyObject* B2D_GetDisplayWidth (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetDisplayHeight (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetDisplayPixels (PyObject* Self, PyObject* Args);

		// Sound Functions
		static PyObject* B2D_CreateSound (PyObject* Self, PyObject* Args);
		static PyObject* B2D_PlaySound (PyObject* Self, PyObject* Args);
		static PyObject* B2D_PauseSound (PyObject* Self, PyObject* Args);
		static PyObject* B2D_StopSound (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetSoundVolume (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetSoundPan (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetSoundPitch (PyObject* Self, PyObject* Args);

		// Camera Functions
		static PyObject* B2D_MoveCamera (PyObject* Self, PyObject* Args);
		static PyObject* B2D_TranslateCamera (PyObject* Self, PyObject* Args);
		static PyObject* B2D_ZoomCamera (PyObject* Self, PyObject* Args);

		// Font Functions
		static PyObject* B2D_CreateFont (PyObject* Self, PyObject* Args);
		static PyObject* B2D_DrawFont (PyObject* Self, PyObject* Args);
		static PyObject* B2D_MoveFont (PyObject* Self, PyObject* Args);
		static PyObject* B2D_TranslateFont (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetFontColour (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetFontSize (PyObject* Self, PyObject* Args);
		static PyObject* B2D_DestroyFont (PyObject* Self, PyObject* Args);

		// GUI Button Functions
		static PyObject* B2D_CreateGUIButton (PyObject* Self, PyObject* Args);
		static PyObject* B2D_MoveGUIButton (PyObject* Self, PyObject* Args);
		static PyObject* B2D_TranslateGUIButton (PyObject* Self, PyObject* Args);
		static PyObject* B2D_ScaleGUIButton (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetGUIButtonClick (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetGUIButtonOver (PyObject* Self, PyObject* Args);
		static PyObject* B2D_DrawGUIButton (PyObject* Self, PyObject* Args);

		// Particle Emitter Functions
		static PyObject* B2D_CreateParticleEmitterPoint (PyObject* Self, PyObject* Args);
		static PyObject* B2D_CreateParticleEmitterLine (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetEmissionRate (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetMaxParticles (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetParticleHealth (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetParticleSize (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetParticleVelocity (PyObject* Self, PyObject* Args);
		static PyObject* B2D_ChangeParticleVelocity (PyObject* Self, PyObject* Args);
		static PyObject* B2D_MoveParticle (PyObject* Self, PyObject* Args);
		static PyObject* B2D_DrawParticle (PyObject* Self, PyObject* Args);
		static PyObject* B2D_DestroyParticle (PyObject* Self, PyObject* Args);

		// Primitive Functions
		static PyObject* B2D_CreateSquare (PyObject* Self, PyObject* Args);
		static PyObject* B2D_DrawSquare (PyObject* Self, PyObject* Args);
		static PyObject* B2D_MoveSquare (PyObject* Self, PyObject* Args);
		static PyObject* B2D_TranslateSquare (PyObject* Self, PyObject* Args);
		static PyObject* B2D_ScaleSquare (PyObject* Self, PyObject* Args);

		// Sprite Functions
		static PyObject* B2D_CreateSprite (PyObject* Self, PyObject* Args);
		static PyObject* B2D_DrawSprite (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SwapSpriteTexture (PyObject* Self, PyObject* Args);
		static PyObject* B2D_PlaySpriteAnimation (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetSpriteFrame (PyObject* Self, PyObject* Args);
		static PyObject* B2D_StopSpriteAnimation (PyObject* Self, PyObject* Args);
		static PyObject* B2D_ResumeSpriteAnimation (PyObject* Self, PyObject* Args);
		static PyObject* B2D_ReloadSprite (PyObject* Self, PyObject* Args);
		static PyObject* B2D_MoveSprite (PyObject* Self, PyObject* Args);
		static PyObject* B2D_TranslateSprite (PyObject* Self, PyObject* Args);
		static PyObject* B2D_ScaleSprite (PyObject* Self, PyObject* Args);
		static PyObject* B2D_DestroySprite (PyObject* Self, PyObject* Args);

		// Path Finding Functions
		static PyObject* B2D_CreatePathFinder (PyObject* Self, PyObject* Args);
		static PyObject* B2D_PathFinderAddNode (PyObject* Self, PyObject* Args);
		static PyObject* B2D_CalculateAStar (PyObject* Self, PyObject* Args);
		static PyObject* B2D_CalculateDijkstra (PyObject* Self, PyObject* Args);
		static PyObject* B2D_FollowPath (PyObject* Self, PyObject* Args);

		// Input Functions
		static PyObject* B2D_GetMousePos (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetMouseButton (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetKey (PyObject* Self, PyObject* Args);

		// Collision Functions
		static PyObject* B2D_GetCollision (PyObject* Self, PyObject* Args);

	private:

		static PyMethodDef B2DFunctions[];
		static std::vector <Sound> soundList;
		static std::vector <Font> fontList;
		static std::vector <GUIButton> guiButtonList;
		static std::vector <ParticleEmitterPoint> particlePointList;
		static std::vector <ParticleEmitterLine> particleLineList;
		static std::vector <Square> primitiveSquareList;
		static std::vector <Sprite> spriteList;
		static std::vector <PathFinder> pathList;
		static std::vector <Node> nodeList;
	};
}

#endif
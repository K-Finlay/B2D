#include "../B2D.h"
#include "Py.h"
#include <iostream>

// The Function Lookup Table
PyMethodDef b2d::Python::B2DFunctions[] = {

	// Window Functions
	{"CreateGameWindow"          , B2D_CreateGameWindow          , METH_VARARGS, "Create The Game Window."            },
	{"ClearScreen"               , B2D_ClearScreen               , METH_VARARGS, "Clear The Screen."                  },
	{"CloseWindow"               , B2D_CloseWindow               , METH_VARARGS, "Close The Window."                  },
	{"ToggleFullScreen"          , B2D_ToggleFullScreen          , METH_VARARGS, "Toggle Full Screen."                },
	{"SetWindowSize"             , B2D_SetWindowSize             , METH_VARARGS, "Set The Window Size."               },
	{"SetWindowTitle"            , B2D_SetWindowTitle            , METH_VARARGS, "Set The Window Title."              },
	{"GameLoop"                  , B2D_GameLoop                  , METH_VARARGS, "The Game Loop."                     },
					             					             										             
	// Time Functions            					             										             
	{"GetSystemTime"             , B2D_GetSystemTime             , METH_VARARGS, "Get The System Time"                },
	{"GetDeltaTime"              , B2D_GetDeltaTime              , METH_VARARGS, "Get The Delta Time"                 },
	{"ResetDeltaTime"            , B2D_ResetDeltaTime            , METH_VARARGS, "Reset The Delta Time"               },
	{"GetFPS"                    , B2D_GetFPS                    , METH_VARARGS, "Get The FPS"                        },
	{"deltaTime"                 , B2D_deltaTime                 , METH_VARARGS, "Return The Delta Time"              },
					             					             										             
	// System Functions          					             										             
	{"GetDisplayWidth"           , B2D_GetDisplayWidth           , METH_VARARGS, "Get The Display Width"              },
	{"GetDisplayHeight"          , B2D_GetDisplayHeight          , METH_VARARGS, "Get The Display Height"             },
	{"GetDisplayPixels"          , B2D_GetDisplayPixels          , METH_VARARGS, "Get The Display Pixels"             },
														         										             
	// Sound Functions									         										             
	{"CreateSound"               , B2D_CreateSound               , METH_VARARGS, "Create A New Sound"                 },
	{"PlaySound"                 , B2D_PlaySound                 , METH_VARARGS, "Play A Sound"                       },
	{"PauseSound"                , B2D_PauseSound                , METH_VARARGS, "Pause A Sound"                      },
	{"StopSound"                 , B2D_StopSound                 , METH_VARARGS, "Stop A Sound"                       },
	{"SetSoundVolume"            , B2D_SetSoundVolume            , METH_VARARGS, "Set Sound Volume"                   },
	{"SetSoundPan"               , B2D_SetSoundPan               , METH_VARARGS, "Set Sound Pan"                      },
	{"SetSoundPitch"             , B2D_SetSoundPitch             , METH_VARARGS, "Set Sound Pitch"                    },
					             					             										              
	// Camera Functions          					             										              
	{"MoveCamera"                , B2D_MoveCamera                , METH_VARARGS, "Move The Camera"                    },
	{"TranslateCamera"           , B2D_TranslateCamera           , METH_VARARGS, "Translate The Camera"               },
	{"ZoomCamera"                , B2D_ZoomCamera                , METH_VARARGS, "Zoom The Camera"                    },
					     					     		  	      							   			             
	// Font Functions    					     		  	      							   			             
	{"CreateFont"                , B2D_CreateFont                , METH_VARARGS, "Create A New Font"                  },
	{"DrawFont"                  , B2D_DrawFont                  , METH_VARARGS, "Draw The Font"                      },
	{"MoveFont"                  , B2D_MoveFont                  , METH_VARARGS, "Move The Font"                      },
	{"TranslateFont"             , B2D_TranslateFont             , METH_VARARGS, "Translate The Font"                 },
	{"SetFontColour"             , B2D_SetFontColour             , METH_VARARGS, "Set The Font Colour"                },
	{"SetFontSize"               , B2D_SetFontSize               , METH_VARARGS, "Set The Font Size"                  },
	{"DestroyFont"               , B2D_DestroyFont               , METH_VARARGS, "Destroy The Font"                   },
														         										             
    // GUI Button Functions								         										             
	{"CreateGUIButton"           , B2D_CreateGUIButton           , METH_VARARGS, "Create A New GUI Button"            },
	{"MoveGUIButton"             , B2D_MoveGUIButton             , METH_VARARGS, "Move The GUI Button"                },
	{"TranslateGUIButton"        , B2D_TranslateGUIButton        , METH_VARARGS, "Translate The GUI Button"           },
	{"ScaleGUIButton"            , B2D_ScaleGUIButton            , METH_VARARGS, "Scale The GUI Button"               },
	{"GetGUIButtonClick"         , B2D_GetGUIButtonClick         , METH_VARARGS, "Get Button Clicked"                 },
	{"GetGUIButtonOver"          , B2D_GetGUIButtonOver          , METH_VARARGS, "Get Mouse Over Button"              },
	{"DrawGUIButton"             , B2D_DrawGUIButton             , METH_VARARGS, "Draw GUI Button"                    },

	// Particle Effect Functions
	{"CreateParticleEmitterPoint", B2D_CreateParticleEmitterPoint, METH_VARARGS, "Create A New Point Particle Emitter"},
	{"CreateParticleEmitterLine" , B2D_CreateParticleEmitterLine , METH_VARARGS, "Create A New Line Particle Emitter" },
	{"SetEmissionRate"           , B2D_SetEmissionRate           , METH_VARARGS, "Set Point Emission Rate"            },
	{"SetMaxParticles"           , B2D_SetMaxParticles           , METH_VARARGS, "Set Max Particles"                  },
	{"SetParticleHealth"         , B2D_SetParticleHealth         , METH_VARARGS, "Set Particle Health"                },
	{"SetParticleSize"           , B2D_SetParticleSize           , METH_VARARGS, "Set Particle Size"                  },
	{"SetParticleVelocity"       , B2D_SetParticleVelocity       , METH_VARARGS, "Set Particle Velocity"              },
	{"ChangeParticleVelocity"    , B2D_ChangeParticleVelocity    , METH_VARARGS, "Change Particle Velocity"           },
	{"MoveParticle"              , B2D_MoveParticle              , METH_VARARGS, "Move The Particle"                  },
	{"DrawParticle"              , B2D_DrawParticle              , METH_VARARGS, "Draw The Particle"                  },
	{"DestroyParticle"           , B2D_DestroyParticle           , METH_VARARGS, "Destroy The Particle"               },

	// Primitive Functions
	{"CreateSquare"              , B2D_CreateSquare              , METH_VARARGS, "Create A New Square"                },
	{"DrawSquare"                , B2D_DrawSquare                , METH_VARARGS, "Draw Square"                        },
	{"MoveSquare"                , B2D_MoveSquare                , METH_VARARGS, "Move Square"                        },
	{"TranslateSquare"           , B2D_TranslateSquare           , METH_VARARGS, "Translate Square"                   },
	{"ScaleSquare"               , B2D_ScaleSquare               , METH_VARARGS, "Scale Square"                       },

	// Sprite Functions
	{"CreateSprite"              , B2D_CreateSprite              , METH_VARARGS, "Create A New Sprite"                },
	{"DrawSprite"                , B2D_DrawSprite                , METH_VARARGS, "Draw Sprite"                        },
	{"SwapSpriteTexture"         , B2D_SwapSpriteTexture         , METH_VARARGS, "Swap The Sprite Texture"            },
	{"PlaySpriteAnimation"       , B2D_PlaySpriteAnimation       , METH_VARARGS, "Play The Sprite Animation"          },
	{"SetSpriteFrame"            , B2D_SetSpriteFrame            , METH_VARARGS, "Set The Sprite Frame"               },
	{"StopSpriteAnimation"       , B2D_StopSpriteAnimation       , METH_VARARGS, "Stop The Animation"                 },
	{"ResumeSpriteAnimation"     , B2D_ResumeSpriteAnimation     , METH_VARARGS, "Resume The Animation"               },
	{"ReloadSprite"              , B2D_ReloadSprite              , METH_VARARGS, "Reload The Sprite"                  },
	{"MoveSprite"                , B2D_MoveSprite                , METH_VARARGS, "Move Sprite"                        },
	{"TranslateSprite"           , B2D_TranslateSprite           , METH_VARARGS, "Translate Sprite"                   },
	{"ScaleSprite"               , B2D_ScaleSprite               , METH_VARARGS, "Scale Sprite"                       },
	{"DestroySprite"             , B2D_DestroySprite             , METH_VARARGS, "Destroy The Sprite"                 },

	// Path Finding Functions
	{"CreatePathFinder"          , B2D_CreatePathFinder          , METH_VARARGS, "Create A Path Finder"               },
	{"PathFinderAddNode"         , B2D_PathFinderAddNode         , METH_VARARGS, "Add Node To Path Finder"            },
	{"CalculateAStar"            , B2D_CalculateAStar            , METH_VARARGS, "Create AStar Path"                  },
	{"CalculateDijkstra"         , B2D_CalculateDijkstra         , METH_VARARGS, "Create Dijkstra's Path"             },
	{"FollowPath"                , B2D_FollowPath                , METH_VARARGS, "Follow The Selected Path"           },

	// Input Functions
	{"GetMousePos"               , B2D_GetMousePos               , METH_VARARGS, "Get The Mouse Position"             },
	{"GetMouseButton"            , B2D_GetMouseButton            , METH_VARARGS, "Get Mouse Button Pressed"           },
	{"GetKey"                    , B2D_GetKey                    , METH_VARARGS, "Get Key Pressed"                    },

	// Collision Functions
	{"GetCollision"              , B2D_GetCollision              , METH_VARARGS, "Get Collision"                      },
	{NULL, NULL, 0, NULL} 
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Python Module Functions                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Functions Required To Load The Python Modules
void ParsePyTupleError (const char* Function, int Line){

	std::cout << "___Error Parsing Tuple___\nFunction : " <<  Function << "\nLine# : " << Line << std::endl;
	PyErr_Print();
}

// Import Python Module
PyObject* ImportPythonModule (const char* ModuleName){

	PyObject* objName = PyString_FromString (ModuleName);
	PyObject* module = PyImport_Import (objName);

	// Check If Module Exists
	if (!module){

		PyErr_Print();
        std::cout << stderr << "Failed to load \" " << ModuleName << "\"" << std::endl;
	}

	Py_DECREF (objName);
	return module;
}

// Get Handle To Python Function
PyObject* GetHandleToPythonFunction (PyObject* Module, const char* FunctionName){

    PyObject* function = PyObject_GetAttrString (Module, FunctionName);

	// Check For Error
	if (! (function && PyCallable_Check (function))){

		if (PyErr_Occurred()){
			PyErr_Print();
		}

		std::cout << stderr << "Cannot find function \"" << FunctionName << "\"" << std::endl;
	}

	return function;
}

// Call Python Function
PyObject* CallPythonFunction (PyObject* Function, PyObject* FunctionArguments){

	PyObject* returnValue = PyObject_CallObject (Function, FunctionArguments);

	// Check For Error
	if (returnValue == NULL){

		PyErr_Print();
		std::cout << stderr << "Call failed\n";
	}

	return returnValue;
}
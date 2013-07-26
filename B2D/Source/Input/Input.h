#ifndef INPUT_H
#define INPUT_H

#include <VML/Vector2/Vector2.h>
#include "../Rendering/Camera/Camera.h"

namespace b2d{

	// Input Type Defines
	typedef enum Key{

		KEY_UNKNOWN     = -1,
		KEY_SPACE       = 32,
        KEY_0           = 48,
        KEY_1           = 49,
        KEY_2           = 50,
        KEY_3           = 51,
        KEY_4           = 52,
        KEY_5           = 53,
        KEY_6           = 54,
        KEY_7           = 55,
        KEY_8           = 56,
        KEY_9           = 57,
        KEY_A           = 65,
        KEY_B           = 66,
        KEY_C           = 67,
        KEY_D           = 68,
        KEY_E           = 69,
        KEY_F           = 70,
        KEY_G           = 71,
        KEY_H           = 72,
        KEY_I           = 73,
        KEY_J           = 74,
        KEY_K           = 75,
        KEY_L           = 76,
        KEY_M           = 77,
        KEY_N           = 78,
        KEY_O           = 79,
        KEY_P           = 80,
        KEY_Q           = 81,
        KEY_R           = 82,
        KEY_S           = 83,
        KEY_T           = 84,
        KEY_U           = 85,
        KEY_V           = 86,
        KEY_W           = 87,
        KEY_X           = 88,
        KEY_Y           = 89,
        KEY_Z           = 90,
		KEY_SPECIAL	    = 256,
	    KEY_ESC         = (KEY_SPECIAL + 1),
	    KEY_F1          = (KEY_SPECIAL + 2),
	    KEY_F2          = (KEY_SPECIAL + 3),
	    KEY_F3          = (KEY_SPECIAL + 4),
	    KEY_F4          = (KEY_SPECIAL + 5),
	    KEY_F5          = (KEY_SPECIAL + 6),
	    KEY_F6          = (KEY_SPECIAL + 7),
	    KEY_F7          = (KEY_SPECIAL + 8),
	    KEY_F8          = (KEY_SPECIAL + 9),
	    KEY_F9          = (KEY_SPECIAL + 10),
	    KEY_F10         = (KEY_SPECIAL + 11),
	    KEY_F11         = (KEY_SPECIAL + 12),
	    KEY_F12         = (KEY_SPECIAL + 13),
	    KEY_F13         = (KEY_SPECIAL + 14),
	    KEY_F14         = (KEY_SPECIAL + 15),
	    KEY_F15         = (KEY_SPECIAL + 16),
	    KEY_F16         = (KEY_SPECIAL + 17),
	    KEY_F17         = (KEY_SPECIAL + 18),
	    KEY_F18         = (KEY_SPECIAL + 19),
	    KEY_F19         = (KEY_SPECIAL + 20),
	    KEY_F20         = (KEY_SPECIAL + 21),
	    KEY_F21         = (KEY_SPECIAL + 22),
	    KEY_F22         = (KEY_SPECIAL + 23),
	    KEY_F23         = (KEY_SPECIAL + 24),
	    KEY_F24         = (KEY_SPECIAL + 25),
	    KEY_F25         = (KEY_SPECIAL + 26),
	    KEY_UP          = (KEY_SPECIAL + 27),
	    KEY_DOWN        = (KEY_SPECIAL + 28),
	    KEY_LEFT        = (KEY_SPECIAL + 29),
	    KEY_RIGHT       = (KEY_SPECIAL + 30),
	    KEY_LSHIFT      = (KEY_SPECIAL + 31),
	    KEY_RSHIFT      = (KEY_SPECIAL + 32),
	    KEY_LCTRL       = (KEY_SPECIAL + 33),
	    KEY_RCTRL       = (KEY_SPECIAL + 34),
	    KEY_LALT        = (KEY_SPECIAL + 35),
	    KEY_RALT        = (KEY_SPECIAL + 36),
	    KEY_TAB         = (KEY_SPECIAL + 37),
	    KEY_ENTER       = (KEY_SPECIAL + 38),
	    KEY_BACKSPACE   = (KEY_SPECIAL + 39),
	    KEY_INSERT      = (KEY_SPECIAL + 40),
	    KEY_DEL         = (KEY_SPECIAL + 41),
	    KEY_PAGEUP      = (KEY_SPECIAL + 42),
	    KEY_PAGEDOWN    = (KEY_SPECIAL + 43),
	    KEY_HOME        = (KEY_SPECIAL + 44),
	    KEY_END         = (KEY_SPECIAL + 45),
	    KEY_KP_0        = (KEY_SPECIAL + 46),
	    KEY_KP_1        = (KEY_SPECIAL + 47),
	    KEY_KP_2        = (KEY_SPECIAL + 48),
	    KEY_KP_3        = (KEY_SPECIAL + 49),
	    KEY_KP_4        = (KEY_SPECIAL + 50),
	    KEY_KP_5        = (KEY_SPECIAL + 51),
	    KEY_KP_6        = (KEY_SPECIAL + 52),
	    KEY_KP_7        = (KEY_SPECIAL + 53),
	    KEY_KP_8        = (KEY_SPECIAL + 54),
	    KEY_KP_9        = (KEY_SPECIAL + 55),
	    KEY_KP_DIVIDE   = (KEY_SPECIAL + 56),
	    KEY_KP_MULTIPLY = (KEY_SPECIAL + 57),
	    KEY_KP_SUBTRACT = (KEY_SPECIAL + 58),
	    KEY_KP_ADD      = (KEY_SPECIAL + 59),
	    KEY_KP_DECIMAL  = (KEY_SPECIAL + 60),
	    KEY_KP_EQUAL    = (KEY_SPECIAL + 61),
	    KEY_KP_ENTER    = (KEY_SPECIAL + 62),
	    KEY_KP_NUM_LOCK = (KEY_SPECIAL + 63),
	    KEY_CAPS_LOCK   = (KEY_SPECIAL + 64),
	    KEY_SCROLL_LOCK = (KEY_SPECIAL + 65),
	    KEY_PAUSE       = (KEY_SPECIAL + 66),
	    KEY_LSUPER      = (KEY_SPECIAL + 67),
	    KEY_RSUPER      = (KEY_SPECIAL + 68),
	    KEY_MENU        = (KEY_SPECIAL + 69),
	    KEY_LAST        = KEY_MENU
	};

	typedef enum Mouse{

		MOUSE_LEFT        = 0,
		MOUSE_MIDDLE      = 2,
		MOUSE_RIGHT       = 1
	};

	// The Input Class
	class Input{
	public:

		static bool GetKey (b2d::Key Key);
		static bool GetMouseButton (b2d::Mouse Mouse);
		static Vector2::Point GetMousePosition();
	};
}

#endif
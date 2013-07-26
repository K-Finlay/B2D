#include "B2D.h"
#include <iostream>

int main(){

	b2d::Window::CreateGameWindow (b2d::System::GetDisplayWidth() / 1.5, b2d::System::GetDisplayHeight() / 1.5, "I am a window!", false, 0);

	b2d::Sprite testSprite (Vector2::Point (b2d::Window::screenWidth / 2, b2d::Window::screenHeight / 2), 128, 128, "./Image.png");
	b2d::Sprite testSprite2 (Vector2::Point (200, 200), 128, 128, "smileyanimated.png");

	b2d::Sound tSound ("./Music.mp3", true, false);
	b2d::Sound tSound2 ("./Music2.mp3", true, false);
	b2d::Sound tSound3 ("./Music2.mp3", true, false);

	b2d::Font testFont ("./SegoeKeycaps.TTF", "I am text!", 72, Vector2::Point (0, 0), RGBA (1, 0.5f, 0, 1), true, 0);
	b2d::Font testFont2 ("./andyb.ttf", "I am too!", 40, Vector2::Point (0, 0), RGBA (0, 0, 1, 1), false, 0);
	b2d::Font testFont3 ("./andyb.ttf", "Owain is a duck!", 40, Vector2::Point (0, 0), RGBA (1, 1, 1, 1), false, 0);

	b2d::Camera (0, 0, 0.5f);
	b2d::GUIButton button (b2d::Window::screenWidth / 2, b2d::Window::screenHeight / 2, 256, 128, "./btnNorm.png", "./btnOver.png");
	testSprite2.PlayAnimation (20, 0, 20, 0.1f);

	while (b2d::GameLoop() && !b2d::Input::GetKey (b2d::KEY_ESC)){

		b2d::Window::Clear();
		std::cout << b2d::Time::GetFPS() << '\n';

		testSprite2.Draw();
		testSprite.Draw();

		testFont.Move (-900 * b2d::Camera::zoom, -450 * b2d::Camera::zoom);
		testFont2.Move (testSprite2.position.x - 60, testSprite2.position.y - 70);
		testFont3.Move (testSprite.position.x - 60, testSprite.position.y - 70);

		testFont.Render();
		testFont2.Render();
		button.Draw();

		if (button.GetClick()){
			std::cout << "Button Clicked" << '\n';
		}

		if (b2d::Input::GetKey (b2d::KEY_ENTER)){
			b2d::Window::SetTitle ("You Pressed Enter!");
		}

		if (b2d::Input::GetKey (b2d::KEY_RCTRL)){
			b2d::Camera::Zoom (0.005f);
		}

		if (b2d::Input::GetKey (b2d::KEY_RALT)){
			b2d::Camera::Zoom (-0.005f);
		}

		if (b2d::Input::GetKey (b2d::KEY_O)){
			testSprite.canRender = true;
		}

		if (b2d::Input::GetKey (b2d::KEY_P)){
			testSprite.canRender = false;
		}

		if (b2d::Input::GetKey (b2d::KEY_LCTRL)){
			
			testSprite2.Scale (10.0f, 10.0f);
		}

	    if (b2d::Input::GetKey (b2d::KEY_LALT)){
			
			testSprite2.Scale (-10.0f, -10.0f);
		}

		if (b2d::Input::GetKey (b2d::KEY_4)){
			testSprite2.SwapTexture ("./Image.png");
		}

		if (b2d::Input::GetKey (b2d::KEY_5)){
			testSprite2.SwapTexture ("./Image2.png");
		}

		if (b2d::Input::GetKey (b2d::KEY_6)){
			testSprite2.SwapTexture ("./Image3.png");
		}

		if (b2d::Input::GetKey (b2d::KEY_D)){
			b2d::Camera::Translate (10, 0);
		}

		if (b2d::Input::GetKey (b2d::KEY_A)){
			b2d::Camera::Translate (-10, 0);
		}

		if (b2d::Input::GetKey (b2d::KEY_W)){
			b2d::Camera::Translate (0, -10);
		}

		if (b2d::Input::GetKey (b2d::KEY_S)){
			b2d::Camera::Translate (0, 10);
		}

		if (b2d::Input::GetKey (b2d::KEY_UP)){

			if (!b2d::Collision::GetCollision (testSprite.position, testSprite2.position, Vector2::Point (128, 128), Vector2::Point (128, 128))){
				
				testSprite2.Translate (0, -8, 0);
			}

			if (b2d::Collision::GetCollision (testSprite.position, testSprite2.position, Vector2::Point (128, 128), Vector2::Point (128, 128))){
			    
				testSprite2.Translate (0, 8, 0);
			}
		}

		if (b2d::Input::GetKey (b2d::KEY_DOWN)){

			if (!b2d::Collision::GetCollision (testSprite.position, testSprite2.position, Vector2::Point (128, 128), Vector2::Point (128, 128))){
				
				testSprite2.Translate (0, 8, 0);
			}

			if (b2d::Collision::GetCollision (testSprite.position, testSprite2.position, Vector2::Point (128, 128), Vector2::Point (128, 128))){
				
				testSprite2.Translate (0, -8, 0);
			}
		}

		if (b2d::Input::GetKey (b2d::KEY_RIGHT)){

			if (!b2d::Collision::GetCollision (testSprite.position, testSprite2.position, Vector2::Point (128, 128), Vector2::Point (128, 128))){
				
				testSprite2.Translate (8, 0, 8);
			}

			if (b2d::Collision::GetCollision (testSprite.position, testSprite2.position, Vector2::Point (128, 128), Vector2::Point (128, 128))){
				
				testSprite2.Translate (-8, 0, 0);
			}
		}

		if (b2d::Input::GetKey (b2d::KEY_LEFT)){

			if (!b2d::Collision::GetCollision (testSprite.position, testSprite2.position, Vector2::Point (128, 128), Vector2::Point (128, 128))){
				
				testSprite2.Translate (-8, 0, -8);
			}

			if (b2d::Collision::GetCollision (testSprite.position, testSprite2.position, Vector2::Point (128, 128), Vector2::Point (128, 128))){
				
				testSprite2.Translate (8, 0, 0);
			}
		}

		if (b2d::Input::GetKey (b2d::KEY_1)){

			if (tSound2.soundIsPlaying)
			    tSound2.Stop();

			if (tSound3.soundIsPlaying)
			    tSound3.Stop();

			tSound.Play();
		}

		if (b2d::Input::GetKey (b2d::KEY_2)){

			tSound.Stop();
			tSound3.Stop();
			tSound2.Play();
		}

		if (b2d::Input::GetKey (b2d::KEY_3)){

			tSound.Stop();
			tSound2.Stop();
			tSound3.Play();
		}

		if (b2d::Input::GetMouseButton (b2d::MOUSE_LEFT)){
			
			testSprite.Move (b2d::Input::GetMousePosition().x, b2d::Input::GetMousePosition().y, -Vector2::RotToPoint (testSprite.position, testSprite2.position));
			testFont3.Render();
		}

		else{
			
			testSprite.Move (testSprite.position.x, testSprite.position.y, -Vector2::RotToPoint (testSprite.position, testSprite2.position));
		}

		if (b2d::Collision::GetCollision (testSprite.position, testSprite2.position, Vector2::Point (128, 128), Vector2::Point (128, 128))){

			Vector2::Point test = b2d::Collision::GetCollisionPoint (testSprite.position, testSprite2.position, 128, 128);

			if (test.x > testSprite2.position.x + 20){
				
				testSprite2.Move (test.x - 64, testSprite2.position.y, testSprite2.rotation);
			}

			else if (test.x < testSprite2.position.x - 20){
				
				testSprite2.Move (test.x + 64, testSprite2.position.y, testSprite2.rotation);
			}

			if (test.y > testSprite2.position.y + 20){
				
				testSprite2.Move (testSprite2.position.x, test.y - 64, testSprite2.rotation);
			}

			else if (test.y < testSprite2.position.y - 20){
				
				testSprite2.Move (testSprite2.position.x, test.y + 64, testSprite2.rotation);
			}
		}
	}

	b2d::Window::Close();
	return 0;
}
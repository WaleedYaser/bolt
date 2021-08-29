#include <bolt/window.h>

#include <stdio.h>

static const char*
bolt_mouse_button_str(bolt::MOUSE_BUTTON button)
{
	switch(button)
	{
		case bolt::MOUSE_BUTTON_LEFT: return "left mouse button";
		case bolt::MOUSE_BUTTON_RIGHT: return "right mouse button";
		case bolt::MOUSE_BUTTON_MIDDLE: return "middle mouse button";
		case bolt::MOUSE_BUTTON_NONE: return "none";
	}
	return "none";
}

static const char*
bolt_key_str(bolt::KEY key)
{
	switch (key)
	{
		case bolt::KEY_0: return "0";
		case bolt::KEY_1: return "1";
		case bolt::KEY_2: return "2";
		case bolt::KEY_3: return "3";
		case bolt::KEY_4: return "4";
		case bolt::KEY_5: return "5";
		case bolt::KEY_6: return "6";
		case bolt::KEY_7: return "7";
		case bolt::KEY_8: return "8";
		case bolt::KEY_9: return "9";
		case bolt::KEY_A: return "a";
		case bolt::KEY_B: return "b";
		case bolt::KEY_C: return "c";
		case bolt::KEY_D: return "d";
		case bolt::KEY_E: return "e";
		case bolt::KEY_F: return "f";
		case bolt::KEY_G: return "g";
		case bolt::KEY_H: return "h";
		case bolt::KEY_I: return "i";
		case bolt::KEY_J: return "j";
		case bolt::KEY_K: return "k";
		case bolt::KEY_L: return "l";
		case bolt::KEY_M: return "m";
		case bolt::KEY_N: return "n";
		case bolt::KEY_O: return "o";
		case bolt::KEY_P: return "p";
		case bolt::KEY_Q: return "q";
		case bolt::KEY_R: return "r";
		case bolt::KEY_S: return "s";
		case bolt::KEY_T: return "t";
		case bolt::KEY_U: return "u";
		case bolt::KEY_V: return "v";
		case bolt::KEY_W: return "w";
		case bolt::KEY_X: return "x";
		case bolt::KEY_Y: return "y";
		case bolt::KEY_Z: return "z";
		case bolt::KEY_SPACE: return "space";
		case bolt::KEY_ENTER: return "enter";
		case bolt::KEY_ESCAPE: return "escape";
		case bolt::KEY_NONE: return "none";
	}
	return "none";
}

int
main()
{
	bolt::Window *window = bolt::window_create("Bolt example", 1280, 720);

	// game loop
	bool running = true;
	while (running)
	{
		// event loop
		while (bolt::window_poll(window))
		{
			switch (window->last_event.type)
			{
				case bolt::EVENT_TYPE_WINDOW_CLOSE:
					running = false;
					break;
				case bolt::EVENT_TYPE_MOUSE_BUTTON_PRESS:
					::printf("%s pressed\n",
						bolt_mouse_button_str(window->last_event.mouse_button_press.button));
					break;
				case bolt::EVENT_TYPE_MOUSE_BUTTON_RELEASE:
					::printf("%s released\n",
						bolt_mouse_button_str(window->last_event.mouse_button_press.button));
					break;
				case bolt::EVENT_TYPE_MOUSE_MOVE:
					::printf("mouse move: %d, %d\n",
						window->last_event.mouse_move.x,
						window->last_event.mouse_move.y);
					break;
				case bolt::EVENT_TYPE_MOUSE_WHEEL_SCROLL_DOWN:
					::printf("mouse wheel scroll down\n");
					break;
				case bolt::EVENT_TYPE_MOUSE_WHEEL_SCROLL_UP:
					::printf("mouse wheel scroll up\n");
					break;
				case bolt::EVENT_TYPE_KEY_PRESS:
					::printf("key %s press\n",
						bolt_key_str(window->last_event.key_press.key));
					break;
				case bolt::EVENT_TYPE_KEY_RELEASE:
					::printf("key %s released\n",
						bolt_key_str(window->last_event.key_release.key));
					break;
				case bolt::EVENT_TYPE_WINDOW_RESIZE:
					::printf("window resize: %d, %d\n",
						window->last_event.window_resize.width,
						window->last_event.window_resize.height);
					break;
				case bolt::EVENT_TYPE_NONE:
					// do nothing
					break;
			}
		}
	}

	bolt::window_destroy(window);
	return 0;
}

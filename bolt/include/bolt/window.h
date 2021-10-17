#pragma once

#include "bolt/exports.h"

#include <cstdint>

namespace bolt
{
	enum MOUSE_BUTTON
	{
		MOUSE_BUTTON_NONE,
		MOUSE_BUTTON_LEFT,
		MOUSE_BUTTON_RIGHT,
		MOUSE_BUTTON_MIDDLE,
	};

	enum KEY
	{
		KEY_NONE,
		// numbers
		KEY_0,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		// letters
		KEY_A,
		KEY_B,
		KEY_C,
		KEY_D,
		KEY_E,
		KEY_F,
		KEY_G,
		KEY_H,
		KEY_I,
		KEY_J,
		KEY_K,
		KEY_L,
		KEY_M,
		KEY_N,
		KEY_O,
		KEY_P,
		KEY_Q,
		KEY_R,
		KEY_S,
		KEY_T,
		KEY_U,
		KEY_V,
		KEY_W,
		KEY_X,
		KEY_Y,
		KEY_Z,
		// special keys
		KEY_SPACE,
		KEY_ENTER,
		KEY_ESCAPE,
	};

	enum EVENT_TYPE
	{
		EVENT_TYPE_NONE,
		// mouse events
		EVENT_TYPE_MOUSE_BUTTON_PRESS,
		EVENT_TYPE_MOUSE_BUTTON_RELEASE,
		EVENT_TYPE_MOUSE_WHEEL_SCROLL_DOWN,
		EVENT_TYPE_MOUSE_WHEEL_SCROLL_UP,
		EVENT_TYPE_MOUSE_MOVE,
		// keyboard events
		EVENT_TYPE_KEY_PRESS,
		EVENT_TYPE_KEY_RELEASE,
		// window events
		EVENT_TYPE_WINDOW_RESIZE,
		EVENT_TYPE_WINDOW_REPAINT,
		EVENT_TYPE_WINDOW_CLOSE
	};

	struct Event
	{
		EVENT_TYPE type;
		union
		{
			struct
			{
				MOUSE_BUTTON button;
			} mouse_button_press, mouse_button_release;

			struct
			{
				int x, y; // relative to the top right of the window client area
			} mouse_move;

			struct
			{
				KEY key;
			} key_press, key_release;

			struct
			{
				int width, height; // client area new size
			} window_resize;
		};
	};

	struct Window
	{
		// READ ONLY variables. don't change them by yourself, we handle them internally.
		void *native_handle;
		const char *title;
		int width, height;
		Event last_event;
	};

	union Pixel
	{
		struct { uint8_t b, g, r, a; };
		uint32_t as_uint; // 0xAARRGGBB
	};

	// create a new window
	//   title: string for window title
	//   width: int client area width
	//   height: int client area hight
	BOLT_EXPORT Window* window_create(const char *title, int width, int height);

	// destroy created window
	//   window: pointer to the created window
	BOLT_EXPORT void window_destroy(Window *window);

	// poll new events from window. if there are any it will return true ohterwise it will return false
	//   window: pointer to the window
	//   return: boolean that descripe if we still have unprocessed events in the queue to poll
	// the function will set window->last_event with the last event we successfully polled.
	BOLT_EXPORT bool window_poll(Window *window);

	// copy/stretch the pixels in to the window
	//   window: pointer to the window
	//   pixels: pointer to array of pixels [width * height]
	BOLT_EXPORT void window_blit(Window *window, Pixel *pixels, int width, int height);
}

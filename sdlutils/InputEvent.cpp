/*
 * InputEvent.cpp
 *
 *  Created on: Dec 22, 2021
 *      Author: ubuntu
 */

#include <cstdlib>
#include <iostream>

#include "SDL_events.h"

#include "InputEvent.h"

int32_t InputEvent::init() {
	sdlEvent = new SDL_Event{}; // Calling with "zero initializer" {}

	if (sdlEvent == nullptr) {
		std::cerr << "Bad allocation of SDL_Event" << std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void InputEvent::deinit() {
	if (sdlEvent != nullptr) {
		delete sdlEvent;
		sdlEvent = nullptr;
	}
}

bool InputEvent::poll() {
	if (SDL_PollEvent(sdlEvent) == 0) {
		return false;
	}

	SDL_GetMouseState(&pos.x, &pos.y);
	setEventTypeInternal();

	return true;
}

bool InputEvent::hasExitEvent() const {
	return sdlEvent->type == EventType::QUIT || key == Keyboard::KEY_ESCAPE;
}

void InputEvent::setEventTypeInternal() {
	switch (sdlEvent->type) {
	case EventType::KEYBOARD_PRESS:
		key = sdlEvent->key.keysym.sym;
		mouseButton = Mouse::UNKNOWN;
		touchEvent = TouchEvent::KEYBOARD_PRESS;
		break;

	case EventType::KEYBOARD_RELEASE:
		key = sdlEvent->key.keysym.sym;
		mouseButton = Mouse::UNKNOWN;
		touchEvent = TouchEvent::KEYBOARD_RELEASE;
		break;

	case EventType::MOUSE_PRESS:
		key = Keyboard::KEY_UNKNOWN;
		mouseButton = sdlEvent->button.button;
		touchEvent = TouchEvent::UNKNOWN;
		break;
	case EventType::FINGER_PRESS:
		key = Keyboard::KEY_UNKNOWN;
		mouseButton = Mouse::UNKNOWN;
		touchEvent = TouchEvent::TOUCH_PRESS;
		break;

	case EventType::MOUSE_RELEASE:
		key = Keyboard::KEY_UNKNOWN;
		mouseButton = sdlEvent->button.button;
		touchEvent = TouchEvent::UNKNOWN;
		break;
	case EventType::FINGER_RELEASE:
		key = Keyboard::KEY_UNKNOWN;
		mouseButton = Mouse::UNKNOWN;
		touchEvent = TouchEvent::TOUCH_RELEASE;
		break;

		//X is pressed on the window (or CTRL-C signal is sent)
	case EventType::QUIT:
	default:
		key = Keyboard::KEY_UNKNOWN;
		mouseButton = Mouse::UNKNOWN;
		touchEvent = TouchEvent::UNKNOWN;
		break;
	}
}

#pragma once

#include "Mode.hpp"

#include "MeshBuffer.hpp"
#include "GL.hpp"

#include <SDL.h>
#include <time.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <vector>
#include <chrono>
#include <random>

// The 'GameMode' mode is the main gameplay mode:

struct GameMode : public Mode {
	GameMode();
	virtual ~GameMode();

	//handle_event is called when new mouse or keyboard events are received:
	// (note that this might be many times per frame or never)
	//The function should return 'true' if it handled the event.
	virtual bool handle_event(SDL_Event const &evt, glm::uvec2 const &window_size) override;

	//update is called at the start of a new frame, after events are handled:
	virtual void update(float elapsed) override;

	//draw is called after update:
	virtual void draw(glm::uvec2 const &drawable_size) override;

	float camera_spin = 0.0f;
	float spot_spin = 0.0f;

	struct Controls{
		bool up = 0;
		bool down = 0;
		bool left = 0;
		bool right = 0;
	} controls;

	Controls prev_controls;

	std::vector< uint32_t > target_sequence;
	std::vector< uint32_t > interaction_record;
	bool reset_sequence = true;
	bool append_to_sequence = true;
	uint32_t index_to_play = 0; // which index of the sequence you're comparing against
	// float warmup = 0.0f;
	float delay_between_cubes = 0.5f;
	bool playing_target_sequence = false;
};

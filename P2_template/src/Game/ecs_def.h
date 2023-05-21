#pragma once

// se encuentra en un namespace
namespace ecs {
	// uint8_t indica que se trata de un entero representado en 8 bits
	using stateId_type = uint8_t;
	// estados que hay en el juego
	enum stateId : stateId_type {
		_s_MAIN_MENU,
		_s_PLAY,
		_s_PAUSE,
		_s_RESULTS,
		_s_GAMEOVER,

		_LAST_STATE_ID
	};
	constexpr stateId_type maxStateId = _LAST_STATE_ID;

	inline const char* ToString(stateId id)
	{
		switch (id)
		{
		case _s_MAIN_MENU:   return "Menu State";
		case _s_PLAY:   return "Play State";
		case _s_PAUSE: return "Pause State";
		case _s_RESULTS: return "Results State";
		case _s_GAMEOVER: return "Game Over State";
		}
	}

	using soundId_type = uint8_t;
	enum soundId : soundId_type {
		_sound_EXPLOSION,
		_sound_SCREAM,
		_sound_COIN,
		_sound_COIN_DROP,
		_sound_GAMEOVER,
		_sound_SKID,
		_sound_WINNER,
		_sound_SUPER_MARIO_COIN,
		_sound_CLICK,

		_LAST_SOUND_ID
	};
	constexpr soundId_type maxSoundId = _LAST_SOUND_ID;
}
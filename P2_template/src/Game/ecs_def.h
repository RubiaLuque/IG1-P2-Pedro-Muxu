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
		}
	}
}
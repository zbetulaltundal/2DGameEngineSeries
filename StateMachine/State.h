#pragma once

#include<SFML/System/Time.hpp>

namespace _engine
{
	// creating an asbtract state class
	class State
	{

	public:
		State() {};
		virtual ~State() {};

		virtual void Init() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(float deltaTime) = 0; // after getting input we will update the game
		virtual void Draw() = 0; // after updating we will draw our 

		virtual void Pause() {}; // will be called when user pauses the game
		virtual void Start() {}; //  will be called when user resumes the game
	};

};


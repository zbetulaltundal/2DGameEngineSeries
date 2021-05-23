#pragma once

#include <stack>
#include <memory>
#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include"State.h"

// container adaptar ?? 

namespace _engine
{
	typedef std::unique_ptr<State> StateRef;

	class StateManager
	{
		// private attributes
		std::stack<StateRef> stateStack;
		/* U CAN NOT COPY UNIQUE PTRS
			implicit call(ptr = new int) is not allowed,
			you need to call explicitly
		*/
		StateRef newState;

		bool isRemoving, isAdding, isReplacing;
	public:
		// constructor(s)
		StateManager();

		// destructor(s)
		~StateManager();

		// methods
		void PushState(StateRef toAdd, bool isReplacing);
		void PopState();
		void ProcessStateChange();

		// getters & setters
		StateRef & GetCurrent();
	};

};


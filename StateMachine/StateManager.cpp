#include "StateManager.h"

//constructor
_engine::StateManager::StateManager()
	: isRemoving(false), isAdding(false), isReplacing(false)
{
}

// destructor
_engine::StateManager::~StateManager()
{
}

// methods
void _engine::StateManager::PushState(StateRef toAdd, bool isReplacing)
{
	isAdding = true;
	this->isReplacing = isReplacing;

	// since toadd is a unique ptr, we can not use direct copy, we need to use std::move
	newState = std::move(toAdd);
}

void _engine::StateManager::PopState()
{
	isRemoving = true;
}

void _engine::StateManager::ProcessStateChange()
{
	if (isRemoving && !stateStack.empty()) {
		stateStack.pop();

		// ????
		if (!stateStack.empty()) {
			stateStack.top()->Start();
		}

		isRemoving = false;
	}

	if (isAdding) {
		if (!stateStack.empty()) {
			// if we want to replace current state
			if (isReplacing) {
				stateStack.pop(); // take off the curr state
			}
			else {
				stateStack.top()->Pause();// ????
			}
		}

		stateStack.push(std::move(newState));
		
		// new state completes its initialization before the update cycle starts
		stateStack.top()->Init();
		isAdding = false;
	}
}

std::unique_ptr<_engine::State>& _engine::StateManager::GetCurrent()
{
	return stateStack.top();
}
 
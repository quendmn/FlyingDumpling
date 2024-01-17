#pragma once

#include <memory>
#include <stack>
#include "State.hpp"

namespace Pelmen {
	typedef std::unique_ptr<State> StateRef;
	
	class StateMachine {
	public:
		StateMachine() {}
		~StateMachine() {}
		
		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();
		void ProcessStateChanges();

		StateRef& GetActiveState();

	private:
		std::stack<StateRef> states_;
		StateRef newState_;

		bool isRemoving_;
		bool isAdding_;
		bool isReplacing_;
	};
}
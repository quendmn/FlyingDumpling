#include "StateMachine.hpp"

namespace Pelmen
{
	// добавить новое состояние
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		this->isAdding_ = true;
		this->isReplacing_ = isReplacing;

		this->newState_ = std::move(newState);

	}

	//удалить состояние
	void StateMachine::RemoveState()
	{
		this->isRemoving_ = true;
	}

	// принять изменения состояний
	void StateMachine::ProcessStateChanges()
	{
		// удаление
		// если значение состояния = удаление и в стеке есть состояния,
		// то удаляем последний. если стек состояний не пуст - запускаем верхнеее, меняем
		// значение состояния на false
		//
		if (this->isRemoving_ && !this->states_.empty())
		{
			this->states_.pop();
			if (!this->states_.empty())
			{
				this->states_.top()->Resume();
			}

			this->isRemoving_ = false;
		}
		
		// добавление
		// если значение состояния = добавление, если состояния в стеке есть:
		// если хотим заменить текущее состояние, то удаляем его.
		// если не заменяем, то ставим текущее состояние на паузу добавляем новое состояние и 
		// инициализируем его, меняем значение состояния на false
		//
		if (this->isAdding_)
		{
			if (!this->states_.empty())
			{
				if (this->isReplacing_)
				{
					this->states_.pop();
				}
				else {
					this->states_.top()->Pause();
				}
			}

			this->states_.push(std::move(this->newState_));
			this->states_.top()->Init();
			this->isAdding_ = false;

		}
	}

	//вернуть новое текущее состояние
	StateRef& StateMachine::GetActiveState()
	{
		return this->states_.top();
	}
}
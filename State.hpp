#pragma once

namespace Pelmen
{
	class State
	{
	public:
		// инициализация 
		virtual void Init() = 0;

		//обработка ввода
		virtual void HandleInput() = 0;

		// обновление
		virtual void Update(float dt) = 0;

		// нарисовать объект
		virtual void Draw(float dt) = 0;

		// пауза
		virtual void Pause() {}

		// продолжить
		virtual void Resume() {}
	};
}
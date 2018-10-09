﻿#include "GameEngine.h"

GameEngine::GameEngine(std::string title)
{
	//Only let the application loop execute if window creation and renderer creation succeed

	int width, height;
	GameSettings::getDimensions(&width, &height);

	GameState::StateRequest firstState;
	firstState.popCurrent = false;
	firstState.popPrev = false;
	firstState.state = GameState::STATE_TITLE;

	//Window and rendering creation
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (m_window == NULL)
	{
		std::cout << "Window creation failed! Error: " << SDL_GetError() << std::endl;
		firstState.state = GameState::STATE_QUIT;
	}
	else
	{
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		 
		if (m_renderer == NULL)
		{
			std::cout << "Renderer creation failed! Error: " << SDL_GetError() << std::endl;
			firstState.state = GameState::STATE_QUIT;
		}
		else
		{
			SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
			stateMachine = new StateMachine(m_window);
			std::cout << "Engine construction successful!" << std::endl;
			stateMachine->setState(firstState);
		}
	}
}

GameEngine::~GameEngine()
{
	delete stateMachine;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void GameEngine::appLoop()
{
	//Loop the program until the state machine requests to quit or the user closes the program
	//Update and draw based on current game state
	while (stateMachine->getStateRequest().state != GameState::STATE_QUIT)
	{
		stateMachine->setState(stateMachine->getStateRequest());
		stateMachine->eventHandler();
		stateMachine->update();
		stateMachine->draw();
	}
}
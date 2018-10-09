#pragma once
#include "../UI/UIContainer.h"
#include "../Core/GameSettings.h"
#include "../UI/UIEditorBarButton.h"
class UIEditorBar:
	public UIContainer
{
public:
	UIEditorBar(SDL_Renderer* renderer);
	~UIEditorBar();

	enum Tools
	{
		TOOL_FILE,
		TOOL_PENCIL,
		TOOL_ERASER,
		TOOL_HAND,
		TOOL_PLAYER
	};

	void update() override;
	void draw() override;
	void SetX(int X);
	void SetY(int Y);
	Tools getSelected();

private:
	SDL_Rect m_drawRect;
	UIEditorBarButton* File;
	UIEditorBarButton* Pencil;
	UIEditorBarButton* Eraser;
	UIEditorBarButton* Hand;
	UIEditorBarButton* Player;
	int x, y;
	SDL_Rect highlight;
	Tools currentTool;
};


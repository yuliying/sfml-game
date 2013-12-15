#include "stdafx.h"
#include "GoalHole.h"
#include "Game.h"

GoalHole::GoalHole()
{
	Load("img/object.png");
	assert(IsLoaded());

	CenterOrigo();
}

GoalHole::~GoalHole()
{
}

void GoalHole::Update(float elapsedTime)
{
	PlayerObject* player = dynamic_cast<PlayerObject*>(Game::GetGameObjectManager().Get("Player"));

	if(player != NULL)
	{
		sf::Rect<float> playerRect = player->GetBoundingRect();
		if(playerRect.intersects(this->GetBoundingRect()))
			std::cout << "GoalHole intersects player\n";
	}
}
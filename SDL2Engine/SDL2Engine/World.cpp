#pragma region system include
#include <string>
#pragma endregion

#pragma region project include
#include "World.h"
#include "Config.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Player.h"
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

#pragma region public function
// initlialize world
void GWorld::Init()
{
	// world in chars
	string world;

	// 0 = background
	// X = dirt
	// W = way
	// L = lava
	// S = player start position
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX0S000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX0000000000000000000000000000000000000000WWWWWWWWW0000000000000000000000000000000000000000000XXXX\n";
	world += "XXXX0000000000WWW0000000000000000000000WWWWWXXXXXXXXXWWWWWWWW000000000000000000000000WWWWWWWWWWWXXXX\n";
	world += "XXXX00000WWWWWXXXWWWW0000000000000WWWWWXXXXXXXXXXXXXXXXXXXXXXWW000000000000000000WWWWXXXXXXXXXXXXXXX\n";
	world += "XXXXWWWWWXXXXXXXXXXXXWWWLWWWWLWWWWXXXXXXXXXXXXXXXXXXXXXXXXXXXXXWWWWWLWWWWWLWWWWWWXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

	// width and height
	int width = 0, height = 0;

	// check every char of world
	for (int i = 0; i < world.length(); i++)
	{
		// create textured entity
		CTexturedEntity* pObj = new CTexturedEntity(
			SVector2(width * BLOCK_WIDTH, height * BLOCK_HEIGHT),
			SVector2(BLOCK_WIDTH, BLOCK_HEIGHT),
			nullptr
		);

		// set texture of block
		pObj->SetTexture(m_pTexture);

		// add entity to ctm
		CTM->AddSceneEntity(pObj);

		// x position of texture in atlas texture
		int xPosInTexture = 0;

		// switch current char
		switch (world[i])
		{

		// X char (dirt)
		case 'X':
		{
			// set x position of texture in atlas
			xPosInTexture = 1 * BLOCK_ATLAS_WIDTH;

			// set collision type of dirt textured entity to static
			pObj->SetColType(ECollisionType::STATIC);
			break;
		}

		// W char (way)
		case 'W':
		{
			// set x position of texture in atlas
			xPosInTexture = 2 * BLOCK_ATLAS_WIDTH;

			// set collision type of way textured entity to static
			pObj->SetColType(ECollisionType::STATIC);
			break;
		}

		// L char (lava)
		case 'L':
		{
			// set x position of texture in atlas
			xPosInTexture = 3 * BLOCK_ATLAS_WIDTH;

			// set collision type of lava textured entity to static
			pObj->SetColType(ECollisionType::STATIC);
			break;
		}

		// S char (player start position)
		case 'S':
		{
			// create player
			GPlayer* pPlayer = new GPlayer(
				SVector2(width * BLOCK_WIDTH, height * BLOCK_HEIGHT),
				SVector2(BLOCK_WIDTH, BLOCK_HEIGHT),
				"Texture/Character/Player/T_Player.bmp"
			);

			// set player tag, collision type to dynamic and speed
			pPlayer->SetTag("Player");
			pPlayer->SetColType(ECollisionType::DYNAMIC);
			pPlayer->SetSpeed(PLAYER_SPEED);

			// add player to ctm
			CTM->AddPersistentEntity(pPlayer);
			break;
		}

		// default
		default:
			break;
		}

		// set source rect of current block
		pObj->SetSrcRect(SRect(BLOCK_ATLAS_WIDTH, BLOCK_ATLAS_HEIGHT, xPosInTexture, 0));

		// increase width
		width++;

		// if current char is new line
		if (world[i] == '\n')
		{
			// increase height and reset width
			height++;
			width = 0;
		}
	}
}
#pragma endregion
#pragma region project include
#include "MainScene.h"
#include "ContentManagement.h"
#include "Engine.h"
#include "TexturedEntity.h"
#include "Input.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMainScene::Init()
{
	// create player and background and add to ctm
	CTM->AddSceneEntity(new CTexturedEntity(SVector2(), SVector2(), "Texture/Environment/Background/T_Background.png"));
	m_pPlayer = new CTexturedEntity(SVector2(), SVector2(64.0, 64.0f), "Texture/Character/Player/T_Player.bmp");
	CTM->AddPersistentEntity(m_pPlayer);
	m_pEnemy = new CTexturedEntity(SVector2(720.0f - 64.0f, 500.0f), SVector2(64.0, 64.0f), "Texture/Character/Enemy/T_Enemy.bmp");
	CTM->AddPersistentEntity(m_pEnemy);
}

// update every frame
void GMainScene::Update(float _deltaTime)
{
	// if player near enemy remove enemy
	if (m_pPlayer->GetPosition().X >= 400.0f && m_pPlayer->GetPosition().X <= 564.0f &&
		m_pPlayer->GetPosition().Y >= 620.0f - 64.0f && m_pPlayer->GetPosition().Y <= 720.0f)
		CTM->RemoveEntity(m_pEnemy);

	// speed of player
	float speed = 250.0f * _deltaTime;

	// handle horizontal movement
	if (CInput::GetKey(SDL_SCANCODE_A))
		m_pPlayer->AddPosition(SVector2(-speed, 0.0f));
	else if (CInput::GetKey(SDL_SCANCODE_D))
		m_pPlayer->AddPosition(SVector2(speed, 0.0f));

	// if player has reached right end of screen set to left screen end
	if (m_pPlayer->GetPosition().X >= 1280.0f)
		m_pPlayer->SetPosition(SVector2(0.0f, m_pPlayer->GetPosition().Y));

	// add movement down
	if (m_pPlayer->GetPosition().Y <= 720.0f - 64.0f)
		m_pPlayer->AddPosition(SVector2(0.0f, 9.81f));

	// add movement up
	if (CInput::GetKeyDown(SDL_SCANCODE_SPACE))
		m_pPlayer->AddPosition(SVector2(0.0f, -300.0f));
}

// render every frame
void GMainScene::Render()
{

}

// clean scene
void GMainScene::Clean()
{
	
}
#pragma endregion
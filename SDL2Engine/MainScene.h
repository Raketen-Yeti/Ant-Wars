#pragma once

#pragma region project include
#include "Scene.h"
#include "Vector2.h"
#pragma endregion

#pragma region forward decleration
class CTexturedEntity;
#pragma endregion

/// <summary>
/// game main scene class
/// </summary>
class GMainScene : public CScene
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	GMainScene() : CScene() {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// initialize scene
	/// </summary>
	virtual void Init() override;

	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	virtual void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	virtual void Render() override;

	/// <summary>
	/// clean scene
	/// </summary>
	virtual void Clean() override;
#pragma endregion

#pragma region private pointer
	/// <summary>
	/// player texture
	/// </summary>
	CTexturedEntity* m_pPlayer = nullptr;

	/// <summary>
	/// enemy texture
	/// </summary>
	CTexturedEntity* m_pEnemy = nullptr;

	/// <summary>
	/// background texture
	/// </summary>
	CTexturedEntity* m_pBackground = nullptr;
#pragma endregion
};
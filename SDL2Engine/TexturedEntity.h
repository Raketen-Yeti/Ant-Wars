#pragma once

#pragma region project include
#include "Entity.h"
#include "Rect.h"
#pragma endregion

#pragma region forward decleration
class CTexture;
#pragma endregion

/// <summary>
/// entity class that can be rendered
/// </summary>
class CTexturedEntity : public CEntity
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of entity</param>
	/// <param name="_size">size of texture (x = width)</param>
	CTexturedEntity(SVector2 _pos = SVector2(), SVector2 _size = SVector2());

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of entity</param>
	/// <param name="_size">size of texture (x = width)</param>
	/// <param name="_pFileName">relative path name of texture</param>
	CTexturedEntity(SVector2 _pos, SVector2 _size, const char* _pFileName);
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	virtual ~CTexturedEntity()
	{
		// delete texture
		delete m_pTexture;
	}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	virtual void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	virtual void Render() override;
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get rect of texture
	/// </summary>
	/// <returns>rect of texture</returns>
	inline SRect GetRect() { return m_rect; }

	/// <summary>
	/// set rect of texture
	/// </summary>
	/// <param name="_rect">rect to set</param>
	inline void SetRect(SRect _rect) { m_rect = _rect; }
#pragma endregion

protected:
#pragma region protected variable
	/// <summary>
	/// rect of texture
	/// </summary>
	SRect m_rect = SRect();
#pragma endregion

#pragma region protected pointer
	/// <summary>
	/// texture reference
	/// </summary>
	CTexture* m_pTexture = nullptr;
#pragma endregion
};
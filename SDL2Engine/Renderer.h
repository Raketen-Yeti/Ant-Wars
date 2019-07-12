#pragma once

#include "Vector2.h"

#pragma region forward decleration
class SRect;
class CTexture;
class SDL_Window;
class SDL_Renderer;
#pragma endregion

/// <summary>
/// renderer class to render textures
/// </summary>
class CRenderer
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pWindow">sdl window reference</param>
	CRenderer(SDL_Window* _pWindow);
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	~CRenderer();
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get sdl renderer
	/// </summary>
	/// <returns>sdl renderer reference</returns>
	inline SDL_Renderer* GetSDLRenderer() { return m_pRenderer; }
#pragma endregion

#pragma region public funtion
	/// <summary>
	/// clear current screen
	/// </summary>
	void ClearScreen();

	/// <summary>
	/// render texture
	/// </summary>
	/// <param name="_pTexture">texture reference</param>
	/// <param name="_pDstRect">destination rect on screen reference</param>
	/// <param name="_pSrcRect">source rect of texture reference</param>
	/// <param name="_angle">angle of texture</param>
	/// <param name="_mirror">x != 0 than mirror horizontal, y != 0 than mirror vertical</param>
	void RenderTexture(CTexture* _pTexture, SRect* _pDstRect = nullptr, SRect* _pSrcRect = nullptr, 
		float _angle = 0.0f, SVector2 _mirror = SVector2());

	/// <summary>
	/// present rendered screen
	/// </summary>
	void Present();
#pragma endregion

private:
#pragma region private pointer
	/// <summary>
	/// sdl renderer reference
	/// </summary>
	SDL_Renderer* m_pRenderer = nullptr;
#pragma endregion
};
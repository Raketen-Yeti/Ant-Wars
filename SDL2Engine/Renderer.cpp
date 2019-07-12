#pragma region SDL2 include
#include <SDL.h>
#pragma endregion

#pragma region project include
#include "Renderer.h"
#include "Texture.h"
#include "Rect.h"
#pragma endregion

#pragma region constructor
// constructor
CRenderer::CRenderer(SDL_Window * _pWindow)
{
	// create renderer
	m_pRenderer = SDL_CreateRenderer(
		_pWindow,												// window reference
		-1,														// index
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC	// flags (F12)
	);
}
#pragma endregion

#pragma region destructor
// destructor
CRenderer::~CRenderer()
{
	SDL_DestroyRenderer(m_pRenderer);
}
#pragma endregion

#pragma region public function
// clear current screen
void CRenderer::ClearScreen()
{
	SDL_RenderClear(m_pRenderer);
}

// render texture
void CRenderer::RenderTexture(CTexture* _pTexture, SRect* _pDstRect, SRect* _pSrcRect, float _angle, SVector2 _mirror)
{
	// if texture not valid
	if (!_pTexture)
		return;

	// set rotation center point
	SDL_Point rotationPoint;

	// if destination rect valid
	if (_pDstRect)
	{
		// set rotation point
		rotationPoint.x = _pDstRect->w / 2;
		rotationPoint.y = _pDstRect->h / 2;
	}

	// if width or height of destination rect 0 set to nullptr
	if (_pDstRect && (!_pDstRect->h || !_pDstRect->w))
		_pDstRect = nullptr;
	
	// if width or height of source rect 0 set to nullptr
	if (_pSrcRect && (!_pSrcRect->h || !_pSrcRect->w))
		_pSrcRect = nullptr;

	// flip
	SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;

	// if mirror x not 0 and y 0 set flip to horizontal
	if (_mirror.X && !_mirror.Y)
		flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;

	// if mirror y not 0 and x 0 set flip to vertical
	else if (_mirror.Y && !_mirror.X)
		flip = SDL_RendererFlip::SDL_FLIP_VERTICAL;

	// if mirror x and mirror y not 0 add 180 angle
	// mirror horizontal and vertical is the same as 180 angle
	else if (_mirror.X && _mirror.Y)
		_angle += 180.0f;

	// render texture
	SDL_RenderCopyEx(
		m_pRenderer,				// sdl renderer reference
		_pTexture->GetSDLTexture(),	// sdl texture reference
		_pSrcRect,					// source rect of texture
		_pDstRect,					// destination rect to render to on screen
		_angle,						// angle of texture
		&rotationPoint,				// rotation point of angle
		flip						// mirror
	);
}

// present rendered screen
void CRenderer::Present()
{
	SDL_RenderPresent(m_pRenderer);
}
#pragma endregion
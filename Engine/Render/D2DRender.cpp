#include "pch.h"
#include "D2DRender.h"

HWND					D2DRender::m_hwnd = nullptr;
ID2D1Factory*			D2DRender::m_factory = nullptr;
IDWriteFactory*			D2DRender::m_writeFactory = nullptr;
IWICImagingFactory*		D2DRender::m_imgFactory = nullptr;
ID2D1HwndRenderTarget*  D2DRender::m_renderTarget = nullptr;
ID2D1SolidColorBrush*	D2DRender::m_brush = nullptr;
IDWriteTextFormat*		D2DRender::m_textFormat = nullptr;

void D2DRender::Initialize(HWND _hwnd)
{
	m_hwnd = _hwnd;

	HRESULT check;

	check = CoInitialize(NULL);

	// 팩토리 초기화
	check = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_factory);
	if (FAILED(check))
		assert(false);
	check = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&m_writeFactory));
	if (FAILED(check))
		assert(false);
	// Create WIC factory
	check = CoCreateInstance(
		CLSID_WICImagingFactory,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&m_imgFactory));
	// 렌더타겟 설정
	RECT rc;
	GetClientRect(m_hwnd, &rc);
	D2D1_SIZE_U size = D2D1::SizeU(
		rc.right - rc.left,
		rc.bottom - rc.top);

	check = m_factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(m_hwnd, size),
		&m_renderTarget);
	if (FAILED(check))
		assert(false);

	check = m_writeFactory->CreateTextFormat(
		L"맑은 고딕",                        // 폰트 이름
		nullptr,                            // 폰트 컬렉션 (nullptr은 기본 폰트 컬렉션)
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		20.0f,                              // 폰트 크기
		L"ko-kr",                           // 로캘(글씨 지역이름 설정이라는데 모르겠네요)
		&m_textFormat);
	if (FAILED(check))
		assert(false);

	// 기본 브러쉬 생성
	check = m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &m_brush);
	if (FAILED(check))
		assert(false);
}

void D2DRender::BeginDraw()
{
	m_renderTarget->BeginDraw();

	m_renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::CadetBlue));
}

void D2DRender::EndDraw()
{
	m_renderTarget->EndDraw();
}

void D2DRender::Release()
{
	if (m_factory) m_factory->Release();
	if (m_writeFactory) m_writeFactory->Release();
	if (m_imgFactory) m_imgFactory->Release();
	if (m_renderTarget) m_renderTarget->Release();
	if (m_textFormat) m_textFormat->Release();
	if (m_brush) m_brush->Release();
	CoUninitialize();
}

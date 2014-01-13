// UncheckyBHO.h : Declaration of the CUncheckyBHO

#pragma once

#include "resource.h"       // main symbols
#include <shlguid.h>        // IID_IWebBrowser2, DIID_DWebBrowserEvents2, etc.
#include <exdispid.h>       // DISPID_DOCUMENTCOMPLETE, etc.
#include <mshtml.h>
#include <mshtmdid.h>		// DISPID_HTMLDOCUMENTEVENTS2_ONCLICK etc.

#include "unchecky_bho_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

// CUncheckyBHO

DEFINE_GUID(CATID_AppContainerCompatible,
	0x59fb2056, 0xd625, 0x48d0, 0xa9, 0x44, 0x1a, 0x85, 0xb5, 0xab, 0x26, 0x40);

class ATL_NO_VTABLE CUncheckyBHO :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CUncheckyBHO, &CLSID_UncheckyBHO>,
	public IObjectWithSiteImpl<CUncheckyBHO>,
	public IDispatchImpl<IUncheckyBHO, &IID_IUncheckyBHO, &LIBID_unchecky_bhoLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispEventImpl<1, CUncheckyBHO, &DIID_DWebBrowserEvents2, &LIBID_SHDocVw, 1, 1>,
	public IDispEventImpl<2, CUncheckyBHO, &DIID_HTMLInputTextElementEvents2, &LIBID_MSHTML, 4, 0>,
	public CMessageMap
{
	typedef IDispEventImpl<1, CUncheckyBHO, &DIID_DWebBrowserEvents2, &LIBID_SHDocVw, 1, 1> IDWebBrowserEvents2Impl;
	typedef IDispEventImpl<2, CUncheckyBHO, &DIID_HTMLInputTextElementEvents2, &LIBID_MSHTML, 4, 0> IHTMLInputTextElementEvents2Impl;

public:
	CUncheckyBHO() : m_wndMsg(L"Static", this)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_UNCHECKYBHO)

DECLARE_NOT_AGGREGATABLE(CUncheckyBHO)

BEGIN_COM_MAP(CUncheckyBHO)
	COM_INTERFACE_ENTRY(IUncheckyBHO)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	BEGIN_SINK_MAP(CUncheckyBHO)
		SINK_ENTRY_EX(1, DIID_DWebBrowserEvents2, DISPID_DOCUMENTCOMPLETE, OnDocumentComplete)
		SINK_ENTRY_EX(2, DIID_HTMLInputTextElementEvents2, DISPID_HTMLELEMENTEVENTS2_ONCLICK, OnMouseClick)
	END_SINK_MAP()

public:
	STDMETHOD(SetSite)(IUnknown *pUnkSite);

	// DWebBrowserEvents2
	void STDMETHODCALLTYPE OnDocumentComplete(IDispatch *pDisp, VARIANT *pvarURL);

	// HTMLInputTextElementEvents2
	void STDMETHODCALLTYPE OnMouseClick(IHTMLEventObj *pEvtObj);

	BEGIN_MSG_MAP(CUncheckyBHO)
		MESSAGE_HANDLER(WM_TIMER, OnTimer)
	END_MSG_MAP()

	LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);

private:
	CComPtr<IWebBrowser2> m_spWebBrowser;
	CComPtr<IHTMLElement> m_spAdvisedCheckbox;
	BOOL m_fAdvised = FALSE, m_fCheckboxAdvised = FALSE;
	CContainedWindow m_wndMsg;
	BOOL m_bTimerRunning = FALSE;

	void StartTimer(UINT nElapse);
	void EndTimer();
	void CheckboxAdvise(IHTMLElement *elementCheckbox);
	void CheckboxUnadvise();

	bool IsAdobePage(BSTR bsUrl, IHTMLDocument2 *pDocument);
	void HandleAdobePage(BSTR bsUrl, IHTMLDocument2 *pDocument);
};

OBJECT_ENTRY_AUTO(__uuidof(UncheckyBHO), CUncheckyBHO)

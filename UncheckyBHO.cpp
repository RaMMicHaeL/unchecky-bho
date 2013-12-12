// UncheckyBHO.cpp : Implementation of CUncheckyBHO

#include "stdafx.h"
#include "UncheckyBHO.h"

// CUncheckyBHO

STDMETHODIMP CUncheckyBHO::SetSite(IUnknown* pUnkSite)
{
	if(pUnkSite != NULL)
	{
		// Cache the pointer to IWebBrowser2.
		HRESULT hr = pUnkSite->QueryInterface(IID_IWebBrowser2, (void **)&m_spWebBrowser);
		if(SUCCEEDED(hr))
		{
			// Register to sink events from DWebBrowserEvents2.
			hr = IDWebBrowserEvents2Impl::DispEventAdvise(m_spWebBrowser);
			if(SUCCEEDED(hr))
			{
				m_fAdvised = TRUE;

				m_wndMsg.Create(HWND_MESSAGE, CWindow::rcDefault);
			}
		}
	}
	else
	{
		// Unregister event sink.
		if(m_fAdvised)
		{
			IDWebBrowserEvents2Impl::DispEventUnadvise(m_spWebBrowser);
			m_fAdvised = FALSE;

			if(m_wndMsg)
				m_wndMsg.DestroyWindow();
		}

		// Release cached pointers and other resources here.
		m_spWebBrowser.Release();
	}

	// Return the base class implementation
	return IObjectWithSiteImpl<CUncheckyBHO>::SetSite(pUnkSite);
}

void STDMETHODCALLTYPE CUncheckyBHO::OnDocumentComplete(IDispatch *pDisp, VARIANT *pvarURL)
{
/*
	// Retrieve the top-level window from the site.
	HWND hwnd;
	HRESULT hr = m_spWebBrowser->get_HWND((LONG_PTR*)&hwnd);
	if(SUCCEEDED(hr))
	{
		// Output a message box when page is loaded.
		MessageBox(hwnd, L"Hello World!", L"BHO", MB_OK);
	}*/

	HRESULT hr = S_OK;

	// Query for the IWebBrowser2 interface.
	CComQIPtr<IWebBrowser2> spTempWebBrowser = pDisp;

	// Is this event associated with the top-level browser?
	if(spTempWebBrowser && m_spWebBrowser &&
		m_spWebBrowser.IsEqualObject(spTempWebBrowser))
	{
		EndTimer();

		CComBSTR bsUrl;
		hr = m_spWebBrowser->get_LocationURL(&bsUrl);
		if(SUCCEEDED(hr))
		{
			// Get the current document object from browser...
			CComPtr<IDispatch> spDispDoc;
			hr = m_spWebBrowser->get_Document(&spDispDoc);
			if(SUCCEEDED(hr))
			{
				// ...and query for an HTML document.
				CComQIPtr<IHTMLDocument2> spHTMLDoc = spDispDoc;
				if(spHTMLDoc != NULL)
				{
					// Finally, handle the page.
					if(IsAdobePage(bsUrl, spHTMLDoc))
					{
						HandleAdobePage(bsUrl, spHTMLDoc);
						StartTimer(200);
					}
				}
			}
		}
	}
}

void STDMETHODCALLTYPE CUncheckyBHO::OnMouseClick(IHTMLEventObj *eventObj)
{
	// I'd like to show a message box here, but
	// things go wrong when I use this event
}

LRESULT CUncheckyBHO::OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
	HRESULT hr;

	if(m_spWebBrowser)
	{
		CComBSTR bsUrl;
		hr = m_spWebBrowser->get_LocationURL(&bsUrl);
		if(SUCCEEDED(hr))
		{
			// Get the current document object from browser...
			CComPtr<IDispatch> spDispDoc;
			hr = m_spWebBrowser->get_Document(&spDispDoc);
			if(SUCCEEDED(hr))
			{
				// ...and query for an HTML document.
				CComQIPtr<IHTMLDocument2> spHTMLDoc = spDispDoc;
				if(spHTMLDoc != NULL)
				{
					// Finally, handle the page.
					HandleAdobePage(bsUrl, spHTMLDoc);
				}
			}
		}
	}

	return 0;
}

void CUncheckyBHO::StartTimer(UINT nElapse)
{
	if(m_wndMsg)
		m_wndMsg.SetTimer(1, nElapse);
}

void CUncheckyBHO::EndTimer()
{
	if(m_wndMsg)
		m_wndMsg.KillTimer(1);
}

bool CUncheckyBHO::IsAdobePage(BSTR bsUrl, IHTMLDocument2 *pDocument)
{
	WCHAR *p = bsUrl;

	if(_wcsnicmp(p, L"http://", sizeof("http://") - 1) == 0)
	{
		p += sizeof("http://") - 1;
	}
	else if(_wcsnicmp(p, L"https://", sizeof("https://") - 1) == 0)
	{
		p += sizeof("https://") - 1;
	}
	else
		return false;

	if(_wcsnicmp(p, L"get.adobe.com/", sizeof("get.adobe.com/") - 1) == 0)
	{
		p += sizeof("get.adobe.com") - 1;
	}
	else
		return false;

	if(!wcsstr(p, L"/flashplayer/") && !wcsstr(p, L"/reader/"))
		return false;

	return true;
}

void CUncheckyBHO::HandleAdobePage(BSTR bsUrl, IHTMLDocument2 *pDocument)
{
	HRESULT hr;

	CComQIPtr<IHTMLDocument3> document3 = pDocument;
	ATLENSURE_RETURN_VAL(document3, );

	CComPtr<IHTMLElement> elementCheckbox;
	hr = document3->getElementById(CComBSTR(L"offerCheckbox"), &elementCheckbox);
	ATLENSURE_RETURN_VAL(SUCCEEDED(hr), );

	if(!elementCheckbox)
	{
		return;
	}

	CComQIPtr<IHTMLInputElement> inputElementCheckbox = elementCheckbox;
	ATLENSURE_RETURN_VAL(inputElementCheckbox, );

	VARIANT_BOOL isChecked;
	hr = inputElementCheckbox->get_checked(&isChecked);
	ATLENSURE_RETURN_VAL(SUCCEEDED(hr), );

	if(!isChecked)
	{
		return;
	}

	elementCheckbox->click();

	CComPtr<IHTMLElement> elementParent;
	hr = elementCheckbox->get_parentElement(&elementParent);
	if(SUCCEEDED(hr) && elementParent)
	{
		// Register to sink events from HTMLDocumentEvents2.
		//hr = IHTMLElementEvents2Impl::DispEventAdvise(elementParent);
		//ATLASSERT(SUCCEEDED(hr));
	}
}

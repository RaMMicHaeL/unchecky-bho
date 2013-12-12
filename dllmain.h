// dllmain.h : Declaration of module class.

class Cunchecky_bhoModule : public ATL::CAtlDllModuleT< Cunchecky_bhoModule >
{
public :
	DECLARE_LIBID(LIBID_unchecky_bhoLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_UNCHECKY_BHO, "{CACACE19-B2A2-4623-B47A-BE7F66D73D25}")
};

extern class Cunchecky_bhoModule _AtlModule;

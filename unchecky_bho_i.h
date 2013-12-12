

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Dec 06 16:55:22 2013
 */
/* Compiler settings for unchecky_bho.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __unchecky_bho_i_h__
#define __unchecky_bho_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUncheckyBHO_FWD_DEFINED__
#define __IUncheckyBHO_FWD_DEFINED__
typedef interface IUncheckyBHO IUncheckyBHO;
#endif 	/* __IUncheckyBHO_FWD_DEFINED__ */


#ifndef __UncheckyBHO_FWD_DEFINED__
#define __UncheckyBHO_FWD_DEFINED__

#ifdef __cplusplus
typedef class UncheckyBHO UncheckyBHO;
#else
typedef struct UncheckyBHO UncheckyBHO;
#endif /* __cplusplus */

#endif 	/* __UncheckyBHO_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IUncheckyBHO_INTERFACE_DEFINED__
#define __IUncheckyBHO_INTERFACE_DEFINED__

/* interface IUncheckyBHO */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IUncheckyBHO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2582D9B0-5E53-492D-A894-9F0FCB088C4C")
    IUncheckyBHO : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IUncheckyBHOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUncheckyBHO * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUncheckyBHO * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUncheckyBHO * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUncheckyBHO * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUncheckyBHO * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUncheckyBHO * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUncheckyBHO * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IUncheckyBHOVtbl;

    interface IUncheckyBHO
    {
        CONST_VTBL struct IUncheckyBHOVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUncheckyBHO_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUncheckyBHO_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUncheckyBHO_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUncheckyBHO_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUncheckyBHO_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUncheckyBHO_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUncheckyBHO_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUncheckyBHO_INTERFACE_DEFINED__ */



#ifndef __unchecky_bhoLib_LIBRARY_DEFINED__
#define __unchecky_bhoLib_LIBRARY_DEFINED__

/* library unchecky_bhoLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_unchecky_bhoLib;

EXTERN_C const CLSID CLSID_UncheckyBHO;

#ifdef __cplusplus

class DECLSPEC_UUID("89CB800E-E9FA-450F-B4A4-7009B7881EFD")
UncheckyBHO;
#endif
#endif /* __unchecky_bhoLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



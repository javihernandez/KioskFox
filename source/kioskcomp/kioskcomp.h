/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM kioskcomp.idl
 */

#ifndef __gen_kioskcomp_h__
#define __gen_kioskcomp_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    kioskcomp */
#define KIOSKCOMP_IID_STR "43580558-ee89-41cc-8958-3bcfb54534a5"

#define KIOSKCOMP_IID \
  {0x43580558, 0xee89, 0x41cc, \
    { 0x89, 0x58, 0x3b, 0xcf, 0xb5, 0x45, 0x34, 0xa5 }}

class NS_NO_VTABLE NS_SCRIPTABLE kioskcomp : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(KIOSKCOMP_IID)

  /* void LockDialogs (); */
  NS_SCRIPTABLE NS_IMETHOD LockDialogs(void) = 0;

  /* void UnlockDialogs (); */
  NS_SCRIPTABLE NS_IMETHOD UnlockDialogs(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(kioskcomp, KIOSKCOMP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_KIOSKCOMP \
  NS_SCRIPTABLE NS_IMETHOD LockDialogs(void); \
  NS_SCRIPTABLE NS_IMETHOD UnlockDialogs(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_KIOSKCOMP(_to) \
  NS_SCRIPTABLE NS_IMETHOD LockDialogs(void) { return _to LockDialogs(); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockDialogs(void) { return _to UnlockDialogs(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_KIOSKCOMP(_to) \
  NS_SCRIPTABLE NS_IMETHOD LockDialogs(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockDialogs(); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockDialogs(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnlockDialogs(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public kioskcomp
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_KIOSKCOMP

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, kioskcomp)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void LockDialogs (); */
NS_IMETHODIMP _MYCLASS_::LockDialogs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void UnlockDialogs (); */
NS_IMETHODIMP _MYCLASS_::UnlockDialogs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_kioskcomp_h__ */

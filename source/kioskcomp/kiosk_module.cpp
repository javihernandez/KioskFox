#include "nsIGenericFactory.h"
#include "kiosk_impl.h"

#pragma comment(lib,"xulrunner-sdk\\sdk\\lib\\nspr4.lib")
#pragma comment(lib,"xulrunner-sdk\\sdk\\lib\\xpcomglue.lib")
#pragma comment(lib,"xulrunner-sdk\\sdk\\lib\\xpcomglue_s.lib")
#pragma comment(lib,"xulrunner-sdk\\sdk\\lib\\plds4.lib ")
#pragma comment(lib,"xulrunner-sdk\\sdk\\lib\\plc4.lib")
#pragma comment(lib,"xulrunner-sdk\\sdk\\lib\\xpcom.lib")
 
NS_GENERIC_FACTORY_CONSTRUCTOR(CKioskComponent)

static nsModuleComponentInfo components[] =
{
  {
    KIOSK_CLASSNAME,
    KIOSK_CID,
    KIOSK_CONTRACTID,
    CKioskComponentConstructor,
  }
};

NS_IMPL_NSGETMODULE("kiosk_module",components)
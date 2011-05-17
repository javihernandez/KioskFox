#ifndef KIOSK_IMPL_H
#define KIOSK_IMPL_H

#include "kioskcomp.h"
#include <windows.h>

#define KIOSK_CONTRACTID "@ohnull.com/kioskfox/lockcomponent;1"
#define KIOSK_CLASSNAME  "Windows Kiosk Locker"
#define KIOSK_CID {0xc73a7b81,0xf94e,0x447e,{0x83,0xa9,0x94,0x3f,0xc2,0xc3,0x30,0x6}}

/* Header file */
class CKioskComponent : public kioskcomp
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_KIOSKCOMP
  CKioskComponent();

private:
  ~CKioskComponent();

protected:
  /* additional members */
};

#endif
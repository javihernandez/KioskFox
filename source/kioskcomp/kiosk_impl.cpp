#include "kiosk_impl.h"
#include <windows.h>
#include <stdio.h>

/* Implementation file */
NS_IMPL_ISUPPORTS1(CKioskComponent, kioskcomp)

CKioskComponent::CKioskComponent()
{
  /* member initializers and constructor code */
}

CKioskComponent::~CKioskComponent()
{
  /* destructor code */
}

/* void LockDialogs (); */
NS_IMETHODIMP CKioskComponent::LockDialogs()
{
	const char* szFunctions[] = {
                                "GetOpenFileNameA", "GetOpenFileNameW",
                                "GetSaveFileNameA", "GetSaveFileNameW",
                                "PrintDlgA", "PrintDlgW",
                                "PrintDlgExA", "PrintDlgExW" 
                              };

	const unsigned char szPatchBytes[] = {0x31,0xC0,0xC2,0x04,0x00};

	const unsigned int FUNC_COUNT = sizeof(szFunctions) / sizeof(szFunctions[0]);
	const unsigned int BYTE_COUNT = sizeof(szPatchBytes)/ sizeof(szPatchBytes[0]);

	HMODULE hComDlg32 = GetModuleHandle(L"comdlg32.dll");
	if(hComDlg32 == NULL) {
		printf("Failed to get module handle to comdlg32.dll\n");
  }else{
	  for(unsigned int i = 0; i < FUNC_COUNT; ++i) 
    {
	    DWORD* dwFuncAddr = (DWORD*)GetProcAddress(hComDlg32,szFunctions[i]);
	    DWORD dwOldProt;

		  if(dwFuncAddr == NULL) {
			  printf("Failed to get function address to %s.\n",szFunctions[i]);
			  continue;
      }

      if(VirtualProtect(dwFuncAddr,BYTE_COUNT,PAGE_EXECUTE_READWRITE,&dwOldProt)) {
		    printf("Patching %s at 0x%X\n",szFunctions[i],dwFuncAddr);
		    memcpy((void*)dwFuncAddr,(void*)szPatchBytes,BYTE_COUNT);
      }else{
        printf("Failed to change page attributes containing function %s.",szFunctions[i]);
      }
    }
  }

	return NS_OK;
}

/* void UnlockDialogs (); */
NS_IMETHODIMP CKioskComponent::UnlockDialogs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
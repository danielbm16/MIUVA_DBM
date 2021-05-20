#ifndef _MPUSBAPI_H_
#define _MPUSBAPI_H_

#define	MPUSB_FAIL                  0
#define MPUSB_SUCCESS               1

#define MP_WRITE                    0
#define MP_READ                     1

// MAX_NUM_MPUSB_DEV is an abstract limitation.
// It is very unlikely that a computer system will have more
// then 127 USB devices attached to it. (single or multiple USB hosts)
#define MAX_NUM_MPUSB_DEV           127

extern "C" __declspec(dllexport)
DWORD MPUSBGetDLLVersion(void);

extern "C" __declspec(dllexport)
DWORD MPUSBGetDeviceCount(PCHAR pVID_PID);

extern "C" __declspec(dllexport)
HANDLE MPUSBOpen(DWORD instance,    // Input
                 PCHAR pVID_PID,    // Input
                 PCHAR pEP,         // Input
                 DWORD dwDir,       // Input
                 DWORD dwReserved); // Input <Future Use>

extern "C" __declspec(dllexport)
DWORD MPUSBRead(HANDLE handle,              // Input
                PVOID pData,                // Output
                DWORD dwLen,                // Input
                PDWORD pLength,             // Output
                DWORD dwMilliseconds);      // Input

extern "C" __declspec(dllexport)
DWORD MPUSBWrite(HANDLE handle,             // Input
                 PVOID pData,               // Input
                 DWORD dwLen,               // Input
                 PDWORD pLength,            // Output
                 DWORD dwMilliseconds);     // Input

extern "C" __declspec(dllexport)
DWORD MPUSBReadInt(HANDLE handle,           // Input
                   PVOID pData,             // Output
                   DWORD dwLen,             // Input
                   PDWORD pLength,          // Output
                   DWORD dwMilliseconds);   // Input

extern "C" __declspec(dllexport)
BOOL MPUSBClose(HANDLE handle);

extern "C" __declspec(dllexport)
DWORD MPUSBReadInt(HANDLE handle,           // Input
                   PVOID pData,             // Output
                   DWORD dwLen,             // Input
                   PDWORD pLength,          // Output
                   DWORD dwMilliseconds);   // Input

extern "C" __declspec(dllexport)
DWORD MPUSBGetConfigInfo(HANDLE handle,         // Input
                         PVOID pData,           // Output
                         DWORD dwLen);           // Input

#endif

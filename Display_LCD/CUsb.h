// Clase USB
#include <windows.h>
#include "usb2550.h"
#pragma once
#if !defined(AFX_USB_H__801FD7DD_554C_4197_A9AF_6A4FC934E5FA__INCLUDED_)
#define AFX_USB_H__801FD7DD_554C_4197_A9AF_6A4FC934E5FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif
class CUsb
{

public:
	void ClosePipes();
	void OpenPipes();
	CUsb();
	virtual ~CUsb();
	void ReceivePacket(BYTE *ReceiveData, DWORD ReceiveLength1);
	void ReceivePacket(/*PVOID*/BYTE* ReceiveData, DWORD ReceiveLength1, DWORD ReceiveLength2);
	void SendPacket(BYTE *SendData, DWORD SendLength);
	void SendPacket(BYTE* SendData, DWORD SendLength, DWORD SendLength2);
};
#endif

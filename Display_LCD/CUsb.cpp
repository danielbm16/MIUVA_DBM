// USB.cpp: implementation of the USB class.
//
//////////////////////////////////////////////////////////////////////
#include "pch.h"
#include "CUsb.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif


//***********************************************************************************************

//#pragma argsused

// Global Vars //Se definieron como atributos en lugar de variables globales

PCHAR vid_pid = (PCHAR) "vid_04d8&pid_0011";
PCHAR out_pipe = (PCHAR) "\\MCHP_EP1";
PCHAR in_pipe = (PCHAR) "\\MCHP_EP1";
HANDLE myOutPipe;
HANDLE myInPipe;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUsb::CUsb()
{
	myOutPipe = myInPipe = NULL;//Esta instrucción se encuentra en el método Initialice
	//PCHAR vid_pid = "vid_04d8&pid_0011";
	//PCHAR out_pipe = "\\MCHP_EP1";
	//PCHAR in_pipe = "\\MCHP_EP1";
}

CUsb::~CUsb()
{

}

void CUsb::OpenPipes()
{
	DWORD selection = 0;

	myOutPipe = MPUSBOpen(selection, vid_pid, out_pipe, 0, 0);
	myInPipe = MPUSBOpen(selection, vid_pid, in_pipe, 1, 0);
}


void CUsb::ClosePipes()
{
	MPUSBClose(myOutPipe);
	MPUSBClose(myInPipe);
}

void CUsb::SendPacket(BYTE *SendData, DWORD SendLength)
{
	DWORD SendDelay = 1000;

	DWORD SentDataLength;

	OpenPipes();
	MPUSBWrite(myOutPipe, (void*)SendData, SendLength, &SentDataLength, SendDelay);
	ClosePipes();
}

/*******************************************************************************************
Esta función recibe del PIC los datos "RecieveData" y la longitud de la cadena "RecieveLenght"
Los otros datos de MPUSBRead los imponemos nosotros, dichos datos del PIC se reciben con la función
usb_put_packet(endpoint,*ptr,len,toggle)
********************************************************************************************/


void CUsb::SendPacket(BYTE* SendData, DWORD SendLength, DWORD SendLength2)
{
	DWORD SendDelay = 1000;
	//DWORD SendDelay = 10;
	DWORD SentDataLength;
	DWORD SentDataLength2;

	OpenPipes();
	MPUSBWrite(myOutPipe, (void*)SendData, SendLength, &SentDataLength, SendDelay);
	MPUSBWrite(myOutPipe, (void*)SendData, SendLength2, &SentDataLength2, SendDelay);
	ClosePipes();
}

void CUsb::ReceivePacket(BYTE* ReceiveData, DWORD ReceiveLength1, DWORD ReceiveLength2)
{
	PDWORD ReceiveLength = &ReceiveLength1;
	PDWORD ReceiveLengthb = &ReceiveLength2;
	DWORD ReceiveDelay = 1000;
	DWORD ExpectedReceiveLength = ReceiveLength1;
	DWORD ExpectedReceiveLengthb = ReceiveLength2;

	OpenPipes();
	MPUSBRead(myInPipe, (void*)ReceiveData, ExpectedReceiveLength, ReceiveLength, ReceiveDelay);
	MPUSBRead(myInPipe, (void*)ReceiveData, ExpectedReceiveLengthb, ReceiveLengthb, ReceiveDelay);

	ClosePipes();
}

void CUsb::ReceivePacket(BYTE *ReceiveData, DWORD ReceiveLength1)
{
	PDWORD ReceiveLength = &ReceiveLength1;
	DWORD ReceiveDelay = 1000;
	DWORD ExpectedReceiveLength = ReceiveLength1;

	OpenPipes();
	MPUSBRead(myInPipe, (void*)ReceiveData, ExpectedReceiveLength, ReceiveLength, ReceiveDelay);

	ClosePipes();
}

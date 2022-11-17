#pragma warning (disable : 4100 4047 4024 6273 4311)

#include "events.h"
#include "Messages.h"
#include "Data.h"



PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallBack(PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo)
{
	
	//DebugMessage("ImageLoaded: %ls \n", FullImageName->Buffer);

	if (wcsstr(FullImageName->Buffer, L"\\Counter-Strike Global Offensive\\csgo\\bin\\client.dll"))
	{
		DebugMessage("CSGO Client.dll file found!");

		CSGOClientDLLAddress = ImageInfo->ImageBase;
		ProcessID = (ULONG)ProcessId;

		DebugMessage("ProcessId: %d \n", ProcessId);

	}

	return STATUS_SUCCESS;
}
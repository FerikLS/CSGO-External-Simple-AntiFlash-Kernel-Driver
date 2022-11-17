#pragma warning (disable : 4100 4047 4024)

#include "Test.h"
#include "events.h"
#include "Data.h"
#include "Communication.h"

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath)
{

	pDriverObject->DriverUnload = UnloadDriver;

	DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "Driver is loaded");

	PsSetLoadImageNotifyRoutine(ImageLoadCallBack);

	RtlInitUnicodeString(&dev, L"\\Device\\TestGuide");
	RtlInitUnicodeString(&dos, L"\\DosDevices\\TestGuide");

	IoCreateDevice(pDriverObject, 0, &dev, FILE_DEVICE_UNKNOWN, FILE_DEVICE_SECURE_OPEN, FALSE, &pDeviceObject);
	IoCreateSymbolicLink(&dos, &dev);

	pDriverObject->MajorFunction[IRP_MJ_CREATE] = CreateCall;
	pDriverObject->MajorFunction[IRP_MJ_CLOSE] = CloseCall;
	pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = IoControl;

	pDriverObject->Flags |= DO_DIRECT_IO;
	pDriverObject->Flags &= ~DO_DEVICE_INITIALIZING;

	return STATUS_SUCCESS;
}

NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverObject)
{
	DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "Driver is unloaded");

	PsRemoveLoadImageNotifyRoutine(ImageLoadCallBack);

	IoDeleteSymbolicLink(&dos);
	IoDeleteDevice(pDriverObject->DeviceObject);

	return STATUS_SUCCESS;
}


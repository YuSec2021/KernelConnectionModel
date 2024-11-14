#pragma once
#include <ntifs.h>
#include <Windows.h>
#include "commStruct.h"


typedef NTSTATUS(NTAPI * CommonCallback)(PCommPackage package);

NTSTATUS DriverRegisterComm(PDRIVER_OBJECT pDriver, CommonCallback commCallback);
VOID DriverDestroyComm(PDRIVER_OBJECT pDriver);

NTSTATUS InitDispatch(PDEVICE_OBJECT DeviceObject, PIRP Irp);
NTSTATUS ReadDispatch(PDEVICE_OBJECT DeviceObject, PIRP Irp);
NTSTATUS WriteDispatch(PDEVICE_OBJECT DeviceObjet, PIRP Irp);
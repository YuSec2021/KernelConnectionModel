#pragma once
#include <ntifs.h>
#include <Windows.h>

#define SYM_NAME L"\\??\\commSymbol"

typedef struct _CommPackage {
	ULONG64 id;
	ULONG64 code;
	ULONG64 inData;
	ULONG64 inLen;
	ULONG64 outData;
	ULONG64 outLen;
} CommPackage, *PCommPackage;


typedef NTSTATUS(NTAPI * CommonCallback)(PCommPackage package);

NTSTATUS DriverRegisterComm(PDRIVER_OBJECT pDriver, CommonCallback commCallback);


#include "comm.h"

HANDLE ghDevice;

BOOLEAN driverInit() {
	HANDLE ghDevice = CreateFile(
		SYM_NAME,
		GENERIC_READ | GENERIC_WRITE,
		NULL,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_SYSTEM,
		0
	);

	if (ghDevice == NULL || ghDevice == INVALID_HANDLE_VALUE) {
		ghDevice = NULL;
		return FALSE;
	}

	return TRUE;
}

BOOLEAN DriverComm(ULONG64 code, PVOID inData, ULONG64 inLen, PVOID outData, ULONG64 outLen) {
	if (!ghDevice) {
		driverInit();
	}

	if (ghDevice) {
		CommPackage package = { 0 };
		package.code = code;
		package.inData = (ULONG64)inData;
		package.inLen = inLen;
		package.outData = (ULONG64)outData;
		package.outLen = outLen;
		SIZE_T pro = NULL;

		package.id = COMM_ID;

		return WriteFile(ghDevice, &package, sizeof(CommPackage), &pro, NULL);
	}

	return FALSE;
}
#include "comm/comm.h"

NTSTATUS NTAPI Dispatch (PCommPackage package) {
	NTSTATUS status = STATUS_UNSUCCESSFUL;
	switch (package->code) {
	case TEST:
		{
			PTest t = (PTest)package->inData;
			KdPrintEx((77, 0, "[db]: ----%x-----%x----\r\n", t->x, t->y));
			t->x = 500;
			t->y = 200;
			status = STATUS_SUCCESS;
		}
		break;
	case WRITE:
		break;
	case READ:
		break;
	}

	return status;
}

VOID DriverUnload(PDRIVER_OBJECT pDriver) {
	DriverDestroyComm(pDriver);
}

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriver, PUNICODE_STRING pReg) {
	NTSTATUS status = STATUS_SUCCESS;

	DriverRegisterComm(pDriver, Dispatch);

	pDriver->DriverUnload = DriverUnload;
	return status;
}
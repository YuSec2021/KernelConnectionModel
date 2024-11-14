#include "comm.h"

CommonCallback gCommCallback = NULL;

NTSTATUS DriverRegisterComm(PDRIVER_OBJECT pDriver, CommonCallback commCallback) {
	gCommCallback = commCallback;
}

VOID DriverDestroyComm(PDRIVER_OBJECT pDriver) {
	UNICODE_STRING symName = { 0 };
	RtlInitUnicodeString(&symName, SYM_NAME);
	IoDeleteSymbolicLink(&symName);
	if (pDriver->DeviceObject) {
		IoDeleteDevice(pDriver->DeviceObject);
	}
}

NTSTATUS InitDispatch(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
	NTSTATUS status = STATUS_SUCCESS;





	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return status;
}

NTSTATUS ReadDispatch(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
	NTSTATUS status = STATUS_SUCCESS;

	PIO_STACK_LOCATION ioStack = IoGetCurrentIrpStackLocation(Irp);
	
	int Length = ioStack->Parameters.Read.Length;
	if (Length == sizeof(CommPackage) && gCommCallback) {
		PCommPackage package = (PCommPackage)Irp->AssociatedIrp.SystemBuffer;
		if (MmIsAddressValid(package)) {
			if (package->id == COMM_ID) {
				status = gCommCallback(package);
			}
		}
	}

	Irp->IoStatus.Information = 0;
	Irp->IoStatus.Status = STATUS_SUCCESS;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return status;
}

NTSTATUS WriteDispatch(PDEVICE_OBJECT DeviceObjet, PIRP Irp) {
	NTSTATUS status = STATUS_SUCCESS;

	PIO_STACK_LOCATION ioStack = IoGetCurrentIrpStackLocation(Irp);
	PVOID buffer = Irp->AssociatedIrp.SystemBuffer;
	int Length = ioStack->Parameters.Write.Length;
	if (Length == sizeof(CommPackage)) {
		PVOID buffer = Irp->AssociatedIrp.SystemBuffer;
	}




	Irp->IoStatus.Information = 0;
	Irp->IoStatus.Status = STATUS_SUCCESS;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return status;
}
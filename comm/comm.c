#include "comm.h"

CommonCallback gCommCallback = NULL;

NTSTATUS DriverRegisterComm(PDRIVER_OBJECT pDriver, CommonCallback commCallback) {
	gCommCallback = commCallback;


}

NTSTATUS WriteDispatch(DEVICE_OBJECT* DeviceObject, IRP* Irp) {

}
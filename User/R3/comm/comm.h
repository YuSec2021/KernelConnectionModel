#pragma once
#include "../../../Kernel/comm/commStruct.h"

BOOLEAN DriverInit();

//
// DriverComm: Package Data And Send Data
//
BOOLEAN DriverComm(ULONG64 code, PVOID inData, ULONG64 inLen, PVOID outData, ULONG64 outLen);
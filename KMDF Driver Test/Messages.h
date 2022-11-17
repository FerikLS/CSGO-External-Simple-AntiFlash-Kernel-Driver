#pragma once

#define DebugMessage(x, ...) DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, x, __VA_ARGS__)
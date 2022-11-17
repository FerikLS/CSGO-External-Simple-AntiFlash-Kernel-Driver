#include <iostream>
#include "kernelinterface.hpp"
#include "offsets.hpp"

int main()
{
	KernelInterface Driver = KernelInterface("\\\\.\\TestGuide");

	ULONG address = Driver.GetClientAddress();
	ULONG processid = Driver.GetProcessId();


	std::cout << " Client Address " << std::hex << address << std::endl;
	std::cout << " ProcessID " << std::hex << processid << std::endl;

	while (true)
	{
		uint32_t LocalPlayerAddress = Driver.ReadVirtualMemory<uint32_t>(processid, address +hazedumper::signatures::dwLocalPlayer, sizeof(uint32_t));

		float num = Driver.ReadVirtualMemory<float>(processid, LocalPlayerAddress + hazedumper::netvars::m_flFlashMaxAlpha, sizeof(float));
		Driver.WriteVirtualMemory(processid, LocalPlayerAddress + hazedumper::netvars::m_flFlashMaxAlpha, 0.f, sizeof(0.f));
	}
}
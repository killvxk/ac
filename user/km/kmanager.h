#ifndef KMANAGER_H
#define KMANAGER_H

#include <windows.h>

#include "..\client.h"
#include "..\threadpool.h"

#include "driver.h"

namespace kernelmode
{
	class KManager
	{
		std::unique_ptr<Driver> driver_interface;
		std::shared_ptr<global::ThreadPool> thread_pool;
	public:
		KManager( LPCWSTR DriverName, std::shared_ptr<global::ThreadPool> ThreadPool, std::shared_ptr<global::Client> ReportInterface);

		VOID RunNmiCallbacks();
		VOID VerifySystemModuleDriverObjects();
		VOID MonitorCallbackReports();
		VOID DetectSystemVirtualization();
		VOID EnumerateHandleTables();
		VOID RequestModuleExecutableRegionsForIntegrityCheck();
		VOID ScanPoolsForUnlinkedProcesses();
		VOID PerformIntegrityCheck();
		VOID CheckForAttachedThreads();
		VOID ValidateProcessModules();
		VOID SendClientHardwareInformation();
		VOID InitiateApcStackwalkOperation();
		VOID CheckForHiddenThreads();
		VOID CheckForEptHooks();
		VOID LaunchIpiInterrupt();
		VOID ValidateSystemModules();
	};
}

#endif
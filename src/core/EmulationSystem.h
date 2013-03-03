/*
 *  Filename	: EmulationSystem.h
 *  Author		: Kuba Sejdak
 *  Created on	: 03-05-2012
 */

#ifndef EMULATIONSYSTEM_H_
#define EMULATIONSYSTEM_H_

#include <QString>
#include <QDir>

extern "C" {
	#include <emu/emu.h>
	#include <emu/emu_cpu_data.h>
	#include <emu/emu_cpu.h>
	#include <emu/emu_memory.h>
	#include <emu/emu_shellcode.h>
	#include <emu/emu_graph.h>
	#include <emu/environment/emu_env.h>
	#include <emu/environment/emu_profile.h>
	#include <emu/environment/win32/emu_env_w32.h>
	#include <emu/environment/win32/emu_env_w32_dll.h>
	#include <emu/environment/win32/emu_env_w32_dll_export.h>
	#include <emu/environment/linux/emu_env_linux.h>
	#include <emu/environment/linux/env_linux_syscall_hooks.h>
}

#include <core/EmulationUnit.h>
#include <core/ExploitSample.h>
#include <utils/SystemLogger.h>
//#include <core/Dot.h>
#include <core/Options.h>

class EmulationSystem {
public:
	EmulationSystem();
	virtual ~EmulationSystem();

	void loadSample(ExploitSample *sample);
	bool emulate();

private:
    EmulationUnit *m_emuUnit;
    ExploitSample *m_sample;
};

#endif /* EMULATIONSYSTEM_H_ */

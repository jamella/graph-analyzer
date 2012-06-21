/*
 * Filename	: AnalysisSystem.h
 * Author	: Kuba Sejdak
 * Created on	: 21-06-2012
 */

#ifndef ANALYSISSYSTEM_H_
#define ANALYSISSYSTEM_H_

/* standard headers */
#include <map>

/* project headers */
#include <toolbox.h>
#include <core/ShellcodeSample.h>
#include <modules/AbstractAnalyze.h>
#include <modules/ModuleManager.h>

class AnalysisSystem {
public:
	AnalysisSystem();
	virtual ~AnalysisSystem();

	void loadSample(ShellcodeSample *sample);
	bool analyze();

private:
	void loadModules();

	ShellcodeSample *sample;
	map<int, AbstractAnalyze *> *analyzeModules;
};

#endif /* ANALYSISSYSTEM_H_ */

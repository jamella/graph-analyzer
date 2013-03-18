/*
 *  Filename	: AnalyzeTask.h
 *  Author		: Kuba Sejdak
 *  Created on	: 14-03-2013
 */

#ifndef ANALYZETASK_H
#define ANALYZETASK_H

#include <QList>
#include <QString>

#include <tasks/ITask.h>
#include <tasks/analyze/AnalysisSystem.h>
#include <tasks/analyze/EmulationSystem.h>
#include <tasks/analyze/modules/ModuleManager.h>
#include <core/ExploitSample.h>

class AnalyzeTask : public ITask {
public:
	AnalyzeTask(int id);
	virtual ~AnalyzeTask() {}

private:
	virtual bool perform();
	bool readConfigXML();
	void addScheduledFile(QString filename);

	int load(QString filename);
	bool emulate(ExploitSample *s);
	bool analyze(ExploitSample *s);

	EmulationSystem m_emulationSystem;
	AnalysisSystem m_analysisSystem;

	QList<QString> m_taskFiles;

	/* task specific info */
	bool m_override;
	int m_scheduledFiles;
	int m_loadedFiles;
	int m_analyzedSamples;
	int m_detectedExploits;
};

#endif /* ANALYZETASK_H */

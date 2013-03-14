/*
 * Filename		: Experiment.h
 * Author		: Kuba Sejdak
 * Created on	: 03-03-2013
 */

#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <QString>
#include <QTime>
#include <QList>

#include <utils/XMLParser.h>
#include <core/ExploitSample.h>

class Experiment {
public:
	Experiment() {}
	virtual ~Experiment() {}

private:
	QString m_name;
	QString m_startTime;
	QString m_endTime;
	QString m_;
	QString m_groupingStrategy;

	QTime m_time;
	QList<ExploitSample *> m_samples;
};

#endif /* EXPERIMENT_H */
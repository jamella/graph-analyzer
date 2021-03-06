/*
 *  Filename	: ITask.h
 *  Author		: Kuba Sejdak
 *  Created on	: 14-03-2013
 */

#ifndef ITASK_H
#define ITASK_H

#define TASKS_FILE		"/var/www/jsejdak/GraphAnalyzerTasks.xml"
#define ROOT_NODE		"Task"

#include <list>
#include <string>
#include <QTime> // TODO: change to some non-Qt
#include <QDate> // TODO: change to some non-Qt

#include <core/ExploitSample.h>
#include <utils/XMLParser.h>

class QDomElement;

class ITask {
public:
	typedef std::map<std::string, std::string> TaskTraits;

	ITask();
	virtual ~ITask() {}

	QDate from();
	QDate until();
	std::list<std::string> taskFiles();

    bool perform();
	virtual void updateStatus() = 0;
	virtual bool readConfigXML(QDomElement taskNode) = 0;

    // for exporting status purpose
    int id();
	std::string name();
	std::string type();
    QTime startTime();
    QTime endTime();
    QTime workTime();
    int errors();
    int progress();
    bool isFinished();
	std::string displayTraitName();
	std::string displayTraitValue();
	TaskTraits &traits();

    void setId(int id);

protected:
	virtual bool performTask() = 0;				// perform specific task

	XMLParser m_xmlParser;						// provides parser for XML configuration file
	SampleList m_samples;						// samples that are used in task
	std::list<std::string> m_exportStrategies;  // strategies for exporting task results
	QTime m_timer;								// provides time functions
	QDate m_from;								// start time criteria
	QDate m_until;								// end time criteria

    // task general info
	int m_id;									// task id
	std::string m_name;							// task name defined by user
	std::string m_type;							// task type
	QTime m_startTime;							// when task was started
	QTime m_endTime;							// when task was ended
	QTime m_workTime;							// how long did task work
	int m_errors;								// number of errors that occured during task
	int m_progress;								// current progress of task
	std::string m_displayTraitName;				// task specific trait name
	std::string m_displayTraitValue;			// task specific trait value
	bool m_finished;							// is task finished
	TaskTraits m_traits;						// task traits
	std::list<std::string> m_taskFiles;			// files that should be used when performing task

};

#endif /* ITASK_H */

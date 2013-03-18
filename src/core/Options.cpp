/*
 * Filename		: Options.cpp
 * Author		: Kuba Sejdak
 * Created on	: 16-09-2012
 */

#include <core/Options.h>
#include <utils/DatabaseManager.h>

Options::Options()
{
	/* initial configuration */
	graphsDir = "/var/www/jsejdak/graphs";
	emulationSteps = 1000000;
	skipBigFiles = true;
	bigFileSize = 20971520;
	skipBrokenSamples = true;
	brokenSampleSize = 50;
	skipEmptySamples = true;

	if(!readConfigXML())
		LOG_ERROR("failed to read XML configuration, using default options\n");

	listOptions();
}

bool Options::readConfigXML()
{
	if(!m_xmlParser.open(CONFIG_FILE))
		return false;

	if(!m_xmlParser.hasRoot("CoreOptions")) {
		m_xmlParser.close();
		return false;
	}

	QDomElement options = m_xmlParser.root("CoreOptions");

	graphsDir = m_xmlParser.child(options, "GraphsDir").attribute("path");

	emulationSteps = m_xmlParser.child(options, "EmulationSteps").attribute("val").toInt();

	skipBigFiles = m_xmlParser.child(options, "SkipBigFiles").attribute("val") == "true" ? true : false;
	bigFileSize = m_xmlParser.child(options, "SkipBigFiles").attribute("size").toInt();

	skipBrokenSamples = m_xmlParser.child(options, "SkipBrokenSamples").attribute("val") == "true" ? true : false;
	brokenSampleSize = m_xmlParser.child(options, "SkipBrokenSamples").attribute("size").toInt();

	skipEmptySamples = m_xmlParser.child(options, "SkipEmptySamples").attribute("val") == "true" ? true : false;

	m_xmlParser.close();
	return true;
}

void Options::listOptions()
{
	/* core settings */
	LOG("core settings:\n");
	LOG("graphsDir: [%s]\n", graphsDir.toStdString().c_str());
	LOG("emulationSteps: [%d]\n", emulationSteps);
	LOG("skipBigFiles: [%s]\n", skipBigFiles ? "true" : "false");
	LOG("bigFileSize: [%d]\n", bigFileSize);
	LOG("skipBrokenSamples: [%s]\n", skipBrokenSamples ? "true" : "false");
	LOG("brokenSampleSize: [%d]\n", brokenSampleSize);
	LOG("skipEmptySamples: [%s]\n", skipEmptySamples ? "true" : "false");
}

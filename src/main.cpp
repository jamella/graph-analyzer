/*
 *  Filename	: main.cpp
 *  Author		: Kuba Sejdak
 *  Created on	: 01-05-2012
 */

#define AUTHOR	"Kuba Sejdak"

#include <vector>
#include <iostream>
#include <boost/program_options.hpp>

#include <core/CoreSystem.h>
#include <utils/SystemLogger.h>

namespace opt = boost::program_options;
using namespace std;

int main(int argc, char *argv[])
{
	// create main system
	CoreSystem system;

	// parse cmd line arguments
	opt::options_description options("Options");
	options.add_options()
			("help,h", "print help message")
			("version,v", "print version")
            ("tasks,t", "execute system tasks")
            ("export-description,d", "save description to XML file")
			;

	opt::variables_map vm;
	opt::store(opt::parse_command_line(argc, argv, options), vm);
	opt::notify(vm);

	// help
	if(vm.count("help")) {
		cout << options << endl;
		return 0;
	}
	// version
	if(vm.count("version")) {
		cout << system.version() << endl;
		return 0;
	}
	// export status
    if(vm.count("export-description")) {
        SystemLogger::instance()->exportDescription();
        return 0;
    }
	// call rpc function
	if(vm.count("tasks")) {
		bool stat = system.executeTasks();

		if(stat == false) {
			LOG("executing tasks failed\n");
			return 1;
		}
	}

    return 0;
}

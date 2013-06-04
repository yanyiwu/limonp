#ifndef CPPCOMMON_CONFIG_H
#define CPPCOMMON_CONFIG_H


#include <map>
#include <fstream>
#include <iostream>
#include "logger.h"

namespace CPPCOMMON
{
	using std::map;
	using std::string;
	using std::cout;
	using std::endl;
	using std::ifstream;
	class Config
	{
		public:
			Config();
			~Config();
			bool init(const string& configFile);
			void display();
		private:
			map<string, string> _map;

	};
}

#endif

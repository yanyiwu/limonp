#include "config.h"
#include "str_functs.h"

namespace CPPCOMMON
{
	Config::Config()
	{
	}

	Config::~Config()
	{
	}

	bool Config::init(const string& configFile)
	{
		char msgBuf[1024];
		ifstream ifile(configFile.c_str());
		if(!ifile)
		{
			sprintf(msgBuf, "open configFile[%s] failed.", configFile.c_str());
			LogError(msgBuf);
			return false;
		}
		string line, key, value;
		vector<string> vecBuf;
		while(getline(ifile, line))
		{
			line = _stripComment(line);
			if(line.empty())
			{
				continue;
			}
			vecBuf = splitStr(line, "=");
			if(2 != vecBuf.size())
			{
				sprintf(msgBuf, "line[%s] is illegal.", line.c_str());
				LogError(msgBuf);
				return false;
			}
			key = vecBuf[0];
			value = vecBuf[1];
			if(_map.end() != _map.find(key))
			{
				sprintf(msgBuf, "key[%s] already exists.", key.c_str());
				LogError(msgBuf);
				return false;
			}
			_map[key] = value;
		}
		ifile.close();
		return true;
	}

	void Config::display()
	{
		for(map<string, string>::iterator it = _map.begin(); it != _map.end(); it++)
		{
			cout<<"("<<it->first<<","<<it->second<<")"<<endl;
		}
	}
	
	string Config::getByKey(const string& key)
	{
		if(_map.end() != _map.find(key))
		{
			return _map[key];
		}
		else
		{
			return "";
		}
	}

	string Config::_stripComment(const string& line)
	{
		string res = line;
		string::size_type pos = res.find('#');
		if(string::npos != pos)
		{
			res = res.substr(0, pos);
		}
		return stripStr(res);
	}

}


#ifdef CONFIG_UT
using namespace CPPCOMMON;
int main()
{
	Config config;
	config.init("1.conf");
	config.display();
	cout<<config.getByKey("a")<<endl;
	cout<<config.getByKey("cm")<<endl;
	return 0;
}

#endif

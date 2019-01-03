/**
 * @fileName log.h
 * @Function Generate log file
 */
#ifndef log_h
#define log_h

#include <bits/stdc++.h>
#include "dig.h"

using namespace std;

string getTime(){//Get time
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );
    return tmp;
}

void put_log(string user,string opreater){//put log in file
	time_t timer;
	time(&timer);
	tm* t_tm = localtime(&timer);
	ofstream file;
	file.open("bin\\log\\history"+dig(t_tm->tm_year+1900)+".log",ios::app);
	file<<getTime()<<" "<<user<<" "<<opreater<<endl;
	file.close();
}
#endif
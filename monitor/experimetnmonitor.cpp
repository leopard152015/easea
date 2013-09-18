/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "experimetnmonitor.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

extern "C"
{
    #include "gfal_api.h"
}

int ExperimentMonitor::init()
{
    if(debug)printf("Creating experiment and worker folders...\n");
    std::string fullpath = exppath+expname;
    int result = gfal_mkdir(fullpath.c_str(),0777);
    
    // check error condition
    printf("Trying to determine or create directory experiment\n");
    if(result<0 && errno!=EEXIST)
    {
        printf("Cannot create experiment folder %s; check user permissions or disk space", fullpath.c_str());
        printf("Result of gfal_mkdir = %d %d\n" ,result,errno);   
	return -1;
    }
    
    std::string workers_info_path=fullpath + "/workers_info";
    

    result = gfal_mkdir(workers_info_path.c_str(),0777);
    
    // check error condition
    printf("Trying to determine or create directory experiment\n");
    if(result<0 && errno!=EEXIST)
    {
        printf("Cannot create experiment folder %s; check user permissions or disk space", workers_info_path.c_str());
        printf("Result of gfal_mkdir = %d %d\n" ,result,errno);   
	return -1;
    }

    
    ListWorkersMonitor = new MonitorWorkerListManager(fullpath,nworkers, debug);
    return 0;
}


int ExperimentMonitor::run()
{
  do
  {
      ListWorkersMonitor->refresh_worker_list();
      sleep(30);
  }while(!ListWorkersMonitor->terminated());
  return 0;
}
/*
 *    Copyright (C) 2013  Waldo Cancino

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#ifndef CCOMGRIDUDPSERVER
#define CCOMGRIDUDPSERVER
#include <queue>
#include <string>
#include <list>
#include <set>
#include "CComWorker.h"
#include <net/if.h>
#include <sys/socket.h> /* for socket(), bind(), and connect() */
#include <netdb.h> /* for gethostbyname */
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */
#include <netinet/in.h> /* for IP Socket data types */
#include <unistd.h>     /* for close() */
#include <stdio.h>
#include "CComWorkerListManager_2.h"
#include "worker_workerlistmanager.h"
#include "filecommworkercommunicator.h"
#include "networkcommworkercommunicator.h"


class CComGridUDPServer {

public:
	int debug;
	//RECV_DATA *data;
	//int nb_data;
	std::queue<std::string> *data;
	CComGridUDPServer(char* path, char* expname, std::queue< std::string >* _data, short unsigned int port, int wn, int dbg);
	static void * UDP_server_thread(void *parm);
	~CComGridUDPServer();
	void read_data_lock();
	void read_data_unlock();
	int register_worker();
	int get_ipaddress(std::string& ip, long unsigned int& nm);
	int create_exp_path(char *path, char *expname);
	int determine_worker_name(std::string &workername);
	int send(char *individual, int dest);
	int send(char* individual, CommWorker dest);
	static void* read_thread_f(void *parm);
	static void* refresh_thread(void *parm);
	static void* write_thread_files_f(void *parm);
	static void* read_thread_files_f(void *parm);
	
	int init_network(short unsigned int& port);
	int number_of_clients();
        int create_tmp_file(int& fd, std::string workerdestname, std::string &tmpfilename);
	int send_file_worker(std::string buffer, std::string workerdestname);
	void send_individuals();
	int refresh_file_list();
	int file_read(const char* filename, char *buffer);
	void readfiles();
	int determine_file_name(std::string tmpfilename, std::string workerdestname);
	int send_file(char *buffer, CommWorker destination);
	int in_same_network(const char* addr1, const char* addr2);
	int log_connection(std::string source, std::string destination, std::string buffer);
	void terminate( std::string );
	
private:
  	std::string workername;
	std::string fullpath;
	std::list<std::pair<std::string,std::string> > writedata;
	std::set<std::string> processed_files;
	std::list<std::string> new_files;
	std::string extract_fitness( std::string buffer );
	static int cancel;
	FileCommWorkerCommunicator *filecomm;
	NetworkCommWorkerCommunicator *networkcomm;
	Worker_WorkerListManager *refresh_workers;
        CommWorker *myself;
	void run();
	int ServerSocket;
	pthread_t read_t,refresh_t, readf_t, writef_t;
	int Socket;
        int worker_number;
	struct sockaddr_in ServAddr;
	FILE *logfile_input, *logfile_output;
};
#endif

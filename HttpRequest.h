#ifndef __HTTP__
#define __HTTP__
 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#if WIN32
#include<WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")
#include<ws2tcpip.h>
#else
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>      
#include <sys/socket.h>
#endif
 
#define BUFSIZE 41000
#define URLSIZE 1024
#define INVALID_SOCKET -1
#define __DEBUG__

#if WIN32
#define os_usleep(x)	::Sleep(x / 1000)
#define os_sleep(x)		::Sleep(x * 1000)
#define os_close(x)		::closesocket(x)
#else
#define os_usleep(x)	usleep(x)
#define os_sleep(x)		sleep(x)
#define os_close(x)		::close(x)
#endif

 
class HttpRequest
{
	public:
		HttpRequest();
		~HttpRequest();
		void DebugOut(const char *fmt, ...);
		
		int HttpGet(const char* strUrl, char* strResponse);
		int HttpPost(const char* strUrl, const char* strData, char* strResponse);
 
	private:
		int   HttpRequestExec(const char* strMethod, const char* strUrl, const char* strData, char* strResponse);
		char* HttpHeadCreate(const char* strMethod, const char* strUrl, const char* strData);
		char* HttpDataTransmit(char *strHttpHead, const int iSockFd);
			
		int   GetPortFromUrl(const char* strUrl);
		char* GetIPFromUrl(const char* strUrl);
		char* GetParamFromUrl(const char* strUrl);
		char* GetHostAddrFromUrl(const char* strUrl);
		
		int   SocketFdCheck(const int iSockFd);	
		
		static int m_iSocketFd;
};
 
#endif

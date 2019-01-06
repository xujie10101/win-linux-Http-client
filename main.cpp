// winHttp.cpp : 定义控制台应用程序的入口点。
//

#if WIN32
#include "stdafx.h"
#endif


#include "HttpRequest.h"

int main()
{
	HttpRequest* Http = new HttpRequest;

	char* str = (char*)malloc(BUFSIZE);

//	const char* url = "https://api.weixin.qq.com/sns/jscode2session?appid=wx739bb5929e1a0a74&secret=3cd7c29cecefa02592fb743fa29ad124&js_code=%s&grant_type=authorization_code";
		const char* url = "http://172.16.1.142//GetRecordTopic";
	memset(str, 0, BUFSIZE);
	if(Http->HttpGet(url, str)) {
		printf("%s\n", str);
	} else {
		printf(" HttpGet请求失败!\n");
	}	

	free(str);
	system("pause");
	return 0;
}


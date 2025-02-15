#pragma once
#include "const.h"
#include "LogicSystem.h"

class HttpConnection;

typedef std::function<void(std::shared_ptr<HttpConnection>)> HttpHandler;

class LogicSystem : public Singleton<LogicSystem>
{
	friend class Singleton<LogicSystem>;
public:
	~LogicSystem() { };
	//处理get请求
	bool HandleGet(std::string path, std::shared_ptr<HttpConnection>);
	//注册get请求
	void RegGet(std::string url, HttpHandler handler);
	void RegPost(std::string url, HttpHandler handler);
	bool HandlePost(std::string path, std::shared_ptr<HttpConnection>);
private:
	LogicSystem();
	std::map<std::string, HttpHandler> _post_handlers;
	std::map<std::string, HttpHandler> _get_handlers;
};


#pragma once
#include "const.h"

class CServer : public std::enable_shared_from_this<CServer>
{
public:
	
	/*构造函数*/
	CServer(boost::asio::io_context& ioc, unsigned short& port);

	/**服务器开始运行**/
	void Start();

private:

	tcp::acceptor _acceptor;
	// 上下文 这里面引用类型是因为io_context不存在拷贝构造
	net::io_context& _ioc;

};


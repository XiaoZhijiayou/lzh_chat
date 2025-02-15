#pragma once
#include "const.h"
#include "LogicSystem.h"

class HttpConnection : public std::enable_shared_from_this<HttpConnection>
{
public:
	friend class LogicSystem;
	// 构造函数
	HttpConnection(boost::asio::io_context& ioc);
	// 用来监听读写事件
	void Start();
	tcp::socket& GetSocket() {
		return _socket;
	}
private:
	// 检测是否发送是否超时
	void CheckDeadline();
	// 应答函数
	void WriteResponse();
	// 处理请求
	void HandleReq();
	// 解析参数
	void PreParseGetParam();

	tcp::socket _socket;
	beast::flat_buffer _buffer{ 8192 };
	// beast下的接收各种请求的模板
	http::request<http::dynamic_body> _request;
	http::response<http::dynamic_body> _response;
	// 定时器
	net::steady_timer deadline_{
		_socket.get_executor(),
		std::chrono::seconds(60)
	};
	// 客户端的url
	std::string _get_url;
	// 解析url后的参数
	std::unordered_map<std::string, std::string> _get_params;
};



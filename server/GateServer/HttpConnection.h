#pragma once
#include "const.h"
#include "LogicSystem.h"

class HttpConnection : public std::enable_shared_from_this<HttpConnection>
{
public:
	friend class LogicSystem;
	// ���캯��
	HttpConnection(boost::asio::io_context& ioc);
	// ����������д�¼�
	void Start();
	tcp::socket& GetSocket() {
		return _socket;
	}
private:
	// ����Ƿ����Ƿ�ʱ
	void CheckDeadline();
	// Ӧ����
	void WriteResponse();
	// ��������
	void HandleReq();
	// ��������
	void PreParseGetParam();

	tcp::socket _socket;
	beast::flat_buffer _buffer{ 8192 };
	// beast�µĽ��ո��������ģ��
	http::request<http::dynamic_body> _request;
	http::response<http::dynamic_body> _response;
	// ��ʱ��
	net::steady_timer deadline_{
		_socket.get_executor(),
		std::chrono::seconds(60)
	};
	// �ͻ��˵�url
	std::string _get_url;
	// ����url��Ĳ���
	std::unordered_map<std::string, std::string> _get_params;
};



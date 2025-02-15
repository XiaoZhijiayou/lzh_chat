#pragma once
#include "const.h"

class CServer : public std::enable_shared_from_this<CServer>
{
public:
	
	/*���캯��*/
	CServer(boost::asio::io_context& ioc, unsigned short& port);

	/**��������ʼ����**/
	void Start();

private:

	tcp::acceptor _acceptor;
	// ������ ������������������Ϊio_context�����ڿ�������
	net::io_context& _ioc;

};


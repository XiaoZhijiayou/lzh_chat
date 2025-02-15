#include "AsioIOServicePool.h"
#include <iostream>

using namespace std;

AsioIOServicePool::AsioIOServicePool(std::size_t size)
	:_ioServices(size),
	_works(size),
	_nextIOService(0) {
	for (std::size_t i = 0; i < size; ++i) {
		//使用新的 Work 类型创建 work guard对象
		_works[i] = std::make_unique<Work>(_ioServices[i].get_executor());
	}

	// 遍历多个 ioservice，创建多个线程，每个线程内部启动 ioservice
	for (std::size_t i = 0; i < _ioServices.size(); ++i) {
		_threads.emplace_back([this, i] {
			_ioServices[i].run();
			});
	}
}


AsioIOServicePool::~AsioIOServicePool() {
	Stop();
	std::cout << "AsioIOServicePool destruct" << std::endl;
}

boost::asio::io_context& AsioIOServicePool::GetIOService() {
	auto& service = _ioServices[_nextIOService++];
	if (_nextIOService == _ioServices.size()) {
		_nextIOService = 0;
	}
	return service;
}

void AsioIOServicePool::Stop() {
	// 因为仅仅执行work.reset 并不能让 iocontext 从run 状态退出
	// 当 iocontext 已经绑定了读或者写的监听事件后， 还需要手动stop 该服务
	for (auto& work : _works) {
		// 先把服务停掉
		work->get_executor().context().stop();
		work.reset();
	}


	for (auto& t : _threads) {
		t.join();
	}
}

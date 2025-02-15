/******************************************************************************
 *
 * @file       singleton.h
 * @brief      单例模式的基类
 *
 * @author     zhihao li
 * @date       2025/01/08
 * @history
 *****************************************************************************/

#ifndef SINGLETON_H
#define SINGLETON_H

#include <global.h>

/**
 * @brief 单例模式
 */

template <typename T>
class Singleton{
protected:
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;
    Singleton& operator = (const Singleton<T>& st) = delete;
    static std::shared_ptr<T> _instance;
public:
    static std::shared_ptr<T> GetInstance(){
        static std::once_flag s_flag;
        std::call_once(s_flag,[&](){
            /// 这里不使用std::make_shared是因为这里的构造函数是protected的，make_shared无法访问受保护的构造函数
            /// 而new可以在类的内部直接调用
            _instance = std::shared_ptr<T>(new T);
        });
        return _instance;
    }

    void PrintAddress(){
        std::cout << _instance.get() << std::endl;
    }

    ~Singleton() {
        std::cout << "this is singleton destruct" << std::endl;
    }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;


#endif // SINGLETON_H

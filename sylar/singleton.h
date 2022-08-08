//
// Created by zhi-jun on 22-8-7.
//

#ifndef SYLAR_SINGLETON_H
#define SYLAR_SINGLETON_H

#include <memory>

namespace sylar{

    template<class T, class X = void, int N = 0>
    class Singleton{
    public:
        static T* GetInstance(){
            static T v;
            return &v;
        }
    };

    template<class T, class X = void, int N = 0>
    class SingletonPtr{
    public:
        static std::shared_ptr<T> GetInstance(){
            static std::shared_ptr<T> v (new T);
            return v;
        }
    };

}

#endif //SYLAR_SINGLETON_H

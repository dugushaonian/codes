#pragma once
#include <iostream>


class ScopeGuard {
public:
    template <typename T>
    ScopeGuard(T&& t) : fun(std::forward<T>(t)){}
    ~ScopeGuard() {
        if (fun) {
            fun();
        }
    }

private:
    std::function<void()> fun;

};

int main() {
    std::cout << "hello world" << std::endl;
    ScopeGuard sg([](){
                  std::cout << "outter sg" << std::endl;
                  });
    {
        ScopeGuard sg([]() {
                      std::cout << "inner sg" << std::endl;
                      });
    }
    ScopeGuard sg2([](){
                   std::cout << "outter2 sg" << std::endl;
                   });
    return 0;
}

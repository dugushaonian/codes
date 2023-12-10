#pragma once

class scope_guard {
public:
    template <typename T>
    scope_guard(T&& t) : {}
    ~scope_guard() {}

private:
    std::function<void> fun;

};


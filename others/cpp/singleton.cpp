/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2024-10-13 14:52:00
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2024-10-13 14:52:00
 */

#include <iostream>
#include <atomic>

class SpinLock {
public:
    void lock() {
        while (_flag.test_and_set(std::memory_order_acquire));
    }

    void unlock() {
        _flag.clear(std::memory_order_release);
    }
private:
    std::atomic_flag _flag = ATOMIC_FLAG_INIT;
};

template <typename T, bool long_life_time = false> class Singleton;

template <typename T>
class Singleton<T, false> {
public:
    template <typename... Args>
    static T& get_instance(Args&&... args) {
        static T instance(std::forward<Args>(args)...);
        return instance;
    }

public:
    virtual ~Singleton() {}

private:
    Singleton() = default;

private:
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};

template <typename T>
class Singleton<T, true> {
public:
    template <typename... Args>
    static T& instance(Args&&... args) {
        if (!_instance) {
            _lock.lock();
            if (!_instance) {
                _destroyed ? on_dead_reference(std::forward<Args>(args)...) : create(std::forward<Args>(args)...);
            }
            _lock.unlock();
        }
        return *_instance;
    }

public:
    virtual ~Singleton() {
        _instance = nullptr;
        _destroyed = true;
    }

private:
    template <typename... Args>
    static void create(Args&&... args) {
        static T instance(std::forward<Args>(args)...);
        _instance = &instance;
    }

    template <typename... Args>
    static void on_dead_reference(Args&&... args) {
        create(std::forward<Args>(args)...);
        new(_instance) T(std::forward<Args>(args)...);
        std::atexit(kill_singleton);
        _destroyed = false;
    }

    static void kill_singleton() {
        _instance->~Singleton();
    }

private:
    static SpinLock _lock;
    static T* _instance;
    static bool _destroyed;

private:
    Singleton() = default;

private:
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};

template <typename T> T* Singleton<T, true>::_instance = nullptr;
template <typename T> bool Singleton<T, true>::_destroyed = false;
template <typename T> SpinLock Singleton<T, true>::_lock;

int main() {
    return 0;
}


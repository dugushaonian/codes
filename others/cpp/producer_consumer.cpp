#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

template <typename T>
class ProducerConsumer {
public:
    ProducerConsumer(int capacity) : _capacity(capacity) {}
    ~ProducerConsumer() {}

    template <typename C>
    void producer(C&& t) {
        std::unique_lock<std::mutex> lock(_mutex);
        _buffer_not_full.wait(lock, [&]{return _buffer.size() < _capacity;});
        _buffer.emplace(std::forward<C>(t));
        _buffer_not_empty.notify_all();
    }

    T consumer() {
        std::unique_lock<std::mutex> lock(_mutex);
        _buffer_not_empty.wait(lock, [&] {return !_buffer.empty();});
        auto t = _buffer.front();
        _buffer.pop();
        _buffer_not_full.notify_all();
        return t;
        
    }
private:
    int _capacity{0};
    std::queue<T> _buffer;
    std::mutex _mutex;
    std::condition_variable _buffer_not_empty;
    std::condition_variable _buffer_not_full;
};

int main()
{
    std::cout << "Hello world" << std::endl;
    ProducerConsumer<int> producer_consumer(5);
    std::thread t1([&](){
                   for (int i = 0; i < 10; ++i) {
                   producer_consumer.producer(i);
                   std::cout << "producer: " << i << std::endl;
                   }
                   });
    std::thread t2([&](){
                   for (int i = 0; i < 10; ++i) {
                   auto t = producer_consumer.consumer();
                   std::cout << "consumer: " << i << " -> " << t << std::endl;
                   }
                   });
    t1.join();
    t2.join();
    return 0;
}


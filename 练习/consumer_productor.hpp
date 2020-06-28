#include <cstdio>
#include <vector>
#include <pthread.h>
#include <semaphore.h>

#define MAX_QUEUE 5
class RingQueue{
    public:
        RingQueue(int maxq = MAX_QUEUE):_arry(maxq), _capacity(maxq),
        _write_step(0), _read_step(0){
            //sem_init(信号量变量， 进程间/线程间标志， 初值)
            sem_init(&_sem_lock, 0, 1);
            sem_init(&_sem_idle, 0, maxq);//一开始队列中都是空闲空间``
            sem_init(&_sem_data, 0, 0);//一开始队列中是没有数据的
        }
        ~RingQueue(){
            sem_destroy(&_sem_data);
            sem_destroy(&_sem_idle);
            sem_destroy(&_sem_lock);
        }
        bool Push(int data) {
            //入队都是生产者，首先得要有空间空间
            //其次在访问空间入队数据的时候需要加锁保护（多个生产同时操作，有可能冲突）
            sem_wait(&_sem_idle);//判断有没有空闲空间, 若有则空闲空间计数-1，后返回
            sem_wait(&_sem_lock);//加锁保护
            _arry[_write_step] = data;
            _write_step  = (_write_step + 1) % _capacity;
            sem_post(&_sem_lock);//计数+1，解锁操作
            sem_post(&_sem_data);//数据空间增加一个
            return true;
        }
        bool Pop(int *data) {
            sem_wait(&_sem_data);//有没有数据
            sem_wait(&_sem_lock);//有数据了能够获取了再去加锁
            *data = _arry[_read_step];
            _read_step = (_read_step + 1) % _capacity;
            sem_post(&_sem_lock);//解锁
            sem_post(&_sem_idle);//空闲空间计数+1
            return true;
        }
    private:
        std::vector<int> _arry;// 实现环形队列的数组
        int _capacity; //决定环形队列中的节点数量
        int _write_step;//当前写入位置的下标 _write_step==_read_step -- 表示队列中没有数据
        int _read_step;//当前读取位置的下标 (_write_step + 1)%_capacity==_read_step则表示队列中数据满了
        sem_t _sem_lock;//用于实现互斥，保护_arry/_capacity/_write_step/_read_step的操作
        //数据空间的个数，对数据资源进行计数,---对于消费者来说通过数据空间计数判断是否出队合理
        sem_t _sem_data;
        //空闲空间的计数---有空闲空间才能入队 -- -对于生产者来说通过空闲空间计数判断是否入队数据合理
        sem_t _sem_idle;
};

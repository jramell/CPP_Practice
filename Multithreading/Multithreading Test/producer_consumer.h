#ifndef SERGIOTEST_PRODUCER_CONSUMER_H
#define SERGIOTEST_PRODUCER_CONSUMER_H

#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <condition_variable>

using namespace std;

namespace jr {
    class ProducerConsumerTest {
        vector<int> list;
        condition_variable conditionVariable;
        mutex lck;
        int processed = 0;

        void producer() {
            while(processed < 50) {
                unique_lock<mutex> uniqueLock(lck);
                while(!list.empty()) {
                    if(processed >= 50) {
                        return;
                    }
                    conditionVariable.wait(uniqueLock);
                }
                for(int i = processed; i < processed+10; i++) {
                    list.push_back(i);
                    cout << "produced " << i << endl;
                }
                conditionVariable.notify_all();
            }
        }

        void consumer() {
            while(processed < 50) {
                unique_lock<mutex> uniqueLock(lck);
                while(list.empty()) {
                    conditionVariable.notify_all();
                    conditionVariable.wait(uniqueLock);
                }
                cout << "processed " << list.at(0) << endl;
                list.erase(list.begin());
                ++processed;
            }
            cout << "Consumer ended consuming" << endl;
            conditionVariable.notify_all();
        }
    public:
        void producedConsumerTest() {
            cout << "Start ---------------------------------------------------" << endl;
            for(int k = 100; k < 105; k++) {
                list.push_back(k);
            }
            thread t1(producer, this);
            thread t2(consumer, this);
            t1.join();
            t2.join();
            cout << "End ---------------------------------------------------" << endl;
        }
    };
}

#endif //SERGIOTEST_PRODUCER_CONSUMER_H

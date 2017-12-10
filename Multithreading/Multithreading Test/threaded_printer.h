#include <string>
#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

namespace jr {
    class ThreadedPrinter {
        mutex mtx;

        static void printCounter(string printer, string message) {
            lock_guard<mutex> guard(mtx);
            static int counter = 0;
            cout << counter++ << " - " << printer << ": " << message << endl;
        }

        static void thread1(string name) {
            for(int i = 0; i < 50; i++) {
                printCounter(name, to_string(i));
            }
        };

        static void thread2(string name) {
            for(int i = 0; i < 50; i++) {
                printCounter(name, to_string(i));
            }
        };
    public:
        static int threadedPrinterTest() {
            cout << "Start-------------------------------------------------------------------" << endl;
            thread t1(thread1, "Thread1");
            thread t2(thread2, "Thread2");
            t1.join();
            t2.join();
            cout << "End-------------------------------------------------------------------" << endl;
        }
    };
}

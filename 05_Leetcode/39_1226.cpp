#include <iostream>
#include <functional>
#include <mutex>
using namespace std;
class DiningPhilosophers
{
public:
    DiningPhilosophers() {}
    std::mutex mtx[5];
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork)
    {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        if (philosopher % 2 == 0)
        {
            mtx[left].lock();
            mtx[right].lock();
        }
        else
        {
            mtx[right].lock();
            mtx[left].lock();
        }

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        mtx[left].unlock();
        mtx[right].unlock();
    }
};
int main()
{

    system("pause");
    return 0;
}

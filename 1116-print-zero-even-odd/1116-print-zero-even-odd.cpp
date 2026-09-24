class ZeroEvenOdd {
private:
    int n;
    int i;
    std::mutex m;
    std::condition_variable cv;
    bool turn_zero;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->i = 1;
        this->turn_zero = true;
    }

    void zero(function<void(int)> printNumber) {
        while(i<=n){
            std::unique_lock<std::mutex> l(m);
            while(!turn_zero) cv.wait(l);
            if(i<=n) printNumber(0);
            turn_zero = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(i<=n){
            std::unique_lock<std::mutex> l(m);
            while(turn_zero || i%2 == 1) cv.wait(l);
            if(i<=n) printNumber(i);
            i += 1;
            turn_zero = true;
            cv.notify_all();
        }   
    }

    void odd(function<void(int)> printNumber) {
        while(i<=n){
            std::unique_lock<std::mutex> l(m);
            while(turn_zero || i%2 == 0) cv.wait(l);
            if(i <= n) printNumber(i);
            i += 1;
            turn_zero = true;
            cv.notify_all();
        }
    }
};
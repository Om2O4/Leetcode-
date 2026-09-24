class FooBar {
private:
    int n;

public:
    atomic<bool> runFoo = true;

    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {

            while(!runFoo);

            printFoo();

            runFoo = false;
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {

            while(runFoo);

            printBar();

            runFoo = true;
        }
    }
};
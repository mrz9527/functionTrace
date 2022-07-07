#include <iostream>


class CA {
public:
    CA(){};
    ~CA() {};

    void show() {
        std::cout << "I am CA!" << std::endl;
    }
};

void process(CA* ca) {
    ca->show();
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    CA* p = new CA;
    process(p);
    delete p;
    p = nullptr;
    return 0;
}


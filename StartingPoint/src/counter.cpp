#include <iostream>
using namespace std;

class Counter {
    friend void set_to_zero(Counter& counter);

    /// <summary>
    /// Const because it doesnt effect the stuff I would presume.
    /// Just see how many things you can make const for it to still work.
    /// </summary>
    const friend Counter operator+(Counter c1, Counter c2);
    const friend Counter operator*(int m, Counter counter);

private:
    int count;

public:
    Counter(int count) : count(count) { }

    void print() const {
        cout << count << endl;
    }

    void increment() {
        count++;
    }

    Counter operator*(int m) const {
        int new_count = count * m;
        return Counter(new_count);
    }
};

void set_to_zero(Counter& counter) {
    counter.count = 0;
}

const Counter operator+(Counter c1, Counter c2) {
    int new_count = c1.count + c2.count;
    return Counter(new_count);
}

const Counter operator*(int m, Counter counter) {
    int new_count = m * counter.count;
    return Counter(new_count);
}

/// <summary>
/// https://www.youtube.com/watch?v=MzGC7H8ywZ0
/// </summary>
int run() {
    Counter counter1(7);
    counter1.increment();
    counter1.print();

    Counter counter2(3);
    counter2.print();

    Counter counter3 = counter1 + counter2;

    counter3.print();

    set_to_zero(counter3);

    counter3.print();

    Counter counter4(5);

    Counter counter5 = counter4 * 20;

    // You cant do this if you aint got friends.
    Counter counter5 = 20 * counter4;

    counter5.print();

    return 0;
}
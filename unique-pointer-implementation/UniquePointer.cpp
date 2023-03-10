#include <iostream>

using namespace std;

template <typename T>
class UniquePointer {
public:
    // Constructor
    explicit UniquePointer(T* ptr = nullptr) : ptr_(ptr) {}

    // Destructor
    ~UniquePointer() {
        delete ptr_;
    }

    // Copy constructor and assignment operator
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    // Move constructor and assignment operator
    UniquePointer(UniquePointer&& other) : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }
    UniquePointer& operator=(UniquePointer&& other) {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    // Member access operators
    T* operator->() const {
        return ptr_;
    }
    T& operator*() const {
        return *ptr_;
    }

    // Get pointer
    T* get() const {
        return ptr_;
    }

    // Release ownership
    T* release() {
        T* ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    // Reset pointer
    void reset(T* ptr = nullptr) {
        delete ptr_;
        ptr_ = ptr;
    }

private:
    T* ptr_;
};

int main()
{
    UniquePointer<int> up1(new int(42));
    UniquePointer<int> up2;
    cout << "move up1 to up2" << endl;
    up2 = move(up1);
    cout << "*up2: " << *up2 << endl;
    up2.reset(new int(17));
    cout << "reset up2 to int(17)" << endl;
    cout << "*up2: " << *up2 << endl;

    return 0;
}
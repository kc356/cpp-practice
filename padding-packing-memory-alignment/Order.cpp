#include <iostream>

using namespace std;

#pragma pack(1)
struct Order
{
    int qty;
    int prc;
    char side;
    char symbol[6];
};
static_assert(sizeof(Order) == 15);

int main()
{
    Order myOrder{12, 100, 'B', "GOOGL"};
    
    cout << "sizeof(myOrder): " << sizeof(myOrder) <<endl;

    auto orderStr = reinterpret_cast<char*>(&myOrder);
    auto order = reinterpret_cast<Order*>(orderStr);

    cout << "qty: " << order->qty <<endl;
    cout << "prc: " << order->prc <<endl;
    cout << "side: " << order->side <<endl;
    cout << "symbol: " << order->symbol <<endl;

    return 0;
}
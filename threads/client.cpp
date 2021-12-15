//
// Created by Anton Zaripov on 15.12.2021.
//
#include "hotel.cpp"
#include <iostream>

using namespace std;

class Client {
public:
    Client() = default;

    static void out(char type, int balance, int total) {
        switch (type) {
            case 'l':
                cout << "placing man with balance " << balance << " in the 200$ room; total cheapest: " << total
                     << '\n';
                break;
            case 'm':
                cout << "placing man with balance " << balance << " in the 400$ room; total middle: " << total
                     << '\n';
            case 'h':
                cout << "placing man with balance " << balance << " in the 600$ room; total highest: " << total
                     << '\n';
        }
    }

    static void payAndRent(Hotel *hotel, int balance) {
        //int balance = rand()%700;
        if (balance >= 200) {
            if (balance < 400) {
                if (hotel->lowest < 10) {
                    hotel->lowest++;
                    // out('l',balance,hotel->lowest);
                }
                //hotel->low[hotel->lowest] = this_thread::get_id();
            } else if (balance < 600) {
                if (hotel->middle < 10) {
                    hotel->middle++;
                    // out('m',balance,hotel->middle);
                } else if (hotel->lowest < 10) {
                    //hotel->low[hotel->lowest] = this_thread::get_id();
                    hotel->lowest++;
                    // out('l',balance,hotel->lowest);
                }
            } else if (balance >= 600) {
                if (hotel->high < 5) {
                    hotel->high++;
                    // out('h',balance,hotel->high);
                } else if (hotel->middle < 10) {
                    hotel->middle++;
                    // out('m',balance,hotel->middle);
                } else if (hotel->lowest < 10) {
                    //hotel->low[hotel->lowest] = this_thread::get_id();
                    hotel->lowest++;
                    //out('l',balance,hotel->lowest);
                }
            }
        }
    }
};
/*
class Concierge : public thread {
public :
    void moveCustomerAway(Hotel *hotel) {
        while (hotel->welcomes()) {
            continue;
        }
        exit(0);
    }
};*/


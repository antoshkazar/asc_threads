#include <iostream>
#include <list>
#include <thread>
#include <fstream>
#include <ctime>
#include "client.cpp"
#include "hotel.cpp"

using namespace std;
Hotel *hotel;

void stopProcess() {
    if (!hotel->welcomes()) {
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "incorrect command line!\n"
                "     command infile outfile01\n";
        return 1;
    }
    hotel = new Hotel();
    ifstream inputStream(argv[1]);
    int total;
    inputStream >> total;
    thread concierge(stopProcess);
    concierge.detach();
    for (int i = 0; i < total; ++i) {
        if (!hotel->welcomes()) {
            break;
        }
        int balance;
        inputStream >> balance; //>> index;
        auto *client1 = new Client();
        thread(client1->payAndRent, hotel, balance).join();
    }
    ofstream basicOfstream(argv[2]);
    hotel->out(basicOfstream);
    cout << "runtime = " << clock() / 1000000.0;
    return 0;
}

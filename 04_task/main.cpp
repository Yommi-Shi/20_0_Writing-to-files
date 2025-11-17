#include <iostream>
#include <fstream>
#include <string>


void print(int money[], const int size) {
    int total_amount = 0;
    int count_100 = 0;
    int count_200 = 0;
    int count_500 = 0;
    int count_1000 = 0;
    int count_2000 = 0;
    int count_5000 = 0;
    for (int i = 0; i < size; i++) {
        total_amount += money[i];
        switch (money[i]) {
            case 100: count_100++; break;
            case 200: count_200++; break;
            case 500: count_500++; break;
            case 1000: count_1000++; break;
            case 2000: count_2000++; break;
            case 5000: count_5000++; break;
        }
    }
    std::cout << "Total amount:" << total_amount << std::endl;
    std::cout << "\tNumber of bills 100: " << count_100 << "\n\tNumber of bills 200: " << count_200
        << "\n\tNumber of bills 500: " << count_500 << "\n\tNumber of bills 1000: " << count_1000
            << "\n\tNumber of bills 2000: " << count_2000 << "\n\tNumber of bills 5000: " << count_5000 << std::endl;
}


int main() {
    std::cout << "Simulation of ATM operation" << std::endl;

    int bills[] = {100, 200, 500, 1000, 2000, 5000};
    const int SIZE = 1000;
    int money[SIZE];

    std::ifstream in_file("atm.bin", std::ios::binary);
    if (in_file.is_open()) {
        in_file.read((char *) money, sizeof(money));
        print(money, 1000);
        in_file.close();
    } else {
        for (int i = 0; i < 1000; i++) {
            money[i] = 0;
        }
        std::cout << "ATM empty" << std::endl;
    }

    std::cout << "Enter operation:";
    std::string operation;
    std::cin >> operation;

    if (operation == "+") {
        for (int i = 0; i < 1000; i++) {
            if (money[i] == 0) {
                money[i] = bills[std::rand() % 6];
            }
        }
        std::ofstream out_file("atm.bin", std::ios::binary);
        out_file.write((char *) money, sizeof(money));
        print(money, SIZE);
        out_file.close();
        return 0;
    }

    if (operation == "-") {
        std::cout << "Amount:";
        int amount;
        std::cin >> amount;
        if (amount % 100 != 0) {
            std::cerr << "Invalid amount: " << amount << std::endl;
            return 1;
        }

        int collect = amount;
        for (int i = 5; i >= 0; i--) {
            int bill = bills[i];
            for (int j = 0; j < 1000; j++) {
                if (money[j] == bill) {
                    if (collect >= bill) {
                        money[j] = 0;
                        collect -= bill;
                        if (collect == 0) {
                            std::cout << "Amount taken:" << amount << std::endl;
                            std::ofstream out_file("atm.bin", std::ios::binary);
                            out_file.write((char *) money, sizeof(money));
                            out_file.close();
                            return 0;
                        }
                    }
                }
            }
        }
        std::cerr << "There is no suitable currency in the ATM" << std::endl;
    }

}
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>


int main() {
    std::cout << "Entry into the accounting record" << std::endl;

    std::cout << "Enter first name, last name, date of issue, payment amount:" << std::endl;

    std::ofstream file("statement.txt", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Something went wrong check the file path";
        return 1;
    }

    std::string str;
    std::getline(std::cin, str);
    std::stringstream temp(str);

    std::string first_name;
    std::string last_name;
    std::string data;
    std::string payment_amount;
    temp >> first_name >> last_name >> data >> payment_amount;

    for (int i = 0; i < first_name.length(); i++) {
        if (std::isdigit(first_name[i])) {
            std::cerr << "Incorrect first name entry" << std::endl;
            return 1;
        }

    }

    for (int i = 0; i < last_name.length(); i++) {
        if (std::isdigit(last_name[i])) {
            std::cerr << "Incorrect last name entry" << std::endl;
            return 1;
        }
    }

    int day = stoi(data.substr(0, 2));
    int month = stoi(data.substr(3, 2));
    std::string year = data.substr(6, 4);
    unsigned int year_len = year.length();
    if ((day < 1 || day > 31) || (month < 0 || month > 12) || year_len != 4) {
        std::cerr << "Incorrect date entry" << std::endl;
        return 1;
    }

    for (int i = 0; i < payment_amount.length(); i++) {
        if (!std::isdigit(payment_amount[i])) {
            std::cerr << "Incorrect payment amount entry" << std::endl;
            return 1;
        }
    }

    file << first_name << " " << last_name << " " << data << " " << payment_amount << "RUB" << std::endl;

    file.close();
}

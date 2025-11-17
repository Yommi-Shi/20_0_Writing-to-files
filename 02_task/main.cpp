#include <iostream>
#include <fstream>
#include <ctime>


int main() {
    std::cout << "Drawing random pictures" << std::endl;

    std::srand(std::time(nullptr));
    std::ofstream file("pic.txt");

    if (!file.is_open()) {
        std::cerr << "Something went wrong check the file path";
        return 1;
    }

    std::cout << "Enter height and width in pixels: ";
    int height_pix, width_pix;
    std::cin >> height_pix >> width_pix;

    for (int i = 0; i < height_pix; i++) {
        for (int j = 0; j < width_pix; j++) {
            file << std::rand() % 2;
        }
        file << std::endl;
    }

    file.close();
}


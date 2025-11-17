#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::cout << "Simulation of the game \"Fishing\"" << std::endl;

    std::ifstream in_file("river.txt");
    std::ofstream out_file("basket.txt", std::ios::app);

    if (!in_file.is_open() || !out_file.is_open()) {
        std::cerr << "Something went wrong check the file path";
        return 1;
    }

    std::cout << "To end fishing, enter \"end of fishing\"" << std::endl;

    std::cout << "What type of fish do you want to catch?" << std::endl;
    std::string target_fish;

    int caught_fish = 0;

    std::string end_game = "end of fishing";
    std::string type_fish;
    while (target_fish != end_game) {
        std::getline(std::cin, target_fish);
        while (!in_file.eof()) {
            in_file >> type_fish;

            if (type_fish == target_fish) {
                out_file << type_fish << std::endl;
                caught_fish++;
            }
        }
        in_file.seekg(0);
    }

    in_file.close();
    out_file.close();

    std::cout << "You caught " << caught_fish << " the fish" << std::endl;

}

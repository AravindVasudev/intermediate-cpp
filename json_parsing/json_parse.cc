#include <iostream>
#include "json.hpp"
using json = nlohmann::json;

int main(int argc, char **argv) {
    json test_json = {
        {"pi", 3.14159},
        {"r2", 1.414},
        {"name", "Aravind Vasudev"},
        {"nothing", nullptr},
        {"fav", {
                    {"color", "black"},
                    {"language", {"javascript", "python"}},
                    {"os", "Ubuntu"}
                }
        }
    };

    std::cout << test_json["name"] << "'s favorite color is " << test_json["fav"]["color"] << " and favorite OS is " << test_json["fav"]["os"] << "\n";
    std::cout << test_json;

}

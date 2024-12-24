#include <fmt/core.h>
#include <string>
#include <nlohmann/json.hpp>

int main()
{
    std::string name = "World";
    int version = 3;

    fmt::print("Hello {}, version {}\n", name, version);
    fmt::print("{:.2f}\n", 3.14159); // Prints: 3.14

    // Named arguments
    fmt::print("Hello {name}, you are {age} years old\n",
               fmt::arg("name", "Bob"),
               fmt::arg("age", 25));

    nlohmann::json j;
    j["name"] = "Alice";
    j["age"] = 30;
    fmt::print("{}\n", j.dump());

    return 0;
}
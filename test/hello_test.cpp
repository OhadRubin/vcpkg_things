#include <gtest/gtest.h>
#include <fmt/core.h>
#include <nlohmann/json.hpp>
#include <sstream>

// Test fixture class
class HelloWorldTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};

TEST_F(HelloWorldTest, FormatsFloatCorrectly) {
    std::string result = fmt::format("{:.2f}", 3.14159);
    EXPECT_EQ(result, "3.15");
}

TEST_F(HelloWorldTest, FormatsNamedArgumentsCorrectly) {
    std::string result = fmt::format("Hello {name}, you are {age} years old",
                                   fmt::arg("name", "Bob"),
                                   fmt::arg("age", 25));
    EXPECT_EQ(result, "Hello Bob, you are 25 years old");
}

TEST_F(HelloWorldTest, HandlesJsonCorrectly) {
    nlohmann::json j;
    j["name"] = "Alice";
    j["age"] = 30;
    EXPECT_EQ(j["name"], "Alice");
    EXPECT_EQ(j["age"], 30);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 
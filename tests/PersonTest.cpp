#include <gtest/gtest.h>
#include "Person.cpp"

TEST(person_test, Constructor){
    Person guy("Jake", "Aalto University");
    EXPECT_EQ(guy.get_name(), "Jake");
    EXPECT_EQ(guy.get_occupation(), "Aalto University");
}


TEST(person_test, Money) {
Person guy("Me", "Student");
    EXPECT_EQ(guy.get_money(), 500);
    guy.remove_money(500);
    EXPECT_EQ(guy.get_money(), 0);
    guy.add_money(10000);
    EXPECT_EQ(guy.get_money(), 10000);
    EXPECT_EQ(guy.has_money(), true);
}

TEST(person_test, RandomGenerator){
    Person guy("Nick", "LUT");
    EXPECT_NE(guy.get_time_coming(), 0);
    EXPECT_NE(guy.get_time_leaving(), 0);
}

TEST(person_test, happines){
    Person guy("Nikolai", "TUNI");
    EXPECT_EQ(guy.get_happiness(), 1000);
    guy.increase_happiness(1000);
    EXPECT_EQ(guy.get_happiness(), 2000);
    guy.decrease_happiness(2000);
    EXPECT_EQ(guy.get_happiness(), 0);
    EXPECT_EQ(guy.is_happy(), false);
}
TEST(person_test, foodAndHunger){
    Person guy("Jake", "Aalto University");
    EXPECT_EQ(guy.get_hunger(), 1500);
    EXPECT_EQ(guy.get_food(), 100);
    guy.add_food(300);
    EXPECT_EQ(guy.get_food(), 400);
    guy.eat_food(400);
    EXPECT_EQ(guy.get_food(), 0);
    EXPECT_EQ(guy.is_hungry(), 1);
}
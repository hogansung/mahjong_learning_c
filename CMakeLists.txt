cmake_minimum_required(VERSION 3.20)
project(mahjong_learning_c)

set(CMAKE_CXX_STANDARD 23)

add_executable(mahjong_learning_c main.cpp enums/tiletype.h tilesets/tileset.h tilesets/guangdong_tileset.h rulesets/ruleset.h rulesets/guangdong_ruleset.h rules/rule.h rules/condition.h rulesets/ruleset.cpp)

include_directories(.)
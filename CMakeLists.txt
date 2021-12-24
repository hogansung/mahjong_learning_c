cmake_minimum_required(VERSION 3.20)
project(mahjong_learning_c)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")

find_package(Boost 1.76.0 COMPONENTS program_options system thread filesystem serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(mahjong_learning_c main.cpp enums/tiletype.h tilesets/tileset.h tilesets/guangdong_tileset.h rulesets/ruleset.h rulesets/guangdong_ruleset.h rules/raw_rule.h state.h rules/rule.h tiletype_counter.h rules/raw_incremental_rule.h rules/raw_decremental_rule.h rules/raw_function_only_rule.h guangdong_common_tiletype_counter.h guangdong_bonus_tiletype_counter.h)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

include_directories(.)
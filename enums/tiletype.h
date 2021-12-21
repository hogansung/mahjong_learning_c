//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_TILETYPE_H
#define MAHJONG_LEARNING_C_TILETYPE_H

#include <vector>

enum class Tiletype {
  bambooOne = 0,             // 一條
  bambooTwo = 1,             // 二條
  bambooThree = 2,           // 三條
  bambooFour = 3,            // 四條
  bambooFive = 4,            // 五條
  bambooSix = 5,             // 六條
  bambooSeven = 6,           // 七條
  bambooEight = 7,           // 八條
  bambooNine = 8,            // 九條
  circleOne = 9,             // 一條
  circleTwo = 10,            // 二條
  circleThree = 11,          // 三條
  circleFour = 12,           // 四條
  circleFive = 13,           // 五條
  circleSix = 14,            // 六條
  circleSeven = 15,          // 七條
  circleEight = 16,          // 八條
  circleNine = 17,           // 九條
  characterOne = 18,         // 一條
  characterTwo = 19,         // 二條
  characterThree = 20,       // 三條
  characterFour = 21,        // 四條
  characterFive = 22,        // 五條
  characterSix = 23,         // 六條
  characterSeven = 24,       // 七條
  characterEight = 25,       // 八條
  characterNine = 26,        // 九條
  windEast = 27,             // 東
  windSouth = 28,            // 南
  windWest = 29,             // 西
  windNorth = 30,            // 北
  dragonRed = 31,            // 紅中
  dragonGreen = 32,          // 白板
  dragonWhite = 33,          // 發財
  seasonSpring = 34,         // 春
  seasonSummer = 35,         // 夏
  seasonAutumn = 36,         // 秋
  seasonWinter = 37,         // 冬
  flowerPlum = 38,           // 梅
  flowerOrchid = 39,         // 蘭
  flowerChrysanthemum = 40,  // 菊
  flowerBamboo = 41,         // 竹
};

typedef std::tuple<Tiletype, Tiletype> TwoSet;
typedef std::tuple<Tiletype, Tiletype, Tiletype> ThreeSet;

void pushBackTwoSet(std::vector<Tiletype>& requirements, TwoSet two_set) {
  requirements.emplace_back(std::get<0>(two_set));
  requirements.emplace_back(std::get<1>(two_set));
}

void popBackTwoSet(std::vector<Tiletype>& requirements) {
  requirements.pop_back();
  requirements.pop_back();
}

void pushBackThreeSet(std::vector<Tiletype>& requirements, ThreeSet three_set) {
  requirements.emplace_back(std::get<0>(three_set));
  requirements.emplace_back(std::get<1>(three_set));
  requirements.emplace_back(std::get<2>(three_set));
}

void popBackThreeSet(std::vector<Tiletype>& requirements) {
  requirements.pop_back();
  requirements.pop_back();
  requirements.pop_back();
}

#endif  // MAHJONG_LEARNING_C_TILETYPE_H

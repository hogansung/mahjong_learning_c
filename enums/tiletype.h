//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_TILETYPE_H
#define MAHJONG_LEARNING_C_TILETYPE_H

#include <vector>

enum class Tiletype {
  soOne = 0,                 // 一條
  soTwo = 1,                 // 二條
  soThree = 2,               // 三條
  soFour = 3,                // 四條
  soFive = 4,                // 五條
  soSix = 5,                 // 六條
  soSeven = 6,               // 七條
  soEight = 7,               // 八條
  soNine = 8,                // 九條
  pinOne = 9,                // 一條
  pinTwo = 10,               // 二條
  pinThree = 11,             // 三條
  pinFour = 12,              // 四條
  pinFive = 13,              // 五條
  pinSix = 14,               // 六條
  pinSeven = 15,             // 七條
  pinEight = 16,             // 八條
  pinNine = 17,              // 九條
  manOne = 18,               // 一條
  manTwo = 19,               // 二條
  manThree = 20,             // 三條
  manFour = 21,              // 四條
  manFive = 22,              // 五條
  manSix = 23,               // 六條
  manSeven = 24,             // 七條
  manEight = 25,             // 八條
  manNine = 26,              // 九條
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

#endif  // MAHJONG_LEARNING_C_TILETYPE_H

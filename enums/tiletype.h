//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_TILETYPE_H
#define MAHJONG_LEARNING_C_TILETYPE_H

#include <vector>

enum class TileType {
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

std::vector<TileType> allBambooTileTypes{
    TileType::bambooOne,   TileType::bambooTwo,   TileType::bambooThree,
    TileType::bambooFour,  TileType::bambooFive,  TileType::bambooSix,
    TileType::bambooSeven, TileType::bambooEight, TileType::bambooNine,
};

std::vector<TileType> allCircleTileTypes{
    TileType::circleOne,   TileType::circleTwo,   TileType::circleThree,
    TileType::circleFour,  TileType::circleFive,  TileType::circleSix,
    TileType::circleSeven, TileType::circleEight, TileType::circleNine,
};

std::vector<TileType> allCharacterTileTypes{
    TileType::characterOne,   TileType::characterTwo,
    TileType::characterThree, TileType::characterFour,
    TileType::characterFive,  TileType::characterSix,
    TileType::characterSeven, TileType::characterEight,
    TileType::characterNine,
};

std::vector<TileType> allSuitedTileTypes{
    TileType::bambooOne,      TileType::bambooTwo,
    TileType::bambooThree,    TileType::bambooFour,
    TileType::bambooFive,     TileType::bambooSix,
    TileType::bambooSeven,    TileType::bambooEight,
    TileType::bambooNine,     TileType::circleOne,
    TileType::circleTwo,      TileType::circleThree,
    TileType::circleFour,     TileType::circleFive,
    TileType::circleSix,      TileType::circleSeven,
    TileType::circleEight,    TileType::circleNine,
    TileType::characterOne,   TileType::characterTwo,
    TileType::characterThree, TileType::characterFour,
    TileType::characterFive,  TileType::characterSix,
    TileType::characterSeven, TileType::characterEight,
    TileType::characterNine,
};

std::vector<TileType> allWindTileTypes{
    TileType::windEast,
    TileType::windSouth,
    TileType::windWest,
    TileType::windNorth,
};

std::vector<TileType> allDragonTileTypes{
    TileType::dragonRed,
    TileType::dragonGreen,
    TileType::dragonWhite,
};

std::vector<TileType> allHonorTileTypes{
    TileType::windEast,    TileType::windSouth, TileType::windWest,
    TileType::windNorth,   TileType::dragonRed, TileType::dragonGreen,
    TileType::dragonWhite,
};

std::vector<TileType> allBonusTileTypes{
    TileType::seasonSpring,        TileType::seasonSummer,
    TileType::seasonAutumn,        TileType::seasonWinter,
    TileType::flowerPlum,          TileType::flowerOrchid,
    TileType::flowerChrysanthemum, TileType::flowerBamboo,
};

typedef std::tuple<TileType, TileType, TileType> ThreeSet;
typedef std::tuple<TileType, TileType, TileType> TwoSet;

#endif  // MAHJONG_LEARNING_C_TILETYPE_H

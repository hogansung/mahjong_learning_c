//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_TILESETS_GUANGDONG_TILESET_H_
#define MAHJONG_LEARNING_C_TILESETS_GUANGDONG_TILESET_H_

#include <unordered_map>

#include "enums/tiletype.h"
#include "tilesets/tileset.h"

class GuangdongTileset : public Tileset {
 public:
  GuangdongTileset()
      : Tileset(
            std::vector<Tiletype>{
                Tiletype::bambooOne,
                Tiletype::bambooTwo,
                Tiletype::bambooThree,
                Tiletype::bambooFour,
                Tiletype::bambooFive,
                Tiletype::bambooSix,
                Tiletype::bambooSeven,
                Tiletype::bambooEight,
                Tiletype::bambooNine,
            },
            std::vector<Tiletype>{
                Tiletype::circleOne,
                Tiletype::circleTwo,
                Tiletype::circleThree,
                Tiletype::circleFour,
                Tiletype::circleFive,
                Tiletype::circleSix,
                Tiletype::circleSeven,
                Tiletype::circleEight,
                Tiletype::circleNine,
            },
            std::vector<Tiletype>{
                Tiletype::characterOne,
                Tiletype::characterTwo,
                Tiletype::characterThree,
                Tiletype::characterFour,
                Tiletype::characterFive,
                Tiletype::characterSix,
                Tiletype::characterSeven,
                Tiletype::characterEight,
                Tiletype::characterNine,
            },
            std::vector<Tiletype>{
                Tiletype::windEast,
                Tiletype::windSouth,
                Tiletype::windWest,
                Tiletype::windNorth,
            },
            std::vector<Tiletype>{
                Tiletype::dragonRed,
                Tiletype::dragonGreen,
                Tiletype::dragonWhite,
            },
            std::vector<Tiletype>{
                Tiletype::seasonSpring,
                Tiletype::seasonSummer,
                Tiletype::seasonAutumn,
                Tiletype::seasonWinter,
            },
            std::vector<Tiletype>{
                Tiletype::flowerPlum,
                Tiletype::flowerOrchid,
                Tiletype::flowerChrysanthemum,
                Tiletype::flowerBamboo,
            }){};
};

#endif  // MAHJONG_LEARNING_C_TILESETS_GUANGDONG_TILESET_H_

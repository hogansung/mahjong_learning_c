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
            std::vector<std::tuple<Tiletype, unsigned int>>{
                std::make_tuple(Tiletype::bambooOne, 4),
                std::make_tuple(Tiletype::bambooTwo, 4),
                std::make_tuple(Tiletype::bambooThree, 4),
                std::make_tuple(Tiletype::bambooFour, 4),
                std::make_tuple(Tiletype::bambooFive, 4),
                std::make_tuple(Tiletype::bambooSix, 4),
                std::make_tuple(Tiletype::bambooSeven, 4),
                std::make_tuple(Tiletype::bambooEight, 4),
                std::make_tuple(Tiletype::bambooNine, 4),
            },
            std::vector<std::tuple<Tiletype, unsigned int>>{
                std::make_tuple(Tiletype::circleOne, 4),
                std::make_tuple(Tiletype::circleTwo, 4),
                std::make_tuple(Tiletype::circleThree, 4),
                std::make_tuple(Tiletype::circleFour, 4),
                std::make_tuple(Tiletype::circleFive, 4),
                std::make_tuple(Tiletype::circleSix, 4),
                std::make_tuple(Tiletype::circleSeven, 4),
                std::make_tuple(Tiletype::circleEight, 4),
                std::make_tuple(Tiletype::circleNine, 4),
            },
            std::vector<std::tuple<Tiletype, unsigned int>>{
                std::make_tuple(Tiletype::characterOne, 4),
                std::make_tuple(Tiletype::characterTwo, 4),
                std::make_tuple(Tiletype::characterThree, 4),
                std::make_tuple(Tiletype::characterFour, 4),
                std::make_tuple(Tiletype::characterFive, 4),
                std::make_tuple(Tiletype::characterSix, 4),
                std::make_tuple(Tiletype::characterSeven, 4),
                std::make_tuple(Tiletype::characterEight, 4),
                std::make_tuple(Tiletype::characterNine, 4),
            },
            std::vector<std::tuple<Tiletype, unsigned int>>{
                std::make_tuple(Tiletype::windEast, 4),
                std::make_tuple(Tiletype::windSouth, 4),
                std::make_tuple(Tiletype::windWest, 4),
                std::make_tuple(Tiletype::windNorth, 4),
            },
            std::vector<std::tuple<Tiletype, unsigned int>>{
                std::make_tuple(Tiletype::dragonRed, 4),
                std::make_tuple(Tiletype::dragonGreen, 4),
                std::make_tuple(Tiletype::dragonWhite, 4),
            },
            std::vector<std::tuple<Tiletype, unsigned int>>{
                std::make_tuple(Tiletype::seasonSpring, 1),
                std::make_tuple(Tiletype::seasonSummer, 1),
                std::make_tuple(Tiletype::seasonAutumn, 1),
                std::make_tuple(Tiletype::seasonWinter, 1),
            },
            std::vector<std::tuple<Tiletype, unsigned int>>{
                std::make_tuple(Tiletype::flowerPlum, 1),
                std::make_tuple(Tiletype::flowerOrchid, 1),
                std::make_tuple(Tiletype::flowerChrysanthemum, 1),
                std::make_tuple(Tiletype::flowerBamboo, 1),
            }){};
};

#endif  // MAHJONG_LEARNING_C_TILESETS_GUANGDONG_TILESET_H_

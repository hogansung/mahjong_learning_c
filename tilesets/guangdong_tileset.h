//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_TILESETS_GUANGDONG_TILESET_H_
#define MAHJONG_LEARNING_C_TILESETS_GUANGDONG_TILESET_H_

#include <sys/types.h>

#include <unordered_map>

#include "enums/tiletype.h"
#include "tilesets/tileset.h"

class GuangdongTileset : public Tileset {
 public:
  GuangdongTileset()
      : Tileset(
            std::vector<std::tuple<Tiletype, uint>>{
                std::make_tuple(Tiletype::soOne, 4),
                std::make_tuple(Tiletype::soTwo, 4),
                std::make_tuple(Tiletype::soThree, 4),
                std::make_tuple(Tiletype::soFour, 4),
                std::make_tuple(Tiletype::soFive, 4),
                std::make_tuple(Tiletype::soSix, 4),
                std::make_tuple(Tiletype::soSeven, 4),
                std::make_tuple(Tiletype::soEight, 4),
                std::make_tuple(Tiletype::soNine, 4),
            },
            std::vector<std::tuple<Tiletype, uint>>{
                std::make_tuple(Tiletype::pinOne, 4),
                std::make_tuple(Tiletype::pinTwo, 4),
                std::make_tuple(Tiletype::pinThree, 4),
                std::make_tuple(Tiletype::pinFour, 4),
                std::make_tuple(Tiletype::pinFive, 4),
                std::make_tuple(Tiletype::pinSix, 4),
                std::make_tuple(Tiletype::pinSeven, 4),
                std::make_tuple(Tiletype::pinEight, 4),
                std::make_tuple(Tiletype::pinNine, 4),
            },
            std::vector<std::tuple<Tiletype, uint>>{
                std::make_tuple(Tiletype::manOne, 4),
                std::make_tuple(Tiletype::manTwo, 4),
                std::make_tuple(Tiletype::manThree, 4),
                std::make_tuple(Tiletype::manFour, 4),
                std::make_tuple(Tiletype::manFive, 4),
                std::make_tuple(Tiletype::manSix, 4),
                std::make_tuple(Tiletype::manSeven, 4),
                std::make_tuple(Tiletype::manEight, 4),
                std::make_tuple(Tiletype::manNine, 4),
            },
            std::vector<std::tuple<Tiletype, uint>>{
                std::make_tuple(Tiletype::windEast, 4),
                std::make_tuple(Tiletype::windSouth, 4),
                std::make_tuple(Tiletype::windWest, 4),
                std::make_tuple(Tiletype::windNorth, 4),
            },
            std::vector<std::tuple<Tiletype, uint>>{
                std::make_tuple(Tiletype::dragonRed, 4),
                std::make_tuple(Tiletype::dragonGreen, 4),
                std::make_tuple(Tiletype::dragonWhite, 4),
            },
            std::vector<std::tuple<Tiletype, uint>>{
                std::make_tuple(Tiletype::seasonSpring, 1),
                std::make_tuple(Tiletype::seasonSummer, 1),
                std::make_tuple(Tiletype::seasonAutumn, 1),
                std::make_tuple(Tiletype::seasonWinter, 1),
            },
            std::vector<std::tuple<Tiletype, uint>>{
                std::make_tuple(Tiletype::flowerPlum, 1),
                std::make_tuple(Tiletype::flowerOrchid, 1),
                std::make_tuple(Tiletype::flowerChrysanthemum, 1),
                std::make_tuple(Tiletype::flowerBamboo, 1),
            }){};
};

#endif  // MAHJONG_LEARNING_C_TILESETS_GUANGDONG_TILESET_H_

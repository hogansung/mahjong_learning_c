//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULESETS_RULESET_H_
#define MAHJONG_LEARNING_C_RULESETS_RULESET_H_

#include "enums/tiletype.h"

class Ruleset {
  std::vector<ThreeSet> triplets{ThreeSet(TileType::)};
  std::vector<ThreeSet> sequences{
      ThreeSet(TileType::bambooOne, TileType::bambooTwo, TileType::bambooThree),
      ThreeSet(TileType::bambooTwo, TileType::bambooThree, TileType::bambooFour),
      ThreeSet(TileType::bambooThree, TileType::bambooFour, TileType::bambooFive),
      ThreeSet(TileType::bambooFour, TileType::bambooFive, TileType::bambooSix),
      ThreeSet(TileType::bambooFive, TileType::bambooSix, TileType::bambooSeven),
      ThreeSet(TileType::bambooSix, TileType::bambooSeven, TileType::bambooEight),
      ThreeSet(TileType::bambooSeven, TileType::bambooEight, TileType::bambooNine),
      ThreeSet(TileType::circleOne, TileType::circleTwo, TileType::circleThree),
      ThreeSet(TileType::circleTwo, TileType::circleThree, TileType::circleFour),
      ThreeSet(TileType::circleThree, TileType::circleFour, TileType::circleFive),
      ThreeSet(TileType::circleFour, TileType::circleFive, TileType::circleSix),
      ThreeSet(TileType::circleFive, TileType::circleSix, TileType::circleSeven),
      ThreeSet(TileType::circleSix, TileType::circleSeven, TileType::circleEight),
      ThreeSet(TileType::circleSeven, TileType::circleEight, TileType::circleNine),
      ThreeSet(TileType::characterOne, TileType::characterTwo, TileType::characterThree),
      ThreeSet(TileType::characterTwo, TileType::characterThree, TileType::characterFour),
      ThreeSet(TileType::characterThree, TileType::characterFour, TileType::characterFive),
      ThreeSet(TileType::characterFour, TileType::characterFive, TileType::characterSix),
      ThreeSet(TileType::characterFive, TileType::characterSix, TileType::characterSeven),
      ThreeSet(TileType::characterSix, TileType::characterSeven, TileType::characterEight),
      ThreeSet(TileType::characterSeven, TileType::characterEight, TileType::characterNine),
  };
};

#endif  // MAHJONG_LEARNING_C_RULESETS_RULESET_H_

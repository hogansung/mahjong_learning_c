//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULESETS_RULESET_H_
#define MAHJONG_LEARNING_C_RULESETS_RULESET_H_

#include "enums/tiletype.h"

class Ruleset {
 public:
  static void generateConditions(std::vector<Tiletype> existing_requirements,
                                 unsigned int max_n_pairs, unsigned int max_n_sequences,
                                 unsigned int max_n_triplets, unsigned int max_n_all);

  //  std::vector<ThreeSet> triplets{ThreeSet(Tiletype::)};
  //  std::vector<ThreeSet> sequences{
  //      ThreeSet(Tiletype::bambooOne, Tiletype::bambooTwo, Tiletype::bambooThree),
  //      ThreeSet(Tiletype::bambooTwo, Tiletype::bambooThree, Tiletype::bambooFour),
  //      ThreeSet(Tiletype::bambooThree, Tiletype::bambooFour, Tiletype::bambooFive),
  //      ThreeSet(Tiletype::bambooFour, Tiletype::bambooFive, Tiletype::bambooSix),
  //      ThreeSet(Tiletype::bambooFive, Tiletype::bambooSix, Tiletype::bambooSeven),
  //      ThreeSet(Tiletype::bambooSix, Tiletype::bambooSeven, Tiletype::bambooEight),
  //      ThreeSet(Tiletype::bambooSeven, Tiletype::bambooEight, Tiletype::bambooNine),
  //      ThreeSet(Tiletype::circleOne, Tiletype::circleTwo, Tiletype::circleThree),
  //      ThreeSet(Tiletype::circleTwo, Tiletype::circleThree, Tiletype::circleFour),
  //      ThreeSet(Tiletype::circleThree, Tiletype::circleFour, Tiletype::circleFive),
  //      ThreeSet(Tiletype::circleFour, Tiletype::circleFive, Tiletype::circleSix),
  //      ThreeSet(Tiletype::circleFive, Tiletype::circleSix, Tiletype::circleSeven),
  //      ThreeSet(Tiletype::circleSix, Tiletype::circleSeven, Tiletype::circleEight),
  //      ThreeSet(Tiletype::circleSeven, Tiletype::circleEight, Tiletype::circleNine),
  //      ThreeSet(Tiletype::characterOne, Tiletype::characterTwo, Tiletype::characterThree),
  //      ThreeSet(Tiletype::characterTwo, Tiletype::characterThree, Tiletype::characterFour),
  //      ThreeSet(Tiletype::characterThree, Tiletype::characterFour, Tiletype::characterFive),
  //      ThreeSet(Tiletype::characterFour, Tiletype::characterFive, Tiletype::characterSix),
  //      ThreeSet(Tiletype::characterFive, Tiletype::characterSix, Tiletype::characterSeven),
  //      ThreeSet(Tiletype::characterSix, Tiletype::characterSeven, Tiletype::characterEight),
  //      ThreeSet(Tiletype::characterSeven, Tiletype::characterEight, Tiletype::characterNine),
  //  };

  //  static generateConditions()
};

#endif  // MAHJONG_LEARNING_C_RULESETS_RULESET_H_

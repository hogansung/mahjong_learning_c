//
// Created by Hao-En Sung on 12/22/21.
//

#ifndef MAHJONG_LEARNING_C__STATE_H_
#define MAHJONG_LEARNING_C__STATE_H_

#include "enums/tiletype.h"
#include "tiletype_counter.h"

template <uint CommonTN, uint BonusTN, class CommonTC = TiletypeCounter<CommonTN>,
          class BonusTC = TiletypeCounter<BonusTN>>
class State {
 public:
  CommonTC common_tiletype_counter_;  // 萬, 桶, 條, 風, 三元牌
  BonusTC bonus_tiletype_counter_;    // 懸賞牌
  Tiletype last_tile_;
  bool is_kong_;
  uint exposed_sequence_num_;
  uint exposed_triplet_num_;
  uint exposed_kong_num_;
  uint concealed_kong_num_;
};

#endif  // MAHJONG_LEARNING_C__STATE_H_

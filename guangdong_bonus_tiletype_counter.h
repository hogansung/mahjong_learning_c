//
// Created by Hao-En Sung on 12/24/21.
//

#ifndef MAHJONG_LEARNING_C__GUANGDONG_BONUS_TILETYPE_COUNTER_H_
#define MAHJONG_LEARNING_C__GUANGDONG_BONUS_TILETYPE_COUNTER_H_

#include "tiletype_counter.h"

class GuangdongBonusTiletypeCounter final : public TiletypeCounter<8> {
 public:
  GuangdongBonusTiletypeCounter() : TiletypeCounter() {}
  GuangdongBonusTiletypeCounter(std::vector<Tiletype>& tiles) : TiletypeCounter(tiles, tileset_singleton_) {}
  GuangdongBonusTiletypeCounter(std::bitset<counter_size_>& counter) : TiletypeCounter(counter) {}

  const static std::hash<std::bitset<TiletypeCounter::counter_size_>> hash_func_;

  const Tileset& getTileset() { return tileset_singleton_; };

  const inline static Tileset tileset_singleton_ = GuangdongTileset();
};

bool operator==(const GuangdongBonusTiletypeCounter& ltc, const GuangdongBonusTiletypeCounter& rtc) {
  return ltc.counter_ == rtc.counter_;
}

template <>
struct std::hash<GuangdongBonusTiletypeCounter> {
  std::size_t operator()(GuangdongBonusTiletypeCounter const& tiletype_counter) const noexcept {
    return GuangdongBonusTiletypeCounter::hash_func_(tiletype_counter.counter_);
  }
};

#endif  // MAHJONG_LEARNING_C__GUANGDONG_BONUS_TILETYPE_COUNTER_H_

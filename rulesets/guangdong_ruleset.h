//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_
#define MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_

#include <vector>

#include "rules/raw_decremental_rule.h"
#include "rules/raw_function_only_rule.h"
#include "rules/raw_incremental_rule.h"
#include "rules/raw_rule.h"
#include "rulesets/ruleset.h"
#include "tilesets/tileset.h"

class GuangdongRuleset : public Ruleset {
 public:
  GuangdongRuleset() : Ruleset(GuangdongTileset(), 14, "guangdong_tiletype_counter_set_by_rules") {
    //    tiletype_counter_set_for_four_sets_one_pair_ =
    //        RawIncrementalRule("胡牌33332", 0, std::vector<std::vector<Tiletype>>{std::vector<Tiletype>()},
    //                           std::vector<std::tuple<uint, uint, uint>>{
    //                               std::make_tuple(1, 0, 4),
    //                               std::make_tuple(1, 1, 3),
    //                               std::make_tuple(1, 2, 2),
    //                               std::make_tuple(1, 3, 1),
    //                               std::make_tuple(1, 4, 0),
    //                           })
    //            .compile(tileset_, tile_num_);
    //    tiletype_counter_set_for_seven_pairs_ =
    //        RawIncrementalRule("胡牌2222222", 0, std::vector<std::vector<Tiletype>>{std::vector<Tiletype>()},
    //                           std::vector<std::tuple<uint, uint, uint>>{
    //                               std::make_tuple(7, 0, 0),
    //                           })
    //            .compile(tileset_, tile_num_);

    // Prepare all raw rules
    std::vector<RawRule*> raw_rule_ptr_vct = std::vector<RawRule*>{
        /* 一番 */
        // TODO: 自摸
        new RawIncrementalRule(
            "三元牌（一刻）", 1,
            std::vector<std::vector<Tiletype>>{
                std::vector<Tiletype>{Tiletype::dragonWhite, Tiletype::dragonWhite, Tiletype::dragonWhite},
                std::vector<Tiletype>{Tiletype::dragonGreen, Tiletype::dragonGreen, Tiletype::dragonGreen},
                std::vector<Tiletype>{Tiletype::dragonRed, Tiletype::dragonRed, Tiletype::dragonRed},
            },
            std::vector<std::tuple<uint, uint, uint>>{
                std::make_tuple(1, 0, 3),
                std::make_tuple(1, 1, 2),
                std::make_tuple(1, 2, 1),
                std::make_tuple(1, 3, 0),
            }),
        new RawIncrementalRule("明杠", 1, std::vector<std::vector<Tiletype>>{std::vector<Tiletype>()},
                               std::vector<std::tuple<uint, uint, uint>>{
                                   std::make_tuple(1, 0, 4),
                                   std::make_tuple(1, 1, 3),
                                   std::make_tuple(1, 2, 2),
                                   std::make_tuple(1, 3, 1),
                               },
                               [](const State& state) { return state.exposed_kong_num_ >= 1; }),
        new RawFunctionOnlyRule("無花", 1,
                                [](const State& state) {
                                  for (auto count : state.bonus_tiletype_counter_.counter_) {
                                    if (count) return false;
                                  }
                                  return true;
                                }),
        // TODO: 正花
        new RawFunctionOnlyRule(
            "門清", 1,
            [](const State& state) { return state.exposed_sequence_num_ == 0 and state.exposed_triplet_num_ == 0; }),
        // TODO: 海底撈月
        // TODO: 海底捞鱼
        // TODO: 絕張
        // TODO: 生張
        // TODO: 坎張
        new RawIncrementalRule("將眼", 1,
                               std::vector<std::vector<Tiletype>>{
                                   std::vector<Tiletype>{Tiletype::soTwo, Tiletype::soTwo},
                                   std::vector<Tiletype>{Tiletype::soFive, Tiletype::soFive},
                                   std::vector<Tiletype>{Tiletype::soEight, Tiletype::soEight},
                                   std::vector<Tiletype>{Tiletype::pinTwo, Tiletype::pinTwo},
                                   std::vector<Tiletype>{Tiletype::pinFive, Tiletype::pinFive},
                                   std::vector<Tiletype>{Tiletype::pinEight, Tiletype::pinEight},
                                   std::vector<Tiletype>{Tiletype::manTwo, Tiletype::manTwo},
                                   std::vector<Tiletype>{Tiletype::manFive, Tiletype::manFive},
                                   std::vector<Tiletype>{Tiletype::manEight, Tiletype::manEight},
                               },
                               std::vector<std::tuple<uint, uint, uint>>{
                                   std::make_tuple(0, 0, 4),
                                   std::make_tuple(0, 1, 3),
                                   std::make_tuple(0, 2, 2),
                                   std::make_tuple(0, 3, 1),
                                   std::make_tuple(0, 4, 0),
                               }),
        new RawIncrementalRule("簡單花么", 1,
                               std::vector<std::vector<Tiletype>>{
                                   std::vector<Tiletype>{Tiletype::soOne, Tiletype::soOne, Tiletype::soOne},
                                   std::vector<Tiletype>{Tiletype::soNine, Tiletype::soNine, Tiletype::soNine},
                                   std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinOne, Tiletype::pinOne},
                                   std::vector<Tiletype>{Tiletype::pinNine, Tiletype::pinNine, Tiletype::pinNine},
                                   std::vector<Tiletype>{Tiletype::manOne, Tiletype::manOne, Tiletype::manOne},
                                   std::vector<Tiletype>{Tiletype::manNine, Tiletype::manNine, Tiletype::manNine},
                               },
                               std::vector<std::tuple<uint, uint, uint>>{
                                   std::make_tuple(1, 0, 3),
                                   std::make_tuple(1, 1, 2),
                                   std::make_tuple(1, 2, 1),
                                   std::make_tuple(1, 3, 0),
                               }),
        // TODO: 莊家
        new RawIncrementalRule("般高", 1,
                               std::vector<std::vector<Tiletype>>{
                                   std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree,
                                                         Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree},
                                   std::vector<Tiletype>{Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour,
                                                         Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour},
                                   std::vector<Tiletype>{Tiletype::soThree, Tiletype::soFour, Tiletype::soFive,
                                                         Tiletype::soThree, Tiletype::soFour, Tiletype::soFive},
                                   std::vector<Tiletype>{Tiletype::soFour, Tiletype::soFive, Tiletype::soSix,
                                                         Tiletype::soFour, Tiletype::soFive, Tiletype::soSix},
                                   std::vector<Tiletype>{Tiletype::soFive, Tiletype::soSix, Tiletype::soSeven,
                                                         Tiletype::soFive, Tiletype::soSix, Tiletype::soSeven},
                                   std::vector<Tiletype>{Tiletype::soSix, Tiletype::soSeven, Tiletype::soEight,
                                                         Tiletype::soSix, Tiletype::soSeven, Tiletype::soEight},
                                   std::vector<Tiletype>{Tiletype::soSeven, Tiletype::soEight, Tiletype::soNine,
                                                         Tiletype::soSeven, Tiletype::soEight, Tiletype::soNine},
                                   std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree,
                                                         Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree},
                                   std::vector<Tiletype>{Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinFour,
                                                         Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinFour},
                                   std::vector<Tiletype>{Tiletype::pinThree, Tiletype::pinFour, Tiletype::pinFive,
                                                         Tiletype::pinThree, Tiletype::pinFour, Tiletype::pinFive},
                                   std::vector<Tiletype>{Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix,
                                                         Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix},
                                   std::vector<Tiletype>{Tiletype::pinFive, Tiletype::pinSix, Tiletype::pinSeven,
                                                         Tiletype::pinFive, Tiletype::pinSix, Tiletype::pinSeven},
                                   std::vector<Tiletype>{Tiletype::pinSix, Tiletype::pinSeven, Tiletype::pinEight,
                                                         Tiletype::pinSix, Tiletype::pinSeven, Tiletype::pinEight},
                                   std::vector<Tiletype>{Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinNine,
                                                         Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinNine},
                                   std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree,
                                                         Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree},
                                   std::vector<Tiletype>{Tiletype::manTwo, Tiletype::manThree, Tiletype::manFour,
                                                         Tiletype::manTwo, Tiletype::manThree, Tiletype::manFour},
                                   std::vector<Tiletype>{Tiletype::manThree, Tiletype::manFour, Tiletype::manFive,
                                                         Tiletype::manThree, Tiletype::manFour, Tiletype::manFive},
                                   std::vector<Tiletype>{Tiletype::manFour, Tiletype::manFive, Tiletype::manSix,
                                                         Tiletype::manFour, Tiletype::manFive, Tiletype::manSix},
                                   std::vector<Tiletype>{Tiletype::manFive, Tiletype::manSix, Tiletype::manSeven,
                                                         Tiletype::manFive, Tiletype::manSix, Tiletype::manSeven},
                                   std::vector<Tiletype>{Tiletype::manSix, Tiletype::manSeven, Tiletype::manEight,
                                                         Tiletype::manSix, Tiletype::manSeven, Tiletype::manEight},
                                   std::vector<Tiletype>{Tiletype::manSeven, Tiletype::manEight, Tiletype::manNine,
                                                         Tiletype::manSeven, Tiletype::manEight, Tiletype::manNine},
                               },
                               std::vector<std::tuple<uint, uint, uint>>{
                                   std::make_tuple(1, 0, 2),
                                   std::make_tuple(1, 1, 1),
                                   std::make_tuple(1, 2, 0),
                               }),
        // TODO: 卡五
        // TODO: 單吊
        // TODO: 偏張
        new RawIncrementalRule("老少", 1,
                               std::vector<std::vector<Tiletype>>{
                                   std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree,
                                                         Tiletype::soSeven, Tiletype::soEight, Tiletype::soNine},
                                   std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree,
                                                         Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinNine},
                                   std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree,
                                                         Tiletype::manSeven, Tiletype::manEight, Tiletype::manNine},
                                   std::vector<Tiletype>{Tiletype::soOne, Tiletype::soOne, Tiletype::soOne,
                                                         Tiletype::soNine, Tiletype::soNine, Tiletype::soNine},
                                   std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinOne, Tiletype::pinOne,
                                                         Tiletype::pinNine, Tiletype::pinNine, Tiletype::pinNine},
                                   std::vector<Tiletype>{Tiletype::manOne, Tiletype::manOne, Tiletype::manOne,
                                                         Tiletype::manNine, Tiletype::manNine, Tiletype::manNine},
                               },
                               std::vector<std::tuple<uint, uint, uint>>{
                                   std::make_tuple(1, 0, 2),
                                   std::make_tuple(1, 1, 1),
                                   std::make_tuple(1, 2, 0),
                               }),
        new RawIncrementalRule("彩龍", 1,
                               std::vector<std::vector<Tiletype>>{
                                   std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree,
                                                         Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix,
                                                         Tiletype::manSeven, Tiletype::manEight, Tiletype::manNine},
                                   std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree,
                                                         Tiletype::manFour, Tiletype::manFive, Tiletype::manSix,
                                                         Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinNine},
                                   std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree,
                                                         Tiletype::soFour, Tiletype::soFive, Tiletype::soSix,
                                                         Tiletype::manSeven, Tiletype::manEight, Tiletype::manNine},
                                   std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree,
                                                         Tiletype::manFour, Tiletype::manFive, Tiletype::manSix,
                                                         Tiletype::soSeven, Tiletype::soEight, Tiletype::soNine},
                                   std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree,
                                                         Tiletype::soFour, Tiletype::soFive, Tiletype::soSix,
                                                         Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinNine},
                                   std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree,
                                                         Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix,
                                                         Tiletype::soSeven, Tiletype::soEight, Tiletype::soNine},
                               },
                               std::vector<std::tuple<uint, uint, uint>>{
                                   std::make_tuple(1, 0, 1),
                                   std::make_tuple(1, 1, 0),
                               }),
        // TODO: 搶杠
        new RawIncrementalRule(
            "兩杠", 1, std::vector<std::vector<Tiletype>>{std::vector<Tiletype>()},
            std::vector<std::tuple<uint, uint, uint>>{
                std::make_tuple(1, 0, 4),
                std::make_tuple(1, 1, 3),
                std::make_tuple(1, 2, 2),
            },
            [](const State& state) { return state.exposed_kong_num_ + state.concealed_kong_num_ >= 2; }),
        new RawIncrementalRule("清四碰", 1, std::vector<std::vector<Tiletype>>{std::vector<Tiletype>()},
                               std::vector<std::tuple<uint, uint, uint>>{
                                   std::make_tuple(1, 0, 4),
                               },
                               [](const State& state) { return state.exposed_triplet_num_ == 4; }),
        // TODO: 四歸一
        // TODO: 半求人
        new RawIncrementalRule("兩色兩顺", 1,
                               std::vector<std::vector<Tiletype>>{
                                   std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree,
                                                         Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree},
                                   std::vector<Tiletype>{Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour,
                                                         Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinFour},
                                   std::vector<Tiletype>{Tiletype::soThree, Tiletype::soFour, Tiletype::soFive,
                                                         Tiletype::pinThree, Tiletype::pinFour, Tiletype::pinFive},
                                   std::vector<Tiletype>{Tiletype::soFour, Tiletype::soFive, Tiletype::soSix,
                                                         Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix},
                                   std::vector<Tiletype>{Tiletype::soFive, Tiletype::soSix, Tiletype::soSeven,
                                                         Tiletype::pinFive, Tiletype::pinSix, Tiletype::pinSeven},
                                   std::vector<Tiletype>{Tiletype::soSix, Tiletype::soSeven, Tiletype::soEight,
                                                         Tiletype::pinSix, Tiletype::pinSeven, Tiletype::pinEight},
                                   std::vector<Tiletype>{Tiletype::soSeven, Tiletype::soEight, Tiletype::soNine,
                                                         Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinNine},
                                   std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree,
                                                         Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree},
                                   std::vector<Tiletype>{Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour,
                                                         Tiletype::manTwo, Tiletype::manThree, Tiletype::manFour},
                                   std::vector<Tiletype>{Tiletype::soThree, Tiletype::soFour, Tiletype::soFive,
                                                         Tiletype::manThree, Tiletype::manFour, Tiletype::manFive},
                                   std::vector<Tiletype>{Tiletype::soFour, Tiletype::soFive, Tiletype::soSix,
                                                         Tiletype::manFour, Tiletype::manFive, Tiletype::manSix},
                                   std::vector<Tiletype>{Tiletype::soFive, Tiletype::soSix, Tiletype::soSeven,
                                                         Tiletype::manFive, Tiletype::manSix, Tiletype::manSeven},
                                   std::vector<Tiletype>{Tiletype::soSix, Tiletype::soSeven, Tiletype::soEight,
                                                         Tiletype::manSix, Tiletype::manSeven, Tiletype::manEight},
                                   std::vector<Tiletype>{Tiletype::soSeven, Tiletype::soEight, Tiletype::soNine,
                                                         Tiletype::manSeven, Tiletype::manEight, Tiletype::manNine},
                                   std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree,
                                                         Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree},
                                   std::vector<Tiletype>{Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinFour,
                                                         Tiletype::manTwo, Tiletype::manThree, Tiletype::manFour},
                                   std::vector<Tiletype>{Tiletype::pinThree, Tiletype::pinFour, Tiletype::pinFive,
                                                         Tiletype::manThree, Tiletype::manFour, Tiletype::manFive},
                                   std::vector<Tiletype>{Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix,
                                                         Tiletype::manFour, Tiletype::manFive, Tiletype::manSix},
                                   std::vector<Tiletype>{Tiletype::pinFive, Tiletype::pinSix, Tiletype::pinSeven,
                                                         Tiletype::manFive, Tiletype::manSix, Tiletype::manSeven},
                                   std::vector<Tiletype>{Tiletype::pinSix, Tiletype::pinSeven, Tiletype::pinEight,
                                                         Tiletype::manSix, Tiletype::manSeven, Tiletype::manEight},
                                   std::vector<Tiletype>{Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinNine,
                                                         Tiletype::manSeven, Tiletype::manEight, Tiletype::manNine},
                               },
                               std::vector<std::tuple<uint, uint, uint>>{
                                   std::make_tuple(1, 0, 2),
                                   std::make_tuple(1, 1, 1),
                                   std::make_tuple(1, 2, 0),
                               }),
        new RawIncrementalRule("連六", 1,
                               std::vector<std::vector<Tiletype>>{
                                   std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree,
                                                         Tiletype::soFour, Tiletype::soFive, Tiletype::soSix},
                                   std::vector<Tiletype>{Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour,
                                                         Tiletype::soFive, Tiletype::soSix, Tiletype::soSeven},
                                   std::vector<Tiletype>{Tiletype::soThree, Tiletype::soFour, Tiletype::soFive,
                                                         Tiletype::soSix, Tiletype::soSeven, Tiletype::soEight},
                                   std::vector<Tiletype>{Tiletype::soFour, Tiletype::soFive, Tiletype::soSix,
                                                         Tiletype::soSeven, Tiletype::soEight, Tiletype::soNine},
                                   std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree,
                                                         Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix},
                                   std::vector<Tiletype>{Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinFour,
                                                         Tiletype::pinFive, Tiletype::pinSix, Tiletype::pinSeven},
                                   std::vector<Tiletype>{Tiletype::pinThree, Tiletype::pinFour, Tiletype::pinFive,
                                                         Tiletype::pinSix, Tiletype::pinSeven, Tiletype::pinEight},
                                   std::vector<Tiletype>{Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix,
                                                         Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinNine},
                                   std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree,
                                                         Tiletype::manFour, Tiletype::manFive, Tiletype::manSix},
                                   std::vector<Tiletype>{Tiletype::manTwo, Tiletype::manThree, Tiletype::manFour,
                                                         Tiletype::manFive, Tiletype::manSix, Tiletype::manSeven},
                                   std::vector<Tiletype>{Tiletype::manThree, Tiletype::manFour, Tiletype::manFive,
                                                         Tiletype::manSix, Tiletype::manSeven, Tiletype::manEight},
                                   std::vector<Tiletype>{Tiletype::manFour, Tiletype::manFive, Tiletype::manSix,
                                                         Tiletype::manSeven, Tiletype::manEight, Tiletype::manNine},
                               },
                               std::vector<std::tuple<uint, uint, uint>>{
                                   std::make_tuple(1, 0, 2),
                                   std::make_tuple(1, 1, 1),
                                   std::make_tuple(1, 2, 0),
                               }),
        /* 三番 */
        // TODO: 門風, 圈風, 花槓, 暗槓, 全求人, 門清自摸, 槓上開花, 雙暗刻, 斷幺九, 一條龍, 三色同順, 五門齊,
        //  四歸二, 混帶夭九, 雙同刻, 三尾, 三料牌, 斷紅
        new RawIncrementalRule("平和", 3,
                               std::vector<std::vector<Tiletype>>{
                                   std::vector<Tiletype>{Tiletype::windEast, Tiletype::windEast},
                                   std::vector<Tiletype>{Tiletype::windSouth, Tiletype::windSouth},
                                   std::vector<Tiletype>{Tiletype::windWest, Tiletype::windWest},
                                   std::vector<Tiletype>{Tiletype::windNorth, Tiletype::windNorth},
                                   std::vector<Tiletype>{Tiletype::dragonWhite, Tiletype::dragonWhite},
                                   std::vector<Tiletype>{Tiletype::dragonGreen, Tiletype::dragonGreen},
                                   std::vector<Tiletype>{Tiletype::dragonRed, Tiletype::dragonRed},
                               },
                               std::vector<std::tuple<uint, uint, uint>>{
                                   std::make_tuple(0, 4, 0),
                               }),
        /* 五番 */
        // TODO:
        /* 七番 */
        // TODO:
        /* 八番 */
        // TODO:
        /* 十番 */
        // TODO:
        /* 十五番 */
        // TODO:
        /* 二十番 */
        // TODO:
        /* 三十番 */
        // TODO:
        /* 四十番 */
        // TODO:

        // 特殊：组合龍, 三元七對, 七搶一, 全不靠, 荒牌十番, 四喜七對, 八仙過海, 十三魔殿, 十三金字塔, 十三騎士,
        // 十三幺, 連七對,

    };

    //    std::vector<RawRule*> raw_decremental_rule_ptr_vct = std::vector<RawRule*>{
    //        /* 一番 */
    //        new RawDecrementalRule("缺五", 1,
    //                               std::vector<std::vector<Tiletype>>{
    //                                   std::vector<Tiletype>{Tiletype::soFive, Tiletype::pinFive, Tiletype::manFive},
    //                               },
    //                               tiletype_counter_set_for_four_sets_one_pair_),
    //        new RawDecrementalRule(
    //            "無字", 1,
    //            std::vector<std::vector<Tiletype>>{
    //                std::vector<Tiletype>{Tiletype::windEast, Tiletype::windSouth, Tiletype::windWest,
    //                Tiletype::windNorth,
    //                                      Tiletype::dragonWhite, Tiletype::dragonGreen, Tiletype::dragonRed},
    //            },
    //            tiletype_counter_set_for_four_sets_one_pair_),
    //        new RawDecrementalRule(
    //            "缺門", 1,
    //            std::vector<std::vector<Tiletype>>{
    //                std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour,
    //                                      Tiletype::soFive, Tiletype::soSix, Tiletype::soSeven, Tiletype::soEight,
    //                                      Tiletype::soNine, Tiletype::windEast, Tiletype::windSouth,
    //                                      Tiletype::windWest, Tiletype::windNorth, Tiletype::dragonWhite,
    //                                      Tiletype::dragonGreen, Tiletype::dragonRed},
    //                std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinFour,
    //                                      Tiletype::pinFive, Tiletype::pinSix, Tiletype::pinSeven, Tiletype::pinEight,
    //                                      Tiletype::pinNine, Tiletype::windEast, Tiletype::windSouth,
    //                                      Tiletype::windWest, Tiletype::windNorth, Tiletype::dragonWhite,
    //                                      Tiletype::dragonGreen, Tiletype::dragonRed},
    //                std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree, Tiletype::manFour,
    //                                      Tiletype::manFive, Tiletype::manSix, Tiletype::manSeven, Tiletype::manEight,
    //                                      Tiletype::manNine, Tiletype::windEast, Tiletype::windSouth,
    //                                      Tiletype::windWest, Tiletype::windNorth, Tiletype::dragonWhite,
    //                                      Tiletype::dragonGreen, Tiletype::dragonRed},
    //            },
    //            tiletype_counter_set_for_four_sets_one_pair_),
    //    };

    // Compile raw rules into rules and deallocate raw rules
    compileRawRules(raw_rule_ptr_vct);
    for (auto raw_rule_ptr : raw_rule_ptr_vct) {
      delete raw_rule_ptr;
    }
  };
};

#endif  // MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_

//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_
#define MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_

#include <vector>

#include "rules/rule.h"
#include "rulesets/ruleset.h"
#include "tilesets/tileset.h"

class GuangdongRuleset : public Ruleset {
 public:
  GuangdongRuleset() : Ruleset(GuangdongTileset()) {
    // Preprocess all common valid combinations
    tiletype_counters_for_four_sets_one_pair_ = generateTiletypeCountersIncrementally(
        std::vector<std::vector<Tiletype>>{std::vector<Tiletype>()}, std::tuple<uint, uint>(1, 1),
        std::tuple<uint, uint>(0, 4), std::tuple<uint, uint>(0, 4), 14);
    tiletype_counters_for_seven_pairs_ = generateTiletypeCountersIncrementally(
        std::vector<std::vector<Tiletype>>{std::vector<Tiletype>()}, std::tuple<uint, uint>(7, 7),
        std::tuple<uint, uint>(0, 0), std::tuple<uint, uint>(0, 0), 14);

    // Prepare all rules
    rules_ = std::vector<Rule>{
        /* 一番 */
        // TODO: 自摸
        Rule("三元牌（一刻）",
             generateTiletypeCountersIncrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::dragonWhite, Tiletype::dragonWhite, Tiletype::dragonWhite},
                     std::vector<Tiletype>{Tiletype::dragonGreen, Tiletype::dragonGreen, Tiletype::dragonGreen},
                     std::vector<Tiletype>{Tiletype::dragonRed, Tiletype::dragonRed, Tiletype::dragonRed},
                 },
                 std::tuple<uint, uint>(1, 1), std::tuple<uint, uint>(0, 3), std::tuple<uint, uint>(0, 3), 14),
             1),
        // TODO: 明杠
        Rule("無花",
             generateTiletypeCountersDecrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::flowerPlum, Tiletype::flowerOrchid, Tiletype::flowerChrysanthemum,
                                           Tiletype::flowerBamboo},
                 },
                 tiletype_counters_for_four_sets_one_pair_),
             1),
        // TODO: 正花
        // TODO: 門清
        // TODO: 海底撈月
        // TODO: 海底捞鱼
        // TODO: 絕張
        // TODO: 生張
        // TODO: 坎張
        Rule("將眼",
             generateTiletypeCountersIncrementally(
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
                 std::tuple<uint, uint>(0, 0), std::tuple<uint, uint>(0, 4), std::tuple<uint, uint>(0, 4), 14),
             1),
        Rule("缺五",
             generateTiletypeCountersDecrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::soFive, Tiletype::pinFive, Tiletype::manFive},
                 },
                 tiletype_counters_for_four_sets_one_pair_),
             1),
        Rule("簡單花么",
             generateTiletypeCountersIncrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::soOne, Tiletype::soOne, Tiletype::soOne},
                     std::vector<Tiletype>{Tiletype::soNine, Tiletype::soNine, Tiletype::soNine},
                     std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinOne, Tiletype::pinOne},
                     std::vector<Tiletype>{Tiletype::pinNine, Tiletype::pinNine, Tiletype::pinNine},
                     std::vector<Tiletype>{Tiletype::manOne, Tiletype::manOne, Tiletype::manOne},
                     std::vector<Tiletype>{Tiletype::manNine, Tiletype::manNine, Tiletype::manNine},
                 },
                 std::tuple<uint, uint>(1, 1), std::tuple<uint, uint>(0, 3), std::tuple<uint, uint>(0, 3), 14),

             1),
        Rule("無字",
             generateTiletypeCountersDecrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::windEast, Tiletype::windSouth, Tiletype::windWest,
                                           Tiletype::windNorth, Tiletype::dragonWhite, Tiletype::dragonGreen,
                                           Tiletype::dragonRed},
                 },
                 tiletype_counters_for_four_sets_one_pair_),
             1),
        // TODO: 莊家
        Rule("般高",
             generateTiletypeCountersIncrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree, Tiletype::soOne,
                                           Tiletype::soTwo, Tiletype::soThree},
                     std::vector<Tiletype>{Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour, Tiletype::soTwo,
                                           Tiletype::soThree, Tiletype::soFour},
                     std::vector<Tiletype>{Tiletype::soThree, Tiletype::soFour, Tiletype::soFive, Tiletype::soThree,
                                           Tiletype::soFour, Tiletype::soFive},
                     std::vector<Tiletype>{Tiletype::soFour, Tiletype::soFive, Tiletype::soSix, Tiletype::soFour,
                                           Tiletype::soFive, Tiletype::soSix},
                     std::vector<Tiletype>{Tiletype::soFive, Tiletype::soSix, Tiletype::soSeven, Tiletype::soFive,
                                           Tiletype::soSix, Tiletype::soSeven},
                     std::vector<Tiletype>{Tiletype::soSix, Tiletype::soSeven, Tiletype::soEight, Tiletype::soSix,
                                           Tiletype::soSeven, Tiletype::soEight},
                     std::vector<Tiletype>{Tiletype::soSeven, Tiletype::soEight, Tiletype::soNine, Tiletype::soSeven,
                                           Tiletype::soEight, Tiletype::soNine},
                     std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinOne,
                                           Tiletype::pinTwo, Tiletype::pinThree},
                     std::vector<Tiletype>{Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinFour, Tiletype::pinTwo,
                                           Tiletype::pinThree, Tiletype::pinFour},
                     std::vector<Tiletype>{Tiletype::pinThree, Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinThree,
                                           Tiletype::pinFour, Tiletype::pinFive},
                     std::vector<Tiletype>{Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix, Tiletype::pinFour,
                                           Tiletype::pinFive, Tiletype::pinSix},
                     std::vector<Tiletype>{Tiletype::pinFive, Tiletype::pinSix, Tiletype::pinSeven, Tiletype::pinFive,
                                           Tiletype::pinSix, Tiletype::pinSeven},
                     std::vector<Tiletype>{Tiletype::pinSix, Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinSix,
                                           Tiletype::pinSeven, Tiletype::pinEight},
                     std::vector<Tiletype>{Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinNine,
                                           Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinNine},
                     std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree, Tiletype::manOne,
                                           Tiletype::manTwo, Tiletype::manThree},
                     std::vector<Tiletype>{Tiletype::manTwo, Tiletype::manThree, Tiletype::manFour, Tiletype::manTwo,
                                           Tiletype::manThree, Tiletype::manFour},
                     std::vector<Tiletype>{Tiletype::manThree, Tiletype::manFour, Tiletype::manFive, Tiletype::manThree,
                                           Tiletype::manFour, Tiletype::manFive},
                     std::vector<Tiletype>{Tiletype::manFour, Tiletype::manFive, Tiletype::manSix, Tiletype::manFour,
                                           Tiletype::manFive, Tiletype::manSix},
                     std::vector<Tiletype>{Tiletype::manFive, Tiletype::manSix, Tiletype::manSeven, Tiletype::manFive,
                                           Tiletype::manSix, Tiletype::manSeven},
                     std::vector<Tiletype>{Tiletype::manSix, Tiletype::manSeven, Tiletype::manEight, Tiletype::manSix,
                                           Tiletype::manSeven, Tiletype::manEight},
                     std::vector<Tiletype>{Tiletype::manSeven, Tiletype::manEight, Tiletype::manNine,
                                           Tiletype::manSeven, Tiletype::manEight, Tiletype::manNine},
                 },
                 std::tuple<uint, uint>(1, 1), std::tuple<uint, uint>(0, 2), std::tuple<uint, uint>(0, 2), 14),
             1),
        // TODO: 卡五
        // TODO: 單吊
        // TODO: 偏張
        Rule("老少",
             generateTiletypeCountersIncrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree, Tiletype::soSeven,
                                           Tiletype::soEight, Tiletype::soNine},
                     std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinSeven,
                                           Tiletype::pinEight, Tiletype::pinNine},
                     std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree, Tiletype::manSeven,
                                           Tiletype::manEight, Tiletype::manNine},
                     std::vector<Tiletype>{Tiletype::soOne, Tiletype::soOne, Tiletype::soOne, Tiletype::soNine,
                                           Tiletype::soNine, Tiletype::soNine},
                     std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinOne, Tiletype::pinOne, Tiletype::pinNine,
                                           Tiletype::pinNine, Tiletype::pinNine},
                     std::vector<Tiletype>{Tiletype::manOne, Tiletype::manOne, Tiletype::manOne, Tiletype::manNine,
                                           Tiletype::manNine, Tiletype::manNine},
                 },
                 std::tuple<uint, uint>(1, 1), std::tuple<uint, uint>(0, 2), std::tuple<uint, uint>(0, 2), 14),
             1),
        Rule("缺門",
             generateTiletypeCountersDecrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour,
                                           Tiletype::soFive, Tiletype::soSix, Tiletype::soSeven, Tiletype::soEight,
                                           Tiletype::soNine, Tiletype::windEast, Tiletype::windSouth,
                                           Tiletype::windWest, Tiletype::windNorth, Tiletype::dragonWhite,
                                           Tiletype::dragonGreen, Tiletype::dragonRed},
                     std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinFour,
                                           Tiletype::pinFive, Tiletype::pinSix, Tiletype::pinSeven, Tiletype::pinEight,
                                           Tiletype::pinNine, Tiletype::windEast, Tiletype::windSouth,
                                           Tiletype::windWest, Tiletype::windNorth, Tiletype::dragonWhite,
                                           Tiletype::dragonGreen, Tiletype::dragonRed},
                     std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree, Tiletype::manFour,
                                           Tiletype::manFive, Tiletype::manSix, Tiletype::manSeven, Tiletype::manEight,
                                           Tiletype::manNine, Tiletype::windEast, Tiletype::windSouth,
                                           Tiletype::windWest, Tiletype::windNorth, Tiletype::dragonWhite,
                                           Tiletype::dragonGreen, Tiletype::dragonRed},
                 },
                 tiletype_counters_for_four_sets_one_pair_),
             1),
        Rule("彩龍",
             generateTiletypeCountersIncrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree, Tiletype::pinFour,
                                           Tiletype::pinFive, Tiletype::pinSix, Tiletype::manSeven, Tiletype::manEight,
                                           Tiletype::manNine},
                     std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree, Tiletype::manFour,
                                           Tiletype::manFive, Tiletype::manSix, Tiletype::pinSeven, Tiletype::pinEight,
                                           Tiletype::pinNine},
                     std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree, Tiletype::soFour,
                                           Tiletype::soFive, Tiletype::soSix, Tiletype::manSeven, Tiletype::manEight,
                                           Tiletype::manNine},
                     std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree, Tiletype::manFour,
                                           Tiletype::manFive, Tiletype::manSix, Tiletype::soSeven, Tiletype::soEight,
                                           Tiletype::soNine},
                     std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree, Tiletype::soFour,
                                           Tiletype::soFive, Tiletype::soSix, Tiletype::pinSeven, Tiletype::pinEight,
                                           Tiletype::pinNine},
                     std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree, Tiletype::pinFour,
                                           Tiletype::pinFive, Tiletype::pinSix, Tiletype::soSeven, Tiletype::soEight,
                                           Tiletype::soNine},
                 },
                 std::tuple<uint, uint>(1, 1), std::tuple<uint, uint>(0, 1), std::tuple<uint, uint>(0, 1), 14),
             1),
        // TODO: 搶杠
        // TODO: 兩杠
        // TODO: 清四碰
        // TODO: 四歸一
        // TODO: 半求人
        Rule("兩色兩顺",
             generateTiletypeCountersIncrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree, Tiletype::pinOne,
                                           Tiletype::pinTwo, Tiletype::pinThree},
                     std::vector<Tiletype>{Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour, Tiletype::pinTwo,
                                           Tiletype::pinThree, Tiletype::pinFour},
                     std::vector<Tiletype>{Tiletype::soThree, Tiletype::soFour, Tiletype::soFive, Tiletype::pinThree,
                                           Tiletype::pinFour, Tiletype::pinFive},
                     std::vector<Tiletype>{Tiletype::soFour, Tiletype::soFive, Tiletype::soSix, Tiletype::pinFour,
                                           Tiletype::pinFive, Tiletype::pinSix},
                     std::vector<Tiletype>{Tiletype::soFive, Tiletype::soSix, Tiletype::soSeven, Tiletype::pinFive,
                                           Tiletype::pinSix, Tiletype::pinSeven},
                     std::vector<Tiletype>{Tiletype::soSix, Tiletype::soSeven, Tiletype::soEight, Tiletype::pinSix,
                                           Tiletype::pinSeven, Tiletype::pinEight},
                     std::vector<Tiletype>{Tiletype::soSeven, Tiletype::soEight, Tiletype::soNine, Tiletype::pinSeven,
                                           Tiletype::pinEight, Tiletype::pinNine},
                     std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree, Tiletype::manOne,
                                           Tiletype::manTwo, Tiletype::manThree},
                     std::vector<Tiletype>{Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour, Tiletype::manTwo,
                                           Tiletype::manThree, Tiletype::manFour},
                     std::vector<Tiletype>{Tiletype::soThree, Tiletype::soFour, Tiletype::soFive, Tiletype::manThree,
                                           Tiletype::manFour, Tiletype::manFive},
                     std::vector<Tiletype>{Tiletype::soFour, Tiletype::soFive, Tiletype::soSix, Tiletype::manFour,
                                           Tiletype::manFive, Tiletype::manSix},
                     std::vector<Tiletype>{Tiletype::soFive, Tiletype::soSix, Tiletype::soSeven, Tiletype::manFive,
                                           Tiletype::manSix, Tiletype::manSeven},
                     std::vector<Tiletype>{Tiletype::soSix, Tiletype::soSeven, Tiletype::soEight, Tiletype::manSix,
                                           Tiletype::manSeven, Tiletype::manEight},
                     std::vector<Tiletype>{Tiletype::soSeven, Tiletype::soEight, Tiletype::soNine, Tiletype::manSeven,
                                           Tiletype::manEight, Tiletype::manNine},
                     std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree, Tiletype::manOne,
                                           Tiletype::manTwo, Tiletype::manThree},
                     std::vector<Tiletype>{Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinFour, Tiletype::manTwo,
                                           Tiletype::manThree, Tiletype::manFour},
                     std::vector<Tiletype>{Tiletype::pinThree, Tiletype::pinFour, Tiletype::pinFive, Tiletype::manThree,
                                           Tiletype::manFour, Tiletype::manFive},
                     std::vector<Tiletype>{Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix, Tiletype::manFour,
                                           Tiletype::manFive, Tiletype::manSix},
                     std::vector<Tiletype>{Tiletype::pinFive, Tiletype::pinSix, Tiletype::pinSeven, Tiletype::manFive,
                                           Tiletype::manSix, Tiletype::manSeven},
                     std::vector<Tiletype>{Tiletype::pinSix, Tiletype::pinSeven, Tiletype::pinEight, Tiletype::manSix,
                                           Tiletype::manSeven, Tiletype::manEight},
                     std::vector<Tiletype>{Tiletype::pinSeven, Tiletype::pinEight, Tiletype::pinNine,
                                           Tiletype::manSeven, Tiletype::manEight, Tiletype::manNine},
                 },
                 std::tuple<uint, uint>(1, 1), std::tuple<uint, uint>(0, 2), std::tuple<uint, uint>(0, 2), 14),
             1),
        Rule("連六",
             generateTiletypeCountersIncrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::soOne, Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour,
                                           Tiletype::soFive, Tiletype::soSix},
                     std::vector<Tiletype>{Tiletype::soTwo, Tiletype::soThree, Tiletype::soFour, Tiletype::soFive,
                                           Tiletype::soSix, Tiletype::soSeven},
                     std::vector<Tiletype>{Tiletype::soThree, Tiletype::soFour, Tiletype::soFive, Tiletype::soSix,
                                           Tiletype::soSeven, Tiletype::soEight},
                     std::vector<Tiletype>{Tiletype::soFour, Tiletype::soFive, Tiletype::soSix, Tiletype::soSeven,
                                           Tiletype::soEight, Tiletype::soNine},
                     std::vector<Tiletype>{Tiletype::pinOne, Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinFour,
                                           Tiletype::pinFive, Tiletype::pinSix},
                     std::vector<Tiletype>{Tiletype::pinTwo, Tiletype::pinThree, Tiletype::pinFour, Tiletype::pinFive,
                                           Tiletype::pinSix, Tiletype::pinSeven},
                     std::vector<Tiletype>{Tiletype::pinThree, Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix,
                                           Tiletype::pinSeven, Tiletype::pinEight},
                     std::vector<Tiletype>{Tiletype::pinFour, Tiletype::pinFive, Tiletype::pinSix, Tiletype::pinSeven,
                                           Tiletype::pinEight, Tiletype::pinNine},
                     std::vector<Tiletype>{Tiletype::manOne, Tiletype::manTwo, Tiletype::manThree, Tiletype::manFour,
                                           Tiletype::manFive, Tiletype::manSix},
                     std::vector<Tiletype>{Tiletype::manTwo, Tiletype::manThree, Tiletype::manFour, Tiletype::manFive,
                                           Tiletype::manSix, Tiletype::manSeven},
                     std::vector<Tiletype>{Tiletype::manThree, Tiletype::manFour, Tiletype::manFive, Tiletype::manSix,
                                           Tiletype::manSeven, Tiletype::manEight},
                     std::vector<Tiletype>{Tiletype::manFour, Tiletype::manFive, Tiletype::manSix, Tiletype::manSeven,
                                           Tiletype::manEight, Tiletype::manNine},
                 },
                 std::tuple<uint, uint>(1, 1), std::tuple<uint, uint>(0, 2), std::tuple<uint, uint>(0, 2), 14),
             1),
        /* 三番 */
        // TODO: 門風, 圈風, 花槓, 暗槓, 全求人, 門清自摸, 槓上開花, 雙暗刻, 斷幺九, 一條龍, 三色同順, 五門齊,
        //  四歸二, 混帶夭九, 雙同刻, 三尾, 三料牌, 斷紅
        Rule("平和",
             generateTiletypeCountersIncrementally(
                 std::vector<std::vector<Tiletype>>{
                     std::vector<Tiletype>{Tiletype::windEast, Tiletype::windEast},
                     std::vector<Tiletype>{Tiletype::windSouth, Tiletype::windSouth},
                     std::vector<Tiletype>{Tiletype::windWest, Tiletype::windWest},
                     std::vector<Tiletype>{Tiletype::windNorth, Tiletype::windNorth},
                     std::vector<Tiletype>{Tiletype::dragonWhite, Tiletype::dragonWhite},
                     std::vector<Tiletype>{Tiletype::dragonGreen, Tiletype::dragonGreen},
                     std::vector<Tiletype>{Tiletype::dragonRed, Tiletype::dragonRed},
                 },
                 std::tuple<uint, uint>(0, 0), std::tuple<uint, uint>(4, 4), std::tuple<uint, uint>(0, 0), 14),
             0),
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
  };
};

#endif  // MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_

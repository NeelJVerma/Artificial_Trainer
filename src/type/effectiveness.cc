/**
 * @project Artificial Trainer
 * @brief The implementation of the Effectiveness function.
 *
 * @file effectiveness.cc
 * @author Neel Verma
 * @date 1/26/19
 */

#include "effectiveness.h"

namespace artificialtrainer {
namespace {
const double kEffectivenessMatrix[kNumTypes][kNumTypes] = {
    {1, 1, 1, 1, 1, 0.5, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {2, 1, 0.5, 0.5, 1, 2, 0.5, 0, 1, 1, 1, 1, 0.5, 2, 1, 1},
    {1, 2, 1, 1, 1, 0.5, 2, 1, 1, 1, 2, 0.5, 1, 1, 1, 1},
    {1, 1, 1, 0.5, 0.5, 0.5, 2, 0.5, 1, 1, 2, 1, 1, 1, 1, 1},
    {1, 1, 0, 2, 1, 2, 0.5, 1, 2, 1, 0.5, 2, 1, 1, 1, 1},
    {1, 0.5, 2, 1, 0.5, 1, 2, 1, 2, 1, 1, 1, 1, 2, 1, 1},
    {1, 0.5, 0.5, 2, 1, 1, 1, 0.5, 0.5, 1, 2, 1, 2, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 0.5, 2, 1, 0.5, 0.5, 2, 1, 1, 2, 0.5, 1},
    {1, 1, 1, 1, 2, 2, 1, 1, 2, 0.5, 0.5, 1, 1, 1, 0.5, 1},
    {1, 1, 0.5, 0.5, 2, 2, 0.5, 1, 0.5, 2, 0.5, 1, 1, 1, 0.5, 1},
    {1, 1, 2, 1, 0, 1, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 0.5, 1},
    {1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1},
    {1, 1, 2, 1, 2, 1, 1, 1, 1, 0.5, 2, 1, 1, 0.5, 2, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

} //namespace

/**
  * @brief: A function to get the effectiveness of a type matchup.
  * @param const TypeNames &attacking: The attacking type (The row in the
  * above matrix.
  * @param const TypeNames &defending: The defending type (The column in the
  * above matrix.
  * @double: The effectiveness.
  */

double Effectiveness(const TypeNames &attacking, const TypeNames &defending) {
  return kEffectivenessMatrix[static_cast<int>(attacking)][static_cast<int>(
      defending)];
}

} //namespace artificialtrainer
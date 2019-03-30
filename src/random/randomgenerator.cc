//
// Created by neel on 3/30/19.
//

#include <random>

namespace artificialtrainer {
namespace {

std::mt19937& RandomGenerator() {
  static std::random_device device;
  static std::mt19937 generator(device());
  return generator;
}

} //namespace

double RandomRealDistribution(const double& lower, const double& upper) {
  std::uniform_real_distribution<> distribution(lower, upper);
  return distribution(RandomGenerator());
}

int RandomIntDistribution(const int &lower, const int &upper) {
  std::uniform_int_distribution<> distribution(lower, upper);
  return distribution(RandomGenerator());
}

} //namespace artificialtrainer
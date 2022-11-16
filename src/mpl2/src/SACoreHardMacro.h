///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (c) 2021, The Regents of the University of California
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>

#include "SimulatedAnnealingCore.h"
#include "object.h"

namespace utl {
class Logger;
}

namespace mpl {

// Class SimulatedAnnealingCore is a base class
// It will have two derived classes:
// 1) SACoreHardMacro : SA for hard macros.  It will be called by ShapeEngine
// and PinAlignEngine 2) SACoreSoftMacro : SA for soft macros.  It will be
// called by MacroPlaceEngine
class SACoreHardMacro : public SimulatedAnnealingCore<HardMacro>
{
 public:
  SACoreHardMacro(float outline_width,
                  float outline_height,  // boundary constraints
                  const std::vector<HardMacro>& macros,
                  // weight for different penalty
                  float area_weight,
                  float outline_weight,
                  float wirelength_weight,
                  float guidance_weight,
                  float fence_weight,  // each blockage will be modeled by a
                                       // macro with fences
                  // probability of each action
                  float pos_swap_prob,
                  float neg_swap_prob,
                  float double_swap_prob,
                  float exchange_prob,
                  float flip_prob,
                  // Fast SA hyperparameter
                  float init_prob,
                  int max_num_step,
                  int num_perturb_per_step,
                  int k,
                  int c,
                  unsigned seed = 0,
                  utl::Logger* logger_ = nullptr);

  // Initialize the SA worker
  void initialize() override;
  void fillDeadSpace() override {}
  // print results
  void printResults();

 private:
  float calNormCost() override;
  void calPenalty() override;
  void shrink() override {}

  void perturb() override;
  void restore() override;
  // actions used
  void flipMacro();  // flip hard macros

  float flip_prob_ = 0.0;
};

}  // namespace mpl

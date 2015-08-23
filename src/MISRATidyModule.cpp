//===--- MISRATidyModule.cpp - clang-tidy-misra ---------------------------===//
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"
#include "rules/c2012/17.1.h"

namespace clang {
namespace tidy {
namespace misra {

class MISRAModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<c2012::Rule_17_1>("misra-c2012-17.1");
  }
};

// Register the MISRATidyModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<MISRAModule> X("misra-module",
                                                   "Adds MISRA rule checks.");

} // namespace misra

// This anchor is used to force the linker to link in the generated object file
// and thus register the MISRAModule.
volatile int MISRAModuleAnchorSource = 0;

} // namespace tidy
} // namespace clang

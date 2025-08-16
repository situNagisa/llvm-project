#pragma once

#include "Address.h"

namespace clang {
namespace CodeGen {

struct EHStaticExceptionContext {
  Address CXXFlag = Address::invalid();
  Address CXXStdError = Address::invalid();

  auto isValid() const { return CXXFlag.isValid() && CXXStdError.isValid(); }
  void EmitFalse(CodeGenFunction &CGF) const;
  void EmitTrue(CodeGenFunction &CGF) const;
  void EmitStdError(CodeGenFunction &CGF, Expr const *E) const;
};

}
}

//===- AMDGPUToROCDL.h - Convert AMDGPU to ROCDL dialect --*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef MLIR_CONVERSION_AMDGPUTOROCDL_AMDGPUTOROCDL_H_
#define MLIR_CONVERSION_AMDGPUTOROCDL_AMDGPUTOROCDL_H_

#include "mlir/Dialect/AMDGPU/Utils/Chipset.h"
#include <memory>
#include <string>

namespace mlir {

class LLVMTypeConverter;
class RewritePatternSet;
class Pass;

#define GEN_PASS_DECL_CONVERTAMDGPUTOROCDLPASS
#include "mlir/Conversion/Passes.h.inc"

/// Note: The ROCDL target does not support the LLVM bfloat type at this time
/// and so this function will add conversions to change all `bfloat` uses
/// to `i16`.
void populateAMDGPUToROCDLConversionPatterns(const LLVMTypeConverter &converter,
                                             RewritePatternSet &patterns,
                                             amdgpu::Chipset chipset);

} // namespace mlir

#endif // MLIR_CONVERSION_AMDGPUTOROCDL_AMDGPUTOROCDL_H_

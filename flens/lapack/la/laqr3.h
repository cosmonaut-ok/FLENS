/*
 *   Copyright (c) 2011, Michael Lehn
 *
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1) Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2) Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *   3) Neither the name of the FLENS development group nor the names of
 *      its contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Based on
 *
      SUBROUTINE DLAQR3( WANTT, WANTZ, N, KTOP, KBOT, NW, H, LDH, ILOZ,
     $                   IHIZ, Z, LDZ, NS, ND, SR, SI, V, LDV, NH, T,
     $                   LDT, NV, WV, LDWV, WORK, LWORK )
      SUBROUTINE ZLAQR3( WANTT, WANTZ, N, KTOP, KBOT, NW, H, LDH, ILOZ,
     $                   IHIZ, Z, LDZ, NS, ND, SH, V, LDV, NH, T, LDT,
     $                   NV, WV, LDWV, WORK, LWORK )
 *
 *  -- LAPACK auxiliary routine (version 3.2.2)                        --
 *     Univ. of Tennessee, Univ. of California Berkeley,
 *     Univ. of Colorado Denver and NAG Ltd..
 *  -- June 2010                                                       --
 *
 */

#ifndef FLENS_LAPACK_LA_LAQR3_H
#define FLENS_LAPACK_LA_LAQR3_H 1

#include <flens/matrixtypes/matrixtypes.h>
#include <flens/vectortypes/vectortypes.h>

namespace flens { namespace lapack {

//== laqr3 =====================================================================
//
//  Real variant
//
template <typename IndexType, typename MH, typename MZ, typename VSR,
          typename VSI, typename MV, typename MT, typename MWV, typename VWORK>
    typename RestrictTo<IsRealGeMatrix<MH>::value
                     && IsRealGeMatrix<MZ>::value
                     && IsRealDenseVector<VSR>::value
                     && IsRealDenseVector<VSI>::value
                     && IsRealGeMatrix<MV>::value
                     && IsRealGeMatrix<MT>::value
                     && IsRealGeMatrix<MWV>::value
                     && IsRealDenseVector<VWORK>::value,
             void>::Type
    laqr3(bool                      wantT,
          bool                      wantZ,
          IndexType                 kTop,
          IndexType                 kBot,
          IndexType                 nw,
          MH                        &&H,
          IndexType                 iLoZ,
          IndexType                 iHiZ,
          MZ                        &&Z,
          IndexType                 &ns,
          IndexType                 &nd,
          VSR                       &&sr,
          VSI                       &&si,
          MV                        &&V,
          MT                        &&T,
          MWV                       &&WV,
          VWORK                     &&work);

//
//  Complex variant
//
template <typename IndexType, typename MH, typename MZ, typename VSH,
          typename MV, typename MT, typename MWV, typename VWORK>
    typename RestrictTo<IsComplexGeMatrix<MH>::value
                     && IsComplexGeMatrix<MZ>::value
                     && IsComplexDenseVector<VSH>::value
                     && IsComplexGeMatrix<MV>::value
                     && IsComplexGeMatrix<MT>::value
                     && IsComplexGeMatrix<MWV>::value
                     && IsComplexDenseVector<VWORK>::value,
             void>::Type
    laqr3(bool                      wantT,
          bool                      wantZ,
          IndexType                 kTop,
          IndexType                 kBot,
          IndexType                 nw,
          MH                        &&H,
          IndexType                 iLoZ,
          IndexType                 iHiZ,
          MZ                        &&Z,
          IndexType                 &ns,
          IndexType                 &nd,
          VSH                       &&sh,
          MV                        &&V,
          MT                        &&T,
          MWV                       &&WV,
          VWORK                     &&work);


//
//  Workspace query (real/complex variant)
//
template <typename IndexType, typename MT>
    IndexType
    laqr3_wsq(IndexType             kTop,
              IndexType             kBot,
              IndexType             nw,
              const GeMatrix<MT>    &T);


} } // namespace lapack, flens

#endif // FLENS_LAPACK_LA_LAQR3_H

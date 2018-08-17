
/*---------------------------------------------------------------*/
/*--- begin                              guest_mips_helpers.c ---*/
/*---------------------------------------------------------------*/

/*
   This file is part of Valgrind, a dynamic binary instrumentation
   framework.

   Copyright (C) 2010-2017 RT-RK
      mips-valgrind@rt-rk.com

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307, USA.

   The GNU General Public License is contained in the file COPYING.
*/

#include "libvex_basictypes.h"
#include "libvex_emnote.h"
#include "libvex_guest_mips32.h"
#include "libvex_guest_mips64.h"
#include "libvex_ir.h"
#include "libvex.h"

#include "main_util.h"
#include "main_globals.h"
#include "guest_generic_bb_to_IR.h"
#include "guest_mips_defs.h"

/* This file contains helper functions for mips guest code.  Calls to
   these functions are generated by the back end.
*/

#define ALWAYSDEFD32(field)                            \
    { offsetof(VexGuestMIPS32State, field),            \
      (sizeof ((VexGuestMIPS32State*)0)->field) }

#define ALWAYSDEFD64(field)                            \
    { offsetof(VexGuestMIPS64State, field),            \
      (sizeof ((VexGuestMIPS64State*)0)->field) }

IRExpr *guest_mips32_spechelper(const HChar * function_name, IRExpr ** args,
                                IRStmt ** precedingStmts, Int n_precedingStmts)
{
   return NULL;
}

IRExpr *guest_mips64_spechelper ( const HChar * function_name, IRExpr ** args,
                                  IRStmt ** precedingStmts,
                                  Int n_precedingStmts )
{
   return NULL;
}

/* VISIBLE TO LIBVEX CLIENT */
void LibVEX_GuestMIPS32_initialise( /*OUT*/ VexGuestMIPS32State * vex_state)
{
   vex_state->guest_r0 = 0;   /* Hardwired to 0 */
   vex_state->guest_r1 = 0;   /* Assembler temporary */
   vex_state->guest_r2 = 0;   /* Values for function returns ... */
   vex_state->guest_r3 = 0;   /* ...and expression evaluation */
   vex_state->guest_r4 = 0;   /* Function arguments */
   vex_state->guest_r5 = 0;
   vex_state->guest_r6 = 0;
   vex_state->guest_r7 = 0;
   vex_state->guest_r8 = 0;   /* Temporaries */
   vex_state->guest_r9 = 0;
   vex_state->guest_r10 = 0;
   vex_state->guest_r11 = 0;
   vex_state->guest_r12 = 0;
   vex_state->guest_r13 = 0;
   vex_state->guest_r14 = 0;
   vex_state->guest_r15 = 0;
   vex_state->guest_r16 = 0;  /* Saved temporaries */
   vex_state->guest_r17 = 0;
   vex_state->guest_r18 = 0;
   vex_state->guest_r19 = 0;
   vex_state->guest_r20 = 0;
   vex_state->guest_r21 = 0;
   vex_state->guest_r22 = 0;
   vex_state->guest_r23 = 0;
   vex_state->guest_r24 = 0;  /* Temporaries */
   vex_state->guest_r25 = 0;
   vex_state->guest_r26 = 0;  /* Reserved for OS kernel */
   vex_state->guest_r27 = 0;
   vex_state->guest_r28 = 0;  /* Global pointer */
   vex_state->guest_r29 = 0;  /* Stack pointer */
   vex_state->guest_r30 = 0;  /* Frame pointer */
   vex_state->guest_r31 = 0;  /* Return address */
   vex_state->guest_PC = 0;   /* Program counter */
   vex_state->guest_HI = 0;   /* Multiply and divide register higher result */
   vex_state->guest_LO = 0;   /* Multiply and divide register lower result */

   /* FPU Registers */
   vex_state->guest_f0 = 0x7ff800007ff80000ULL; /* Floting point GP registers */
   vex_state->guest_f1 = 0x7ff800007ff80000ULL;
   vex_state->guest_f2 = 0x7ff800007ff80000ULL;
   vex_state->guest_f3 = 0x7ff800007ff80000ULL;
   vex_state->guest_f4 = 0x7ff800007ff80000ULL;
   vex_state->guest_f5 = 0x7ff800007ff80000ULL;
   vex_state->guest_f6 = 0x7ff800007ff80000ULL;
   vex_state->guest_f7 = 0x7ff800007ff80000ULL;
   vex_state->guest_f8 = 0x7ff800007ff80000ULL;
   vex_state->guest_f9 = 0x7ff800007ff80000ULL;
   vex_state->guest_f10 = 0x7ff800007ff80000ULL;
   vex_state->guest_f11 = 0x7ff800007ff80000ULL;
   vex_state->guest_f12 = 0x7ff800007ff80000ULL;
   vex_state->guest_f13 = 0x7ff800007ff80000ULL;
   vex_state->guest_f14 = 0x7ff800007ff80000ULL;
   vex_state->guest_f15 = 0x7ff800007ff80000ULL;
   vex_state->guest_f16 = 0x7ff800007ff80000ULL;
   vex_state->guest_f17 = 0x7ff800007ff80000ULL;
   vex_state->guest_f18 = 0x7ff800007ff80000ULL;
   vex_state->guest_f19 = 0x7ff800007ff80000ULL;
   vex_state->guest_f20 = 0x7ff800007ff80000ULL;
   vex_state->guest_f21 = 0x7ff800007ff80000ULL;
   vex_state->guest_f22 = 0x7ff800007ff80000ULL;
   vex_state->guest_f23 = 0x7ff800007ff80000ULL;
   vex_state->guest_f24 = 0x7ff800007ff80000ULL;
   vex_state->guest_f25 = 0x7ff800007ff80000ULL;
   vex_state->guest_f26 = 0x7ff800007ff80000ULL;
   vex_state->guest_f27 = 0x7ff800007ff80000ULL;
   vex_state->guest_f28 = 0x7ff800007ff80000ULL;
   vex_state->guest_f29 = 0x7ff800007ff80000ULL;
   vex_state->guest_f30 = 0x7ff800007ff80000ULL;
   vex_state->guest_f31 = 0x7ff800007ff80000ULL;

   vex_state->guest_FIR = 0;  /* FP implementation and revision register */
   vex_state->guest_FCCR = 0; /* FP condition codes register */
   vex_state->guest_FEXR = 0; /* FP exceptions register */
   vex_state->guest_FENR = 0; /* FP enables register */
   vex_state->guest_FCSR = 0; /* FP control/status register */
   vex_state->guest_ULR = 0; /* TLS */

   /* Various pseudo-regs mandated by Vex or Valgrind. */
   /* Emulation notes */
   vex_state->guest_EMNOTE = 0;

   /* For clflush: record start and length of area to invalidate */
   vex_state->guest_CMSTART = 0;
   vex_state->guest_CMLEN = 0;
   vex_state->host_EvC_COUNTER = 0;
   vex_state->host_EvC_FAILADDR = 0;

   /* Used to record the unredirected guest address at the start of
      a translation whose start has been redirected. By reading
      this pseudo-register shortly afterwards, the translation can
      find out what the corresponding no-redirection address was.
      Note, this is only set for wrap-style redirects, not for
      replace-style ones. */
   vex_state->guest_NRADDR = 0;

   vex_state->guest_COND = 0;

   vex_state->guest_CP0_status = 0;

   vex_state->guest_LLaddr = 0xFFFFFFFF;
   vex_state->guest_LLdata = 0;

   /* MIPS32 DSP ASE(r2) specific registers */
   vex_state->guest_DSPControl = 0;   /* DSPControl register */
   vex_state->guest_ac0 = 0;          /* Accumulator 0 */
   vex_state->guest_ac1 = 0;          /* Accumulator 1 */
   vex_state->guest_ac2 = 0;          /* Accumulator 2 */
   vex_state->guest_ac3 = 0;          /* Accumulator 3 */
}

void LibVEX_GuestMIPS64_initialise ( /*OUT*/ VexGuestMIPS64State * vex_state )
{
   vex_state->guest_r0 = 0;  /* Hardwired to 0 */
   vex_state->guest_r1 = 0;  /* Assembler temporary */
   vex_state->guest_r2 = 0;  /* Values for function returns ... */
   vex_state->guest_r3 = 0;
   vex_state->guest_r4 = 0;  /* Function arguments */
   vex_state->guest_r5 = 0;
   vex_state->guest_r6 = 0;
   vex_state->guest_r7 = 0;
   vex_state->guest_r8 = 0;
   vex_state->guest_r9 = 0;
   vex_state->guest_r10 = 0;
   vex_state->guest_r11 = 0;
   vex_state->guest_r12 = 0;  /* Temporaries */
   vex_state->guest_r13 = 0;
   vex_state->guest_r14 = 0;
   vex_state->guest_r15 = 0;
   vex_state->guest_r16 = 0;  /* Saved temporaries */
   vex_state->guest_r17 = 0;
   vex_state->guest_r18 = 0;
   vex_state->guest_r19 = 0;
   vex_state->guest_r20 = 0;
   vex_state->guest_r21 = 0;
   vex_state->guest_r22 = 0;
   vex_state->guest_r23 = 0;
   vex_state->guest_r24 = 0;  /* Temporaries */
   vex_state->guest_r25 = 0;
   vex_state->guest_r26 = 0;  /* Reserved for OS kernel */
   vex_state->guest_r27 = 0;
   vex_state->guest_r28 = 0;  /* Global pointer */
   vex_state->guest_r29 = 0;  /* Stack pointer */
   vex_state->guest_r30 = 0;  /* Frame pointer */
   vex_state->guest_r31 = 0;  /* Return address */
   vex_state->guest_PC = 0;   /* Program counter */
   vex_state->guest_HI = 0;   /* Multiply and divide register higher result */
   vex_state->guest_LO = 0;   /* Multiply and divide register lower result */

   /* FPU Registers */
   vex_state->guest_f0 =  0x7ff800007ff80000ULL;  /* Floting point registers */
   vex_state->guest_f1 =  0x7ff800007ff80000ULL;
   vex_state->guest_f2 =  0x7ff800007ff80000ULL;
   vex_state->guest_f3 =  0x7ff800007ff80000ULL;
   vex_state->guest_f4 =  0x7ff800007ff80000ULL;
   vex_state->guest_f5 =  0x7ff800007ff80000ULL;
   vex_state->guest_f6 =  0x7ff800007ff80000ULL;
   vex_state->guest_f7 =  0x7ff800007ff80000ULL;
   vex_state->guest_f8 =  0x7ff800007ff80000ULL;
   vex_state->guest_f9 =  0x7ff800007ff80000ULL;
   vex_state->guest_f10 = 0x7ff800007ff80000ULL;
   vex_state->guest_f11 = 0x7ff800007ff80000ULL;
   vex_state->guest_f12 = 0x7ff800007ff80000ULL;
   vex_state->guest_f13 = 0x7ff800007ff80000ULL;
   vex_state->guest_f14 = 0x7ff800007ff80000ULL;
   vex_state->guest_f15 = 0x7ff800007ff80000ULL;
   vex_state->guest_f16 = 0x7ff800007ff80000ULL;
   vex_state->guest_f17 = 0x7ff800007ff80000ULL;
   vex_state->guest_f18 = 0x7ff800007ff80000ULL;
   vex_state->guest_f19 = 0x7ff800007ff80000ULL;
   vex_state->guest_f20 = 0x7ff800007ff80000ULL;
   vex_state->guest_f21 = 0x7ff800007ff80000ULL;
   vex_state->guest_f22 = 0x7ff800007ff80000ULL;
   vex_state->guest_f23 = 0x7ff800007ff80000ULL;
   vex_state->guest_f24 = 0x7ff800007ff80000ULL;
   vex_state->guest_f25 = 0x7ff800007ff80000ULL;
   vex_state->guest_f26 = 0x7ff800007ff80000ULL;
   vex_state->guest_f27 = 0x7ff800007ff80000ULL;
   vex_state->guest_f28 = 0x7ff800007ff80000ULL;
   vex_state->guest_f29 = 0x7ff800007ff80000ULL;
   vex_state->guest_f30 = 0x7ff800007ff80000ULL;
   vex_state->guest_f31 = 0x7ff800007ff80000ULL;

   vex_state->guest_FIR = 0;   /* FP implementation and revision register */
   vex_state->guest_FCCR = 0;  /* FP condition codes register */
   vex_state->guest_FEXR = 0;  /* FP exceptions register */
   vex_state->guest_FENR = 0;  /* FP enables register */
   vex_state->guest_FCSR = 0;  /* FP control/status register */

   vex_state->guest_ULR = 0;

   /* Various pseudo-regs mandated by Vex or Valgrind. */
   /* Emulation notes */
   vex_state->guest_EMNOTE = 0;

   /* For clflush: record start and length of area to invalidate */
   vex_state->guest_CMSTART = 0;
   vex_state->guest_CMLEN = 0;
   vex_state->host_EvC_COUNTER = 0;
   vex_state->host_EvC_FAILADDR = 0;

   /* Used to record the unredirected guest address at the start of
      a translation whose start has been redirected. By reading
      this pseudo-register shortly afterwards, the translation can
      find out what the corresponding no-redirection address was.
      Note, this is only set for wrap-style redirects, not for
      replace-style ones. */
   vex_state->guest_NRADDR = 0;

   vex_state->guest_COND = 0;

   vex_state->guest_CP0_status = MIPS_CP0_STATUS_FR;

   vex_state->guest_LLaddr = 0xFFFFFFFFFFFFFFFFULL;
   vex_state->guest_LLdata = 0;
}

/*-----------------------------------------------------------*/
/*--- Describing the mips guest state, for the benefit    ---*/
/*--- of iropt and instrumenters.                         ---*/
/*-----------------------------------------------------------*/

/* Figure out if any part of the guest state contained in minoff
   .. maxoff requires precise memory exceptions.  If in doubt return
   True (but this generates significantly slower code).

   We enforce precise exns for guest SP, PC.

   Only SP is needed in mode VexRegUpdSpAtMemAccess.
*/
Bool guest_mips32_state_requires_precise_mem_exns (
        Int minoff, Int maxoff, VexRegisterUpdates pxControl
     )
{
   Int sp_min = offsetof(VexGuestMIPS32State, guest_r29);
   Int sp_max = sp_min + 4 - 1;
   Int pc_min = offsetof(VexGuestMIPS32State, guest_PC);
   Int pc_max = pc_min + 4 - 1;

   if (maxoff < sp_min || minoff > sp_max) {
      /* no overlap with sp */
      if (pxControl == VexRegUpdSpAtMemAccess)
         return False;  /* We only need to check stack pointer. */
   } else {
      return True;
   }

   if (maxoff < pc_min || minoff > pc_max) {
      /* no overlap with pc */
   } else {
      return True;
   }

   /* We appear to need precise updates of R11 in order to get proper
      stacktraces from non-optimised code. */
   Int fp_min = offsetof(VexGuestMIPS32State, guest_r30);
   Int fp_max = fp_min + 4 - 1;

   if (maxoff < fp_min || minoff > fp_max) {
      /* no overlap with fp */
   } else {
      return True;
   }

   return False;
}

Bool guest_mips64_state_requires_precise_mem_exns (
        Int minoff, Int maxoff, VexRegisterUpdates pxControl
     )
{
   Int sp_min = offsetof(VexGuestMIPS64State, guest_r29);
   Int sp_max = sp_min + 8 - 1;
   Int pc_min = offsetof(VexGuestMIPS64State, guest_PC);
   Int pc_max = pc_min + 8 - 1;

   if ( maxoff < sp_min || minoff > sp_max ) {
      /* no overlap with sp */
      if (pxControl == VexRegUpdSpAtMemAccess)
         return False;  /* We only need to check stack pointer. */
   } else {
      return True;
   }

   if ( maxoff < pc_min || minoff > pc_max ) {
      /* no overlap with pc */
   } else {
      return True;
   }

   Int fp_min = offsetof(VexGuestMIPS64State, guest_r30);
   Int fp_max = fp_min + 8 - 1;

   if ( maxoff < fp_min || minoff > fp_max ) {
      /* no overlap with fp */
   } else {
      return True;
   }

   return False;
}

VexGuestLayout mips32Guest_layout = {
   /* Total size of the guest state, in bytes. */
   .total_sizeB = sizeof(VexGuestMIPS32State),
   /* Describe the stack pointer. */
   .offset_SP = offsetof(VexGuestMIPS32State, guest_r29),
   .sizeof_SP = 4,
   /* Describe the frame pointer. */
   .offset_FP = offsetof(VexGuestMIPS32State, guest_r30),
   .sizeof_FP = 4,
   /* Describe the instruction pointer. */
   .offset_IP = offsetof(VexGuestMIPS32State, guest_PC),
   .sizeof_IP = 4,
   /* Describe any sections to be regarded by Memcheck as
      'always-defined'. */
   .n_alwaysDefd = 8,
   /* ? :(  */
   .alwaysDefd = {
             /* 0 */ ALWAYSDEFD32(guest_r0),
             /* 1 */ ALWAYSDEFD32(guest_r1),
             /* 2 */ ALWAYSDEFD32(guest_EMNOTE),
             /* 3 */ ALWAYSDEFD32(guest_CMSTART),
             /* 4 */ ALWAYSDEFD32(guest_CMLEN),
             /* 5 */ ALWAYSDEFD32(guest_r29),
             /* 6 */ ALWAYSDEFD32(guest_r31),
             /* 7 */ ALWAYSDEFD32(guest_ULR)
             }
};

VexGuestLayout mips64Guest_layout = {
   /* Total size of the guest state, in bytes. */
   .total_sizeB = sizeof(VexGuestMIPS64State),
   /* Describe the stack pointer. */
   .offset_SP = offsetof(VexGuestMIPS64State, guest_r29),
   .sizeof_SP = 8,
   /* Describe the frame pointer. */
   .offset_FP = offsetof(VexGuestMIPS64State, guest_r30),
   .sizeof_FP = 8,
   /* Describe the instruction pointer. */
   .offset_IP = offsetof(VexGuestMIPS64State, guest_PC),
   .sizeof_IP = 8,
   /* Describe any sections to be regarded by Memcheck as
      'always-defined'. */
   .n_alwaysDefd = 7,
   /* ? :(  */
   .alwaysDefd = {
                  /* 0 */ ALWAYSDEFD64 (guest_r0),
                  /* 1 */ ALWAYSDEFD64 (guest_EMNOTE),
                  /* 2 */ ALWAYSDEFD64 (guest_CMSTART),
                  /* 3 */ ALWAYSDEFD64 (guest_CMLEN),
                  /* 4 */ ALWAYSDEFD64 (guest_r29),
                  /* 5 */ ALWAYSDEFD64 (guest_r31),
                  /* 6 */ ALWAYSDEFD64 (guest_ULR)
                  }
};

#define ASM_VOLATILE_RDHWR(opcode)                                 \
   __asm__ __volatile__(".word 0x7C02003B | "#opcode" << 11  \n\t" \
                        : "+r" (x) : :                             \
                       )

HWord mips_dirtyhelper_rdhwr ( UInt rd )
{
#if defined(__mips__)
   register HWord x __asm__("v0") = 0;

   switch (rd) {
      case 0:  /* x = CPUNum() */
         ASM_VOLATILE_RDHWR(0); /* rdhwr v0, $0 */
         break;

      case 1:  /* x = SYNCI_Step() */
         ASM_VOLATILE_RDHWR(1); /* rdhwr v0, $1 */
         break;

      case 2:  /* x = CC() */
         ASM_VOLATILE_RDHWR(2); /* rdhwr v0, $2 */
         break;

      case 3:  /* x = CCRes() */
         ASM_VOLATILE_RDHWR(3); /* rdhwr v0, $3 */
         break;

      case 31:  /* x = CVMX_get_cycles() */
         ASM_VOLATILE_RDHWR(31); /* rdhwr v0, $31 */
         break;

      default:
         vassert(0);
         break;
   }
   return x;
#else
   return 0;
#endif
}

#define ASM_VOLATILE_UNARY32(inst)                                  \
   __asm__ volatile(".set  push"        "\n\t"                      \
                    ".set  hardfloat"   "\n\t"                      \
                    "cfc1  $t0,  $31"   "\n\t"                      \
                    "ctc1  %2,   $31"   "\n\t"                      \
                    "mtc1  %1,   $f20"  "\n\t"                      \
                    #inst" $f20, $f20"  "\n\t"                      \
                    "cfc1  %0,   $31"   "\n\t"                      \
                    "ctc1  $t0,  $31"   "\n\t"                      \
                    ".set  pop"         "\n\t"                      \
                    : "=r" (ret)                                    \
                    : "r" (loFsVal), "r" (fcsr)                     \
                    : "t0", "$f20"                                  \
                   );

#define ASM_VOLATILE_UNARY32_DOUBLE(inst)                           \
   __asm__ volatile(".set  push"        "\n\t"                      \
                    ".set  hardfloat"   "\n\t"                      \
                    "cfc1  $t0,  $31"   "\n\t"                      \
                    "ctc1  %2,   $31"   "\n\t"                      \
                    "ldc1  $f20, 0(%1)" "\n\t"                      \
                    #inst" $f20, $f20"  "\n\t"                      \
                    "cfc1  %0,   $31"   "\n\t"                      \
                    "ctc1  $t0,  $31"   "\n\t"                      \
                    ".set  pop"         "\n\t"                      \
                    : "=r" (ret)                                    \
                    : "r" (&fsVal), "r" (fcsr)                      \
                    : "t0", "$f20", "$f21"                          \
                   );

#define ASM_VOLATILE_UNARY64(inst)                                  \
   __asm__ volatile(".set  push"         "\n\t"                     \
                    ".set  hardfloat"    "\n\t"                     \
                    ".set  fp=64"        "\n\t"                     \
                    "cfc1  $t0,  $31"    "\n\t"                     \
                    "ctc1  %2,   $31"    "\n\t"                     \
                    "ldc1  $f24, 0(%1)"  "\n\t"                     \
                    #inst" $f24, $f24"   "\n\t"                     \
                    "cfc1  %0,   $31"    "\n\t"                     \
                    "ctc1  $t0,  $31"    "\n\t"                     \
                    ".set  pop"          "\n\t"                     \
                    : "=r" (ret)                                    \
                    : "r" (&(addr[fs])), "r" (fcsr)                 \
                    : "t0", "$f24"                                  \
                   );

#define ASM_VOLATILE_BINARY32(inst)                                 \
   __asm__ volatile(".set  push"              "\n\t"                \
                    ".set  hardfloat"         "\n\t"                \
                    "cfc1  $t0,  $31"         "\n\t"                \
                    "ctc1  %3,   $31"         "\n\t"                \
                    "mtc1  %1,   $f20"        "\n\t"                \
                    "mtc1  %2,   $f22"        "\n\t"                \
                    #inst" $f20, $f20, $f22"  "\n\t"                \
                    "cfc1  %0,   $31"         "\n\t"                \
                    "ctc1  $t0,  $31"         "\n\t"                \
                    ".set  pop"               "\n\t"                \
                    : "=r" (ret)                                    \
                    : "r" (loFsVal), "r" (loFtVal), "r" (fcsr)      \
                    : "t0", "$f20", "$f22"                          \
                   );

#define ASM_VOLATILE_BINARY32_DOUBLE(inst)                          \
   __asm__ volatile(".set  push"              "\n\t"                \
                    ".set  hardfloat"         "\n\t"                \
                    "cfc1  $t0,  $31"         "\n\t"                \
                    "ctc1  %3,   $31"         "\n\t"                \
                    "ldc1  $f20, 0(%1)"       "\n\t"                \
                    "ldc1  $f22, 0(%2)"       "\n\t"                \
                    #inst" $f20, $f20, $f22"  "\n\t"                \
                    "cfc1  %0,   $31"         "\n\t"                \
                    "ctc1  $t0,  $31"         "\n\t"                \
                    ".set  pop"               "\n\t"                \
                    : "=r" (ret)                                    \
                    : "r" (&fsVal), "r" (&ftVal), "r" (fcsr)        \
                    : "t0", "$f20", "$f21", "$f22", "$f23"          \
                   );

#define ASM_VOLATILE_BINARY64(inst)                                     \
   __asm__ volatile(".set  push"              "\n\t"                    \
                    ".set  hardfloat"         "\n\t"                    \
                    "cfc1  $t0,  $31"         "\n\t"                    \
                    "ctc1  %3,   $31"         "\n\t"                    \
                    "ldc1  $f24, 0(%1)"       "\n\t"                    \
                    "ldc1  $f26, 0(%2)"       "\n\t"                    \
                    #inst" $f24, $f24, $f26"  "\n\t"                    \
                    "cfc1  %0,   $31"         "\n\t"                    \
                    "ctc1  $t0,  $31"         "\n\t"                    \
                    ".set  pop"               "\n\t"                    \
                    : "=r" (ret)                                        \
                    : "r" (&(addr[fs])), "r" (&(addr[ft])), "r" (fcsr)  \
                    : "t0", "$f24", "$f26"                              \
                   );

/* TODO: Add cases for all fpu instructions because all fpu instructions are
         change the value of FCSR register. */
extern UInt mips_dirtyhelper_calculate_FCSR_fp32 ( void* gs, UInt fs, UInt ft,
                                                   flt_op inst )
{
   UInt ret = 0;
#if defined(__mips__)
   VexGuestMIPS32State* guest_state = (VexGuestMIPS32State*)gs;
   UInt loFsVal, hiFsVal, loFtVal, hiFtVal;
#if defined (_MIPSEL)
   ULong *addr = (ULong *)&guest_state->guest_f0;
   loFsVal     = (UInt)addr[fs];
   hiFsVal     = (UInt)addr[fs+1];
   loFtVal     = (UInt)addr[ft];
   hiFtVal     = (UInt)addr[ft+1];
#elif defined (_MIPSEB)
   UInt *addr = (UInt *)&guest_state->guest_f0;
   loFsVal    = (UInt)addr[fs*2];
   hiFsVal    = (UInt)addr[fs*2+2];
   loFtVal    = (UInt)addr[ft*2];
   hiFtVal    = (UInt)addr[ft*2+2];
#endif
   ULong fsVal   = ((ULong) hiFsVal) << 32 | loFsVal;
   ULong ftVal   = ((ULong) hiFtVal) << 32 | loFtVal;
   UInt fcsr     = guest_state->guest_FCSR;
   switch (inst) {
      case ROUNDWD:
         ASM_VOLATILE_UNARY32_DOUBLE(round.w.d)
         break;
      case FLOORWS:
         ASM_VOLATILE_UNARY32(floor.w.s)
         break;
      case FLOORWD:
         ASM_VOLATILE_UNARY32_DOUBLE(floor.w.d)
         break;
      case TRUNCWS:
         ASM_VOLATILE_UNARY32(trunc.w.s)
         break;
      case TRUNCWD:
         ASM_VOLATILE_UNARY32_DOUBLE(trunc.w.d)
         break;
      case CEILWS:
         ASM_VOLATILE_UNARY32(ceil.w.s)
         break;
      case CEILWD:
         ASM_VOLATILE_UNARY32_DOUBLE(ceil.w.d)
         break;
      case CVTDS:
         ASM_VOLATILE_UNARY32(cvt.d.s)
         break;
      case CVTDW:
         ASM_VOLATILE_UNARY32(cvt.d.w)
         break;
      case CVTSW:
         ASM_VOLATILE_UNARY32(cvt.s.w)
         break;
      case CVTSD:
         ASM_VOLATILE_UNARY32_DOUBLE(cvt.s.d)
         break;
      case CVTWS:
         ASM_VOLATILE_UNARY32(cvt.w.s)
         break;
      case CVTWD:
         ASM_VOLATILE_UNARY32_DOUBLE(cvt.w.d)
         break;
      case ROUNDWS:
         ASM_VOLATILE_UNARY32(round.w.s)
         break;
      case ADDS:
          ASM_VOLATILE_BINARY32(add.s)
          break;
      case ADDD:
          ASM_VOLATILE_BINARY32_DOUBLE(add.d)
          break;
      case SUBS:
          ASM_VOLATILE_BINARY32(sub.s)
          break;
      case SUBD:
          ASM_VOLATILE_BINARY32_DOUBLE(sub.d)
          break;
      case DIVS:
          ASM_VOLATILE_BINARY32(div.s)
          break;
      default:
         vassert(0);
         break;
   }
#endif
   return ret;
}

/* TODO: Add cases for all fpu instructions because all fpu instructions are
         change the value of FCSR register. */
extern UInt mips_dirtyhelper_calculate_FCSR_fp64 ( void* gs, UInt fs, UInt ft,
                                                   flt_op inst )
{
   UInt ret = 0;
#if defined(__mips__) && ((__mips == 64) ||                                  \
                          (defined(__mips_isa_rev) && (__mips_isa_rev >= 2)))
#if defined(VGA_mips32)
   VexGuestMIPS32State* guest_state = (VexGuestMIPS32State*)gs;
#else
   VexGuestMIPS64State* guest_state = (VexGuestMIPS64State*)gs;
#endif
   ULong *addr = (ULong *)&guest_state->guest_f0;
   UInt fcsr   = guest_state->guest_FCSR;
   switch (inst) {
      case ROUNDWD:
         ASM_VOLATILE_UNARY64(round.w.d)
         break;
      case FLOORWS:
         ASM_VOLATILE_UNARY64(floor.w.s)
         break;
      case FLOORWD:
         ASM_VOLATILE_UNARY64(floor.w.d)
         break;
      case TRUNCWS:
         ASM_VOLATILE_UNARY64(trunc.w.s)
         break;
      case TRUNCWD:
         ASM_VOLATILE_UNARY64(trunc.w.d)
         break;
      case CEILWS:
         ASM_VOLATILE_UNARY64(ceil.w.s)
         break;
      case CEILWD:
         ASM_VOLATILE_UNARY64(ceil.w.d)
         break;
      case CVTDS:
         ASM_VOLATILE_UNARY64(cvt.d.s)
         break;
      case CVTDW:
         ASM_VOLATILE_UNARY64(cvt.d.w)
         break;
      case CVTSW:
         ASM_VOLATILE_UNARY64(cvt.s.w)
         break;
      case CVTSD:
         ASM_VOLATILE_UNARY64(cvt.s.d)
         break;
      case CVTWS:
         ASM_VOLATILE_UNARY64(cvt.w.s)
         break;
      case CVTWD:
         ASM_VOLATILE_UNARY64(cvt.w.d)
         break;
      case ROUNDWS:
         ASM_VOLATILE_UNARY64(round.w.s)
         break;
      case CEILLS:
         ASM_VOLATILE_UNARY64(ceil.l.s)
         break;
      case CEILLD:
         ASM_VOLATILE_UNARY64(ceil.l.d)
         break;
      case CVTDL:
         ASM_VOLATILE_UNARY64(cvt.d.l)
         break;
      case CVTLS:
         ASM_VOLATILE_UNARY64(cvt.l.s)
         break;
      case CVTLD:
         ASM_VOLATILE_UNARY64(cvt.l.d)
         break;
      case CVTSL:
         ASM_VOLATILE_UNARY64(cvt.s.l)
         break;
      case FLOORLS:
         ASM_VOLATILE_UNARY64(floor.l.s)
         break;
      case FLOORLD:
         ASM_VOLATILE_UNARY64(floor.l.d)
         break;
      case ROUNDLS:
         ASM_VOLATILE_UNARY64(round.l.s)
         break;
      case ROUNDLD:
         ASM_VOLATILE_UNARY64(round.l.d)
         break;
      case TRUNCLS:
         ASM_VOLATILE_UNARY64(trunc.l.s)
         break;
      case TRUNCLD:
         ASM_VOLATILE_UNARY64(trunc.l.d)
         break;
      case ADDS:
          ASM_VOLATILE_BINARY64(add.s)
          break;
      case ADDD:
          ASM_VOLATILE_BINARY64(add.d)
          break;
      case SUBS:
          ASM_VOLATILE_BINARY64(sub.s)
          break;
      case SUBD:
          ASM_VOLATILE_BINARY64(sub.d)
          break;
      case DIVS:
          ASM_VOLATILE_BINARY64(div.s)
          break;
      default:
         vassert(0);
         break;
   }
#endif
   return ret;
}

/*---------------------------------------------------------------*/
/*--- end                                guest_mips_helpers.c ---*/
/*---------------------------------------------------------------*/

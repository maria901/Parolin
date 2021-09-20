/* Copyright 2014 Google Inc. All Rights Reserved, modified in 2021 by MathMan (SmartApe) from BinaryWork

   Distributed under MIT license.
   See file LICENSE for detail or copy at https://opensource.org/licenses/MIT
 */

/* Command line interface for Brotli library. */
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <wctype.h>
#include <wchar.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <locale.h>
#include <signal.h>
#include <limits.h>
#include <float.h>
#include <iso646.h>

#undef NDEBUG
#include <assert.h>

#include <stdbool.h>

void pedro_dprintf(
    int amanda_level,
    char *format, ...);

//#define ARP_DEBUG__ 0x1001

#include "stdio_v2.h"
#include "stdio_v3.h"

int compress(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);
int compress_thread_1(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);
int compress_thread_2(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);
int compress_thread_3(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);
int compress_thread_4(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);
int compress_thread_5(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);
int compress_thread_6(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);
int compress_thread_7(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_8(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_9(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_10(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_11(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_12(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_13(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_14(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_15(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_16(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_17(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_18(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_19(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_20(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_21(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_22(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_23(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_24(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_25(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_26(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_27(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_28(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_29(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_30(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_31(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_32(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_33(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_34(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_35(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_36(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_37(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_38(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_39(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_40(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_41(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_42(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_43(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_44(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_45(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_46(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_47(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_48(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_49(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_50(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_51(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_52(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_53(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_54(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_55(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_56(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_57(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_58(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_59(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_60(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_61(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_62(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_63(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_64(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_65(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_66(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_67(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_68(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_69(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_70(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_71(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_72(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_73(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_74(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_75(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_76(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_77(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_78(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_79(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_80(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_81(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_82(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_83(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_84(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_85(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_86(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_87(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_88(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_89(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_90(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_91(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_92(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_93(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_94(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_95(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_96(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_97(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_98(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_99(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_100(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_101(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_102(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_103(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_104(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_105(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_106(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_107(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_108(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_109(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_110(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_111(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_112(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_113(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_114(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_115(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_116(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_117(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_118(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_119(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_120(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_121(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_122(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_123(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_124(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_125(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_126(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_127(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int compress_thread_128(
    FILE *fdin,
    FILE_z *fdout,
    my_thread_struct_z *amanda);

int decompress(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_1(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_2(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_3(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_4(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_5(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_6(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_7(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);
int decompress_thread_8(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_9(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_10(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_11(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_12(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_13(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_14(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_15(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_16(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_17(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_18(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_19(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_20(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_21(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_22(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_23(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_24(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_25(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_26(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_27(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_28(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_29(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_30(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_31(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_32(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_33(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_34(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_35(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_36(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_37(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_38(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_39(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_40(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_41(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_42(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_43(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_44(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_45(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_46(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_47(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_48(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_49(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_50(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_51(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_52(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_53(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_54(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_55(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_56(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_57(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_58(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_59(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_60(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_61(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_62(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_63(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_64(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_65(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_66(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_67(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_68(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_69(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_70(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_71(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_72(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_73(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_74(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_75(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_76(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_77(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_78(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_79(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_80(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_81(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_82(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_83(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_84(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_85(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_86(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_87(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_88(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_89(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_90(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_91(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_92(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_93(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_94(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_95(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_96(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_97(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_98(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_99(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_100(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_101(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_102(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_103(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_104(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_105(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_106(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_107(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_108(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_109(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_110(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_111(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_112(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_113(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_114(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_115(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_116(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_117(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_118(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_119(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_120(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_121(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_122(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_123(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_124(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_125(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_126(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_127(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

int decompress_thread_128(
    FILE *fdin,
    FILE *fdout,
    my_thread_struct_z *amanda);

extern int lgetpor(__int64 max_Amanda, __int64 fatia_Ricardo);
extern WCHAR *__stdcall utf8towide(const char *pUTF8);
extern __int64 getfilesize_aakp_plus_rspk(char *infile_utf8_valquiria);

extern __int64 tamanho____aakp;
extern __int64 processado_rspk;

extern int intpause___aakp;
extern int intcancel__rspk;
extern int return_value_arp;

compressResult_t
compress_file(__attribute__((unused)) FILE *f_in,
              __attribute__((unused)) FILE_z *f_out,
              my_thread_struct_z *amanda)
{
     int returnvalue_z = 0;

     compressResult_t result_z = {1, 0, 0};

     switch (amanda->thread_id_z)
     {
     case 0:
     pedro_dprintf(0, "!!!thread 0");
          returnvalue_z = compress(amanda->input_file, amanda->dest, amanda);
          break;
     case 1:
     pedro_dprintf(0, "???thread 1");
          returnvalue_z = compress_thread_1(amanda->input_file, amanda->dest, amanda);
          break;
     case 2:
     pedro_dprintf(0, "---thread 2");
          returnvalue_z = compress_thread_2(amanda->input_file, amanda->dest, amanda);
          break;
     case 3:
          returnvalue_z = compress_thread_3(amanda->input_file, amanda->dest, amanda);
          break;
     case 4:
          returnvalue_z = compress_thread_4(amanda->input_file, amanda->dest, amanda);
          break;
     case 5:
          returnvalue_z = compress_thread_5(amanda->input_file, amanda->dest, amanda);
          break;
     case 6:
          returnvalue_z = compress_thread_6(amanda->input_file, amanda->dest, amanda);
          break;
     case 7:
          returnvalue_z = compress_thread_7(amanda->input_file, amanda->dest, amanda);
          break;
     case 8:
          pedro_dprintf(0, "calling 8 %p\n", amanda);
          returnvalue_z = compress_thread_8(amanda->input_file, amanda->dest, amanda);
          break;
     case 9:
          pedro_dprintf(0, "calling 9 %p\n", amanda);
          returnvalue_z = compress_thread_9(amanda->input_file, amanda->dest, amanda);
          break;
     case 10:
          returnvalue_z = compress_thread_10(amanda->input_file, amanda->dest, amanda);
          break;
     case 11:
          returnvalue_z = compress_thread_11(amanda->input_file, amanda->dest, amanda);
          break;
     case 12:
          returnvalue_z = compress_thread_12(amanda->input_file, amanda->dest, amanda);
          break;
     case 13:
          returnvalue_z = compress_thread_13(amanda->input_file, amanda->dest, amanda);
          break;
     case 14:
          returnvalue_z = compress_thread_14(amanda->input_file, amanda->dest, amanda);
          break;
     case 15:
          returnvalue_z = compress_thread_15(amanda->input_file, amanda->dest, amanda);
          break;
     case 16:
          returnvalue_z = compress_thread_16(amanda->input_file, amanda->dest, amanda);
          break;
     case 17:
          returnvalue_z = compress_thread_17(amanda->input_file, amanda->dest, amanda);
          break;
     case 18:
          returnvalue_z = compress_thread_18(amanda->input_file, amanda->dest, amanda);
          break;
     case 19:
          returnvalue_z = compress_thread_19(amanda->input_file, amanda->dest, amanda);
          break;
     case 20:
          returnvalue_z = compress_thread_20(amanda->input_file, amanda->dest, amanda);
          break;
     case 21:
          returnvalue_z = compress_thread_21(amanda->input_file, amanda->dest, amanda);
          break;
     case 22:
          returnvalue_z = compress_thread_22(amanda->input_file, amanda->dest, amanda);
          break;
     case 23:
          returnvalue_z = compress_thread_23(amanda->input_file, amanda->dest, amanda);
          break;
     case 24:
          returnvalue_z = compress_thread_24(amanda->input_file, amanda->dest, amanda);
          break;
     case 25:
          returnvalue_z = compress_thread_25(amanda->input_file, amanda->dest, amanda);
          break;
     case 26:
          returnvalue_z = compress_thread_26(amanda->input_file, amanda->dest, amanda);
          break;
     case 27:
          returnvalue_z = compress_thread_27(amanda->input_file, amanda->dest, amanda);
          break;
     case 28:
          returnvalue_z = compress_thread_28(amanda->input_file, amanda->dest, amanda);
          break;
     case 29:
          returnvalue_z = compress_thread_29(amanda->input_file, amanda->dest, amanda);
          break;
     case 30:
          returnvalue_z = compress_thread_30(amanda->input_file, amanda->dest, amanda);
          break;
     case 31:
          returnvalue_z = compress_thread_31(amanda->input_file, amanda->dest, amanda);
          break;
     case 32:
          returnvalue_z = compress_thread_32(amanda->input_file, amanda->dest, amanda);
          break;
     case 33:
          returnvalue_z = compress_thread_33(amanda->input_file, amanda->dest, amanda);
          break;
     case 34:
          returnvalue_z = compress_thread_34(amanda->input_file, amanda->dest, amanda);
          break;
     case 35:
          returnvalue_z = compress_thread_35(amanda->input_file, amanda->dest, amanda);
          break;
     case 36:
          returnvalue_z = compress_thread_36(amanda->input_file, amanda->dest, amanda);
          break;
     case 37:
          returnvalue_z = compress_thread_37(amanda->input_file, amanda->dest, amanda);
          break;
     case 38:
          returnvalue_z = compress_thread_38(amanda->input_file, amanda->dest, amanda);
          break;
     case 39:
          returnvalue_z = compress_thread_39(amanda->input_file, amanda->dest, amanda);
          break;
     case 40:
          returnvalue_z = compress_thread_40(amanda->input_file, amanda->dest, amanda);
          break;
     case 41:
          returnvalue_z = compress_thread_41(amanda->input_file, amanda->dest, amanda);
          break;
     case 42:
          returnvalue_z = compress_thread_42(amanda->input_file, amanda->dest, amanda);
          break;
     case 43:
          returnvalue_z = compress_thread_43(amanda->input_file, amanda->dest, amanda);
          break;
     case 44:
          returnvalue_z = compress_thread_44(amanda->input_file, amanda->dest, amanda);
          break;
     case 45:
          returnvalue_z = compress_thread_45(amanda->input_file, amanda->dest, amanda);
          break;
     case 46:
          returnvalue_z = compress_thread_46(amanda->input_file, amanda->dest, amanda);
          break;
     case 47:
          returnvalue_z = compress_thread_47(amanda->input_file, amanda->dest, amanda);
          break;
     case 48:
          returnvalue_z = compress_thread_48(amanda->input_file, amanda->dest, amanda);
          break;
     case 49:
          returnvalue_z = compress_thread_49(amanda->input_file, amanda->dest, amanda);
          break;
     case 50:
          returnvalue_z = compress_thread_50(amanda->input_file, amanda->dest, amanda);
          break;
     case 51:
          returnvalue_z = compress_thread_51(amanda->input_file, amanda->dest, amanda);
          break;
     case 52:
          returnvalue_z = compress_thread_52(amanda->input_file, amanda->dest, amanda);
          break;
     case 53:
          returnvalue_z = compress_thread_53(amanda->input_file, amanda->dest, amanda);
          break;
     case 54:
          returnvalue_z = compress_thread_54(amanda->input_file, amanda->dest, amanda);
          break;
     case 55:
          returnvalue_z = compress_thread_55(amanda->input_file, amanda->dest, amanda);
          break;
     case 56:
          returnvalue_z = compress_thread_56(amanda->input_file, amanda->dest, amanda);
          break;
     case 57:
          returnvalue_z = compress_thread_57(amanda->input_file, amanda->dest, amanda);
          break;
     case 58:
          returnvalue_z = compress_thread_58(amanda->input_file, amanda->dest, amanda);
          break;
     case 59:
          returnvalue_z = compress_thread_59(amanda->input_file, amanda->dest, amanda);
          break;
     case 60:
          returnvalue_z = compress_thread_60(amanda->input_file, amanda->dest, amanda);
          break;
     case 61:
          returnvalue_z = compress_thread_61(amanda->input_file, amanda->dest, amanda);
          break;
     case 62:
          returnvalue_z = compress_thread_62(amanda->input_file, amanda->dest, amanda);
          break;
     case 63:
          returnvalue_z = compress_thread_63(amanda->input_file, amanda->dest, amanda);
          break;
     case 64:
          returnvalue_z = compress_thread_64(amanda->input_file, amanda->dest, amanda);
          break;
     case 65:
          returnvalue_z = compress_thread_65(amanda->input_file, amanda->dest, amanda);
          break;
     case 66:
          returnvalue_z = compress_thread_66(amanda->input_file, amanda->dest, amanda);
          break;
     case 67:
          returnvalue_z = compress_thread_67(amanda->input_file, amanda->dest, amanda);
          break;
     case 68:
          returnvalue_z = compress_thread_68(amanda->input_file, amanda->dest, amanda);
          break;
     case 69:
          returnvalue_z = compress_thread_69(amanda->input_file, amanda->dest, amanda);
          break;
     case 70:
          returnvalue_z = compress_thread_70(amanda->input_file, amanda->dest, amanda);
          break;
     case 71:
          returnvalue_z = compress_thread_71(amanda->input_file, amanda->dest, amanda);
          break;
     case 72:
          returnvalue_z = compress_thread_72(amanda->input_file, amanda->dest, amanda);
          break;
     case 73:
          returnvalue_z = compress_thread_73(amanda->input_file, amanda->dest, amanda);
          break;
     case 74:
          returnvalue_z = compress_thread_74(amanda->input_file, amanda->dest, amanda);
          break;
     case 75:
          returnvalue_z = compress_thread_75(amanda->input_file, amanda->dest, amanda);
          break;
     case 76:
          returnvalue_z = compress_thread_76(amanda->input_file, amanda->dest, amanda);
          break;
     case 77:
          returnvalue_z = compress_thread_77(amanda->input_file, amanda->dest, amanda);
          break;
     case 78:
          returnvalue_z = compress_thread_78(amanda->input_file, amanda->dest, amanda);
          break;
     case 79:
          returnvalue_z = compress_thread_79(amanda->input_file, amanda->dest, amanda);
          break;
     case 80:
          returnvalue_z = compress_thread_80(amanda->input_file, amanda->dest, amanda);
          break;
     case 81:
          returnvalue_z = compress_thread_81(amanda->input_file, amanda->dest, amanda);
          break;
     case 82:
          returnvalue_z = compress_thread_82(amanda->input_file, amanda->dest, amanda);
          break;
     case 83:
          returnvalue_z = compress_thread_83(amanda->input_file, amanda->dest, amanda);
          break;
     case 84:
          returnvalue_z = compress_thread_84(amanda->input_file, amanda->dest, amanda);
          break;
     case 85:
          returnvalue_z = compress_thread_85(amanda->input_file, amanda->dest, amanda);
          break;
     case 86:
          returnvalue_z = compress_thread_86(amanda->input_file, amanda->dest, amanda);
          break;
     case 87:
          returnvalue_z = compress_thread_87(amanda->input_file, amanda->dest, amanda);
          break;
     case 88:
          returnvalue_z = compress_thread_88(amanda->input_file, amanda->dest, amanda);
          break;
     case 89:
          returnvalue_z = compress_thread_89(amanda->input_file, amanda->dest, amanda);
          break;
     case 90:
          returnvalue_z = compress_thread_90(amanda->input_file, amanda->dest, amanda);
          break;
     case 91:
          returnvalue_z = compress_thread_91(amanda->input_file, amanda->dest, amanda);
          break;
     case 92:
          returnvalue_z = compress_thread_92(amanda->input_file, amanda->dest, amanda);
          break;
     case 93:
          returnvalue_z = compress_thread_93(amanda->input_file, amanda->dest, amanda);
          break;
     case 94:
          returnvalue_z = compress_thread_94(amanda->input_file, amanda->dest, amanda);
          break;
     case 95:
          returnvalue_z = compress_thread_95(amanda->input_file, amanda->dest, amanda);
          break;
     case 96:
          returnvalue_z = compress_thread_96(amanda->input_file, amanda->dest, amanda);
          break;
     case 97:
          returnvalue_z = compress_thread_97(amanda->input_file, amanda->dest, amanda);
          break;
     case 98:
          returnvalue_z = compress_thread_98(amanda->input_file, amanda->dest, amanda);
          break;
     case 99:
          returnvalue_z = compress_thread_99(amanda->input_file, amanda->dest, amanda);
          break;
     case 100:
          returnvalue_z = compress_thread_100(amanda->input_file, amanda->dest, amanda);
          break;
     case 101:
          returnvalue_z = compress_thread_101(amanda->input_file, amanda->dest, amanda);
          break;
     case 102:
          returnvalue_z = compress_thread_102(amanda->input_file, amanda->dest, amanda);
          break;
     case 103:
          returnvalue_z = compress_thread_103(amanda->input_file, amanda->dest, amanda);
          break;
     case 104:
          returnvalue_z = compress_thread_104(amanda->input_file, amanda->dest, amanda);
          break;
     case 105:
          returnvalue_z = compress_thread_105(amanda->input_file, amanda->dest, amanda);
          break;
     case 106:
          returnvalue_z = compress_thread_106(amanda->input_file, amanda->dest, amanda);
          break;
     case 107:
          returnvalue_z = compress_thread_107(amanda->input_file, amanda->dest, amanda);
          break;
     case 108:
          returnvalue_z = compress_thread_108(amanda->input_file, amanda->dest, amanda);
          break;
     case 109:
          returnvalue_z = compress_thread_109(amanda->input_file, amanda->dest, amanda);
          break;
     case 110:
          returnvalue_z = compress_thread_110(amanda->input_file, amanda->dest, amanda);
          break;
     case 111:
          returnvalue_z = compress_thread_111(amanda->input_file, amanda->dest, amanda);
          break;
     case 112:
          returnvalue_z = compress_thread_112(amanda->input_file, amanda->dest, amanda);
          break;
     case 113:
          returnvalue_z = compress_thread_113(amanda->input_file, amanda->dest, amanda);
          break;
     case 114:
          returnvalue_z = compress_thread_114(amanda->input_file, amanda->dest, amanda);
          break;
     case 115:
          returnvalue_z = compress_thread_115(amanda->input_file, amanda->dest, amanda);
          break;
     case 116:
          returnvalue_z = compress_thread_116(amanda->input_file, amanda->dest, amanda);
          break;
     case 117:
          returnvalue_z = compress_thread_117(amanda->input_file, amanda->dest, amanda);
          break;
     case 118:
          returnvalue_z = compress_thread_118(amanda->input_file, amanda->dest, amanda);
          break;
     case 119:
          returnvalue_z = compress_thread_119(amanda->input_file, amanda->dest, amanda);
          break;
     case 120:
          returnvalue_z = compress_thread_120(amanda->input_file, amanda->dest, amanda);
          break;
     case 121:
          returnvalue_z = compress_thread_121(amanda->input_file, amanda->dest, amanda);
          break;
     case 122:
          returnvalue_z = compress_thread_122(amanda->input_file, amanda->dest, amanda);
          break;
     case 123:
          returnvalue_z = compress_thread_123(amanda->input_file, amanda->dest, amanda);
          break;
     case 124:
          returnvalue_z = compress_thread_124(amanda->input_file, amanda->dest, amanda);
          break;
     case 125:
          returnvalue_z = compress_thread_125(amanda->input_file, amanda->dest, amanda);
          break;
     case 126:
          returnvalue_z = compress_thread_126(amanda->input_file, amanda->dest, amanda);
          break;
     case 127:
          returnvalue_z = compress_thread_127(amanda->input_file, amanda->dest, amanda);
          break;
     case 128:
          returnvalue_z = compress_thread_128(amanda->input_file, amanda->dest, amanda);
          break;

     default:
          pedro_dprintf(2, "Invalid value for compress2 thread\n");
          exit(27);

          break;
     }
     if (0 == returnvalue_z)
     {
          result_z.error = 0;
     }

     return result_z;
}

/* @result : 1==error, 0==success */
int decompress_file(FILE *f_in, FILE *f_out, my_thread_struct_z *amanda)
{
     int retvalue_z = 0;

     switch (amanda->thread_id_z)
     {
     case 0:
     pedro_dprintf(0, "...thread 0");
          retvalue_z = decompress(f_in, f_out, amanda);
          break;
     case 1:
     pedro_dprintf(0, "...thread 1");
          retvalue_z = decompress_thread_1(f_in, f_out, amanda);
          break;
     case 2:
     pedro_dprintf(0, "...thread 2");
          retvalue_z = decompress_thread_2(f_in, f_out, amanda);
          break;
     case 3:
          retvalue_z = decompress_thread_3(f_in, f_out, amanda);
          break;
     case 4:
          retvalue_z = decompress_thread_4(f_in, f_out, amanda);
          break;
     case 5:
          retvalue_z = decompress_thread_5(f_in, f_out, amanda);
          break;
     case 6:
          retvalue_z = decompress_thread_6(f_in, f_out, amanda);
          break;
     case 7:
          retvalue_z = decompress_thread_7(f_in, f_out, amanda);
          break;
     case 8:
          retvalue_z = decompress_thread_8(f_in, f_out, amanda);
          break;
     case 9:
          retvalue_z = decompress_thread_9(f_in, f_out, amanda);
          break;
     case 10:
          retvalue_z = decompress_thread_10(f_in, f_out, amanda);
          break;
     case 11:
          retvalue_z = decompress_thread_11(f_in, f_out, amanda);
          break;
     case 12:
          retvalue_z = decompress_thread_12(f_in, f_out, amanda);
          break;
     case 13:
          retvalue_z = decompress_thread_13(f_in, f_out, amanda);
          break;
     case 14:
          retvalue_z = decompress_thread_14(f_in, f_out, amanda);
          break;
     case 15:
          retvalue_z = decompress_thread_15(f_in, f_out, amanda);
          break;
     case 16:
          retvalue_z = decompress_thread_16(f_in, f_out, amanda);
          break;
     case 17:
          retvalue_z = decompress_thread_17(f_in, f_out, amanda);
          break;
     case 18:
          retvalue_z = decompress_thread_18(f_in, f_out, amanda);
          break;
     case 19:
          retvalue_z = decompress_thread_19(f_in, f_out, amanda);
          break;
     case 20:
          retvalue_z = decompress_thread_20(f_in, f_out, amanda);
          break;
     case 21:
          retvalue_z = decompress_thread_21(f_in, f_out, amanda);
          break;
     case 22:
          retvalue_z = decompress_thread_22(f_in, f_out, amanda);
          break;
     case 23:
          retvalue_z = decompress_thread_23(f_in, f_out, amanda);
          break;
     case 24:
          retvalue_z = decompress_thread_24(f_in, f_out, amanda);
          break;
     case 25:
          retvalue_z = decompress_thread_25(f_in, f_out, amanda);
          break;
     case 26:
          retvalue_z = decompress_thread_26(f_in, f_out, amanda);
          break;
     case 27:
          retvalue_z = decompress_thread_27(f_in, f_out, amanda);
          break;
     case 28:
          retvalue_z = decompress_thread_28(f_in, f_out, amanda);
          break;
     case 29:
          retvalue_z = decompress_thread_29(f_in, f_out, amanda);
          break;
     case 30:
          retvalue_z = decompress_thread_30(f_in, f_out, amanda);
          break;
     case 31:
          retvalue_z = decompress_thread_31(f_in, f_out, amanda);
          break;
     case 32:
          retvalue_z = decompress_thread_32(f_in, f_out, amanda);
          break;
     case 33:
          retvalue_z = decompress_thread_33(f_in, f_out, amanda);
          break;
     case 34:
          retvalue_z = decompress_thread_34(f_in, f_out, amanda);
          break;
     case 35:
          retvalue_z = decompress_thread_35(f_in, f_out, amanda);
          break;
     case 36:
          retvalue_z = decompress_thread_36(f_in, f_out, amanda);
          break;
     case 37:
          retvalue_z = decompress_thread_37(f_in, f_out, amanda);
          break;
     case 38:
          retvalue_z = decompress_thread_38(f_in, f_out, amanda);
          break;
     case 39:
          retvalue_z = decompress_thread_39(f_in, f_out, amanda);
          break;
     case 40:
          retvalue_z = decompress_thread_40(f_in, f_out, amanda);
          break;
     case 41:
          retvalue_z = decompress_thread_41(f_in, f_out, amanda);
          break;
     case 42:
          retvalue_z = decompress_thread_42(f_in, f_out, amanda);
          break;
     case 43:
          retvalue_z = decompress_thread_43(f_in, f_out, amanda);
          break;
     case 44:
          retvalue_z = decompress_thread_44(f_in, f_out, amanda);
          break;
     case 45:
          retvalue_z = decompress_thread_45(f_in, f_out, amanda);
          break;
     case 46:
          retvalue_z = decompress_thread_46(f_in, f_out, amanda);
          break;
     case 47:
          retvalue_z = decompress_thread_47(f_in, f_out, amanda);
          break;
     case 48:
          retvalue_z = decompress_thread_48(f_in, f_out, amanda);
          break;
     case 49:
          retvalue_z = decompress_thread_49(f_in, f_out, amanda);
          break;
     case 50:
          retvalue_z = decompress_thread_50(f_in, f_out, amanda);
          break;
     case 51:
          retvalue_z = decompress_thread_51(f_in, f_out, amanda);
          break;
     case 52:
          retvalue_z = decompress_thread_52(f_in, f_out, amanda);
          break;
     case 53:
          retvalue_z = decompress_thread_53(f_in, f_out, amanda);
          break;
     case 54:
          retvalue_z = decompress_thread_54(f_in, f_out, amanda);
          break;
     case 55:
          retvalue_z = decompress_thread_55(f_in, f_out, amanda);
          break;
     case 56:
          retvalue_z = decompress_thread_56(f_in, f_out, amanda);
          break;
     case 57:
          retvalue_z = decompress_thread_57(f_in, f_out, amanda);
          break;
     case 58:
          retvalue_z = decompress_thread_58(f_in, f_out, amanda);
          break;
     case 59:
          retvalue_z = decompress_thread_59(f_in, f_out, amanda);
          break;
     case 60:
          retvalue_z = decompress_thread_60(f_in, f_out, amanda);
          break;
     case 61:
          retvalue_z = decompress_thread_61(f_in, f_out, amanda);
          break;
     case 62:
          retvalue_z = decompress_thread_62(f_in, f_out, amanda);
          break;
     case 63:
          retvalue_z = decompress_thread_63(f_in, f_out, amanda);
          break;
     case 64:
          retvalue_z = decompress_thread_64(f_in, f_out, amanda);
          break;
     case 65:
          retvalue_z = decompress_thread_65(f_in, f_out, amanda);
          break;
     case 66:
          retvalue_z = decompress_thread_66(f_in, f_out, amanda);
          break;
     case 67:
          retvalue_z = decompress_thread_67(f_in, f_out, amanda);
          break;
     case 68:
          retvalue_z = decompress_thread_68(f_in, f_out, amanda);
          break;
     case 69:
          retvalue_z = decompress_thread_69(f_in, f_out, amanda);
          break;
     case 70:
          retvalue_z = decompress_thread_70(f_in, f_out, amanda);
          break;
     case 71:
          retvalue_z = decompress_thread_71(f_in, f_out, amanda);
          break;
     case 72:
          retvalue_z = decompress_thread_72(f_in, f_out, amanda);
          break;
     case 73:
          retvalue_z = decompress_thread_73(f_in, f_out, amanda);
          break;
     case 74:
          retvalue_z = decompress_thread_74(f_in, f_out, amanda);
          break;
     case 75:
          retvalue_z = decompress_thread_75(f_in, f_out, amanda);
          break;
     case 76:
          retvalue_z = decompress_thread_76(f_in, f_out, amanda);
          break;
     case 77:
          retvalue_z = decompress_thread_77(f_in, f_out, amanda);
          break;
     case 78:
          retvalue_z = decompress_thread_78(f_in, f_out, amanda);
          break;
     case 79:
          retvalue_z = decompress_thread_79(f_in, f_out, amanda);
          break;
     case 80:
          retvalue_z = decompress_thread_80(f_in, f_out, amanda);
          break;
     case 81:
          retvalue_z = decompress_thread_81(f_in, f_out, amanda);
          break;
     case 82:
          retvalue_z = decompress_thread_82(f_in, f_out, amanda);
          break;
     case 83:
          retvalue_z = decompress_thread_83(f_in, f_out, amanda);
          break;
     case 84:
          retvalue_z = decompress_thread_84(f_in, f_out, amanda);
          break;
     case 85:
          retvalue_z = decompress_thread_85(f_in, f_out, amanda);
          break;
     case 86:
          retvalue_z = decompress_thread_86(f_in, f_out, amanda);
          break;
     case 87:
          retvalue_z = decompress_thread_87(f_in, f_out, amanda);
          break;
     case 88:
          retvalue_z = decompress_thread_88(f_in, f_out, amanda);
          break;
     case 89:
          retvalue_z = decompress_thread_89(f_in, f_out, amanda);
          break;
     case 90:
          retvalue_z = decompress_thread_90(f_in, f_out, amanda);
          break;
     case 91:
          retvalue_z = decompress_thread_91(f_in, f_out, amanda);
          break;
     case 92:
          retvalue_z = decompress_thread_92(f_in, f_out, amanda);
          break;
     case 93:
          retvalue_z = decompress_thread_93(f_in, f_out, amanda);
          break;
     case 94:
          retvalue_z = decompress_thread_94(f_in, f_out, amanda);
          break;
     case 95:
          retvalue_z = decompress_thread_95(f_in, f_out, amanda);
          break;
     case 96:
          retvalue_z = decompress_thread_96(f_in, f_out, amanda);
          break;
     case 97:
          retvalue_z = decompress_thread_97(f_in, f_out, amanda);
          break;
     case 98:
          retvalue_z = decompress_thread_98(f_in, f_out, amanda);
          break;
     case 99:
          retvalue_z = decompress_thread_99(f_in, f_out, amanda);
          break;
     case 100:
          retvalue_z = decompress_thread_100(f_in, f_out, amanda);
          break;
     case 101:
          retvalue_z = decompress_thread_101(f_in, f_out, amanda);
          break;
     case 102:
          retvalue_z = decompress_thread_102(f_in, f_out, amanda);
          break;
     case 103:
          retvalue_z = decompress_thread_103(f_in, f_out, amanda);
          break;
     case 104:
          retvalue_z = decompress_thread_104(f_in, f_out, amanda);
          break;
     case 105:
          retvalue_z = decompress_thread_105(f_in, f_out, amanda);
          break;
     case 106:
          retvalue_z = decompress_thread_106(f_in, f_out, amanda);
          break;
     case 107:
          retvalue_z = decompress_thread_107(f_in, f_out, amanda);
          break;
     case 108:
          retvalue_z = decompress_thread_108(f_in, f_out, amanda);
          break;
     case 109:
          retvalue_z = decompress_thread_109(f_in, f_out, amanda);
          break;
     case 110:
          retvalue_z = decompress_thread_110(f_in, f_out, amanda);
          break;
     case 111:
          retvalue_z = decompress_thread_111(f_in, f_out, amanda);
          break;
     case 112:
          retvalue_z = decompress_thread_112(f_in, f_out, amanda);
          break;
     case 113:
          retvalue_z = decompress_thread_113(f_in, f_out, amanda);
          break;
     case 114:
          retvalue_z = decompress_thread_114(f_in, f_out, amanda);
          break;
     case 115:
          retvalue_z = decompress_thread_115(f_in, f_out, amanda);
          break;
     case 116:
          retvalue_z = decompress_thread_116(f_in, f_out, amanda);
          break;
     case 117:
          retvalue_z = decompress_thread_117(f_in, f_out, amanda);
          break;
     case 118:
          retvalue_z = decompress_thread_118(f_in, f_out, amanda);
          break;
     case 119:
          retvalue_z = decompress_thread_119(f_in, f_out, amanda);
          break;
     case 120:
          retvalue_z = decompress_thread_120(f_in, f_out, amanda);
          break;
     case 121:
          retvalue_z = decompress_thread_121(f_in, f_out, amanda);
          break;
     case 122:
          retvalue_z = decompress_thread_122(f_in, f_out, amanda);
          break;
     case 123:
          retvalue_z = decompress_thread_123(f_in, f_out, amanda);
          break;
     case 124:
          retvalue_z = decompress_thread_124(f_in, f_out, amanda);
          break;
     case 125:
          retvalue_z = decompress_thread_125(f_in, f_out, amanda);
          break;
     case 126:
          retvalue_z = decompress_thread_126(f_in, f_out, amanda);
          break;
     case 127:
          retvalue_z = decompress_thread_127(f_in, f_out, amanda);
          break;
     case 128:
          retvalue_z = decompress_thread_128(f_in, f_out, amanda);
          break;

     default:
          pedro_dprintf(2, "Invalid value for decompress thread\n");
          exit(27);

          break;
     }

     if (retvalue_z)
     {
          retvalue_z = 1;
     }

     return retvalue_z;
}
AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -I ./ -Wno-misleading-indentation
JULIET_FLAGS  = 

AMANDA_SIZE__ =                                    62

amanda_32: ar_main_32arp.o                         \
	7zAlloc_32aakp.o 7zArcIn_32aakp.o          \
	7zBuf2_32aakp.o	7zBuf_32aakp.o             \
	7zCrc_32aakp.o 7zCrcOpt_32aakp.o           \
	7zDec_32aakp.o 7zFile_32aakp.o             \
	7zStream_32aakp.o Aes_32aakp.o             \
	AesOpt_32aakp.o	Alloc_32aakp.o             \
	pedro_32aakp.o                             \
	Bcj2_32aakp.o Bcj2Enc_32aakp.o             \
	Bra86_32aakp.o Bra_32aakp.o                \
	BraIA64_32aakp.o CpuArch_32aakp.o          \
	Delta_32aakp.o DllSecur_32aakp.o           \
	LzFind_32aakp.o LzFindMt_32aakp.o          \
	Lzma2Dec_32aakp.o Lzma2DecMt_32aakp.o      \
	Lzma2Enc_32aakp.o Lzma86Dec_32aakp.o       \
	Lzma86Enc_32aakp.o LzmaDec_32aakp.o        \
	LzmaEnc_32aakp.o LzmaLib_32aakp.o          \
	MtCoder_32aakp.o MtDec_32aakp.o            \
	Ppmd7_32aakp.o Ppmd7Dec_32aakp.o           \
	Ppmd7Enc_32aakp.o Sha256_32aakp.o          \
	Sort_32aakp.o Threads_32aakp.o             \
	util/Lzma/LzmaUtil_32arp.o Xz_32aakp.o     \
	XzCrc64_32aakp.o XzCrc64Opt_32aakp.o       \
	XzDec_32aakp.o XzEnc_32aakp.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	ar_main_32arp.o                            \
	7zAlloc_32aakp.o 7zArcIn_32aakp.o          \
	7zBuf2_32aakp.o	7zBuf_32aakp.o             \
	7zCrc_32aakp.o 7zCrcOpt_32aakp.o           \
	7zDec_32aakp.o 7zFile_32aakp.o             \
	7zStream_32aakp.o Aes_32aakp.o             \
	AesOpt_32aakp.o	Alloc_32aakp.o             \
	pedro_32aakp.o                             \
	Bcj2_32aakp.o Bcj2Enc_32aakp.o             \
	Bra86_32aakp.o Bra_32aakp.o                \
	BraIA64_32aakp.o CpuArch_32aakp.o          \
	Delta_32aakp.o DllSecur_32aakp.o           \
	LzFind_32aakp.o LzFindMt_32aakp.o          \
	Lzma2Dec_32aakp.o Lzma2DecMt_32aakp.o      \
	Lzma2Enc_32aakp.o Lzma86Dec_32aakp.o       \
	Lzma86Enc_32aakp.o LzmaDec_32aakp.o        \
	LzmaEnc_32aakp.o LzmaLib_32aakp.o          \
	MtCoder_32aakp.o MtDec_32aakp.o            \
	Ppmd7_32aakp.o Ppmd7Dec_32aakp.o           \
	Ppmd7Enc_32aakp.o Sha256_32aakp.o          \
	Sort_32aakp.o Threads_32aakp.o             \
	util/Lzma/LzmaUtil_32arp.o Xz_32aakp.o     \
	XzCrc64_32aakp.o XzCrc64Opt_32aakp.o       \
	XzDec_32aakp.o XzEnc_32aakp.o

	@./amandaricardo_mvbuild26_32.exe          \
	./amanda_file_counter_32.ini               \
	versio_n.ama.rc                            \
	version_ricardo_mislaine_final_2_.rc       \
	aline_definitive_header_2_.h               \
	"32 bits" rsp_lzma_aakp_32.dll increase

	@i686-w64-mingw32-windres.exe -o           \
	ver_32_ar.o -O coff                        \
	version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -mdll -O3 -o     \
	rsp_lzma_aakp_32.dll def_ar.def            \
	ar_main_32arp.o                            \
	7zAlloc_32aakp.o 7zArcIn_32aakp.o          \
	7zBuf2_32aakp.o	7zBuf_32aakp.o             \
	7zCrc_32aakp.o 7zCrcOpt_32aakp.o           \
	7zDec_32aakp.o 7zFile_32aakp.o             \
	7zStream_32aakp.o Aes_32aakp.o             \
	AesOpt_32aakp.o	Alloc_32aakp.o             \
	pedro_32aakp.o                             \
	Bcj2_32aakp.o Bcj2Enc_32aakp.o             \
	Bra86_32aakp.o Bra_32aakp.o                \
	BraIA64_32aakp.o CpuArch_32aakp.o          \
	Delta_32aakp.o DllSecur_32aakp.o           \
	LzFind_32aakp.o LzFindMt_32aakp.o          \
	Lzma2Dec_32aakp.o Lzma2DecMt_32aakp.o      \
	Lzma2Enc_32aakp.o Lzma86Dec_32aakp.o       \
	Lzma86Enc_32aakp.o LzmaDec_32aakp.o        \
	LzmaEnc_32aakp.o LzmaLib_32aakp.o          \
	MtCoder_32aakp.o MtDec_32aakp.o            \
	Ppmd7_32aakp.o Ppmd7Dec_32aakp.o           \
	Ppmd7Enc_32aakp.o Sha256_32aakp.o          \
	Sort_32aakp.o Threads_32aakp.o             \
	util/Lzma/LzmaUtil_32arp.o Xz_32aakp.o     \
	XzCrc64_32aakp.o XzCrc64Opt_32aakp.o       \
	XzDec_32aakp.o XzEnc_32aakp.o              \
	-Wl,-enable-stdcall-fixup

	@cp rsp_lzma_aakp_32.dll ../..

	@cp rsp_lzma_aakp_32.DLL                   'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'

	@./espaco_arp.exe $(AMANDA_SIZE__)

ar_main_32arp.o : ar_main.c
	i686-w64-mingw32-gcc.exe -c -o             \
	ar_main_32arp.o                            \
	ar_main.c                                  \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	ar_main_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

util/Lzma/LzmaUtil_32arp.o : util/Lzma/LzmaUtil.c
	i686-w64-mingw32-gcc.exe -c -o             \
	util/Lzma/LzmaUtil_32arp.o                 \
	util/Lzma/LzmaUtil.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	util/Lzma/LzmaUtil_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_32aakp.o : pedro.c
	i686-w64-mingw32-gcc.exe -c -o             \
	pedro_32aakp.o                             \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	pedro_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zAlloc_32aakp.o : 7zAlloc.c
	i686-w64-mingw32-gcc.exe -c -o             \
	7zAlloc_32aakp.o 7zAlloc.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	7zAlloc_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zArcIn_32aakp.o : 7zArcIn.c
	i686-w64-mingw32-gcc.exe -c -o             \
	7zArcIn_32aakp.o 7zArcIn.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	7zArcIn_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zBuf_32aakp.o : 7zBuf.c
	i686-w64-mingw32-gcc.exe -c -o             \
	7zBuf_32aakp.o 7zBuf.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	7zBuf_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zBuf2_32aakp.o : 7zBuf2.c
	i686-w64-mingw32-gcc.exe -c -o             \
	7zBuf2_32aakp.o 7zBuf2.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	7zBuf2_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zCrc_32aakp.o : 7zCrc.c
	i686-w64-mingw32-gcc.exe -c -o             \
	7zCrc_32aakp.o 7zCrc.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	7zCrc_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zCrcOpt_32aakp.o : 7zCrcOpt.c
	i686-w64-mingw32-gcc.exe -c -o             \
	7zCrcOpt_32aakp.o 7zCrcOpt.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	7zCrcOpt_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zDec_32aakp.o : 7zDec.c
	i686-w64-mingw32-gcc.exe -c -o             \
	7zDec_32aakp.o 7zDec.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	7zDec_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zFile_32aakp.o : 7zFile.c
	i686-w64-mingw32-gcc.exe -c -o             \
	7zFile_32aakp.o 7zFile.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	7zFile_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zStream_32aakp.o : 7zStream.c
	i686-w64-mingw32-gcc.exe -c -o             \
	7zStream_32aakp.o 7zStream.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	7zStream_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Aes_32aakp.o : Aes.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Aes_32aakp.o Aes.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Aes_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

AesOpt_32aakp.o : AesOpt.c
	i686-w64-mingw32-gcc.exe -c -o             \
	AesOpt_32aakp.o AesOpt.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	AesOpt_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Alloc_32aakp.o : Alloc.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Alloc_32aakp.o Alloc.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Alloc_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Bcj2_32aakp.o : Bcj2.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Bcj2_32aakp.o Bcj2.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Bcj2_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Bcj2Enc_32aakp.o : Bcj2Enc.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Bcj2Enc_32aakp.o Bcj2Enc.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Bcj2Enc_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Bra_32aakp.o : Bra.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Bra_32aakp.o Bra.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Bra_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Bra86_32aakp.o : Bra86.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Bra86_32aakp.o Bra86.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Bra86_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

BraIA64_32aakp.o : BraIA64.c
	i686-w64-mingw32-gcc.exe -c -o             \
	BraIA64_32aakp.o BraIA64.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	BraIA64_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

CpuArch_32aakp.o : CpuArch.c
	i686-w64-mingw32-gcc.exe -c -o             \
	CpuArch_32aakp.o CpuArch.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	CpuArch_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Delta_32aakp.o : Delta.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Delta_32aakp.o Delta.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Delta_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

DllSecur_32aakp.o : DllSecur.c
	i686-w64-mingw32-gcc.exe -c -o             \
	DllSecur_32aakp.o DllSecur.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	DllSecur_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

LzFind_32aakp.o : LzFind.c
	i686-w64-mingw32-gcc.exe -c -o             \
	LzFind_32aakp.o LzFind.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	LzFind_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

LzFindMt_32aakp.o : LzFindMt.c
	i686-w64-mingw32-gcc.exe -c -o             \
	LzFindMt_32aakp.o LzFindMt.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	LzFindMt_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Lzma2Dec_32aakp.o : Lzma2Dec.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Lzma2Dec_32aakp.o Lzma2Dec.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Lzma2Dec_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Lzma2DecMt_32aakp.o : Lzma2DecMt.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Lzma2DecMt_32aakp.o Lzma2DecMt.c           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Lzma2DecMt_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Lzma2Enc_32aakp.o : Lzma2Enc.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Lzma2Enc_32aakp.o Lzma2Enc.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Lzma2Enc_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Lzma86Dec_32aakp.o : Lzma86Dec.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Lzma86Dec_32aakp.o Lzma86Dec.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Lzma86Dec_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Lzma86Enc_32aakp.o : Lzma86Enc.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Lzma86Enc_32aakp.o Lzma86Enc.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Lzma86Enc_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

LzmaDec_32aakp.o : LzmaDec.c
	i686-w64-mingw32-gcc.exe -c -o             \
	LzmaDec_32aakp.o LzmaDec.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	LzmaDec_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

LzmaEnc_32aakp.o : LzmaEnc.c
	i686-w64-mingw32-gcc.exe -c -o             \
	LzmaEnc_32aakp.o LzmaEnc.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	LzmaEnc_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

LzmaLib_32aakp.o : LzmaLib.c
	i686-w64-mingw32-gcc.exe -c -o             \
	LzmaLib_32aakp.o LzmaLib.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	LzmaLib_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

MtCoder_32aakp.o : MtCoder.c
	i686-w64-mingw32-gcc.exe -c -o             \
	MtCoder_32aakp.o MtCoder.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	MtCoder_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

MtDec_32aakp.o : MtDec.c
	i686-w64-mingw32-gcc.exe -c -o             \
	MtDec_32aakp.o MtDec.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	MtDec_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Ppmd7_32aakp.o : Ppmd7.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Ppmd7_32aakp.o Ppmd7.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Ppmd7_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Ppmd7Dec_32aakp.o : Ppmd7Dec.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Ppmd7Dec_32aakp.o Ppmd7Dec.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Ppmd7Dec_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Ppmd7Enc_32aakp.o : Ppmd7Enc.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Ppmd7Enc_32aakp.o Ppmd7Enc.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Ppmd7Enc_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Sha256_32aakp.o : Sha256.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Sha256_32aakp.o Sha256.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Sha256_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Sort_32aakp.o : Sort.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Sort_32aakp.o Sort.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Sort_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Threads_32aakp.o : Threads.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Threads_32aakp.o Threads.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Threads_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Xz_32aakp.o : Xz.c
	i686-w64-mingw32-gcc.exe -c -o             \
	Xz_32aakp.o Xz.c                           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	Xz_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

XzCrc64_32aakp.o : XzCrc64.c
	i686-w64-mingw32-gcc.exe -c -o             \
	XzCrc64_32aakp.o XzCrc64.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	XzCrc64_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

XzCrc64Opt_32aakp.o : XzCrc64Opt.c
	i686-w64-mingw32-gcc.exe -c -o             \
	XzCrc64Opt_32aakp.o XzCrc64Opt.c           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	XzCrc64Opt_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

XzDec_32aakp.o : XzDec.c
	i686-w64-mingw32-gcc.exe -c -o             \
	XzDec_32aakp.o XzDec.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	XzDec_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

XzEnc_32aakp.o : XzEnc.c
	i686-w64-mingw32-gcc.exe -c -o             \
	XzEnc_32aakp.o XzEnc.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	XzEnc_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

##########################64 bits

ricardo_64: ar_main_64arp.o                        \
	7zAlloc_64aakp.o 7zArcIn_64aakp.o          \
	7zBuf2_64aakp.o	7zBuf_64aakp.o             \
	7zCrc_64aakp.o 7zCrcOpt_64aakp.o           \
	7zDec_64aakp.o 7zFile_64aakp.o             \
	7zStream_64aakp.o Aes_64aakp.o             \
	AesOpt_64aakp.o	Alloc_64aakp.o             \
	pedro_64aakp.o                             \
	Bcj2_64aakp.o Bcj2Enc_64aakp.o             \
	Bra86_64aakp.o Bra_64aakp.o                \
	BraIA64_64aakp.o CpuArch_64aakp.o          \
	Delta_64aakp.o DllSecur_64aakp.o           \
	LzFind_64aakp.o LzFindMt_64aakp.o          \
	Lzma2Dec_64aakp.o Lzma2DecMt_64aakp.o      \
	Lzma2Enc_64aakp.o Lzma86Dec_64aakp.o       \
	Lzma86Enc_64aakp.o LzmaDec_64aakp.o        \
	LzmaEnc_64aakp.o LzmaLib_64aakp.o          \
	MtCoder_64aakp.o MtDec_64aakp.o            \
	Ppmd7_64aakp.o Ppmd7Dec_64aakp.o           \
	Ppmd7Enc_64aakp.o Sha256_64aakp.o          \
	Sort_64aakp.o Threads_64aakp.o             \
	util/Lzma/LzmaUtil_64arp.o Xz_64aakp.o     \
	XzCrc64_64aakp.o XzCrc64Opt_64aakp.o       \
	XzDec_64aakp.o XzEnc_64aakp.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	ar_main_64arp.o                            \
	7zAlloc_64aakp.o 7zArcIn_64aakp.o          \
	7zBuf2_64aakp.o	7zBuf_64aakp.o             \
	7zCrc_64aakp.o 7zCrcOpt_64aakp.o           \
	7zDec_64aakp.o 7zFile_64aakp.o             \
	7zStream_64aakp.o Aes_64aakp.o             \
	AesOpt_64aakp.o	Alloc_64aakp.o             \
	pedro_64aakp.o                             \
	Bcj2_64aakp.o Bcj2Enc_64aakp.o             \
	Bra86_64aakp.o Bra_64aakp.o                \
	BraIA64_64aakp.o CpuArch_64aakp.o          \
	Delta_64aakp.o DllSecur_64aakp.o           \
	LzFind_64aakp.o LzFindMt_64aakp.o          \
	Lzma2Dec_64aakp.o Lzma2DecMt_64aakp.o      \
	Lzma2Enc_64aakp.o Lzma86Dec_64aakp.o       \
	Lzma86Enc_64aakp.o LzmaDec_64aakp.o        \
	LzmaEnc_64aakp.o LzmaLib_64aakp.o          \
	MtCoder_64aakp.o MtDec_64aakp.o            \
	Ppmd7_64aakp.o Ppmd7Dec_64aakp.o           \
	Ppmd7Enc_64aakp.o Sha256_64aakp.o          \
	Sort_64aakp.o Threads_64aakp.o             \
	util/Lzma/LzmaUtil_64arp.o Xz_64aakp.o     \
	XzCrc64_64aakp.o XzCrc64Opt_64aakp.o       \
	XzDec_64aakp.o XzEnc_64aakp.o

	@./amandaricardo_mvbuild26_32.exe          \
	./amanda_file_counter_32.ini               \
	versio_n.ama.rc                            \
	version_ricardo_mislaine_final_2_.rc       \
	aline_definitive_header_2_.h               \
	"63.5 bits" rsp_lzma_aakp_64.dll increase

	@x86_64-w64-mingw32-windres.exe -o         \
	ver_64_ar.o -O coff                        \
	version_ricardo_mislaine_final_2_.rc

	@x86_64-w64-mingw32-gcc.exe -mdll -O3 -o   \
	rsp_lzma_aakp_64.dll                       \
	def_ar.def ar_main_64arp.o                 \
	7zAlloc_64aakp.o 7zArcIn_64aakp.o          \
	7zBuf2_64aakp.o	7zBuf_64aakp.o             \
	7zCrc_64aakp.o 7zCrcOpt_64aakp.o           \
	7zDec_64aakp.o 7zFile_64aakp.o             \
	7zStream_64aakp.o Aes_64aakp.o             \
	AesOpt_64aakp.o	Alloc_64aakp.o             \
	pedro_64aakp.o                             \
	Bcj2_64aakp.o Bcj2Enc_64aakp.o             \
	Bra86_64aakp.o Bra_64aakp.o                \
	BraIA64_64aakp.o CpuArch_64aakp.o          \
	Delta_64aakp.o DllSecur_64aakp.o           \
	LzFind_64aakp.o LzFindMt_64aakp.o          \
	Lzma2Dec_64aakp.o Lzma2DecMt_64aakp.o      \
	Lzma2Enc_64aakp.o Lzma86Dec_64aakp.o       \
	Lzma86Enc_64aakp.o LzmaDec_64aakp.o        \
	LzmaEnc_64aakp.o LzmaLib_64aakp.o          \
	MtCoder_64aakp.o MtDec_64aakp.o            \
	Ppmd7_64aakp.o Ppmd7Dec_64aakp.o           \
	Ppmd7Enc_64aakp.o Sha256_64aakp.o          \
	Sort_64aakp.o Threads_64aakp.o             \
	util/Lzma/LzmaUtil_64arp.o Xz_64aakp.o     \
	XzCrc64_64aakp.o XzCrc64Opt_64aakp.o       \
	XzDec_64aakp.o XzEnc_64aakp.o              \
	-Wl,-enable-stdcall-fixup

	@cp rsp_lzma_aakp_64.dll ../..

	@cp rsp_lzma_aakp_64.DLL                   'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar_x64/tar_sample_ar/bin/Release'

	@./espaco_arp.exe $(AMANDA_SIZE__)

ar_main_64arp.o : ar_main.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	ar_main_64arp.o                            \
	ar_main.c                                  \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	ar_main_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

util/Lzma/LzmaUtil_64arp.o : util/Lzma/LzmaUtil.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	util/Lzma/LzmaUtil_64arp.o                 \
	util/Lzma/LzmaUtil.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	util/Lzma/LzmaUtil_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_64aakp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	pedro_64aakp.o                             \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	pedro_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zAlloc_64aakp.o : 7zAlloc.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	7zAlloc_64aakp.o 7zAlloc.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	7zAlloc_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zArcIn_64aakp.o : 7zArcIn.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	7zArcIn_64aakp.o 7zArcIn.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	7zArcIn_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zBuf_64aakp.o : 7zBuf.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	7zBuf_64aakp.o 7zBuf.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	7zBuf_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zBuf2_64aakp.o : 7zBuf2.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	7zBuf2_64aakp.o 7zBuf2.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	7zBuf2_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zCrc_64aakp.o : 7zCrc.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	7zCrc_64aakp.o 7zCrc.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	7zCrc_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zCrcOpt_64aakp.o : 7zCrcOpt.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	7zCrcOpt_64aakp.o 7zCrcOpt.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	7zCrcOpt_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zDec_64aakp.o : 7zDec.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	7zDec_64aakp.o 7zDec.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	7zDec_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zFile_64aakp.o : 7zFile.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	7zFile_64aakp.o 7zFile.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	7zFile_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

7zStream_64aakp.o : 7zStream.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	7zStream_64aakp.o 7zStream.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	7zStream_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Aes_64aakp.o : Aes.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Aes_64aakp.o Aes.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Aes_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

AesOpt_64aakp.o : AesOpt.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	AesOpt_64aakp.o AesOpt.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	AesOpt_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Alloc_64aakp.o : Alloc.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Alloc_64aakp.o Alloc.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Alloc_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Bcj2_64aakp.o : Bcj2.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Bcj2_64aakp.o Bcj2.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Bcj2_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Bcj2Enc_64aakp.o : Bcj2Enc.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Bcj2Enc_64aakp.o Bcj2Enc.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Bcj2Enc_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Bra_64aakp.o : Bra.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Bra_64aakp.o Bra.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Bra_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Bra86_64aakp.o : Bra86.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Bra86_64aakp.o Bra86.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Bra86_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

BraIA64_64aakp.o : BraIA64.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	BraIA64_64aakp.o BraIA64.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	BraIA64_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

CpuArch_64aakp.o : CpuArch.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	CpuArch_64aakp.o CpuArch.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	CpuArch_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Delta_64aakp.o : Delta.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Delta_64aakp.o Delta.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Delta_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

DllSecur_64aakp.o : DllSecur.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	DllSecur_64aakp.o DllSecur.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	DllSecur_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

LzFind_64aakp.o : LzFind.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	LzFind_64aakp.o LzFind.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	LzFind_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

LzFindMt_64aakp.o : LzFindMt.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	LzFindMt_64aakp.o LzFindMt.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	LzFindMt_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Lzma2Dec_64aakp.o : Lzma2Dec.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Lzma2Dec_64aakp.o Lzma2Dec.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Lzma2Dec_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Lzma2DecMt_64aakp.o : Lzma2DecMt.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Lzma2DecMt_64aakp.o Lzma2DecMt.c           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Lzma2DecMt_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Lzma2Enc_64aakp.o : Lzma2Enc.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Lzma2Enc_64aakp.o Lzma2Enc.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Lzma2Enc_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Lzma86Dec_64aakp.o : Lzma86Dec.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Lzma86Dec_64aakp.o Lzma86Dec.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Lzma86Dec_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Lzma86Enc_64aakp.o : Lzma86Enc.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Lzma86Enc_64aakp.o Lzma86Enc.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Lzma86Enc_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

LzmaDec_64aakp.o : LzmaDec.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	LzmaDec_64aakp.o LzmaDec.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	LzmaDec_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

LzmaEnc_64aakp.o : LzmaEnc.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	LzmaEnc_64aakp.o LzmaEnc.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	LzmaEnc_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

LzmaLib_64aakp.o : LzmaLib.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	LzmaLib_64aakp.o LzmaLib.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	LzmaLib_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

MtCoder_64aakp.o : MtCoder.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	MtCoder_64aakp.o MtCoder.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	MtCoder_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

MtDec_64aakp.o : MtDec.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	MtDec_64aakp.o MtDec.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	MtDec_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Ppmd7_64aakp.o : Ppmd7.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Ppmd7_64aakp.o Ppmd7.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Ppmd7_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Ppmd7Dec_64aakp.o : Ppmd7Dec.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Ppmd7Dec_64aakp.o Ppmd7Dec.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Ppmd7Dec_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Ppmd7Enc_64aakp.o : Ppmd7Enc.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Ppmd7Enc_64aakp.o Ppmd7Enc.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Ppmd7Enc_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Sha256_64aakp.o : Sha256.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Sha256_64aakp.o Sha256.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Sha256_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Sort_64aakp.o : Sort.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Sort_64aakp.o Sort.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Sort_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Threads_64aakp.o : Threads.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Threads_64aakp.o Threads.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Threads_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

Xz_64aakp.o : Xz.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	Xz_64aakp.o Xz.c                           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	Xz_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

XzCrc64_64aakp.o : XzCrc64.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	XzCrc64_64aakp.o XzCrc64.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	XzCrc64_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

XzCrc64Opt_64aakp.o : XzCrc64Opt.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	XzCrc64Opt_64aakp.o XzCrc64Opt.c           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	XzCrc64Opt_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

XzDec_64aakp.o : XzDec.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	XzDec_64aakp.o XzDec.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	XzDec_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

XzEnc_64aakp.o : XzEnc.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	XzEnc_64aakp.o XzEnc.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	XzEnc_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

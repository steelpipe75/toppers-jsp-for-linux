/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
 *  Copyright (C) 2010 by Cronus Computer Works, JAPAN
 * 
 *  上記著作権者は，以下の (1)～(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id
 */

/*
 *   SH2内蔵シリアルコミュニケーションインタフェースSCIF用 簡易ドライバ
 */

#include <s_services.h>
#include "sh726xscif.h"
#define _MACRO_ONLY
#include "hw_serial.h"

/*
 *  シリアルI/Oポート管理ブロックの定義
 */

#ifndef GDB_STUB

const SIOPINIB siopinib_table[TNUM_PORT] = {
	{REGBASE_SERIAL, BRR_VALUE(SCIF_BPS), 0x0, SCIF_INTLVL},
#if TNUM_PORT >= 2
	{REGBASE_SERIAL2, BRR_VALUE(SCIF_BPS), 0x0, SCIF_INTLVL},
#endif /* TNUM_PORT >= 2 */
};

#else /* GDB_STUB */

const SIOPINIB siopinib_table[TNUM_PORT] = {
	{REGBASE_SERIAL, BRR_VALUE(SCIF_BPS), 0x0, SCIF_INTLVL},
};

#endif /* GDB_STUB */

/*
 *  シリアルI/Oポート管理ブロックのエリア
 */
static SIOPCB siopcb_table[TNUM_PORT];

/*
 *  シリアルI/OポートIDから管理ブロックを取り出すためのマクロ
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  文字を受信できるか？
 */
Inline BOOL
sh2scif_getready (SIOPCB * siopcb)
{
	/*  レシーブデータレジスタフル・フラグのチェック  */
	return (sil_reh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCFSR)) &
			SCFSR_RDRF);
}

/*
 *  文字を送信できるか？
 */
Inline BOOL
sh2scif_putready (SIOPCB * siopcb)
{
	/*  トランスミットFIFOデータレジスタエンプティ・フラグのチェック */
	return (sil_reh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCFSR)) &
			SCFSR_TDFE);
}

/*
 *  受信した文字の取出し
 */
Inline char
sh2scif_getchar (SIOPCB * siopcb)
{
	VB data;

	data = sil_reb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFRDR));
	/*  レシーブデータレジスタフル・フラグのクリア  */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCFSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SCFSR)) & ~SCFSR_RDRF);
	return data;
}

/*
 *  送信する文字の書込み
 */
Inline void
sh2scif_putchar (SIOPCB * siopcb, char c)
{
	/*  トランスミットFIFOデータレジスタエンプティ・フラグのクリア */
	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCFTDR), c);
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCFSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SCFSR)) & ~SCFSR_TDFE);
}

/*
 *  SIOドライバの初期化ルーチン
 */
void
sh2scif_initialize ()
{
	SIOPCB *siopcb;
	UINT i;

	/*
	 *  シルアルI/Oポート管理ブロックの初期化
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_PORT; siopcb++, i++) {
		siopcb->openflag = FALSE;
		siopcb->siopinib = (&siopinib_table[i]);
	}
}

/*
 *  オープンしているポートがあるか？
 */
BOOL
sh2scif_openflag (ID siopid)
{
	return (siopcb_table[siopid - 1].openflag);
}

/*
 *  シリアルI/Oポートのオープン
 */
SIOPCB *
sh2scif_opn_por (ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb;

	siopcb = get_siopcb (siopid);

	/*  送受信停止  */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SCSCR)) & ~(SCSCR_TE | SCSCR_RE));

	/*  SCIFデータ入出力ポートの設定  */
	/*  ピンアサイン */
	/* sys_initializeで設定 */

	/*  FIFOの初期化  */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCFCR),
				 (VH) (SCFCR_TFRST | SCFCR_RFRST));

	/*  送受信フォーマット  */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCSMR), 0x0000);
	/*  調歩同期式  */
	/*  8ビット、パリティなし  */
	/*  ストップビットレングス：1   */
	/*  クロックセレクト */

	sil_wrb_mem ((VB *) (siopcb->siopinib->reg_base + SCIF_SCBRR),
				 (VB) siopcb->siopinib->brr);	/* ボーレート設定 */


	/*
	 * ボーレートの設定後、1カウント分待たなければならない。
	 */
	sil_dly_nse (sh2scif_DELAY);

	/*  FIFOの設定  */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCFCR), 0x0030);

	/* エラーフラグをクリア */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCFSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SCFSR)) & ~SCFSR_ER);

	/*  送受信開始  */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
				 (VH) (SCSCR_TE | SCSCR_RE));

	siopcb->exinf = exinf;
	siopcb->openflag = TRUE;
	return (siopcb);
}

/*
 *  シリアルI/Oポートのクローズ
 */
void
sh2scif_cls_por (SIOPCB * siopcb)
{
	/*  送受信停止、割込み禁止  */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
				 (VH) ~ (SCSCR_TIE | SCSCR_RIE | SCSCR_TE | SCSCR_RE));

	siopcb->openflag = FALSE;
}

/*
 *  シリアルI/Oポートへの文字送信
 */
BOOL
sh2scif_snd_chr (SIOPCB * siopcb, char c)
{
	if (sh2scif_putready (siopcb)) {
		sh2scif_putchar (siopcb, c);
		return (TRUE);
	}
	return (FALSE);
}

/*
 *  シリアルI/Oポートからの文字受信
 */
INT
sh2scif_rcv_chr (SIOPCB * siopcb)
{
	if (sh2scif_getready (siopcb)) {
		return ((INT) (UB) sh2scif_getchar (siopcb));
	}
	return (-1);
}

/*
 *  シリアルI/Oポートからのコールバックの許可
 */
void
sh2scif_ena_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* 送信割り込み要求を許可 */
		sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) | SCSCR_TIE);
		break;
	case SIO_ERDY_RCV:			/* 受信割り込み要求を許可 */
		sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) | SCSCR_RIE);
		break;
	}
}

/*
 *  シリアルI/Oポートからのコールバックの禁止
 */
void
sh2scif_dis_cbr (SIOPCB * siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:			/* 送信割り込み要求を禁止 */
		sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) & ~SCSCR_TIE);
		break;
	case SIO_ERDY_RCV:			/* 受信割り込み要求を禁止 */
		sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCSCR),
					 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
										  SCIF_SCSCR)) & ~SCSCR_RIE);
		break;
	}
}

/*
 *  シリアルI/Oポートに対する送信割込み処理
 */
Inline void
sh2scif_isr_siop_out (SIOPCB * siopcb)
{
	VH scr0 = sil_reh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCSCR));

	if ((scr0 & SCSCR_TIE) != 0 && sh2scif_putready (siopcb)) {
		/*
		 *  送信通知コールバックルーチンを呼び出す．
		 */
		sh2scif_ierdy_snd (siopcb->exinf);
	}
}

/*
 *  シリアルI/Oポートに対する受信割込み処理
 */
Inline void
sh2scif_isr_siop_in (SIOPCB * siopcb)
{
	VH scr0 = sil_reh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCSCR));

	if ((scr0 & SCSCR_RIE) != 0 && sh2scif_getready (siopcb)) {
		/*
		 *  受信通知コールバックルーチンを呼び出す．
		 */
		sh2scif_ierdy_rcv (siopcb->exinf);
	}
}

/*
 *  シリアルI/Oポートに対する受信エラー割込み処理
 */
Inline void
sh2scif_isr_siop_err (SIOPCB * siopcb)
{
	/* エラーフラグをクリア */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCFSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SCFSR)) & ~SCFSR_ER);
	/*  FIFOの初期化  */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCFCR),
				 (VH) SCFCR_RFRST);
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCFCR), 0x0030);
}

/* ブレーク検出処理 */
/* フラグをリセットする */
Inline void
sh2scif_isr_siop_brk (SIOPCB * siopcb)
{
	/* フラグをクリア */
	sil_wrh_mem ((VH *) (siopcb->siopinib->reg_base + SCIF_SCFSR),
				 sil_reh_mem ((VH *) (siopcb->siopinib->reg_base +
									  SCIF_SCFSR)) & ~SCFSR_BRK);
}

/*
 *  SCIF送信割込みサービスルーチン
 *  
 *  　SH2内蔵のSCIFでは割込み番号が送受信別、チャネル別に分かれているので、
 *  　SCIFの送信割込み以外でこのルーチンが呼ばれることはない
 *  
 */
void
sh2scif_isr_out ()
{
	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_out (get_siopcb (1));
	}
}

/*
 *  SCIF受信割込みサービスルーチン
 *  
 *  　SH2内蔵のSCIFでは割込み番号が送受信別、チャネル別に分かれているので、
 *  　SCIFの受信割込み以外でこのルーチンが呼ばれることはない
 *  
 */
void
sh2scif_isr_in ()
{
	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_in (get_siopcb (1));
	}
}

/*
 *  SIO受信エラー割込みサービスルーチン
 *  
 *  　SH2内蔵のSCIFでは割込み番号がチャネル別に分かれているので、
 *  　SCIFの受信エラー割込み以外でこのルーチンが呼ばれることはない
 *  　
 *  　エラー処理自体はエラーフラグのクリアのみにとどめている。
 *  　　　・オーバーランエラー
 *  　　　・フレーミングエラー
 *  　　　・パリティエラー
 */
void
sh2scif_isr_error (void)
{

	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_err (get_siopcb (1));
	}
}

/* ブレーク検出 */
void
sh2scif_isr_brk (void)
{

	if (siopcb_table[0].openflag) {
		sh2scif_isr_siop_brk (get_siopcb (1));
	}
}

/*
 * ポーリングによる文字の送信
 */
void
sh2scif_putc_pol (ID portid, char c)
{
	while (!sh2scif_putready (&siopcb_table[portid - 1]));
	sh2scif_putchar (&siopcb_table[portid - 1], c);
}

#if TNUM_PORT >= 2
/*
 *  SCIF受信割込みサービスルーチン
 *  
 */
void
sh2scif_isr2_in (void)
{
	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_in (get_siopcb (2));
	}
}

/*
 *  SCIF送信割込みサービスルーチン
 *  
 */
void
sh2scif_isr2_out (void)
{
	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_out (get_siopcb (2));
	}
}

/*
 *  SCIF受信エラー割込みサービスルーチン
 */
void
sh2scif_isr2_error (void)
{
	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_err (get_siopcb (2));
	}
}

/* ブレーク検出 */
void
sh2scif_isr2_brk (void)
{

	if (siopcb_table[1].openflag) {
		sh2scif_isr_siop_brk (get_siopcb (2));
	}
}
#endif /* of #if TNUM_PORT >= 2 */

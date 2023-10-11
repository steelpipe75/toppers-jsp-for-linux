/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2010 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: hw_serial.h,v 1.17 2007/03/23 07:22:15 honda Exp $
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

/*
 *  ターゲット依存シリアルI/Oモジュール（H8用）
 *    ・ポートが 1本の場合は HWPORT1_ADDRに指定されたポートを使用し、
 *      2本の場合は、HWPORT1_ADDRをユーザ用、HWPORT2_ADDRをコンソール
 *      出力として使用する。
 *      HWPORTx_ADDRは ターゲット依存の sys_config.h中で指定する。
 *    ・共通部のモジュールによって、XON/XOFFフロー制御が行わ
 *      れているので、信号線はTxDとRxDの2本でよい
 */

#include <s_services.h>

#ifndef _MACRO_ONLY

/*
 *  シリアルポートの初期化ブロック
 */

typedef struct sio_port_initialization_block {
	UW	base;		/* SCI のベースアドレス	*/
	UW	baudrate;	/* ボーレート		*/	
	IRC	irc;		/* 割込みレベル設定情報 */
	UB	smr_init;	/* SMR の設定値		*/
} SIOPINIB;

/*
 *  シリアルポートの制御ブロック
 */

typedef struct sio_port_control_block {
	const SIOPINIB	*inib;		/* 初期化ブロック	*/
	VP_INT		exinf;		/* 拡張情報		*/
	BOOL		openflag;	/* オープン済みフラグ	*/
} SIOPCB;

extern SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO ID から管理ブロックへの変換マクロ
 */

#define INDEX_SIO(sioid)	((UINT)((sioid) - 1))
#define get_siopcb(sioid)	(&(siopcb_table[INDEX_SIO(sioid)]))

/*
 *  コールバックルーチンの識別番号
 */

#define SIO_ERDY_SND		1u			/* 送信可能コールバック			*/
#define SIO_ERDY_RCV		2u			/* 受信通知コールバック			*/

/*
 *  SCI 関数の参照
 */

extern void	SCI_initialize (ID sioid);		/* SCI の初期化				*/
extern void	SCI_cls_por(UW base);			/* SCI のクローズ			*/
extern void	SCI_in_handler(ID sioid);		/* SCI 入力割り込みハンドラ		*/
extern void	SCI_out_handler(ID sioid);		/* SCI 出力割り込みハンドラ		*/
extern void	SCI_err_handler(ID sioid);		/* SCI 入力エラー割り込みハンドラ		*/
extern void	SCI_ierdy_snd(VP_INT exinf);		/* シリアル I/O からの送信可能コールバック	*/
extern void	SCI_ierdy_rcv(VP_INT exinf);		/* シリアル I/O からの受信通知コールバック	*/

/*
 *  SCI レベルの関数
 */

/*
 *  SCI のオープン
 */

Inline SIOPCB *
SCI_opn_por (ID sioid)
{
	SCI_initialize(sioid);
	return get_siopcb(sioid);
}

/*
 *  SCI_putchar -- 送信する文字の書き込み
 */

Inline void
SCI_putchar(SIOPCB *p, UB c)
{
	UW addr = p->inib->base + H8SSR;

	sil_wrb_mem((VP)(p->inib->base + H8TDR), c);
	bitclr((UB *)addr, H8SSR_TDRE_BIT);
}

/*
 *  SCI_wait_putchar -- 直接出力 (待ちあり)
 */

Inline void
SCI_wait_putchar (int base, char c)
{
	UW addr = base + H8SSR;

	/* TDRE が 1 になるまで待つ */
	while ((sil_reb_mem((VP)addr) & H8SSR_TDRE) == 0)
		;
	sil_wrb_mem((VP)(base + H8TDR), c);
	bitclr((UB *)addr, H8SSR_TDRE_BIT);
}

/*
 *  SCI_getchar -- 受信した文字の読み出し
 */

Inline INT
SCI_getchar(SIOPCB *p)
{
	INT	ch;
	UW	addr = p->inib->base + H8SSR;

	ch = (INT)(UB)sil_reb_mem((VP)(p->inib->base + H8RDR));
	/*  UB型へのキャストは、符号拡張を防ぐため  */

	bitclr((UB *)addr, H8SSR_RDRF_BIT);
	return ch;
}

/*
 *  SCI_putready -- 送信可能か
 */

Inline BOOL
SCI_putready(SIOPCB *pcb)
{
	UB ssr = sil_reb_mem((VP)(pcb->inib->base + H8SSR));
	return ((ssr & H8SSR_TDRE) != 0);
}

/*
 *  SCI_getready -- 受信可能か
 */

Inline BOOL
SCI_getready(SIOPCB *pcb)
{
#ifndef HEW_SIMULATOR
	UB ssr = sil_reb_mem((VP)(pcb->inib->base + H8SSR));
	return ((ssr & H8SSR_RDRF) != 0);
#else /* HEW_SIMULATOR */
	return TRUE;
#endif /* HEW_SIMULATOR */
}

/*
 *  送信割り込み制御関数
 */

Inline void
SCI_enable_send(SIOPCB *p)
{
	UW addr = p->inib->base + H8SCR;
	
	bitset((UB *)addr, H8SCR_TIE_BIT);
}

Inline void
SCI_disable_send(SIOPCB *p)
{
	UW addr = p->inib->base + H8SCR;

	bitclr((UB *)addr, H8SCR_TIE_BIT);
}

/*
 *  受信割り込み制御関数
 */

Inline void
SCI_enable_recv(SIOPCB *p)
{
	UW addr = p->inib->base + H8SCR;

	bitset((UB *)addr, H8SCR_RIE_BIT);
}

Inline void
SCI_disable_recv(SIOPCB *p)
{
	UW addr = p->inib->base + H8SCR;

	bitclr((UB *)addr, H8SCR_RIE_BIT);
}

/*
 *  SIO 関数の参照
 */

extern void	sio_initialize(void);			/* SCI の初期化				*/
extern void	sio_ena_cbr(SIOPCB *pcb, UINT cbrtn);	/* シリアル I/O からのコールバック許可	*/
extern void	sio_dis_cbr(SIOPCB *pcb, UINT cbrtn);	/* シリアル I/O からのコールバック禁止	*/

/*
 *  関数シミュレーションマクロ
 */
												/* SCI からの文字受信			*/
#ifdef HEW_SIMULATOR
extern BOOL hew_io_sim_snd_chr(char c);
#define sio_snd_chr(siopcb, c) hew_io_sim_snd_chr(c)

#else	/* HEW_SIMULATOR */
#define sio_snd_chr(p,c)	SCI_snd_chr(p,c)
#endif	/* HEW_SIMULATOR */
												/* SCI からの文字受信			*/
#ifdef HEW_SIMULATOR
extern INT hew_io_sim_rcv_chr(void);
#define sio_rcv_chr(siopcb) hew_io_sim_rcv_chr( )

#else	/* HEW_SIMULATOR */
#define sio_rcv_chr(p)		SCI_rcv_chr(p)
#endif	/* HEW_SIMULATOR */

#define sio_ierdy_snd(e)	SCI_ierdy_snd(e)	/* シリアル I/O からの送信可能コールバック	*/
#define sio_ierdy_rcv(e)	SCI_ierdy_rcv(e)	/* シリアル I/O からの受信通知コールバック	*/

/*
 *  SIO レベルの関数
 */

/*
 *  sio_opn_por -- ポートのオープン
 */

Inline SIOPCB *
sio_opn_por(ID sioid, VP_INT exinf)
{
	SIOPCB	*pcb;

	pcb = SCI_opn_por(sioid);
	pcb->exinf    = exinf;
	pcb->openflag = TRUE;
	return pcb;
}

/*
 *  sio_cls_por -- ポートのクローズ
 */

Inline void
sio_cls_por(SIOPCB *pcb)
{
	SCI_cls_por(pcb->inib->base);
	pcb->openflag = FALSE;
}

/*
 *  sio_snd_chr -- 文字送信
 */

#ifndef HEW_SIMULATOR
Inline BOOL
sio_snd_chr(SIOPCB *pcb, INT chr)
{
	if (SCI_putready(pcb)) {
		SCI_putchar(pcb, (UB)chr);
		return TRUE;
	} else {
		return FALSE;
	}
}
#endif	/* HEW_SIMULATOR */

/*
 *  sio_rcv_chr -- 文字受信
 */

#ifndef HEW_SIMULATOR
Inline INT
sio_rcv_chr(SIOPCB *pcb)
{
	if (SCI_getready(pcb)) {
		return SCI_getchar(pcb);
	} else {
		return -1;
	}
}
#endif	/* HEW_SIMULATOR */

#endif	/* of #ifndef _MACRO_ONLY */

#endif /* _HW_SERIAL_H_ */

/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2007 by Kurusugawa-Electronics Technology Inc
 *  Copyright (C) 2008 by Takahisa Yokota
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
 *  @(#) $Id: cpu_defs.h,v 1.13 2005/11/12 14:58:24 hiro Exp $
 */

/*
 *	プロセッサに依存する定義（COLDFIRE用）
 *
 *  このインクルードファイルは，kernel.h と sil.h でインクルードされる．
 *  他のファイルから直接インクルードすることはない．このファイルをイン
 *  クルードする前に，t_stddef.h と itron.h がインクルードされるので，
 *  それらに依存してもよい．
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

/*
 *  ユーザー定義情報
 */
#include <user_config.h>	/*  SUPPORT_VXGET_TIMマクロの定義  */

/* カーネル起動時のメッセージ   */
#define COPYRIGHT_CPU \
"Copyright (C) 2007 by Kurusugawa-Electronics Industory Inc\n" \
"Copyright (C) 2008 by Takahisa Yokota\n" \
"   \n\n"

#define CFV2		/* プロセッサ略称 */

#ifndef _MACRO_ONLY

/*
 *  割込み／CPU例外ハンドラ番号の型
 */
typedef	UINT	INHNO;		/* 割込みハンドラ番号 */
typedef	UINT	EXCNO;		/* CPU例外ハンドラ番号 */

/*
 *  割込みマスクの型と割込みマスクの変更／参照
 */
typedef	UINT	IPM;		/* 割込みマスク */

extern ER	chg_ipm(IPM ipm) throw();
extern ER	get_ipm(IPM *p_ipm) throw();
/*
 *  SIL関連の定義
 */


/*
 *  現在の割込みマスクの読出し
 */
#define _current_intmask_	current_intmask

/*
 *  割込みマスクの設定
 */
#define _set_intmask_		set_intmask

/*
 *  NMIを除くすべての割込みを禁止
 *  　disint()がカーネルが管理する割込みのみを禁止するのに対して
 *  　_disint_()はカーネル管理外の割込みも含めて禁止する。
 *  　具体的にはGDB stubのシリアル受信割込みの扱いが異なる。
 */
Inline void
_disint_()
{
	UW sr;

	Asm("move.w  %%sr, %0" : "=d"(sr));
	sr |= 0x0700;
	Asm("move.w %0, %%sr" : : "d"(sr) );
}


/*
 *  割込みロック状態の制御
 */
#define	SIL_PRE_LOC	UW _intmask_ = _current_intmask_()
#define	SIL_LOC_INT()	_disint_()
#define	SIL_UNL_INT()	_set_intmask_(_intmask_)

/*
 *  微少時間待ち
 */
Inline void
sil_dly_nse(UINT dlytim)
{
	register VW d0 asm("d0") = (VW) dlytim;
	Asm("jsr _sil_dly_nse" : "=g"(d0) : "0"(d0));
}

#endif /* _MACRO_ONLY */

/*
 *  プロセッサのエンディアン
 */
#define	SIL_ENDIAN	SIL_ENDIAN_BIG	/* ビッグエンディアン */

#ifndef _MACRO_ONLY
/*
 *  性能評価用システム時刻の参照
 */

#ifdef SUPPORT_VXGET_TIM
typedef	UD	SYSUTIM;	/* 性能評価用システム時刻 */

extern ER	vxget_tim(SYSUTIM *p_sysutim) throw();

#endif /*  SUPPORT_VXGET_TIM  */

#endif /* _MACRO_ONLY */

#endif /* _CPU_DEFS_H_ */

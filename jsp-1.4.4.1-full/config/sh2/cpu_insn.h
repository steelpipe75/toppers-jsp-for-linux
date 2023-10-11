/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2010 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002-2004 by Hokkaido Industrial Research Institute, JAPAN
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
 *  @(#) $Id: cpu_insn.h,v 1.5 2005/07/06 00:45:07 honda Exp $
 */

/*
 *	プロセッサの特殊命令のインライン関数定義（SH1/2用）
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/*
 *  ステータスレジスタ（SR）の現在値の読出し
 */
Inline UW
current_sr(void)
{
	UW sr;
	Asm("stc  sr,%0" : "=r"(sr));
	return(sr);
}

/*
 *  ステータスレジスタ（SR）の現在値の変更
 */
Inline void
set_sr(UW sr)
{
	Asm("ldc %0, sr" : : "r"(sr) : "memory", "t");
}

/*
 *  NMIを除くすべての割込みを禁止
 *  　（カーネルが管理する割込みのみ禁止）
 */
Inline void
disint(void)
{
    set_sr((current_sr() & ~0x000000f0u) |  (MAX_IPM << 4) );
}

/*
 *  すべての割込みを許可
 */
Inline void
enaint()
{
	set_sr(current_sr() & ~0x000000f0u);
}

/*
 *  ベクタベースレジスタ（VBR）の現在値の読出し
 */
Inline VP
current_vbr()
{
	VP	vbr;

	Asm("stc vbr,%0" : "=r"(vbr));
	return(vbr);
}

/*
 *  ベクタベースレジスタ（VBR）の設定
 */
Inline void
set_vbr(VP vbr)
{
	Asm("ldc  %0, vbr" : : "r"(vbr) );
}

/*
 *  レディキューサーチのためのビットマップサーチ関数
 *
 *　　機種非依存部で用意する関数を利用するので
 *　　CPU_BITMAP_SEARCHマクロは定義しない
 */

#endif /* _CPU_INSN_H_ */

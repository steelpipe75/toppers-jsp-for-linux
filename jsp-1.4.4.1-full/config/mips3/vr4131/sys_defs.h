/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 */

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

/*
 *  プロセッサタイプ
 */
#define VR4131

/*
 *  起動メッセージのターゲットボード名
 */
#define	TARGET_NAME	"KZ-VR4131PCI-01"

/*
 *  INTNO型と割込みの禁止/許可
 */
#ifndef _MACRO_ONLY

typedef	UINT	INTNO;			/* 割込み番号（icu_set_ilvで利用） */

#if 0		/*  MIPS3版ではサポートしていない  */
extern ER	dis_int(INTNO intno) throw();
extern ER	ena_int(INTNO intno) throw();
#endif

#endif /* _MACRO_ONLY */

/*
 *  タイムティックの定義
 */
#define	TIC_NUME	1u		/* タイムティックの周期の分子 */
#define	TIC_DENO	1u		/* タイムティックの周期の分母 */

/*
 *  ターゲットシステム依存のサービスコール
 */
#ifndef _MACRO_ONLY

typedef	UD 	SYSUTIM;		/* 性能評価用システム時刻 */
extern	ER	vxget_tim(SYSUTIM *pk_sysutim) throw();

#endif /* _MACRO_ONLY */

/*
 *  プロセッサのエンディアン
 */
#define	SIL_ENDIAN	SIL_ENDIAN_LITTLE	/* リトルエンディアン */

#ifndef _MACRO_ONLY

/*
 *  割込みコントローラの割込みマスクの型定義
 */
typedef struct{
	UH	msysint1;	/*  システム割込みマスクレジスタ1  */
	UH	msysint2;	/*  システム割込みマスクレジスタ2  */
} ICU_IPM;

/*
 *  システムの停止処理
 */
Inline void
kernel_abort()
{
	Asm("break");
}

#endif /* _MACRO_ONLY */

#endif /* _SYS_DEFS_H_ */

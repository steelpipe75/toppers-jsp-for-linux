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

#include "jsp_kernel.h"
#include <hw_serial.h>		/* シリアルコントローラ関係 */

/*  割込みコントローラに用いる割込みマスクの擬似テーブル  */
ICU_IPM icu_intmask_table[ TMAX_ALL_INTNO ];

/*
 *  ターゲットシステム依存 初期化ルーチン
 */
void sys_initialize() {

	ICU_IPM icu_ipm0 = {INIT_INT0M, INIT_INT1M};

	/*
	 *  外部割込みコントローラの割込みマスクの初期化
	 */
	icu_set_ipm( &icu_ipm0 );

	/*
	 *  バナー表示用シリアルポートの初期化
	 */
	sio_init();
}

/*
 *  ターゲットシステムの終了ルーチン
 */
void sys_exit(void) {

#ifndef GDB_STUB
	while (1);
#else	/*  GDB_STUB  */
	vr5500_exit();
#endif	/*  GDB_STUB  */

}

/*
 *  GDB STUB / 直接呼出し コンソール呼出しルーチン
 */

/*
 *  gdb stub によるコンソール出力
 */
/* a0($4) = 0xfe00, a1($5) = 出力したいキャラクタ を代入して、
   SYSCALL 例外を発生させる。 */

/* この関数を呼び出す時には、ステータスレジスタのEXLビット = 0 で呼び出すこと。
   なお、現在、カーネルでは、バナー表示時、シリアル出力時に呼出を行っている。*/
Inline void stub_putc(int c) {

	Asm("	move	$5, %0;		\
	     	li	$4, 0xfe00;	\
		syscall;		\
		nop"
		:: "r"(c)
		: "$4","$5" );
}

#ifdef GDB_STUB
#define vr5500_putc(c) stub_putc( c )
#else  /* GDB_STUB */
#define	vr5500_putc(c) sio_snd_chr_pol( c )
#endif /* GDB_STUB */

/*
 *   システム文字出力先の指定
 */
void
sys_putc(char c)
{
	if (c == '\n') {
		vr5500_putc('\r');
	}
	vr5500_putc(c);
}


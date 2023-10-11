/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: sys_defs.h,v 1.5 2004/02/05 09:16:25 honda Exp $
 */


/*
 *  システムに依存する定義（MIREF）
 *
 *  このインクルードファイルは，kernel.h と sil.h でインクルードされる．
 *  他のファイルから直接インクルードすることはない．このファイルをイン
 *  クルードする前に，t_stddef.h と itron.h がインクルードされるので，
 *  それらに依存してもよい．
 */


#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

#define MB_TEMPLATE_SYSTEM



/*
 *  起動メッセージのターゲット名
 */
#define	TARGET_NAME	"MIREF(Microblaze)"

/*
 *  コンフィギュレーション依存の定義
 */
/*
 *  JSPカーネル動作時のメモリマップ
 *  BRAM
 *  0x00000000 - 0x000003ff    STUBが使用
 *  0x00000400 - 0000000fff    タスク独立部用スタック
 *  SRAM
 *  0x00800000 - 0x0081ffff コード領域(128KB)
 *  0x00820000 - 0x0083ffff データ領域(128KB)
 *
 */

/*
 *   スタック領域の定義
 */                 
#define STACKTOP    0x1000    /* タスク独立部用スタックの初期値 */


/*
 *  タイマ値の内部表現とミリ秒単位との変換
 */
#define TIMER_CLOCK		25000

/*
 *  タイムティックの定義
 */
#define	TIC_NUME	1		/* タイムティックの周期の分子 */
#define	TIC_DENO	1		/* タイムティックの周期の分母 */


/*
 *  INTC のベースアドレス
 */
#define INTC_BASE 0xFFFF2000

/*
 *  TIMER のベースアドレス
 */
#define TIMER_BASE 0xFFFF2300   

/*
 * カーネルで使用する UART のベースアドレス
 */
#define UART_BASE 0xFFFF2200

/*
 * YG0130のベースアドレス
 */
#define  YG0130_0_BASE_ADDR  0xffff8200    


/*
 *  TIM 割込みの割込み番号
 */
#define TIMINTLVL        5


/*
 * UART 割込みの割込み番号
 */
#define UARTINTLVL 2

/*
 *  YG0130の割込み番号
 */
#define  YG0130_0_INTLVL 4

#define INHNO_IF_ED YG0130_0_INTLVL


/*                                                                             
 *  シリアルポート番号に関する定義      
 */
#define TNUM_PORT   1   /* サポートするシリアルポートの数 */
#define TNUM_SIOP   1   /* サポートするシリアルI/Oポートの数 */

/*
 *  システムタスクに関する定義
 */
#define	LOGTASK_PORTID	1	/* システムログを出力するシリアルポート番号 */


/*
 *  微少時間待ちのための定義
 */
#define SIL_DLY_TIM1    420
#define SIL_DLY_TIM2    90


/*
 * 起動時のキャッシュの設定
 * キャッシュをONにしたい場合に定義する．
 */
#define D_CACHE_ENABLE
#define I_CACHE_ENABLE


#endif /* _SYS_DEFS_H_ */

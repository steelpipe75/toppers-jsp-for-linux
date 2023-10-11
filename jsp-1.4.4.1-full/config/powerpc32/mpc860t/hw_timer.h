/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
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
 * 
 *  @(#) $Id: hw_timer.h,v 1.2 2004/10/07 17:10:56 honda Exp $
 */

/*
 *	タイマドライバ（MPC860T用）
 *　　　　　MPC860T内蔵の周期割込みタイマPITを使用
 *
 *　　　　　割込みコントローラ依存はこのファイルに記述する
 *　　　　　タイマデバイス自体に依存する処理はpit.hに記述する
 *
 */

#ifndef _HW_TIMER_H_
#define _HW_TIMER_H_

#include <s_services.h>

#ifndef _MACRO_ONLY
#include <pit.h>
#endif /* _MACRO_ONLY */

/*  タイマ割込みハンドラのベクタ番号  */
#define	INHNO_TIMER	LEVEL_TO_INHNO(INTLVL_PIT)

/*  タイマ割込みのIPM  */
#define	IPM_PIT		LEVEL_TO_IPM(INTLVL_PIT)

/*  タイマ割込みの許可ビット  */
#define	ENABLE_PIT	LEVEL_TO_ENABLE_BIT(INTLVL_PIT)


#ifndef _MACRO_ONLY

/*
 *  タイマ割込み要求のクリア
 */
#define hw_timer_int_clear	pit_int_clear


/*
 *  タイマの起動処理
 *
 *  タイマを初期化し，周期的なタイマ割込み要求を発生させる．
 */
Inline void
hw_timer_initialize()
{
	/*
	 *  タイマデバイス自体の初期化
	 */
	pit_initialize();

	/*
	 *  システムインターフェースユニットSIUのIPM初期化
	 */
	mpc860_orh_mem(SIMASK, ENABLE_PIT);

	/*
	 *  カーネル内部のデータ初期化
	 */
	define_ipm(INHNO_TIMER, IPM_PIT);	/* IPMの設定　*/

	
	pit_int_clear();	/*  割込み要求をクリア  */
	pit_start();		/*  タイマスタート    	*/
}

/*
 *  タイマの停止処理
 *
 *  タイマの動作を停止させる．
 */
#define hw_timer_terminate		pit_terminate

/*
 *  タイマの現在値の読出し
 *　　　タイマの動作を一時的に停止し，タイマ値を読み出す．
 */
#define hw_timer_get_current		pit_get_current

/*
 *  タイマ割込み要求のチェック
 */
#define hw_timer_fetch_interrupt	pit_fetch_interrupt

#endif /* _MACRO_ONLY */
#endif /* _HW_TIMER_H_ */
/*  end of file  */

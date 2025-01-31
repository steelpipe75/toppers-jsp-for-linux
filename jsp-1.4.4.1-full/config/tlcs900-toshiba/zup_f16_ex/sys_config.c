/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2010 by Witz Corporation, JAPAN
 * 
 *  The above copyright holders grant permission gratis to use,
 *  duplicate, modify, or redistribute (hereafter called use) this
 *  software (including the one made by modifying this software),
 *  provided that the following four conditions (1) through (4) are
 *  satisfied.
 * 
 *  (1) When this software is used in the form of source code, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be retained in the source code without modification.
 * 
 *  (2) When this software is redistributed in the forms usable for the
 *      development of other software, such as in library form, the above
 *      copyright notice, this use conditions, and the disclaimer shown
 *      below must be shown without modification in the document provided
 *      with the redistributed software, such as the user manual.
 * 
 *  (3) When this software is redistributed in the forms unusable for the
 *      development of other software, such as the case when the software
 *      is embedded in a piece of equipment, either of the following two
 *      conditions must be satisfied:
 * 
 *    (a) The above copyright notice, this use conditions, and the
 *           disclaimer shown below must be shown without modification in
 *        the document provided with the redistributed software, such as
 *        the user manual.
 * 
 *    (b) How the software is to be redistributed must be reported to the
 *        TOPPERS Project according to the procedure described
 *        separately.
 * 
 *  (4) The above copyright holders and the TOPPERS Project are exempt
 *      from responsibility for any type of damage directly or indirectly
 *      caused from the use of this software and are indemnified by any
 *      users or end users of this software from any and all causes of
 *      action whatsoever.
 * 
 *  THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 *  THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 *  PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 *  TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 *  INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 * 
 *  上記著作権者は，以下の (1)～(4) の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改変・
 *  再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作権
 *      表示，この利用条件および下記の無保証規定が，そのままの形でソース
 *      コード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使用
 *      できる形で再配布する場合には，再配布に伴うドキュメント（利用者マ
 *      ニュアルなど）に，上記の著作権表示，この利用条件および下記の無保
 *      証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使用
 *      できない形で再配布する場合には，次のいずれかの条件を満たすこと．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著作
 *        権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに報
 *        告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損害
 *      からも，上記著作権者およびTOPPERSプロジェクトを免責すること．また，
 *      本ソフトウェアのユーザまたはエンドユーザからのいかなる理由に基づ
 *      く請求からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者およ
 *  びTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的に対す
 *  る適合性も含めて，いかなる保証も行わない．また，本ソフトウェアの利用
 *  により直接的または間接的に生じたいかなる損害に関しても，その責任を負
 *  わない．
 * 
 *  @(#) $Id: sys_config.c,v 1.1 2006/04/10 08:19:25 honda Exp $
 */

/*
 *	ターゲットシステム依存モジュール（Zup-F16拡張ボード用）
 */


#include "jsp_kernel.h"
#include <sil.h>
#include <tmp91cy22.h>
#include "hw_serial.h"


/* システムログ送信中フラグ */
BOOL	log_io_busy;

/*
 *  ターゲットシステム依存 初期化ルーチン
 */

void
sys_initialize()
{
	/*
	 *  バナー表示用シリアルポートの初期化
	 *
	 *  送信バッファ空フラグが無く，ポーリングによる送信処理の実装が
	 *  できないため，送信完了割込み要求フラグをポーリングし，初回送信
	 *  用にシステムログ送信中フラグを用いる．
	 */
	/* システムログ送信中フラグ初期化 */
	log_io_busy = FALSE;

	/* シリアルI/Oドライバ初期化	*/
	/* 受信停止	*/
	sil_wrb_mem((VP)(TADR_SFR_SC1MOD0), 0x00 );
	/* ポート設定(TXD1)として使用	*/
	sil_wrb_mem((VP)(TADR_SFR_P9FC), 0x08 );
	sil_wrb_mem((VP)(TADR_SFR_P9CR), 0x08 );
	/* 動作モード設定	*/
	sil_wrb_mem((VP)(TADR_SFR_SC1MOD0), (VB)(TBIT_SIOSMU8 | TBIT_SIOSCBRG) );
							/* 8bitUARTモード,ボーレートジェネレータ使用	*/
	sil_reb_mem((VP)(TADR_SFR_SC1CR));	/* 読出しによりエラーフラグクリア	*/
	sil_wrb_mem((VP)(TADR_SFR_SC1CR), 0x00 );	/* パリティ無し	*/
	sil_wrb_mem((VP)(TADR_SFR_BR1CR), (VB)BRCR_19200);
							/* φT2使用,19200bps,補正機能未使用	*/
	sil_wrb_mem((VP)(TADR_SFR_BR1ADD), BRADD_19200);
	sil_wrb_mem((VP)(TADR_SFR_SC1MOD1), TBIT_SIOI2S);

	/* シリアル割込み要求フラグクリア	 */
	sil_wrb_mem((VP)(TADR_SFR_INTCLR), TBIT_TX1_CLR );	/* 送信要求クリア	*/

	/* LED初期化	*/
	sil_wrb_mem((VP)(TADR_SFR_PA), 0xff );
	sil_wrb_mem((VP)(TADR_SFR_PAFC), 0x00 );
	sil_wrb_mem((VP)(TADR_SFR_PACR), 0xff );

}

/*
 *  ターゲットシステムの終了ルーチン
 */

void
sys_exit(void)
{
  while(1);
}

/*
 *  システムログ用文字送信関数
 *
 *  本関数はCPUロック状態(割込み禁止)で実行すること
 */
void
sys_putc(char c)
{
	/* 改行コードの場合先に'\r'を送る	*/
	if(c == '\n'){
		if( log_io_busy == TRUE ){
			/* 既に送信中の場合は割込み要求フラグをポーリング	*/
			while( (sil_reb_mem((VP)(TADR_SFR_INTES1)) & TBIT_INTC_H) == 0 );
			sil_wrb_mem((VP)TADR_SFR_INTCLR, (TBIT_TX1_CLR) );	/* 送信要求クリア	*/
			sil_wrb_mem((VP)(TADR_SFR_SC1BUF), '\r');
		}
		else{
			/* 送信状態にして文字を送信	*/
			log_io_busy = TRUE;
			sil_wrb_mem((VP)(TADR_SFR_SC1BUF), '\r');
		}
	}
	if( log_io_busy == TRUE ){
		/* 既に送信中の場合は割込み要求フラグをポーリング	*/
		while( (sil_reb_mem((VP)(TADR_SFR_INTES1)) & TBIT_INTC_H) == 0 );
		sil_wrb_mem((VP)TADR_SFR_INTCLR, (TBIT_TX1_CLR) );	/* 送信要求クリア	*/
		sil_wrb_mem((VP)(TADR_SFR_SC1BUF), c);
	}
	else{
		/* 送信状態にして文字を送信	*/
		log_io_busy = TRUE;
		sil_wrb_mem((VP)(TADR_SFR_SC1BUF), c);
	}
}




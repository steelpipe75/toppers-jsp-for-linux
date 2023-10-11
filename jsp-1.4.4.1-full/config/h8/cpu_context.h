/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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
 *  @(#) $Id: cpu_context.h,v 1.16 2007/03/23 07:22:15 honda Exp $
 */

#ifndef _CPU_CONTEXT_H_
#define _CPU_CONTEXT_H_

/*
 *  タスクコンテキスト操作ルーチン
 *
 *  このファイルを cpu_conf.h と分離しているのは，このファイルはTCBが
 *  定義された後に読む必要があるのに対して，cpu_conf.h にはTCBを定義す
 *  る前に読む必要がある定義を含んでいるためである．
 */

#include "task.h"

/*
 *  タスクコンテキストブロックの初期化
 *
 *  タスクが休止状態に移行する時（タスクの生成時，タスクの終了時）に呼
 *  ばれる．基本的には，タスクコンテキストブロックをタスクが起動できる
 *  状態に設定する処理を，create_context と activate_context で行えば
 *  よい．多くの処理はどちらの関数で行ってもよい．
 */
Inline void
create_context(TCB *tcb)
{
}

/*
 *  タスクの起動準備
 *
 *  タスクが休止状態から実行できる状態に移行する時に呼ばれる．
 *
 *  スタック上には何も積まない
 *  activate_rではruntskから必要な情報を取り出せるので、
 *  スタックに積む必要はない（効率が悪い）
 *  
 */

extern void	activate_r(void);

Inline void
activate_context(TCB *tcb)
{
	VW	*sp;

	sp = (VW *)(((VB *) tcb->tinib->stk) + tcb->tinib->stksz);
	tcb->tskctxb.sp = sp;
	tcb->tskctxb.pc = activate_r;
}


/*
 *  ext_tsk がスタック上に確保するダミー領域のサイズ
 *  
 *  　H8依存部では、create_context(),activate_context()ともにタスク
 *　　スタックの底を書き換えないので,ACTIVATED_STACK_SIZEの定義は
 *　　必要ない。
 */

/*
 *  calltex は使用しない
 */
#define OMIT_CALLTEX

#endif /* _CPU_CONTEXT_H_ */

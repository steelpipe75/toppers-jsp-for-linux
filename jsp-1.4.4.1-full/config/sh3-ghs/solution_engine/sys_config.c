/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                     2003 by Advanced Data Controls, Corp
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
 *  @(#) $Id: sys_config.c,v 1.3 2003/12/19 11:24:55 honda Exp $
 */

/*
 * ターゲットシステム依存モジュール（Solution Engine用）
 */

#include "jsp_kernel.h"
#include <sil.h>
#include <solution_engine.h>
#include <fdc37c935a.h>

/*
 *  ターゲットシステム依存 初期化ルーチン
 */
void
sys_initialize()
{
#if defined(MS7709ASE01) || defined(MS7729RSE01)    
    /* Enable IRL Interrupt */
    sil_wrh_mem((VP)ICR1, 0x5000);
#else /* MS7750SE01 */
    sil_wrh_mem((VP)ICR, 0x0000);
#endif /* defined(MS7709ASE01) | defined(MS7729RSE01) */   
    /*
     * Init Super I/O
     */
    smsc_init();

    /*
     * Init SIO
     */
    fdc37c935a_init();
}


/*
 *  ターゲットシステムの終了ルーチン
 *
 *  システムを終了する時に使う．通常はモニタ呼び出しで実現する．
 *  
 */
void
sys_exit(void)
{
  kernel_abort();
}

/*
 *   システム文字出力先の指定
 */

#ifdef  MULTI_IO
#include <stdio.h>
#define SYS_PUT_CHAR(c) putchar(c)
#else
#define SYS_PUT_CHAR(c) fdc37c935a_pol_putc(c)
#endif 

void
sys_putc(char c)
{
    if (c == '\n') {
        SYS_PUT_CHAR('\r');
    }
    SYS_PUT_CHAR(c);
}




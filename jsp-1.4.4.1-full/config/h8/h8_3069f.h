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
 *  Copyright (C) 2001-2004 by Kunihiko Ohnaka
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
 *  @(#) $Id: h8_3069f.h,v 1.4 2007/03/23 07:22:15 honda Exp $
 */

#ifndef _H8_3069F_H_
#define _H8_3069F_H_

/*
 *  H8/3069F 用定義
 */

/* Interrupt numbers */

#define IRQ_NMI			7		/* NMI */

#define TRAP8			8

#define IRQ_EXT0		12		/* IRQ0 */
#define IRQ_EXT1		13		/* IRQ1 */
#define IRQ_EXT2		14		/* IRQ2 */
#define IRQ_EXT3		15		/* IRQ3 */
#define IRQ_EXT4		16		/* IRQ4 */
#define IRQ_EXT5		17		/* IRQ5 */

#define IRQ_WOVI		20		/* Watch Doc Timer */

#define IRQ_CMI			21		/* Compare Match */

#define IRQ_ADI			23		/* A/D */

#define IRQ_IMIA0		24		/* 16 bit timer 0 IMIA0 */
#define IRQ_IMIB0		25		/* 16 bit timer 0 IMIB0 */
#define IRQ_OVI0		26		/* 16 bit timer 0 OVI0  */

#define IRQ_IMIA1		28		/* 16 bit timer 1 IMIA1 */
#define IRQ_IMIB1		29		/* 16 bit timer 1 IMIB1 */
#define IRQ_OVI1		30		/* 16 bit timer 1 OVI1  */

#define IRQ_IMIA2		32		/* 16 bit timer 2 IMIA2 */
#define IRQ_IMIB2		33		/* 16 bit timer 2 IMIB2 */
#define IRQ_OVI2		34		/* 16 bit timer 2 OVI2  */

#define IRQ_CIMIA0		36		/* 8 bit timer 0 CIMIA0 */
#define IRQ_CIMIB0		37		/* 8 bit timer 0 CIMIB0 */
#define IRQ_CIMIA1		38		/* 8 bit timer 1 CIMIA1 */
#define IRQ_CIMIB1		38		/* 8 bit timer 1 CIMIB1 */
#define IRQ_TOVI0		39		/* 8 bit timer 0 TOVI0  */
#define IRQ_TOVI1		39		/* 8 bit timer 1 TOVI1  */

#define IRQ_CIMIA2		40		/* 8 bit timer 2 CIMIA2 */
#define IRQ_CIMIB2		41		/* 8 bit timer 2 CIMIB2 */
#define IRQ_CIMIA3		42		/* 8 bit timer 3 CIMIA3 */
#define IRQ_CIMIB3		42		/* 8 bit timer 3 CIMIB3 */
#define IRQ_TOVI2		43		/* 8 bit timer 2 TOVI2  */
#define IRQ_TOVI3		43		/* 8 bit timer 3 TOVI3  */

#define IRQ_DEND0A		44		/* DMAC */
#define IRQ_DEND0B		45		/* DMAC */
#define IRQ_DEND1A		46		/* DMAC */
#define IRQ_DEND1B		47		/* DMAC */

#define IRQ_ERI0		52		/* SCI0 ERI */
#define IRQ_RXI0		53		/* SCI0 RXI */
#define IRQ_TXI0		54		/* SCI0 TXI */
#define IRQ_TEI0		55		/* SCI0 TEI */

#define IRQ_ERI1		56		/* SCI1 ERI */
#define IRQ_RXI1		57		/* SCI1 RXI */
#define IRQ_TXI1		58		/* SCI1 TXI */
#define IRQ_TEI1		59		/* SCI1 TEI */

#define IRQ_ERI2		60		/* SCI2 ERI */
#define IRQ_RXI2		61		/* SCI2 RXI */
#define IRQ_TXI2		62		/* SCI2 TXI */
#define IRQ_TEI2		63		/* SCI2 TEI */

/* 
 * register address 
 *　　内部I/Oレジスタ(1) 0xfe,e000～0xfe,e0ff
 *　　内部I/Oレジスタ(2) 0xff,ff20～0xff,ffe9
 *　　　　マニュアルには下位20ビットしか記載されていないので
 *　　　　上位4ビット（0xf0,0000）を補う。
 */

/* I/O ports */

/* port1: A0  - A7  */

#define H8P1DDR			0xfee000
#define H8P1DR			0xffffd0

/* port2: A8  - A15 */

#define H8P2DDR			0xfee001
#define H8P2DR			0xffffd1
#define H8P2PCR			0xfee03c

/* port3: D8  - D15 */

#define H8P3DDR			0xfee002
#define H8P3DR			0xffffd2

/* port4: D0  - D7  */

#define H8P4DDR			0xfee003
#define H8P4DR			0xffffd3
#define H8P4PCR			0xfee03e

/* port5: A16 - A19 */

#define H8P5DDR			0xfee004
#define H8P5DR			0xffffd4
#define H8P5PCR			0xfee03f

#define H8P5DDR_A19_BIT		3
#define H8P5DDR_A18_BIT		2
#define H8P5DDR_A17_BIT		1
#define H8P5DDR_A16_BIT		0

#define H8P5DDR_A19		(1<<H8P5DDR_A19_BIT)
#define H8P5DDR_A18		(1<<H8P5DDR_A18_BIT)
#define H8P5DDR_A17		(1<<H8P5DDR_A17_BIT)
#define H8P5DDR_A16		(1<<H8P5DDR_A16_BIT)

/* port6 */

#define H8P6DDR			0xfee005
#define H8P6DR			0xffffd5

#define H8P6DDR_CLOCK_BIT	7
#define H8P6DDR_HWR_BIT		6
#define H8P6DDR_LWR_BIT		5
#define H8P6DDR_RD_BIT		4
#define H8P6DDR_AS_BIT		3
#define H8P6DDR_BACK_BIT	2
#define H8P6DDR_BREQ_BIT	1
#define H8P6DDR_WAIT_BIT	0

#define H8P6DDR_CLOCK		(1<<H8P6DDR_CLOCK_BIT)
#define H8P6DDR_HWR			(1<<H8P6DDR_HWR_BIT)
#define H8P6DDR_LWR			(1<<H8P6DDR_LWR_BIT)
#define H8P6DDR_RD			(1<<H8P6DDR_RD_BIT)
#define H8P6DDR_AS			(1<<H8P6DDR_AS_BIT)
#define H8P6DDR_BACK		(1<<H8P6DDR_BACK_BIT)
#define H8P6DDR_BREQ		(1<<H8P6DDR_BREQ_BIT)
#define H8P6DDR_WAIT		(1<<H8P6DDR_WAIT_BIT)

/* port7 */

#define H8P7DR			0xffffd6

/* port8 */

#define H8P8DDR			0xfee007
#define H8P8DR			0xffffd7

#define H8P8DDR_CS0_BIT		4
#define H8P8DDR_CS1_BIT		3
#define H8P8DDR_CS2_BIT		2
#define H8P8DDR_CS3_BIT		1
#define H8P8DDR_RFSH_BIT	0

#define H8P8DDR_CS0			(1<<H8P8DDR_CS0_BIT)
#define H8P8DDR_CS1			(1<<H8P8DDR_CS1_BIT)
#define H8P8DDR_CS2			(1<<H8P8DDR_CS2_BIT)
#define H8P8DDR_CS3			(1<<H8P8DDR_CS3_BIT)
#define H8P8DDR_RFSH		(1<<H8P8DDR_RFSH_BIT)

#define H8P8DDR_IRQ3_BIT	3
#define H8P8DDR_IRQ2_BIT	2
#define H8P8DDR_IRQ1_BIT	1
#define H8P8DDR_IRQ0_BIT	0

#define H8P8DDR_IRQ3		(1<<H8P8DDR_IRQ3_BIT)
#define H8P8DDR_IRQ2		(1<<H8P8DDR_IRQ2_BIT)
#define H8P8DDR_IRQ1		(1<<H8P8DDR_IRQ1_BIT)
#define H8P8DDR_IRQ0		(1<<H8P8DDR_IRQ0_BIT)

#define H8P8DDR_ADTRG_BIT	3

#define H8P8DDR_ADTRG		(1<<H8PBDDR_ADTRG_BIT)

/* port9 (SCI) */

#define H8P9DDR			0xfee008
#define H8P9DR			0xffffd8

#define H8P9DDR_SCK1_BIT	5
#define H8P9DDR_SCK0_BIT	4
#define H8P9DDR_RXD1_BIT	3
#define H8P9DDR_RXD0_BIT	2
#define H8P9DDR_TXD1_BIT	1
#define H8P9DDR_TXD0_BIT	0

#define H8P9DDR_SCK1		(1<<H8P9DDR_SCK1_BIT)
#define H8P9DDR_SCK0		(1<<H8P9DDR_SCK0_BIT)
#define H8P9DDR_RXD1		(1<<H8P9DDR_RXD1_BIT)
#define H8P9DDR_RXD0		(1<<H8P9DDR_RXD0_BIT)
#define H8P9DDR_TXD1		(1<<H8P9DDR_TXD1_BIT)
#define H8P9DDR_TXD0		(1<<H8P9DDR_TXD0_BIT)

#define H8P9DDR_IRQ5_BIT	5
#define H8P9DDR_IRQ4_BIT	4

#define H8P9DDR_IRQ5		(1<<H8P9DDR_IRQ5_BIT)
#define H8P9DDR_IRQ4		(1<<H8P9DDR_IRQ4_BIT)

/* portA (TPC/ITU/DMA) */

#define H8PADDR			0xfee009
#define H8PADR			0xffffd9

#define H8PADDR_TP7_BIT		7
#define H8PADDR_TP6_BIT		6
#define H8PADDR_TP5_BIT		5
#define H8PADDR_TP4_BIT		4
#define H8PADDR_TP3_BIT		3
#define H8PADDR_TP2_BIT		2
#define H8PADDR_TP1_BIT		1
#define H8PADDR_TP0_BIT		0

#define H8PADDR_TP7		(1<<H8PADDR_TP7_BIT)
#define H8PADDR_TP6		(1<<H8PADDR_TP6_BIT)
#define H8PADDR_TP5		(1<<H8PADDR_TP5_BIT)
#define H8PADDR_TP4		(1<<H8PADDR_TP4_BIT)
#define H8PADDR_TP3		(1<<H8PADDR_TP3_BIT)
#define H8PADDR_TP2		(1<<H8PADDR_TP2_BIT)
#define H8PADDR_TP1		(1<<H8PADDR_TP1_BIT)
#define H8PADDR_TP0		(1<<H8PADDR_TP0_BIT)

#define H8PADDR_TIOCB2_BIT	7
#define H8PADDR_TIOCA2_BIT	6
#define H8PADDR_TIOCB1_BIT	5
#define H8PADDR_TIOCA1_BIT	4
#define H8PADDR_TIOCB0_BIT	3
#define H8PADDR_TIOCA0_BIT	2

#define H8PADDR_TIOCB2		(1<<H8PADDR_TIOCB2_BIT)
#define H8PADDR_TIOCA2		(1<<H8PADDR_TIOCA2_BIT)
#define H8PADDR_TIOCB1		(1<<H8PADDR_TIOCB1_BIT)
#define H8PADDR_TIOCA1		(1<<H8PADDR_TIOCA1_BIT)
#define H8PADDR_TIOCB0		(1<<H8PADDR_TIOCB0_BIT)
#define H8PADDR_TIOCA0		(1<<H8PADDR_TIOCA0_BIT)

#define H8PADDR_TEND1_BIT	1
#define H8PADDR_TEND0_BIT	0

#define H8PADDR_TEND1		(1<<H8PADDR_TEND1_BIT)
#define H8PADDR_TEND0		(1<<H8PADDR_TEND0_BIT)

#define H8PADDR_A20_BIT		7
#define H8PADDR_A21_BIT		6
#define H8PADDR_A22_BIT		5
#define H8PADDR_A23_BIT		4

#define H8PADDR_A20		(1<<H8PADDR_A20_BIT)
#define H8PADDR_A21		(1<<H8PADDR_A21_BIT)
#define H8PADDR_A22		(1<<H8PADDR_A22_BIT)
#define H8PADDR_A23		(1<<H8PADDR_A23_BIT)

#define H8PADDR_TCLKD_BIT	3
#define H8PADDR_TCLKC_BIT	2
#define H8PADDR_TCLKB_BIT	1
#define H8PADDR_TCLKA_BIT	0

#define H8PADDR_TCLKD		(1<<H8PADDR_TCLKD_BIT)
#define H8PADDR_TCLKC		(1<<H8PADDR_TCLKC_BIT)
#define H8PADDR_TCLKB		(1<<H8PADDR_TCLKB_BIT)
#define H8PADDR_TCLKA		(1<<H8PADDR_TCLKA_BIT)

/* portB (TP/ITU/DMA/AD) */

#define H8PBDDR			0xfee00a
#define H8PBDR			0xffffda

#define H8PBDDR_TP15_BIT	7
#define H8PBDDR_TP14_BIT	6
#define H8PBDDR_TP13_BIT	5
#define H8PBDDR_TP12_BIT	4
#define H8PBDDR_TP11_BIT	3
#define H8PBDDR_TP10_BIT	2
#define H8PBDDR_TP9_BIT		1
#define H8PBDDR_TP8_BIT		0

#define H8PBDDR_TP15		(1<<H8PBDDR_TP15_BIT)
#define H8PBDDR_TP14		(1<<H8PBDDR_TP14_BIT)
#define H8PBDDR_TP13		(1<<H8PBDDR_TP13_BIT)
#define H8PBDDR_TP12		(1<<H8PBDDR_TP12_BIT)
#define H8PBDDR_TP11		(1<<H8PBDDR_TP11_BIT)
#define H8PBDDR_TP10		(1<<H8PBDDR_TP10_BIT)
#define H8PBDDR_TP9			(1<<H8PBDDR_TP9_BIT)
#define H8PBDDR_TP8			(1<<H8PBDDR_TP8_BIT)

#define H8PBDDR_LCAS_BIT	5
#define H8PBDDR_UCAS_BIT	4
#define H8PBDDR_DREQ1_BIT	3
#define H8PBDDR_DREQ0_BIT	1

#define H8PBDDR_LCAS		(1<<H8PBDDR_LCAS_BIT)
#define H8PBDDR_UCAS		(1<<H8PBDDR_UCAS_BIT)
#define H8PBDDR_DREQ1		(1<<H8PBDDR_DREQ1_BIT)
#define H8PBDDR_DREQ0		(1<<H8PBDDR_DREQ0_BIT)

#define H8PBDDR_TMIO3_BIT	3
#define H8PBDDR_TMIO2_BIT	2
#define H8PBDDR_TMIO1_BIT	1
#define H8PBDDR_TMIO0_BIT	0

#define H8PBDDR_TMIO4		(1<<H8PBDDR_TMIO3_BIT)
#define H8PBDDR_TMIO3		(1<<H8PBDDR_TMIO2_BIT)
#define H8PBDDR_TMIO2		(1<<H8PBDDR_TMIO1_BIT)
#define H8PBDDR_TMIO1		(1<<H8PBDDR_TMIO0_BIT)

#define H8PBDDR_RXD2_BIT	7
#define H8PBDDR_TXD2_BIT	6
#define H8PBDDR_SCK2_BIT	5

#define H8PBDDR_RXD2		(1<<H8PBDDR_RXD2_BIT)
#define H8PBDDR_TXD2		(1<<H8PBDDR_TXD2_BIT)
#define H8PBDDR_SCK2		(1<<H8PBDDR_SCK2_BIT)

#define H8PBDDR_CS4_BIT		3
#define H8PBDDR_CS5_BIT		2
#define H8PBDDR_CS6_BIT		1
#define H8PBDDR_CS7_BIT		0

#define H8PBDDR_CS4		(1<<H8PBDDR_CS4_BIT)
#define H8PBDDR_CS5		(1<<H8PBDDR_CS5_BIT)
#define H8PBDDR_CS6		(1<<H8PBDDR_CS6_BIT)
#define H8PBDDR_CS7		(1<<H8PBDDR_CS7_BIT)

/* Interrupt Contolller */

#define H8INTC			0xfee014  /* interrupt controller base address */
#define H8ISCR			0xfee014
#define H8IER			0xfee015
#define H8ISR			0xfee016
#define H8IPRA			0xfee018
#define H8IPRB			0xfee019

/* System Control Register */

#define H8SYSCR			0xfee012  /* SYSCR */

#define H8SYSCR_SSBY_BIT	7
#define H8SYSCR_STS2_BIT	6
#define H8SYSCR_STS1_BIT	5
#define H8SYSCR_STS0_BIT	4
#define H8SYSCR_UE_BIT		3
#define H8SYSCR_NMIEG_BIT	2
#define H8SYSCR_SSOE_BIT	1
#define H8SYSCR_RAME_BIT	0

#define H8SYSCR_SSBY		(1<<(H8SYSCR_SSBY_BIT))
#define H8SYSCR_STS2		(1<<(H8SYSCR_STS2_BIT))
#define H8SYSCR_STS1		(1<<(H8SYSCR_STS1_BIT))
#define H8SYSCR_STS0		(1<<(H8SYSCR_STS0_BIT))
#define H8SYSCR_UE			(1<<(H8SYSCR_UE_BIT))
#define H8SYSCR_NMIEG		(1<<(H8SYSCR_NMIEG_BIT))
#define H8SYSCR_SSOE		(1<<(H8SYSCR_SSOE_BIT))
#define H8SYSCR_RAME		(1<<(H8SYSCR_RAME_BIT))

/* Interrupt Enable Register */

#define H8IER_IRQ5E_BIT		5	/* IRQ5			*/
#define H8IER_IRQ4E_BIT		4	/* IRQ4			*/
#define H8IER_IRQ3E_BIT		3	/* IRQ3			*/
#define H8IER_IRQ2E_BIT		2	/* IRQ2			*/
#define H8IER_IRQ1E_BIT		1	/* IRQ1			*/
#define H8IER_IRQ0E_BIT		0	/* IRQ0			*/

#define H8IER_IRQ5E			(1<<(H8IER_IRQ5E_BIT))
#define H8IER_IRQ4E			(1<<(H8IER_IRQ4E_BIT))
#define H8IER_IRQ3E			(1<<(H8IER_IRQ3E_BIT))
#define H8IER_IRQ2E			(1<<(H8IER_IRQ2E_BIT))
#define H8IER_IRQ1E			(1<<(H8IER_IRQ1E_BIT))
#define H8IER_IRQ0E			(1<<(H8IER_IRQ0E_BIT))

/*  IRQ Sense Control Register  */
#define H8ISCR_IRQ0SC	0x01
#define H8ISCR_IRQ1SC	0x02
#define H8ISCR_IRQ2SC	0x04
#define H8ISCR_IRQ3SC	0x08
#define H8ISCR_IRQ4SC	0x10
#define H8ISCR_IRQ5SC	0x20

/*  IRQ Status Register  */
#define H8ISR_IRQ0F		0x01
#define H8ISR_IRQ1F		0x02
#define H8ISR_IRQ2F		0x04
#define H8ISR_IRQ3F		0x08
#define H8ISR_IRQ4F		0x10
#define H8ISR_IRQ5F		0x20


/* Interrupt Priority Register A */

#define H8IPR_IRQ0_BIT		7	/* IRQ0			*/
#define H8IPR_IRQ1_BIT		6	/* IRQ1			*/
#define H8IPR_IRQ2_BIT		5	/* IRQ2			*/
#define H8IPR_IRQ3_BIT		5	/* IRQ3			*/
#define H8IPR_IRQ4_BIT		4	/* IRQ4			*/
#define H8IPR_IRQ5_BIT		4	/* IRQ5			*/
#define H8IPR_WDT_BIT		3	/* WDT			*/
#define H8IPR_AD_BIT		3	/* A/D			*/
#define H8IPR_CMI_BIT		3	/* CMI			*/
#define H8IPR_ITU0_BIT		2	/* 16 bit timer 0	*/
#define H8IPR_ITU1_BIT		1	/* 16 bit timer 1	*/
#define H8IPR_ITU2_BIT		0	/* 16 bit timer 2	*/

#define H8IPR_IRQ0		(1<<(H8IPR_IRQ0_BIT))
#define H8IPR_IRQ1		(1<<(H8IPR_IRQ1_BIT))
#define H8IPR_IRQ2		(1<<(H8IPR_IRQ2_BIT))
#define H8IPR_IRQ3		(1<<(H8IPR_IRQ3_BIT))
#define H8IPR_IRQ4		(1<<(H8IPR_IRQ4_BIT))
#define H8IPR_IRQ5		(1<<(H8IPR_IRQ5_BIT))
#define H8IPR_WDT		(1<<(H8IPR_WDT_BIT))
#define H8IPR_AD		(1<<(H8IPR_AD_BIT))
#define H8IPR_CMI		(1<<(H8IPR_CMI_BIT))
#define H8IPR_ITU0		(1<<(H8IPR_ITU0_BIT))
#define H8IPR_ITU1		(1<<(H8IPR_ITU1_BIT))
#define H8IPR_ITU2		(1<<(H8IPR_ITU2_BIT))

/* Interrupt Priority Register B */

#define H8IPR_TU80_BIT		7	/* 8 bit timer 0	*/
#define H8IPR_TU81_BIT		6	/* 8 bit timer 1	*/
#define H8IPR_DMAC_BIT		5	/* DMAC (CH0,1)		*/
#define H8IPR_SCI0_BIT		3	/* SCI0			*/
#define H8IPR_SCI1_BIT		2	/* SCI1			*/
#define H8IPR_SCI2_BIT		1	/* SCI2			*/

#define H8IPR_TU80		(1<<(H8IPR_TU80_BIT))
#define H8IPR_TU81		(1<<(H8IPR_TU81_BIT))
#define H8IPR_DMAC		(1<<(H8IPR_DMAC_BIT))
#define H8IPR_SCI0		(1<<(H8IPR_SCI0_BIT))
#define H8IPR_SCI1		(1<<(H8IPR_SCI1_BIT))
#define H8IPR_SCI2		(1<<(H8IPR_SCI2_BIT))

/* 16 bit Timer */

#define H816TU			0xffff60	/* base address */
#define H816TU_TSTR		0xffff60
#define H816TU_TSNC		0xffff61
#define H816TU_TMDR		0xffff62
#define H816TU_TOLR		0xffff63
#define H816TU_TISRA	0xffff64
#define H816TU_TISRB	0xffff65
#define H816TU_TISRC	0xffff66

#define H816TU0			0xffff68	/* base address */
#define H816TU1			0xffff70	/* base address */
#define H816TU2			0xffff78	/* base address */

/* address offset */

#define H8TCR			0
#define H8TIOR			1
#define H8TCNT			2
#define H8TCNTH			2
#define H8TCNTL			3
#define H8GRA			4
#define H8GRAH			4
#define H8GRAL			5
#define H8GRB			6
#define H8GRBH			6
#define H8GRBL			7

/* Timer Start Register (TSTR) */

#define H8TSTR_STR2_BIT		2
#define H8TSTR_STR1_BIT		1
#define H8TSTR_STR0_BIT		0

#define H8TSTR_STR2		(1<<H8TSTR_STR2_BIT)
#define H8TSTR_STR1		(1<<H8TSTR_STR1_BIT)
#define H8TSTR_STR0		(1<<H8TSTR_STR0_BIT)

/* Timer Synchronous Register (TSNC) */

#define H8TSNC_SYNC2_BIT	2
#define H8TSNC_SYNC1_BIT	1
#define H8TSNC_SYNC0_BIT	0

#define H8TSNC_SYNC2		(1<<H8TSNC_SYNC2_BIT)
#define H8TSNC_SYNC1		(1<<H8TSNC_SYNC1_BIT)
#define H8TSNC_SYNC0		(1<<H8TSNC_SYNC0_BIT)

/* Timer Mode Register (TMDR) */

#define H8TMDR_MDF_BIT		6
#define H8TMDR_FDIR_BIT		5
#define H8TMDR_PWM2_BIT		2
#define H8TMDR_PWM1_BIT		1
#define H8TMDR_PWM0_BIT		0

#define H8TMDR_MDF		(1<<H8TMDR_MDF_BIT)
#define H8TMDR_FDIR		(1<<H8TMDR_FDIR_BIT)
#define H8TMDR_PWM2		(1<<H8TMDR_PWM2_BIT)
#define H8TMDR_PWM1		(1<<H8TMDR_PWM1_BIT)
#define H8TMDR_PWM0		(1<<H8TMDR_PWM0_BIT)

/* Timer Interrupt Status Register A (TISRA) */

#define H8TISRA_IMIEA2_BIT	6
#define H8TISRA_IMIEA1_BIT	5
#define H8TISRA_IMIEA0_BIT	4
#define H8TISRA_IMFA2_BIT	2
#define H8TISRA_IMFA1_BIT	1
#define H8TISRA_IMFA0_BIT	0

#define H8TISRA_IMIEA2		(1<<H8TISRA_IMIEA2_BIT)
#define H8TISRA_IMIEA1		(1<<H8TISRA_IMIEA1_BIT)
#define H8TISRA_IMIEA0		(1<<H8TISRA_IMIEA0_BIT)
#define H8TISRA_IMFA2		(1<<H8TISRA_IMFA2_BIT)
#define H8TISRA_IMFA1		(1<<H8TISRA_IMFA1_BIT)
#define H8TISRA_IMFA0		(1<<H8TISRA_IMFA0_BIT)

/* Timer Interrupt Status Register B (TISRB) */

#define H8TISRB_IMIEB2_BIT	6
#define H8TISRB_IMIEB1_BIT	5
#define H8TISRB_IMIEB0_BIT	4
#define H8TISRB_IMFB2_BIT	2
#define H8TISRB_IMFB1_BIT	1
#define H8TISRB_IMFB0_BIT	0

#define H8TISRB_IMIEB2		(1<<H8TISRB_IMIEB2_BIT)
#define H8TISRB_IMIEB1		(1<<H8TISRB_IMIEB1_BIT)
#define H8TISRB_IMIEB0		(1<<H8TISRB_IMIEB0_BIT)
#define H8TISRB_IMFB2		(1<<H8TISRB_IMFB2_BIT)
#define H8TISRB_IMFB1		(1<<H8TISRB_IMFB1_BIT)
#define H8TISRB_IMFB0		(1<<H8TISRB_IMFB0_BIT)

/* Timer Interrupt Status Register C (TISRC) */

#define H8TISRC_OVIEA2_BIT	6
#define H8TISRC_OVIEA1_BIT	5
#define H8TISRC_OVIEA0_BIT	4
#define H8TISRC_OVFA2_BIT	2
#define H8TISRC_OVFA1_BIT	1
#define H8TISRC_OVFA0_BIT	0

#define H8TISRC_OVIEA2		(1<<H8TISRC_OVIEA2_BIT)
#define H8TISRC_OVIEA1		(1<<H8TISRC_OVIEA1_BIT)
#define H8TISRC_OVIEA0		(1<<H8TISRC_OVIEA0_BIT)
#define H8TISRC_OVFA2		(1<<H8TISRC_OVFA2_BIT)
#define H8TISRC_OVFA1		(1<<H8TISRC_OVFA1_BIT)
#define H8TISRC_OVFA0		(1<<H8TISRC_OVFA0_BIT)

/* Timer Control Register (TCR) */

#define H8TCR_CCLR1_BIT		6
#define H8TCR_CCLR0_BIT		5
#define H8TCR_CKEG1_BIT		4
#define H8TCR_CKEG0_BIT		3
#define H8TCR_TPSC2_BIT		2
#define H8TCR_TPSC1_BIT		1
#define H8TCR_TPSC0_BIT		0

#define H8TCR_CCLR1		(1<<H8TCR_CCLR1_BIT)
#define H8TCR_CCLR0		(1<<H8TCR_CCLR0_BIT)
#define H8TCR_CKEG1		(1<<H8TCR_CKEG1_BIT)
#define H8TCR_CKEG0		(1<<H8TCR_CKEG0_BIT)
#define H8TCR_TPSC2		(1<<H8TCR_TPSC2_BIT)
#define H8TCR_TPSC1		(1<<H8TCR_TPSC1_BIT)
#define H8TCR_TPSC0		(1<<H8TCR_TPSC0_BIT)

/* Timer I/O Control Register (TIOR) */

#define H8TIOR_IOB2_BIT		6
#define H8TIOR_IOB1_BIT		5
#define H8TIOR_IOB0_BIT		4
#define H8TIOR_IOA2_BIT		2
#define H8TIOR_IOA1_BIT		1
#define H8TIOR_IOA0_BIT		0

#define H8TIOR_IOB2		(1<<H8TIOR_IOB2_BIT)
#define H8TIOR_IOB1		(1<<H8TIOR_IOB1_BIT)
#define H8TIOR_IOB0		(1<<H8TIOR_IOB0_BIT)
#define H8TIOR_IOA2		(1<<H8TIOR_IOA2_BIT)
#define H8TIOR_IOA1		(1<<H8TIOR_IOA1_BIT)
#define H8TIOR_IOA0		(1<<H8TIOR_IOA0_BIT)

/* 8 bit Timer */

#define H88TU0			0xffff80	/* base address */
#define H88TU1			0xffff81
#define H88TU2			0xffff90
#define H88TU3			0xffff91

/* address offset */

#define H88TCR			0
#define H88TCSR			2
#define H88TCORA		4
#define H88TCORB		6
#define H88TCNT			8

/* 8 Bit Timer Control Register (8TCR) */

#define H88TCR_CMIEB_BIT	7
#define H88TCR_CMIEA_BIT	6
#define H88TCR_OVIE_BIT		5
#define H88TCR_CCLR1_BIT	4
#define H88TCR_CCLR0_BIT	3
#define H88TCR_CKS2_BIT		2
#define H88TCR_CKS1_BIT		1
#define H88TCR_CKS0_BIT		0

#define H88TCR_CMIEB		(1<<H88TCR_CMIEB_BIT)
#define H88TCR_CMIEA		(1<<H88TCR_CMIEA_BIT)
#define H88TCR_OVIE			(1<<H88TCR_OVIE_BIT)
#define H88TCR_CCLR1		(1<<H88TCR_CCLR1_BIT)
#define H88TCR_CCLR0		(1<<H88TCR_CCLR0_BIT)
#define H88TCR_CKS2			(1<<H88TCR_CKS2_BIT)
#define H88TCR_CKS1			(1<<H88TCR_CKS1_BIT)
#define H88TCR_CKS0			(1<<H88TCR_CKS0_BIT)

/* 8 Bit Timer Control/Status Register (8TCSR) */

#define H88TCSR_CMFB_BIT	7
#define H88TCSR_CMFA_BIT	6
#define H88TCSR_OVF_BIT		5
#define H88TCSR_ADTE_BIT	4
#define H88TCSR_ICE_BIT		4
#define H88TCSR_OIS3_BIT	3
#define H88TCSR_OIS2_BIT	2
#define H88TCSR_OS1_BIT		1
#define H88TCSR_OS0_BIT		0

#define H88TCSR_CMFB		(1<<H88TCSR_CMFB_BIT)
#define H88TCSR_CMFA		(1<<H88TCSR_CMFA_BIT)
#define H88TCSR_OVF			(1<<H88TCSR_OVF_BIT)
#define H88TCSR_ADTE		(1<<H88TCSR_ADTE_BIT)
#define H88TCSR_ICE			(1<<H88TCSR_ICE_BIT)
#define H88TCSR_OIS3		(1<<H88TCSR_OIS3_BIT)
#define H88TCSR_OIS2		(1<<H88TCSR_OIS2_BIT)
#define H88TCSR_OS1			(1<<H88TCSR_OS1_BIT)
#define H88TCSR_OS0			(1<<H88TCSR_OS0_BIT)

/* Serial Communication Interface (SCI) */

#define H8SCI0			0xffffb0	/* base address */
#define H8SCI1			0xffffb8
#define H8SCI2			0xffffc0

/* address offset */

#define H8SMR			0
#define H8BRR			1
#define H8SCR			2
#define H8TDR			3
#define H8SSR			4
#define H8RDR			5
#define H8SCMR			6

/* SCI Serial Mode Register (SMR) */

#define H8SMR_GM_BIT		7
#define H8SMR_CHR_BIT		6
#define H8SMR_PE_BIT		5
#define H8SMR_OE_BIT		4
#define H8SMR_STOP_BIT		3
#define H8SMR_MP_BIT		2
#define H8SMR_CKS1_BIT		1
#define H8SMR_CKS0_BIT		0

#define H8SMR_GM			(1<<H8SMR_GM_BIT)
#define H8SMR_CHR			(1<<H8SMR_CHR_BIT)
#define H8SMR_PE			(1<<H8SMR_PE_BIT)
#define H8SMR_OE			(1<<H8SMR_OE_BIT)
#define H8SMR_STOP			(1<<H8SMR_STOP_BIT)
#define H8SMR_MP			(1<<H8SMR_MP_BIT)
#define H8SMR_CKS1			(1<<H8SMR_CKS1_BIT)
#define H8SMR_CKS0			(1<<H8SMR_CKS0_BIT)
#define H8SMR_CKS_MASK		(H8SMR_CKS1|H8SMR_CKS0)

/* SCI Serial Control Register (SCR) */

#define H8SCR_TIE_BIT		7
#define H8SCR_RIE_BIT		6
#define H8SCR_TE_BIT		5
#define H8SCR_RE_BIT		4
#define H8SCR_MPIE_BIT		3
#define H8SCR_TEIE_BIT		2
#define H8SCR_CKE1_BIT		1
#define H8SCR_CKE0_BIT		0

#define H8SCR_TIE		(1<<H8SCR_TIE_BIT)
#define H8SCR_RIE		(1<<H8SCR_RIE_BIT)
#define H8SCR_TE		(1<<H8SCR_TE_BIT)
#define H8SCR_RE		(1<<H8SCR_RE_BIT)
#define H8SCR_MPIE		(1<<H8SCR_MPIE_BIT)
#define H8SCR_TEIE		(1<<H8SCR_TEIE_BIT)
#define H8SCR_CKE1		(1<<H8SCR_CKE1_BIT)
#define H8SCR_CKE0		(1<<H8SCR_CKE0_BIT)
#define H8SCR_CKE_MASK	(H8SCR_CKE1|H8SCR_CKE0)
#define H8SCR_IE		(H8SCR_TIE|H8SCR_RIE|H8SCR_MPIE|H8SCR_TEIE)

/* SCI Serial Status Register (SSR) */

#define H8SSR_TDRE_BIT		7
#define H8SSR_RDRF_BIT		6
#define H8SSR_ORER_BIT		5
#define H8SSR_FER_BIT		4
#define H8SSR_PER_BIT		3
#define H8SSR_TEND_BIT		2
#define H8SSR_MPB_BIT		1
#define H8SSR_MPBT_BIT		0

#define H8SSR_TDRE		(1<<H8SSR_TDRE_BIT)
#define H8SSR_RDRF		(1<<H8SSR_RDRF_BIT)
#define H8SSR_ORER		(1<<H8SSR_ORER_BIT)
#define H8SSR_FER		(1<<H8SSR_FER_BIT)
#define H8SSR_PER		(1<<H8SSR_PER_BIT)
#define H8SSR_TEND		(1<<H8SSR_TEND_BIT)
#define H8SSR_MPB		(1<<H8SSR_MPB_BIT)
#define H8SSR_MPBT		(1<<H8SSR_MPBT_BIT)


/*	Bus Release Control Regisger	*/

#define H8BRCR			0xfee013

/*	Control bit in BRCR		*/

#define H8BRCR_A23E_BIT		7
#define H8BRCR_A22E_BIT		6
#define H8BRCR_A21E_BIT		5
#define H8BRCR_BRLE_BIT		1

#define H8BRCR_A23E		(1<<(H8BRCR_A23E_BIT))
#define H8BRCR_A22E		(1<<(H8BRCR_A22E_BIT))
#define H8BRCR_A21E		(1<<(H8BRCR_A21E_BIT))
#define H8BRCR_BRLE		(1<<(H8BRCR_BRLE_BIT))

/* DRAM Control Registers */

#define H8DRCRA			0xfee026	/* Control Register A			*/
#define H8DRCRB			0xfee027	/* Control Register B			*/
#define H8RTMCSR		0xfee028	/* Timer Control / Status Register	*/
#define H8RTCNT			0xfee029	/* Reflesh Timer Counter		*/
#define H8RTCOR			0xfee02a	/* Reflesh Time Constant Register	*/

/* DRAM Control Register A */

#define H8DRCRA_DRAS2_BIT	7
#define H8DRCRA_DRAS1_BIT	6
#define H8DRCRA_DRAS0_BIT	5
#define H8DRCRA_BE_BIT		3
#define H8DRCRA_RDM_BIT		2
#define H8DRCRA_SRFMD_BIT	1
#define H8DRCRA_RFSHE_BIT	0

#define H8DRCRA_DRAS2		(1<<H8DRCRA_DRAS2_BIT)
#define H8DRCRA_DRAS1		(1<<H8DRCRA_DRAS1_BIT)
#define H8DRCRA_DRAS0		(1<<H8DRCRA_DRAS0_BIT)
#define H8DRCRA_BE			(1<<H8DRCRA_BE_BIT)
#define H8DRCRA_RDM			(1<<H8DRCRA_RDM_BIT)
#define H8DRCRA_SRFMD		(1<<H8DRCRA_SRFMD_BIT)
#define H8DRCRA_RFSHE		(1<<H8DRCRA_RFSHE_BIT)

/* DRAM Control Register B */

#define H8DRCRB_MXC1_BIT	7
#define H8DRCRB_MXC0_BIT	6
#define H8DRCRB_CSEL_BIT	5
#define H8DRCRB_RCYCE_BIT	4
#define H8DRCRB_TPC_BIT		2
#define H8DRCRB_RCW_BIT		1
#define H8DRCRB_RLW_BIT		0

#define H8DRCRB_MXC1		(1<<H8DRCRB_MXC1_BIT)
#define H8DRCRB_MXC0		(1<<H8DRCRB_MXC0_BIT)
#define H8DRCRB_CSEL		(1<<H8DRCRB_CSEL_BIT)
#define H8DRCRB_RCYCE		(1<<H8DRCRB_RCYCE_BIT)
#define H8DRCRB_TPC			(1<<H8DRCRB_TPC_BIT)
#define H8DRCRB_RCW			(1<<H8DRCRB_RCW_BIT)
#define H8DRCRB_RLW			(1<<H8DRCRB_RLW_BIT)

/* Reflesh Timer Control / Status Register */

#define H8RTMCSR_CMF_BIT	7
#define H8RTMCSR_CMIE_BIT	6
#define H8RTMCSR_CKS2_BIT	5
#define H8RTMCSR_CKS1_BIT	4
#define H8RTMCSR_CKS0_BIT	3

#define H8RTMCSR_CMF		(1<<H8RTMCSR_CMF_BIT)
#define H8RTMCSR_CMIE		(1<<H8RTMCSR_CMIE_BIT)
#define H8RTMCSR_CKS2		(1<<H8RTMCSR_CKS2_BIT)
#define H8RTMCSR_CKS1		(1<<H8RTMCSR_CKS1_BIT)
#define H8RTMCSR_CKS0		(1<<H8RTMCSR_CKS0_BIT)

/* BUS Wait Control Registers */
#define H8WCRH			0xfee022 	/* Control Register H */
#define H8WCRL			0xfee023 	/* Control Register L */

#define H8WCRH_W71_BIT		6
#define H8WCRH_W70_BIT		6
#define H8WCRH_W61_BIT		5
#define H8WCRH_W60_BIT		4
#define H8WCRH_W51_BIT		3
#define H8WCRH_W50_BIT		2
#define H8WCRH_W41_BIT		1
#define H8WCRH_W40_BIT		0

#define H8WCRL_W31_BIT		7
#define H8WCRL_W30_BIT		6
#define H8WCRL_W21_BIT		5
#define H8WCRL_W20_BIT		4
#define H8WCRL_W11_BIT		3
#define H8WCRL_W10_BIT		2
#define H8WCRL_W01_BIT		1
#define H8WCRL_W00_BIT		0

#define H8WCRH_W7_NOWAIT	(0<<H8WCRH_W70_BIT)
#define H8WCRH_W7_1WAIT		(1<<H8WCRH_W70_BIT)
#define H8WCRH_W7_2WAIT		(2<<H8WCRH_W70_BIT)
#define H8WCRH_W7_3WAIT		(3<<H8WCRH_W70_BIT)
#define H8WCRH_W6_NOWAIT	(0<<H8WCRH_W60_BIT)
#define H8WCRH_W6_1WAIT		(1<<H8WCRH_W60_BIT)
#define H8WCRH_W6_2WAIT		(2<<H8WCRH_W60_BIT)
#define H8WCRH_W6_3WAIT		(3<<H8WCRH_W60_BIT)
#define H8WCRH_W5_NOWAIT	(0<<H8WCRH_W50_BIT)
#define H8WCRH_W5_1WAIT		(1<<H8WCRH_W50_BIT)
#define H8WCRH_W5_2WAIT		(2<<H8WCRH_W50_BIT)
#define H8WCRH_W5_3WAIT		(3<<H8WCRH_W50_BIT)
#define H8WCRH_W4_NOWAIT	(0<<H8WCRH_W40_BIT)
#define H8WCRH_W4_1WAIT		(1<<H8WCRH_W40_BIT)
#define H8WCRH_W4_2WAIT		(2<<H8WCRH_W40_BIT)
#define H8WCRH_W4_3WAIT		(3<<H8WCRH_W40_BIT)
#define H8WCRL_W3_NOWAIT	(0<<H8WCRL_W30_BIT)
#define H8WCRL_W3_1WAIT		(1<<H8WCRL_W30_BIT)
#define H8WCRL_W3_2WAIT		(2<<H8WCRL_W30_BIT)
#define H8WCRL_W3_3WAIT		(3<<H8WCRL_W30_BIT)
#define H8WCRL_W2_NOWAIT	(0<<H8WCRL_W20_BIT)
#define H8WCRL_W2_1WAIT		(1<<H8WCRL_W20_BIT)
#define H8WCRL_W2_2WAIT		(2<<H8WCRL_W20_BIT)
#define H8WCRL_W2_3WAIT		(3<<H8WCRL_W20_BIT)
#define H8WCRL_W1_NOWAIT	(0<<H8WCRL_W10_BIT)
#define H8WCRL_W1_1WAIT		(1<<H8WCRL_W10_BIT)
#define H8WCRL_W1_2WAIT		(2<<H8WCRL_W10_BIT)
#define H8WCRL_W1_3WAIT		(3<<H8WCRL_W10_BIT)
#define H8WCRL_W0_NOWAIT	(0<<H8WCRL_W00_BIT)
#define H8WCRL_W0_1WAIT		(1<<H8WCRL_W00_BIT)
#define H8WCRL_W0_2WAIT		(2<<H8WCRL_W00_BIT)
#define H8WCRL_W0_3WAIT		(3<<H8WCRL_W00_BIT)

/* BUS Access State Control Register */

#define H8ASTCR			0xfee021

#define H8ASTCR_AST7_BIT	7
#define H8ASTCR_AST6_BIT	6
#define H8ASTCR_AST5_BIT	5
#define H8ASTCR_AST4_BIT	4
#define H8ASTCR_AST3_BIT	3
#define H8ASTCR_AST2_BIT	2
#define H8ASTCR_AST1_BIT	1
#define H8ASTCR_AST0_BIT	0

#define H8ASTCR_AST7    	(1<<H8ASTCR_AST7_BIT)
#define H8ASTCR_AST6    	(1<<H8ASTCR_AST6_BIT)
#define H8ASTCR_AST5    	(1<<H8ASTCR_AST5_BIT)
#define H8ASTCR_AST4    	(1<<H8ASTCR_AST4_BIT)
#define H8ASTCR_AST3    	(1<<H8ASTCR_AST3_BIT)
#define H8ASTCR_AST2    	(1<<H8ASTCR_AST2_BIT)
#define H8ASTCR_AST1    	(1<<H8ASTCR_AST1_BIT)
#define H8ASTCR_AST0    	(1<<H8ASTCR_AST0_BIT)

/*
 *  内蔵メモリの定義
 */
#define H8IN_ROM_BASE		0x000000
#define H8IN_ROM_SIZE		0x080000
#define H8IN_RAM_BASE		0xffbf20
#define H8IN_RAM_SIZE		0x004000


/*
 *  I/Oポート
 */
#define H8PORT_NUM		12	/*  ポート1～ポートB (DDR値一時保存用) */

/*  ポート1  */
#define H8P10DDR		0x01
#define H8P11DDR		0x02
#define H8P12DDR		0x04
#define H8P13DDR		0x08
#define H8P14DDR		0x10
#define H8P15DDR		0x20
#define H8P16DDR		0x40
#define H8P17DDR		0x80

#define H8P10DR			0x01
#define H8P11DR			0x02
#define H8P12DR			0x04
#define H8P13DR			0x08
#define H8P14DR			0x10
#define H8P15DR			0x20
#define H8P16DR			0x40
#define H8P17DR			0x80

/*  ポート2  */
#define H8P20DDR		0x01
#define H8P21DDR		0x02
#define H8P22DDR		0x04
#define H8P23DDR		0x08
#define H8P24DDR		0x10
#define H8P25DDR		0x20
#define H8P26DDR		0x40
#define H8P27DDR		0x80

#define H8P20DR			0x01
#define H8P21DR			0x02
#define H8P22DR			0x04
#define H8P23DR			0x08
#define H8P24DR			0x10
#define H8P25DR			0x20
#define H8P26DR			0x40
#define H8P27DR			0x80

#define H8P20PCR		0x01
#define H8P21PCR		0x02
#define H8P22PCR		0x04
#define H8P23PCR		0x08
#define H8P24PCR		0x10
#define H8P25PCR		0x20
#define H8P26PCR		0x40
#define H8P27PCR		0x80

/*  ポート3  */
#define H8P30DDR		0x01
#define H8P31DDR		0x02
#define H8P32DDR		0x04
#define H8P33DDR		0x08
#define H8P34DDR		0x10
#define H8P35DDR		0x20
#define H8P36DDR		0x40
#define H8P37DDR		0x80

#define H8P30DR			0x01
#define H8P31DR			0x02
#define H8P32DR			0x04
#define H8P33DR			0x08
#define H8P34DR			0x10
#define H8P35DR			0x20
#define H8P36DR			0x40
#define H8P37DR			0x80

/*  ポート4  */
#define H8P40DDR		0x01
#define H8P41DDR		0x02
#define H8P42DDR		0x04
#define H8P43DDR		0x08
#define H8P44DDR		0x10
#define H8P45DDR		0x20
#define H8P46DDR		0x40
#define H8P47DDR		0x80

#define H8P40DR			0x01
#define H8P41DR			0x02
#define H8P42DR			0x04
#define H8P43DR			0x08
#define H8P44DR			0x10
#define H8P45DR			0x20
#define H8P46DR			0x40
#define H8P47DR			0x80

#define H8P40PCR		0x01
#define H8P41PCR		0x02
#define H8P42PCR		0x04
#define H8P43PCR		0x08
#define H8P44PCR		0x10
#define H8P45PCR		0x20
#define H8P46PCR		0x40
#define H8P47PCR		0x80

/*  ポート5  */
#define H8P50DDR		0x01
#define H8P51DDR		0x02
#define H8P52DDR		0x04
#define H8P53DDR		0x08

#define H8P50DR			0x01
#define H8P51DR			0x02
#define H8P52DR			0x04
#define H8P53DR			0x08

#define H8P50PCR		0x01
#define H8P51PCR		0x02
#define H8P52PCR		0x04
#define H8P53PCR		0x08

/*  ポート6   */
#define H8P60DDR		0x01
#define H8P61DDR		0x02
#define H8P62DDR		0x04
#define H8P63DDR		0x08
#define H8P64DDR		0x10
#define H8P65DDR		0x20
#define H8P66DDR		0x40
#define H8P67DDR		0x80

#define H8P60DR			0x01
#define H8P61DR			0x02
#define H8P62DR			0x04
#define H8P63DR			0x08
#define H8P64DR			0x10
#define H8P65DR			0x20
#define H8P66DR			0x40
#define H8P67DR			0x80

/*  ポート7   */
#define H8P70DDR		0x01
#define H8P71DDR		0x02
#define H8P72DDR		0x04
#define H8P73DDR		0x08
#define H8P74DDR		0x10
#define H8P75DDR		0x20
#define H8P76DDR		0x40
#define H8P77DDR		0x80

/*  ポート8  */
#define H8P80DDR		0x01
#define H8P81DDR		0x02
#define H8P82DDR		0x04
#define H8P83DDR		0x08
#define H8P84DDR		0x10

#define H8P80DR			0x01
#define H8P81DR			0x02
#define H8P82DR			0x04
#define H8P83DR			0x08
#define H8P84DR			0x10

/*  ポート9   */
#define H8P90DDR		0x01
#define H8P91DDR		0x02
#define H8P92DDR		0x04
#define H8P93DDR		0x08
#define H8P94DDR		0x10
#define H8P95DDR		0x20

#define H8P90DR			0x01
#define H8P91DR			0x02
#define H8P92DR			0x04
#define H8P93DR			0x08
#define H8P94DR			0x10
#define H8P95DR			0x20

/*  ポートA  */
#define H8PA0DDR		0x01
#define H8PA1DDR		0x02
#define H8PA2DDR		0x04
#define H8PA3DDR		0x08
#define H8PA4DDR		0x10
#define H8PA5DDR		0x20
#define H8PA6DDR		0x40
#define H8PA7DDR		0x80

#define H8PA0DR			0x01
#define H8PA1DR			0x02
#define H8PA2DR			0x04
#define H8PA3DR			0x08
#define H8PA4DR			0x10
#define H8PA5DR			0x20
#define H8PA6DR			0x40
#define H8PA7DR			0x80

/*  ポートB  */
#define H8PB0DDR		0x01
#define H8PB1DDR		0x02
#define H8PB2DDR		0x04
#define H8PB3DDR		0x08
#define H8PB4DDR		0x10
#define H8PB5DDR		0x20
#define H8PB6DDR		0x40
#define H8PB7DDR		0x80

#define H8PB0DR			0x01
#define H8PB1DR			0x02
#define H8PB2DR			0x04
#define H8PB3DR			0x08
#define H8PB4DR			0x10
#define H8PB5DR			0x20
#define H8PB6DR			0x40
#define H8PB7DR			0x80

/*  Ｄ／Ａ変換  */
#define H8DADR0         0xFFFF9C
#define H8DADR1         0xFFFF9D
#define H8DACR          0xFFFF9E
#define H8DASTCR        0xFEE01A

#define H8DACR_DAOE1    0x80
#define H8DACR_DAOE0    0x40
#define H8DACR_DAE      0x20
#define H8DASTCR_DASTE  0x01

/*  Ａ／Ｄ変換  */
#define H8ADDRA         0xFFFFE0
#define H8ADDRB         0xFFFFE2
#define H8ADDRC         0xFFFFE4
#define H8ADDRD         0xFFFFE6

#define H8ADDRAH        H8ADDRA
#define H8ADDRAL        (H8ADDRA + 1)
#define H8ADDRBH        H8ADDRB
#define H8ADDRBL        (H8ADDRB + 1)
#define H8ADDRCH        H8ADDRC
#define H8ADDRCL        (H8ADDRC + 1)
#define H8ADDRDH        H8ADDRD
#define H8ADDRDL        (H8ADDRD + 1)

#define H8ADCSR         0xFFFFE8
#define H8ADCR          0xFFFFE9

#define H8ADCSR_ADF     0x80
#define H8ADCSR_ADIE    0x40
#define H8ADCSR_ADST    0x20
#define H8ADCSR_SCAN    0x10
#define H8ADCSR_CKS     0x08
#define H8ADCSR_CH2     0x04
#define H8ADCSR_CH1     0x02
#define H8ADCSR_CH0     0x01

#define H8ADCR_TRGE     0x80


/*  DMA  */

/* DMAC チャネル0A */
#define H8DMA_MAR0AR		0xffff20
#define H8DMA_MAR0AE		0xffff21
#define H8DMA_MAR0AH		0xffff22
#define H8DMA_MAR0AL		0xffff23
#define H8DMA_IOAR0A		0xffff26
#define H8DMA_ETCR0AH		0xffff24
#define H8DMA_ETCR0AL		0xffff25
#define H8DMA_DTCR0A		0xffff27

/* DMAC チャネル0B */
#define H8DMA_MAR0BR		0xffff28
#define H8DMA_MAR0BE		0xffff29
#define H8DMA_MAR0BH		0xffff2A
#define H8DMA_MAR0BL		0xffff2B
#define H8DMA_IOAR0B		0xffff2E
#define H8DMA_ETCR0BH		0xffff2C
#define H8DMA_ETCR0BL		0xffff2D
#define H8DMA_DTCR0B		0xffff2F

/* DMAC チャネル1A */
#define H8DMA_MAR1AR		0xffff30
#define H8DMA_MAR1AE		0xffff31
#define H8DMA_MAR1AH		0xffff32
#define H8DMA_MAR1AL		0xffff33
#define H8DMA_IOAR1A		0xffff36
#define H8DMA_ETCR1AH		0xffff34
#define H8DMA_ETCR1AL		0xffff35
#define H8DMA_DTCR1A		0xffff37

/* DMAC チャネル1B */
#define H8DMA_MAR1BR		0xffff38
#define H8DMA_MAR1BE		0xffff39
#define H8DMA_MAR1BH		0xffff3A
#define H8DMA_MAR1BL		0xffff3B
#define H8DMA_IOAR1B		0xffff3E
#define H8DMA_ETCR1BH		0xffff3C
#define H8DMA_ETCR1BL		0xffff3D
#define H8DMA_DTCR1B		0xffff3F

/* データトランスファコントロールレジスタ (DTCR) */
#define H8DMA_DTCR_DTE		0x80
#define H8DMA_DTCR_DTSZ 	0x40
#define H8DMA_DTCR_DTID		0x20
#define H8DMA_DTCR_RPE		0x10
#define H8DMA_DTCR_DTIE		0x08
#define H8DMA_DTCR_DTS2		0x04
#define H8DMA_DTCR_DTS1		0x02
#define H8DMA_DTCR_DTS0		0x01

#endif /* _H8_3069F_H_ */

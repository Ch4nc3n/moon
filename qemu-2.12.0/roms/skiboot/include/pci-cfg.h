/* Copyright 2013-2014 IBM Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * PCI Configuration space definitions
 */
#ifndef __PCI_CFG_H
#define __PCI_CFG_H

/* Common cfg space header */
#define PCI_CFG_VENDOR_ID		0x0000
#define PCI_CFG_DEVICE_ID		0x0002
#define PCI_CFG_CMD			0x0004
#define   PCI_CFG_CMD_IO_EN		  0x0001
#define   PCI_CFG_CMD_MEM_EN		  0x0002
#define   PCI_CFG_CMD_BUS_MASTER_EN	  0x0004
#define   PCI_CFG_CMD_PERR_RESP		  0x0040
#define   PCI_CFG_CMD_SERR_EN		  0x0100
#define   PCI_CFG_CMD_INTx_DIS		  0x0400
#define PCI_CFG_STAT			0x0006
#define  PCI_CFG_STAT_INTx		  0x0008
#define  PCI_CFG_STAT_CAP		  0x0010
#define  PCI_CFG_STAT_MDATAPERR		  0x0100
#define  PCI_CFG_STAT_SENT_TABORT	  0x0800
#define  PCI_CFG_STAT_RECV_TABORT	  0x1000
#define  PCI_CFG_STAT_RECV_MABORT	  0x2000
#define  PCI_CFG_STAT_SENT_SERR		  0x4000
#define  PCI_CFG_STAT_RECV_PERR		  0x8000
#define PCI_CFG_REV_ID			0x0008
#define PCI_CFG_CLAS_CODE		0x0009
#define PCI_CFG_CACHE_LINE_SIZE		0x000c
#define PCI_CFG_LAT_TIMER		0x000d
#define PCI_CFG_HDR_TYPE		0x000e
#define PCI_CFG_BIST			0x000f
#define PCI_CFG_BAR0			0x0010
#define   PCI_CFG_BAR_TYPE		  0x00000001
#define   PCI_CFG_BAR_TYPE_MEM		  0x00000000
#define   PCI_CFG_BAR_TYPE_IO		  0x00000001
#define   PCI_CFG_BAR_MEM64		  0x00000004
#define   PCI_CFG_BAR_MEM_PREFETCH	  0x00000008
#define PCI_CFG_BAR1			0x0014

/* Type 0 fields */
#define PCI_CFG_BAR2			0x0018
#define PCI_CFG_BAR3			0x001c
#define PCI_CFG_BAR4			0x0020
#define PCI_CFG_BAR5			0x0024
#define PCI_CFG_CARDBUS_CIS		0x0028
#define PCI_CFG_SUBSYS_VENDOR_ID	0x002c
#define PCI_CFG_SUBSYS_ID		0x002e
#define PCI_CFG_ROMBAR			0x0030
#define PCI_CFG_CAP			0x0034
#define PCI_CFG_INT_LINE		0x003c
#define PCI_CFG_INT_PIN			0x003d
#define PCI_CFG_INT_MIN_GNT		0x003e
#define PCI_CFG_INT_MAX_LAT		0x003f

/* Type 1 fields */
#define PCI_CFG_PRIMARY_BUS		0x0018
#define PCI_CFG_SECONDARY_BUS		0x0019
#define PCI_CFG_SUBORDINATE_BUS		0x001a
#define PCI_CFG_SEC_LAT_TIMER		0x001b
#define PCI_CFG_IO_BASE			0x001c
#define PCI_CFG_IO_LIMIT		0x001d
#define PCI_CFG_SECONDARY_STATUS	0x001e
#define PCI_CFG_MEM_BASE		0x0020
#define PCI_CFG_MEM_LIMIT		0x0022
#define PCI_CFG_PREF_MEM_BASE		0x0024
#define PCI_CFG_PREF_MEM_LIMIT		0x0026
#define PCI_CFG_PREF_MEM_BASE_U32	0x0028
#define PCI_CFG_PREF_MEM_LIMIT_U32	0x002c
#define PCI_CFG_IO_BASE_U16		0x0030
#define PCI_CFG_IO_LIMIT_U16		0x0032
#define PCI_CFG_BR_CAP			0x0034 /* Same as type 0 */
#define PCI_CFG_BR_ROMBAR		0x0038 /* Different from type 0 */
#define PCI_CFG_BR_INT_LINE		0x003c /* Same as type 0 */
#define PCI_CFG_BR_INT_PIN		0x003d /* Same as type 0 */
#define PCI_CFG_BRCTL			0x003e
#define   PCI_CFG_BRCTL_PERR_RESP_EN	  0x0001
#define   PCI_CFG_BRCTL_SERR_EN		  0x0002
#define   PCI_CFG_BRCTL_ISA_EN		  0x0004
#define   PCI_CFG_BRCTL_VGA_EN		  0x0008
#define   PCI_CFG_BRCTL_VGA_16BIT	  0x0010
#define   PCI_CFG_BRCTL_MABORT_REPORT	  0x0020
#define   PCI_CFG_BRCTL_SECONDARY_RESET	  0x0040
#define   PCI_CFG_BRCTL_FAST_BACK2BACK	  0x0080
#define   PCI_CFG_BRCTL_PRI_DISC_TIMER	  0x0100
#define   PCI_CFG_BRCTL_SEC_DISC_TIMER	  0x0200
#define   PCI_CFG_BRCTL_DISC_TIMER_STAT	  0x0400
#define   PCI_CFG_BRCTL_DISC_TIMER_SERR	  0x0800

/*
 * Standard capabilties
 */
#define PCI_CFG_CAP_ID			0
#define PCI_CFG_CAP_NEXT		1

/* PCI Power Management capability */
#define PCI_CFG_CAP_ID_PM		1

/* PCI bridge subsystem ID capability */
#define PCI_CFG_CAP_ID_SUBSYS_VID	0x0d
#define   PCICAP_SUBSYS_VID_VENDOR	4
#define   PCICAP_SUBSYS_VID_DEVICE	6

/* Vendor specific capability */
#define PCI_CFG_CAP_ID_VENDOR		9

/* PCI Express capability */
#define PCI_CFG_CAP_ID_EXP	 	0x10
/* PCI Express capability fields */
#define PCICAP_EXP_CAPABILITY_REG	0x02
#define   PCICAP_EXP_CAP_VERSION	0x000f
#define   PCICAP_EXP_CAP_TYPE		0x00f0
#define     PCIE_TYPE_ENDPOINT		0x0
#define     PCIE_TYPE_LEGACY		0x1
#define     PCIE_TYPE_ROOT_PORT		0x4
#define     PCIE_TYPE_SWITCH_UPPORT	0x5
#define     PCIE_TYPE_SWITCH_DNPORT	0x6
#define     PCIE_TYPE_PCIE_TO_PCIX	0x7
#define     PCIE_TYPE_PCIX_TO_PCIE	0x8
#define     PCIE_TYPE_RC_INTEGRATED	0x9
#define     PCIE_TYPE_RC_EVT_COLL	0xa
#define   PCICAP_EXP_CAP_SLOT		0x0100
#define   PCICAP_EXP_CAP_MSI_NUM	0x3e00
#define   PCICAP_EXP_CAP_TCS_ROUTING	0x4000
#define PCICAP_EXP_DEVCAP		0x04
#define   PCICAP_EXP_DEVCAP_MPSS	0x00000007
#define      PCIE_MPSS_128		0
#define      PCIE_MPSS_256		1
#define      PCIE_MPSS_512		2
#define      PCIE_MPSS_1024		3
#define      PCIE_MPSS_2048		4
#define      PCIE_MPSS_4096		5
#define   PCICAP_EXP_DEVCAP_PHANT	0x00000018
#define     PCIE_PHANTOM_NONE		0
#define     PCIE_PHANTOM_1MSB		1
#define     PCIE_PHANTOM_2MSB		2
#define     PCIE_PHANTOM_3MSB		3
#define   PCICAP_EXP_DEVCAP_EXTTAG	0x00000020
#define   PCICAP_EXP_DEVCAP_L0SL	0x000001c0
#define     PCIE_L0SL_MAX_64NS		0
#define     PCIE_L0SL_MAX_128NS		1
#define     PCIE_L0SL_MAX_256NS		2
#define     PCIE_L0SL_MAX_512NS		3
#define     PCIE_L0SL_MAX_1US		4
#define     PCIE_L0SL_MAX_2US		5
#define     PCIE_L0SL_MAX_4US		6
#define     PCIE_L0SL_MAX_NO_LIMIT	7
#define   PCICAP_EXP_DEVCAP_L1L		0x00000e00
#define     PCIE_L1L_MAX_1US		0
#define     PCIE_L1L_MAX_2US		1
#define     PCIE_L1L_MAX_4US		2
#define     PCIE_L1L_MAX_8US		3
#define     PCIE_L1L_MAX_16US		4
#define     PCIE_L1L_MAX_32US		5
#define     PCIE_L1L_MAX_64US		6
#define     PCIE_L1L_MAX_NO_LIMIT	7
#define   PCICAP_EXP_ROLE_BASED_ERR	0x00008000
#define   PCICAP_EXP_DEVCAP_PWRVAL	0x03fc0000
#define   PCICAP_EXP_DEVCAP_PWRSCA	0x0c000000
#define     PCIE_SLOT_PWR_SCALE_1x	0
#define     PCIE_SLOT_PWR_SCALE_0d1x	1
#define     PCIE_SLOT_PWR_SCALE_0d01x	2
#define     PCIE_SLOT_PWR_SCALE_0d001x	3
#define   PCICAP_EXP_DEVCAP_FUNC_RESET	0x10000000
#define PCICAP_EXP_DEVCTL		0x08
#define   PCICAP_EXP_DEVCTL_CE_REPORT	0x0001
#define   PCICAP_EXP_DEVCTL_NFE_REPORT	0x0002
#define   PCICAP_EXP_DEVCTL_FE_REPORT	0x0004
#define   PCICAP_EXP_DEVCTL_UR_REPORT	0x0008
#define   PCICAP_EXP_DEVCTL_RELAX_ORD	0x0010
#define   PCICAP_EXP_DEVCTL_MPS		0x00e0
#define     PCIE_MPS_128B		0
#define     PCIE_MPS_256B		1
#define     PCIE_MPS_512B		2
#define     PCIE_MPS_1024B		3
#define     PCIE_MPS_2048B		4
#define     PCIE_MPS_4096B		5
#define   PCICAP_EXP_DEVCTL_EXT_TAG	0x0100
#define	  PCICAP_EXP_DEVCTL_PHANTOM	0x0200
#define	  PCICAP_EXP_DEVCTL_AUX_POW_PM	0x0400
#define	  PCICAP_EXP_DEVCTL_NO_SNOOP	0x0800
#define   PCICAP_EXP_DEVCTL_MRRS	0x7000
#define     PCIE_MRSS_128B		0
#define     PCIE_MRSS_256B		1
#define     PCIE_MRSS_512B		2
#define     PCIE_MRSS_1024B		3
#define     PCIE_MRSS_2048B		4
#define     PCIE_MRSS_4096B		5
#define   PCICAP_EXP_DEVCTL_PCIX_RETRY	0x8000	/* PCIe - PCIX bridges only */
#define   PCICAP_EXP_DEVCTL_FUNC_RESET	0x8000	/* all others */
#define PCICAP_EXP_DEVSTAT		0x0a
#define   PCICAP_EXP_DEVSTAT_CE		0x0001
#define   PCICAP_EXP_DEVSTAT_NFE	0x0002
#define   PCICAP_EXP_DEVSTAT_FE		0x0004
#define   PCICAP_EXP_DEVSTAT_UE		0x0008
#define   PCICAP_EXP_DEVSTAT_AUX_POW	0x0010
#define   PCICAP_EXP_DEVSTAT_TPEND	0x0020
#define PCICAP_EXP_LCAP			0x0c
#define   PCICAP_EXP_LCAP_MAXSPD	0x0000000f
#define     PCIE_LSPEED_VECBIT_0	0x1
#define     PCIE_LSPEED_VECBIT_1	0x2
#define     PCIE_LSPEED_VECBIT_2	0x3
#define     PCIE_LSPEED_VECBIT_3	0x4
#define     PCIE_LSPEED_VECBIT_4	0x5
#define     PCIE_LSPEED_VECBIT_5	0x6
#define     PCIE_LSPEED_VECBIT_6	0x7
#define   PCICAP_EXP_LCAP_MAXWDTH	0x000003f0
#define     PCIE_LWIDTH_1X		1
#define     PCIE_LWIDTH_2X		2
#define     PCIE_LWIDTH_4X		4
#define     PCIE_LWIDTH_8X		8
#define     PCIE_LWIDTH_12X		12
#define     PCIE_LWIDTH_16X		16
#define     PCIE_LWIDTH_32X		32
#define   PCICAP_EXP_LCAP_ASPM_L0S	0x00000400
#define   PCICAP_EXP_LCAP_ASPM_L1	0x00000800
#define   PCICAP_EXP_LCAP_L0S_EXLT	0x00007000
#define     PCIE_L0S_EXLT_LESS_64NS	0
#define     PCIE_L0S_EXLT_64NS_128NS	1
#define     PCIE_L0S_EXLT_128NS_256NS	2
#define     PCIE_L0S_EXLT_256NS_512NS	3
#define     PCIE_L0S_EXLT_512NS_1US	4
#define     PCIE_L0S_EXLT_1US_2US	5
#define     PCIE_L0S_EXLT_2US_4US	6
#define     PCIE_L0S_EXLT_MORE_4US	7
#define   PCICAP_EXP_LCAP_L1_EXLT	0x00038000
#define     PCIE_L1_EXLT_LESS_1US	0
#define     PCIE_L1_EXLT_1US_2US	1
#define     PCIE_L1_EXLT_2US_4US	2
#define     PCIE_L1_EXLT_4US_8US	3
#define     PCIE_L1_EXLT_8US_16US	4
#define     PCIE_L1_EXLT_16US_32US	5
#define     PCIE_L1_EXLT_32US_64US	6
#define     PCIE_L1_EXLT_MORE_64US	7
#define   PCICAP_EXP_LCAP_CLK_PM	0x00040000
#define   PCICAP_EXP_LCAP_SURP_DWN_ERR	0x00080000
#define   PCICAP_EXP_LCAP_DL_ACT_REP	0x00100000
#define   PCICAP_EXP_LCAP_LNKBWDTH_NOTF	0x00200000
#define   PCICAP_EXP_LCAP_ASPM_OPT_CMPL	0x00400000
#define   PCICAP_EXP_LCAP_PORTNUM	0xff000000
#define PCICAP_EXP_LCTL			0x10
#define   PCICAP_EXP_LCTL_ASPM_L0S	0x0001
#define   PCICAP_EXP_LCTL_ASPM_L1	0x0002
#define   PCICAP_EXP_LCTL_RCB		0x0008 /* RO on root ports */
#define   PCICAP_EXP_LCTL_LINK_DIS	0x0010
#define   PCICAP_EXP_LCTL_LINK_RETRAIN	0x0020
#define   PCICAP_EXP_LCTL_COMMON_CLK	0x0040
#define   PCICAP_EXP_LCTL_EXT_SYNCH	0x0080
#define   PCICAP_EXP_LCTL_CLOCK_PM	0x0100
#define   PCICAP_EXP_LCTL_HW_AWIDTH_DIS	0x0200
#define   PCICAP_EXP_LCTL_LBWM_INT_EN	0x0400
#define   PCICAP_EXP_LCTL_LAWD_INT_EN	0x0800
#define PCICAP_EXP_LSTAT		0x12
#define   PCICAP_EXP_LSTAT_SPEED	0x000f /* use PCIE_LSPEED_* consts */
#define   PCICAP_EXP_LSTAT_WIDTH	0x03f0 /* use PCIE_LWIDTH_* consts */
#define   PCICAP_EXP_LSTAT_TRAINING	0x0800
#define   PCICAP_EXP_LSTAT_SLOTCLKCFG	0x1000
#define   PCICAP_EXP_LSTAT_DLLL_ACT	0x2000
#define   PCICAP_EXP_LSTAT_LBWM_STAT	0x4000
#define   PCICAP_EXP_LSTAT_LAWS_STAT	0x8000
#define PCICAP_EXP_SLOTCAP		0x14
#define   PCICAP_EXP_SLOTCAP_ATTNB	0x00000001
#define   PCICAP_EXP_SLOTCAP_PWCTRL	0x00000002
#define   PCICAP_EXP_SLOTCAP_MRLSENS	0x00000004
#define   PCICAP_EXP_SLOTCAP_ATTNI	0x00000008
#define   PCICAP_EXP_SLOTCAP_PWRI	0x00000010
#define   PCICAP_EXP_SLOTCAP_HPLUG_SURP	0x00000020
#define   PCICAP_EXP_SLOTCAP_HPLUG_CAP	0x00000040
#define   PCICAP_EXP_SLOTCAP_SPLVA	0x00007f80
#define   PCICAP_EXP_SLOTCAP_SPLSC	0x00018000
#define   PCICAP_EXP_SLOTCAP_EIP	0x00020000
#define   PCICAP_EXP_SLOTCAP_NO_CMDCOMP	0x00040000
#define   PCICAP_EXP_SLOTCAP_PSLOT	0xfff80000
#define PCICAP_EXP_SLOTCTL		0x18
#define   PCICAP_EXP_SLOTCTL_ATTNB	0x0001
#define   PCICAP_EXP_SLOTCTL_PFLT	0x0002
#define   PCICAP_EXP_SLOTCTL_MRLSENSE	0x0004
#define   PCICAP_EXP_SLOTCTL_PDETECT	0x0008
#define   PCICAP_EXP_SLOTCTL_CMDCOMPINT	0x0010
#define   PCICAP_EXP_SLOTCTL_HPINT	0x0020
#define   PCICAP_EXP_SLOTCTL_ATTNI	0x00c0
#define     PCIE_INDIC_ON		1
#define     PCIE_INDIC_BLINK		2
#define     PCIE_INDIC_OFF		3
#define   PCICAP_EXP_SLOTCTL_PWRI	0x0300 /* Use PCIE_INDIC_* consts */
#define   PCICAP_EXP_SLOTCTL_PWRCTLR	0x0400
#define   PCICAP_EXP_SLOTCTL_EIC	0x0800
#define   PCICAP_EXP_SLOTCTL_DLLSTCHG	0x1000
#define PCICAP_EXP_SLOTSTAT		0x1a
#define   PCICAP_EXP_SLOTSTAT_ATTNBCH	0x0001
#define   PCICAP_EXP_SLOTSTAT_PWRFLTCH	0x0002
#define   PCICAP_EXP_SLOTSTAT_MRLSENSCH	0x0004
#define   PCICAP_EXP_SLOTSTAT_PDETECTCH	0x0008
#define   PCICAP_EXP_SLOTSTAT_CMDCOMPCH	0x0010
#define   PCICAP_EXP_SLOTSTAT_MRLSENSST	0x0020
#define   PCICAP_EXP_SLOTSTAT_PDETECTST	0x0040
#define   PCICAP_EXP_SLOTSTAT_EIS	0x0080
#define   PCICAP_EXP_SLOTSTAT_DLLSTCH	0x0100
#define PCICAP_EXP_RC			0x1c
#define   PCICAP_EXP_RC_SYSERR_ON_CE	0x0001
#define   PCICAP_EXP_RC_SYSERR_ON_NFE	0x0002
#define   PCICAP_EXP_RC_SYSERR_ON_FE	0x0004
#define   PCICAP_EXP_RC_PME_INT_EN	0x0008
#define   PCICAP_EXP_RC_CRS_VISIBLE	0x0010
#define PCICAP_EXP_RCAP			0x1e
#define   PCICAP_EXP_RCAP_CRS_VISIBLE	0x0001
#define PCICAP_EXP_RSTAT		0x20
#define   PCICAP_EXP_RSTAT_PME_RID	0x0000ffff
#define   PCICAP_EXP_RSTAT_PME_STATUS	0x00010000
#define   PCICAP_EXP_RSTAT_PME_PENDING	0x00020000
#define PCIECAP_EXP_DCAP2		0x24
#define   PCICAP_EXP_DCAP2_CMPTOUT	0x0000000f
#define   PCICAP_EXP_DCAP2_CMPTOUT_DIS	0x00000010
#define   PCICAP_EXP_DCAP2_ARI_FWD	0x00000020
#define   PCICAP_EXP_DCAP2_ATOMIC_RTE	0x00000040
#define   PCICAP_EXP_DCAP2_ATOMIC32	0x00000080
#define   PCICAP_EXP_DCAP2_ATOMIC64	0x00000100
#define   PCICAP_EXP_DCAP2_CAS128	0x00000200
#define   PCICAP_EXP_DCAP2_NORO_PRPR	0x00000400
#define   PCICAP_EXP_DCAP2_LTR		0x00000800
#define   PCICAP_EXP_DCAP2_TPHCOMP	0x00001000
#define   PCICAP_EXP_DCAP2_TPHCOMP_EXT	0x00002000
#define   PCICAP_EXP_DCAP2_OBFF_MSG	0x00040000
#define   PCICAP_EXP_DCAP2_OBFF_WAKE	0x00080000
#define   PCICAP_EXP_DCAP2_EXTFMT	0x00100000
#define   PCICAP_EXP_DCAP2_EETLP_PFX	0x00200000
#define   PCICAP_EXP_DCAP2_MAXEETP	0x00c00000
#define     PCIE_EETLPP_1		1
#define     PCIE_EETLPP_2		2
#define     PCIE_EETLPP_3		3
#define     PCIE_EETLPP_4		0
#define PCICAP_EXP_DCTL2		0x28
#define   PCICAP_EXP_DCTL2_CMPTOUT	0x000f
#define   PCICAP_EXP_DCTL2_CMPTOUT_DIS	0x0010
#define   PCICAP_EXP_DCTL2_ARI_FWD	0x0020
#define   PCICAP_EXP_DCTL2_ATOMIC_REQ	0x0040
#define   PCICAP_EXP_DCTL2_ATOMIC_EGBLK	0x0080
#define   PCICAP_EXP_DCTL2_IDO_REQ	0x0100
#define   PCICAP_EXP_DCTL2_IDO_COMPL	0x0200
#define   PCICAP_EXP_DCTL2_LTR		0x0400
#define   PCICAP_EXP_DCTL2_OBFF		0x6000
#define     PCIE_OBFF_MODE_DISABLED	0
#define     PCIE_OBFF_MODE_MSG_A	1
#define     PCIE_OBFF_MODE_MSG_B	2
#define     PCIE_OBFF_MODE_WAKE		3
#define   PCICAP_EXP_DCTL2_EETLPP_BLK	0x8000
#define PCICAP_EXP_DSTA2		0x2a
#define PCICAP_EXP_LCAP2		0x2c
#define   PCICAP_EXP_LCAP2_SP_2d5GTs	0x00000002
#define   PCICAP_EXP_LCAP2_SP_5d0GTs	0x00000004
#define   PCICAP_EXP_LCAP2_SP_8d0GTs	0x00000008
#define   PCICAP_EXP_LCAP2_XLINK	0x00000100
#define PCICAP_EXP_LCTL2		0x30
#define   PCICAP_EXP_LCTL2_TLSPD	0x000f /* use PCIE_LSPEED_ consts */
#define   PCICAP_EXP_LCTL2_ENTER_COMPL	0x0010
#define   PCICAP_EXP_LCTL2_HWAUTSPDIS	0x0020
#define   PCICAP_EXP_LCTL2_SEL_DEEMPH	0x0040
#define   PCICAP_EXP_LCTL2_XMTMARG	0x0380
#define   PCICAP_EXP_LCTL2_ENTER_MCOMPL	0x0400
#define   PCICAP_EXP_LCTL2_COMPL_SOS	0x0800
#define   PCICAP_EXP_LCTL2_CMPPDEM	0xf000
#define PCICAP_EXP_LSTA2		0x32
#define   PCICAP_EXP_LSTA2_DEMPH_LVL	0x0001
#define   PCICAP_EXP_LSTA2_EQ_COMPLETE	0x0002
#define   PCICAP_EXP_LSTA2_EQ_PH1_OK	0x0004
#define   PCICAP_EXP_LSTA2_EQ_PH2_OK	0x0008
#define   PCICAP_EXP_LSTA2_EQ_PH3_OK	0x0010
#define   PCICAP_EXP_LSTA2_LINK_EQ_REQ	0x0020
#define   PCICAP_EXP_SCAP2		0x34
#define   PCICAP_EXP_SCTL2		0x38
#define   PCICAP_EXP_SSTA2		0x3a

/*
 * PCI-E Extended capabilties
 */
#define PCI_CFG_ECAP_START		0x100
#define PCI_CFG_ECAP_ID			0x0000ffff
#define PCI_CFG_ECAP_VERS		0x000f0000
#define PCI_CFG_ECAP_NEXT		0xfff00000

/* AER Ext. Capability */
#define PCIECAP_ID_AER			0x0001
#define PCIECAP_AER_UE_STATUS		0x04
#define   PCIECAP_AER_UE_DLP		0x00000010
#define   PCIECAP_AER_UE_SURPRISE_DOWN	0x00000020
#define   PCIECAP_AER_UE_POISON_TLP	0x00001000
#define   PCIECAP_AER_UE_FLOW_CTL_PROT	0x00002000
#define   PCIECAP_AER_UE_COMPL_TIMEOUT	0x00004000
#define   PCIECAP_AER_UE_COMPL_ABORT	0x00008000
#define   PCIECAP_AER_UE_UNEXP_COMPL	0x00010000
#define   PCIECAP_AER_UE_RECV_OVFLOW	0x00020000
#define   PCIECAP_AER_UE_MALFORMED_TLP	0x00040000
#define   PCIECAP_AER_UE_ECRC		0x00080000
#define   PCIECAP_AER_UE_UNSUPP_REQ	0x00100000
#define   PCIECAP_AER_UE_ACS_VIOLATION	0x00200000
#define   PCIECAP_AER_UE_INTERNAL	0x00400000
#define   PCIECAP_AER_UE_MC_BLKD_TLP	0x00800000
#define   PCIECAP_AER_UE_ATOMIC_EGBLK	0x01000000
#define   PCIECAP_AER_UE_TLP_PRFX_BLK	0x02000000
#define PCIECAP_AER_UE_MASK		0x08
#define   PCIECAP_AER_UE_MASK_DLLP		0x00000010
#define   PCIECAP_AER_UE_MASK_SURPRISE_DOWN	0x00000020
#define   PCIECAP_AER_UE_MASK_POISON_TLP	0x00001000
#define   PCIECAP_AER_UE_MASK_FLOW_CTL_PROT	0x00002000
#define   PCIECAP_AER_UE_MASK_COMPL_TIMEOUT	0x00004000
#define   PCIECAP_AER_UE_MASK_COMPL_ABORT	0x00008000
#define   PCIECAP_AER_UE_MASK_UNEXP_COMPL	0x00010000
#define   PCIECAP_AER_UE_MASK_RECV_OVFLOW	0x00020000
#define   PCIECAP_AER_UE_MASK_MALFORMED_TLP	0x00040000
#define   PCIECAP_AER_UE_MASK_ECRC		0x00080000
#define   PCIECAP_AER_UE_MASK_UNSUPP_REQ	0x00100000
#define PCIECAP_AER_UE_SEVERITY		0x0c
#define   PCIECAP_AER_UE_SEVERITY_DLLP		0x00000010
#define   PCIECAP_AER_UE_SEVERITY_SURPRISE_DOWN	0x00000020
#define   PCIECAP_AER_UE_SEVERITY_POISON_TLP	0x00001000
#define   PCIECAP_AER_UE_SEVERITY_FLOW_CTL_PROT	0x00002000
#define   PCIECAP_AER_UE_SEVERITY_COMPL_TIMEOUT	0x00004000
#define   PCIECAP_AER_UE_SEVERITY_COMPL_ABORT	0x00008000
#define   PCIECAP_AER_UE_SEVERITY_UNEXP_COMPL	0x00010000
#define   PCIECAP_AER_UE_SEVERITY_RECV_OVFLOW	0x00020000
#define   PCIECAP_AER_UE_SEVERITY_MALFORMED_TLP	0x00040000
#define   PCIECAP_AER_UE_SEVERITY_ECRC		0x00080000
#define   PCIECAP_AER_UE_SEVERITY_UNSUPP_REQ	0x00100000
#define   PCIECAP_AER_UE_SEVERITY_INTERNAL	0x00400000
#define PCIECAP_AER_CE_STATUS		0x10
#define   PCIECAP_AER_CE_RECVR_ERR	0x00000001
#define   PCIECAP_AER_CE_BAD_TLP	0x00000040
#define   PCIECAP_AER_CE_BAD_DLLP	0x00000080
#define   PCIECAP_AER_CE_REPLAY_ROLLVR	0x00000100
#define   PCIECAP_AER_CE_REPLAY_TMR_TO	0x00001000
#define   PCIECAP_AER_CE_ADV_NONFATAL	0x00002000
#define   PCIECAP_AER_CE_CORTD_INTERNAL	0x00004000
#define   PCIECAP_AER_CE_HDR_LOG_OVFL	0x00008000
#define PCIECAP_AER_CE_MASK		0x14
#define   PCIECAP_AER_CE_MASK_RECVR_ERR		0x00000001
#define   PCIECAP_AER_CE_MASK_BAD_TLP		0x00000040
#define   PCIECAP_AER_CE_MASK_BAD_DLLP		0x00000080
#define   PCIECAP_AER_CE_MASK_REPLAY_ROLLVR	0x00000100
#define   PCIECAP_AER_CE_MASK_REPLAY_TMR_TO	0x00001000
#define   PCIECAP_AER_CE_MASK_ADV_NONFATAL	0x00002000
#define   PCIECAP_AER_CE_MASK_CORTD_INTERNAL	0x00004000
#define   PCIECAP_AER_CE_MASK_HDR_LOG_OVFL	0x00008000
#define PCIECAP_AER_CAPCTL		0x18
#define   PCIECAP_AER_CAPCTL_FPTR	0x0000001f
#define   PCIECAP_AER_CAPCTL_ECRCG_CAP	0x00000020
#define   PCIECAP_AER_CAPCTL_ECRCG_EN	0x00000040
#define   PCIECAP_AER_CAPCTL_ECRCC_CAP	0x00000080
#define   PCIECAP_AER_CAPCTL_ECRCC_EN	0x00000100
#define   PCIECAP_AER_CAPCTL_MHREC_CAP	0x00000200
#define   PCIECAP_AER_CAPCTL_MHREC_EN	0x00000400
#define   PCIECAP_AER_CAPCTL_TLPPL_PR	0x00000800
#define PCIECAP_AER_HDR_LOG0		0x1c
#define PCIECAP_AER_HDR_LOG1		0x20
#define PCIECAP_AER_HDR_LOG2		0x24
#define PCIECAP_AER_HDR_LOG3		0x28
#define PCIECAP_AER_RERR_CMD		0x2c
#define   PCIECAP_AER_RERR_CMD_FE	0x00000001
#define   PCIECAP_AER_RERR_CMD_NFE	0x00000002
#define   PCIECAP_AER_RERR_CMD_CE	0x00000004
#define PCIECAP_AER_RERR_STA		0x30
#define   PCIECAP_AER_RERR_STA_CORR	0x00000001
#define   PCIECAP_AER_RERR_STA_MCORR	0x00000002
#define   PCIECAP_AER_RERR_STA_FNF	0x00000004
#define   PCIECAP_AER_RERR_STA_MFNF	0x00000008
#define   PCIECAP_AER_RERR_F_UFATAL	0x00000010
#define   PCIECAP_AER_RERR_NFE		0x00000020
#define   PCIECAP_AER_RERR_FE		0x00000040
#define   PCIECAP_AER_RERR_MSINO	0xf8000000
#define PCIECAP_AER_SRCID		0x34
#define   PCIECAP_AER_SRCID_CORR	0x0000ffff
#define   PCIECAP_AER_SRCID_FNF		0xffff0000
#define PCIECAP_AER_TLP_PFX_LOG0	0x38
#define PCIECAP_AER_TLP_PFX_LOG1	0x3c
#define PCIECAP_AER_TLP_PFX_LOG2	0x40
#define PCIECAP_AER_TLP_PFX_LOG3	0x44

/* SRIOV capability */
#define PCIECAP_ID_SRIOV		0x10
#define PCIECAP_SRIOV_CAP		0x04
#define   PCIECAP_SRIOV_CAP_VFM		0x01
#define   PCIECAP_SRIOV_CAP_INTR(x)	((x) >> 21)
#define PCIECAP_SRIOV_CTRL		0x08
#define   PCIECAP_SRIOV_CTRL_VFE	0x01
#define   PCIECAP_SRIOV_CTRL_VFM	0x02
#define   PCIECAP_SRIOV_CTRL_INTR	0x04
#define   PCIECAP_SRIOV_CTRL_MSE	0x08
#define   PCIECAP_SRIOV_CTRL_ARI	0x10
#define PCIECAP_SRIOV_STATUS		0x0a
#define   PCIECAP_SRIOV_STATUS_VFM	0x01
#define PCIECAP_SRIOV_INITIAL_VF	0x0c
#define PCIECAP_SRIOV_TOTAL_VF		0x0e
#define PCIECAP_SRIOV_NUM_VF		0x10
#define PCIECAP_SRIOV_FUNC_LINK		0x12
#define PCIECAP_SRIOV_VF_OFFSET		0x14
#define PCIECAP_SRIOV_VF_STRIDE		0x16
#define PCIECAP_SRIOV_VF_DID		0x1a
#define PCIECAP_SRIOV_SUP_PGSIZE	0x1c
#define PCIECAP_SRIOV_SYS_PGSIZE	0x20
#define PCIECAP_SRIOV_BAR		0x24
#define    PCIECAP_SRIOV_NUM_BARS	6
#define PCIECAP_SRIOV_VFM		0x3c
#define  PCIECAP_SRIOV_VFM_BIR(x)	((x) & 7)
#define  PCIECAP_SRIOV_VFM_OFFSET(x)	((x) & ~7)
#define  PCIECAP_SRIOV_VFM_UA		0x0
#define  PCIECAP_SRIOV_VFM_MI		0x1
#define  PCIECAP_SRIOV_VFM_MO		0x2
#define  PCIECAP_SRIOV_VFM_AV		0x3

/* Vendor specific extend capability */
#define PCIECAP_ID_VNDR			0x0b
#define PCIECAP_VNDR_HDR		0x04
#define   PCIECAP_VNDR_HDR_ID_MASK	0x0000ffff
#define   PCIECAP_VNDR_HDR_ID_LSH	0
#define   PCIECAP_VNDR_HDR_REV_MASK	0x000f0000
#define   PCIECAP_VNDR_HDR_REV_LSH	16
#define   PCIECAP_VNDR_HDR_LEN_MASK	0xfff00000
#define   PCIECAP_VNDR_HDR_LEN_LSH	20

#endif /* __PCI_CFG_H */

/*
 * BCMSDH Function Driver for the native SDIO/MMC driver in the Linux Kernel
 *
 * Copyright (C) 1999-2014, Broadcom Corporation
 * 
 *      Unless you and Broadcom execute a separate written software license
 * agreement governing use of this software, this software is licensed to you
 * under the terms of the GNU General Public License version 2 (the "GPL"),
 * available at http://www.broadcom.com/licenses/GPLv2.php, with the
 * following added to such license:
 * 
 *      As a special exception, the copyright holders of this software give you
 * permission to link this software with independent modules, and to copy and
 * distribute the resulting executable under terms of your choice, provided that
 * you also meet, for each linked independent module, the terms and conditions of
 * the license of that module.  An independent module is a module which is not
 * derived from this software.  The special exception does not apply to any
 * modifications of the software.
 * 
 *      Notwithstanding the above, under no circumstances may you combine this
 * software in any way with any other Broadcom software provided under a license
 * other than the GPL, without Broadcom's express prior written consent.
 *
<<<<<<< HEAD
 * $Id: bcmsdh_sdmmc.h 444019 2013-12-18 08:36:54Z $
=======
 * $Id: bcmsdh_sdmmc.h 355594 2012-09-07 10:22:02Z $
>>>>>>> parent of c421809... update bcmdhd driver from GT-9505 Source
 */

#ifndef __BCMSDH_SDMMC_H__
#define __BCMSDH_SDMMC_H__

#define sd_err(x) do {printf x;} while (0)
#define sd_trace(x)
#define sd_info(x)
#define sd_debug(x)
#define sd_data(x)
#define sd_ctrl(x)

<<<<<<< HEAD
#ifdef CUSTOMER_HW4
#undef sd_err
#define sd_err(x) do {printf x;} while (0)
#endif
=======
#define sd_trace_hw4	sd_trace
>>>>>>> parent of c421809... update bcmdhd driver from GT-9505 Source

#define sd_sync_dma(sd, read, nbytes)
#define sd_init_dma(sd)
#define sd_ack_intr(sd)
#define sd_wakeup(sd);

#define sd_log(x)

#define SDIOH_ASSERT(exp) \
	do { if (!(exp)) \
		printf("!!!ASSERT fail: file %s lines %d", __FILE__, __LINE__); \
	} while (0)

#define BLOCK_SIZE_4318 64
#define BLOCK_SIZE_4328 512

/* internal return code */
#define SUCCESS	0
#define ERROR	1

/* private bus modes */
#define SDIOH_MODE_SD4		2
<<<<<<< HEAD
#define CLIENT_INTR			0x100	/* Get rid of this! */
#define SDIOH_SDMMC_MAX_SG_ENTRIES	(SDPCM_MAXGLOM_SIZE+2)

struct sdioh_info {
	osl_t		*osh;			/* osh handler */
	void		*bcmsdh;		/* upper layer handle */
=======
#define CLIENT_INTR 		0x100	/* Get rid of this! */

struct sdioh_info {
	osl_t 		*osh;			/* osh handler */
>>>>>>> parent of c421809... update bcmdhd driver from GT-9505 Source
	bool		client_intr_enabled;	/* interrupt connnected flag */
	bool		intr_handler_valid;	/* client driver interrupt handler valid */
	sdioh_cb_fn_t	intr_handler;		/* registered interrupt handler */
	void		*intr_handler_arg;	/* argument to call interrupt handler */
	uint16		intmask;		/* Current active interrupts */
<<<<<<< HEAD
=======
	void		*sdos_info;		/* Pointer to per-OS private data */

	uint 		irq;			/* Client irq */
	int 		intrcount;		/* Client interrupts */
>>>>>>> parent of c421809... update bcmdhd driver from GT-9505 Source

	int		intrcount;		/* Client interrupts */
	bool		sd_use_dma;		/* DMA on CMD53 */
	bool 		sd_blockmode;		/* sd_blockmode == FALSE => 64 Byte Cmd 53s. */
						/*  Must be on for sd_multiblock to be effective */
<<<<<<< HEAD
	bool		use_client_ints;	/* If this is false, make sure to restore */
	int		sd_mode;		/* SD1/SD4/SPI */
	int		client_block_size[SDIOD_MAX_IOFUNCS];		/* Blocksize */
	uint8		num_funcs;		/* Supported funcs on client */
	uint32		com_cis_ptr;
	uint32		func_cis_ptr[SDIOD_MAX_IOFUNCS];
	bool		use_rxchain;
	struct scatterlist	sg_list[SDIOH_SDMMC_MAX_SG_ENTRIES];
	struct sdio_func	fake_func0;
	struct sdio_func	*func[SDIOD_MAX_IOFUNCS];

=======
	bool 		use_client_ints;	/* If this is false, make sure to restore */
	int 		sd_mode;		/* SD1/SD4/SPI */
	int 		client_block_size[SDIOD_MAX_IOFUNCS];		/* Blocksize */
	uint8 		num_funcs;		/* Supported funcs on client */
	uint32 		com_cis_ptr;
	uint32 		func_cis_ptr[SDIOD_MAX_IOFUNCS];

#define SDIOH_SDMMC_MAX_SG_ENTRIES	32
	struct scatterlist sg_list[SDIOH_SDMMC_MAX_SG_ENTRIES];
	bool		use_rxchain;
>>>>>>> parent of c421809... update bcmdhd driver from GT-9505 Source
};

/************************************************************
 * Internal interfaces: per-port references into bcmsdh_sdmmc.c
 */

/* Global message bits */
extern uint sd_msglevel;

/* OS-independent interrupt handler */
extern bool check_client_intr(sdioh_info_t *sd);

/* Core interrupt enable/disable of device interrupts */
extern void sdioh_sdmmc_devintr_on(sdioh_info_t *sd);
extern void sdioh_sdmmc_devintr_off(sdioh_info_t *sd);


/**************************************************************
 * Internal interfaces: bcmsdh_sdmmc.c references to per-port code
 */

/* Register mapping routines */
extern uint32 *sdioh_sdmmc_reg_map(osl_t *osh, int32 addr, int size);
extern void sdioh_sdmmc_reg_unmap(osl_t *osh, int32 addr, int size);

/* Interrupt (de)registration routines */
extern int sdioh_sdmmc_register_irq(sdioh_info_t *sd, uint irq);
extern void sdioh_sdmmc_free_irq(uint irq, sdioh_info_t *sd);

extern sdioh_info_t *sdioh_attach(osl_t *osh, struct sdio_func *func);
extern SDIOH_API_RC sdioh_detach(osl_t *osh, sdioh_info_t *sd);
#endif /* __BCMSDH_SDMMC_H__ */

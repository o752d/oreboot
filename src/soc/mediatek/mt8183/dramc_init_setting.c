/*
 * This file is part of the coreboot project.
 *
 * Copyright 2018 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <device/mmio.h>
#include <soc/emi.h>
#include <soc/dramc_pi_api.h>
#include <soc/dramc_register.h>
#include <soc/infracfg.h>

struct reg_init_value {
	u32 *addr;
	u32 value;
};

struct reg_init_value dramc_init_sequence[] = {
	{&mt8183_infracfg->dramc_wbr, 0x00000000},
	{&ch[0].ao.refctrl0, 0x20712000},
	{&ch[1].ao.refctrl0, 0x20712000},
	{&ch[0].ao.ckectrl, 0x00100480},
	{&ch[1].ao.ckectrl, 0x00100480},
	{&ch[0].phy.ckmux_sel, 0x00000003},
	{&ch[1].phy.ckmux_sel, 0x00000003},
	{&mt8183_infracfg->dramc_wbr, 0x0000001f},
	{&ch[0].phy.misc_cg_ctrl0, 0x00000101},
	{&ch[0].phy.misc_ctrl0, 0x38010000},
	{&ch[0].phy.misc_spm_ctrl1, 0x00000000},
	{&ch[0].phy.misc_spm_ctrl2, 0x00000000},
	{&ch[0].phy.misc_spm_ctrl0, 0x00000000},
	{&ch[0].phy.misc_cg_ctrl2, 0x006003bf},
	{&ch[0].phy.misc_cg_ctrl4, 0x333f3f00},
	{&ch[0].phy.shu[0].pll[1], 0x0000001f},
	{&ch[0].phy.shu[0].b[0].dq[7], 0x00000010},
	{&ch[0].phy.shu[0].b[1].dq[7], 0x00000000},
	{&ch[0].phy.shu[0].pll[4], 0xe57800ff},
	{&ch[0].phy.shu[0].pll[6], 0xe57800ff},
	{&ch[0].phy.shu[0].pll[14], 0x00000000},
	{&ch[0].phy.shu[0].pll20, 0x00000000},
	{&ch[0].phy.ca_cmd[2], 0x00000000},
	{&ch[0].phy.b[0].dq[2], 0x00000000},
	{&ch[0].phy.b[1].dq[2], 0x00000000},
	{&ch[0].phy.b[0].dq[9], 0x10000000},
	{&ch[0].phy.b[1].dq[9], 0x10000000},
	{&ch[0].phy.ca_cmd[10], 0x00000000},
	{&ch[0].phy.b0_rxdvs[0], 0x10000022},
	{&ch[0].phy.b1_rxdvs[0], 0x10000022},
	{&ch[0].phy.b0_rxdvs[0], 0x10000222},
	{&ch[0].phy.b1_rxdvs[0], 0x10000222},
	{&ch[0].phy.r[0].b[0].rxdvs[2], 0x20000000},
	{&ch[0].phy.r[1].b[0].rxdvs[2], 0x20000000},
	{&ch[0].phy.shu[0].b[0].dq[5], 0x0030000e},
	{&ch[0].phy.r[0].b[0].rxdvs[1], 0x00020002},
	{&ch[0].phy.r[0].b[0].rxdvs[2], 0xb0800000},
	{&ch[0].phy.r[1].b[0].rxdvs[1], 0x00020002},
	{&ch[0].phy.r[1].b[0].rxdvs[2], 0xb0800000},
	{&ch[0].phy.r[0].b[1].rxdvs[2], 0x20000000},
	{&ch[0].phy.r[1].b[1].rxdvs[2], 0x20000000},
	{&ch[0].phy.shu[0].b[1].dq[5], 0x0030000e},
	{&ch[0].phy.r[0].b[1].rxdvs[1], 0x00020002},
	{&ch[0].phy.r[0].b[1].rxdvs[2], 0xb0800000},
	{&ch[0].phy.r[1].b[1].rxdvs[1], 0x00020002},
	{&ch[0].phy.r[1].b[1].rxdvs[2], 0xb0800000},
	{&ch[0].phy.b0_rxdvs[0], 0x00000222},
	{&ch[0].phy.b1_rxdvs[0], 0x00000222},
	{&ch[0].phy.b[0].dq[9], 0x10000001},
	{&ch[0].phy.shu[0].rk[0].b[0].dq[7], 0x001f1f00},
	{&ch[0].phy.shu[0].rk[1].b[0].dq[7], 0x001f1f00},
	{&ch[0].phy.b[0].dq[4], 0x00001010},
	{&ch[0].phy.b[0].dq[5], 0x00110e10},
	{&ch[0].phy.b[0].dq[6], 0x010310c0},
	{&ch[0].phy.b[0].dq[5], 0x02110e00},
	{&ch[0].phy.b[1].dq[9], 0x10000001},
	{&ch[0].phy.shu[0].rk[0].b[1].dq[7], 0x001f1f00},
	{&ch[0].phy.shu[0].rk[1].b[1].dq[7], 0x001f1f00},
	{&ch[0].phy.b[1].dq[4], 0x00001010},
	{&ch[0].phy.b[1].dq[5], 0x00110e10},
	{&ch[0].phy.b[1].dq[6], 0x010310c0},
	{&ch[0].phy.b[1].dq[5], 0x02110e00},
	{&ch[0].phy.ca_cmd[3], 0x0000008c},
	{&ch[0].phy.ca_cmd[6], 0x00020000},
	{&ch[0].phy.pll3, 0x00000011},
	{&ch[0].phy.b[0].dq[3], 0x00000008},
	{&ch[0].phy.b[1].dq[3], 0x00000008},
	{&ch[0].phy.shu[0].pll[8], 0x00040000},
	{&ch[0].phy.shu[0].pll[9], 0x00000000},
	{&ch[0].phy.shu[0].pll[11], 0x00000000},
	{&ch[0].phy.shu[0].pll[10], 0x00040000},
	{&ch[0].phy.pll4, 0x000c0000},
	{&ch[0].phy.shu[0].pll[0], 0x00000003},
	{&ch[0].phy.ca_dll_fine_tune[1], 0x00200000},
	{&ch[0].phy.b[0].dq[3], 0x0000040e},
	{&ch[0].phy.b[1].dq[3], 0x0000040e},
	{&mt8183_infracfg->dramc_wbr, 0x00000000},
	{&ch[0].phy.shu[0].ca_dll[0], 0x00666009},
	{&ch[1].phy.shu[0].ca_dll[0], 0x00666009},
	{&mt8183_infracfg->dramc_wbr, 0x0000001f},
	{&ch[0].phy.shu[0].b[0].dll[0], 0xc0778608},
	{&ch[0].phy.shu[0].b[1].dll[0], 0xc0778608},
	{&ch[0].phy.shu[0].ca_cmd[5], 0x00000000},
	{&ch[0].phy.shu[0].ca_cmd[0], 0x00104010},
	{&mt8183_infracfg->dramc_wbr, 0x00000000},
	{&ch[0].phy.shu[0].ca_cmd[6], 0x000000c0},
	{&ch[1].phy.shu[0].ca_cmd[6], 0x00000040},
	{&mt8183_infracfg->dramc_wbr, 0x0000001f},
	{&ch[0].phy.shu[0].b[0].dq[6], 0x00000040},
	{&ch[0].phy.shu[0].b[1].dq[6], 0x00000040},
	{&mt8183_infracfg->dramc_wbr, 0x00000000},
	{&ch[0].phy.misc_shu_opt, 0x00050909},
	{&ch[1].phy.misc_shu_opt, 0x00090909},
	{&ch[0].phy.shu[0].ca_dll[1], 0x00090004},
	{&ch[1].phy.shu[0].ca_dll[1], 0x00090001},
	{&mt8183_infracfg->dramc_wbr, 0x0000001f},
	{&ch[0].phy.shu[0].b[0].dll[1], 0x00000001},
	{&ch[0].phy.shu[0].b[1].dll[1], 0x00000001},
	{&ch[0].phy.pll2, 0x00000000},
	{&ch[0].phy.misc_cg_ctrl0, 0x0000000f},
	{&mt8183_infracfg->dramc_wbr, 0x00000000},
	{&ch[0].phy.shu[0].ca_cmd[6], 0x000604c0},
	{&ch[1].phy.shu[0].ca_cmd[6], 0x00060440},
	{&ch[0].phy.shu[0].ca_dll[1], 0x0004e104},
	{&ch[0].phy.shu[0].b[0].dq[6], 0x00060440},
	{&ch[0].phy.shu[0].b[0].dll[1], 0x00022401},
	{&ch[0].phy.shu[0].b[1].dq[6], 0x00060440},
	{&ch[0].phy.shu[0].b[1].dll[1], 0x00022401},
	{&ch[1].phy.shu[0].ca_dll[1], 0x0004e101},
	{&ch[1].phy.shu[0].b[0].dq[6], 0x00060440},
	{&ch[1].phy.shu[0].b[0].dll[1], 0x00022401},
	{&ch[1].phy.shu[0].b[1].dq[6], 0x00060440},
	{&ch[1].phy.shu[0].b[1].dll[1], 0x00022401},
	{&ch[0].phy.shu[0].pll[4], 0xe5780000},
	{&ch[0].phy.shu[0].pll[6], 0xe5780000},
	{&ch[0].phy.misc_shu_opt, 0x00050909},
	{&ch[0].phy.ckmux_sel, 0x00000003},
	{&ch[0].phy.shu[0].ca_cmd[0], 0x00144010},
	{&ch[0].ao.dvfsdll, 0x00000000},
	{&ch[0].phy.shu[0].ca_dll[0], 0x00698619},
	{&ch[0].phy.shu[0].ca_dll[1], 0x0004e104},
	{&ch[0].phy.shu[0].ca_cmd[6], 0x000604c0},
	{&ch[0].phy.b[0].dq[7], 0x00000055},
	{&ch[0].phy.b[1].dq[7], 0x00000055},
	{&ch[0].phy.ca_cmd[7], 0x00000055},
	{&ch[0].phy.ca_cmd[2], 0x00200000},
	{&ch[0].phy.misc_cg_ctrl0, 0x0000000f},
	{&ch[0].phy.shu[0].b[0].dq[6], 0x00060440},
	{&ch[0].phy.shu[0].b[1].dq[6], 0x00060440},
	{&ch[0].phy.shu[0].ca_cmd[6], 0x000604c0},
	{&ch[0].phy.pll4, 0x000c0000},
	{&ch[0].phy.pll1, 0x00000000},
	{&ch[0].phy.pll2, 0x00000000},
	{&ch[0].phy.ca_dll_fine_tune[2], 0x00000000},
	{&ch[0].phy.b[0].dll_fine_tune[2], 0x00000000},
	{&ch[0].phy.b[1].dll_fine_tune[2], 0x00000000},
	{&ch[0].phy.b[0].dll_fine_tune[2], 0x880aec00},
	{&ch[0].phy.b[1].dll_fine_tune[2], 0x880aec00},
	{&ch[0].phy.ca_dll_fine_tune[2], 0x880bac00},
	{&ch[0].phy.ca_dll_fine_tune[0], 0x00000000},
	{&ch[0].phy.b[0].dll_fine_tune[0], 0x00000000},
	{&ch[0].phy.b[1].dll_fine_tune[0], 0x00000000},
	{&ch[0].phy.shu[0].pll[8], 0x00040000},
	{&ch[0].phy.shu[0].pll[10], 0x00040000},
	{&ch[0].phy.shu[0].pll[5], 0x7b000002},
	{&ch[0].phy.shu[0].pll[7], 0x7b000002},
	{&ch[0].phy.ca_dll_fine_tune[0], 0x00000002},
	{&ch[0].phy.b[0].dll_fine_tune[0], 0x00000002},
	{&ch[0].phy.b[1].dll_fine_tune[0], 0x00000002},
	{&ch[0].phy.ca_dll_fine_tune[1], 0x00200000},
	{&ch[0].phy.b[0].dll_fine_tune[1], 0x00000000},
	{&ch[0].phy.b[1].dll_fine_tune[1], 0x00000000},
	{&ch[0].phy.shu[0].b[0].dq[6], 0x02860440},
	{&ch[0].phy.shu[0].b[1].dq[6], 0x02860440},
	{&ch[0].phy.shu[0].ca_cmd[6], 0x028604c0},
	{&ch[0].phy.ca_dll_fine_tune[0], 0x0000000a},
	{&ch[0].phy.b[0].dll_fine_tune[0], 0x0000000a},
	{&ch[0].phy.b[1].dll_fine_tune[0], 0x0000000a},
	{&ch[0].phy.pll1, 0x80000000},
	{&ch[0].phy.pll2, 0x80000000},
	{&ch[0].phy.pll4, 0x004d0000},
	{&ch[0].phy.shu[0].b[0].dq[6], 0x06860440},
	{&ch[0].phy.shu[0].b[1].dq[6], 0x06860440},
	{&ch[0].phy.shu[0].ca_cmd[6], 0x068604c0},
	{&ch[0].phy.ca_dll_fine_tune[3], 0x000ba000},
	{&ch[0].phy.b[0].dll_fine_tune[3], 0x0002e800},
	{&ch[0].phy.b[1].dll_fine_tune[3], 0x0002e800},
	{&ch[0].phy.ca_dll_fine_tune[2], 0x00000800},
	{&ch[0].phy.b[0].dll_fine_tune[2], 0x00000800},
	{&ch[0].phy.b[1].dll_fine_tune[2], 0x00000800},
	{&ch[0].phy.ca_dll_fine_tune[2], 0x00000800},
	{&ch[0].phy.b[0].dll_fine_tune[2], 0x00000000},
	{&ch[0].phy.b[1].dll_fine_tune[2], 0x00000000},
	{&ch[0].phy.misc_cg_ctrl0, 0x0000001f},
	{&ch[0].phy.ca_dll_fine_tune[2], 0x00000801},
	{&ch[0].phy.b[0].dll_fine_tune[2], 0x00000001},
	{&ch[0].phy.b[1].dll_fine_tune[2], 0x00000001},
	{&ch[0].phy.ca_cmd[2], 0x00000000},
	{&ch[0].phy.b[0].dq[7], 0x00000040},
	{&ch[0].phy.b[1].dq[7], 0x00000040},
	{&ch[0].phy.ca_cmd[7], 0x00000040},
	{&ch[0].ao.ckectrl, 0x00100400},
	{&ch[1].ao.ckectrl, 0x00100400},
	{&ch[0].phy.shu[0].pll[5], 0x7b000003},
	{&ch[0].phy.shu[0].pll[7], 0x7b000003},
	{&ch[0].phy.shu[0].pll[14], 0x00000002},
	{&ch[0].phy.shu[0].pll20, 0x00000002},
	{&ch[0].phy.shu[0].pll[14], 0x02080002},
	{&ch[0].phy.shu[0].pll20, 0x02080002},
	{&ch[0].phy.shu[0].pll[15], 0x0c030000},
	{&ch[0].phy.shu[0].pll21, 0x0c030000},
	{&ch[1].phy.shu[0].pll[4], 0x00000000},
	{&ch[1].phy.shu[0].pll[6], 0x00000000},
	{&ch[1].phy.misc_shu_opt, 0x00090909},
	{&ch[1].phy.ckmux_sel, 0x00000003},
	{&ch[1].phy.shu[0].ca_cmd[0], 0x00144010},
	{&ch[1].ao.dvfsdll, 0x00000000},
	{&ch[1].phy.shu[0].ca_dll[0], 0xc0778609},
	{&ch[1].phy.shu[0].ca_dll[1], 0x0004e101},
	{&ch[1].phy.shu[0].ca_cmd[6], 0x00060440},
	{&ch[1].phy.b[0].dq[7], 0x00000055},
	{&ch[1].phy.b[1].dq[7], 0x00000055},
	{&ch[1].phy.ca_cmd[7], 0x00000055},
	{&ch[1].phy.ca_cmd[2], 0x00200000},
	{&ch[1].phy.misc_cg_ctrl0, 0x0000000f},
	{&ch[1].phy.shu[0].b[0].dq[6], 0x00060440},
	{&ch[1].phy.shu[0].b[1].dq[6], 0x00060440},
	{&ch[1].phy.shu[0].ca_cmd[6], 0x00060440},
	{&ch[1].phy.pll4, 0x00000000},
	{&ch[1].phy.pll1, 0x00000000},
	{&ch[1].phy.pll2, 0x00000000},
	{&ch[1].phy.ca_dll_fine_tune[2], 0x00000000},
	{&ch[1].phy.b[0].dll_fine_tune[2], 0x00000000},
	{&ch[1].phy.b[1].dll_fine_tune[2], 0x00000000},
	{&ch[1].phy.b[0].dll_fine_tune[2], 0x880aec00},
	{&ch[1].phy.b[1].dll_fine_tune[2], 0x880aec00},
	{&ch[1].phy.ca_dll_fine_tune[2], 0x880bac00},
	{&ch[1].phy.ca_dll_fine_tune[0], 0x00000000},
	{&ch[1].phy.b[0].dll_fine_tune[0], 0x00000000},
	{&ch[1].phy.b[1].dll_fine_tune[0], 0x00000000},
	{&ch[1].phy.shu[0].pll[8], 0x00040000},
	{&ch[1].phy.shu[0].pll[10], 0x00040000},
	{&ch[1].phy.shu[0].pll[5], 0x7b000000},
	{&ch[1].phy.shu[0].pll[7], 0x7b000000},
	{&ch[1].phy.ca_dll_fine_tune[0], 0x00000002},
	{&ch[1].phy.b[0].dll_fine_tune[0], 0x00000002},
	{&ch[1].phy.b[1].dll_fine_tune[0], 0x00000002},
	{&ch[1].phy.ca_dll_fine_tune[1], 0x00200000},
	{&ch[1].phy.b[0].dll_fine_tune[1], 0x00000000},
	{&ch[1].phy.b[1].dll_fine_tune[1], 0x00000000},
	{&ch[1].phy.shu[0].b[0].dq[6], 0x02860440},
	{&ch[1].phy.shu[0].b[1].dq[6], 0x02860440},
	{&ch[1].phy.shu[0].ca_cmd[6], 0x02860440},
	{&ch[1].phy.ca_dll_fine_tune[0], 0x0000000a},
	{&ch[1].phy.b[0].dll_fine_tune[0], 0x0000000a},
	{&ch[1].phy.b[1].dll_fine_tune[0], 0x0000000a},
	{&ch[1].phy.pll1, 0x80000000},
	{&ch[1].phy.pll2, 0x80000000},
	{&ch[1].phy.pll4, 0x00410000},
	{&ch[1].phy.shu[0].b[0].dq[6], 0x06860440},
	{&ch[1].phy.shu[0].b[1].dq[6], 0x06860440},
	{&ch[1].phy.shu[0].ca_cmd[6], 0x06860440},
	{&ch[1].phy.ca_dll_fine_tune[3], 0x0003a000},
	{&ch[1].phy.b[0].dll_fine_tune[3], 0x0002e800},
	{&ch[1].phy.b[1].dll_fine_tune[3], 0x0002e800},
	{&ch[1].phy.ca_dll_fine_tune[2], 0x00000800},
	{&ch[1].phy.b[0].dll_fine_tune[2], 0x00000800},
	{&ch[1].phy.b[1].dll_fine_tune[2], 0x00000800},
	{&ch[1].phy.ca_dll_fine_tune[2], 0x00000800},
	{&ch[1].phy.b[0].dll_fine_tune[2], 0x00000000},
	{&ch[1].phy.b[1].dll_fine_tune[2], 0x00000000},
	{&ch[1].phy.misc_cg_ctrl0, 0x0000001f},
	{&ch[1].phy.ca_dll_fine_tune[2], 0x00000801},
	{&ch[1].phy.b[0].dll_fine_tune[2], 0x00000001},
	{&ch[1].phy.b[1].dll_fine_tune[2], 0x00000001},
	{&ch[1].phy.ca_cmd[2], 0x00000000},
	{&ch[1].phy.b[0].dq[7], 0x00000040},
	{&ch[1].phy.b[1].dq[7], 0x00000040},
	{&ch[1].phy.ca_cmd[7], 0x00000040},
	{&ch[0].ao.ckectrl, 0x00100400},
	{&ch[1].ao.ckectrl, 0x00100400},
	{&ch[1].phy.shu[0].pll[5], 0x00000001},
	{&ch[1].phy.shu[0].pll[7], 0x00000001},
	{&ch[1].phy.shu[0].pll[14], 0x00000002},
	{&ch[1].phy.shu[0].pll20, 0x00000002},
	{&ch[1].phy.shu[0].pll[14], 0x02080000},
	{&ch[1].phy.shu[0].pll20, 0x02080000},
	{&ch[1].phy.shu[0].pll[15], 0x0c030000},
	{&ch[1].phy.shu[0].pll21, 0x0c030000},
	{&mt8183_infracfg->dramc_wbr, 0x0000001f},
	{&ch[0].ao.drsctrl, 0x20080000},
	{&ch[0].ao.ckectrl, 0x08100400},
	{&ch[0].ao.dramctrl, 0x30822201},
	{&ch[0].ao.spcmdctrl, 0x200007d2},
	{&ch[0].phy.b[0].dq[9], 0x10000011},
	{&ch[0].phy.b[1].dq[9], 0x10000011},
	{&ch[0].ao.shu[0].rk[1].dqsien, 0x0f0f0f0f},
	{&ch[0].ao.stbcal1, 0x00014310},
	{&ch[0].ao.shu[0].dqsg_retry, 0x80200608},
	{&ch[0].ao.shu[0].drving[0], 0x14a5294a},
	{&ch[0].ao.shu[0].drving[1], 0x14a5294a},
	{&ch[0].ao.shu[0].drving[2], 0x14a5294a},
	{&ch[0].ao.shu[0].drving[3], 0x14a5294a},
	{&ch[0].ao.shuctrl2, 0x0001d00a},
	{&ch[0].ao.dvfsdll, 0x00000001},
	{&ch[0].ao.ddrconf0, 0x04109000},
	{&ch[0].ao.stbcal2, 0x70000010},
	{&ch[0].ao.stbcal2, 0x50000010},
	{&ch[0].ao.clkar, 0x020c0000},
	{&ch[0].phy.b[0].dq[9], 0x10100011},
	{&ch[0].phy.b[1].dq[9], 0x10100011},
	{&ch[0].phy.ca_cmd[10], 0x00000000},
	{&ch[0].phy.misc_ctrl0, 0xb901020f},
	{&ch[0].phy.misc_ctrl1, 0x8100908c},
	{&ch[1].phy.misc_ctrl1, 0x8100908c},
	{&ch[0].phy.b0_rxdvs[0], 0x01000222},
	{&ch[0].phy.b1_rxdvs[0], 0x01000222},
	{&ch[0].phy.ca_rxdvs0, 0x00000000},
	{&ch[0].phy.ca_cmd[7], 0x00000000},
	{&ch[0].phy.b[0].dq[7], 0x00000000},
	{&ch[0].phy.b[1].dq[7], 0x00000000},
	{&ch[0].ao.shu[0].conf[0], 0xa10810bf},
	{&ch[0].ao.shu[0].odtctrl, 0xc0010003},
	{&ch[0].phy.shu[0].b[0].dq[7], 0x00008010},
	{&ch[0].phy.shu[0].b[1].dq[7], 0x00008000},
	{&ch[0].ao.refctrl0, 0x25712000},
	{&ch[0].ao.shu[0].selph_ca1, 0x00000000},
	{&ch[0].ao.shu[0].selph_ca2, 0x00070000},
	{&ch[0].ao.shu[0].selph_ca3, 0x00000000},
	{&ch[0].ao.shu[0].selph_ca4, 0x00000000},
	{&ch[0].ao.shu[0].selph_ca5, 0x11111011},
	{&ch[0].ao.shu[0].selph_dqs0, 0x33333333},
	{&ch[0].ao.shu[0].selph_dqs1, 0x11114444},
	{&ch[0].ao.shu[0].rk[0].selph_dq[0], 0x33333333},
	{&ch[0].ao.shu[0].rk[0].selph_dq[1], 0x33333333},
	{&ch[0].ao.shu[0].rk[0].selph_dq[2], 0x11113333},
	{&ch[0].ao.shu[0].rk[0].selph_dq[3], 0x11113333},
	{&ch[0].ao.shu[0].rk[1].selph_dq[0], 0x33333333},
	{&ch[0].ao.shu[0].rk[1].selph_dq[1], 0x33333333},
	{&ch[0].ao.shu[0].rk[1].selph_dq[2], 0x11113333},
	{&ch[0].ao.shu[0].rk[1].selph_dq[3], 0x11113333},
	{&ch[0].phy.shu[0].rk[0].b[0].dq[7], 0x001a1a00},
	{&ch[0].phy.shu[0].rk[1].b[0].dq[7], 0x00141400},
	{&ch[0].phy.shu[0].rk[0].b[1].dq[7], 0x001a1a00},
	{&ch[0].phy.shu[0].rk[1].b[1].dq[7], 0x00141400},
	{&ch[0].phy.b[0].dq[9], 0x10100031},
	{&ch[0].phy.b[0].dq[6], 0x010350c0},
	{&ch[0].phy.b[1].dq[9], 0x10100031},
	{&ch[0].phy.b[1].dq[6], 0x010350c0},
	{&ch[0].ao.stbcal, 0xf0100000},
	{&ch[0].ao.srefctrl, 0x08400000},
	{&ch[0].ao.shu[0].ckectrl, 0x33210000},
	{&ch[0].ao.shu[0].pipe, 0xc0000000},
	{&ch[0].ao.ckectrl, 0x88102400},
	{&ch[0].ao.rkcfg, 0x00731004},
	{&ch[0].ao.shu[0].conf[2], 0x9007000f},
	{&ch[0].ao.spcmdctrl, 0x240007d2},
	{&ch[0].ao.shuctrl1, 0x00000040},
	{&ch[0].ao.shuctrl, 0x0001c110},
	{&ch[0].ao.refctrl1, 0x30000700},
	{&ch[0].ao.refratre_filter, 0x6543b321},
	{&ch[0].ao.dramctrl, 0x30822001},
	{&ch[0].ao.misctl0, 0x81080000},
	{&ch[0].ao.perfctl0, 0x00024f13},
	{&ch[0].ao.arbctl, 0x00000080},
	{&ch[0].ao.padctrl, 0x00000009},
	{&ch[0].ao.dramc_pd_ctrl, 0x80000106},
	{&ch[0].ao.clkctrl, 0x3000000c},
	{&ch[0].ao.refctrl0, 0x25714001},
	{&ch[0].ao.shu[0].rankctl, 0x64400000},
	{&ch[0].ao.shu[0].rk[0].dqsien, 0x00001919},
	{&ch[0].ao.shu[0].rk[1].dqsien, 0x00001b1b},
	{&ch[0].ao.dramctrl, 0x308a2001},
	{&ch[0].ao.zqcs, 0x00000a56},
	{&ch[0].ao.shu[0].conf[3], 0x00ff0000},
	{&ch[0].ao.refctrl0, 0x65714001},
	{&ch[0].ao.srefctrl, 0x48400000},
	{&ch[0].ao.mpc_option, 0x00020000},
	{&ch[0].ao.dramc_pd_ctrl, 0xc0000106},
	{&ch[0].ao.dramc_pd_ctrl, 0xc0000107},
	{&ch[0].ao.eyescan, 0x00010000},
	{&ch[0].ao.stbcal1, 0x00014f10},
	{&ch[0].ao.test2_3, 0x12000480},
	{&ch[0].ao.rstmask, 0x57000000},
	{&ch[0].ao.rstmask, 0x17000000},
	{&ch[0].ao.hw_mrr_fun, 0x00000068},
	{&ch[0].ao.perfctl0, 0x000a4f13},
	{&ch[0].ao.rstmask, 0x07000000},
	{&ch[0].ao.rkcfg, 0x00731804},
	{&ch[0].ao.spcmdctrl, 0x340007d2},
	{&ch[0].ao.eyescan, 0x00010004},
	{&ch[0].ao.dramctrl, 0x308a2000},
	{&ch[0].ao.mpc_option, 0x00020000},
	{&ch[0].ao.shu[0].wodt, 0xa0000000},
	{&ch[0].phy.shu[0].b[0].dq[7], 0x00008090},
	{&ch[0].phy.shu[0].b[1].dq[7], 0x00008080},
	{&ch[0].ao.shu[0].rankctl, 0x64400000},
	{&ch[0].ao.shu[0].rk[0].selph_dq[0], 0x33333322},
	{&ch[0].ao.shu[0].rk[0].selph_dq[1], 0x33333322},
	{&ch[0].ao.shu[0].rk[1].selph_dq[0], 0x33333322},
	{&ch[0].ao.shu[0].rk[1].selph_dq[1], 0x33333322},
	{&ch[0].ao.stbcal1, 0x00034f10},
	{&ch[0].ao.stbcal1, 0x00014f10},
	{&ch[0].ao.stbcal, 0xfc100001},
	{&ch[0].ao.stbcal1, 0x00014f50},
	{&ch[0].ao.shu[0].dqsg, 0x02009800},
	{&ch[0].phy.misc_ctrl0, 0xb9010200},
	{&ch[0].ao.shu[0].stbcal, 0x00000100},
	{&ch[0].ao.stbcal, 0xfc120001},
	{&ch[0].phy.shu[0].b[0].dq[7], 0x00008090},
	{&ch[0].phy.shu[0].b[1].dq[7], 0x00008080},
	{&ch[0].ao.shu[0].stbcal, 0x00000110},
	{&ch[0].ao.shu[0].stbcal, 0x00000112},
	{&ch[0].ao.refctrl1, 0x30000721},
	{&ch[0].ao.dqsoscr, 0x098e0080},
	{&ch[0].ao.rstmask, 0x00000000},
	{&ch[0].ao.rkcfg, 0x00731814},
	{&ch[0].ao.shu[0].rankctl, 0x64300000},
	{&ch[0].ao.shu[0].wodt, 0x20000000},
	{&ch[0].ao.shu[0].rk[0].fine_tune, 0x1a1a1a1a},
	{&ch[0].ao.shu[0].rk[1].fine_tune, 0x14141414},
	{&ch[0].ao.shu[0].rk[0].selph_dq[2], 0x33333333},
	{&ch[0].ao.shu[0].rk[0].selph_dq[3], 0x33333333},
	{&ch[0].ao.shu[0].rk[1].selph_dq[2], 0x33333333},
	{&ch[0].ao.shu[0].rk[1].selph_dq[3], 0x33333333},
	{&ch[0].ao.shu[0].dqsg_retry, 0x8120050c},
	{&ch[0].phy.shu[0].b[0].dq[7], 0x00008090},
	{&ch[0].phy.shu[0].b[1].dq[7], 0x00008080},
	{&ch[0].ao.shu[0].dqs2dq_tx, 0x00000000},
	{&ch[0].ao.shu[0].odtctrl, 0xc0010003},
	{&ch[0].phy.shu[0].b[0].dq[7], 0x00008090},
	{&ch[0].phy.shu[0].b[1].dq[7], 0x00008080},
	{&ch[0].phy.r[0].b[0].rxdvs[2], 0x20000000},
	{&ch[0].phy.r[1].b[0].rxdvs[2], 0x20000000},
	{&ch[0].phy.r[0].b[1].rxdvs[2], 0x20000000},
	{&ch[0].phy.r[1].b[1].rxdvs[2], 0x20000000},
	{&ch[0].phy.shu[0].ca_cmd[7], 0x00000000},
	{&ch[0].phy.ca_cmd[3], 0x0000048c},
	{&ch[0].phy.ca_cmd[10], 0x00000020},
	{&ch[0].phy.ca_cmd[6], 0x00024000},
	{&ch[0].phy.b[0].dq[3], 0x000004ee},
	{&ch[0].phy.b[1].dq[3], 0x000004ee},
	{&ch[0].phy.ca_cmd[3], 0x000004ac},
	{&ch[0].phy.b[0].dq[3], 0x000004ec},
	{&ch[0].phy.b[1].dq[3], 0x000004ec},
	{&ch[0].phy.b[0].dq[5], 0x82110e00},
	{&ch[0].phy.b[1].dq[5], 0x82110e00},
	{&ch[0].phy.ca_cmd[5], 0x80000808},
	{&ch[0].phy.ca_cmd[6], 0x00034000},
	{&ch[0].phy.misc_imp_ctrl0, 0x00000020},
	{&ch[0].phy.b[0].dq[6], 0x010352c0},
	{&ch[0].phy.b[1].dq[6], 0x010352c0},
	{&ch[0].phy.ca_cmd[6], 0x00034200},
	{&ch[0].phy.b[0].dq[6], 0x010352c1},
	{&ch[0].phy.b[1].dq[6], 0x010352c1},
	{&ch[0].phy.ca_cmd[6], 0x00034201},
	{&ch[0].phy.ca_cmd[6], 0x00034241},
	{&ch[0].phy.b[0].dq[6], 0x010352c9},
	{&ch[0].phy.b[1].dq[6], 0x010352c9},
	{&ch[0].phy.ca_cmd[6], 0x00034249},
	{&ch[0].phy.b[0].dq[6], 0x010352e9},
	{&ch[0].phy.b[1].dq[6], 0x010352e9},
	{&ch[0].phy.ca_cmd[6], 0x00034269},
	{&ch[0].phy.shu[0].b[0].dq[5], 0x0030000e},
	{&ch[0].phy.b[0].dq[5], 0x82110e00},
	{&ch[0].phy.shu[0].b[1].dq[5], 0x0030000e},
	{&ch[0].phy.b[1].dq[5], 0x82110e00},
	{&ch[0].phy.b[0].dq[8], 0x00000007},
	{&ch[0].phy.b[1].dq[8], 0x00000007},
	{&ch[0].phy.ca_cmd[9], 0x00010007},
	{&ch[0].ao.stbcal1, 0x00014f70},
	{&ch[0].ao.stbcal, 0xfc120001},
	{&ch[0].phy.b[0].dq[6], 0x010392e9},
	{&ch[0].phy.b[0].dq[9], 0x10100031},
	{&ch[0].phy.b[0].dq[9], 0x10100020},
	{&ch[0].phy.b[0].dq[9], 0x10100031},
	{&ch[0].phy.b[1].dq[6], 0x010392e9},
	{&ch[0].phy.b[1].dq[9], 0x10100031},
	{&ch[0].phy.b[1].dq[9], 0x10100020},
	{&ch[0].phy.b[1].dq[9], 0x10100031},
	{&ch[1].phy.b[0].dq[8], 0x00000007},
	{&ch[1].phy.b[1].dq[8], 0x00000007},
	{&ch[1].phy.ca_cmd[9], 0x00010007},
	{&ch[1].ao.stbcal1, 0x00014f70},
	{&ch[1].ao.stbcal, 0xfc120001},
	{&ch[1].phy.b[0].dq[6], 0x010392e9},
	{&ch[1].phy.b[0].dq[9], 0x10100031},
	{&ch[1].phy.b[0].dq[9], 0x10100020},
	{&ch[1].phy.b[0].dq[9], 0x10100031},
	{&ch[1].phy.b[1].dq[6], 0x010392e9},
	{&ch[1].phy.b[1].dq[9], 0x10100031},
	{&ch[1].phy.b[1].dq[9], 0x10100020},
	{&ch[1].phy.b[1].dq[9], 0x10100031},
	{&ch[0].phy.ca_cmd[8], 0x00080a0a},
	{&ch[0].phy.ca_cmd[8], 0x00080a0a},
	{&ch[0].ao.shu[0].misc, 0x0000f132},
	{&ch[0].ao.shu[0].dqsg, 0x02a19800},
	{&ch[0].phy.shu[0].b[0].dq[5], 0x0030000e},
	{&ch[0].phy.shu[0].b[1].dq[5], 0x0030000e},
	{&ch[0].phy.shu[0].ca_cmd[5], 0x00000000},
	{&mt8183_infracfg->dramc_wbr, 0x00000000},
	{&ch[0].phy.shu[0].b[0].dq[6], 0x06860440},
	{&ch[0].phy.shu[0].b[1].dq[6], 0x06860440},
	{&ch[0].phy.shu[0].ca_cmd[6], 0x068604c0},
	{&ch[1].phy.shu[0].b[0].dq[6], 0x06860440},
	{&ch[1].phy.shu[0].b[1].dq[6], 0x06860440},
	{&ch[1].phy.shu[0].ca_cmd[6], 0x06860440},
	{&mt8183_infracfg->dramc_wbr, 0x0000001f},
	{&ch[0].ao.shu[0].impcal1, 0x81080004},
	{&ch[0].ao.srefctrl, 0x4840f000},
	{&ch[0].ao.pre_tdqsck[0], 0x00020000},
	{&ch[0].ao.shu[0].misc, 0x0000f132},
	{&ch[0].phy.shu[0].b[0].dq[8], 0xffc07fff},
	{&ch[0].phy.shu[0].b[1].dq[8], 0xffc07fff},
	{&ch[0].phy.shu[0].ca_cmd[8], 0xffc07fff},
	{&ch[0].phy.misc_ctrl3, 0x15351135},
	{&ch[0].phy.shu[0].b[0].dq[7], 0x00008090},
	{&ch[0].phy.shu[0].b[1].dq[7], 0x00008080},
	{&ch[0].ao.clkar, 0x020cffff},
	{&ch[0].ao.shu[0].dqsg_retry, 0x8120050c},
	{&ch[0].ao.write_lev, 0x00080000},
	{&ch[0].ao.dummy_rd, 0x01000000},
	{&ch[0].ao.stbcal2, 0x50000010},
	{&ch[0].ao.eyescan, 0x00010704},
	{&ch[0].ao.shu[0].odtctrl, 0xc001000f},
	{&ch[0].phy.shu[0].b[0].dll[0], 0xc0778609},
	{&ch[0].phy.shu[0].b[1].dll[0], 0xc0778609},
	{&ch[0].phy.ca_dll_fine_tune[1], 0x00200000},
	{&ch[0].ao.perfctl0, 0x040acf13},
	{&ch[0].ao.srefctrl, 0x4840f000},
	{&ch[0].ao.shuctrl1, 0x0000001a},
	{&ch[0].phy.b[0].dq[6], 0x010392e9},
	{&ch[0].phy.b[1].dq[6], 0x010392e9},
	{&ch[0].phy.ca_cmd[6], 0x000352e9},
	{&ch[0].ao.stbcal2, 0x50010010},
	{&ch[0].phy.shu[0].b[0].dq[7], 0x13008090},
	{&ch[0].phy.shu[0].b[1].dq[7], 0x13008080},
	{&ch[0].ao.shu[0].rodtenstb, 0x00000000},
	{&ch[0].ao.shu[0].dqsg, 0x02a19800},
	{&ch[0].ao.shu[0].rk[0].dqscal, 0x00000000},
	{&ch[0].ao.shu[0].rk[1].dqscal, 0x00000000},
	{&ch[0].ao.shu[0].stbcal, 0x00000112},
	{&ch[1].ao.shu[0].dqsg, 0x02a19800},
	{&ch[1].ao.shu[0].rk[0].dqscal, 0x00000000},
	{&ch[1].ao.shu[0].rk[1].dqscal, 0x00000000},
	{&ch[1].ao.shu[0].stbcal, 0x00000112},
	{&ch[0].phy.b[0].dq[9], 0x10100431},
	{&ch[0].phy.b[1].dq[9], 0x10100431},
	{&ch[0].phy.ca_cmd[10], 0x00000020},
	{&ch[0].phy.shu[0].b[0].dq[8], 0xffc07fff},
	{&ch[0].phy.shu[0].b[1].dq[8], 0xffc07fff},
	{&ch[0].phy.shu[0].b[0].dll[1], 0x00022401},
	{&ch[0].phy.shu[0].b[1].dll[1], 0x00022401},
	{&ch[0].ao.shu[0].odtctrl, 0xc001000f},
	{&ch[0].phy.shu[0].b[0].dq[7], 0x13008090},
	{&ch[0].phy.shu[0].b[1].dq[7], 0x13008080},
	{&ch[0].ao.drsctrl, 0x20080000},
	{&ch[0].ao.refctrl0, 0x75714001},
	{&ch[0].ao.zqcs, 0x00080a56},
	{&ch[0].ao.dummy_rd, 0x0d000000},
	{&ch[0].ao.shuctrl2, 0x0001d10a},
	{&ch[0].ao.shuctrl3, 0x0b80000d},
	{&ch[0].phy.misc_ctrl3, 0x1d351135},
	{&ch[0].phy.b[0].dll_fine_tune[1], 0x00300000},
	{&ch[0].phy.b[1].dll_fine_tune[1], 0x00300000},
	{&ch[0].phy.ca_dll_fine_tune[1], 0x00300000},
	{&ch[0].phy.misc_ctrl0, 0xb1010200},
	{&ch[0].phy.misc_rxdvs[2], 0x00000101},
	{&ch[0].ao.clkctrl, 0x3000008c},
	{&ch[0].ao.refctrl1, 0x300007a1},
	{&ch[0].ao.shuctrl, 0x0c01c1d0},
	{&ch[0].ao.shuctrl2, 0x8001dd0a},
	{&ch[0].ao.stbcal2, 0x50010000},
	{&ch[0].ao.pre_tdqsck[0], 0x00020000},
	{&ch[0].ao.ckectrl, 0x88502400},
	{&ch[0].phy.ca_tx_mck, 0xa94011c0},
	{&ch[0].ao.ckectrl, 0x88d02400},
	{&ch[0].ao.shu[0].rodtenstb, 0x00000000},
	{&ch[0].ao.test2_4, 0x0080110d},
	{&ch[0].ao.shu[0].conf[3], 0x00ff0005},
	{&ch[0].ao.refctrl0, 0x75774001},
	{&ch[0].ao.shuctrl2, 0x8301dd0a},
	{&ch[0].ao.refctrl0, 0x75774001},
	{&ch[0].ao.dramctrl, 0x348a2000},
	{&ch[0].ao.dummy_rd, 0x0d426810},
	{&ch[0].ao.test2_4, 0x4080110d},
	{&ch[0].ao.dramctrl, 0x348a2000},
	{&mt8183_infracfg->dramc_wbr, 0x00000000},
	{&ch[0].ao.shuctrl, 0x0c03c1d0},
	{&ch[0].ao.shuctrl2, 0x8301dd0a},
	{&ch[1].ao.shuctrl, 0x0c01c1f0},
	{&ch[1].ao.shuctrl2, 0x8301cd0a},

	/* dramc duty calibration */
	{&ch[0].phy.shu[0].rk[0].ca_cmd[1], 0x00000000},
	{&ch[0].phy.shu[0].rk[0].ca_cmd[0], 0x00000000},
	{&ch[0].phy.shu[0].rk[1].ca_cmd[1], 0x00000000},
	{&ch[0].phy.shu[0].rk[1].ca_cmd[0], 0x00000000},
	{&ch[0].phy.shu[0].ca_cmd[3], 0x00000400},
	{&ch[0].phy.shu[0].rk[0].b[0].dq[1], 0x00110000},
	{&ch[0].phy.shu[0].rk[0].b[1].dq[1], 0x00110000},
	{&ch[0].phy.shu[0].rk[1].b[0].dq[1], 0x00110000},
	{&ch[0].phy.shu[0].rk[1].b[1].dq[1], 0x00110000},
	{&ch[0].phy.shu[0].b[0].dll[1], 0x00022601},
	{&ch[1].phy.shu[0].rk[0].ca_cmd[1], 0x00000000},
	{&ch[1].phy.shu[0].rk[0].ca_cmd[0], 0x00000000},
	{&ch[1].phy.shu[0].rk[1].ca_cmd[1], 0x00000000},
	{&ch[1].phy.shu[0].rk[1].ca_cmd[0], 0x00000000},
	{&ch[1].phy.shu[0].ca_cmd[3], 0x00000400},
	{&ch[1].phy.shu[0].rk[0].b[0].dq[1], 0x22000000},
	{&ch[1].phy.shu[0].rk[0].b[1].dq[1], 0x22000000},
	{&ch[1].phy.shu[0].rk[1].b[0].dq[1], 0x22000000},
	{&ch[1].phy.shu[0].rk[1].b[1].dq[1], 0x22000000},
	{&ch[1].phy.shu[0].b[0].dll[1], 0x00022501},

	/* dramc mode register init */
	{&ch[0].phy.misc_ctrl1, 0x8100908c},
	{&ch[1].phy.misc_ctrl1, 0x8100908c},
	{&ch[0].ao.ckectrl, 0x88d02480},
	{&ch[1].ao.ckectrl, 0x88d02480},
	{&ch[0].phy.misc_ctrl1, 0x8100b08c},
	{&ch[1].phy.misc_ctrl1, 0x8100b08c},
	{&ch[0].ao.dramc_pd_ctrl, 0xc4000107},
	{&ch[1].ao.dramc_pd_ctrl, 0xc4000107},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000000},
	{&ch[0].ao.dramc_pd_ctrl, 0xc4000107},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000000},
	{&ch[0].ao.mpc_option, 0x00020000},
	{&ch[0].ao.spcmd, 0x00000040},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.mrs, 0x00000000},
	{&ch[0].ao.dramc_pd_ctrl, 0xc4000107},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000d18},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000c5d},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000156},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x0000020b},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000b00},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00001638},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000e5d},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000330},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000d58},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000c5d},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000156},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x0000022d},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000b23},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00001634},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000e10},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000330},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000330},
	{&ch[0].ao.dramc_pd_ctrl, 0xc4000107},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x11000330},
	{&ch[0].ao.mpc_option, 0x00020000},
	{&ch[0].ao.spcmd, 0x00000040},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.mrs, 0x01000330},
	{&ch[0].ao.dramc_pd_ctrl, 0xc4000107},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000d18},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000c5d},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000156},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x0100020b},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000b00},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01001638},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000e5d},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000330},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000d58},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000c5d},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000156},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x0100022d},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000b23},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01001634},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000e10},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000330},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000330},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x00000dd8},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000dd8},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000dd8},
	{&ch[0].ao.spcmd, 0x00000001},
	{&ch[0].ao.spcmd, 0x00000000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.mrs, 0x01000dd8},
	{&ch[0].ao.shu[0].hwset_mr13, 0x00d8000d},
	{&ch[0].ao.shu[0].hwset_vrcg, 0x00d8000d},
	{&ch[0].ao.shu[0].hwset_mr2, 0x002d0002},
	{&ch[1].ao.mrs, 0x00000000},
	{&ch[1].ao.dramc_pd_ctrl, 0xc4000107},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000000},
	{&ch[1].ao.mpc_option, 0x00020000},
	{&ch[1].ao.spcmd, 0x00000040},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.mrs, 0x00000000},
	{&ch[1].ao.dramc_pd_ctrl, 0xc4000107},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000d18},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000c5d},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000156},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x0000020b},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000b00},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00001638},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000e5d},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000330},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000d58},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000c5d},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000156},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x0000022d},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000b23},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00001634},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000e10},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000330},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000330},
	{&ch[1].ao.dramc_pd_ctrl, 0xc4000107},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x11000330},
	{&ch[1].ao.mpc_option, 0x00020000},
	{&ch[1].ao.spcmd, 0x00000040},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.mrs, 0x01000330},
	{&ch[1].ao.dramc_pd_ctrl, 0xc4000107},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000d18},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000c5d},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000156},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x0100020b},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000b00},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01001638},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000e5d},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000330},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000d58},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000c5d},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000156},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x0100022d},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000b23},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01001634},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000e10},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000330},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000330},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x00000dd8},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000dd8},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000dd8},
	{&ch[1].ao.spcmd, 0x00000001},
	{&ch[1].ao.spcmd, 0x00000000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.mrs, 0x01000dd8},
	{&ch[1].ao.shu[0].hwset_mr13, 0x00d8000d},
	{&ch[1].ao.shu[0].hwset_vrcg, 0x00d8000d},
	{&ch[1].ao.shu[0].hwset_mr2, 0x002d0002},
	{&ch[0].ao.mrs, 0x00000dd8},
	{&ch[1].ao.mrs, 0x00000dd8},

	/* update the ac timing */
	{&ch[0].ao.shu[0].actim[0], 0x06020c07},
	{&ch[0].ao.shu[0].actim[1], 0x10080501},
	{&ch[0].ao.shu[0].actim[2], 0x07070201},
	{&ch[0].ao.shu[0].actim[3], 0x6164002c},
	{&ch[0].ao.shu[0].actim[4], 0x22650077},
	{&ch[0].ao.shu[0].actim[5], 0x0a000c0b},
	{&ch[0].ao.shu[0].actim_xrt, 0x05030609},
	{&ch[0].ao.shu[0].ac_time_05t, 0x000106e1},
	{&ch[0].ao.catraining1, 0x0b000000},
	{&ch[0].ao.shu[0].rk[0].dqsctl, 0x00000004},
	{&ch[0].ao.shu[0].rk[1].dqsctl, 0x00000004},
	{&ch[0].ao.shu[0].odtctrl, 0xc001004f},
	{&ch[0].ao.shu[0].conf[1], 0x34000d0f},
	{&ch[0].ao.shu[0].conf[2], 0x9007640f},
	{&ch[0].ao.shu[0].scintv, 0x4e39eb36},
	{&ch[0].ao.shu[0].ckectrl, 0x33210000},
	{&ch[0].ao.ckectrl, 0x88d02440},
	{&ch[0].ao.shu[0].rankctl, 0x64300003},
	{&ch[0].ao.shu[0].rankctl, 0x64301203},
	{&ch[1].ao.shu[0].actim[0], 0x06020c07},
	{&ch[1].ao.shu[0].actim[1], 0x10080501},
	{&ch[1].ao.shu[0].actim[2], 0x07070201},
	{&ch[1].ao.shu[0].actim[3], 0x6164002c},
	{&ch[1].ao.shu[0].actim[4], 0x22650077},
	{&ch[1].ao.shu[0].actim[5], 0x0a000c0b},
	{&ch[1].ao.shu[0].actim_xrt, 0x05030609},
	{&ch[1].ao.shu[0].ac_time_05t, 0x000106e1},
	{&ch[1].ao.catraining1, 0x0b000000},
	{&ch[1].ao.shu[0].rk[0].dqsctl, 0x00000004},
	{&ch[1].ao.shu[0].rk[1].dqsctl, 0x00000004},
	{&ch[1].ao.shu[0].odtctrl, 0xc001004f},
	{&ch[1].ao.shu[0].conf[1], 0x34000d0f},
	{&ch[1].ao.shu[0].conf[2], 0x9007640f},
	{&ch[1].ao.shu[0].scintv, 0x4e39eb36},
	{&ch[1].ao.shu[0].ckectrl, 0x33210000},
	{&ch[1].ao.ckectrl, 0x88d02440},
	{&ch[1].ao.shu[0].rankctl, 0x64300003},
	{&ch[1].ao.shu[0].rankctl, 0x64301203},
	{&ch[0].ao.arbctl, 0x00000c80},
	{&ch[0].ao.rstmask, 0x00000000},
	{&ch[0].ao.arbctl, 0x00000c80},
};

void dramc_init(void)
{
	for (int i = 0; i < ARRAY_SIZE(dramc_init_sequence); i++)
		write32(dramc_init_sequence[i].addr,
			dramc_init_sequence[i].value);
}

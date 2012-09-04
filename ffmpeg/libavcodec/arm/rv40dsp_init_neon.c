/*
 * Copyright (c) 2011 Janne Grunau <janne-libav@jannau.net>
 *
 * This file is part of Libav.
 *
 * Libav is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Libav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Libav; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <stdint.h>

#include "libavcodec/avcodec.h"
#include "libavcodec/rv34dsp.h"

void ff_put_rv40_chroma_mc8_neon(uint8_t *, uint8_t *, int, int, int, int);
void ff_put_rv40_chroma_mc4_neon(uint8_t *, uint8_t *, int, int, int, int);

void ff_avg_rv40_chroma_mc8_neon(uint8_t *, uint8_t *, int, int, int, int);
void ff_avg_rv40_chroma_mc4_neon(uint8_t *, uint8_t *, int, int, int, int);

void ff_rv40_weight_func_16_neon(uint8_t *, uint8_t *, uint8_t *, int, int, int);
void ff_rv40_weight_func_8_neon(uint8_t *, uint8_t *, uint8_t *, int, int, int);

void ff_rv40dsp_init_neon(RV34DSPContext *c, DSPContext* dsp)
{
    c->put_chroma_pixels_tab[0] = ff_put_rv40_chroma_mc8_neon;
    c->put_chroma_pixels_tab[1] = ff_put_rv40_chroma_mc4_neon;
    c->avg_chroma_pixels_tab[0] = ff_avg_rv40_chroma_mc8_neon;
    c->avg_chroma_pixels_tab[1] = ff_avg_rv40_chroma_mc4_neon;

    c->rv40_weight_pixels_tab[0] = ff_rv40_weight_func_16_neon;
    c->rv40_weight_pixels_tab[1] = ff_rv40_weight_func_8_neon;
}

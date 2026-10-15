/*
 * File: psp_texture_manager.h
 * Project: gfx
 * File Created: Friday, 7th August 2020 9:11:56 pm
 * Author: HaydenKow
 * -----
 * Copyright (c) 2020 Hayden Kowalchuk, Hayden Kowalchuk
 * License: BSD 3-clause "New" or "Revised" License, http://www.opensource.org/licenses/BSD-3-Clause
 */

#pragma once
#define TEX_ALIGNMENT (16)

/* Upper bound for the VRAM part of the cache; gfx_scegu clamps it to the VRAM
 * left after the frame and depth buffers. */
#define TEXMAN_BUFFER_SIZE (1 * 1024 * 1024 + 256 * 1024)

/* Overflow area in main RAM. The GE can sample from RAM directly, so textures
 * that do not fit in VRAM go here instead of forcing a cache flush. */
#define TEXMAN_RAM_BUFFER_SIZE (6 * 1024 * 1024)

/* Texture ID 0 is reserved, and the gfx_pc cache holds at most 512 nodes. */
#define TEXMAN_MAX_TEXTURES 513

/* Largest single upload, used as the margin when checking for free space. */
#define TEXMAN_MAX_UPLOAD_SIZE (64 * 1024)

struct PSP_Texture {
    unsigned char *location;
    int width, height;
    unsigned int type;
    unsigned int swizzled;
};

/* used for initialization */
int texman_inited(void);
void texman_reset(void *buf, unsigned int size);
void texman_set_buffer(void *buf, unsigned int size);
void texman_set_ram_buffer(void *buf, unsigned int size);

/* management funcs for clients
Steps:
1. create
2. reserve memory & upload by pointer OR upload_swizzle

note: texture will be bound
*/
unsigned int texman_create(void);
void texman_clear(void);
int gfx_vram_space_available(void);
int texman_texture_slot_available(void);
unsigned char *texman_get_tex_data(unsigned int num);
struct PSP_Texture *texman_reserve_memory(int width, int height, unsigned int type);
void texman_upload_swizzle(int width, int height, unsigned int type, const void *buffer);
void texman_upload(int width, int height, unsigned int type, const void *buffer);
void texman_bind_tex(unsigned int num);
unsigned int texman_get_bound(void);

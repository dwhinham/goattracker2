#ifndef ALREADY_INCLUDED_CHUNKPOOL
#define ALREADY_INCLUDED_CHUNKPOOL

/*
 * Copyright (c) 2003 -2005 Magnus Lind.
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 *
 * Permission is granted to anyone to use this software, alter it and re-
 * distribute it freely for any non-commercial, non-profit purpose subject to
 * the following restrictions:
 *
 *   1. The origin of this software must not be misrepresented; you must not
 *   claim that you wrote the original software. If you use this software in a
 *   product, an acknowledgment in the product documentation would be
 *   appreciated but is not required.
 *
 *   2. Altered source versions must be plainly marked as such, and must not
 *   be misrepresented as being the original software.
 *
 *   3. This notice may not be removed or altered from any distribution.
 *
 *   4. The names of this software and/or it's copyright holders may not be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 */

#include "callback.h"

#define CHUNKPOOL_CHUNKS_MAX    64

struct chunkpool {
    int chunk_size;
    int chunk;
    int chunk_pos;
    int chunk_max;
    void *chunks[64];
};

void
chunkpool_init(struct chunkpool *ctx, int size);

void
chunkpool_free(struct chunkpool *ctx);

void
chunkpool_free2(struct chunkpool *ctx, cb_free *f);

void *
chunkpool_malloc(struct chunkpool *ctx);

void *
chunkpool_calloc(struct chunkpool *ctx);

#endif

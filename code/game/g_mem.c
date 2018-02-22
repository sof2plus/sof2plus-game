/*
===========================================================================
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2013 - 2015, OpenJK contributors
Copyright (C) 2017, SoF2Plus contributors

This file is part of the SoF2Plus source code.

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 3 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/
// g_mem.c - Game module memory management.

#include "g_local.h"

// The default pool size is 2 MB.
#define POOLSIZE        (2048 * 1024)

static char             *memoryPool;
static int              poolSize;
static int              poolTail;

/*
==================
G_Alloc

Aligns memory pool pointer, then
allocates the memory from the
pool if it is available.
==================
*/

void *G_Alloc(int size)
{
    // Align the memory pool (4 byte alignment).
    poolSize = ((poolSize + 0x00000003) & 0xfffffffc);

    // Check if we have enough memory left in our pool.
    if(poolSize + size > poolTail){
        Com_Error(ERR_DROP, "G_Alloc: buffer exceeded tail (%d > %d)", poolSize + size, poolTail);
        return 0;
    }

    // Set new pool size.
    poolSize += size;

    // Return index pointer to the memory pool.
    return &memoryPool[poolSize - size];
}

/*
==================
G_AllocUnaligned

Allocates the memory from the
pool if it is available,
without alignment.
==================
*/

void *G_AllocUnaligned(int size)
{
    // Check if we have enough memory left in our pool.
    if(poolSize + size > poolTail){
        Com_Error(ERR_DROP, "G_AllocUnaligned: buffer exceeded tail (%d > %d)", poolSize + size, poolTail);
        return 0;
    }

    // Set new pool size.
    poolSize += size;

    // Return index pointer to the memory pool.
    return &memoryPool[poolSize - size];
}

/*
==================
G_TempAlloc

Aligns the requested size, then
reserves the temporary memory
from the pool if there is
enough space available.
==================
*/

void *G_TempAlloc(int size)
{
    // 4-byte align the specified size.
    size = ((size + 0x00000003) & 0xfffffffc);

    // Check if there is enough free space available in the pool.
    if(poolTail - size < poolSize){
        Com_Error(ERR_DROP, "G_TempAlloc: buffer exceeded head (%d > %d)", poolTail - size, poolSize);
        return 0;
    }

    // Make sure we cannot use this temporary memory for regular G_Alloc* allocations.
    poolTail -= size;

    // Return index pointer to the memory pool.
    return &memoryPool[poolTail];
}

/*
==================
G_TempFree

Aligns the requested size, then
puts back the reserved temporary
memory.

NOTE: Free must be in opposite
order of allocation.
==================
*/

void G_TempFree(int size)
{
    // 4-byte align the specified size.
    size = ((size + 0x00000003) & 0xfffffffc);

    // Check if we're not putting back more memory then initially allocated.
    if(poolTail + size > POOLSIZE){
        Com_Error(ERR_DROP, "G_TempFree: tail greater than size (%d > %d)", poolTail + size, POOLSIZE);
    }

    // We can use this memory again in our regular memory pool operations.
    poolTail += size;
}

/*
==================
G_StringAlloc

Allocates memory from the pool
for the specified source
string. Returns a copy of the
source in the newly allocated
memory.
==================
*/

char *G_StringAlloc(const char *source)
{
    void *dest;

    // Allocate the memory required from the pool.
    dest = G_Alloc(strlen(source) + 1);

    // Copy our source string into the new memory.
    memcpy(dest, source, strlen(source));

    // Return the new destination string.
    return (char *)dest;
}

/*
==================
G_InitMemory

Initializes the game
module memory pool.
==================
*/

void G_InitMemory()
{
    // Request the game module memory
    // from the zone memory.
    memoryPool = trap_Mem_Init(POOLSIZE);

    // Set initial pool variable values.
    poolSize = 0;
    poolTail = POOLSIZE;
}

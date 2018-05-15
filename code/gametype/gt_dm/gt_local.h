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
// gt_local.h - Local definitions for gametype module.

#ifndef __GT_LOCAL_H
#define __GT_LOCAL_H

#include "../../qcommon/q_shared.h"
#include "../gt_public.h"
#include "../gt_syscalls.h"

//=============================================
//
// Global gametype definitions.
//

#define GAMETYPE_NAME               "DM"
#define GAMETYPE_NAME_FULL          "Deathmatch"

//=============================================

typedef     struct      gametypeLocals_s    gametypeLocals_t;
typedef     struct      cvarTable_s         cvarTable_t;

//=============================================
//
// Main gametype structures.
//

struct gametypeLocals_s {
    int         time;
};

struct cvarTable_s {
    vmCvar_t    *vmCvar;
    char        *cvarName;
    char        *defaultString;
    int         cvarFlags;
    float       mMinValue, mMaxValue;
    int         modificationCount;  // for tracking changes
    qboolean    trackChange;        // track this variable, and announce if changed
    qboolean    teamShader;         // track and if changed, update shader state
};

//=============================================

//
// gt_main.c
//

extern gametypeLocals_t gametype;

void    GT_Init         ( void );
void    GT_RunFrame     ( int time );
int     GT_Event        ( int cmd, int time, int arg0, int arg1, int arg2, int arg3, int arg4 );
void    GT_Shutdown     ( void );

#endif // __GT_LOCAL_H

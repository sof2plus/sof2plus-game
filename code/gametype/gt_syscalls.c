// Copyright (C) 2001-2002 Raven Software.
//
#include "../qcommon/q_shared.h"
#include "gt_public.h"

// this file is only included when building a dll
// gt_syscalls.asm is included instead when building a qvm

static intptr_t (QDECL *syscall)( intptr_t arg, ... ) = (intptr_t (QDECL *)( intptr_t, ...))-1;


Q_EXPORT void dllEntry( intptr_t (QDECL *syscallptr)( intptr_t arg,... ) ) {
    syscall = syscallptr;
}

int PASSFLOAT( float x )
{
    float   floatTemp;
    floatTemp = x;
    return *(int *)&floatTemp;
}

void    trap_Print( const char *text ) {
    syscall( GT_PRINT, text );
}

void    trap_Error( const char *text ) {
    syscall( GT_ERROR, text );
    // shut up GCC warning about returning functions, because we know better
    exit(1);
}

int trap_Milliseconds( void )
{
    return syscall( GT_MILLISECONDS );
}

void trap_Cvar_Register ( vmCvar_t *cvar, const char *var_name, const char *value, int flags, float MinValue, float MaxValue )
{
    syscall( GT_CVAR_REGISTER, cvar, var_name, value, flags, PASSFLOAT(MinValue), PASSFLOAT(MaxValue) );
}

void trap_Cvar_Update( vmCvar_t *cvar )
{
    syscall( GT_CVAR_UPDATE, cvar );
}

void trap_Cvar_Set( const char *var_name, const char *value )
{
    syscall( GT_CVAR_SET, var_name, value );
}

int trap_Cvar_VariableIntegerValue( const char *var_name )
{
    return syscall( GT_CVAR_VARIABLE_INTEGER_VALUE, var_name );
}

void trap_Cvar_VariableStringBuffer( const char *var_name, char *buffer, int bufsize )
{
    syscall( GT_CVAR_VARIABLE_STRING_BUFFER, var_name, buffer, bufsize );
}



void trap_Cmd_Restart ( int delay )
{
    syscall ( GT_RESTART, delay );
}

void trap_Cmd_TextMessage ( int client, const char* message )
{
    syscall ( GT_TEXTMESSAGE, client, message );
}

void trap_Cmd_RadioMessage ( int client, const char* message )
{
    syscall ( GT_RADIOMESSAGE, client, message );
}

int trap_Cmd_RegisterSound ( const char* sound )
{
    return syscall ( GT_REGISTERSOUND, sound );
}

void trap_Cmd_StartGlobalSound ( int sound )
{
    syscall ( GT_STARTGLOBALSOUND, sound );
}

void trap_Cmd_StartSound ( int sound, vec3_t origin )
{
    syscall ( GT_STARTSOUND, sound, origin );
}

int trap_Cmd_RegisterEffect ( const char* effect )
{
    return syscall ( GT_REGISTEREFFECT, effect );
}

void trap_Cmd_PlayEffect ( int effect, vec3_t origin, vec3_t angles )
{
    syscall ( GT_PLAYEFFECT, effect, origin, angles );
}

int trap_Cmd_RegisterIcon ( const char* icon )
{
    return syscall ( GT_REGISTERICON, icon);
}

void trap_Cmd_SetHUDIcon ( int index, int icon )
{
    syscall ( GT_SETHUDICON, index, icon );
}

void trap_Cmd_AddTeamScore ( team_t team, int score )
{
    syscall ( GT_ADDTEAMSCORE, team, score );
}

void trap_Cmd_AddClientScore ( int clientid, int score )
{
    syscall ( GT_ADDCLIENTSCORE, clientid, score );
}

qboolean trap_Cmd_RegisterItem ( int itemid, const char* name, gtItemDef_t* def )
{
    return (qboolean)syscall ( GT_REGISTERITEM, itemid, name, def );
}

qboolean trap_Cmd_RegisterTrigger ( int trigid, const char* name, gtTriggerDef_t* def )
{
    return (qboolean)syscall ( GT_REGISTERTRIGGER, trigid, name, def );
}

void trap_Cmd_ResetItem ( int itemid )
{
    syscall ( GT_RESETITEM, itemid );
}

void trap_Cmd_GetClientName ( int clientid, const char* buffer, int buffersize )
{
    syscall ( GT_GETCLIENTNAME, clientid, buffer, buffersize );
}

qboolean trap_Cmd_DoesClientHaveItem ( int clientid, int itemid )
{
    return (qboolean) syscall ( GT_DOESCLIENTHAVEITEM, clientid, itemid );
}

void trap_Cmd_GetClientOrigin ( int clientid, vec3_t origin )
{
    syscall ( GT_GETCLIENTORIGIN, clientid, origin );
}

void trap_Cmd_GiveClientItem ( int clientid, int itemid )
{
    syscall ( GT_GIVECLIENTITEM, clientid, itemid );
}

int trap_Cmd_GetClientList ( team_t team, int* clients, int clientcount )
{
    return syscall ( GT_GETCLIENTLIST, team, clients, clientcount );
}

void trap_Cmd_TakeClientItem ( int clientid, int itemid )
{
    syscall ( GT_TAKECLIENTITEM, clientid, itemid );
}

void trap_Cmd_SpawnItem ( int clientid, vec3_t origin, vec3_t angles )
{
    syscall ( GT_SPAWNITEM, clientid, origin, angles );
}

void trap_Cmd_UseTargets ( const char* targetname )
{
    syscall ( GT_USETARGETS, targetname );
}

void trap_Cmd_GetTriggerTarget ( int triggerid, const char* buffer, int buffersize )
{
    syscall ( GT_GETTRIGGERTARGET, triggerid, buffer, buffersize );
}

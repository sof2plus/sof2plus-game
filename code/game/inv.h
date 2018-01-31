#ifndef _INV_H_
#define _INV_H_

#define INVENTORY_NONE              0
//pickups
#define INVENTORY_ARMOR             1
#define INVENTORY_HEALTH            2
//items
#define INVENTORY_SEEKER            3
#define INVENTORY_MEDPAC            4
#define INVENTORY_DATAPAD           5
#define INVENTORY_BINOCULARS        6
#define INVENTORY_SENTRY_GUN        7
#define INVENTORY_GOGGLES           8
//weapons
#define INVENTORY_STUN_BATON        9
#define INVENTORY_SABER             10
#define INVENTORY_M1911A1_PISTOL    11
#define INVENTORY_BLASTER           12
#define INVENTORY_DISRUPTOR         13
#define INVENTORY_BOWCASTER         14
#define INVENTORY_REPEATER          15
#define INVENTORY_DEMP2             16
#define INVENTORY_FLECHETTE         17
#define INVENTORY_ROCKET_LAUNCHER   18
#define INVENTORY_THERMAL           19
#define INVENTORY_TRIP_MINE         20
#define INVENTORY_DET_PACK          21
//ammo
#define INVENTORY_AMMO_FORCE        22
#define INVENTORY_AMMO_BLASTER      23
#define INVENTORY_AMMO_BOLTS        24
#define INVENTORY_AMMO_ROCKETS      25

//enemy stuff
#define ENEMY_HORIZONTAL_DIST       200
#define ENEMY_HEIGHT                201
#define NUM_VISIBLE_ENEMIES         202
#define NUM_VISIBLE_TEAMMATES       203

// NOTENOTE Update this so that it is in sync.
//item numbers (make sure they are in sync with bg_itemlist in bg_misc.c)
//pickups
typedef enum 
{
    MODELINDEX_NONE,

    MODELINDEX_ARMOR_BIG,           // 1
    MODELINDEX_ARMOR_MEDIUM,
    MODELINDEX_ARMOR_SMALL,
    MODELINDEX_HEALTH_BIG,          
    MODELINDEX_HEALTH_SMALL,            
                                    
    MODELINDEX_WEAPON_KNIFE,        // 6
    MODELINDEX_WEAPON_SOCOM,            
    MODELINDEX_WEAPON_M19,          
    MODELINDEX_WEAPON_SILVERTALON,
    MODELINDEX_WEAPON_MICROUZI, 
        
    MODELINDEX_WEAPON_M3A1,         // 11
    MODELINDEX_WEAPON_MP5,
    MODELINDEX_WEAPON_USAS12,       
    MODELINDEX_WEAPON_M590,         
    MODELINDEX_WEAPON_MSG90A1,      

    MODELINDEX_WEAPON_M4,           // 16
    MODELINDEX_WEAPON_AK74,         
    MODELINDEX_WEAPON_SIG551,
    MODELINDEX_WEAPON_M60,          
    MODELINDEX_WEAPON_RPG7,         

    MODELINDEX_WEAPON_MM1,          // 21
    MODELINDEX_WEAPON_M84,          
    MODELINDEX_WEAPON_SMOHG92,      
    MODELINDEX_WEAPON_ANM14,        
    MODELINDEX_WEAPON_M15,          

    MODELINDEX_AMMO_045,            // 26       
    MODELINDEX_AMMO_9MM,                
    MODELINDEX_AMMO_12GAUGE,        
    MODELINDEX_AMMO_762,            
    MODELINDEX_AMMO_556,            

    MODELINDEX_AMMO_40MM,           // 31
    MODELINDEX_AMMO_RPG7,
    MODELINDEX_BACKPACK,            

    MODELINDEX_GAMETYPE_ITEM,       // 34
    MODELINDEX_GAMETYPE_ITEM_2,
    MODELINDEX_GAMETYPE_ITEM_3,
    MODELINDEX_GAMETYPE_ITEM_4,
    MODELINDEX_GAMETYPE_ITEM_5,     

    MODELINDEX_ARMOR,               // 39
    MODELINDEX_NIGHTVISION,
    MODELINDEX_THERMAL,

} modelIndex_t;

#endif

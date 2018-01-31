#ifndef __G2_LOCAL_H
#define __G2_LOCAL_H

//=============================================
//
// Global Ghoul II definitions.
//

#define BONE_ANGLES_PREMULT         0x0001
#define BONE_ANGLES_POSTMULT        0x0002
#define BONE_ANGLES_REPLACE         0x0004
#define BONE_ANGLES_REPLACE_TO_ANIM 0x0400

#define BONE_ANGLES_TOTAL           (BONE_ANGLES_PREMULT | BONE_ANGLES_POSTMULT | BONE_ANGLES_REPLACE | BONE_ANGLES_REPLACE_TO_ANIM)
#define BONE_ANIM_OVERRIDE          0x0008
#define BONE_ANIM_OVERRIDE_LOOP     0x0010
#define BONE_ANIM_OVERRIDE_DEFAULT  (0x0020 + BONE_ANIM_OVERRIDE)
#define BONE_ANIM_OVERRIDE_FREEZE   (0x0040 + BONE_ANIM_OVERRIDE)
#define BONE_ANIM_TOTAL             (BONE_ANIM_OVERRIDE | BONE_ANIM_OVERRIDE_LOOP | BONE_ANIM_OVERRIDE_DEFAULT | BONE_ANIM_OVERRIDE_FREEZE)


#define ENTITY_WIDTH                12
#define MODEL_WIDTH                 10

#define MODEL_AND                   ((1<<MODEL_WIDTH)-1)
#define ENTITY_AND                  ((1<<ENTITY_WIDTH)-1)

#define BOLT_SHIFT                  0
#define ENTITY_SHIFT                (MODEL_SHIFT + MODEL_WIDTH)

#endif // __G2_LOCAL_H

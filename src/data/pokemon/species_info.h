#include "constants/abilities.h"
#include "constants/teaching_types.h"
#include "species_info/shared_dex_text.h"
#include "species_info/shared_front_pic_anims.h"

// Macros for ease of use.

#define EVOLUTION(...) (const struct Evolution[]) { __VA_ARGS__, { EVOLUTIONS_END }, }
#define CONDITIONS(...) ((const struct EvolutionParam[]) { __VA_ARGS__, {CONDITIONS_END} })

#define ANIM_FRAMES(...) (const union AnimCmd *const[]) { sAnim_GeneralFrame0, (const union AnimCmd[]) { __VA_ARGS__ ANIMCMD_END, }, }

#if P_FOOTPRINTS
#define FOOTPRINT(sprite) .footprint = gMonFootprint_## sprite,
#else
#define FOOTPRINT(sprite)
#endif

#if B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE
#define SHADOW(x, y, size)  .enemyShadowXOffset = x, .enemyShadowYOffset = y, .enemyShadowSize = size,
#define NO_SHADOW           .suppressEnemyShadow = TRUE,
#else
#define SHADOW(x, y, size)  .enemyShadowXOffset = 0, .enemyShadowYOffset = 0, .enemyShadowSize = 0,
#define NO_SHADOW           .suppressEnemyShadow = FALSE,
#endif

#define SIZE_32x32 1
#define SIZE_64x64 0

// Set .compressed = OW_GFX_COMPRESS
#define COMP OW_GFX_COMPRESS

#if OW_POKEMON_OBJECT_EVENTS
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
#define OVERWORLD_PAL(...)                                  \
    .overworldPalette = DEFAULT(NULL, __VA_ARGS__),         \
    .overworldShinyPalette = DEFAULT_2(NULL, __VA_ARGS__),
#if P_GENDER_DIFFERENCES
#define OVERWORLD_PAL_FEMALE(...)                                 \
    .overworldPaletteFemale = DEFAULT(NULL, __VA_ARGS__),         \
    .overworldShinyPaletteFemale = DEFAULT_2(NULL, __VA_ARGS__),
#else
#define OVERWORLD_PAL_FEMALE(...)
#endif //P_GENDER_DIFFERENCES
#else
#define OVERWORLD_PAL(...)
#define OVERWORLD_PAL_FEMALE(...)
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE

#define OVERWORLD_DATA(picTable, _size, shadow, _tracks, _anims)                                                                     \
{                                                                                                                                       \
    .tileTag = TAG_NONE,                                                                                                                \
    .paletteTag = OBJ_EVENT_PAL_TAG_DYNAMIC,                                                                                            \
    .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,                                                                                     \
    .size = (_size == SIZE_32x32 ? 512 : 2048),                                                                                         \
    .width = (_size == SIZE_32x32 ? 32 : 64),                                                                                           \
    .height = (_size == SIZE_32x32 ? 32 : 64),                                                                                          \
    .paletteSlot = PALSLOT_NPC_1,                                                                                                       \
    .shadowSize = shadow,                                                                                                               \
    .inanimate = FALSE,                                                                                                                 \
    .compressed = COMP,                                                                                                                 \
    .tracks = _tracks,                                                                                                                  \
    .oam = (_size == SIZE_32x32 ? &gObjectEventBaseOam_32x32 : &gObjectEventBaseOam_64x64),                                             \
    .subspriteTables = (_size == SIZE_32x32 ? sOamTables_32x32 : sOamTables_64x64),                                                     \
    .anims = _anims,                                                                                                                    \
    .images = picTable,                                                                                                                 \
}

#define OVERWORLD(objEventPic, _size, shadow, _tracks, _anims, ...)                                 \
    .overworldData = OVERWORLD_DATA(objEventPic, _size, shadow, _tracks, _anims),                   \
    OVERWORLD_PAL(__VA_ARGS__)

#if P_GENDER_DIFFERENCES
#define OVERWORLD_FEMALE(objEventPic, _size, shadow, _tracks, _anims, ...)                          \
    .overworldDataFemale = OVERWORLD_DATA(objEventPic, _size, shadow, _tracks, _anims),             \
    OVERWORLD_PAL_FEMALE(__VA_ARGS__)
#else
#define OVERWORLD_FEMALE(...)
#endif //P_GENDER_DIFFERENCES

#else
#define OVERWORLD(...)
#define OVERWORLD_FEMALE(...)
#define OVERWORLD_PAL(...)
#define OVERWORLD_PAL_FEMALE(...)
#endif //OW_POKEMON_OBJECT_EVENTS

// Maximum value for a female Pokémon is 254 (MON_FEMALE) which is 100% female.
// 255 (MON_GENDERLESS) is reserved for genderless Pokémon.
#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))

#define MON_TYPES(type1, ...) { type1, DEFAULT(type1, __VA_ARGS__) }
#define MON_EGG_GROUPS(group1, ...) { group1, DEFAULT(group1, __VA_ARGS__) }

#define FLIP    0
#define NO_FLIP 1

const struct SpeciesInfo gSpeciesInfo[] =
{
    [SPECIES_NONE] =
    {
        .speciesName = _("??????????"),
        .cryId = CRY_PORYGON,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = gFallbackPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(QuestionMark)
        SHADOW(-1, 0, SHADOW_SIZE_M)
    #if OW_POKEMON_OBJECT_EVENTS
        .overworldData = {
            .tileTag = TAG_NONE,
            .paletteTag = OBJ_EVENT_PAL_TAG_SUBSTITUTE,
            .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,
            .size = 512,
            .width = 32,
            .height = 32,
            .paletteSlot = PALSLOT_NPC_1,
            .shadowSize = SHADOW_SIZE_M,
            .inanimate = FALSE,
            .compressed = COMP,
            .tracks = TRACKS_FOOT,
            .oam = &gObjectEventBaseOam_32x32,
            .subspriteTables = sOamTables_32x32,
            .anims = sAnimTable_Following,
            .images = sPicTable_Substitute,
        },
    #endif
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .eggMoveLearnset = sNoneEggMoveLearnset,
    },

    #include "species_info/gen_1_families.h"
    #include "species_info/gen_2_families.h"
    #include "species_info/gen_3_families.h"
    #include "species_info/gen_4_families.h"
    #include "species_info/gen_5_families.h"
    #include "species_info/gen_6_families.h"
    #include "species_info/gen_7_families.h"
    #include "species_info/gen_8_families.h"
    #include "species_info/gen_9_families.h"

    [SPECIES_EGG] =
    {
        .frontPic = gMonFrontPic_Egg,
        .frontPicSize = MON_COORDS_SIZE(24, 24),
        .frontPicYOffset = 20,
        .backPic = gMonFrontPic_Egg,
        .backPicSize = MON_COORDS_SIZE(24, 24),
        .backPicYOffset = 20,
        .palette = gMonPalette_Egg,
        .shinyPalette = gMonPalette_Egg,
        .iconSprite = gMonIcon_Egg,
        .iconPalIndex = 1,
    },

    /* You may add any custom species below this point based on the following structure: */

    [SPECIES_GULPIN_NORMAL] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_NORMAL),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_NORMAL}),
    },

    [SPECIES_GULPIN_FIGHTING] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_FIGHTING),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_FIGHTING}),
    },

    [SPECIES_GULPIN_FLYING] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_FLYING),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_FLYING}),
    },

    [SPECIES_GULPIN_GROUND] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_GROUND),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_GROUND}),
    },

    [SPECIES_GULPIN_ROCK] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_ROCK),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_ROCK}),
    },

        [SPECIES_GULPIN_BUG] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_BUG),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_BUG}),
    },

        [SPECIES_GULPIN_GHOST] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_GHOST),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_GHOST}),
    },

        [SPECIES_GULPIN_STEEL] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_STEEL),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_STEEL}),
    },

    [SPECIES_GULPIN_FIRE] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_FIRE),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_FIRE}),
    },

    [SPECIES_GULPIN_WATER] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_WATER),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_WATER}),
    },

    [SPECIES_GULPIN_GRASS] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_GRASS),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_GRASS}),
    },

    [SPECIES_GULPIN_ELECTRIC] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_ELECTRIC),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_ELECTRIC}),
    },

    [SPECIES_GULPIN_PSYCHIC] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_PSYCHIC),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_PSYCHIC}),
    },

    [SPECIES_GULPIN_ICE] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_ICE),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_ICE}),
    },

    [SPECIES_GULPIN_DRAGON] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_DRAGON),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_DRAGON}),
    },

    [SPECIES_GULPIN_DARK] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_DARK),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_DARK}),
    },

    [SPECIES_GULPIN_FAIRY] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON, TYPE_FAIRY),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Gulpin"),
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
        .categoryName = _("Stomach"),
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SWALOT_FAIRY}),
    },

    [SPECIES_SWALOT_NORMAL] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_NORMAL),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_NORMAL}), // Ambrosia
    },

    [SPECIES_SWALOT_FIGHTING] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_FIGHTING),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_FIGHTING}), // Ambrosia
    },

    [SPECIES_SWALOT_FLYING] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_FLYING),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_FLYING}), // Ambrosia
    },

    [SPECIES_SWALOT_GROUND] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_GROUND),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_GROUND}), // Ambrosia
    },

    [SPECIES_SWALOT_ROCK] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_ROCK),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_ROCK}), // Ambrosia
    },

    [SPECIES_SWALOT_BUG] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_BUG),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_BUG}), // Ambrosia
    },

    [SPECIES_SWALOT_GHOST] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_GHOST),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_GHOST}), // Ambrosia
    },
    
    [SPECIES_SWALOT_STEEL] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_STEEL),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_STEEL}), // Ambrosia
    },

    [SPECIES_SWALOT_FIRE] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_FIRE),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_FIRE}), // Ambrosia
    },

    [SPECIES_SWALOT_WATER] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_WATER),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_WATER}), // Ambrosia
    },

    [SPECIES_SWALOT_GRASS] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_GRASS),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_GRASS}), // Ambrosia
    },

    [SPECIES_SWALOT_ELECTRIC] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_ELECTRIC),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_ELECTRIC}), // Ambrosia
    },

    [SPECIES_SWALOT_PSYCHIC] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_PSYCHIC),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_PSYCHIC}), // Ambrosia
    },

    [SPECIES_SWALOT_ICE] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_ICE),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_ICE}), // Ambrosia
    },

    [SPECIES_SWALOT_DRAGON] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_DRAGON),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_DRAGON}), // Ambrosia
    },

    [SPECIES_SWALOT_DARK] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_DARK),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_DARK}), // Ambrosia
    },

    [SPECIES_SWALOT_FAIRY] =
    {
        .baseHP        = 100,
        .baseAttack    = 83,
        .baseDefense   = 93,
        .baseSpeed     = 55,
        .baseSpAttack  = 83,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_POISON, TYPE_FAIRY),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_DROUGHT }, //Rending Tide
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Swalot"),
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
        .categoryName = _("Big Stomach"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
    #if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
    #endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VALVORIN_FAIRY}), // Ambrosia
    },

    /*
    [SPECIES_NONE] =
    {
        .baseHP        = 1,
        .baseAttack    = 1,
        .baseDefense   = 1,
        .baseSpeed     = 1,
        .baseSpAttack  = 1,
        .baseSpDefense = 1,
        .types = MON_TYPES(TYPE_MYSTERY),
        .catchRate = 255,
        .expYield = 67,
        .evYield_HP = 1,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_NONE, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("??????????"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_None,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_CircledQuestionMark,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_CircledQuestionMarkF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .paletteFemale = gMonPalette_CircledQuestionMarkF,
        .shinyPaletteFemale = gMonShinyPalette_CircledQuestionMarkF,
        .iconSpriteFemale = gMonIcon_QuestionMarkF,
        .iconPalIndexFemale = 1,
#endif //P_GENDER_DIFFERENCES
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        FOOTPRINT(QuestionMark)
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 100, SPECIES_NONE},
                                {EVO_ITEM, ITEM_MOOMOO_MILK, SPECIES_NONE}),
        //.formSpeciesIdTable = sNoneFormSpeciesIdTable,
        //.formChangeTable = sNoneFormChangeTable,
        //.perfectIVCount = NUM_STATS,
    },
    */
};

const struct EggData gEggDatas[EGG_ID_COUNT] =
{
#include "egg_data.h"
};

BersketCity_MapScripts::
# 3 "data/maps/BersketCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 4 "data/maps/BersketCity/scripts.pory"
	setflag FLAG_VISITED_BERSKET_CITY
# 5 "data/maps/BersketCity/scripts.pory"
	setflag FLAG_HIDE_RIVAL_BERSKETCITY
	return


BersketCity_EventScript_Guljira::
# 11 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Guljira_Text_0
# 12 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Guljira_Text_1
# 13 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Guljira_Text_2
# 14 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Guljira_Text_3
# 15 "data/maps/BersketCity/scripts.pory"
	closemessage
	end


BersketCity_EventScript_Rival::
# 20 "data/maps/BersketCity/scripts.pory"
	lockall
# 21 "data/maps/BersketCity/scripts.pory"
	opendoor 40, 31
# 22 "data/maps/BersketCity/scripts.pory"
	delay 10
# 23 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_PLAYER, BersketCity_Movement_StepAway
# 24 "data/maps/BersketCity/scripts.pory"
	waitmovement LOCALID_PLAYER
# 25 "data/maps/BersketCity/scripts.pory"
	delay 20
# 27 "data/maps/BersketCity/scripts.pory"
	checkplayergender
# 28 "data/maps/BersketCity/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq BersketCity_EventScript_Rival_2
# 31 "data/maps/BersketCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
BersketCity_EventScript_Rival_1:
# 34 "data/maps/BersketCity/scripts.pory"
	addobject LOCALID_BERSKET_CITY_GULPINATOR
# 35 "data/maps/BersketCity/scripts.pory"
	delay 10
# 36 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_BERSKET_CITY_GULPINATOR, Common_Movement_ExclamationMark
# 37 "data/maps/BersketCity/scripts.pory"
	playse SE_PIN
# 38 "data/maps/BersketCity/scripts.pory"
	waitmovement
# 39 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_BERSKET_CITY_GULPINATOR, BersketCity_Movement_GulpinatorEntrance
# 40 "data/maps/BersketCity/scripts.pory"
	delay 20
# 41 "data/maps/BersketCity/scripts.pory"
	addobject LOCALID_BERSKET_CITY_RIVAL
# 42 "data/maps/BersketCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 43 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_BERSKET_CITY_RIVAL, BersketCity_Movement_RivalEntrance
# 44 "data/maps/BersketCity/scripts.pory"
	waitmovement LOCALID_BERSKET_CITY_GULPINATOR
# 45 "data/maps/BersketCity/scripts.pory"
	waitmovement LOCALID_BERSKET_CITY_RIVAL
# 46 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Rival_Text_0
# 47 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Rival_Text_1
# 49 "data/maps/BersketCity/scripts.pory"
	checkplayergender
# 50 "data/maps/BersketCity/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq BersketCity_EventScript_Rival_6
# 67 "data/maps/BersketCity/scripts.pory"
	switch VAR_STARTER_MON
# 68 "data/maps/BersketCity/scripts.pory"
	case 0, BersketCity_EventScript_Rival_14
# 72 "data/maps/BersketCity/scripts.pory"
	case 1, BersketCity_EventScript_Rival_15
# 76 "data/maps/BersketCity/scripts.pory"
	case 2, BersketCity_EventScript_Rival_16
BersketCity_EventScript_Rival_5:
# 82 "data/maps/BersketCity/scripts.pory"
	call BersketCity_EventScript_RivalDefeated
	return

BersketCity_EventScript_Rival_2:
# 29 "data/maps/BersketCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
	goto BersketCity_EventScript_Rival_1

BersketCity_EventScript_Rival_6:
# 51 "data/maps/BersketCity/scripts.pory"
	switch VAR_STARTER_MON
# 52 "data/maps/BersketCity/scripts.pory"
	case 0, BersketCity_EventScript_Rival_10
# 56 "data/maps/BersketCity/scripts.pory"
	case 1, BersketCity_EventScript_Rival_11
# 60 "data/maps/BersketCity/scripts.pory"
	case 2, BersketCity_EventScript_Rival_12
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_10:
# 53 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_TREECKO, BersketCity_Text_MayDefeat
# 54 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_MAY_TREECKO
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_11:
# 57 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_TORCHIC, BersketCity_Text_MayDefeat
# 58 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_MAY_TORCHIC
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_12:
# 61 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_MUDKIP, BersketCity_Text_MayDefeat
# 62 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_MAY_MUDKIP
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_14:
# 69 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_TREECKO, BersketCity_Text_BrendanDefeat
# 70 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_BRENDAN_TREECKO
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_15:
# 73 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_TORCHIC, BersketCity_Text_BrendanDefeat
# 74 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_BRENDAN_TORCHIC
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_16:
# 77 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_MUDKIP, BersketCity_Text_BrendanDefeat
# 78 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_BRENDAN_MUDKIP
	goto BersketCity_EventScript_Rival_5


BersketCity_EventScript_RivalDefeated::
# 86 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_0
# 87 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_1
# 88 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_2
# 89 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_3
# 90 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_4
# 91 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_5
# 92 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_6
# 93 "data/maps/BersketCity/scripts.pory"
	closemessage
# 94 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_BERSKET_CITY_GULPINATOR, BersketCity_Movement_GulpinatorExit
# 95 "data/maps/BersketCity/scripts.pory"
	delay 3
# 96 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_BERSKET_CITY_RIVAL, BersketCity_Movement_RivalExit
# 97 "data/maps/BersketCity/scripts.pory"
	waitmovement LOCALID_BERSKET_CITY_GULPINATOR
# 98 "data/maps/BersketCity/scripts.pory"
	waitmovement LOCALID_BERSKET_CITY_RIVAL
# 99 "data/maps/BersketCity/scripts.pory"
	removeobject LOCALID_BERSKET_CITY_GULPINATOR
# 100 "data/maps/BersketCity/scripts.pory"
	removeobject LOCALID_BERSKET_CITY_RIVAL
# 101 "data/maps/BersketCity/scripts.pory"
	setflag FLAG_HIDE_RIVAL_BERSKETCITY
# 102 "data/maps/BersketCity/scripts.pory"
	setvar VAR_BERSKET_CITY_STATE, 1
# 103 "data/maps/BersketCity/scripts.pory"
	fadedefaultbgm
# 104 "data/maps/BersketCity/scripts.pory"
	releaseall
	end


# 108 "data/maps/BersketCity/scripts.pory"
BersketCity_Movement_StepAway:
# 109 "data/maps/BersketCity/scripts.pory"
	face_up
# 110 "data/maps/BersketCity/scripts.pory"
	lock_facing_direction
# 111 "data/maps/BersketCity/scripts.pory"
	walk_down
# 112 "data/maps/BersketCity/scripts.pory"
	unlock_facing_direction
# 113 "data/maps/BersketCity/scripts.pory"
	face_up
	step_end

# 116 "data/maps/BersketCity/scripts.pory"
BersketCity_Movement_GulpinatorEntrance:
# 117 "data/maps/BersketCity/scripts.pory"
	walk_down
# 118 "data/maps/BersketCity/scripts.pory"
	walk_right
# 119 "data/maps/BersketCity/scripts.pory"
	face_down
	step_end

# 122 "data/maps/BersketCity/scripts.pory"
BersketCity_Movement_RivalEntrance:
# 123 "data/maps/BersketCity/scripts.pory"
	walk_down
	step_end

# 126 "data/maps/BersketCity/scripts.pory"
BersketCity_Movement_GulpinatorExit:
# 127 "data/maps/BersketCity/scripts.pory"
	walk_fast_down
# 127 "data/maps/BersketCity/scripts.pory"
	walk_fast_down
# 128 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 128 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 128 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 128 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 128 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 128 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 128 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 128 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 128 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 128 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
	step_end

# 131 "data/maps/BersketCity/scripts.pory"
BersketCity_Movement_RivalExit:
# 132 "data/maps/BersketCity/scripts.pory"
	walk_right
# 133 "data/maps/BersketCity/scripts.pory"
	walk_down
# 134 "data/maps/BersketCity/scripts.pory"
	walk_fast_down
# 135 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 135 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 135 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 135 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 135 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 135 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 135 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 135 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 135 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 135 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
	step_end

BersketCity_EventScript_Guljira_Text_0:
# 11 "data/maps/BersketCity/scripts.pory"
	.string "Hey, I'm hungry. Do you have any food?$"

BersketCity_EventScript_Guljira_Text_1:
# 12 "data/maps/BersketCity/scripts.pory"
	.string "Lips: Oh no!\n What happened?$"

BersketCity_EventScript_Guljira_Text_2:
# 13 "data/maps/BersketCity/scripts.pory"
	.string "No food.$"

BersketCity_EventScript_Guljira_Text_3:
# 14 "data/maps/BersketCity/scripts.pory"
	.string "Lips: Something must have gone wrong.\n"
	.string "This is bad.\p"
	.string "{PLAYER}, this is Guljira. He's our\n"
	.string "leader.\p"
	.string "But he's supposed to have special food\n"
	.string "from the forest. Without it, the hunger\l"
	.string "is too much, and his great wisdom is\l"
	.string "gone.\p"
	.string "We need to talk to the professor.$"

BersketCity_EventScript_Rival_Text_0:
# 46 "data/maps/BersketCity/scripts.pory"
	.string "{RIVAL}: {PLAYER}! You're finally\n"
	.string "here. Just in time.$"

BersketCity_EventScript_Rival_Text_1:
# 47 "data/maps/BersketCity/scripts.pory"
	.string "Gulpinator: Behold my true form!$"

BersketCity_EventScript_RivalDefeated_Text_0:
# 86 "data/maps/BersketCity/scripts.pory"
	.string "{RIVAL}: Looks like my dad was right\n"
	.string "to give you that Pokémon. Seeing you, I\l"
	.string "get the feeling you could befriend any\l"
	.string "Pokémon with ease.$"

BersketCity_EventScript_RivalDefeated_Text_1:
# 87 "data/maps/BersketCity/scripts.pory"
	.string "Gulpinator: And you have a Gulpin\n"
	.string "friend! Nice!$"

BersketCity_EventScript_RivalDefeated_Text_2:
# 88 "data/maps/BersketCity/scripts.pory"
	.string "Lips: Hi.\n"
	.string "So you must've eaten the Steel berry.\p"
	.string "Wow.\p"
	.string "That's kind of gross.$"

BersketCity_EventScript_RivalDefeated_Text_3:
# 89 "data/maps/BersketCity/scripts.pory"
	.string "Gulpinator: Better than the Normal\n"
	.string "berry!$"

BersketCity_EventScript_RivalDefeated_Text_4:
# 90 "data/maps/BersketCity/scripts.pory"
	.string "Lips: So why'd you lose then?$"

BersketCity_EventScript_RivalDefeated_Text_5:
# 91 "data/maps/BersketCity/scripts.pory"
	.string "{RIVAL}: Alright, we've gotta go.\n"
	.string "We're heading to Rustboro to learn this\l"
	.string "'Engram' thing.\p"
	.string "Maybe the Professors will give you a\n"
	.string "copy too.\p"
	.string "And we're off!$"

BersketCity_EventScript_RivalDefeated_Text_6:
# 92 "data/maps/BersketCity/scripts.pory"
	.string "Gulpinator: Taste ya later!$"

BersketCity_Text_BrendanDefeat::
# 138 "data/maps/BersketCity/scripts.pory"
	.string "Wow! That's great!\n"
	.string "{PLAYER}, you're pretty good!$"

BersketCity_Text_MayDefeat::
# 143 "data/maps/BersketCity/scripts.pory"
	.string "Wow! That's great!\n"
	.string "{PLAYER}, you're pretty good!$"

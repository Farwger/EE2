BersketCity_MapScripts::
# 22 "data/maps/BersketCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

BersketCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 23 "data/maps/BersketCity/scripts.pory"
	setflag FLAG_VISITED_BERSKET_CITY
# 24 "data/maps/BersketCity/scripts.pory"
	setflag FLAG_HIDE_RIVAL_BERSKETCITY
# 25 "data/maps/BersketCity/scripts.pory"
	setvar VAR_BERSKET_CITY_STATE, 1
# 26 "data/maps/BersketCity/scripts.pory"
	setflag FLAG_BADGE01_GET
	return


BersketCity_EventScript_Guljira::
# 34 "data/maps/BersketCity/scripts.pory"
	compare VAR_BERSKET_CITY_STATE, 11
	goto_if_lt BersketCity_EventScript_Guljira_1
	return

BersketCity_EventScript_Guljira_1:
# 35 "data/maps/BersketCity/scripts.pory"
	playmoncry SPECIES_GULPIN, 0
# 36 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Guljira_Text_0
# 39 "data/maps/BersketCity/scripts.pory"
	compare VAR_BERSKET_CITY_STATE, 2
	goto_if_lt BersketCity_EventScript_Guljira_3
# 47 "data/maps/BersketCity/scripts.pory"
	compare VAR_BERSKET_CITY_STATE, 3
	goto_if_lt BersketCity_EventScript_Guljira_4
	return

BersketCity_EventScript_Guljira_3:
# 40 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Guljira_Text_1
# 41 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Guljira_Text_2
# 42 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Guljira_Text_3
# 43 "data/maps/BersketCity/scripts.pory"
	closemessage
	end

BersketCity_EventScript_Guljira_4:
# 48 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Guljira_Text_4
# 49 "data/maps/BersketCity/scripts.pory"
	closemessage
	end


BersketCity_EventScript_Rival::
# 58 "data/maps/BersketCity/scripts.pory"
	lockall
# 59 "data/maps/BersketCity/scripts.pory"
	opendoor 40, 31
# 60 "data/maps/BersketCity/scripts.pory"
	delay 10
# 61 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_PLAYER, BersketCity_Movement_StepAway
# 62 "data/maps/BersketCity/scripts.pory"
	waitmovement LOCALID_PLAYER
# 63 "data/maps/BersketCity/scripts.pory"
	delay 20
# 65 "data/maps/BersketCity/scripts.pory"
	checkplayergender
# 66 "data/maps/BersketCity/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq BersketCity_EventScript_Rival_2
# 69 "data/maps/BersketCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
BersketCity_EventScript_Rival_1:
# 72 "data/maps/BersketCity/scripts.pory"
	addobject LOCALID_BERSKET_CITY_GULPINATOR
# 73 "data/maps/BersketCity/scripts.pory"
	delay 10
# 74 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_BERSKET_CITY_GULPINATOR, Common_Movement_ExclamationMark
# 75 "data/maps/BersketCity/scripts.pory"
	playse SE_PIN
# 76 "data/maps/BersketCity/scripts.pory"
	waitmovement
# 77 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_BERSKET_CITY_GULPINATOR, BersketCity_Movement_GulpinatorEntrance
# 78 "data/maps/BersketCity/scripts.pory"
	delay 20
# 79 "data/maps/BersketCity/scripts.pory"
	addobject LOCALID_BERSKET_CITY_RIVAL
# 80 "data/maps/BersketCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 81 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_BERSKET_CITY_RIVAL, BersketCity_Movement_RivalEntrance
# 82 "data/maps/BersketCity/scripts.pory"
	waitmovement LOCALID_BERSKET_CITY_GULPINATOR
# 83 "data/maps/BersketCity/scripts.pory"
	waitmovement LOCALID_BERSKET_CITY_RIVAL
# 84 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Rival_Text_0
# 85 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Rival_Text_1
# 87 "data/maps/BersketCity/scripts.pory"
	checkplayergender
# 88 "data/maps/BersketCity/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq BersketCity_EventScript_Rival_6
# 105 "data/maps/BersketCity/scripts.pory"
	switch VAR_STARTER_MON
# 106 "data/maps/BersketCity/scripts.pory"
	case 0, BersketCity_EventScript_Rival_14
# 110 "data/maps/BersketCity/scripts.pory"
	case 1, BersketCity_EventScript_Rival_15
# 114 "data/maps/BersketCity/scripts.pory"
	case 2, BersketCity_EventScript_Rival_16
BersketCity_EventScript_Rival_5:
# 120 "data/maps/BersketCity/scripts.pory"
	call BersketCity_EventScript_RivalDefeated
	return

BersketCity_EventScript_Rival_2:
# 67 "data/maps/BersketCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
	goto BersketCity_EventScript_Rival_1

BersketCity_EventScript_Rival_6:
# 89 "data/maps/BersketCity/scripts.pory"
	switch VAR_STARTER_MON
# 90 "data/maps/BersketCity/scripts.pory"
	case 0, BersketCity_EventScript_Rival_10
# 94 "data/maps/BersketCity/scripts.pory"
	case 1, BersketCity_EventScript_Rival_11
# 98 "data/maps/BersketCity/scripts.pory"
	case 2, BersketCity_EventScript_Rival_12
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_10:
# 91 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_TREECKO, BersketCity_Text_MayDefeat
# 92 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_MAY_TREECKO
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_11:
# 95 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_TORCHIC, BersketCity_Text_MayDefeat
# 96 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_MAY_TORCHIC
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_12:
# 99 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_MUDKIP, BersketCity_Text_MayDefeat
# 100 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_MAY_MUDKIP
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_14:
# 107 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_TREECKO, BersketCity_Text_BrendanDefeat
# 108 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_BRENDAN_TREECKO
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_15:
# 111 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_TORCHIC, BersketCity_Text_BrendanDefeat
# 112 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_BRENDAN_TORCHIC
	goto BersketCity_EventScript_Rival_5

BersketCity_EventScript_Rival_16:
# 115 "data/maps/BersketCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_MUDKIP, BersketCity_Text_BrendanDefeat
# 116 "data/maps/BersketCity/scripts.pory"
	clearflag TRAINER_BRENDAN_MUDKIP
	goto BersketCity_EventScript_Rival_5


BersketCity_EventScript_RivalDefeated::
# 124 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_0
# 125 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_1
# 126 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_2
# 127 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_3
# 128 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_4
# 129 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_5
# 130 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_RivalDefeated_Text_6
# 131 "data/maps/BersketCity/scripts.pory"
	closemessage
# 132 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_BERSKET_CITY_GULPINATOR, BersketCity_Movement_GulpinatorExit
# 133 "data/maps/BersketCity/scripts.pory"
	delay 3
# 134 "data/maps/BersketCity/scripts.pory"
	applymovement LOCALID_BERSKET_CITY_RIVAL, BersketCity_Movement_RivalExit
# 135 "data/maps/BersketCity/scripts.pory"
	waitmovement LOCALID_BERSKET_CITY_GULPINATOR
# 136 "data/maps/BersketCity/scripts.pory"
	waitmovement LOCALID_BERSKET_CITY_RIVAL
# 137 "data/maps/BersketCity/scripts.pory"
	removeobject LOCALID_BERSKET_CITY_GULPINATOR
# 138 "data/maps/BersketCity/scripts.pory"
	removeobject LOCALID_BERSKET_CITY_RIVAL
# 139 "data/maps/BersketCity/scripts.pory"
	setflag FLAG_HIDE_RIVAL_BERSKETCITY
# 140 "data/maps/BersketCity/scripts.pory"
	setvar VAR_BERSKET_CITY_STATE, 1
# 141 "data/maps/BersketCity/scripts.pory"
	fadedefaultbgm
# 142 "data/maps/BersketCity/scripts.pory"
	releaseall
	end


# 146 "data/maps/BersketCity/scripts.pory"
BersketCity_Movement_StepAway:
# 147 "data/maps/BersketCity/scripts.pory"
	face_up
# 148 "data/maps/BersketCity/scripts.pory"
	lock_facing_direction
# 149 "data/maps/BersketCity/scripts.pory"
	walk_down
# 150 "data/maps/BersketCity/scripts.pory"
	unlock_facing_direction
# 151 "data/maps/BersketCity/scripts.pory"
	face_up
	step_end

# 154 "data/maps/BersketCity/scripts.pory"
BersketCity_Movement_GulpinatorEntrance:
# 155 "data/maps/BersketCity/scripts.pory"
	walk_down
# 156 "data/maps/BersketCity/scripts.pory"
	walk_right
# 157 "data/maps/BersketCity/scripts.pory"
	face_down
	step_end

# 160 "data/maps/BersketCity/scripts.pory"
BersketCity_Movement_RivalEntrance:
# 161 "data/maps/BersketCity/scripts.pory"
	walk_down
	step_end

# 164 "data/maps/BersketCity/scripts.pory"
BersketCity_Movement_GulpinatorExit:
# 165 "data/maps/BersketCity/scripts.pory"
	walk_fast_down
# 165 "data/maps/BersketCity/scripts.pory"
	walk_fast_down
# 166 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 166 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 166 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 166 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 166 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 166 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 166 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 166 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 166 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 166 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
	step_end

# 169 "data/maps/BersketCity/scripts.pory"
BersketCity_Movement_RivalExit:
# 170 "data/maps/BersketCity/scripts.pory"
	walk_right
# 171 "data/maps/BersketCity/scripts.pory"
	walk_down
# 172 "data/maps/BersketCity/scripts.pory"
	walk_fast_down
# 173 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 173 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 173 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 173 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 173 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 173 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 173 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 173 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 173 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
# 173 "data/maps/BersketCity/scripts.pory"
	walk_fast_left
	step_end

BersketCity_EventScript_CitySign::
# 188 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_CitySign_Text_0, MSGBOX_SIGN
	end


BersketCity_EventScript_LabSign::
# 193 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_LabSign_Text_0, MSGBOX_SIGN
# 194 "data/maps/BersketCity/scripts.pory"
	giveitem ITEM_TM_THUNDERBOLT
	end


BersketCity_EventScript_Resteraunt::
# 199 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_Resteraunt_Text_0, MSGBOX_SIGN
	end


BersketCity_EventScript_FoodStorage::
# 204 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_FoodStorage_Text_0, MSGBOX_SIGN
	end


BersketCity_EventScript_ResturketSign::
# 209 "data/maps/BersketCity/scripts.pory"
	msgbox BersketCity_EventScript_ResturketSign_Text_0, MSGBOX_SIGN
	end


BersketCity_EventScript_Guljira_Text_0:
# 36 "data/maps/BersketCity/scripts.pory"
	.string "GUUUULLLLLP\p"
	.string "Hey, I'm hungry. Do you have any food?$"

BersketCity_EventScript_Guljira_Text_1:
# 40 "data/maps/BersketCity/scripts.pory"
	.string "Lips: Oh no!\nWhat's happened?$"

BersketCity_EventScript_Guljira_Text_2:
# 41 "data/maps/BersketCity/scripts.pory"
	.string "No food.\nGulp.$"

BersketCity_EventScript_Guljira_Text_3:
# 42 "data/maps/BersketCity/scripts.pory"
	.string "Lips: Something must have gone wrong.\n"
	.string "This is bad.\p"
	.string "{PLAYER}, this is Guljira. He's our\n"
	.string "leader.\p"
	.string "But he's supposed to have special food\n"
	.string "from the forest. Without it, the hunger\l"
	.string "is too much, and his great wisdom is\l"
	.string "gone.\p"
	.string "We need to talk to the professors.$"

BersketCity_EventScript_Guljira_Text_4:
# 48 "data/maps/BersketCity/scripts.pory"
	.string "Lips: Don't worry! We're going to get\n"
	.string "you food. We just need to go to\l"
	.string "Rustboro first. We'll be quick.$"

BersketCity_EventScript_Rival_Text_0:
# 84 "data/maps/BersketCity/scripts.pory"
	.string "{RIVAL}: {PLAYER}! You're finally\n"
	.string "here. Just in time.$"

BersketCity_EventScript_Rival_Text_1:
# 85 "data/maps/BersketCity/scripts.pory"
	.string "Gulpinator: Behold my true form!$"

BersketCity_EventScript_RivalDefeated_Text_0:
# 124 "data/maps/BersketCity/scripts.pory"
	.string "{RIVAL}: Looks like my dad was right\n"
	.string "to give you that Pokémon. Seeing you, I\l"
	.string "get the feeling you could befriend any\l"
	.string "Pokémon with ease.$"

BersketCity_EventScript_RivalDefeated_Text_1:
# 125 "data/maps/BersketCity/scripts.pory"
	.string "Gulpinator: And you have a Gulpin\n"
	.string "friend! Nice!$"

BersketCity_EventScript_RivalDefeated_Text_2:
# 126 "data/maps/BersketCity/scripts.pory"
	.string "Lips: Hi.\n"
	.string "So you must've eaten the Steel berry.\p"
	.string "Wow.\p"
	.string "That's kind of gross.$"

BersketCity_EventScript_RivalDefeated_Text_3:
# 127 "data/maps/BersketCity/scripts.pory"
	.string "Gulpinator: Better than the Normal\n"
	.string "berry!$"

BersketCity_EventScript_RivalDefeated_Text_4:
# 128 "data/maps/BersketCity/scripts.pory"
	.string "Lips: So why'd you lose then?$"

BersketCity_EventScript_RivalDefeated_Text_5:
# 129 "data/maps/BersketCity/scripts.pory"
	.string "{RIVAL}: Alright, we've gotta go.\n"
	.string "We're heading to Rustboro to learn this\l"
	.string "'Engram' thing.\p"
	.string "Maybe the Professors will give you a\n"
	.string "copy too.\p"
	.string "And we're off!$"

BersketCity_EventScript_RivalDefeated_Text_6:
# 130 "data/maps/BersketCity/scripts.pory"
	.string "Gulpinator: Taste ya later!$"

BersketCity_EventScript_CitySign_Text_0:
# 188 "data/maps/BersketCity/scripts.pory"
	.string "Bersket City\p“The berry-basket of Hoenn.“$"

BersketCity_EventScript_LabSign_Text_0:
# 193 "data/maps/BersketCity/scripts.pory"
	.string "Professor Jacuzzi's lab.$"

BersketCity_EventScript_Resteraunt_Text_0:
# 199 "data/maps/BersketCity/scripts.pory"
	.string "Resteraunt.$"

BersketCity_EventScript_FoodStorage_Text_0:
# 204 "data/maps/BersketCity/scripts.pory"
	.string "Bersket food storage.$"

BersketCity_EventScript_ResturketSign_Text_0:
# 209 "data/maps/BersketCity/scripts.pory"
	.string "Resturket Tunnel\n"
	.string "Linking Bersket, Rustboro, and\l"
	.string "Verdanturf.$"

BersketCity_Text_BrendanDefeat::
# 176 "data/maps/BersketCity/scripts.pory"
	.string "Wow! That's great!\n"
	.string "{PLAYER}, you're pretty good!$"

BersketCity_Text_MayDefeat::
# 181 "data/maps/BersketCity/scripts.pory"
	.string "Wow! That's great!\n"
	.string "{PLAYER}, you're pretty good!$"

BersketCity_Lab_MapScripts::
	.byte 0


BersketCity_Lab_EventScript_PC::
# 6 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_PC_Text_0, MSGBOX_SIGN
	end


BersketCity_Lab_EventScript_Bookcase::
# 11 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Bookcase_Text_0, MSGBOX_SIGN
	end


BersketCity_Lab_EventScript_Machine::
# 16 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Machine_Text_0, MSGBOX_SIGN
	end


BersketCity_Lab_EventScript_ProfJacuzzi::
# 25 "data/maps/BersketCity_Lab/scripts.pory"
	lockall
# 26 "data/maps/BersketCity_Lab/scripts.pory"
	faceplayer
# 27 "data/maps/BersketCity_Lab/scripts.pory"
	setvar VAR_0x8004, 0
# 30 "data/maps/BersketCity_Lab/scripts.pory"
	compare VAR_BERSKET_CITY_STATE, 2
	goto_if_ge BersketCity_Lab_EventScript_ProfJacuzzi_2
# 42 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfJacuzzi_Text_2
# 43 "data/maps/BersketCity_Lab/scripts.pory"
	closemessage
# 44 "data/maps/BersketCity_Lab/scripts.pory"
	switch VAR_FACING
# 45 "data/maps/BersketCity_Lab/scripts.pory"
	case DIR_NORTH, BersketCity_Lab_EventScript_ProfJacuzzi_6
# 47 "data/maps/BersketCity_Lab/scripts.pory"
	case DIR_WEST, BersketCity_Lab_EventScript_ProfJacuzzi_7
# 49 "data/maps/BersketCity_Lab/scripts.pory"
	case DIR_EAST, BersketCity_Lab_EventScript_ProfJacuzzi_8
BersketCity_Lab_EventScript_ProfJacuzzi_4:
# 52 "data/maps/BersketCity_Lab/scripts.pory"
	waitmovement LOCALID_BERSKET_LAB_SYRUP
# 53 "data/maps/BersketCity_Lab/scripts.pory"
	delay 5
# 54 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfJacuzzi_Text_3
# 55 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfJacuzzi_Text_4
# 56 "data/maps/BersketCity_Lab/scripts.pory"
	call BersketCity_Lab_EventScript_Profs
	return

BersketCity_Lab_EventScript_ProfJacuzzi_2:
# 31 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfJacuzzi_Text_0, MSGBOX_YESNO
# 32 "data/maps/BersketCity_Lab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BersketCity_Lab_EventScript_ProfJacuzzi_10
BersketCity_Lab_EventScript_ProfJacuzzi_9:
# 35 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfJacuzzi_Text_1
# 36 "data/maps/BersketCity_Lab/scripts.pory"
	closemessage
# 37 "data/maps/BersketCity_Lab/scripts.pory"
	releaseall
	end

BersketCity_Lab_EventScript_ProfJacuzzi_6:
# 46 "data/maps/BersketCity_Lab/scripts.pory"
	applymovement LOCALID_BERSKET_LAB_SYRUP, BersketCity_Lab_Movement_SyrupApproach1
	goto BersketCity_Lab_EventScript_ProfJacuzzi_4

BersketCity_Lab_EventScript_ProfJacuzzi_7:
# 48 "data/maps/BersketCity_Lab/scripts.pory"
	applymovement LOCALID_BERSKET_LAB_SYRUP, BersketCity_Lab_Movement_SyrupApproach2
	goto BersketCity_Lab_EventScript_ProfJacuzzi_4

BersketCity_Lab_EventScript_ProfJacuzzi_8:
# 50 "data/maps/BersketCity_Lab/scripts.pory"
	applymovement LOCALID_BERSKET_LAB_SYRUP, BersketCity_Lab_Movement_SyrupApproach3
	goto BersketCity_Lab_EventScript_ProfJacuzzi_4

BersketCity_Lab_EventScript_ProfJacuzzi_10:
# 33 "data/maps/BersketCity_Lab/scripts.pory"
	call BersketCity_Lab_EventScript_ProfQuestions
	goto BersketCity_Lab_EventScript_ProfJacuzzi_9


BersketCity_Lab_EventScript_ProfSyrup::
# 64 "data/maps/BersketCity_Lab/scripts.pory"
	lockall
# 65 "data/maps/BersketCity_Lab/scripts.pory"
	faceplayer
# 66 "data/maps/BersketCity_Lab/scripts.pory"
	setvar VAR_0x8004, 1
# 69 "data/maps/BersketCity_Lab/scripts.pory"
	compare VAR_BERSKET_CITY_STATE, 2
	goto_if_ge BersketCity_Lab_EventScript_ProfSyrup_2
# 81 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfSyrup_Text_0
# 82 "data/maps/BersketCity_Lab/scripts.pory"
	closemessage
# 83 "data/maps/BersketCity_Lab/scripts.pory"
	switch VAR_FACING
# 84 "data/maps/BersketCity_Lab/scripts.pory"
	case DIR_NORTH, BersketCity_Lab_EventScript_ProfSyrup_6
# 88 "data/maps/BersketCity_Lab/scripts.pory"
	case DIR_EAST, BersketCity_Lab_EventScript_ProfSyrup_7
BersketCity_Lab_EventScript_ProfSyrup_4:
# 91 "data/maps/BersketCity_Lab/scripts.pory"
	waitmovement LOCALID_BERSKET_LAB_JACUZZI
# 92 "data/maps/BersketCity_Lab/scripts.pory"
	delay 5
# 93 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfJacuzzi_Text_2
# 94 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfSyrup_Text_1
# 95 "data/maps/BersketCity_Lab/scripts.pory"
	call BersketCity_Lab_EventScript_Profs
	return

BersketCity_Lab_EventScript_ProfSyrup_2:
# 70 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfJacuzzi_Text_0, MSGBOX_YESNO
# 71 "data/maps/BersketCity_Lab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BersketCity_Lab_EventScript_ProfSyrup_9
BersketCity_Lab_EventScript_ProfSyrup_8:
# 74 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfJacuzzi_Text_1
# 75 "data/maps/BersketCity_Lab/scripts.pory"
	closemessage
# 76 "data/maps/BersketCity_Lab/scripts.pory"
	releaseall
	end

BersketCity_Lab_EventScript_ProfSyrup_6:
# 85 "data/maps/BersketCity_Lab/scripts.pory"
	applymovement LOCALID_BERSKET_LAB_JACUZZI, BersketCity_Lab_Movement_JacuzziApproach
# 86 "data/maps/BersketCity_Lab/scripts.pory"
	waitmovement LOCALID_BERSKET_LAB_JACUZZI
# 87 "data/maps/BersketCity_Lab/scripts.pory"
	applymovement LOCALID_BERSKET_LAB_JACUZZI, Common_Movement_WalkInPlaceFasterRight
	goto BersketCity_Lab_EventScript_ProfSyrup_4

BersketCity_Lab_EventScript_ProfSyrup_7:
# 89 "data/maps/BersketCity_Lab/scripts.pory"
	applymovement LOCALID_BERSKET_LAB_JACUZZI, BersketCity_Lab_Movement_JacuzziApproach
	goto BersketCity_Lab_EventScript_ProfSyrup_4

BersketCity_Lab_EventScript_ProfSyrup_9:
# 72 "data/maps/BersketCity_Lab/scripts.pory"
	call BersketCity_Lab_EventScript_ProfQuestions
	goto BersketCity_Lab_EventScript_ProfSyrup_8


BersketCity_Lab_EventScript_Profs::
# 104 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_0
# 105 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_1
# 106 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_2
# 107 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_3
# 108 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_4
# 109 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_5
# 110 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_6
# 111 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_7
# 112 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_8
# 113 "data/maps/BersketCity_Lab/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
# 114 "data/maps/BersketCity_Lab/scripts.pory"
	waitmovement LOCALID_PLAYER
# 115 "data/maps/BersketCity_Lab/scripts.pory"
	delay 30
# 116 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_9
# 117 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_10
# 118 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_11
# 119 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_12
# 121 "data/maps/BersketCity_Lab/scripts.pory"
	goto_if_unset FLAG_BADGE01_GET, BersketCity_Lab_EventScript_Profs_2
# 129 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_17
# 130 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_14
# 131 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_15
# 132 "data/maps/BersketCity_Lab/scripts.pory"
	giveitem ITEM_ENGRAM_CUT, 1
# 133 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_18
BersketCity_Lab_EventScript_Profs_1:
# 135 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_19, MSGBOX_YESNO
# 136 "data/maps/BersketCity_Lab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq BersketCity_Lab_EventScript_Profs_6
BersketCity_Lab_EventScript_Profs_5:
# 139 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_20
# 140 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_21
# 141 "data/maps/BersketCity_Lab/scripts.pory"
	closemessage
# 142 "data/maps/BersketCity_Lab/scripts.pory"
	setvar VAR_BERSKET_CITY_STATE, 2
# 143 "data/maps/BersketCity_Lab/scripts.pory"
	releaseall
	end

BersketCity_Lab_EventScript_Profs_2:
# 122 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_13
# 123 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_14
# 124 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_15
# 125 "data/maps/BersketCity_Lab/scripts.pory"
	giveitem ITEM_ENGRAM_CUT, 1
# 126 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_Profs_Text_16
	goto BersketCity_Lab_EventScript_Profs_1

BersketCity_Lab_EventScript_Profs_6:
# 137 "data/maps/BersketCity_Lab/scripts.pory"
	call BersketCity_Lab_EventScript_ProfQuestions
	goto BersketCity_Lab_EventScript_Profs_5


BersketCity_Lab_EventScript_ProfQuestions::
# 153 "data/maps/BersketCity_Lab/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq BersketCity_Lab_EventScript_ProfQuestions_2
BersketCity_Lab_EventScript_ProfQuestions_1:
# 158 "data/maps/BersketCity_Lab/scripts.pory"
	multichoicedefault 20, 8, MULTI_BERSKETPROFS_QUESTIONS, 0, FALSE
# 159 "data/maps/BersketCity_Lab/scripts.pory"
	switch VAR_RESULT
# 160 "data/maps/BersketCity_Lab/scripts.pory"
	case 0, BersketCity_Lab_EventScript_ProfQuestions_6
# 167 "data/maps/BersketCity_Lab/scripts.pory"
	case 1, BersketCity_Lab_EventScript_ProfQuestions_7
# 173 "data/maps/BersketCity_Lab/scripts.pory"
	case 2, BersketCity_Lab_EventScript_ProfQuestions_8
# 177 "data/maps/BersketCity_Lab/scripts.pory"
	case 3, BersketCity_Lab_EventScript_ProfQuestions_9
# 178 "data/maps/BersketCity_Lab/scripts.pory"
	case MULTI_B_PRESSED, BersketCity_Lab_EventScript_ProfQuestions_9
BersketCity_Lab_EventScript_ProfQuestions_4:
	return

BersketCity_Lab_EventScript_ProfQuestions_2:
# 154 "data/maps/BersketCity_Lab/scripts.pory"
	applymovement LOCALID_BERSKET_LAB_JACUZZI, Common_Movement_WalkInPlaceFasterRight
# 155 "data/maps/BersketCity_Lab/scripts.pory"
	waitmovement LOCALID_BERSKET_LAB_JACUZZI
	goto BersketCity_Lab_EventScript_ProfQuestions_1

BersketCity_Lab_EventScript_ProfQuestions_6:
# 161 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfQuestions_Text_0
# 162 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfQuestions_Text_1
# 163 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfQuestions_Text_2
# 164 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfQuestions_Text_3
# 165 "data/maps/BersketCity_Lab/scripts.pory"
	closemessage
# 166 "data/maps/BersketCity_Lab/scripts.pory"
	call BersketCity_Lab_EventScript_ProfQuestions
	goto BersketCity_Lab_EventScript_ProfQuestions_4

BersketCity_Lab_EventScript_ProfQuestions_7:
# 168 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfQuestions_Text_4
# 169 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfQuestions_Text_5
# 170 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfQuestions_Text_6
# 171 "data/maps/BersketCity_Lab/scripts.pory"
	closemessage
# 172 "data/maps/BersketCity_Lab/scripts.pory"
	call BersketCity_Lab_EventScript_ProfQuestions
	goto BersketCity_Lab_EventScript_ProfQuestions_4

BersketCity_Lab_EventScript_ProfQuestions_8:
# 174 "data/maps/BersketCity_Lab/scripts.pory"
	msgbox BersketCity_Lab_EventScript_ProfQuestions_Text_7
# 175 "data/maps/BersketCity_Lab/scripts.pory"
	closemessage
# 176 "data/maps/BersketCity_Lab/scripts.pory"
	call BersketCity_Lab_EventScript_ProfQuestions
	goto BersketCity_Lab_EventScript_ProfQuestions_4

BersketCity_Lab_EventScript_ProfQuestions_9:
	return


# 185 "data/maps/BersketCity_Lab/scripts.pory"
BersketCity_Lab_Movement_SyrupApproach1:
# 186 "data/maps/BersketCity_Lab/scripts.pory"
	walk_left
# 187 "data/maps/BersketCity_Lab/scripts.pory"
	walk_down
# 187 "data/maps/BersketCity_Lab/scripts.pory"
	walk_down
# 187 "data/maps/BersketCity_Lab/scripts.pory"
	walk_down
	step_end

# 190 "data/maps/BersketCity_Lab/scripts.pory"
BersketCity_Lab_Movement_SyrupApproach2:
# 191 "data/maps/BersketCity_Lab/scripts.pory"
	walk_left
# 192 "data/maps/BersketCity_Lab/scripts.pory"
	walk_down
# 192 "data/maps/BersketCity_Lab/scripts.pory"
	walk_down
	step_end

# 195 "data/maps/BersketCity_Lab/scripts.pory"
BersketCity_Lab_Movement_SyrupApproach3:
# 196 "data/maps/BersketCity_Lab/scripts.pory"
	walk_down
# 196 "data/maps/BersketCity_Lab/scripts.pory"
	walk_down
# 196 "data/maps/BersketCity_Lab/scripts.pory"
	walk_down
# 196 "data/maps/BersketCity_Lab/scripts.pory"
	walk_down
# 197 "data/maps/BersketCity_Lab/scripts.pory"
	walk_left
# 197 "data/maps/BersketCity_Lab/scripts.pory"
	walk_left
	step_end

# 200 "data/maps/BersketCity_Lab/scripts.pory"
BersketCity_Lab_Movement_JacuzziApproach:
# 201 "data/maps/BersketCity_Lab/scripts.pory"
	walk_right
# 202 "data/maps/BersketCity_Lab/scripts.pory"
	walk_up
# 202 "data/maps/BersketCity_Lab/scripts.pory"
	walk_up
	step_end

BersketCity_Lab_EventScript_PC_Text_0:
# 6 "data/maps/BersketCity_Lab/scripts.pory"
	.string "It's a PC used for research.\nLooks like Gulpin are a focus.\pBetter not mess around with it.$"

BersketCity_Lab_EventScript_Bookcase_Text_0:
# 11 "data/maps/BersketCity_Lab/scripts.pory"
	.string "It's crammed with books on many\n"
	.string "subjects. There are several books\l"
	.string "about Gulpin.$"

BersketCity_Lab_EventScript_Machine_Text_0:
# 16 "data/maps/BersketCity_Lab/scripts.pory"
	.string "It's a serious-looking machine.\nThey must use this for research.\pDo they put Gulpin in this?$"

BersketCity_Lab_EventScript_ProfJacuzzi_Text_0:
# 31 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Do you have any questions?$"

BersketCity_Lab_EventScript_ProfJacuzzi_Text_1:
# 35 "data/maps/BersketCity_Lab/scripts.pory"
	.string "I will see you soon.$"

BersketCity_Lab_EventScript_ProfJacuzzi_Text_2:
# 42 "data/maps/BersketCity_Lab/scripts.pory"
	.string "{PLAYER}, is it? I'm Professor\n"
	.string "Jacuzzi.$"

BersketCity_Lab_EventScript_ProfJacuzzi_Text_3:
# 54 "data/maps/BersketCity_Lab/scripts.pory"
	.string "And I am 'Professor' Syrup.$"

BersketCity_Lab_EventScript_ProfJacuzzi_Text_4:
# 55 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Jacuzzi: It's good to see you,\n"
	.string "{PLAYER}. Your friends told me you\l"
	.string "were on your way.$"

BersketCity_Lab_EventScript_ProfSyrup_Text_0:
# 81 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Hello. I am 'Professor' Syrup. That is\n"
	.string "what Guljira calls me at least.$"

BersketCity_Lab_EventScript_ProfSyrup_Text_1:
# 94 "data/maps/BersketCity_Lab/scripts.pory"
	.string "It's good to see you. Your friends told\n"
	.string "me you were on your way.$"

BersketCity_Lab_EventScript_Profs_Text_0:
# 104 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Lips: I'm here too!$"

BersketCity_Lab_EventScript_Profs_Text_1:
# 105 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Syrup: Disciple Lips? Where are you?$"

BersketCity_Lab_EventScript_Profs_Text_2:
# 106 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Lips: I'm in a 'pokéball.'\n"
	.string "It's my palace!$"

BersketCity_Lab_EventScript_Profs_Text_3:
# 107 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Syrup: Oh.\nHow are you?$"

BersketCity_Lab_EventScript_Profs_Text_4:
# 108 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Lips: Good. I brought {PLAYER} to\n"
	.string "meet you guys.$"

BersketCity_Lab_EventScript_Profs_Text_5:
# 109 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Jacuzzi: Well … we were hoping that you\n"
	.string "could help us.$"

BersketCity_Lab_EventScript_Profs_Text_6:
# 110 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Lips: Huh?$"

BersketCity_Lab_EventScript_Profs_Text_7:
# 111 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Jacuzzi: Our path to the tree has been\n"
	.string "blocked.$"

BersketCity_Lab_EventScript_Profs_Text_8:
# 112 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Lips: … Oh. Oh no!\n"
	.string "That forest is bad news lately.$"

BersketCity_Lab_EventScript_Profs_Text_9:
# 116 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Jacuzzi: I will explain.\p"
	.string "I'm sure you've seen Guljira. He needs a\n"
	.string "lot of food. Luckily there's a tree in\l"
	.string "Petalburg Woods with special fruit. It\l"
	.string "keeps Guljira full.\p"
	.string "But we can't reach the tree anymore.\p"
	.string "The whole forest is changing, growing in\n"
	.string "odd ways. The path to the tree has been\l"
	.string "blocked by these strange growths. They\l"
	.string "seem intent on stopping us.\p"
	.string "My assistants tried to find another\n"
	.string "path, but they've gone missing!$"

BersketCity_Lab_EventScript_Profs_Text_10:
# 117 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Syrup: We need to find a way to reach\n"
	.string "the tree or Guljira will starve.$"

BersketCity_Lab_EventScript_Profs_Text_11:
# 118 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Jacuzzi: I think he's trying to help us.\n"
	.string "Today he spat up something I've named\l"
	.string "an 'Engram.'\p"
	.string "It seems to be a move, 'Cut,' in physical\n"
	.string "form.\p"
	.string "With 'Cut,' perhaps we can … cut our way\n"
	.string "to the tree and find out what has gone\l"
	.string "wrong.\p"
	.string "But first we need to learn the move.$"

BersketCity_Lab_EventScript_Profs_Text_12:
# 119 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Syrup: This 'Cut' is a Rock flavored\n"
	.string "move, and Rustboro has a Rock flavored\l"
	.string "gym.\p"
	.string "We want you to go and learn from them.\n"
	.string "That is what a 'trainer' would do.$"

BersketCity_Lab_EventScript_Profs_Text_13:
# 122 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Lips: Hey, {PLAYER}, let's go beat the\n"
	.string "gym! Your dad will be proud.$"

BersketCity_Lab_EventScript_Profs_Text_14:
# 123 "data/maps/BersketCity_Lab/scripts.pory"
	.string "… … … … … … … …\n… … … … … … … …$"

BersketCity_Lab_EventScript_Profs_Text_15:
# 124 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Jacuzzi: Good, thank you. Here, this is a\n"
	.string "copy of the Engram.$"

BersketCity_Lab_EventScript_Profs_Text_16:
# 126 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Jacuzzi: Rustboro is on the other side\n"
	.string "of the lake. It's not far.\p"
	.string "The gym leader should help you learn\n"
	.string "'Cut'. That's the point of a gym after\l"
	.string "all.$"

BersketCity_Lab_EventScript_Profs_Text_17:
# 129 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Lips: Funnily enough, we've already\n"
	.string "been there. But we can go back.$"

BersketCity_Lab_EventScript_Profs_Text_18:
# 133 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Jacuzzi: Show it to the gym leader; she\n"
	.string "should be able to teach you the move.$"

BersketCity_Lab_EventScript_Profs_Text_19:
# 135 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Before you go, do you have any\n"
	.string "questions?$"

BersketCity_Lab_EventScript_Profs_Text_20:
# 139 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Jacuzzi: Alright. Well, we hope to hear\n"
	.string "from you soon.$"

BersketCity_Lab_EventScript_Profs_Text_21:
# 140 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Syrup: Know that you will succeed. You\n"
	.string "have already suceeded. Be full.$"

BersketCity_Lab_EventScript_ProfQuestions_Text_0:
# 161 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Jacuzzi: It was a few months ago.\n"
	.string "Gulpin were attacking the city, like\l"
	.string "they do every year. This time though I\l"
	.string "built a 'spit up' machine to launch them\l"
	.string "away.\p"
	.string "But then the machine malfunctioned. It\n"
	.string "enlarged one of the Gulpin to a massive\l"
	.string "size. That's 'Guljira.$"

BersketCity_Lab_EventScript_ProfQuestions_Text_1:
# 162 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Syrup: It was not a malfunction. In\n"
	.string "using his 'spit up' against him, you\l"
	.string "awakened Guljira's true power.\p"
	.string "His mouth is now large enough to grasp\n"
	.string "profound wisdom. He has become\l"
	.string "enlightened.$"

BersketCity_Lab_EventScript_ProfQuestions_Text_2:
# 163 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Jacuzzi: In all my fifty years of\n"
	.string "studying Gulpin, I have never seen\l"
	.string "anything like this. It's amazing. The\l"
	.string "local Gulpin population now follows\l"
	.string "Guljira as a leader. And they're not\l"
	.string "hungry anymore.$"

BersketCity_Lab_EventScript_ProfQuestions_Text_3:
# 164 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Syrup: Guljira provides for all who\n"
	.string "hunger.$"

BersketCity_Lab_EventScript_ProfQuestions_Text_4:
# 168 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Syrup: Guljira spat up eighteen berries\n"
	.string "of power, one for each of the world's\l"
	.string "flavors.\p"
	.string "Seventeen disciples ate them and went\n"
	.string "forth to master the flavors. So that\l"
	.string "they may eat a way to salvation.$"

BersketCity_Lab_EventScript_ProfQuestions_Text_5:
# 169 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Lips: Yeah, I got the Normal berry. Kind\n"
	.string "of boring. It's like plain bread. But it's\l"
	.string "healthy!$"

BersketCity_Lab_EventScript_ProfQuestions_Text_6:
# 170 "data/maps/BersketCity_Lab/scripts.pory"
	.string "Syrup: And your friend, 'Gulpinator.'\n"
	.string "Well, there was one berry left.\p"
	.string "The Steel berry.\p"
	.string "Oh, Steel, it is the worst flavor.\n"
	.string "Inedibible even. No one wanted it.\p"
	.string "Until 'Gulpinator' came along.\n"
	.string "He is odd.$"

BersketCity_Lab_EventScript_ProfQuestions_Text_7:
# 174 "data/maps/BersketCity_Lab/scripts.pory"
	.string "remind player what to do.$"

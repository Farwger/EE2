OldaleRuins_MapScripts::
	.byte 0


OldaleRuins_Sign::
	msgbox OldaleRuins_Sign_Text_0, MSGBOX_SIGN
	end


OldaleRuins_Grunt1::
	trainerbattle_single TRAINER_GRUNT_OLDALE_RUINS_1, OldaleRuins_Grunt1_Intro, OldaleRuins_Grunt1_Defeat
	clearflag FLAG_HIDE_OLDALE_RUIN_ALDEN
	msgbox OldaleRuins_Grunt1_Text_0, MSGBOX_NPC
	end


OldaleRuins_Sign_Text_0:
	.string "{RIGHT_ARROW} Oldale Ruins$"

OldaleRuins_Grunt1_Text_0:
	.string "You may have defeated me, but if you go\n"
	.string "in there, you'll be in for a world of\l"
	.string "hurt!$"

OldaleRuins_Grunt1_Intro::
	.string "What're you doing out here, kid?\n"
	.string "You're trespassing.$"

OldaleRuins_Grunt1_Defeat::
	.string "These ruins belong to Team Magma!$"

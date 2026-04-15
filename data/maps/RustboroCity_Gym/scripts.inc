# 1 "data/maps/RustboroCity_Gym/scripts.pory"

# 2 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_MapScripts::
# 3 "data/maps/RustboroCity_Gym/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_Gym/scripts.pory"

# 5 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneDefeated::
# 6 "data/maps/RustboroCity_Gym/scripts.pory"
	message RustboroCity_Gym_Text_ReceivedStoneBadge
# 7 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 8 "data/maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 9 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
# 10 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_BADGE01_GET
# 11 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 1
# 12 "data/maps/RustboroCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 13 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 14 "data/maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 15 "data/maps/RustboroCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 16 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GiveRockTomb
# 17 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 18 "data/maps/RustboroCity_Gym/scripts.pory"

# 19 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GiveRockTomb::
# 20 "data/maps/RustboroCity_Gym/scripts.pory"
	giveitem ITEM_TM_ROCK_TOMB
# 21 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 22 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
# 23 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
# 24 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 25 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 26 "data/maps/RustboroCity_Gym/scripts.pory"

# 27 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneRematch::
# 28 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_ROXANNE, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
# 29 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
# 30 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 31 "data/maps/RustboroCity_Gym/scripts.pory"

# 32 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Josh::
# 33 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
# 34 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
# 35 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 36 "data/maps/RustboroCity_Gym/scripts.pory"

# 37 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Tommy::
# 38 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
# 39 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
# 40 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 41 "data/maps/RustboroCity_Gym/scripts.pory"

# 42 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Marc::
# 43 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
# 44 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
# 45 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 46 "data/maps/RustboroCity_Gym/scripts.pory"

# 47 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuide::
# 48 "data/maps/RustboroCity_Gym/scripts.pory"
	lock
# 49 "data/maps/RustboroCity_Gym/scripts.pory"
	faceplayer
# 50 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymGuidePostVictory
# 51 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 52 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 53 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 54 "data/maps/RustboroCity_Gym/scripts.pory"

# 55 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuidePostVictory::
# 56 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 57 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 58 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 59 "data/maps/RustboroCity_Gym/scripts.pory"

# 60 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_LeftGymStatue::
# 61 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 62 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueBothCertified
# 63 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_ge VAR_BERSKET_CITY_STATE, 1, RustboroCity_Gym_EventScript_GymStatueGulpinatorCertified
# 64 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 65 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 66 "data/maps/RustboroCity_Gym/scripts.pory"

# 67 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RightGymStatue::
# 68 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 69 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueBothCertified
# 70 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_ge VAR_BERSKET_CITY_STATE, 1, RustboroCity_Gym_EventScript_GymStatueGulpinatorCertified
# 71 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 72 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 73 "data/maps/RustboroCity_Gym/scripts.pory"

# 74 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatueBothCertified::
# 75 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatueBothCertified, MSGBOX_DEFAULT
# 76 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 77 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 78 "data/maps/RustboroCity_Gym/scripts.pory"

# 79 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatueGulpinatorCertified::
# 80 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatueGulpinatorCertified, MSGBOX_DEFAULT
# 81 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 82 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 83 "data/maps/RustboroCity_Gym/scripts.pory"

# 84 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatue::
# 85 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 86 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 87 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 88 "data/maps/RustboroCity_Gym/scripts.pory"

# 89 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RegisterRoxanne::
# 90 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 91 "data/maps/RustboroCity_Gym/scripts.pory"
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
# 92 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 93 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 94 "data/maps/RustboroCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 95 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
# 96 "data/maps/RustboroCity_Gym/scripts.pory"
	waitfanfare
# 97 "data/maps/RustboroCity_Gym/scripts.pory"
	closemessage
# 98 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 99 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
# 100 "data/maps/RustboroCity_Gym/scripts.pory"
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 101 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 102 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 103 "data/maps/RustboroCity_Gym/scripts.pory"

# 104 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuideAdvice:
# 105 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Yo, how's it going?\p"
# 106 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Listen, my friend!\n"
# 107 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Would you like to become the CHAMPION?\p"
# 108 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm no TRAINER, not me, but I can\n"
# 109 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "sure give you winning advice.\p"
# 110 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That's settled, then! We'll aim for the\n"
# 111 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON CHAMPIONSHIP together!\p"
# 112 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It's your job as a TRAINER to collect\n"
# 113 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "GYM BADGES, am I right?\p"
# 114 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "But GYM LEADERS aren't pushovers!\p"
# 115 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "And that's where I come in!\n"
# 116 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm here to provide expert advice!\p"
# 117 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE, the GYM LEADER, is a user\n"
# 118 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "of ROCK-type POKéMON.\p"
# 119 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The ROCK type is very durable, but\n"
# 120 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "it can't stand WATER-type and\l"
# 121 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "GRASS-type moves.\p"
# 122 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Come see me afterwards, if you beat\n"
# 123 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the GYM LEADER.\p"
# 124 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Well, go for it!$"
# 125 "data/maps/RustboroCity_Gym/scripts.pory"

# 126 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuidePostVictory:
# 127 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Whoa! What a breathtaking victory!\n"
# 128 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "My cheering must've worked!\p"
# 129 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Great!\n"
# 130 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Check your TRAINER CARD.\p"
# 131 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE you got should be\n"
# 132 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "properly recorded on it.\p"
# 133 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "In other words…\p"
# 134 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You've climbed the first step on\n"
# 135 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the stairs to the CHAMPIONSHIP!\p"
# 136 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That's got to feel awesome!$"
# 137 "data/maps/RustboroCity_Gym/scripts.pory"

# 138 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshIntro:
# 139 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Don't take us GYM TRAINERS lightly!\n"
# 140 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'll show you why we're better!$"
# 141 "data/maps/RustboroCity_Gym/scripts.pory"

# 142 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshDefeat:
# 143 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You were too good for me…$"
# 144 "data/maps/RustboroCity_Gym/scripts.pory"

# 145 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshPostBattle:
# 146 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You haven't seen anything of the ROCK\n"
# 147 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "type's terrifying power!$"
# 148 "data/maps/RustboroCity_Gym/scripts.pory"

# 149 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyIntro:
# 150 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "If you can't beat me, you won't stand\n"
# 151 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "a chance against ROXANNE!$"
# 152 "data/maps/RustboroCity_Gym/scripts.pory"

# 153 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyDefeat:
# 154 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Wow! You've got some potential!$"
# 155 "data/maps/RustboroCity_Gym/scripts.pory"

# 156 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyPostBattle:
# 157 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE is stronger than me by\n"
# 158 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "several times.\p"
# 159 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You'd better be on your guard!$"
# 160 "data/maps/RustboroCity_Gym/scripts.pory"

# 161 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcIntro:
# 162 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "We might be in the middle of town,\n"
# 163 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "but so what?\p"
# 164 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "My ROCK POKéMON need room to\n"
# 165 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "rampage!$"
# 166 "data/maps/RustboroCity_Gym/scripts.pory"

# 167 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcDefeat:
# 168 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, man oh man!\n"
# 169 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Our challenger is one feisty customer!$"
# 170 "data/maps/RustboroCity_Gym/scripts.pory"

# 171 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcPostBattle:
# 172 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I have to hand it to our LEADER.\p"
# 173 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It took smarts and sense for her to\n"
# 174 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "pick the ROCK type at her young age.$"
# 175 "data/maps/RustboroCity_Gym/scripts.pory"

# 176 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneIntro:
# 177 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Hello, I am ROXANNE, the RUSTBORO\n"
# 178 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON GYM LEADER.\p"
# 179 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I became a GYM LEADER so that I might\n"
# 180 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "apply what I learned at the POKéMON\l"
# 181 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINER'S SCHOOL in battle.\p"
# 182 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Would you kindly demonstrate how you\n"
# 183 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battle, and with which POKéMON?$"
# 184 "data/maps/RustboroCity_Gym/scripts.pory"

# 185 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneDefeat:
# 186 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "So…\n"
# 187 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I lost…\p"
# 188 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It seems that I still have much more\n"
# 189 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "to learn…\p"
# 190 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I understand.\p"
# 191 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The POKéMON LEAGUE's rules state\n"
# 192 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "that TRAINERS are to be given this\l"
# 193 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "if they defeat a GYM LEADER.\p"
# 194 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please accept the official POKéMON\n"
# 195 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "LEAGUE STONE BADGE.$"
# 196 "data/maps/RustboroCity_Gym/scripts.pory"

# 197 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ReceivedStoneBadge:
# 198 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER} received the STONE BADGE\n"
# 199 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "from ROXANNE.$"
# 200 "data/maps/RustboroCity_Gym/scripts.pory"

# 201 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
# 202 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The STONE BADGE heightens the ATTACK\n"
# 203 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "power of your POKéMON.\p"
# 204 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It also enables them to use the HM move\n"
# 205 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "CUT outside of battle.\p"
# 206 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please take this with you, too.$"
# 207 "data/maps/RustboroCity_Gym/scripts.pory"

# 208 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ExplainRockTomb:
# 209 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That TECHNICAL MACHINE, TM39,\n"
# 210 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "contains ROCK TOMB.\p"
# 211 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It not only inflicts damage by dropping\n"
# 212 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "rocks, it also lowers SPEED.\p"
# 213 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "If you use a TM, it instantly teaches\n"
# 214 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the move to a POKéMON.\p"
# 215 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Remember, a TM can be used only once,\n"
# 216 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "so think before you use it.$"
# 217 "data/maps/RustboroCity_Gym/scripts.pory"

# 218 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostBattle:
# 219 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Since you are so strong, you should\n"
# 220 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "challenge other GYM LEADERS.\p"
# 221 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "By battling many TRAINERS, you should\n"
# 222 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "learn many things.$"
# 223 "data/maps/RustboroCity_Gym/scripts.pory"

# 224 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatue:
# 225 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM$"
# 226 "data/maps/RustboroCity_Gym/scripts.pory"

# 227 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatueGulpinatorCertified:
# 228 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\p"
# 229 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
# 230 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{RIVAL}\p"
# 231 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … …$"
# 232 "data/maps/RustboroCity_Gym/scripts.pory"

# 233 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatueBothCertified:
# 234 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\p"
# 235 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
# 236 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{RIVAL}\p" 
# 237 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER}\p"
# 238 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … …$"
# 239 "data/maps/RustboroCity_Gym/scripts.pory"

# 240 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRegisterCall:
# 241 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 242 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Beep!\p"
# 243 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
# 244 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "This is ROXANNE of RUSTBORO CITY.\p"
# 245 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I heard from BRAWLY that you're\n"
# 246 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "moving up through the ranks of\l"
# 247 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "TRAINERS at an incredible clip.\p"
# 248 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Well, I'd rather not think that\n"
# 249 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I can't beat you.\p"
# 250 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I promise, I will shape up my GYM\n"
# 251 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "so that you may challenge us again.\p"
# 252 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I hope you'll be looking forward to\n"
# 253 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "that occasion as much as me!\p"
# 254 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 255 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Click!$"
# 256 "data/maps/RustboroCity_Gym/scripts.pory"

# 257 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RegisteredRoxanne:
# 258 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Registered GYM LEADER ROXANNE\n"
# 259 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 260 "data/maps/RustboroCity_Gym/scripts.pory"

# 261 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePreRematch:
# 262 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 263 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 264 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 265 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 266 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 267 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "we've become. Let us battle!$"
# 268 "data/maps/RustboroCity_Gym/scripts.pory"

# 269 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchDefeat:
# 270 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Grr…\n"
# 271 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Again, I have lost…$"
# 272 "data/maps/RustboroCity_Gym/scripts.pory"

# 273 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostRematch:
# 274 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I still have much to learn\n"
# 275 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "when it comes to battling POKéMON.\p"
# 276 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That awareness makes me love battling\n"
# 277 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "all that much more!$"
# 278 "data/maps/RustboroCity_Gym/scripts.pory"

# 279 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
# 280 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "ROXANNE: I'm so glad to see you again.\n"
# 281 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
# 282 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 283 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 284 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 285 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "we've become…\p"
# 286 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, no…\n"
# 287 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You only have one POKéMON with you?\p"
# 288 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please return with at least one more\n"
# 289 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "POKéMON.$"

RustboroCity_Gym_EventScript_Roxanne::
# 298 "data/maps/RustboroCity_Gym/scripts.pory"
	lock
# 299 "data/maps/RustboroCity_Gym/scripts.pory"
	faceplayer
# 301 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_FACING, DIR_WEST
	goto_if_eq RustboroCity_Gym_EventScript_Roxanne_2
RustboroCity_Gym_EventScript_Roxanne_1:
# 307 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_Roxanne_5
RustboroCity_Gym_EventScript_Roxanne_4:
# 330 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_5
# 331 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_6
# 332 "data/maps/RustboroCity_Gym/scripts.pory"
	call RustboroCity_Gym_EventScript_RoxanneChips
	return

RustboroCity_Gym_EventScript_Roxanne_2:
# 303 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement LOCALID_RUSTBOROGYM_CHIPS, Common_Movement_WalkInPlaceFasterRight
# 304 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement LOCALID_RUSTBOROGYM_CHIPS
	goto RustboroCity_Gym_EventScript_Roxanne_1

RustboroCity_Gym_EventScript_Roxanne_5:
# 309 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_BERSKET_CITY_STATE, 2
	goto_if_eq RustboroCity_Gym_EventScript_Roxanne_7
# 317 "data/maps/RustboroCity_Gym/scripts.pory"
	checkitem ITEM_CHARTI_BERRY
# 318 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_Gym_EventScript_Roxanne_11
RustboroCity_Gym_EventScript_Roxanne_10:
# 323 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_4
# 325 "data/maps/RustboroCity_Gym/scripts.pory"
	release
	end

RustboroCity_Gym_EventScript_Roxanne_7:
# 310 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_0
# 311 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_1
# 312 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_2
# 313 "data/maps/RustboroCity_Gym/scripts.pory"
	call RustboroCity_Gym_EventScript_LearnCut
	goto RustboroCity_Gym_EventScript_Roxanne_4

RustboroCity_Gym_EventScript_Roxanne_11:
# 319 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_3
# 320 "data/maps/RustboroCity_Gym/scripts.pory"
	giveitem ITEM_CHARTI_BERRY
# 321 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto RustboroCity_Gym_EventScript_Roxanne_10


RustboroCity_Gym_EventScript_Chips::
# 340 "data/maps/RustboroCity_Gym/scripts.pory"
	lock
# 341 "data/maps/RustboroCity_Gym/scripts.pory"
	faceplayer
# 343 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_Chips_2
RustboroCity_Gym_EventScript_Chips_1:
# 359 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Chips_Text_0
# 360 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Chips_Text_1
# 361 "data/maps/RustboroCity_Gym/scripts.pory"
	call RustboroCity_Gym_EventScript_RoxanneChips
	return

RustboroCity_Gym_EventScript_Chips_2:
# 345 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_BERSKET_CITY_STATE, 2
	goto_if_eq RustboroCity_Gym_EventScript_Chips_4
# 354 "data/maps/RustboroCity_Gym/scripts.pory"
	release
	end

RustboroCity_Gym_EventScript_Chips_4:
# 346 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_0
# 347 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_1
# 348 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_2
# 349 "data/maps/RustboroCity_Gym/scripts.pory"
	call RustboroCity_Gym_EventScript_LearnCut
	goto RustboroCity_Gym_EventScript_Chips_1


RustboroCity_Gym_EventScript_RoxanneChips::
# 369 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_0
# 370 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_1
# 371 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_2
# 372 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_3
# 373 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_4
# 376 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_BERSKET_CITY_STATE, 2
	goto_if_eq RustboroCity_Gym_EventScript_RoxanneChips_2
# 384 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_6
RustboroCity_Gym_EventScript_RoxanneChips_1:
# 387 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE, RustboroCity_Gym_Text_RoxanneDefeat
# 388 "data/maps/RustboroCity_Gym/scripts.pory"
	message RustboroCity_Gym_Text_ReceivedStoneBadge
# 389 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 390 "data/maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 391 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_BADGE01_GET
# 394 "data/maps/RustboroCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 395 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 396 "data/maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 397 "data/maps/RustboroCity_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 398 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_7
# 399 "data/maps/RustboroCity_Gym/scripts.pory"
	message RustboroCity_Gym_EventScript_RoxanneChips_Text_8
# 400 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 401 "data/maps/RustboroCity_Gym/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 402 "data/maps/RustboroCity_Gym/scripts.pory"
	waitfanfare
# 403 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_9
# 404 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_10
# 405 "data/maps/RustboroCity_Gym/scripts.pory"
	giveitem ITEM_CHARTI_BERRY
# 406 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 407 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_11
# 409 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_BERSKET_CITY_STATE, 2
	goto_if_eq RustboroCity_Gym_EventScript_RoxanneChips_6
RustboroCity_Gym_EventScript_RoxanneChips_5:
# 414 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_4
# 415 "data/maps/RustboroCity_Gym/scripts.pory"
	closemessage
# 416 "data/maps/RustboroCity_Gym/scripts.pory"
	release
	end

RustboroCity_Gym_EventScript_RoxanneChips_2:
# 377 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_0
# 378 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_1
# 379 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Text_2
# 380 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_5
	goto RustboroCity_Gym_EventScript_RoxanneChips_1

RustboroCity_Gym_EventScript_RoxanneChips_6:
# 410 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_RoxanneChips_Text_12
# 411 "data/maps/RustboroCity_Gym/scripts.pory"
	call RustboroCity_Gym_EventScript_LearnCut
	goto RustboroCity_Gym_EventScript_RoxanneChips_5


RustboroCity_Gym_EventScript_LearnCut::
# 425 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_0
# 426 "data/maps/RustboroCity_Gym/scripts.pory"
	closemessage
# 427 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 428 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement LOCALID_PLAYER
# 429 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 10
# 430 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_1
# 431 "data/maps/RustboroCity_Gym/scripts.pory"
	closemessage
# 432 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 20
# 433 "data/maps/RustboroCity_Gym/scripts.pory"
	playse SE_M_ROCK_THROW
# 434 "data/maps/RustboroCity_Gym/scripts.pory"
	waitse
# 435 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 15
# 436 "data/maps/RustboroCity_Gym/scripts.pory"
	playse SE_M_ROCK_THROW
# 437 "data/maps/RustboroCity_Gym/scripts.pory"
	waitse
# 438 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 10
# 439 "data/maps/RustboroCity_Gym/scripts.pory"
	playse SE_M_ROCK_THROW
# 440 "data/maps/RustboroCity_Gym/scripts.pory"
	waitse
# 441 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 20
# 442 "data/maps/RustboroCity_Gym/scripts.pory"
	playse SE_PC_LOGIN
# 443 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 5
# 444 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_2
# 445 "data/maps/RustboroCity_Gym/scripts.pory"
	removeitem ITEM_ENGRAM_CUT
# 446 "data/maps/RustboroCity_Gym/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 447 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_3
# 448 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_LEARNED_MOVE_CUT
# 449 "data/maps/RustboroCity_Gym/scripts.pory"
	waitfanfare
# 450 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_BERSKET_CITY_STATE, 3
# 451 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_4
# 452 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_5
# 453 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_6
# 454 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_7
# 455 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_8
# 456 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_9
# 457 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_10
# 458 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_11
# 459 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_12
# 460 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_13
# 461 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_14
# 462 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_LearnCut_Text_15
# 463 "data/maps/RustboroCity_Gym/scripts.pory"
	closemessage
# 464 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
	end


RustboroCity_Gym_EventScript_Roxanne_Text_0:
# 310 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Lips: Hey, so we need to learn this move,\n"
	.string "'Cut.' It's in this 'Engram' thing. Can\l"
	.string "you do that?$"

RustboroCity_Gym_EventScript_Roxanne_Text_1:
# 311 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: An engram? You have an actual\n"
	.string "engram?$"

RustboroCity_Gym_EventScript_Roxanne_Text_2:
# 312 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Lips: Uh, yeah. And it's Rock flavored.$"

RustboroCity_Gym_EventScript_Roxanne_Text_3:
# 319 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: Here, you can have another\n"
	.string "berry.$"

RustboroCity_Gym_EventScript_Roxanne_Text_4:
# 323 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: You show promise. You should\n"
	.string "challenge the other Gym Leaders. By\l"
	.string "battling many TRAINERS, you will learn\l"
	.string "many things.\p"
	.string "Farewell.$"

RustboroCity_Gym_EventScript_Roxanne_Text_5:
# 330 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Hello, I am Roxanne, the Rustboro\nGym Leader.$"

RustboroCity_Gym_EventScript_Roxanne_Text_6:
# 331 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Chips: Hey, I'm Chips. I'm a Rock\n"
	.string "flavored Gulpin. Disciple of Guljira.$"

RustboroCity_Gym_EventScript_Chips_Text_0:
# 359 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Hey, I'm Chips. I'm a Rock flavored\n"
	.string "Gulpin. A disciple of Guljira.$"

RustboroCity_Gym_EventScript_Chips_Text_1:
# 360 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: I am Roxanne, the Rustboro\n"
	.string "Gym Leader.$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_0:
# 369 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Lips: Hi Chips!\n"
	.string "It makes sense you'd be here.$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_1:
# 370 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Chips: Yes. I seek to master the Rock\n"
	.string "flavor,\p"
	.string "and then …\p"
	.string "I will gulp down this big rock we live on!$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_2:
# 371 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Lips: Wow!$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_3:
# 372 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: I understand that you speak\n"
	.string "in metaphors.$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_4:
# 373 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Chips: … Sort of.$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_5:
# 380 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: I will try to do what you ask.\p"
	.string "But first …\p"
	.string "You must defeat us in battle!$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_6:
# 384 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: Challenger, you and your\n"
	.string "Gulpin friend, you have come to battle,\l"
	.string "am I correct? You wish to earn our\l"
	.string "badge?\p"
	.string "Then let us begin!$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_7:
# 398 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Chips: Lips, I have something for you.$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_8:
# 399 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Lips recieved the Stone Seed!$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_9:
# 403 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Chips: This is some of my power. You\n"
	.string "might be able to grow it into another\l"
	.string "Rock berry.\p"
	.string "Then you too can rock out!$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_10:
# 404 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: Please take this with you, too.$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_11:
# 407 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: If a Pokémon holds this berry,\n"
	.string "the berry will weaken a Rock type move\l"
	.string "that hits the Pokémon.\p"
	.string "It may also heal the Pokémon at low\n"
	.string "health.\p"
	.string "You can get a replacement at any\n"
	.string "Pokémon Center. I will inform them.$"

RustboroCity_Gym_EventScript_RoxanneChips_Text_12:
# 410 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Lips: So, can you teach us 'Cut' now?\n"
	.string "Guljira is really hungry.$"

RustboroCity_Gym_EventScript_LearnCut_Text_0:
# 425 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Chips: Yes. I should be able to teach\n"
	.string "you this move.\p"
	.string "You, 'trainer,' you have shown yourself\n"
	.string "capable.\p"
	.string "This move, it is a move for you to learn.$"

RustboroCity_Gym_EventScript_LearnCut_Text_1:
# 430 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Chips: You humans misunderstand\n"
	.string "yourselves. You're not something\l"
	.string "different. You're just one species on\l"
	.string "this big rock.\p"
	.string "And it is a trainer's power to draw out\n"
	.string "the power of others. Now, you will\l"
	.string "unlock some of your own.\p"
	.string "Your first move.\p"
	.string "I'll activate the Engram.$"

RustboroCity_Gym_EventScript_LearnCut_Text_2:
# 444 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The Engram shines\pand vanishes!$"

RustboroCity_Gym_EventScript_LearnCut_Text_3:
# 447 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER} learned Cut!$"

RustboroCity_Gym_EventScript_LearnCut_Text_4:
# 451 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Chips: It worked. You now wield\n"
	.string "sharpened stone.$"

RustboroCity_Gym_EventScript_LearnCut_Text_5:
# 452 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Lips: Wow! Nice going.$"

RustboroCity_Gym_EventScript_LearnCut_Text_6:
# 453 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxxane: Do you have any more of those\n"
	.string "engrams?$"

RustboroCity_Gym_EventScript_LearnCut_Text_7:
# 454 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Lips: Just that one.$"

RustboroCity_Gym_EventScript_LearnCut_Text_8:
# 455 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxxane: Oh. That is unfortunate. I\n"
	.string "would like to learn one as well.$"

RustboroCity_Gym_EventScript_LearnCut_Text_9:
# 456 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "…$"

RustboroCity_Gym_EventScript_LearnCut_Text_10:
# 457 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Lips: We should be ready for Petalburg\n"
	.string "Woods now.$"

RustboroCity_Gym_EventScript_LearnCut_Text_11:
# 458 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxxane: You're going into the woods?\n"
	.string "Have you not heard about all the\l"
	.string "missing people?$"

RustboroCity_Gym_EventScript_LearnCut_Text_12:
# 459 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Lips: Yeah, that's why we're going. It's\n"
	.string "my Gulpin duty to save them!$"

RustboroCity_Gym_EventScript_LearnCut_Text_13:
# 460 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Chips: Lips is right.$"

RustboroCity_Gym_EventScript_LearnCut_Text_14:
# 461 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: …$"

RustboroCity_Gym_EventScript_LearnCut_Text_15:
# 462 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Lips: Alright, let's goooo!$"

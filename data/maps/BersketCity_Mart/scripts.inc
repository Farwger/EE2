# 1 "data/maps/BersketCity_Mart/scripts.pory"

# 2 "data/maps/BersketCity_Mart/scripts.pory"
BersketCity_Mart_MapScripts::
# 3 "data/maps/BersketCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/BersketCity_Mart/scripts.pory"

# 5 "data/maps/BersketCity_Mart/scripts.pory"
BersketCity_Mart_EventScript_Clerk::
# 6 "data/maps/BersketCity_Mart/scripts.pory"
	lock
# 7 "data/maps/BersketCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/BersketCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/BersketCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/BersketCity_Mart/scripts.pory"
	pokemart BersketCity_Mart_Pokemart
# 11 "data/maps/BersketCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/BersketCity_Mart/scripts.pory"
	release
# 13 "data/maps/BersketCity_Mart/scripts.pory"
	end
# 14 "data/maps/BersketCity_Mart/scripts.pory"

# 15 "data/maps/BersketCity_Mart/scripts.pory"
	.align 2
# 16 "data/maps/BersketCity_Mart/scripts.pory"
BersketCity_Mart_Pokemart:
# 17 "data/maps/BersketCity_Mart/scripts.pory"
	.2byte ITEM_POKE_BALL
# 18 "data/maps/BersketCity_Mart/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 19 "data/maps/BersketCity_Mart/scripts.pory"
	.2byte ITEM_POTION
# 20 "data/maps/BersketCity_Mart/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 21 "data/maps/BersketCity_Mart/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 22 "data/maps/BersketCity_Mart/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 23 "data/maps/BersketCity_Mart/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 24 "data/maps/BersketCity_Mart/scripts.pory"
	.2byte ITEM_REPEL
# 25 "data/maps/BersketCity_Mart/scripts.pory"
	.2byte ITEM_HARBOR_MAIL
# 26 "data/maps/BersketCity_Mart/scripts.pory"
	pokemartlistend

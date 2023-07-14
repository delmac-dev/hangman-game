#if !defined(_SCREENS_H_)
#define _SCREENS_H_

#include "WG_home_page.h"
#include "WG_exit_page.h"
#include "WG_player_page.h"
#include "WG_credits_page.h"
#include "WG_play_page.h"
#include "WG_help_page.h"
#include "WG_hof_page.h"
#include "WG_game_page.h"
#include "WG_start_page.h"

struct Screens
{
    WG_Start_Page StartPage;
    WG_Exit_Page ExitPage;
    WG_Home_Page HomePage;
    WG_HoF_Page HofPage;
    WG_Help_Page HelpPage;
    WG_Credits_Page CreditsPage;
    WG_Play_Page PlayMenuPage;
    WG_Player_Page PlayerInitPage;
    WG_Game_Page DeGamePage;
};

#endif // _SCREENS_H_

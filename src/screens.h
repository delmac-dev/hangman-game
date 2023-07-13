#if !defined(_SCREENS_H_)
#define _SCREENS_H_

#include "Screens/Home_Page/WG_home_page.h"
#include "Screens/Exit_Page/WG_exit_page.h"
#include "Screens/Player_Page/WG_player_page.h"
#include "Screens/Credits_Page/WG_credits_page.h"
#include "Screens/Play_Page/WG_play_page.h"
#include "Screens/Help_Page/WG_help_page.h"
#include "Screens/HoF_Page/WG_hof_page.h"
#include "Screens/Game_Page/WG_game_page.h"
#include "Screens/Start_Page/WG_start_page.h"

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
